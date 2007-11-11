#ifndef _REPEAT1_H_
#define _REPEAT1_H_

#define _1_REP_ZEROTEST0(a,b) a
#define _1_REP_ZEROTEST1(a,b) b
#define _1_REP_ZEROTEST2(a,b) b
#define _1_REP_ZEROTEST3(a,b) b
#define _1_REP_ZEROTEST4(a,b) b
#define _1_REP_ZEROTEST5(a,b) b
#define _1_REP_ZEROTEST6(a,b) b
#define _1_REP_ZEROTEST7(a,b) b
#define _1_REP_ZEROTEST8(a,b) b
#define _1_REP_ZEROTEST9(a,b) b

#define _1_REP0(Fn)
#define _1_REP1(Fn) Fn(1)
#define _1_REP2(Fn) _1_REP1(Fn) Fn(2)
#define _1_REP3(Fn) _1_REP2(Fn) Fn(3)
#define _1_REP4(Fn) _1_REP3(Fn) Fn(4)
#define _1_REP5(Fn) _1_REP4(Fn) Fn(5)
#define _1_REP6(Fn) _1_REP5(Fn) Fn(6)
#define _1_REP7(Fn) _1_REP6(Fn) Fn(7)
#define _1_REP8(Fn) _1_REP7(Fn) Fn(8)
#define _1_REP9(Fn) _1_REP8(Fn) Fn(9)

#define _1_REP_N(n,Fn) _1_REP##n(Fn)
#define _1_REP_0_N(n,Fn) Fn(0) _1_REP##n(Fn)
#define _1_REP_0_9(Fn) Fn(0) _1_REP9(Fn)

#define _1_REPC0(Fn1,Fn)
#define _1_REPC1(Fn1,Fn) Fn1(1)
#define _1_REPC2(Fn1,Fn) _1_REPC1(Fn1,Fn) Fn(2)
#define _1_REPC3(Fn1,Fn) _1_REPC2(Fn1,Fn) Fn(3)
#define _1_REPC4(Fn1,Fn) _1_REPC3(Fn1,Fn) Fn(4)
#define _1_REPC5(Fn1,Fn) _1_REPC4(Fn1,Fn) Fn(5)
#define _1_REPC6(Fn1,Fn) _1_REPC5(Fn1,Fn) Fn(6)
#define _1_REPC7(Fn1,Fn) _1_REPC6(Fn1,Fn) Fn(7)
#define _1_REPC8(Fn1,Fn) _1_REPC7(Fn1,Fn) Fn(8)
#define _1_REPC9(Fn1,Fn) _1_REPC8(Fn1,Fn) Fn(9)

#define _1_REPC_N(n,Fn1,Fn) _1_REPC##n(Fn1,Fn)
#define _1_REPC_0_N(n,Fn1,Fn) Fn1(0) _1_REP##n(Fn)

#define _1_REPX0(Fxn,X)
#define _1_REPX1(Fxn,X)				Fxn(X,1)
#define _1_REPX2(Fxn,X) _1_REPX1(Fxn,X) Fxn(X,2)
#define _1_REPX3(Fxn,X) _1_REPX2(Fxn,X) Fxn(X,3)
#define _1_REPX4(Fxn,X) _1_REPX3(Fxn,X) Fxn(X,4)
#define _1_REPX5(Fxn,X) _1_REPX4(Fxn,X) Fxn(X,5)
#define _1_REPX6(Fxn,X) _1_REPX5(Fxn,X) Fxn(X,6)
#define _1_REPX7(Fxn,X) _1_REPX6(Fxn,X) Fxn(X,7)
#define _1_REPX8(Fxn,X) _1_REPX7(Fxn,X) Fxn(X,8)
#define _1_REPX9(Fxn,X) _1_REPX8(Fxn,X) Fxn(X,9)

#define _1_REPX_N(n,Fxn,X) _1_REPX##n(Fxn,X)
#define _1_REPX_0_N(n,Fxn,X) Fxn(X,0) _1_REPX##n(Fxn,X)
#define _1_REPX_0_9(Fxn,X) Fxn(X,0) _1_REPX9(Fxn,X)

