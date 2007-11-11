#ifndef _REPEAT2_H_
#define _REPEAT2_H_

#define _2_REP_ZEROTEST0(a,b) a
#define _2_REP_ZEROTEST1(a,b) b
#define _2_REP_ZEROTEST2(a,b) b
#define _2_REP_ZEROTEST3(a,b) b
#define _2_REP_ZEROTEST4(a,b) b
#define _2_REP_ZEROTEST5(a,b) b
#define _2_REP_ZEROTEST6(a,b) b
#define _2_REP_ZEROTEST7(a,b) b
#define _2_REP_ZEROTEST8(a,b) b
#define _2_REP_ZEROTEST9(a,b) b

#define _2_REP0(Fn)
#define _2_REP1(Fn) Fn(1)
#define _2_REP2(Fn) _2_REP1(Fn) Fn(2)
#define _2_REP3(Fn) _2_REP2(Fn) Fn(3)
#define _2_REP4(Fn) _2_REP3(Fn) Fn(4)
#define _2_REP5(Fn) _2_REP4(Fn) Fn(5)
#define _2_REP6(Fn) _2_REP5(Fn) Fn(6)
#define _2_REP7(Fn) _2_REP6(Fn) Fn(7)
#define _2_REP8(Fn) _2_REP7(Fn) Fn(8)
#define _2_REP9(Fn) _2_REP8(Fn) Fn(9)

#define _2_REP_N(n,Fn) _2_REP##n(Fn)
#define _2_REP_0_N(n,Fn) Fn(0) _2_REP##n(Fn)
#define _2_REP_0_9(Fn) Fn(0) _2_REP9(Fn)

#define _2_REPC0(Fn1,Fn)
#define _2_REPC1(Fn1,Fn) Fn1(1)
#define _2_REPC2(Fn1,Fn) _2_REPC1(Fn1,Fn) Fn(2)
#define _2_REPC3(Fn1,Fn) _2_REPC2(Fn1,Fn) Fn(3)
#define _2_REPC4(Fn1,Fn) _2_REPC3(Fn1,Fn) Fn(4)
#define _2_REPC5(Fn1,Fn) _2_REPC4(Fn1,Fn) Fn(5)
#define _2_REPC6(Fn1,Fn) _2_REPC5(Fn1,Fn) Fn(6)
#define _2_REPC7(Fn1,Fn) _2_REPC6(Fn1,Fn) Fn(7)
#define _2_REPC8(Fn1,Fn) _2_REPC7(Fn1,Fn) Fn(8)
#define _2_REPC9(Fn1,Fn) _2_REPC8(Fn1,Fn) Fn(9)

#define _2_REPC_N(n,Fn1,Fn) _2_REPC##n(Fn1,Fn)
#define _2_REPC_0_N(n,Fn1,Fn) Fn1(0) _2_REP##n(Fn)

#define _2_REPX0(Fxn,X)
#define _2_REPX1(Fxn,X)				Fxn(X,1)
#define _2_REPX2(Fxn,X) _2_REPX1(Fxn,X) Fxn(X,2)
#define _2_REPX3(Fxn,X) _2_REPX2(Fxn,X) Fxn(X,3)
#define _2_REPX4(Fxn,X) _2_REPX3(Fxn,X) Fxn(X,4)
#define _2_REPX5(Fxn,X) _2_REPX4(Fxn,X) Fxn(X,5)
#define _2_REPX6(Fxn,X) _2_REPX5(Fxn,X) Fxn(X,6)
#define _2_REPX7(Fxn,X) _2_REPX6(Fxn,X) Fxn(X,7)
#define _2_REPX8(Fxn,X) _2_REPX7(Fxn,X) Fxn(X,8)
#define _2_REPX9(Fxn,X) _2_REPX8(Fxn,X) Fxn(X,9)

#define _2_REPX_N(n,Fxn,X) _2_REPX##n(Fxn,X)
#define _2_REPX_0_N(n,Fxn,X) Fxn(X,0) _2_REPX##n(Fxn,X)
#define _2_REPX_0_9(Fxn,X) Fxn(X,0) _2_REPX9(Fxn,X)

