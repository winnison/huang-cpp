#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <new>
#include <memory>

#ifndef _MUTEX_CLASS
#ifdef WIN32
#include <windows.h>
#define _MUTEX_CLASS       CRITICAL_SECTION
#define _MUTEX_INIT(m)     InitializeCriticalSection((m))
#define _MUTEX_DELETE(m)   DeleteCriticalSection((m))
#define _MUTEX_LOCK(m)     EnterCriticalSection((m))
#define _MUTEX_UNLOCK(m)   LeaveCriticalSection((m))
#else
#include <pthread.h>
#define _MUTEX_CLASS       pthread_mutex_t
#define _MUTEX_INIT(m)     pthread_mutex_init((m), NULL)
#define _MUTEX_DELETE(m)   pthread_mutex_destroy((m))
#define _MUTEX_LOCK(m)     pthread_mutex_lock((m))
#define _MUTEX_UNLOCK(m)   pthread_mutex_unlock((m))
#endif
#endif

class locker
{
	_MUTEX_CLASS mutex;
public:
	locker()               {_MUTEX_INIT(&mutex);}
	locker(const locker&)  {_MUTEX_INIT(&mutex);}
	~locker()              {_MUTEX_DELETE(&mutex);}
	inline void lock()     {_MUTEX_LOCK(&mutex);}
	inline void unlock()   {_MUTEX_UNLOCK(&mutex);}
};

struct empty_locker
{
	inline void lock(){}
	inline void unlock(){}
};

#ifdef _SIGNAL_DEFAULT_USE_LOCKER
typedef locker defaultlocker;
#else
typedef empty_locker defaultlocker;
#endif

template<class Locker>
class lockerguard
{
	Locker* k;
public:
	lockerguard(Locker& _k)                 : k(&_k) { k->lock(); }
	void release()                          { if(k){k->unlock(); k = NULL;} }
	~lockerguard()                          { if(k) k->unlock(); }
};

class _emitter
{
	_emitter* next;
	_emitter():next(NULL){}
	bool equal(_emitter* e)                 { return e && size() == e->size() && memcmp(data(), e->data(), size()) == 0; }
	static _emitter* getcopy(_emitter* e, _emitter *&last)
	{
		if(e == NULL)
			return NULL;
		_emitter* a = e->clone();
		last = a;
		while(e = e->next)
		{
			last->next = e->clone();
			last = last->next;
		}
		return a;
	}
	static _emitter* getcopy(_emitter* e)   { _emitter *last; return getcopy(e, last); }
	_emitter* tail(){ _emitter* e = this; while(e->next) e = e->next; return e; }
	static bool containsremove(_emitter *&a, _emitter *b)
	{
		if(a->equal(b))
		{
			b = a;
			a = a->next;
			delete b;
			return true;
		}
		for(_emitter *c = a->next, *d = a; c!=NULL; c=c->next)
		{
			if(c->equal(b))
			{
				d->next = c->next;
				delete c;
				c = d->next;
				return true;
			}
			d = c;
		}
		return false;
	}
public:
	virtual void emit() = 0;
	virtual _emitter* clone() = 0;
	virtual int size() = 0;
	virtual void* data() = 0;

	template<class Object, class Method>
	friend class _methodemit;
	template<class Object>
	friend class _fnobjectemit;
	
	friend class _functionemit;
	
	friend class action;
	template<class Locker>
	friend class signal;
};

template<class Object, class Method>
class _methodemit : public _emitter
{
	Object* object;
	Method  method;
public:
	_methodemit(Object* object, Method method)
		: object(object), method(method) {}
	void emit()                       { (object->*method)(); }
	_emitter* clone()                 { return new _methodemit(object, method); }
	int size()                        { return sizeof(Object*) + sizeof(Method); };
	void* data()                      { return &object; };
};

template<class Object>
class _fnobjectemit : public _emitter
{
	Object *object;
public:
	_fnobjectemit(Object* object)      : object(object) {}
	void emit()                       { (*object)(); }
	_emitter* clone()                 { return new _fnobjectemit(object); }
	int size()                        { return sizeof(Object *); };
	void* data()                      { return &object; };
};


class _functionemit : public _emitter
{
	typedef void (*function)();
	function fn;
public:
	_functionemit(function fn)        : fn(fn) {}
	void emit()                       { (*fn)(); }
	_emitter* clone()                 { return new _functionemit(fn); }
	int size()                        { return sizeof(function); };
	void* data()                      { return &fn; };
};