#define _1_REPXC0(Fxn1,Fxn,X)
#define _1_REPXC1(Fxn1,Fxn,X)				Fxn1(X,1)
#define _1_REPXC2(Fxn1,Fxn,X) _1_REPXC1(Fxn1,Fxn,X) Fxn(X,2)
#define _1_REPXC3(Fxn1,Fxn,X) _1_REPXC2(Fxn1,Fxn,X) Fxn(X,3)
#define _1_REPXC4(Fxn1,Fxn,X) _1_REPXC3(Fxn1,Fxn,X) Fxn(X,4)
#define _1_REPXC5(Fxn1,Fxn,X) _1_REPXC4(Fxn1,Fxn,X) Fxn(X,5)
#define _1_REPXC6(Fxn1,Fxn,X) _1_REPXC5(Fxn1,Fxn,X) Fxn(X,6)
#define _1_REPXC7(Fxn1,Fxn,X) _1_REPXC6(Fxn1,Fxn,X) Fxn(X,7)
#define _1_REPXC8(Fxn1,Fxn,X) _1_REPXC7(Fxn1,Fxn,X) Fxn(X,8)
#define _1_REPXC9(Fxn1,Fxn,X) _1_REPXC8(Fxn1,Fxn,X) Fxn(X,9)

#define _1_REPXC_N(n,Fxn1,Fxn,X) _1_REPXC##n(Fxn,X)
#define _1_REPXC_0_N(n,Fxn1,Fxn,X) Fxn1(X,0) _1_REPX##n(Fxn,X)

#define __1_REPX0(Fxn,X)
#define __1_REPX1(Fxn,X)				  Fxn(X,1)
#define __1_REPX2(Fxn,X) __1_REPX1(Fxn,X) Fxn(X,2)
#define __1_REPX3(Fxn,X) __1_REPX2(Fxn,X) Fxn(X,3)
#define __1_REPX4(Fxn,X) __1_REPX3(Fxn,X) Fxn(X,4)
#define __1_REPX5(Fxn,X) __1_REPX4(Fxn,X) Fxn(X,5)
#define __1_REPX6(Fxn,X) __1_REPX5(Fxn,X) Fxn(X,6)
#define __1_REPX7(Fxn,X) __1_REPX6(Fxn,X) Fxn(X,7)
#define __1_REPX8(Fxn,X) __1_REPX7(Fxn,X) Fxn(X,8)
#define __1_REPX9(Fxn,X) __1_REPX8(Fxn,X) Fxn(X,9)

#define I__1_REPX0(Fxn,X) 
#define I__1_REPX1(Fxn,X) __1_REPX0(Fxn,X)
#define I__1_REPX2(Fxn,X) __1_REPX1(Fxn,X)
#define I__1_REPX3(Fxn,X) __1_REPX2(Fxn,X)
#define I__1_REPX4(Fxn,X) __1_REPX3(Fxn,X)
#define I__1_REPX5(Fxn,X) __1_REPX4(Fxn,X)
#define I__1_REPX6(Fxn,X) __1_REPX5(Fxn,X)
#define I__1_REPX7(Fxn,X) __1_REPX6(Fxn,X)
#define I__1_REPX8(Fxn,X) __1_REPX7(Fxn,X)
#define I__1_REPX9(Fxn,X) __1_REPX8(Fxn,X)

#define _1_REP_NN(n1,n2,Fnn) \
	_1_REP_ZEROTEST##n1(\
		_1_REPX_N(n2,Fnn,0)\
		,\
		_1_REPX_N(9,Fnn,0) I__1_REPX##n1(_1_REPX_0_9,Fnn) _1_REPX_0_N(n2,Fnn, n1)\
	)
#define _1_REP_0_NN(n1,n2,Fnn) \
	_1_REP_ZEROTEST##n1(\
		_1_REPX_0_N(n2,Fnn,0)\
		,\
		_1_REPX_0_N(9,Fnn,0) I__1_REPX##n1(_1_REPX_0_9,Fnn) _1_REPX_0_N(n2,Fnn, n1)\
	)
#define _1_REPC_NN(n1,n2,Fnn1,Fnn) \
	_1_REP_ZEROTEST##n1(\
		_1_REPXC_N(n2,Fnn1,Fnn,0)\
		,\
		_1_REPXC_N(9,Fnn1,Fnn,0) I__1_REPX##n1(_1_REPX_0_9,Fnn) _1_REPX_0_N(n2,Fnn, n1)\
	)
#define _1_REPC_0_NN(n1,n2,Fnn1,Fnn) \
	_1_REP_ZEROTEST##n1(\
		_1_REPXC_0_N(n2,Fnn1,Fnn,0)\
		,\
		_1_REPXC_0_N(9,Fnn1,Fnn,0) I__1_REPX##n1(_1_REPX_0_9,Fnn) _1_REPX_0_N(n2,Fnn, n1)\
	)

#define _1_REPXX0(Fxxn,X1,X2)
#define _1_REPXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define _1_REPXX2(Fxxn,X1,X2) _1_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define _1_REPXX3(Fxxn,X1,X2) _1_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define _1_REPXX4(Fxxn,X1,X2) _1_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define _1_REPXX5(Fxxn,X1,X2) _1_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define _1_REPXX6(Fxxn,X1,X2) _1_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define _1_REPXX7(Fxxn,X1,X2) _1_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define _1_REPXX8(Fxxn,X1,X2) _1_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define _1_REPXX9(Fxxn,X1,X2) _1_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define _1_REPXX_N(n,Fxxn,X1,X2) _1_REPXX##n(Fxxn,X1,X2)
#define _1_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) _1_REPXX##n(Fxxn,X1,X2)
#define _1_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) _1_REPXX9(Fxxn,X1,X2)

#define _1_REPXXC0(Fxxn1,Fxxn,X1,X2)
#define _1_REPXXC1(Fxxn1,Fxxn,X1,X2)						Fxxn1(X1,X2,1)
#define _1_REPXXC2(Fxxn1,Fxxn,X1,X2) _1_REPXXC1(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,2)
#define _1_REPXXC3(Fxxn1,Fxxn,X1,X2) _1_REPXXC2(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,3)
#define _1_REPXXC4(Fxxn1,Fxxn,X1,X2) _1_REPXXC3(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,4)
#define _1_REPXXC5(Fxxn1,Fxxn,X1,X2) _1_REPXXC4(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,5)
#define _1_REPXXC6(Fxxn1,Fxxn,X1,X2) _1_REPXXC5(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,6)
#define _1_REPXXC7(Fxxn1,Fxxn,X1,X2) _1_REPXXC6(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,7)
#define _1_REPXXC8(Fxxn1,Fxxn,X1,X2) _1_REPXXC7(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,8)
#define _1_REPXXC9(Fxxn1,Fxxn,X1,X2) _1_REPXXC8(Fxxn1,Fxxn,X1,X2) Fxxn(X1,X2,9)

#define _1_REPXXC_N(n,Fxxn1,Fxxn,X1,X2) _1_REPXXC##n(Fxxn1,Fxxn,X1,X2)
#define _1_REPXXC_0_N(n,Fxxn1,Fxxn,X1,X2) Fxxn1(X1,X2,0) _1_REPXX##n(Fxxn,X1,X2)

#define __1_REPXX0(Fxxn,X1,X2)
#define __1_REPXX1(Fxxn,X1,X2)					  Fxxn(X1,X2,1)
#define __1_REPXX2(Fxxn,X1,X2) __1_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define __1_REPXX3(Fxxn,X1,X2) __1_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define __1_REPXX4(Fxxn,X1,X2) __1_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define __1_REPXX5(Fxxn,X1,X2) __1_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define __1_REPXX6(Fxxn,X1,X2) __1_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define __1_REPXX7(Fxxn,X1,X2) __1_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define __1_REPXX8(Fxxn,X1,X2) __1_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define __1_REPXX9(Fxxn,X1,X2) __1_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define __1_REPXX_N(n,Fxxn,X1,X2) __1_REPXX##n(Fxxn,X1,X2)
#define __1_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) __1_REPXX##n(Fxxn,X1,X2)
#define __1_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) __1_REPXX9(Fxxn,X1,X2)