#define _2_REPXC0(Fxn1,Fxn,X)
#define _2_REPXC1(Fxn1,Fxn,X)				Fxn1(X,1)
#define _2_REPXC2(Fxn1,Fxn,X) _2_REPXC1(Fxn1,Fxn,X) Fxn(X,2)
#define _2_REPXC3(Fxn1,Fxn,X) _2_REPXC2(Fxn1,Fxn,X) Fxn(X,3)
#define _2_REPXC4(Fxn1,Fxn,X) _2_REPXC3(Fxn1,Fxn,X) Fxn(X,4)
#define _2_REPXC5(Fxn1,Fxn,X) _2_REPXC4(Fxn1,Fxn,X) Fxn(X,5)
#define _2_REPXC6(Fxn1,Fxn,X) _2_REPXC5(Fxn1,Fxn,X) Fxn(X,6)
#define _2_REPXC7(Fxn1,Fxn,X) _2_REPXC6(Fxn1,Fxn,X) Fxn(X,7)
#define _2_REPXC8(Fxn1,Fxn,X) _2_REPXC7(Fxn1,Fxn,X) Fxn(X,8)
#define _2_REPXC9(Fxn1,Fxn,X) _2_REPXC8(Fxn1,Fxn,X) Fxn(X,9)

#define _2_REPXC_N(n,Fxn1,Fxn,X) _2_REPXC##n(Fxn,X)
#define _2_REPXC_0_N(n,Fxn1,Fxn,X) Fxn1(X,0) _2_REPX##n(Fxn,X)

#define __2_REPX0(Fxn,X)
#define __2_REPX1(Fxn,X)				  Fxn(X,1)
#define __2_REPX2(Fxn,X) __2_REPX1(Fxn,X) Fxn(X,2)
#define __2_REPX3(Fxn,X) __2_REPX2(Fxn,X) Fxn(X,3)
#define __2_REPX4(Fxn,X) __2_REPX3(Fxn,X) Fxn(X,4)
#define __2_REPX5(Fxn,X) __2_REPX4(Fxn,X) Fxn(X,5)
#define __2_REPX6(Fxn,X) __2_REPX5(Fxn,X) Fxn(X,6)
#define __2_REPX7(Fxn,X) __2_REPX6(Fxn,X) Fxn(X,7)
#define __2_REPX8(Fxn,X) __2_REPX7(Fxn,X) Fxn(X,8)
#define __2_REPX9(Fxn,X) __2_REPX8(Fxn,X) Fxn(X,9)

#define I__2_REPX0(Fxn,X) 
#define I__2_REPX1(Fxn,X) __2_REPX0(Fxn,X)
#define I__2_REPX2(Fxn,X) __2_REPX1(Fxn,X)
#define I__2_REPX3(Fxn,X) __2_REPX2(Fxn,X)
#define I__2_REPX4(Fxn,X) __2_REPX3(Fxn,X)
#define I__2_REPX5(Fxn,X) __2_REPX4(Fxn,X)
#define I__2_REPX6(Fxn,X) __2_REPX5(Fxn,X)
#define I__2_REPX7(Fxn,X) __2_REPX6(Fxn,X)
#define I__2_REPX8(Fxn,X) __2_REPX7(Fxn,X)
#define I__2_REPX9(Fxn,X) __2_REPX8(Fxn,X)

#define _2_REP_NN(n1,n2,Fnn) \
	_2_REP_ZEROTEST##n1(\
		_2_REPX_N(n2,Fnn,0)\
		,\
		_2_REPX_N(9,Fnn,0) I__2_REPX##n1(_2_REPX_0_9,Fnn) _2_REPX_0_N(n2,Fnn, n1)\
	)
#define _2_REP_0_NN(n1,n2,Fnn) \
	_2_REP_ZEROTEST##n1(\
		_2_REPX_0_N(n2,Fnn,0)\
		,\
		_2_REPX_0_N(9,Fnn,0) I__2_REPX##n1(_2_REPX_0_9,Fnn) _2_REPX_0_N(n2,Fnn, n1)\
	)
#define _2_REPC_NN(n1,n2,Fnn1,Fnn) \
	_2_REP_ZEROTEST##n1(\
		_2_REPXC_N(n2,Fnn1,Fnn,0)\
		,\
		_2_REPXC_N(9,Fnn1,Fnn,0) I__2_REPX##n1(_2_REPX_0_9,Fnn) _2_REPX_0_N(n2,Fnn, n1)\
	)
#define _2_REPC_0_NN(n1,n2,Fnn1,Fnn) \
	_2_REP_ZEROTEST##n1(\
		_2_REPXC_0_N(n2,Fnn1,Fnn,0)\
		,\
		_2_REPXC_0_N(9,Fnn1,Fnn,0) I__2_REPX##n1(_2_REPX_0_9,Fnn) _2_REPX_0_N(n2,Fnn, n1)\
	)

