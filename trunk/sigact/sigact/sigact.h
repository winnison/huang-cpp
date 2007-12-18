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

namespace sigact{
class locker
{
	_MUTEX_CLASS mutex;
public:
	inline locker()               {_MUTEX_INIT(&mutex);}
	inline locker(const locker&)  {_MUTEX_INIT(&mutex);}
	inline ~locker()              {_MUTEX_DELETE(&mutex);}
	inline void lock()     {_MUTEX_LOCK(&mutex);}
	inline void unlock()   {_MUTEX_UNLOCK(&mutex);}
};

class lockerguard
{
	locker* k;
public:
	inline lockerguard(locker& _k)                 : k(&_k) { k->lock(); }
	inline void release()                          { if(k){k->unlock(); k = NULL;} }
	inline ~lockerguard()                          { if(k) k->unlock(); }
};


// signal empty args-list begin
class action;
class signal;

class _emitter
{
	template<class Object, class Method>
	friend class _methodemit;
	template<class Object>
	friend class _fnobjectemit;
	
	friend class _functionemit;
	
	friend class action;
	friend class signal;
	
	_emitter* next;
	_emitter():next(NULL){}
	bool inline equal(_emitter* e)               { return e && size() == e->size() && memcmp(data(), e->data(), size()) == 0; }
	_emitter* tail()                             { _emitter* e = this; while(e->next) e = e->next; return e; }
	static inline _emitter* getcopy(_emitter* e) { _emitter *last; return getcopy(e, last); }
	static inline _emitter* getcopy(_emitter* e, _emitter *&last)
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
	static inline bool containsremove(_emitter *&a, _emitter *b)
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

template<class Object, class Method>
action getaction(const Object *object, void (Method::*method)() const);
template<class Object, class Method>
action getaction(Object *object, void (Method::*method)());
template<class Object>
action getaction(const Object *object);
template<class Object>
action getaction(Object *object);

action getaction(void (*fn)());

class action
{
	friend class signal;

	_emitter* e;
	inline action(_emitter* e)             : e(e) {}
public:
	action()                               : e(NULL){}
	~action()                              { clear(); }

	action(const action& a)                : e(_emitter::getcopy(a.e)){}
	action& operator=(const action& src)   { if(this != &src) { this->action::~action(); ::new(this) action(src); } return *this; }
	
	inline action& operator=(void (*fn)()) { this->action::~action(); e = new _functionemit(fn); return *this; }
	template<class T> 
	inline action& operator=(const T* t)   { this->action::~action(); e = new _fnobjectemit<const T>(t);return *this; }
	template<class T> 
	inline action& operator=(T* t)         { this->action::~action(); e = new _fnobjectemit<T>(t);return *this; }

	void operator()() const                { for(_emitter *b = e; b !=NULL; b->emit(), b = b->next); }
	action popemit()                       { if(e){ _emitter *b = e; b->emit(); e = e->next; b->next = NULL; return b; } return e; }
	inline bool empty() const              { return e == NULL; }
	void clear()                           { for(_emitter *b = e, *c; b !=NULL; c = b, b = b->next, delete c); }

	template<class T> inline action operator+(const T* b)const { return *this + from(b); }
	template<class T> inline action operator-(const T* b)const { return *this - from(b); }
	template<class T> inline action operator&(const T* b)const { return *this & from(b); }
	template<class T> inline action& operator+=(const T* b)    { return *this += from(b); }
	template<class T> inline action& operator-=(const T* b)    { return *this -= from(b); }
	template<class T> inline action& operator&=(const T* b)    { return *this &= from(b); }
	template<class T> inline action operator+(T* b)const { return *this + from(b); }
	template<class T> inline action operator-(T* b)const { return *this - from(b); }
	template<class T> inline action operator&(T* b)const { return *this & from(b); }
	template<class T> inline action& operator+=(T* b)    { return *this += from(b); }
	template<class T> inline action& operator-=(T* b)    { return *this -= from(b); }
	template<class T> inline action& operator&=(T* b)    { return *this &= from(b); }

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
	friend inline action getaction(const Object *object, void (Method::*method)() const)
	{ return action(new _methodemit<const Object, void (Method::*)() const>(object, method)); }
	template<class Object, class Method>
	friend inline action getaction(Object *object, void (Method::*method)())
	{ return action(new _methodemit<Object, void (Method::*)()>(object, method)); }
	template<class Object>
	friend inline action getaction(const Object *object)
	{ return action(new _fnobjectemit<const Object>(object)); }
	template<class Object>
	friend inline action getaction(Object *object)
	{ return action(new _fnobjectemit<Object>(object)); }
	