#define ___1_REPXX0(Fxxn,X1,X2)
#define ___1_REPXX1(Fxxn,X1,X2)						Fxxn(X1,X2,1)
#define ___1_REPXX2(Fxxn,X1,X2) ___1_REPXX1(Fxxn,X1,X2) Fxxn(X1,X2,2)
#define ___1_REPXX3(Fxxn,X1,X2) ___1_REPXX2(Fxxn,X1,X2) Fxxn(X1,X2,3)
#define ___1_REPXX4(Fxxn,X1,X2) ___1_REPXX3(Fxxn,X1,X2) Fxxn(X1,X2,4)
#define ___1_REPXX5(Fxxn,X1,X2) ___1_REPXX4(Fxxn,X1,X2) Fxxn(X1,X2,5)
#define ___1_REPXX6(Fxxn,X1,X2) ___1_REPXX5(Fxxn,X1,X2) Fxxn(X1,X2,6)
#define ___1_REPXX7(Fxxn,X1,X2) ___1_REPXX6(Fxxn,X1,X2) Fxxn(X1,X2,7)
#define ___1_REPXX8(Fxxn,X1,X2) ___1_REPXX7(Fxxn,X1,X2) Fxxn(X1,X2,8)
#define ___1_REPXX9(Fxxn,X1,X2) ___1_REPXX8(Fxxn,X1,X2) Fxxn(X1,X2,9)

#define ___1_REPXX_N(n,Fxxn,X1,X2) ___1_REPXX##n(Fxxn,X1,X2)
#define ___1_REPXX_0_N(n,Fxxn,X1,X2) Fxxn(X1,X2,0) ___1_REPXX##n(Fxxn,X1,X2)
#define ___1_REPXX_0_9(Fxxn,X1,X2) Fxxn(X1,X2,0) ___1_REPXX9(Fxxn,X1,X2)

#define I__1_REPXX0(Fxxn,X1,X2) 
#define I__1_REPXX1(Fxxn,X1,X2) ___1_REPXX0(Fxxn,X1,X2)
#define I__1_REPXX2(Fxxn,X1,X2) ___1_REPXX1(Fxxn,X1,X2)
#define I__1_REPXX3(Fxxn,X1,X2) ___1_REPXX2(Fxxn,X1,X2)
#define I__1_REPXX4(Fxxn,X1,X2) ___1_REPXX3(Fxxn,X1,X2)
#define I__1_REPXX5(Fxxn,X1,X2) ___1_REPXX4(Fxxn,X1,X2)
#define I__1_REPXX6(Fxxn,X1,X2) ___1_REPXX5(Fxxn,X1,X2)
#define I__1_REPXX7(Fxxn,X1,X2) ___1_REPXX6(Fxxn,X1,X2)
#define I__1_REPXX8(Fxxn,X1,X2) ___1_REPXX7(Fxxn,X1,X2)
#define I__1_REPXX9(Fxxn,X1,X2) ___1_REPXX8(Fxxn,X1,X2)

