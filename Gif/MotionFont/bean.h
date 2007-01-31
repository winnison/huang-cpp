#define BEAN(type, name) \
private:\
	type m_##name;\
public:\
	virtual bool Set##name(type name){m_##name = name;return true;}\
	virtual type Get##name(){return m_##name;}\
private:

#define BEANC(name, type) \
private:\
	type m_##name;\
public:\
	virtual bool Set##name(type name)\
	{\
		if(Check##name(name))\
		{\
			m_##name = name;\
			return true;\
		}\
		return false;\
	}\
	virtual type Get##name()\
	{\
		return m_##name;\
	}\
private:

