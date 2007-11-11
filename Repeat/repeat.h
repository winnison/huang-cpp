#ifndef _REPEAT_H_
#define _REPEAT_H_

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

#define REPEAT_ZEROTEST0(a,b) a
#define REPEAT_ZEROTEST1(a,b) b
#define REPEAT_ZEROTEST2(a,b) b
#define REPEAT_ZEROTEST3(a,b) b
#define REPEAT_ZEROTEST4(a,b) b
#define REPEAT_ZEROTEST5(a,b) b
#define REPEAT_ZEROTEST6(a,b) b
#define REPEAT_ZEROTEST7(a,b) b
#define REPEAT_ZEROTEST8(a,b) b
#define REPEAT_ZEROTEST9(a,b) b

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
	REPEAT_ZEROTEST##n1(\
		REPEATX_N(n2,Fnn,0)\
		,\
		REPEATX_N(9,Fnn,0) I_REPEATX##n1(REPEATX_0_9,Fnn) REPEATX_0_N(n2,Fnn, n1)\
	)

#define REPEAT_0_NN(n1,n2,Fnn) \
	REPEAT_ZEROTEST##n1(\
		REPEATX_0_N(n2,Fnn,0)\
		,\
		REPEATX_0_N(9,Fnn,0) I_REPEATX##n1(REPEATX_0_9,Fnn) REPEATX_0_N(n2,Fnn, n1)\
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
	REPEAT_ZEROTEST##n1(\
		REPEAT_ZEROTEST##n2(\
			REPEATXX_N(n3,Fnnn,0,0)\
			,\
			REPEATXX_N(9,Fnnn,0,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,0) REPEATXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATXX_N(9,Fnnn,0,0) _REPEATXX9(REPEATXX_0_9,Fnnn,0) I_REPEATXX##n1(_REPEATXX_0_9,REPEATXX_0_9,Fnnn) \
		REPEAT_ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATXX_0_N(9,Fnnn,n1,0)  I_REPEATXX##n2(REPEATXX_0_9,Fnnn,n1) REPEATXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define REPEAT_0_NNN(n1,n2,n3,Fnnn)\
	REPEAT_ZEROTEST##n1(\
		REPEAT_ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,0,0)\
			,\
			REPEATXX_0_N(9,Fnnn,0,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,0) REPEATXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		REPEATXX_0_N(9,Fnnn,0,0) _REPEATXX9(REPEATXX_0_9,Fnnn,0) I_REPEATXX##n1(_REPEATXX_0_9,REPEATXX_0_9,Fnnn) \
		REPEAT_ZEROTEST##n2(\
			REPEATXX_0_N(n3,Fnnn,n1,0)\
			,\
			REPEATXX_0_N(9,Fnnn,n1,0) I_REPEATXX##n2(REPEATXX_0_9,Fnnn,n1) REPEATXX_0_N(n3,Fnnn,n1,n2)\
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
	REPEAT_ZEROTEST##n1(\
		REPEAT_ZEROTEST##n2(\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATXXX_N(9,Fnnnn,0,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,0) REPEATXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATXXX_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,0)\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,0,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,n2) REPEATXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATXXX_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) __REPEATXXX9(_REPEATXXX_0_9, REPEATXXX_0_9,Fnnnn,0) I_REPEATXXX##n1(__REPEATXXX_0_9,_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn)\
		REPEAT_ZEROTEST##n2(\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,0) REPEATXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,n1,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,n1,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,n1)\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,n2) REPEATXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#define REPEAT_0_NNNN(n1,n2,n3,n4,Fnnnn)\
	REPEAT_ZEROTEST##n1(\
		REPEAT_ZEROTEST##n2(\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,0,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,0) REPEATXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,0)\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,0,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,0,n2) REPEATXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		REPEATXXX_0_N(9,Fnnnn,0,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,0,0) __REPEATXXX9(_REPEATXXX_0_9, REPEATXXX_0_9,Fnnnn,0) I_REPEATXXX##n1(__REPEATXXX_0_9,_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn)\
		REPEAT_ZEROTEST##n2(\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,0,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,0) REPEATXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			REPEATXXX_0_N(9,Fnnnn,n1,0,0) _REPEATXXX9(REPEATXXX_0_9,Fnnnn,n1,0,0) I_REPEATXXX##n2(_REPEATXXX_0_9,REPEATXXX_0_9,Fnnnn,n1)\
			REPEAT_ZEROTEST##n3(\
				REPEATXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				REPEATXXX_0_N(9,Fnnnn,n1,n2,0) I_REPEATXXX##n3(REPEATXXX_0_9,Fnnnn,n1,n2) REPEATXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

//Fn(1),Fn(2),Fn(3),...)
#define LOOPC0(Fn)
#define LOOPC1(Fn) Fn(1)
#define LOOPC2(Fn) LOOPC1(Fn), Fn(2)
#define LOOPC3(Fn) LOOPC2(Fn), Fn(3)
#define LOOPC4(Fn) LOOPC3(Fn), Fn(4)
#define LOOPC5(Fn) LOOPC4(Fn), Fn(5)
#define LOOPC6(Fn) LOOPC5(Fn), Fn(6)
#define LOOPC7(Fn) LOOPC6(Fn), Fn(7)
#define LOOPC8(Fn) LOOPC7(Fn), Fn(8)
#define LOOPC9(Fn) LOOPC8(Fn), Fn(9)
#define LOOPC_N(n,Fn) LOOPC##n(Fn)
//Fnx(1,X),Fnx(2,X),Fnx(3,X),...)
#define LOOPXC0(Fnx,X)
#define LOOPXC1(Fnx,X) Fnx(1,X)
#define LOOPXC2(Fnx,X) LOOPXC1(Fnx,X), Fnx(2,X)
#define LOOPXC3(Fnx,X) LOOPXC2(Fnx,X), Fnx(3,X)
#define LOOPXC4(Fnx,X) LOOPXC3(Fnx,X), Fnx(4,X)
#define LOOPXC5(Fnx,X) LOOPXC4(Fnx,X), Fnx(5,X)
#define LOOPXC6(Fnx,X) LOOPXC5(Fnx,X), Fnx(6,X)
#define LOOPXC7(Fnx,X) LOOPXC6(Fnx,X), Fnx(7,X)
#define LOOPXC8(Fnx,X) LOOPXC7(Fnx,X), Fnx(8,X)
#define LOOPXC9(Fnx,X) LOOPXC8(Fnx,X), Fnx(9,X)
#define LOOPXC_N(n,Fnx,X) LOOPXC##n(Fnx,X)
//Fnxx(1,X,X),Fnxx(2,X,X),Fnxx(3,X,X) ...)
#define LOOPXXC0(Fnxx,X1,X2)
#define LOOPXXC1(Fnxx,X1,X2) Fnxx(1,X1,X2)
#define LOOPXXC2(Fnxx,X1,X2) LOOPXXC1(Fnxx,X1,X2), Fnxx(2,X1,X2)
#define LOOPXXC3(Fnxx,X1,X2) LOOPXXC2(Fnxx,X1,X2), Fnxx(3,X1,X2)
#define LOOPXXC4(Fnxx,X1,X2) LOOPXXC3(Fnxx,X1,X2), Fnxx(4,X1,X2)
#define LOOPXXC5(Fnxx,X1,X2) LOOPXXC4(Fnxx,X1,X2), Fnxx(5,X1,X2)
#define LOOPXXC6(Fnxx,X1,X2) LOOPXXC5(Fnxx,X1,X2), Fnxx(6,X1,X2)
#define LOOPXXC7(Fnxx,X1,X2) LOOPXXC6(Fnxx,X1,X2), Fnxx(7,X1,X2)
#define LOOPXXC8(Fnxx,X1,X2) LOOPXXC7(Fnxx,X1,X2), Fnxx(8,X1,X2)
#define LOOPXXC9(Fnxx,X1,X2) LOOPXXC8(Fnxx,X1,X2), Fnxx(9,X1,X2)
#define LOOPXXC_N(n,Fnxx,X1,X2) LOOPXXC##n(Fnxx,X1,X2)
//
#define PREFIX_NUMBER0(n,Fn) Fn(0##n)
#define PREFIX_NUMBER1(n,Fn) Fn(1##n)
#define PREFIX_NUMBER2(n,Fn) Fn(2##n)
#define PREFIX_NUMBER3(n,Fn) Fn(3##n)
#define PREFIX_NUMBER4(n,Fn) Fn(4##n)
#define PREFIX_NUMBER5(n,Fn) Fn(5##n)
#define PREFIX_NUMBER6(n,Fn) Fn(6##n)
#define PREFIX_NUMBER7(n,Fn) Fn(7##n)
#define PREFIX_NUMBER8(n,Fn) Fn(8##n)
#define PREFIX_NUMBER9(n,Fn) Fn(9##n)
//
#define PREFIX_NUMBER_X_0(n,Fnx,X) Fnx(0##n,X)
#define PREFIX_NUMBER_X_1(n,Fnx,X) Fnx(1##n,X)
#define PREFIX_NUMBER_X_2(n,Fnx,X) Fnx(2##n,X)
#define PREFIX_NUMBER_X_3(n,Fnx,X) Fnx(3##n,X)
#define PREFIX_NUMBER_X_4(n,Fnx,X) Fnx(4##n,X)
#define PREFIX_NUMBER_X_5(n,Fnx,X) Fnx(5##n,X)
#define PREFIX_NUMBER_X_6(n,Fnx,X) Fnx(6##n,X)
#define PREFIX_NUMBER_X_7(n,Fnx,X) Fnx(7##n,X)
#define PREFIX_NUMBER_X_8(n,Fnx,X) Fnx(8##n,X)
#define PREFIX_NUMBER_X_9(n,Fnx,X) Fnx(9##n,X)
//Fn(01),Fn(02),Fn(03),...)
#define _LOOPC_0(n,Fn)               LOOPXC_N(n,PREFIX_NUMBER0,Fn)
#define _LOOPC_1(n,Fn) _LOOPC_0(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER1,Fn)
#define _LOOPC_2(n,Fn) _LOOPC_1(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER2,Fn)
#define _LOOPC_3(n,Fn) _LOOPC_2(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER3,Fn)
#define _LOOPC_4(n,Fn) _LOOPC_3(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER4,Fn)
#define _LOOPC_5(n,Fn) _LOOPC_4(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER5,Fn)
#define _LOOPC_6(n,Fn) _LOOPC_5(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER6,Fn)
#define _LOOPC_7(n,Fn) _LOOPC_6(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER7,Fn)
#define _LOOPC_8(n,Fn) _LOOPC_7(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER8,Fn)
#define _LOOPC_9(n,Fn) _LOOPC_8(9,Fn), LOOPXC_0_N(n,PREFIX_NUMBER9,Fn)
#define _LOOPC_NN(n1,n2,Fn) _LOOPC_##n1(n2,Fn)
//Fn(01,X),Fn(02,X),Fn(03,X),...)
#define _LOOPXC_0(n,Fnx,X)                  LOOPXXC_N(n,PREFIX_NUMBER_X_0,Fnx,X)
#define _LOOPXC_1(n,Fnx,X) _LOOPXC_0(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_1,Fnx,X)
#define _LOOPXC_2(n,Fnx,X) _LOOPXC_1(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_2,Fnx,X)
#define _LOOPXC_3(n,Fnx,X) _LOOPXC_2(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_3,Fnx,X)
#define _LOOPXC_4(n,Fnx,X) _LOOPXC_3(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_4,Fnx,X)
#define _LOOPXC_5(n,Fnx,X) _LOOPXC_4(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_5,Fnx,X)
#define _LOOPXC_6(n,Fnx,X) _LOOPXC_5(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_6,Fnx,X)
#define _LOOPXC_7(n,Fnx,X) _LOOPXC_6(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_7,Fnx,X)
#define _LOOPXC_8(n,Fnx,X) _LOOPXC_7(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_8,Fnx,X)
#define _LOOPXC_9(n,Fnx,X) _LOOPXC_8(9,Fnx,X), LOOPXXC_0_N(n,PREFIX_NUMBER_X_9,Fnx,X)
#define _LOOPXC_NN(n1,n2,Fnx,X) _LOOPXC_##n1(n2,Fnx,X)
//Fn(001),Fn(002),Fn(003),...)
#define _LOOPC__0(n1,n2,Fn)                 _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER0,Fn)
#define _LOOPC__1(n1,n2,Fn) _LOOPC__0(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER1,Fn)
#define _LOOPC__2(n1,n2,Fn) _LOOPC__1(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER2,Fn)
#define _LOOPC__3(n1,n2,Fn) _LOOPC__2(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER3,Fn)
#define _LOOPC__4(n1,n2,Fn) _LOOPC__3(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER4,Fn)
#define _LOOPC__5(n1,n2,Fn) _LOOPC__4(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER5,Fn)
#define _LOOPC__6(n1,n2,Fn) _LOOPC__5(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER6,Fn)
#define _LOOPC__7(n1,n2,Fn) _LOOPC__6(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER7,Fn)
#define _LOOPC__8(n1,n2,Fn) _LOOPC__7(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER8,Fn)
#define _LOOPC__9(n1,n2,Fn) _LOOPC__8(9,9,Fn) _LOOPXC_0_NN(n1,n2,PREFIX_NUMBER9,Fn)
#define _LOOPC_NNN(n1,n2,n3,Fn) _LOOPC__##n1(n2,n3,Fn)

#define REPEATC_N(n,Fn) LOOPC_N(n,Fn)
#define REPEATC_NN(n1,n2,Fn) _LOOPC_NN(n1,n2,Fn)
#define REPEATC_NNN(n1,n2,n3,Fn) _LOOPC_NNN(n1,n2,n3,Fn)

#endif //_REPEAT_H_