class action
{
	template<class Locker>
	friend class signal;

	_emitter* e;
	action(_emitter* e)               : e(e) {}
public:
	action()                          : e(NULL){}
	~action()                         { clear(); }


	action(const action& a)           : e(_emitter::getcopy(a.e)){}
	action& operator=(const action& src)
	{ if(this != &src) { this->action::~action(); ::new(this) action(src); } return *this; }
	action(void (*fn)())           : e(new _functionemit(fn)){}
	action& operator=(void (*fn)())
	{ this->action::~action(); e = new _functionemit(fn); return *this; }
	template<class T>
	action& operator=(const T* t)
	{ this->action::~action(); e = new _fnobjectemit<const T>(t);return *this; }
	template<class T>
	action& operator=(T* t)
	{ this->action::~action(); e = new _fnobjectemit<T>(t);return *this; }

	void operator()()                 
	{ for(_emitter *b = e; b !=NULL; b->emit(), b = b->next); }
	bool empty() { return e == NULL; }
	void clear()
	{ for(_emitter *b = e, *c; b !=NULL; c = b, b = b->next, delete c); }

	template<class T>
	action operator+(const T* b)const  { return *this + from(b); }
	template<class T>
	action operator-(const T* b)const  { return *this - from(b); }
	template<class T>
	action operator&(const T* b)const  { return *this & from(b); }
	template<class T>
	action& operator+=(const T* b)     { return *this += from(b); }
	template<class T>
	action& operator-=(const T* b)     { return *this -= from(b); }
	template<class T>
	action& operator&=(const T* b)     { return *this &= from(b); }
	template<class T>
	action operator+(T* b)const  { return *this + from(b); }
	template<class T>
	action operator-(T* b)const  { return *this - from(b); }
	template<class T>
	action operator&(T* b)const  { return *this & from(b); }
	template<class T>
	action& operator+=(T* b)     { return *this += from(b); }
	template<class T>
	action& operator-=(T* b)     { return *this -= from(b); }
	template<class T>
	action& operator&=(T* b)     { return *this &= from(b); }

	action operator+(const action& b)const
	{
		if(this->e)
		{
			_emitter *c, *ret = _emitter::getcopy(this->e, c);
			c->next = _emitter::getcopy(b.e);
			return ret;
		}
		return _emitter::getcopy(b.e);
	}
	action operator-(const action& b)const
	{
		_emitter*ret = NULL, *c, *d, *e = _emitter::getcopy(b.e);
		for(c = this->e; c != NULL; c = c->next)
			if(e == NULL || !_emitter::containsremove(e, c))
			{
				if(ret)
				{
					d->next = c->clone();
					d = d->next;
				}
				else
				{
					ret = d = c->clone();
				}
			}
			return ret;
	}
	action operator&(const action& b)const
	{
		_emitter*ret = NULL, *c, *d, *e = _emitter::getcopy(b.e);
		for(c = this->e; c != NULL; c = c->next)
			if(_emitter::containsremove(e, c))
			{
				if(ret)
				{
					d->next = c->clone();
					d = d->next;
				}
				else
				{
					ret = d = c->clone();
				}
			}
			else if(e == NULL)
				break;
		return ret;
	}
	action& operator+=(const action& b)
	{
		if(this == &b)
			return *this;
		if(this->e)
			this->e->tail()->next = _emitter::getcopy(b.e);
		else
			this->e =_emitter::getcopy(b.e);
		return *this;
	}
	action& operator-=(const action& b)
	{
		if(this == &b)
		{
			this->clear();
			return *this;
		}
		_emitter *c, *d, *e = _emitter::getcopy(b.e);
		for(c = this->e; c != NULL;)
			if(_emitter::containsremove(e, c))
			{
				if(c == this->e)
				{
					this->e = c->next;
					delete c;
					c = this->e;
				}
				else
				{
					d->next = c->next;
					delete c;
					c = d->next;
				}
				if(e == NULL)
					break;
			}
			else
			{
				d = c;
				c = c->next;
			}
			return *this;
	}
	action& operator&=(const action& b)
	{
		if(this == &b)
			return *this;
		_emitter *c, *d, *e = _emitter::getcopy(b.e);
		for(c = this->e; c != NULL;)
			if(!_emitter::containsremove(e, c))
			{
				if(c == this->e)
				{
					this->e = c->next;
					delete c;
					c = this->e;
				}
				else
				{
					d->next = c->next;
					delete c;
					c = d->next;
				}
			}
			else
			{
				if(e == NULL)
					break;
				d = c;
				c = c->next;
			}
			return *this;
	}

