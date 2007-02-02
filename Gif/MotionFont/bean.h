

#define BEAN(type, name) \
private:\
	type m_##name;\
public:\
	virtual bool Set##name (type value){m_##name = value;return true;}\
	virtual type Get##name (){return m_##name;}\
private:


#define BEANC(type, name) \
private:\
	type m_##name;\
public:\
	virtual bool Set##name (type value)\
	{\
		if(Check##name (value))\
		{\
			m_##name = value;\
			return true;\
		}\
		return false;\
	}\
	virtual type Get##name ()\
	{\
		return m_##name;\
	}\
private:


#define BEANBIND(type, name, bindmember, bname) \
public:\
	virtual bool Set##name(type name){return bindmember.Set##bname(name);}\
	virtual type Get##name(){return bindmember.Get##bname(name);}\
private:
