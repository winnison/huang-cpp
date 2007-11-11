#ifndef _REPEAT_H_
#define _REPEAT_H_

#define ZEROTEST0(a,b) a
#define ZEROTEST1(a,b) b
#define ZEROTEST2(a,b) b
#define ZEROTEST3(a,b) b
#define ZEROTEST4(a,b) b
#define ZEROTEST5(a,b) b
#define ZEROTEST6(a,b) b
#define ZEROTEST7(a,b) b
#define ZEROTEST8(a,b) b
#define ZEROTEST9(a,b) b

#define NUMBERN(n) n

#define NUMBER0(n) NUMBERN(n)
#define NUMBER1(n) 1##n
#define NUMBER2(n) 2##n
#define NUMBER3(n) 3##n
#define NUMBER4(n) 4##n
#define NUMBER5(n) 5##n
#define NUMBER6(n) 6##n
#define NUMBER7(n) 7##n
#define NUMBER8(n) 8##n
#define NUMBER9(n) 9##n
#define NUMBERNN(n1,n2) NUMBER##n1(n2)

#define _NUMBER0(n1,n2) NUMBERNN(n1,n2)
#define _NUMBER1(n1,n2) 1##n1##n2
#define _NUMBER2(n1,n2) 2##n1##n2
#define _NUMBER3(n1,n2) 3##n1##n2
#define _NUMBER4(n1,n2) 4##n1##n2
#define _NUMBER5(n1,n2) 5##n1##n2
#define _NUMBER6(n1,n2) 6##n1##n2
#define _NUMBER7(n1,n2) 7##n1##n2
#define _NUMBER8(n1,n2) 8##n1##n2
#define _NUMBER9(n1,n2) 9##n1##n2
#define NUMBERNNN(n1,n2,n3) _NUMBER##n1(n2,n3)

#define __NUMBER0(n1,n2,n3) NUMBERNNN(n1,n2,n3)
#define __NUMBER1(n1,n2,n3) 1##n1##n2##n3
#define __NUMBER2(n1,n2,n3) 2##n1##n2##n3
#define __NUMBER3(n1,n2,n3) 3##n1##n2##n3
#define __NUMBER4(n1,n2,n3) 4##n1##n2##n3
#define __NUMBER5(n1,n2,n3) 5##n1##n2##n3
#define __NUMBER6(n1,n2,n3) 6##n1##n2##n3
#define __NUMBER7(n1,n2,n3) 7##n1##n2##n3
#define __NUMBER8(n1,n2,n3) 8##n1##n2##n3
#define __NUMBER9(n1,n2,n3) 9##n1##n2##n3
#define NUMBERNNNN(n1,n2,n3,n4) __NUMBER##n1(n2,n3,n4)

#define REPEAT0(Fn)
#define REPEAT1(Fn) Fn(1)
#define REPEAT2(Fn) REPEAT1(Fn) Fn(2)
#define REPEAT3(Fn) REPEAT2(Fn) Fn(3)
#define REPEAT4(Fn) REPEAT3(Fn) Fn(4)
#define REPEAT5(Fn) REPEAT4(Fn) Fn(5)
#define REPEAT6(Fn) REPEAT5(Fn) Fn(6)
#define REPEAT7(Fn) REPEAT6(Fn) Fn(7)
#define REPEAT8(Fn) REPEAT7(Fn) Fn(8)
#define REPEAT9(Fn) REPEAT8(Fn) Fn(9)

#define REPEAT_N(n,Fn) REPEAT##n(Fn)
#define REPEAT_0_N(n,Fn) Fn(0) REPEAT##n(Fn)
#define REPEAT_0_9(Fn) Fn(0) REPEAT9(Fn)

#define _REPEAT0(Fn)
#define _REPEAT1(Fn) Fn(1)
#define _REPEAT2(Fn) _REPEAT1(Fn) Fn(2)
#define _REPEAT3(Fn) _REPEAT2(Fn) Fn(3)
#define _REPEAT4(Fn) _REPEAT3(Fn) Fn(4)
#define _REPEAT5(Fn) _REPEAT4(Fn) Fn(5)
#define _REPEAT6(Fn) _REPEAT5(Fn) Fn(6)
#define _REPEAT7(Fn) _REPEAT6(Fn) Fn(7)
#define _REPEAT8(Fn) _REPEAT7(Fn) Fn(8)
#define _REPEAT9(Fn) _REPEAT8(Fn) Fn(9)

#define _REPEAT_N(n,Fn) _REPEAT##n(Fn)
#define _REPEAT_0_N(n,Fn) Fn(0) _REPEAT##n(Fn)
#define _REPEAT_0_9(Fn) Fn(0) _REPEAT9(Fn)

#define REPEATX0(Fxn,X)
#define REPEATX1(Fxn,X)				Fxn(X,1)
#define REPEATX2(Fxn,X) REPEATX1(Fxn,X) Fxn(X,2)
#define REPEATX3(Fxn,X) REPEATX2(Fxn,X) Fxn(X,3)
#define REPEATX4(Fxn,X) REPEATX3(Fxn,X) Fxn(X,4)
#define REPEATX5(Fxn,X) REPEATX4(Fxn,X) Fxn(X,5)
#define REPEATX6(Fxn,X) REPEATX5(Fxn,X) Fxn(X,6)
#define REPEATX7(Fxn,X) REPEATX6(Fxn,X) Fxn(X,7)
#define REPEATX8(Fxn,X) REPEATX7(Fxn,X) Fxn(X,8)
#define REPEATX9(Fxn,X) REPEATX8(Fxn,X) Fxn(X,9)

#define REPEATX_N(n,Fxn,X) REPEATX##n(Fxn,X)
#define REPEATX_0_N(n,Fxn,X) Fxn(X,0) REPEATX##n(Fxn,X)
#define REPEATX_0_9(Fxn,X) Fxn(X,0) REPEATX9(Fxn,X)

#define _REPEATX0(Fxn,X)
#define _REPEATX1(Fxn,X)				  Fxn(X,1)
#define _REPEATX2(Fxn,X) _REPEATX1(Fxn,X) Fxn(X,2)
#define _REPEATX3(Fxn,X) _REPEATX2(Fxn,X) Fxn(X,3)
#define _REPEATX4(Fxn,X) _REPEATX3(Fxn,X) Fxn(X,4)
#define _REPEATX5(Fxn,X) _REPEATX4(Fxn,X) Fxn(X,5)
#define _REPEATX6(Fxn,X) _REPEATX5(Fxn,X) Fxn(X,6)
#define _REPEATX7(Fxn,X) _REPEATX6(Fxn,X) Fxn(X,7)
#define _REPEATX8(Fxn,X) _REPEATX7(Fxn,X) Fxn(X,8)
#define _REPEATX9(Fxn,X) _REPEATX8(Fxn,X) Fxn(X,9)

#define I_REPEATX0(Fxn,X) 
#define I_REPEATX1(Fxn,X) _REPEATX0(Fxn,X)
#define I_REPEATX2(Fxn,X) _REPEATX1(Fxn,X)
#define I_REPEATX3(Fxn,X) _REPEATX2(Fxn,X)
#define I_REPEATX4(Fxn,X) _REPEATX3(Fxn,X)
#define I_REPEATX5(Fxn,X) _REPEATX4(Fxn,X)
#define I_REPEATX6(Fxn,X) _REPEATX5(Fxn,X)
#define I_REPEATX7(Fxn,X) _REPEATX6(Fxn,X)
#define I_REPEATX8(Fxn,X) _REPEATX7(Fxn,X)
#define I_REPEATX9(Fxn,X) _REPEATX8(Fxn,X)

#define REPEAT_NN(n1,n2,Fnn) \
	ZEROTEST##n1(\
		REPEATX_N(n2,Fnn,0)\
		,\
		REPEATX9(Fnn,0) I_REPEATX##n1(REPEATX_0_9,Fnn) REPEATX_0_N(n2,Fnn, n1)\
	)

#define REPEAT_0_NN(n1,n2,Fnn) \
	ZEROTEST##n1(\
		REPEATX_0_N(n2,Fnn,0)\
		,\
		REPEATX_0_9(Fnn,0) I_REPEATX##n1(REPEATX_0_9,Fnn) REPEATX_0_N(n2,Fnn, n1)\
	)

#define REPEATXX0(Fxxn,X1,X2)
#define REPEATXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define REPEATXX2(Fxxn,X1,X2) REPEATXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define REPEATXX3(Fxxn,X1,X2) REPEATXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define REPEATXX4(Fxxn,X1,X2) REPEATXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define REPEATXX5(Fxxn,X1,X2) REPEATXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define REPEATXX6(Fxxn,X1,X2) REPEATXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define REPEATXX7(Fxxn,X1,X2) REPEATXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define REPEATXX8(Fxxn,X1,X2) REPEATXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define REPEATXX9(Fxxn,X1,X2) REPEATXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define REPEATXX_N(n,Fxxn,X1,X2) REPEATXX##n(Fxxn,X1,X2)
#define REPEATXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) REPEATXX##n(Fxxn,X1,X2)
#define REPEATXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) REPEATXX9(Fxxn,X1,X2)

#define _REPEATXX0(Fxxn,X1,X2)
#define _REPEATXX1(Fxxn,X1,X2)					  Fxxn(X1,X2,1)
#define _REPEATXX2(Fxxn,X1,X2) _REPEATXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define _REPEATXX3(Fxxn,X1,X2) _REPEATXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define _REPEATXX4(Fxxn,X1,X2) _REPEATXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define _REPEATXX5(Fxxn,X1,X2) _REPEATXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define _REPEATXX6(Fxxn,X1,X2) _REPEATXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define _REPEATXX7(Fxxn,X1,X2) _REPEATXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define _REPEATXX8(Fxxn,X1,X2) _REPEATXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define _REPEATXX9(Fxxn,X1,X2) _REPEATXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define _REPEATXX_N(n,Fxxn,X1,X2) _REPEATXX##n(Fxxn,X1,X2)
#define _REPEATXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) _REPEATXX##n(Fxxn,X1,X2)
#define _REPEATXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) _REPEATXX9(Fxxn,X1,X2)

#define __REPEATXX0(Fxxn,X1,X2)
#define __REPEATXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define __REPEATXX2(Fxxn,X1,X2) __REPEATXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define __REPEATXX3(Fxxn,X1,X2) __REPEATXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define __REPEATXX4(Fxxn,X1,X2) __REPEATXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define __REPEATXX5(Fxxn,X1,X2) __REPEATXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define __REPEATXX6(Fxxn,X1,X2) __REPEATXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define __REPEATXX7(Fxxn,X1,X2) __REPEATXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define __REPEATXX8(Fxxn,X1,X2) __REPEATXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define __REPEATXX9(Fxxn,X1,X2) __REPEATXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define __REPEATXX_N(n,Fxxn,X1,X2) __REPEATXX##n(Fxxn,X1,X2)
#define __REPEATXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) __REPEATXX##n(Fxxn,X1,X2)
#define __REPEATXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) __REPEATXX9(Fxxn,X1,X2)

#define I_REPEATXX0(Fxxn,X1,X2) 
#define I_REPEATXX1(Fxxn,X1,X2) __REPEATXX0(Fxxn,X1,X2)
#define I_REPEATXX2(Fxxn,X1,X2) __REPEATXX1(Fxxn,X1,X2)
#define I_REPEATXX3(Fxxn,X1,X2) __REPEATXX2(Fxxn,X1,X2)
#define I_REPEATXX4(Fxxn,X1,X2) __REPEATXX3(Fxxn,X1,X2)
#define I_REPEATXX5(Fxxn,X1,X2) __REPEATXX4(Fxxn,X1,X2)
#define I_REPEATXX6(Fxxn,X1,X2) __REPEATXX5(Fxxn,X1,X2)
#define I_REPEATXX7(Fxxn,X1,X2) __REPEATXX6(Fxxn,X1,X2)
#define I_REPEATXX8(Fxxn,X1,X2) __REPEATXX7(Fxxn,X1,X2)
#define I_REPEATXX9(Fxxn,X1,X2) __REPEATXX8(Fxxn,X1,X2)

#define REPEAT_NNN(n1,n2,n3,Fnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			REPEATXX_N(n3,Fnnn,0,0)\
			,\
			REPEATXX_N(9,Fnnn,0,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,0) REPEATXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATXX_N(9,Fnnn,0,0) _REPEATXX9(REPEATXX_0_9,Fnnn,0) I_REPEATXX##n1(_REPEATXX_0_9,REPEATXX_0_9,Fnnn) \
		ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATXX_0_9(Fnnn,n1,0)  I_REPEATXX##n2(REPEATXX_0_9,Fnnn,n1) REPEATXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define REPEAT_0_NNN(n1,n2,n3,Fnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,0,0)\
			,\
			REPEATXX_0_N(9,Fnnn,0,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,0) REPEATXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATXX_0_N(9,Fnnn,0,0) _REPEATXX9(REPEATXX_0_9,Fnnn,0) I_REPEATXX##n1(_REPEATXX_0_9,REPEATXX_0_9,Fnnn) \
		ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATXX_0_9(Fnnn,n1,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,n1) REPEATXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)

#define REPEATXXX0(Fxxxn,X1,X2,X3)
#define REPEATXXX1(Fxxxn,X1,X2,X3)						  Fxxxn(X1,X2,X3,1)
#define REPEATXXX2(Fxxxn,X1,X2,X3) REPEATXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define REPEATXXX3(Fxxxn,X1,X2,X3) REPEATXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define REPEATXXX4(Fxxxn,X1,X2,X3) REPEATXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define REPEATXXX5(Fxxxn,X1,X2,X3) REPEATXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define REPEATXXX6(Fxxxn,X1,X2,X3) REPEATXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define REPEATXXX7(Fxxxn,X1,X2,X3) REPEATXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define REPEATXXX8(Fxxxn,X1,X2,X3) REPEATXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define REPEATXXX9(Fxxxn,X1,X2,X3) REPEATXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define REPEATXXX_N(n,Fxxxn,X1,X2,X3) REPEATXXX##n(Fxxxn,X1,X2,X3)
#define REPEATXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) REPEATXXX##n(Fxxxn,X1,X2,X3)
#define REPEATXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) REPEATXXX9(Fxxxn,X1,X2,X3)

#define _REPEATXXX0(Fxxxn,X1,X2,X3) 
#define _REPEATXXX1(Fxxxn,X1,X2,X3)							Fxxxn(X1,X2,X3,1)
#define _REPEATXXX2(Fxxxn,X1,X2,X3) _REPEATXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define _REPEATXXX3(Fxxxn,X1,X2,X3) _REPEATXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define _REPEATXXX4(Fxxxn,X1,X2,X3) _REPEATXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define _REPEATXXX5(Fxxxn,X1,X2,X3) _REPEATXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define _REPEATXXX6(Fxxxn,X1,X2,X3) _REPEATXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define _REPEATXXX7(Fxxxn,X1,X2,X3) _REPEATXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define _REPEATXXX8(Fxxxn,X1,X2,X3) _REPEATXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define _REPEATXXX9(Fxxxn,X1,X2,X3) _REPEATXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define _REPEATXXX_N(n,Fxxxn,X1,X2,X3) _REPEATXXX##n(Fxxxn,X1,X2,X3)
#define _REPEATXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _REPEATXXX##n(Fxxxn,X1,X2,X3)
#define _REPEATXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _REPEATXXX9(Fxxxn,X1,X2,X3)

#define __REPEATXXX0(Fxxxn,X1,X2,X3)	
#define __REPEATXXX1(Fxxxn,X1,X2,X3)							  Fxxxn(X1,X2,X3,1)
#define __REPEATXXX2(Fxxxn,X1,X2,X3) __REPEATXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define __REPEATXXX3(Fxxxn,X1,X2,X3) __REPEATXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define __REPEATXXX4(Fxxxn,X1,X2,X3) __REPEATXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define __REPEATXXX5(Fxxxn,X1,X2,X3) __REPEATXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define __REPEATXXX6(Fxxxn,X1,X2,X3) __REPEATXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define __REPEATXXX7(Fxxxn,X1,X2,X3) __REPEATXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define __REPEATXXX8(Fxxxn,X1,X2,X3) __REPEATXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define __REPEATXXX9(Fxxxn,X1,X2,X3) __REPEATXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define __REPEATXXX_N(n,Fxxxn,X1,X2,X3) __REPEATXXX##n(Fxxxn,X1,X2,X3)
#define __REPEATXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __REPEATXXX##n(Fxxxn,X1,X2,X3)
#define __REPEATXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __REPEATXXX9(Fxxxn,X1,X2,X3)