#define _1_REP_NNN(n1,n2,n3,Fnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_N(n3,Fnnn,0,0)\
			,\
			_1_REPXX_N(9,Fnnn,0,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,0) _1_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_1_REPXX_N(9,Fnnn,0,0) __1_REPXX9(_1_REPXX_0_9,Fnnn,0) I__1_REPXX##n1(__1_REPXX_0_9,_1_REPXX_0_9,Fnnn) \
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_1_REPXX_0_N(9,Fnnn,n1,0)  I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,n1) _1_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _1_REP_0_NNN(n1,n2,n3,Fnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_0_N(n3,Fnnn,0,0)\
			,\
			_1_REPXX_0_N(9,Fnnn,0,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,0) _1_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_1_REPXX_0_N(9,Fnnn,0,0) __1_REPXX9(_1_REPXX_0_9,Fnnn,0) I__1_REPXX##n1(__1_REPXX_0_9,_1_REPXX_0_9,Fnnn) \
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_1_REPXX_0_N(9,Fnnn,n1,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,n1) _1_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _1_REPC_NNN(n1,n2,n3,Fnnn1,Fnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REPXXC_N(n3,Fnnn1,Fnnn,0,0)\
			,\
			_1_REPXXC_N(9,Fnnn1,Fnnn,0,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,0) _1_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_1_REPXXC_N(9,Fnnn1,Fnnn,0,0) __1_REPXX9(_1_REPXX_0_9,Fnnn,0) I__1_REPXX##n1(__1_REPXX_0_9,_1_REPXX_0_9,Fnnn) \
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_1_REPXX_0_N(9,Fnnn,n1,0)  I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,n1) _1_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)
#define _1_REPC_0_NNN(n1,n2,n3,Fnnn1,Fnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REPXXC_0_N(n3,Fnnn1,Fnnn,0,0)\
			,\
			_1_REPXXC_0_N(9,Fnnn1,Fnnn,0,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,0) _1_REPXX_0_N(n3,Fnnn,0,n2)\
		)\
		,\
		_1_REPXXC_0_N(9,Fnnn1,Fnnn,0,0) __1_REPXX9(_1_REPXX_0_9,Fnnn,0) I__1_REPXX##n1(__1_REPXX_0_9,_1_REPXX_0_9,Fnnn) \
		_1_REP_ZEROTEST##n2(\
			_1_REPXX_0_N(n3,Fnnn,n1,0)\
			,\
			_1_REPXX_0_N(9,Fnnn,n1,0) I__1_REPXX##n2(_1_REPXX_0_9,Fnnn,n1) _1_REPXX_0_N(n3,Fnnn,n1,n2)\
		)\
	)


#define _1_REPXXX0(Fxxxn,X1,X2,X3)
#define _1_REPXXX1(Fxxxn,X1,X2,X3)						  Fxxxn(X1,X2,X3,1)
#define _1_REPXXX2(Fxxxn,X1,X2,X3) _1_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define _1_REPXXX3(Fxxxn,X1,X2,X3) _1_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define _1_REPXXX4(Fxxxn,X1,X2,X3) _1_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define _1_REPXXX5(Fxxxn,X1,X2,X3) _1_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define _1_REPXXX6(Fxxxn,X1,X2,X3) _1_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define _1_REPXXX7(Fxxxn,X1,X2,X3) _1_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define _1_REPXXX8(Fxxxn,X1,X2,X3) _1_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define _1_REPXXX9(Fxxxn,X1,X2,X3) _1_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define _1_REPXXX_N(n,Fxxxn,X1,X2,X3) _1_REPXXX##n(Fxxxn,X1,X2,X3)
#define _1_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _1_REPXXX##n(Fxxxn,X1,X2,X3)
#define _1_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) _1_REPXXX9(Fxxxn,X1,X2,X3)

#define _1_REPXXXC0(Fxxxn1,Fxxxn,X1,X2,X3)
#define _1_REPXXXC1(Fxxxn1,Fxxxn,X1,X2,X3)						  Fxxxn1(X1,X2,X3,1)
#define _1_REPXXXC2(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC1(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define _1_REPXXXC3(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC2(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define _1_REPXXXC4(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC3(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define _1_REPXXXC5(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC4(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define _1_REPXXXC6(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC5(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define _1_REPXXXC7(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC6(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define _1_REPXXXC8(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC7(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define _1_REPXXXC9(Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC8(Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define _1_REPXXXC_N(n,Fxxxn1,Fxxxn,X1,X2,X3) _1_REPXXXC##n(Fxxxn,X1,X2,X3)
#define _1_REPXXXC_0_N(n,Fxxxn1,Fxxxn,X1,X2,X3) Fxxxn1(X1,X2,X3,0) _1_REPXXX##n(Fxxxn,X1,X2,X3)

#define __1_REPXXX0(Fxxxn,X1,X2,X3) 
#define __1_REPXXX1(Fxxxn,X1,X2,X3)							Fxxxn(X1,X2,X3,1)
#define __1_REPXXX2(Fxxxn,X1,X2,X3) __1_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define __1_REPXXX3(Fxxxn,X1,X2,X3) __1_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define __1_REPXXX4(Fxxxn,X1,X2,X3) __1_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define __1_REPXXX5(Fxxxn,X1,X2,X3) __1_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define __1_REPXXX6(Fxxxn,X1,X2,X3) __1_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define __1_REPXXX7(Fxxxn,X1,X2,X3) __1_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define __1_REPXXX8(Fxxxn,X1,X2,X3) __1_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define __1_REPXXX9(Fxxxn,X1,X2,X3) __1_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define __1_REPXXX_N(n,Fxxxn,X1,X2,X3) __1_REPXXX##n(Fxxxn,X1,X2,X3)
#define __1_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __1_REPXXX##n(Fxxxn,X1,X2,X3)
#define __1_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) __1_REPXXX9(Fxxxn,X1,X2,X3)

#define ___1_REPXXX0(Fxxxn,X1,X2,X3)	
#define ___1_REPXXX1(Fxxxn,X1,X2,X3)							  Fxxxn(X1,X2,X3,1)
#define ___1_REPXXX2(Fxxxn,X1,X2,X3) ___1_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define ___1_REPXXX3(Fxxxn,X1,X2,X3) ___1_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define ___1_REPXXX4(Fxxxn,X1,X2,X3) ___1_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define ___1_REPXXX5(Fxxxn,X1,X2,X3) ___1_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define ___1_REPXXX6(Fxxxn,X1,X2,X3) ___1_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define ___1_REPXXX7(Fxxxn,X1,X2,X3) ___1_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define ___1_REPXXX8(Fxxxn,X1,X2,X3) ___1_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define ___1_REPXXX9(Fxxxn,X1,X2,X3) ___1_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define ___1_REPXXX_N(n,Fxxxn,X1,X2,X3) ___1_REPXXX##n(Fxxxn,X1,X2,X3)
#define ___1_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___1_REPXXX##n(Fxxxn,X1,X2,X3)
#define ___1_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ___1_REPXXX9(Fxxxn,X1,X2,X3)

#define ____1_REPXXX0(Fxxxn,X1,X2,X3)	
#define ____1_REPXXX1(Fxxxn,X1,X2,X3)								Fxxxn(X1,X2,X3,1)
#define ____1_REPXXX2(Fxxxn,X1,X2,X3) ____1_REPXXX1(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,2)
#define ____1_REPXXX3(Fxxxn,X1,X2,X3) ____1_REPXXX2(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,3)
#define ____1_REPXXX4(Fxxxn,X1,X2,X3) ____1_REPXXX3(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,4)
#define ____1_REPXXX5(Fxxxn,X1,X2,X3) ____1_REPXXX4(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,5)
#define ____1_REPXXX6(Fxxxn,X1,X2,X3) ____1_REPXXX5(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,6)
#define ____1_REPXXX7(Fxxxn,X1,X2,X3) ____1_REPXXX6(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,7)
#define ____1_REPXXX8(Fxxxn,X1,X2,X3) ____1_REPXXX7(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,8)
#define ____1_REPXXX9(Fxxxn,X1,X2,X3) ____1_REPXXX8(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,9)

#define ____1_REPXXX_N(n,Fxxxn,X1,X2,X3) ____1_REPXXX##n(Fxxxn,X1,X2,X3)
#define ____1_REPXXX_0_N(n,Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ____1_REPXXX##n(Fxxxn,X1,X2,X3)
#define ____1_REPXXX_0_9(Fxxxn,X1,X2,X3) Fxxxn(X1,X2,X3,0) ____1_REPXXX9(Fxxxn,X1,X2,X3)

#define I__1_REPXXX0(Fxxxn,X1,X2,X3) 
#define I__1_REPXXX1(Fxxxn,X1,X2,X3) ____1_REPXXX0(Fxxxn,X1,X2,X3)
#define I__1_REPXXX2(Fxxxn,X1,X2,X3) ____1_REPXXX1(Fxxxn,X1,X2,X3)
#define I__1_REPXXX3(Fxxxn,X1,X2,X3) ____1_REPXXX2(Fxxxn,X1,X2,X3)
#define I__1_REPXXX4(Fxxxn,X1,X2,X3) ____1_REPXXX3(Fxxxn,X1,X2,X3)
#define I__1_REPXXX5(Fxxxn,X1,X2,X3) ____1_REPXXX4(Fxxxn,X1,X2,X3)
#define I__1_REPXXX6(Fxxxn,X1,X2,X3) ____1_REPXXX5(Fxxxn,X1,X2,X3)
#define I__1_REPXXX7(Fxxxn,X1,X2,X3) ____1_REPXXX6(Fxxxn,X1,X2,X3)
#define I__1_REPXXX8(Fxxxn,X1,X2,X3) ____1_REPXXX7(Fxxxn,X1,X2,X3)
#define I__1_REPXXX9(Fxxxn,X1,X2,X3) ____1_REPXXX8(Fxxxn,X1,X2,X3)