	template<class Object, class Method>
	friend action getaction(const Object *object, void (Method::*method)() const)
	{ return action(new _methodemit<const Object, void (Method::*)() const>(object, method)); }
	template<class Object, class Method>
	friend action getaction(Object *object, void (Method::*method)())
	{ return action(new _methodemit<Object, void (Method::*)()>(object, method)); }
	template<class Object>
	friend action getaction(const Object *object)
	{ return action(new _fnobjectemit<const Object>(object)); }
	template<class Object>
	friend action getaction(Object *object)
	{ return action(new _fnobjectemit<Object>(object)); }
	
	friend action getaction(void (*fn)())
	{ return action(new _functionemit(fn)); }

	template<class Object>
	static inline action from(const Object *object)
	{return action(new _fnobjectemit<const Object>(object));}
	template<class Object>
	static inline action from(Object *object)
	{return action(new _fnobjectemit<Object>(object));}
};

template<class Locker = defaultlocker>
class signal
{
	Locker k, k2;
	action actions;
	volatile int version;

	void operator=(const signal& src){}
	signal(const signal& src){}
public:
	signal():version(0){}
	void operator()()
	{
		action a;
		int ver;
		{
			lockerguard<Locker> guard(k);
			a.e = _emitter::getcopy(actions.e);
			ver = version;
		}
		_emitter *&e =a.e, *b;
		while(e)
		{
			lockerguard<Locker> guard(k);
			if(ver != version)
			{
				a &= actions;
				if(a.e == NULL)
					return;
			}
			lockerguard<Locker> guard2(k2);
			guard.release();
			(b = e)->emit();
			e = e->next;
			delete b;
		}
	}

	template<class T>
	signal<Locker> & operator+=(const T& a)
	{
		lockerguard<Locker> guard(k);
		actions += a;
		return *this;
	}

	template<class T>
	signal<Locker> & operator=(const T& a)
	{
		lockerguard<Locker> guard(k);
		actions &= a;
		return *this;
	}

	template<class T>
	signal<Locker> & operator-=(const T& a)
	{
		{
			lockerguard<Locker> guard(k);
			actions -= a;
			version++;
		}
		lockerguard<Locker> guard2(k2);
		return *this;
	}

	template<class T>
	signal<Locker> & operator+=(T& a)
	{
		lockerguard<Locker> guard(k);
		actions += a;
		return *this;
	}

	template<class T>
	signal<Locker> & operator&=(T& a)
	{
		lockerguard<Locker> guard(k);
		actions &= a;
		return *this;
	}

	template<class T>
	signal<Locker> & operator-=(T& a)
	{
		{
			lockerguard<Locker> guard(k);
			actions -= a;
			version++;
		}
		lockerguard<Locker> guard2(k2);
		return *this;
	}

	void clear()
	{
		lockerguard<Locker> guard(k);
		actions.clear();
	}
};

#include "number0.h"
#include "repeat0.h"
#include "repeat1.h"

#define JUST_NAME(name,n1,n2,n3) NUMBERNNN(name,,n1,n2,n3)

#define T_DEF(n1,n2,n3) typename NUMBERNNN(T,,n1,n2,n3)
#define T_DEF_B(n1,n2,n3) , typename NUMBERNNN(T,,n1,n2,n3)
#define TS_DEF(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,T_DEF,T_DEF_B)
#define T_USE(n1,n2,n3) NUMBERNNN(T,,n1,n2,n3)
#define T_USE_B(n1,n2,n3) , NUMBERNNN(T,,n1,n2,n3)
#define TS_USE(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,T_USE,T_USE_B)

#define P_DEF(n1,n2,n3) typename NUMBERNNN(P,,n1,n2,n3)
#define P_DEF_B(n1,n2,n3) , typename NUMBERNNN(P,,n1,n2,n3)
#define PS_DEF(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,P_DEF,P_DEF_B)
#define P_USE(n1,n2,n3) NUMBERNNN(P,,n1,n2,n3)
#define P_USE_B(n1,n2,n3) , NUMBERNNN(P,,n1,n2,n3)
#define PS_USE(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,P_USE,P_USE_B)