#define ___REPEATXXX0(Fxxxn,X1,X2,X3)	
#define ___REPEATXXX1(Fxxxn,X1,X2,X3)								Fxxxn(X1,X2,X3,1)
#define ___REPEATXXX2(Fxxxn,X1,X2,X3) ___REPEATXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define ___REPEATXXX3(Fxxxn,X1,X2,X3) ___REPEATXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define ___REPEATXXX4(Fxxxn,X1,X2,X3) ___REPEATXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define ___REPEATXXX5(Fxxxn,X1,X2,X3) ___REPEATXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define ___REPEATXXX6(Fxxxn,X1,X2,X3) ___REPEATXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define ___REPEATXXX7(Fxxxn,X1,X2,X3) ___REPEATXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define ___REPEATXXX8(Fxxxn,X1,X2,X3) ___REPEATXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define ___REPEATXXX9(Fxxxn,X1,X2,X3) ___REPEATXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define ___REPEATXXX_N(n,Fxxxn,X1,X2,X3) ___REPEATXXX##n(Fxxxn,X1,X2,X3)
#define ___REPEATXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___REPEATXXX##n(Fxxxn,X1,X2,X3)
#define ___REPEATXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___REPEATXXX9(Fxxxn,X1,X2,X3)

#define I_REPEATXXX0(Fxxxn,X1,X2,X3) 
#define I_REPEATXXX1(Fxxxn,X1,X2,X3) ___REPEATXXX0(Fxxxn,X1,X2,X3)
#define I_REPEATXXX2(Fxxxn,X1,X2,X3) ___REPEATXXX1(Fxxxn,X1,X2,X3)
#define I_REPEATXXX3(Fxxxn,X1,X2,X3) ___REPEATXXX2(Fxxxn,X1,X2,X3)
#define I_REPEATXXX4(Fxxxn,X1,X2,X3) ___REPEATXXX3(Fxxxn,X1,X2,X3)
#define I_REPEATXXX5(Fxxxn,X1,X2,X3) ___REPEATXXX4(Fxxxn,X1,X2,X3)
#define I_REPEATXXX6(Fxxxn,X1,X2,X3) ___REPEATXXX5(Fxxxn,X1,X2,X3)
#define I_REPEATXXX7(Fxxxn,X1,X2,X3) ___REPEATXXX6(Fxxxn,X1,X2,X3)
#define I_REPEATXXX8(Fxxxn,X1,X2,X3) ___REPEATXXX7(Fxxxn,X1,X2,X3)
#define I_REPEATXXX9(Fxxxn,X1,X2,X3) ___REPEATXXX8(Fxxxn,X1,X2,X3)

#define REPEAT_NNNN(n1,n2,n3,n4,Fnnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATXXX_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATXXX_N(9,Fnnnn,0,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,0) REPEATXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATXXX_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,0)\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATXXX_0_9(Fnnnn,0,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,n2) REPEATXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATXXX_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) __REPEATXXX9(_REPEATXXX_0_9, REPEATXXX_0_9,Fnnnn,0) I_REPEATXXX##n1(__REPEATXXX_0_9,_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn)\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,0) REPEATXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,n1,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,n1,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,n1)\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATXXX_0_9(Fnnnn,n1,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,n2) REPEATXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#define REPEAT_0_NNNN(n1,n2,n3,n4,Fnnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,0,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,0) REPEATXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,0)\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATXXX_0_9(Fnnnn,0,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,n2) REPEATXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATXXX_0_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) __REPEATXXX9(_REPEATXXX_0_9, REPEATXXX_0_9,Fnnnn,0) I_REPEATXXX##n1(__REPEATXXX_0_9,_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn)\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,0) REPEATXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,n1,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,n1,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,n1)\
			ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATXXX_0_9(Fnnnn,n1,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,n2) REPEATXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#define REPEATC0(Fn)
#define REPEATC1(Fn) Fn(1)
#define REPEATC2(Fn) REPEATC1(Fn), Fn(2)
#define REPEATC3(Fn) REPEATC2(Fn), Fn(3)
#define REPEATC4(Fn) REPEATC3(Fn), Fn(4)
#define REPEATC5(Fn) REPEATC4(Fn), Fn(5)
#define REPEATC6(Fn) REPEATC5(Fn), Fn(6)
#define REPEATC7(Fn) REPEATC6(Fn), Fn(7)
#define REPEATC8(Fn) REPEATC7(Fn), Fn(8)
#define REPEATC9(Fn) REPEATC8(Fn), Fn(9)

#define REPEATC_N(n,Fn) REPEATC##n(Fn)
#define _I_REPEATC_0_N(n,Fn) Fn(0), REPEATC##n(Fn)
#define REPEATC_0_N(n,Fn) ZEROTEST##n(Fn(0),_I_REPEATC_0_N(n,Fn)) 
#define REPEATC_0_9(Fn) Fn(0), REPEATC9(Fn)

#define _REPEATC0(Fn)
#define _REPEATC1(Fn) Fn(1)
#define _REPEATC2(Fn) _REPEATC1(Fn), Fn(2)
#define _REPEATC3(Fn) _REPEATC2(Fn), Fn(3)
#define _REPEATC4(Fn) _REPEATC3(Fn), Fn(4)
#define _REPEATC5(Fn) _REPEATC4(Fn), Fn(5)
#define _REPEATC6(Fn) _REPEATC5(Fn), Fn(6)
#define _REPEATC7(Fn) _REPEATC6(Fn), Fn(7)
#define _REPEATC8(Fn) _REPEATC7(Fn), Fn(8)
#define _REPEATC9(Fn) _REPEATC8(Fn), Fn(9)