#define _1_REP_NNNN(n1,n2,n3,n4,Fnnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_N(n4,Fnnnn,0,0,0)\
				,\
				_1_REPXXX_N(9,Fnnnn,0,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,0) _1_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_1_REPXXX_N(9,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,0)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,0,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,n2) _1_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_1_REPXXX_N(9,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) ___1_REPXXX9(__1_REPXXX_0_9, _1_REPXXX_0_9,Fnnnn,0) I__1_REPXXX##n1(___1_REPXXX_0_9,__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn)\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,0) _1_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_1_REPXXX_0_N(9,Fnnnn,n1,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,n1,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,n1)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,n2) _1_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _1_REP_0_NNNN(n1,n2,n3,n4,Fnnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,0,0,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,0,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,0) _1_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_1_REPXXX_0_N(9,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,0)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,0,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,n2) _1_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_1_REPXXX_0_N(9,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) ___1_REPXXX9(__1_REPXXX_0_9, _1_REPXXX_0_9,Fnnnn,0) I__1_REPXXX##n1(___1_REPXXX_0_9,__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn)\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,0) _1_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_1_REPXXX_0_N(9,Fnnnn,n1,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,n1,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,n1)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,n2) _1_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _1_REPC_NNNN(n1,n2,n3,n4,Fnnnn1,Fnnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXXC_N(n4,Fnnnn1,Fnnnn,0,0,0)\
				,\
				_1_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,0) _1_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_1_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,0)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,0,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,n2) _1_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_1_REPXXXC_N(9,Fnnnn1,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) ___1_REPXXX9(__1_REPXXX_0_9, _1_REPXXX_0_9,Fnnnn,0) I__1_REPXXX##n1(___1_REPXXX_0_9,__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn)\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,0) _1_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_1_REPXXX_0_N(9,Fnnnn,n1,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,n1,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,n1)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,n2) _1_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)
#define _1_REPC_0_NNNN(n1,n2,n3,n4,Fnnnn1,Fnnnn)\
	_1_REP_ZEROTEST##n1(\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXXC_0_N(n4,Fnnnn1,Fnnnn,0,0,0)\
				,\
				_1_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,0) _1_REPXXX_0_N(n4,Fnnnn,0,0,n3)\
			)\
			,\
			_1_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,0)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,0,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,0,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,0,n2) _1_REPXXX_0_N(n4,Fnnnn,0,n2,n3)\
			)\
		)\
		,\
		_1_REPXXXC_0_N(9,Fnnnn1,Fnnnn,0,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,0,0) ___1_REPXXX9(__1_REPXXX_0_9, _1_REPXXX_0_9,Fnnnn,0) I__1_REPXXX##n1(___1_REPXXX_0_9,__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn)\
		_1_REP_ZEROTEST##n2(\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,0,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,0,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,0) _1_REPXXX_0_N(n4,Fnnnn,n1,0,n3)\
			)\
			,\
			_1_REPXXX_0_N(9,Fnnnn,n1,0,0) __1_REPXXX9(_1_REPXXX_0_9,Fnnnn,n1,0,0) I__1_REPXXX##n2(__1_REPXXX_0_9,_1_REPXXX_0_9,Fnnnn,n1)\
			_1_REP_ZEROTEST##n3(\
				_1_REPXXX_0_N(n4,Fnnnn,n1,n2,0)\
				,\
				_1_REPXXX_0_N(9,Fnnnn,n1,n2,0) I__1_REPXXX##n3(_1_REPXXX_0_9,Fnnnn,n1,n2) _1_REPXXX_0_N(n4,Fnnnn,n1,n2,n3)\
			)\
		)\
	)

#endif //_REPEAT1_H_