	friend inline action getaction(void (*fn)())
	{ return action(new _functionemit(fn)); }

	template<class Object>
	static inline action from(const Object *object)
	{return action(new _fnobjectemit<const Object>(object));}
	template<class Object>
	static inline action from(Object *object)
	{return action(new _fnobjectemit<Object>(object));}
};

class signal
{
	locker k, k2;
	action actions;
	volatile int version;

	signal& operator=(const signal& src)  {}
	signal(const signal& src)             {}
public:
	signal()                               :version(0){}
	signal(const action& a)                :actions(a){}
	operator action()                      { lockerguard guard(k); return actions; }
	void operator()()
	{
		action a;
		int ver;
		{
			lockerguard guard(k);
			a.e = _emitter::getcopy(actions.e);
			ver = version;
		}
		while(!a.empty())
		{
			lockerguard guard(k);
			if(ver != version)
			{
				a &= actions;
				if(a.empty())
					return;
			}
			lockerguard guard2(k2);
			guard.release();
			a.popemit();
		}
	}

	signal & ensure()               { { lockerguard guard(k2); } return *this; }
	signal & clear()                { { lockerguard guard(k); actions.clear(); version++; } return *this; }
	template<class T> 
	signal & operator+=(const T& a) { {	lockerguard guard(k); actions += a; } return *this; }
	template<class T> 
	signal & operator&=(const T& a) { { lockerguard guard(k); actions &= a; } return *this; }
	template<class T> 
	signal & operator-=(const T& a) { { lockerguard guard(k); actions -= a; version++; } return *this; }
	template<class T> 
	signal & operator=(const T& a)  { { lockerguard guard(k); actions = a; version++; } return *this; }
};

#include "number0.h"
#include "repeat0.h"
#include "repeat1.h"

#define __NAME_ACTION(n1,n2,n3)       NUMBERNNN(action,,n1,n2,n3)
#define __NAME_SIGNAL(n1,n2,n3)       NUMBERNNN(signal,,n1,n2,n3)
#define __NAME_EMITTER(n1,n2,n3)      NUMBERNNN(_emitter,,n1,n2,n3)
#define __NAME_METHODEMIT(n1,n2,n3)   NUMBERNNN(_methodemit,,n1,n2,n3)
#define __NAME_FUNCEMIT(n1,n2,n3)     NUMBERNNN(_functionemit,,n1,n2,n3)
#define __NAME_FNOBJEMIT(n1,n2,n3)    NUMBERNNN(_fnobjectemit,,n1,n2,n3)
#define __NAME_GETACTION(n1,n2,n3)    NUMBERNNN(getaction,,n1,n2,n3)

#define __T_DEF(n1,n2,n3)     typename NUMBERNNN(T,,n1,n2,n3)
#define __T_DEF_B(n1,n2,n3)   , typename NUMBERNNN(T,,n1,n2,n3)
#define __TS_DEF(n1,n2,n3)    _REPEATC_NNN(n1,n2,n3,__T_DEF,__T_DEF_B)
#define __T_USE(n1,n2,n3)     NUMBERNNN(T,,n1,n2,n3)
#define __T_USE_B(n1,n2,n3)   , NUMBERNNN(T,,n1,n2,n3)
#define __TS_USE(n1,n2,n3)    _REPEATC_NNN(n1,n2,n3,__T_USE,__T_USE_B)

#define __P_DEF(n1,n2,n3)     typename NUMBERNNN(P,,n1,n2,n3)
#define __P_DEF_B(n1,n2,n3)   , typename NUMBERNNN(P,,n1,n2,n3)
#define __PS_DEF(n1,n2,n3)    _REPEATC_NNN(n1,n2,n3,__P_DEF,__P_DEF_B)
#define __P_USE(n1,n2,n3)     NUMBERNNN(P,,n1,n2,n3)
#define __P_USE_B(n1,n2,n3)   , NUMBERNNN(P,,n1,n2,n3)
#define __PS_USE(n1,n2,n3)    _REPEATC_NNN(n1,n2,n3,__P_USE,__P_USE_B)

#define __ARG_DEF(n1,n2,n3)   NUMBERNNN(T,,n1,n2,n3) NUMBERNNN(arg,,n1,n2,n3)
#define __ARG_DEF_B(n1,n2,n3) , NUMBERNNN(T,,n1,n2,n3) NUMBERNNN(arg,,n1,n2,n3)
#define __ARGS_DEF(n1,n2,n3)  _REPEATC_NNN(n1,n2,n3,__ARG_DEF,__ARG_DEF_B)
#define __ARG_USE(n1,n2,n3)   NUMBERNNN(arg,,n1,n2,n3)
#define __ARG_USE_B(n1,n2,n3) , NUMBERNNN(arg,,n1,n2,n3)
#define __ARGS_USE(n1,n2,n3)  _REPEATC_NNN(n1,n2,n3,__ARG_USE,__ARG_USE_B)

#define SIGACT_DECLARATION(n1,n2,n3)\
template<__TS_DEF(n1,n2,n3)> \
class __NAME_ACTION(n1,n2,n3); \
template<__TS_DEF(n1,n2,n3)> \
class __NAME_SIGNAL(n1,n2,n3); \
	 \
template<__TS_DEF(n1,n2,n3)> \
class __NAME_EMITTER(n1,n2,n3) \
{ \
	template<class Object, class Method, __PS_DEF(n1,n2,n3)> \
	friend class __NAME_METHODEMIT(n1,n2,n3); \
	template<class Object, __PS_DEF(n1,n2,n3)> \
	friend class __NAME_FNOBJEMIT(n1,n2,n3); \
	template<__PS_DEF(n1,n2,n3)> \
	friend class __NAME_FUNCEMIT(n1,n2,n3); \
	template<__PS_DEF(n1,n2,n3)> \
	friend class __NAME_ACTION(n1,n2,n3); \
	template<__PS_DEF(n1,n2,n3)> \
	friend class __NAME_SIGNAL(n1,n2,n3); \
	 \
	typedef __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> emittertype; \
	emittertype* next; \
	inline __NAME_EMITTER(n1,n2,n3)()   :next(NULL){} \
	inline bool equal(emittertype* e)       { return e && size() == e->size() && memcmp(data(), e->data(), size()) == 0; } \
	inline emittertype* tail()              { emittertype* e = this; while(e->next) e = e->next; return e; } \
	static inline emittertype* getcopy(emittertype* e, emittertype *&last) \
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
	static inline emittertype* getcopy(emittertype* e) { emittertype *last; return getcopy(e, last); } \
	static inline bool containsremove(emittertype *&a, emittertype *b) \
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
	virtual void emit(__ARGS_DEF(n1,n2,n3)) = 0; \
	virtual emittertype* clone() = 0; \
	virtual int size() = 0; \
	virtual const void* data() = 0; \
}; \
	 \
template<class Object, class Method, __TS_DEF(n1,n2,n3)> \
class __NAME_METHODEMIT(n1,n2,n3) : public __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> \
{ \
	Object* object; \
	Method  method; \
public: \
	__NAME_METHODEMIT(n1,n2,n3)(Object* object, Method method) \
		                              : object(object), method(method) {} \
	void emit(__ARGS_DEF(n1,n2,n3))  { (object->*method)(__ARGS_USE(n1,n2,n3)); } \
	__NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)>* clone() \
	                                 { return new __NAME_METHODEMIT(n1,n2,n3)(object, method); } \
	int size()                       { return sizeof(Object*) + sizeof(Method); }; \
	const void* data()               { return &object; }; \
}; \
	 \
template<class Object, __TS_DEF(n1,n2,n3)> \
class __NAME_FNOBJEMIT(n1,n2,n3) : public __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> \
{ \
	Object *object; \
public: \
	__NAME_FNOBJEMIT(n1,n2,n3)(Object* object) \
	                                  : object(object) {} \
	void emit(__ARGS_DEF(n1,n2,n3)) { (*object)(__ARGS_USE(n1,n2,n3)); } \
	__NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)>* clone() \
	                                { return new __NAME_FNOBJEMIT(n1,n2,n3)(object); } \
	int size()                      { return sizeof(Object *); }; \
	const void* data()              { return &object; }; \
}; \
	 \