#define _2_REPXX0(Fxxn,X1,X2)
#define _2_REPXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define _2_REPXX2(Fxxn,X1,X2) _2_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define _2_REPXX3(Fxxn,X1,X2) _2_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define _2_REPXX4(Fxxn,X1,X2) _2_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define _2_REPXX5(Fxxn,X1,X2) _2_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define _2_REPXX6(Fxxn,X1,X2) _2_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define _2_REPXX7(Fxxn,X1,X2) _2_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define _2_REPXX8(Fxxn,X1,X2) _2_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define _2_REPXX9(Fxxn,X1,X2) _2_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define _2_REPXX_N(n,Fxxn,X1,X2) _2_REPXX##n(Fxxn,X1,X2)
#define _2_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) _2_REPXX##n(Fxxn,X1,X2)
#define _2_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) _2_REPXX9(Fxxn,X1,X2)

#define _2_REPXXC0(Fxxn1,Fxxn,X1,X2)
#define _2_REPXXC1(Fxxn1,Fxxn,X1,X2)						Fxxn1(X1,X2,1)
#define _2_REPXXC2(Fxxn1,Fxxn,X1,X2) _2_REPXXC1(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,2)
#define _2_REPXXC3(Fxxn1,Fxxn,X1,X2) _2_REPXXC2(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,3)
#define _2_REPXXC4(Fxxn1,Fxxn,X1,X2) _2_REPXXC3(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,4)
#define _2_REPXXC5(Fxxn1,Fxxn,X1,X2) _2_REPXXC4(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,5)
#define _2_REPXXC6(Fxxn1,Fxxn,X1,X2) _2_REPXXC5(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,6)
#define _2_REPXXC7(Fxxn1,Fxxn,X1,X2) _2_REPXXC6(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,7)
#define _2_REPXXC8(Fxxn1,Fxxn,X1,X2) _2_REPXXC7(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,8)
#define _2_REPXXC9(Fxxn1,Fxxn,X1,X2) _2_REPXXC8(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,9)

#define _2_REPXXC_N(n,Fxxn1,Fxxn,X1,X2) _2_REPXXC##n(Fxxn1,Fxxn,X1,X2)
#define _2_REPXXC_0_N(n,Fxxn1,Fxxn,X1,X2) Fxxn1(X1,X2,0) _2_REPXX##n(Fxxn,X1,X2)

#define __2_REPXX0(Fxxn,X1,X2)
#define __2_REPXX1(Fxxn,X1,X2)					  Fxxn(X1,X2,1)
#define __2_REPXX2(Fxxn,X1,X2) __2_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define __2_REPXX3(Fxxn,X1,X2) __2_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define __2_REPXX4(Fxxn,X1,X2) __2_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define __2_REPXX5(Fxxn,X1,X2) __2_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define __2_REPXX6(Fxxn,X1,X2) __2_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define __2_REPXX7(Fxxn,X1,X2) __2_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define __2_REPXX8(Fxxn,X1,X2) __2_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define __2_REPXX9(Fxxn,X1,X2) __2_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define __2_REPXX_N(n,Fxxn,X1,X2) __2_REPXX##n(Fxxn,X1,X2)
#define __2_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) __2_REPXX##n(Fxxn,X1,X2)
#define __2_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) __2_REPXX9(Fxxn,X1,X2)

#define ___2_REPXX0(Fxxn,X1,X2)
#define ___2_REPXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define ___2_REPXX2(Fxxn,X1,X2) ___2_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define ___2_REPXX3(Fxxn,X1,X2) ___2_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define ___2_REPXX4(Fxxn,X1,X2) ___2_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define ___2_REPXX5(Fxxn,X1,X2) ___2_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define ___2_REPXX6(Fxxn,X1,X2) ___2_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define ___2_REPXX7(Fxxn,X1,X2) ___2_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define ___2_REPXX8(Fxxn,X1,X2) ___2_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define ___2_REPXX9(Fxxn,X1,X2) ___2_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define ___2_REPXX_N(n,Fxxn,X1,X2) ___2_REPXX##n(Fxxn,X1,X2)
#define ___2_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) ___2_REPXX##n(Fxxn,X1,X2)
#define ___2_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) ___2_REPXX9(Fxxn,X1,X2)

#define I__2_REPXX0(Fxxn,X1,X2) 
#define I__2_REPXX1(Fxxn,X1,X2) ___2_REPXX0(Fxxn,X1,X2)
#define I__2_REPXX2(Fxxn,X1,X2) ___2_REPXX1(Fxxn,X1,X2)
#define I__2_REPXX3(Fxxn,X1,X2) ___2_REPXX2(Fxxn,X1,X2)
#define I__2_REPXX4(Fxxn,X1,X2) ___2_REPXX3(Fxxn,X1,X2)
#define I__2_REPXX5(Fxxn,X1,X2) ___2_REPXX4(Fxxn,X1,X2)
#define I__2_REPXX6(Fxxn,X1,X2) ___2_REPXX5(Fxxn,X1,X2)
#define I__2_REPXX7(Fxxn,X1,X2) ___2_REPXX6(Fxxn,X1,X2)
#define I__2_REPXX8(Fxxn,X1,X2) ___2_REPXX7(Fxxn,X1,X2)
#define I__2_REPXX9(Fxxn,X1,X2) ___2_REPXX8(Fxxn,X1,X2)

#define _2_REP_NNN(n1,n2,n3,Fnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_N(n3,Fnnn,0,0)\
			,\
			_2_REPXX_N(9,Fnnn,0,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,0) _2_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_2_REPXX_N(9,Fnnn,0,0) __2_REPXX9(_2_REPXX_0_9,Fnnn,0) I__2_REPXX##n1(__2_REPXX_0_9,_2_REPXX_0_9,Fnnn) \
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_2_REPXX_0_N(9,Fnnn,n1,0)  I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,n1) _2_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _2_REP_0_NNN(n1,n2,n3,Fnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_0_N(n3,Fnnn,0,0)\
			,\
			_2_REPXX_0_N(9,Fnnn,0,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,0) _2_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_2_REPXX_0_N(9,Fnnn,0,0) __2_REPXX9(_2_REPXX_0_9,Fnnn,0) I__2_REPXX##n1(__2_REPXX_0_9,_2_REPXX_0_9,Fnnn) \
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_2_REPXX_0_N(9,Fnnn,n1,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,n1) _2_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _2_REPC_NNN(n1,n2,n3,Fnnn1,Fnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REPXXC_N(n3,Fnnn1,Fnnn,0,0)\
			,\
			_2_REPXXC_N(9,Fnnn1,Fnnn,0,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,0) _2_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_2_REPXXC_N(9,Fnnn1,Fnnn,0,0) __2_REPXX9(_2_REPXX_0_9,Fnnn,0) I__2_REPXX##n1(__2_REPXX_0_9,_2_REPXX_0_9,Fnnn) \
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_2_REPXX_0_N(9,Fnnn,n1,0)  I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,n1) _2_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _2_REPC_0_NNN(n1,n2,n3,Fnnn1,Fnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REPXXC_0_N(n3,Fnnn1,Fnnn,0,0)\
			,\
			_2_REPXXC_0_N(9,Fnnn1,Fnnn,0,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,0) _2_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_2_REPXXC_0_N(9,Fnnn1,Fnnn,0,0) __2_REPXX9(_2_REPXX_0_9,Fnnn,0) I__2_REPXX##n1(__2_REPXX_0_9,_2_REPXX_0_9,Fnnn) \
		_2_REP_ZEROTEST##n2(\
			_2_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_2_REPXX_0_N(9,Fnnn,n1,0) I__2_REPXX##n2(_2_REPXX_0_9,Fnnn,n1) _2_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)


#define _2_REPXXX0(Fxxxn,X1,X2,X3)
#define _2_REPXXX1(Fxxxn,X1,X2,X3)						  Fxxxn(X1,X2,X3,1)
#define _2_REPXXX2(Fxxxn,X1,X2,X3) _2_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define _2_REPXXX3(Fxxxn,X1,X2,X3) _2_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define _2_REPXXX4(Fxxxn,X1,X2,X3) _2_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define _2_REPXXX5(Fxxxn,X1,X2,X3) _2_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define _2_REPXXX6(Fxxxn,X1,X2,X3) _2_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define _2_REPXXX7(Fxxxn,X1,X2,X3) _2_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define _2_REPXXX8(Fxxxn,X1,X2,X3) _2_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define _2_REPXXX9(Fxxxn,X1,X2,X3) _2_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define _2_REPXXX_N(n,Fxxxn,X1,X2,X3) _2_REPXXX##n(Fxxxn,X1,X2,X3)
#define _2_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _2_REPXXX##n(Fxxxn,X1,X2,X3)
#define _2_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _2_REPXXX9(Fxxxn,X1,X2,X3)

#define _2_REPXXXC0(Fxxxn1,Fxxxn,X1,X2,X3)
#define _2_REPXXXC1(Fxxxn1,Fxxxn,X1,X2,X3)						  Fxxxn1(X1,X2,X3,1)
#define _2_REPXXXC2(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC1(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define _2_REPXXXC3(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC2(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define _2_REPXXXC4(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC3(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define _2_REPXXXC5(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC4(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define _2_REPXXXC6(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC5(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define _2_REPXXXC7(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC6(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define _2_REPXXXC8(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC7(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define _2_REPXXXC9(Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC8(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define _2_REPXXXC_N(n,Fxxxn1,Fxxxn,X1,X2,X3) _2_REPXXXC##n(Fxxxn,X1,X2,X3)
#define _2_REPXXXC_0_N(n,Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn1(X1,X2,X3,0) _2_REPXXX##n(Fxxxn,X1,X2,X3)

#define __2_REPXXX0(Fxxxn,X1,X2,X3) 
#define __2_REPXXX1(Fxxxn,X1,X2,X3)							Fxxxn(X1,X2,X3,1)
#define __2_REPXXX2(Fxxxn,X1,X2,X3) __2_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define __2_REPXXX3(Fxxxn,X1,X2,X3) __2_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define __2_REPXXX4(Fxxxn,X1,X2,X3) __2_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define __2_REPXXX5(Fxxxn,X1,X2,X3) __2_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define __2_REPXXX6(Fxxxn,X1,X2,X3) __2_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define __2_REPXXX7(Fxxxn,X1,X2,X3) __2_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define __2_REPXXX8(Fxxxn,X1,X2,X3) __2_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define __2_REPXXX9(Fxxxn,X1,X2,X3) __2_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define __2_REPXXX_N(n,Fxxxn,X1,X2,X3) __2_REPXXX##n(Fxxxn,X1,X2,X3)
#define __2_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __2_REPXXX##n(Fxxxn,X1,X2,X3)
#define __2_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __2_REPXXX9(Fxxxn,X1,X2,X3)

#define ___2_REPXXX0(Fxxxn,X1,X2,X3)	
#define ___2_REPXXX1(Fxxxn,X1,X2,X3)							  Fxxxn(X1,X2,X3,1)
#define ___2_REPXXX2(Fxxxn,X1,X2,X3) ___2_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define ___2_REPXXX3(Fxxxn,X1,X2,X3) ___2_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define ___2_REPXXX4(Fxxxn,X1,X2,X3) ___2_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define ___2_REPXXX5(Fxxxn,X1,X2,X3) ___2_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define ___2_REPXXX6(Fxxxn,X1,X2,X3) ___2_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define ___2_REPXXX7(Fxxxn,X1,X2,X3) ___2_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define ___2_REPXXX8(Fxxxn,X1,X2,X3) ___2_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define ___2_REPXXX9(Fxxxn,X1,X2,X3) ___2_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define ___2_REPXXX_N(n,Fxxxn,X1,X2,X3) ___2_REPXXX##n(Fxxxn,X1,X2,X3)
#define ___2_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___2_REPXXX##n(Fxxxn,X1,X2,X3)
#define ___2_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___2_REPXXX9(Fxxxn,X1,X2,X3)

#define ____2_REPXXX0(Fxxxn,X1,X2,X3)	
#define ____2_REPXXX1(Fxxxn,X1,X2,X3)								Fxxxn(X1,X2,X3,1)
#define ____2_REPXXX2(Fxxxn,X1,X2,X3) ____2_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define ____2_REPXXX3(Fxxxn,X1,X2,X3) ____2_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define ____2_REPXXX4(Fxxxn,X1,X2,X3) ____2_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define ____2_REPXXX5(Fxxxn,X1,X2,X3) ____2_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define ____2_REPXXX6(Fxxxn,X1,X2,X3) ____2_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define ____2_REPXXX7(Fxxxn,X1,X2,X3) ____2_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define ____2_REPXXX8(Fxxxn,X1,X2,X3) ____2_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define ____2_REPXXX9(Fxxxn,X1,X2,X3) ____2_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define ____2_REPXXX_N(n,Fxxxn,X1,X2,X3) ____2_REPXXX##n(Fxxxn,X1,X2,X3)
#define ____2_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ____2_REPXXX##n(Fxxxn,X1,X2,X3)
#define ____2_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ____2_REPXXX9(Fxxxn,X1,X2,X3)

#define I__2_REPXXX0(Fxxxn,X1,X2,X3) 
#define I__2_REPXXX1(Fxxxn,X1,X2,X3) ____2_REPXXX0(Fxxxn,X1,X2,X3)
#define I__2_REPXXX2(Fxxxn,X1,X2,X3) ____2_REPXXX1(Fxxxn,X1,X2,X3)
#define I__2_REPXXX3(Fxxxn,X1,X2,X3) ____2_REPXXX2(Fxxxn,X1,X2,X3)
#define I__2_REPXXX4(Fxxxn,X1,X2,X3) ____2_REPXXX3(Fxxxn,X1,X2,X3)
#define I__2_REPXXX5(Fxxxn,X1,X2,X3) ____2_REPXXX4(Fxxxn,X1,X2,X3)
#define I__2_REPXXX6(Fxxxn,X1,X2,X3) ____2_REPXXX5(Fxxxn,X1,X2,X3)
#define I__2_REPXXX7(Fxxxn,X1,X2,X3) ____2_REPXXX6(Fxxxn,X1,X2,X3)
#define I__2_REPXXX8(Fxxxn,X1,X2,X3) ____2_REPXXX7(Fxxxn,X1,X2,X3)
#define I__2_REPXXX9(Fxxxn,X1,X2,X3) ____2_REPXXX8(Fxxxn,X1,X2,X3)

#define _2_REP_NNNN(n1,n2,n3,n4,Fnnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_N(n4,Fnnnn,0,0,0)\
				,\
				_2_REPXXX_N(9,Fnnnn,0,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,0) _2_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_2_REPXXX_N(9,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,0)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,0,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,n2) _2_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_2_REPXXX_N(9,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) ___2_REPXXX9(__2_REPXXX_0_9, _2_REPXXX_0_9,Fnnnn,0) I__2_REPXXX##n1(___2_REPXXX_0_9,__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn)\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,0) _2_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_2_REPXXX_0_N(9,Fnnnn,n1,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,n1,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,n1)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,n2) _2_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _2_REP_0_NNNN(n1,n2,n3,n4,Fnnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,0,0,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,0,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,0) _2_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_2_REPXXX_0_N(9,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,0)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,0,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,n2) _2_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_2_REPXXX_0_N(9,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) ___2_REPXXX9(__2_REPXXX_0_9, _2_REPXXX_0_9,Fnnnn,0) I__2_REPXXX##n1(___2_REPXXX_0_9,__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn)\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,0) _2_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_2_REPXXX_0_N(9,Fnnnn,n1,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,n1,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,n1)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,n2) _2_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _2_REPC_NNNN(n1,n2,n3,n4,Fnnnn1,Fnnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXXC_N(n4,Fnnnn1,Fnnnn,0,0,0)\
				,\
				_2_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,0) _2_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_2_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,0)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,0,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,n2) _2_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_2_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) ___2_REPXXX9(__2_REPXXX_0_9, _2_REPXXX_0_9,Fnnnn,0) I__2_REPXXX##n1(___2_REPXXX_0_9,__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn)\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,0) _2_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_2_REPXXX_0_N(9,Fnnnn,n1,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,n1,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,n1)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,n2) _2_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _2_REPC_0_NNNN(n1,n2,n3,n4,Fnnnn1,Fnnnn)\
	_2_REP_ZEROTEST##n1(\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXXC_0_N(n4,Fnnnn1,Fnnnn,0,0,0)\
				,\
				_2_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,0) _2_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_2_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,0)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,0,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,0,n2) _2_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_2_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,0,0) ___2_REPXXX9(__2_REPXXX_0_9, _2_REPXXX_0_9,Fnnnn,0) I__2_REPXXX##n1(___2_REPXXX_0_9,__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn)\
		_2_REP_ZEROTEST##n2(\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,0,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,0) _2_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_2_REPXXX_0_N(9,Fnnnn,n1,0,0) __2_REPXXX9(_2_REPXXX_0_9,Fnnnn,n1,0,0) I__2_REPXXX##n2(__2_REPXXX_0_9,_2_REPXXX_0_9,Fnnnn,n1)\
			_2_REP_ZEROTEST##n3(\
				_2_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_2_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__2_REPXXX##n3(_2_REPXXX_0_9,Fnnnn,n1,n2) _2_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#endif //_REPEAT2_H_