#define ARG_DEF(n1,n2,n3) NUMBERNNN(T,,n1,n2,n3) NUMBERNNN(arg,,n1,n2,n3)
#define ARG_DEF_B(n1,n2,n3) , NUMBERNNN(T,,n1,n2,n3) NUMBERNNN(arg,,n1,n2,n3)
#define ARGS_DEF(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,ARG_DEF,ARG_DEF_B)
#define ARG_USE(n1,n2,n3) NUMBERNNN(arg,,n1,n2,n3)
#define ARG_USE_B(n1,n2,n3) , NUMBERNNN(arg,,n1,n2,n3)
#define ARGS_USE(n1,n2,n3) _REPEATC_NNN(n1,n2,n3,ARG_USE,ARG_USE_B)

#define SIGACT_DEF(n1,n2,n3)\
template<TS_DEF(n1,n2,n3)> \
class JUST_NAME(_emitter,n1,n2,n3) \
{ \
	typedef JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> emittertype; \
	emittertype* next; \
	JUST_NAME(_emitter,n1,n2,n3)()   :next(NULL){} \
	bool equal(emittertype* e)       { return e && size() == e->size() && memcmp(data(), e->data(), size()) == 0; } \
	emittertype* tail()              { emittertype* e = this; while(e->next) e = e->next; return e; } \
	static emittertype* getcopy(emittertype* e, emittertype *&last) \
	{ \
		if(e == NULL) \
			return NULL; \
		emittertype* a = e->clone(); \
		last = a; \
		while(e = e->next) \
		{ \
			last->next = e->clone(); \
			last = last->next; \
		} \
		return a; \
	} \
	static emittertype* getcopy(emittertype* e) { emittertype *last; return getcopy(e, last); } \
	static bool containsremove(emittertype *&a, emittertype *b) \
	{ \
		if(a->equal(b)) \
		{ \
			b = a; \
			a = a->next; \
			delete b; \
			return true; \
		} \
		for(emittertype *c = a->next, *d = a; c!=NULL; c=c->next) \
		{ \
			if(c->equal(b)) \
			{ \
				d->next = c->next; \
				delete c; \
				c = d->next; \
				return true; \
			} \
			d = c; \
		} \
		return false; \
	} \
public: \
	virtual void emit(ARGS_DEF(n1,n2,n3)) = 0; \
	virtual emittertype* clone() = 0; \
	virtual int size() = 0; \
	virtual void* data() = 0; \
	 \
	template<class Object, class Method, PS_DEF(n1,n2,n3)> \
	friend class JUST_NAME(_methodemit,n1,n2,n3); \
	template<class Object, PS_DEF(n1,n2,n3)> \
	friend class JUST_NAME(_fnobjectemit,n1,n2,n3); \
	template<PS_DEF(n1,n2,n3)> \
	friend class JUST_NAME(_functionemit,n1,n2,n3); \
	template<PS_DEF(n1,n2,n3)> \
	friend class JUST_NAME(action,n1,n2,n3); \
	template<PS_DEF(n1,n2,n3), class Locker> \
	friend class JUST_NAME(signal,n1,n2,n3); \
}; \
	 \
template<class Object, class Method, TS_DEF(n1,n2,n3)> \
class JUST_NAME(_methodemit,n1,n2,n3) : public JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> \
{ \
	Object* object; \
	Method  method; \
public: \
	JUST_NAME(_methodemit,n1,n2,n3)(Object* object, Method method) \
		                              : object(object), method(method) {} \
	void emit(ARGS_DEF(n1,n2,n3))     { (object->*method)(ARGS_USE(n1,n2,n3)); } \
	JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)>* clone() \
	                                  { return new JUST_NAME(_methodemit,n1,n2,n3)(object, method); } \
	int size()                        { return sizeof(Object*) + sizeof(Method); }; \
	void* data()                      { return &object; }; \
}; \
	 \
template<class Object, TS_DEF(n1,n2,n3)> \
class JUST_NAME(_fnobjectemit,n1,n2,n3) : public JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> \
{ \
	Object *object; \
public: \
	JUST_NAME(_fnobjectemit,n1,n2,n3)(Object* object) \
	                                  : object(object) {} \
	void emit(ARGS_DEF(n1,n2,n3))     { (*object)(ARGS_USE(n1,n2,n3)); } \
	JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)>* clone() \
	                                  { return new JUST_NAME(_fnobjectemit,n1,n2,n3)(object); } \
	int size()                        { return sizeof(Object *); }; \
	void* data()                      { return &object; }; \
}; \
	 \