#define _REPEATC_N(n,Fn) _REPEATC##n(Fn)
#define _I__REPEATC_0_N(n,Fn) Fn(0), _REPEATC##n(Fn)
#define _REPEATC_0_N(n,Fn) ZEROTEST##n(Fn(0),_I__REPEATC_0_N(n,Fn)) 
#define _REPEATC_0_9(Fn) Fn(0), _REPEATC9(Fn)

#define REPEATCX0(Fxn,X)
#define REPEATCX1(Fxn,X)				   Fxn(X,1)
#define REPEATCX2(Fxn,X) REPEATCX1(Fxn,X), Fxn(X,2)
#define REPEATCX3(Fxn,X) REPEATCX2(Fxn,X), Fxn(X,3)
#define REPEATCX4(Fxn,X) REPEATCX3(Fxn,X), Fxn(X,4)
#define REPEATCX5(Fxn,X) REPEATCX4(Fxn,X), Fxn(X,5)
#define REPEATCX6(Fxn,X) REPEATCX5(Fxn,X), Fxn(X,6)
#define REPEATCX7(Fxn,X) REPEATCX6(Fxn,X), Fxn(X,7)
#define REPEATCX8(Fxn,X) REPEATCX7(Fxn,X), Fxn(X,8)
#define REPEATCX9(Fxn,X) REPEATCX8(Fxn,X), Fxn(X,9)

#define REPEATCX_N(n,Fxn,X) REPEATCX##n(Fxn,X)
#define _I_REPEATCX_0_N(n,Fxn,X) Fxn(X,0), REPEATCX##n(Fxn,X)
#define REPEATCX_0_N(n,Fxn,X) ZEROTEST##n(Fxn(X,0),_I_REPEATCX_0_N(n,Fxn,X)) 
#define REPEATCX_0_9(Fxn,X) Fxn(X,0), REPEATCX9(Fxn,X)

#define _REPEATCX0(Fxn,X)
#define _REPEATCX1(Fxn,X)					 Fxn(X,1)
#define _REPEATCX2(Fxn,X) _REPEATCX1(Fxn,X), Fxn(X,2)
#define _REPEATCX3(Fxn,X) _REPEATCX2(Fxn,X), Fxn(X,3)
#define _REPEATCX4(Fxn,X) _REPEATCX3(Fxn,X), Fxn(X,4)
#define _REPEATCX5(Fxn,X) _REPEATCX4(Fxn,X), Fxn(X,5)
#define _REPEATCX6(Fxn,X) _REPEATCX5(Fxn,X), Fxn(X,6)
#define _REPEATCX7(Fxn,X) _REPEATCX6(Fxn,X), Fxn(X,7)
#define _REPEATCX8(Fxn,X) _REPEATCX7(Fxn,X), Fxn(X,8)
#define _REPEATCX9(Fxn,X) _REPEATCX8(Fxn,X), Fxn(X,9)

#define I_REPEATCX0(Fxn,X) 
#define I_REPEATCX1(Fxn,X) _REPEATCX0(Fxn,X),
#define I_REPEATCX2(Fxn,X) _REPEATCX1(Fxn,X),
#define I_REPEATCX3(Fxn,X) _REPEATCX2(Fxn,X),
#define I_REPEATCX4(Fxn,X) _REPEATCX3(Fxn,X),
#define I_REPEATCX5(Fxn,X) _REPEATCX4(Fxn,X),
#define I_REPEATCX6(Fxn,X) _REPEATCX5(Fxn,X),
#define I_REPEATCX7(Fxn,X) _REPEATCX6(Fxn,X),
#define I_REPEATCX8(Fxn,X) _REPEATCX7(Fxn,X),
#define I_REPEATCX9(Fxn,X) _REPEATCX8(Fxn,X),

#define REPEATC_NN(n1,n2,Fnn) \
	ZEROTEST##n1(\
		REPEATCX_N(n2,Fnn,0)\
		,\
		REPEATCX9(Fnn,0), I_REPEATCX##n1(REPEATCX_0_9,Fnn) REPEATCX_0_N(n2,Fnn, n1)\
	)

#define REPEATC_0_NN(n1,n2,Fnn) \
	ZEROTEST##n1(\
		REPEATCX_0_N(n2,Fnn,0)\
		,\
		REPEATCX_0_9(Fnn,0), I_REPEATCX##n1(REPEATCX_0_9,Fnn) REPEATCX_0_N(n2,Fnn, n1)\
	)

#define REPEATCXX0(Fxxn,X1,X2)
#define REPEATCXX1(Fxxn,X1,X2)						   Fxxn(X1,X2,1)
#define REPEATCXX2(Fxxn,X1,X2) REPEATCXX1(Fxxn,X1,X2), Fxxn(X1,X2,2)
#define REPEATCXX3(Fxxn,X1,X2) REPEATCXX2(Fxxn,X1,X2), Fxxn(X1,X2,3)
#define REPEATCXX4(Fxxn,X1,X2) REPEATCXX3(Fxxn,X1,X2), Fxxn(X1,X2,4)
#define REPEATCXX5(Fxxn,X1,X2) REPEATCXX4(Fxxn,X1,X2), Fxxn(X1,X2,5)
#define REPEATCXX6(Fxxn,X1,X2) REPEATCXX5(Fxxn,X1,X2), Fxxn(X1,X2,6)
#define REPEATCXX7(Fxxn,X1,X2) REPEATCXX6(Fxxn,X1,X2), Fxxn(X1,X2,7)
#define REPEATCXX8(Fxxn,X1,X2) REPEATCXX7(Fxxn,X1,X2), Fxxn(X1,X2,8)
#define REPEATCXX9(Fxxn,X1,X2) REPEATCXX8(Fxxn,X1,X2), Fxxn(X1,X2,9)