template<__TS_DEF(n1,n2,n3)> \
class __NAME_FUNCEMIT(n1,n2,n3) : public __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> \
{ \
	typedef void (*function)(__TS_USE(n1,n2,n3)); \
	function fn; \
public: \
	__NAME_FUNCEMIT(n1,n2,n3)(function fn) \
	                                  : fn(fn) {} \
	void emit(__ARGS_DEF(n1,n2,n3)) { (*fn)(__ARGS_USE(n1,n2,n3)); } \
	__NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)>* clone() \
	                                { return new __NAME_FUNCEMIT(n1,n2,n3)(fn); } \
	int size()                      { return sizeof(function); }; \
	const void* data()              { return &fn; }; \
}; \
	 \
template<class Object, class Method, __PS_DEF(n1,n2,n3)> \
__NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(const Object *object, void (Method::*method)(__PS_USE(n1,n2,n3)) const); \
template<class Object, class Method, __PS_DEF(n1,n2,n3)> \
__NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(Object *object, void (Method::*method)(__PS_USE(n1,n2,n3))); \
template<class Object, __PS_DEF(n1,n2,n3)> \
__NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(const Object *object); \
template<class Object, __PS_DEF(n1,n2,n3)> \
__NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(Object *object); \
template<__PS_DEF(n1,n2,n3)> \
__NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(void (*fn)(__PS_USE(n1,n2,n3))); \
	 \
