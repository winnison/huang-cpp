#define SAVEDELETE(p) if(p){delete p;p=0;}

#define CHECKRANGE(a, left, right) \
	if ((a)<(left))\
	{\
	(a) = (left);\
	}\
	else if((a)>(right))\
	{\
	(a) = (right);\
	}

#define ROUNDDIV(a,n) (((a)+(n)/2)/(n))


#define TryCatch(process) try\
{\
	process;
}\
catch (...)\
{\
}\