#define REPEATCXX_N(n,Fxxn,X1,X2) REPEATCXX##n(Fxxn,X1,X2)
#define _I_REPEATCXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0), REPEATCXX##n(Fxxn,X1,X2)
#define REPEATCXX_0_N(n,Fxxn,X1,X2) ZEROTEST##n(Fxxn(X1,X2,0),_I_REPEATCXX_0_N(Fxxn,X1,X2)) 
#define REPEATCXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0), REPEATCXX9(Fxxn,X1,X2)

#define _REPEATCXX0(Fxxn,X1,X2)
#define _REPEATCXX1(Fxxn,X1,X2)							 Fxxn(X1,X2,1)
#define _REPEATCXX2(Fxxn,X1,X2) _REPEATCXX1(Fxxn,X1,X2), Fxxn(X1,X2,2)
#define _REPEATCXX3(Fxxn,X1,X2) _REPEATCXX2(Fxxn,X1,X2), Fxxn(X1,X2,3)
#define _REPEATCXX4(Fxxn,X1,X2) _REPEATCXX3(Fxxn,X1,X2), Fxxn(X1,X2,4)
#define _REPEATCXX5(Fxxn,X1,X2) _REPEATCXX4(Fxxn,X1,X2), Fxxn(X1,X2,5)
#define _REPEATCXX6(Fxxn,X1,X2) _REPEATCXX5(Fxxn,X1,X2), Fxxn(X1,X2,6)
#define _REPEATCXX7(Fxxn,X1,X2) _REPEATCXX6(Fxxn,X1,X2), Fxxn(X1,X2,7)
#define _REPEATCXX8(Fxxn,X1,X2) _REPEATCXX7(Fxxn,X1,X2), Fxxn(X1,X2,8)
#define _REPEATCXX9(Fxxn,X1,X2) _REPEATCXX8(Fxxn,X1,X2), Fxxn(X1,X2,9)

#define _REPEATCXX_N(n,Fxxn,X1,X2) _REPEATCXX##n(Fxxn,X1,X2)
#define _I__REPEATCXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0), _REPEATCXX##n(Fxxn,X1,X2)
#define _REPEATCXX_0_N(n,Fxxn,X1,X2) ZEROTEST##n(Fxxn(X1,X2,0), _I__REPEATCXX_0_N(Fxxn,X1,X2))
#define _REPEATCXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0), _REPEATCXX9(Fxxn,X1,X2)

#define __REPEATCXX0(Fxxn,X1,X2)
#define __REPEATCXX1(Fxxn,X1,X2)						   Fxxn(X1,X2,1)
#define __REPEATCXX2(Fxxn,X1,X2) __REPEATCXX1(Fxxn,X1,X2), Fxxn(X1,X2,2)
#define __REPEATCXX3(Fxxn,X1,X2) __REPEATCXX2(Fxxn,X1,X2), Fxxn(X1,X2,3)
#define __REPEATCXX4(Fxxn,X1,X2) __REPEATCXX3(Fxxn,X1,X2), Fxxn(X1,X2,4)
#define __REPEATCXX5(Fxxn,X1,X2) __REPEATCXX4(Fxxn,X1,X2), Fxxn(X1,X2,5)
#define __REPEATCXX6(Fxxn,X1,X2) __REPEATCXX5(Fxxn,X1,X2), Fxxn(X1,X2,6)
#define __REPEATCXX7(Fxxn,X1,X2) __REPEATCXX6(Fxxn,X1,X2), Fxxn(X1,X2,7)
#define __REPEATCXX8(Fxxn,X1,X2) __REPEATCXX7(Fxxn,X1,X2), Fxxn(X1,X2,8)
#define __REPEATCXX9(Fxxn,X1,X2) __REPEATCXX8(Fxxn,X1,X2), Fxxn(X1,X2,9)

#define __REPEATCXX_N(n,Fxxn,X1,X2) __REPEATCXX##n(Fxxn,X1,X2)
#define _I___REPEATCXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) __REPEATCXX##n(Fxxn,X1,X2)
#define __REPEATCXX_0_N(n,Fxxn,X1,X2) ZEROTEST##n(Fxxn(X1,X2,0) _I___REPEATCXX_0_N(Fxxn,X1,X2))
#define __REPEATCXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) __REPEATCXX9(Fxxn,X1,X2)

#define I_REPEATCXX0(Fxxn,X1,X2) 
#define I_REPEATCXX1(Fxxn,X1,X2) __REPEATCXX0(Fxxn,X1,X2),
#define I_REPEATCXX2(Fxxn,X1,X2) __REPEATCXX1(Fxxn,X1,X2),
#define I_REPEATCXX3(Fxxn,X1,X2) __REPEATCXX2(Fxxn,X1,X2),
#define I_REPEATCXX4(Fxxn,X1,X2) __REPEATCXX3(Fxxn,X1,X2),
#define I_REPEATCXX5(Fxxn,X1,X2) __REPEATCXX4(Fxxn,X1,X2),
#define I_REPEATCXX6(Fxxn,X1,X2) __REPEATCXX5(Fxxn,X1,X2),
#define I_REPEATCXX7(Fxxn,X1,X2) __REPEATCXX6(Fxxn,X1,X2),
#define I_REPEATCXX8(Fxxn,X1,X2) __REPEATCXX7(Fxxn,X1,X2),
#define I_REPEATCXX9(Fxxn,X1,X2) __REPEATCXX8(Fxxn,X1,X2),