template<__TS_DEF(n1,n2,n3)> \
class __NAME_ACTION(n1,n2,n3) \
{ \
	template<__PS_DEF(n1,n2,n3)> \
	friend class __NAME_SIGNAL(n1,n2,n3); \
	typedef __NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)> actiontype; \
	typedef __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> emittertype; \
	typedef __NAME_FUNCEMIT(n1,n2,n3)<__TS_USE(n1,n2,n3)> functionemittype; \
	 \
	emittertype* e; \
	inline __NAME_ACTION(n1,n2,n3)(emittertype* e)                   : e(e) {} \
public: \
	__NAME_ACTION(n1,n2,n3)()                                 : e(NULL){} \
	~__NAME_ACTION(n1,n2,n3)()                                { clear(); } \
	 \
	__NAME_ACTION(n1,n2,n3)(const __NAME_ACTION(n1,n2,n3)& a) : e(emittertype::getcopy(a.e)){} \
	inline actiontype& operator=(const actiontype& src) \
	{ if(this != &src) { this->actiontype::~__NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)>(); ::new(this) actiontype(src); } return *this; } \
	 \
	inline actiontype& operator=(void (*fn)(__TS_USE(n1,n2,n3))) \
	{ this->actiontype::~__NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)>(); e = new functionemittype(fn);return *this; } \
	template<class T> \
	inline actiontype& operator=(const T* t) \
	{ this->actiontype::~__NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)>(); e = new __NAME_FNOBJEMIT(n1,n2,n3)<const T, __TS_USE(n1,n2,n3)>(t);return *this; } \
	template<class T> \
	inline actiontype& operator=(T* t) \
	{ this->actiontype::~__NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)>(); e = new __NAME_FNOBJEMIT(n1,n2,n3)<T, __TS_USE(n1,n2,n3)>(t);return *this; } \
	 \
	void operator()(__ARGS_DEF(n1,n2,n3)) const\
	{ for(emittertype *b = e; b !=NULL; b->emit(__ARGS_USE(n1,n2,n3)), b = b->next); } \
	actiontype popemit(__ARGS_DEF(n1,n2,n3))       { if(e){ emittertype *b = e; b->emit(__ARGS_USE(n1,n2,n3)); e = e->next; b->next = NULL; return b; } return e; } \
	inline bool empty() const  { return e == NULL; } \
	void clear()               { for(emittertype *b = e, *c; b !=NULL; c = b, b = b->next, delete c); } \
	 \
	template<class T> inline actiontype operator+(const T* b)const { return *this + from(b); } \
	template<class T> inline actiontype operator-(const T* b)const { return *this - from(b); } \
	template<class T> inline actiontype operator&(const T* b)const { return *this & from(b); } \
	template<class T> inline actiontype& operator+=(const T* b)    { return *this += from(b); } \
	template<class T> inline actiontype& operator-=(const T* b)    { return *this -= from(b); } \
	template<class T> inline actiontype& operator&=(const T* b)    { return *this &= from(b); } \
	template<class T> inline actiontype operator+(T* b)const       { return *this + from(b); } \
	template<class T> inline actiontype operator-(T* b)const       { return *this - from(b); } \
	template<class T> inline actiontype operator&(T* b)const       { return *this & from(b); } \
	template<class T> inline actiontype& operator+=(T* b)          { return *this += from(b); } \
	template<class T> inline actiontype& operator-=(T* b)          { return *this -= from(b); } \
	template<class T> inline actiontype& operator&=(T* b)          { return *this &= from(b); } \
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
	template<class Object, class Method, __PS_DEF(n1,n2,n3)> \
	friend inline __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(const Object *object, void (Method::*method)(__PS_USE(n1,n2,n3)) const) \
	{ return __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)>(new __NAME_METHODEMIT(n1,n2,n3)<const Object, void (Method::*)(__PS_USE(n1,n2,n3)) const, __PS_USE(n1,n2,n3)>(object, method)); } \
	template<class Object, class Method, __PS_DEF(n1,n2,n3)> \
	friend inline __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(Object *object, void (Method::*method)(__PS_USE(n1,n2,n3))) \
	{ return __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)>(new __NAME_METHODEMIT(n1,n2,n3)<Object, void (Method::*)(__PS_USE(n1,n2,n3)), __PS_USE(n1,n2,n3)>(object, method)); } \
	template<class Object, __PS_DEF(n1,n2,n3)> \
	friend inline __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(const Object *object) \
	{ return __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)>(new __NAME_FNOBJEMIT(n1,n2,n3)<const Object, __PS_USE(n1,n2,n3)>(object)); } \
	template<class Object, __PS_DEF(n1,n2,n3)> \
	friend inline __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(Object *object) \
	{ return __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)>(new __NAME_FNOBJEMIT(n1,n2,n3)<Object, __PS_USE(n1,n2,n3)>(object)); } \
	template<__PS_DEF(n1,n2,n3)> \
	friend inline __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)> __NAME_GETACTION(n1,n2,n3)(void (*fn)(__PS_USE(n1,n2,n3))) \
	{ return __NAME_ACTION(n1,n2,n3)<__PS_USE(n1,n2,n3)>(new __NAME_FUNCEMIT(n1,n2,n3)<__PS_USE(n1,n2,n3)>(fn)); } \
	 \
	template<class Object> \
	static inline actiontype from(const Object *object) \
	{return __NAME_ACTION(n1,n2,n3)(new __NAME_FNOBJEMIT(n1,n2,n3)<const Object, __TS_USE(n1,n2,n3)>(object));} \
	template<class Object> \
	static inline actiontype from(Object *object) \
	{return actiontype(new __NAME_FNOBJEMIT(n1,n2,n3)<Object, __TS_USE(n1,n2,n3)>(object));} \
}; \
	 \
template<__TS_DEF(n1,n2,n3)> \
class __NAME_SIGNAL(n1,n2,n3) \
{ \
	typedef __NAME_SIGNAL(n1,n2,n3)<__TS_USE(n1,n2,n3)> signaltype; \
	typedef __NAME_ACTION(n1,n2,n3)<__TS_USE(n1,n2,n3)> actiontype; \
	typedef __NAME_EMITTER(n1,n2,n3)<__TS_USE(n1,n2,n3)> emittertype; \
	\
	locker k, k2; \
	actiontype actions; \
	volatile int version; \
	 \
	signaltype operator=(const signaltype& src)    {} \
	__NAME_SIGNAL(n1,n2,n3)(const signaltype& src) {} \
public: \
	__NAME_SIGNAL(n1,n2,n3)()                      :version(0){} \
	__NAME_SIGNAL(n1,n2,n3)(const actiontype& a)   :actions(a){} \
	operator actiontype()                          { lockerguard guard(k); return actions; } \
	void operator()(__ARGS_DEF(n1,n2,n3)) \
	{ \
		actiontype a; \
		int ver; \
		{ \
			lockerguard guard(k); \
			a.e = emittertype::getcopy(actions.e); \
			ver = version; \
		} \
		while(!a.empty()) \
		{ \
			lockerguard guard(k); \
			if(ver != version) \
			{ \
				a &= actions; \
				if(a.empty()) \
					return; \
			} \
			lockerguard guard2(k2); \
			guard.release(); \
			a.popemit(__ARGS_USE(n1,n2,n3)); \
		} \
	} \
	 \
	signaltype & ensure()               { { lockerguard guard2(k2); } return *this; }\
	signaltype & clear()                { { lockerguard guard(k); actions.clear(); version++; } return *this; } \
	template<class T> \
	signaltype & operator+=(const T& a) { { lockerguard guard(k); actions += a; } return *this; } \
	template<class T> \
	signaltype & operator&=(const T& a) { { lockerguard guard(k); actions &= a; } return *this; } \
	template<class T> \
	signaltype & operator-=(const T& a) { { lockerguard guard(k); actions -= a; version++; } return *this; } \
	template<class T> \
	signaltype & operator=(const T& a)  { { lockerguard guard(k); actions = a; version++; } return *this; } \
}; \


REPEAT_NNN(0,0,2,SIGACT_DECLARATION)


} // namespace sigact;
#endif