template<TS_DEF(n1,n2,n3)> \
class JUST_NAME(_functionemit,n1,n2,n3) : public JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> \
{ \
	typedef void (*function)(TS_USE(n1,n2,n3)); \
	function fn; \
public: \
	JUST_NAME(_functionemit,n1,n2,n3)(function fn) \
	                                  : fn(fn) {} \
	void emit(ARGS_DEF(n1,n2,n3))     { (*fn)(ARGS_USE(n1,n2,n3)); } \
	JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)>* clone() \
	                                  { return new JUST_NAME(_functionemit,n1,n2,n3)(fn); } \
	int size()                        { return sizeof(function); }; \
	void* data()                      { return &fn; }; \
}; \
	 \
template<TS_DEF(n1,n2,n3)> \
class JUST_NAME(action,n1,n2,n3) \
{ \
	template<PS_DEF(n1,n2,n3), class Locker> \
	friend class JUST_NAME(signal,n1,n2,n3); \
	typedef JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)> actiontype; \
	typedef JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> emittertype; \
	typedef JUST_NAME(_functionemit,n1,n2,n3)<TS_USE(n1,n2,n3)> functionemittype; \
	 \
	emittertype* e; \
	JUST_NAME(action,n1,n2,n3)(emittertype* e)                         : e(e) {} \