#define REPEATC_NNN(n1,n2,n3,Fnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			REPEATCXX_N(n3,Fnnn,0,0)\
			,\
			REPEATCXX_N(9,Fnnn,0,0), I_REPEATCXX##n2(REPEATCXX_0_9,Fnnn,0) REPEATCXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATCXX_N(9,Fnnn,0,0), _REPEATCXX9(REPEATCXX_0_9,Fnnn,0), I_REPEATCXX##n1(_REPEATCXX_0_9,REPEATCXX_0_9,Fnnn) \
		ZEROTEST##n2(\
			REPEATCXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATCXX_0_9(Fnnn,n1,0), I_REPEATCXX##n2(REPEATCXX_0_9,Fnnn,n1) REPEATCXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define REPEATC_0_NNN(n1,n2,n3,Fnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			REPEATCXX_0_N(n3,Fnnn,0,0)\
			,\
			REPEATCXX_0_N(9,Fnnn,0,0), I_REPEATCXX##n2(REPEATCXX_0_9,Fnnn,0) REPEATCXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATCXX_0_N(9,Fnnn,0,0), _REPEATCXX9(REPEATCXX_0_9,Fnnn,0), I_REPEATCXX##n1(_REPEATCXX_0_9,REPEATCXX_0_9,Fnnn) \
		ZEROTEST##n2(\
			REPEATCXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATCXX_0_9(Fnnn,n1,0), I_REPEATCXX##n2(REPEATCXX_0_9,Fnnn,n1) REPEATCXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)

#define REPEATCXXX0(Fxxxn,X1,X2,X3)
#define REPEATCXXX1(Fxxxn,X1,X2,X3)								 Fxxxn(X1,X2,X3,1)
#define REPEATCXXX2(Fxxxn,X1,X2,X3) REPEATCXXX1(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,2)
#define REPEATCXXX3(Fxxxn,X1,X2,X3) REPEATCXXX2(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,3)
#define REPEATCXXX4(Fxxxn,X1,X2,X3) REPEATCXXX3(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,4)
#define REPEATCXXX5(Fxxxn,X1,X2,X3) REPEATCXXX4(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,5)
#define REPEATCXXX6(Fxxxn,X1,X2,X3) REPEATCXXX5(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,6)
#define REPEATCXXX7(Fxxxn,X1,X2,X3) REPEATCXXX6(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,7)
#define REPEATCXXX8(Fxxxn,X1,X2,X3) REPEATCXXX7(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,8)
#define REPEATCXXX9(Fxxxn,X1,X2,X3) REPEATCXXX8(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,9)

#define REPEATCXXX_N(n,Fxxxn,X1,X2,X3) REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define _I_REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) ZEROTEST##n(Fxxxn(X1,X2,X3,0), _I_REPEATCXXX_0_N(Fxxxn,X1,X2,X3))
#define REPEATCXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), REPEATCXXX9(Fxxxn,X1,X2,X3)

#define _REPEATCXXX0(Fxxxn,X1,X2,X3) 
#define _REPEATCXXX1(Fxxxn,X1,X2,X3)							   Fxxxn(X1,X2,X3,1)
#define _REPEATCXXX2(Fxxxn,X1,X2,X3) _REPEATCXXX1(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,2)
#define _REPEATCXXX3(Fxxxn,X1,X2,X3) _REPEATCXXX2(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,3)
#define _REPEATCXXX4(Fxxxn,X1,X2,X3) _REPEATCXXX3(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,4)
#define _REPEATCXXX5(Fxxxn,X1,X2,X3) _REPEATCXXX4(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,5)
#define _REPEATCXXX6(Fxxxn,X1,X2,X3) _REPEATCXXX5(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,6)
#define _REPEATCXXX7(Fxxxn,X1,X2,X3) _REPEATCXXX6(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,7)
#define _REPEATCXXX8(Fxxxn,X1,X2,X3) _REPEATCXXX7(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,8)
#define _REPEATCXXX9(Fxxxn,X1,X2,X3) _REPEATCXXX8(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,9)

#define _REPEATCXXX_N(n,Fxxxn,X1,X2,X3) _REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define _I__REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), _REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define _REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) ZEROTEST##n(Fxxxn(X1,X2,X3,0), _I__REPEATCXXX_0_N(Fxxxn,X1,X2,X3))
#define _REPEATCXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), _REPEATCXXX9(Fxxxn,X1,X2,X3)

#define __REPEATCXXX0(Fxxxn,X1,X2,X3)	
#define __REPEATCXXX1(Fxxxn,X1,X2,X3)								 Fxxxn(X1,X2,X3,1)
#define __REPEATCXXX2(Fxxxn,X1,X2,X3) __REPEATCXXX1(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,2)
#define __REPEATCXXX3(Fxxxn,X1,X2,X3) __REPEATCXXX2(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,3)
#define __REPEATCXXX4(Fxxxn,X1,X2,X3) __REPEATCXXX3(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,4)
#define __REPEATCXXX5(Fxxxn,X1,X2,X3) __REPEATCXXX4(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,5)
#define __REPEATCXXX6(Fxxxn,X1,X2,X3) __REPEATCXXX5(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,6)
#define __REPEATCXXX7(Fxxxn,X1,X2,X3) __REPEATCXXX6(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,7)
#define __REPEATCXXX8(Fxxxn,X1,X2,X3) __REPEATCXXX7(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,8)
#define __REPEATCXXX9(Fxxxn,X1,X2,X3) __REPEATCXXX8(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,9)

#define __REPEATCXXX_N(n,Fxxxn,X1,X2,X3) __REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define _I___REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), __REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define __REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) ZEROTEST##n(Fxxxn(X1,X2,X3,0), _I__REPEATCXXX_0_N(Fxxxn,X1,X2,X3))
#define __REPEATCXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), __REPEATCXXX9(Fxxxn,X1,X2,X3)

#define ___REPEATCXXX0(Fxxxn,X1,X2,X3)	
#define ___REPEATCXXX1(Fxxxn,X1,X2,X3)								   Fxxxn(X1,X2,X3,1)
#define ___REPEATCXXX2(Fxxxn,X1,X2,X3) ___REPEATCXXX1(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,2)
#define ___REPEATCXXX3(Fxxxn,X1,X2,X3) ___REPEATCXXX2(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,3)
#define ___REPEATCXXX4(Fxxxn,X1,X2,X3) ___REPEATCXXX3(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,4)
#define ___REPEATCXXX5(Fxxxn,X1,X2,X3) ___REPEATCXXX4(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,5)
#define ___REPEATCXXX6(Fxxxn,X1,X2,X3) ___REPEATCXXX5(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,6)
#define ___REPEATCXXX7(Fxxxn,X1,X2,X3) ___REPEATCXXX6(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,7)
#define ___REPEATCXXX8(Fxxxn,X1,X2,X3) ___REPEATCXXX7(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,8)
#define ___REPEATCXXX9(Fxxxn,X1,X2,X3) ___REPEATCXXX8(Fxxxn,X1,X2,X3), Fxxxn(X1,X2,X3,9)

#define ___REPEATCXXX_N(n,Fxxxn,X1,X2,X3) ___REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define _I____REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), ___REPEATCXXX##n(Fxxxn,X1,X2,X3)
#define ___REPEATCXXX_0_N(n,Fxxxn,X1,X2,X3) ZEROTEST##n(Fxxxn(X1,X2,X3,0), _I___REPEATCXXX_0_N(Fxxxn,X1,X2,X3))
#define ___REPEATCXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0), ___REPEATCXXX9(Fxxxn,X1,X2,X3)

#define I_REPEATCXXX0(Fxxxn,X1,X2,X3) 
#define I_REPEATCXXX1(Fxxxn,X1,X2,X3) ___REPEATCXXX0(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX2(Fxxxn,X1,X2,X3) ___REPEATCXXX1(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX3(Fxxxn,X1,X2,X3) ___REPEATCXXX2(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX4(Fxxxn,X1,X2,X3) ___REPEATCXXX3(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX5(Fxxxn,X1,X2,X3) ___REPEATCXXX4(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX6(Fxxxn,X1,X2,X3) ___REPEATCXXX5(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX7(Fxxxn,X1,X2,X3) ___REPEATCXXX6(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX8(Fxxxn,X1,X2,X3) ___REPEATCXXX7(Fxxxn,X1,X2,X3),
#define I_REPEATCXXX9(Fxxxn,X1,X2,X3) ___REPEATCXXX8(Fxxxn,X1,X2,X3),

#define REPEATC_NNNN(n1,n2,n3,n4,Fnnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATCXXX_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATCXXX_N(9,Fnnnn,0,0,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,0,0) REPEATCXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATCXXX_N(9,Fnnnn,0,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,0,0), I_REPEATCXXX##n2(_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn,0)\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATCXXX_0_9(Fnnnn,0,n2,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,0,n2) REPEATCXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATCXXX_N(9,Fnnnn,0,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,0,0), __REPEATCXXX9(_REPEATCXXX_0_9, REPEATCXXX_0_9,Fnnnn,0), I_REPEATCXXX##n1(__REPEATCXXX_0_9,_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn)\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATCXXX_0_N(9,Fnnnn,n1,0,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,n1,0) REPEATCXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATCXXX_0_N(9,Fnnnn,n1,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,n1,0,0), I_REPEATCXXX##n2(_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn,n1)\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATCXXX_0_9(Fnnnn,n1,n2,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,n1,n2) REPEATCXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#define REPEATC_0_NNNN(n1,n2,n3,n4,Fnnnn)\
	ZEROTEST##n1(\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATCXXX_0_N(9,Fnnnn,0,0,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,0,0) REPEATCXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATCXXX_0_N(9,Fnnnn,0,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,0,0), I_REPEATCXXX##n2(_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn,0)\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATCXXX_0_9(Fnnnn,0,n2,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,0,n2) REPEATCXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATCXXX_0_N(9,Fnnnn,0,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,0,0), __REPEATCXXX9(_REPEATCXXX_0_9, REPEATCXXX_0_9,Fnnnn,0), I_REPEATCXXX##n1(__REPEATCXXX_0_9,_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn)\
		ZEROTEST##n2(\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATCXXX_0_N(9,Fnnnn,n1,0,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,n1,0) REPEATCXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATCXXX_0_N(9,Fnnnn,n1,0,0), _REPEATCXXX9(REPEATCXXX_0_9,Fnnnn,n1,0,0), I_REPEATCXXX##n2(_REPEATCXXX_0_9,REPEATCXXX_0_9,Fnnnn,n1)\
			ZEROTEST##n3(\
				REPEATCXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATCXXX_0_9(Fnnnn,n1,n2,0), I_REPEATCXXX##n3(REPEATCXXX_0_9,Fnnnn,n1,n2) REPEATCXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#endif //_REPEAT_H_