public: \
	JUST_NAME(action,n1,n2,n3)()                                       : e(NULL){} \
	~JUST_NAME(action,n1,n2,n3)()                                      { clear(); } \
	 \
	JUST_NAME(action,n1,n2,n3)(const JUST_NAME(action,n1,n2,n3)& a)    : e(emittertype::getcopy(a.e)){} \
	actiontype& operator=(const actiontype& src) \
	{ if(this != &src) { this->actiontype::~JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)>(); ::new(this) actiontype(src); } return *this; } \
	actiontype& operator=(actiontype& src) \
	{ if(this != &src) { this->actiontype::~JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)>(); ::new(this) actiontype(src); } return *this; } \
	 \
	JUST_NAME(action,n1,n2,n3)(void (*fn)(TS_USE(n1,n2,n3)))  :e(new functionemittype(fn)) {} \
	actiontype& operator=(void (*fn)(TS_USE(n1,n2,n3))) \
	{ this->actiontype::~JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)>(); e = new functionemittype(fn);return *this; } \
	 \
	template<class T> actiontype& operator=(const T* t) \
	{ this->actiontype::~JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)>(); e = new JUST_NAME(_fnobjectemit,n1,n2,n3)<const T, TS_USE(n1,n2,n3)>(t);return *this; } \
	template<class T> actiontype& operator=(T* t) \
	{ this->actiontype::~JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)>(); e = new JUST_NAME(_fnobjectemit,n1,n2,n3)<T, TS_USE(n1,n2,n3)>(t);return *this; } \
	 \
	void operator()(ARGS_DEF(n1,n2,n3))                  \
	{ for(emittertype *b = e; b !=NULL; b->emit(ARGS_USE(n1,n2,n3)), b = b->next); } \
	bool empty() { return e == NULL; } \
	void clear() { for(emittertype *b = e, *c; b !=NULL; c = b, b = b->next, delete c); } \
	 \
	template<class T> actiontype operator+(const T* b)const  { return *this + from(b); } \
	template<class T> actiontype operator-(const T* b)const  { return *this - from(b); } \
	template<class T> actiontype operator&(const T* b)const  { return *this & from(b); } \
	template<class T> actiontype& operator+=(const T* b)     { return *this += from(b); } \
	template<class T> actiontype& operator-=(const T* b)     { return *this -= from(b); } \
	template<class T> actiontype& operator&=(const T* b)     { return *this &= from(b); } \
	template<class T> actiontype operator+(T* b)const  { return *this + from(b); } \
	template<class T> actiontype operator-(T* b)const  { return *this - from(b); } \
	template<class T> actiontype operator&(T* b)const  { return *this & from(b); } \
	template<class T> actiontype& operator+=(T* b)     { return *this += from(b); } \
	template<class T> actiontype& operator-=(T* b)     { return *this -= from(b); } \
	template<class T> actiontype& operator&=(T* b)     { return *this &= from(b); } \
	 \
	actiontype operator+(const actiontype& b)const \
	{ \
		if(this->e) \
		{ \
			emittertype *c, *ret = emittertype::getcopy(this->e, c); \
			c->next = emittertype::getcopy(b.e); \
			return ret; \
		} \
		return emittertype::getcopy(b.e); \
	} \
	actiontype operator-(const actiontype& b)const \
	{ \
		emittertype*ret = NULL, *c, *d, *e = emittertype::getcopy(b.e); \
		for(c = this->e; c != NULL; c = c->next) \
			if(e == NULL || !emittertype::containsremove(e, c)) \
			{ \
				if(ret) \
				{ \
					d->next = c->clone(); \
					d = d->next; \
				} \
				else \
				{ \
					ret = d = c->clone(); \
				} \
			} \
			return ret; \
	} \
	actiontype operator&(const actiontype& b)const \
	{ \
		emittertype*ret = NULL, *c, *d, *e = emittertype::getcopy(b.e); \
		for(c = this->e; c != NULL; c = c->next) \
			if(emittertype::containsremove(e, c)) \
			{ \
				if(ret) \
				{ \
					d->next = c->clone(); \
					d = d->next; \
				} \
				else \
				{ \
					ret = d = c->clone(); \
				} \
			} \
			else if(e == NULL) \
				break; \
		return ret; \
	} \
	actiontype& operator+=(const actiontype& b) \
	{ \
		if(this == &b) \
			return *this; \
		if(this->e) \
			this->e->tail()->next = emittertype::getcopy(b.e); \
		else \
			this->e =emittertype::getcopy(b.e); \
		return *this; \
	} \
	actiontype& operator-=(const actiontype& b) \
	{ \
		if(this == &b) \
		{ \
			this->clear(); \
			return *this; \
		} \
		emittertype *c, *d, *e = emittertype::getcopy(b.e); \
		for(c = this->e; c != NULL;) \
			if(emittertype::containsremove(e, c)) \
			{ \
				if(c == this->e) \
				{ \
					this->e = c->next; \
					delete c; \
					c = this->e; \
				} \
				else \
				{ \
					d->next = c->next; \
					delete c; \
					c = d->next; \
				} \
				if(e == NULL) \
					break; \
			} \
			else \
			{ \
				d = c; \
				c = c->next; \
			} \
			return *this; \
	} \
	actiontype& operator&=(const actiontype& b) \
	{ \
		if(this == &b) \
			return *this; \
		emittertype *c, *d, *e = emittertype::getcopy(b.e); \
		for(c = this->e; c != NULL;) \
			if(!emittertype::containsremove(e, c)) \
			{ \
				if(c == this->e) \
				{ \
					this->e = c->next; \
					delete c; \
					c = this->e; \
				} \
				else \
				{ \
					d->next = c->next; \
					delete c; \
					c = d->next; \
				} \
			} \
			else \
			{ \
				if(e == NULL) \
					break; \
				d = c; \
				c = c->next; \
			} \
			return *this; \
	} \
	 \
	template<class Object, class Method, PS_DEF(n1,n2,n3)> \
	friend JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)> JUST_NAME(getaction,n1,n2,n3)(const Object *object, void (Method::*method)(PS_USE(n1,n2,n3)) const) \
	{ return JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)>(new JUST_NAME(_methodemit,n1,n2,n3)<const Object, void (Method::*)(PS_USE(n1,n2,n3)) const, PS_USE(n1,n2,n3)>(object, method)); } \
	template<class Object, class Method, PS_DEF(n1,n2,n3)> \
	friend JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)> JUST_NAME(getaction,n1,n2,n3)(Object *object, void (Method::*method)(PS_USE(n1,n2,n3))) \
	{ return JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)>(new JUST_NAME(_methodemit,n1,n2,n3)<Object, void (Method::*)(PS_USE(n1,n2,n3)), PS_USE(n1,n2,n3)>(object, method)); } \
	template<class Object, PS_DEF(n1,n2,n3)> \
	friend JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)> JUST_NAME(getaction,n1,n2,n3)(const Object *object) \
	{ return JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)>(new JUST_NAME(_fnobjectemit,n1,n2,n3)<const Object, PS_USE(n1,n2,n3)>(object)); } \
	template<class Object, PS_DEF(n1,n2,n3)> \
	friend JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)> JUST_NAME(getaction,n1,n2,n3)(Object *object) \
	{ return JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)>(new JUST_NAME(_fnobjectemit,n1,n2,n3)<Object, PS_USE(n1,n2,n3)>(object)); } \
	template<PS_DEF(n1,n2,n3)> \
	friend JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)> JUST_NAME(getaction,n1,n2,n3)(void (*fn)(PS_USE(n1,n2,n3))) \
	{ return JUST_NAME(action,n1,n2,n3)<PS_USE(n1,n2,n3)>(new JUST_NAME(_functionemit,n1,n2,n3)<PS_USE(n1,n2,n3)>(fn)); } \
	 \
	template<class Object> \
	static inline actiontype from(const Object *object) \
	{return JUST_NAME(action,n1,n2,n3)(new JUST_NAME(_fnobjectemit,n1,n2,n3)<const Object, TS_USE(n1,n2,n3)>(object));} \
	template<class Object> \
	static inline actiontype from(Object *object) \
	{return actiontype(new JUST_NAME(_fnobjectemit,n1,n2,n3)<Object, TS_USE(n1,n2,n3)>(object));} \
}; \
	 \
template<TS_DEF(n1,n2,n3), class Locker = defaultlocker> \
class JUST_NAME(signal,n1,n2,n3) \
{ \
	typedef JUST_NAME(signal,n1,n2,n3)<TS_USE(n1,n2,n3), Locker> signaltype; \
	typedef JUST_NAME(action,n1,n2,n3)<TS_USE(n1,n2,n3)> actiontype; \
	typedef JUST_NAME(_emitter,n1,n2,n3)<TS_USE(n1,n2,n3)> emittertype; \
	\
	Locker k, k2; \
	actiontype actions; \
	volatile int version; \
	 \
	void operator=(const JUST_NAME(signal,n1,n2,n3)& src){} \
	JUST_NAME(signal,n1,n2,n3)(const JUST_NAME(signal,n1,n2,n3)& src){} \
public: \
	JUST_NAME(signal,n1,n2,n3)():version(0){} \
	void operator()(ARGS_DEF(n1,n2,n3)) \
	{ \
		actiontype a; \
		int ver; \
		{ \
			lockerguard<Locker> guard(k); \
			a.e = emittertype::getcopy(actions.e); \
			ver = version; \
		} \
		emittertype *&e =a.e, *b; \
		while(e) \
		{ \
			lockerguard<Locker> guard(k); \
			if(ver != version) \
			{ \
				a &= actions; \
				if(a.e == NULL) \
					return; \
			} \
			lockerguard<Locker> guard2(k2); \
			guard.release(); \
			(b = e)->emit(ARGS_USE(n1,n2,n3)); \
			e = e->next; \
			delete b; \
		} \
	} \
	 \
	template<class T> signaltype & operator+=(const T& a) \
	{ \
		lockerguard<Locker> guard(k); \
		actions += a; \
		return *this; \
	} \
	 \
	template<class T> signaltype & operator=(const T& a) \
	{ \
		lockerguard<Locker> guard(k); \
		actions &= a; \
		return *this; \
	} \
	 \
	template<class T> signaltype & operator-=(const T& a) \
	{ \
		{ \
			lockerguard<Locker> guard(k); \
			actions -= a; \
			version++; \
		} \
		lockerguard<Locker> guard2(k2); \
		return *this; \
	} \
	 \
	template<class T> signaltype & operator+=(T& a) \
	{ \
		lockerguard<Locker> guard(k); \
		actions += a; \
		return *this; \
	} \
	 \
	template<class T> signaltype & operator&=(T& a) \
	{ \
		lockerguard<Locker> guard(k); \
		actions &= a; \
		return *this; \
	} \
	 \
	template<class T> signaltype & operator-=(T& a) \
	{ \
		{ \
			lockerguard<Locker> guard(k); \
			actions -= a; \
			version++; \
		} \
		lockerguard<Locker> guard2(k2); \
		return *this; \
	} \
	 \
	void clear() \
	{ \
		lockerguard<Locker> guard(k); \
		actions.clear(); \
	} \
}; \

REPEAT_NNN(0,1,0,SIGACT_DEF)

#endif
