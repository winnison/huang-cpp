#ifndef REPEAT_N

#define REPEAT_N( n , Fn) 										_0_REPEAT_N( n , Fn )
#define REPEAT_0_N( n , Fn ) 									Fn( 0 ) _0_REPEAT_N( n , Fn )
#define REPEATC_N( n , Fn1 , Fn ) 								_0_REPEATC_N( n , Fn1 , Fn )

#define REPEAT_NN( n1 , n2 , Fnn ) 								_0_REPEAT_NN( n1 , n2 , Fnn )
#define REPEAT_0_NN( n1 , n2 , Fnn ) 							Fnn( 0 , 0 ) _0_REPEAT_NN( n1 , n2 , Fnn )
#define REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) 						_0_REPEATC_NN( n1 , n2 , Fnn1 , Fnn )

#define REPEAT_NNN( n1 , n2 , n3 , Fnnn ) 						_0_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define REPEAT_0_NNN( n1 , n2 , n3 , Fnnn ) 					Fnnn( 0 , 0 , 0 ) _0_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn ) 				_0_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )

#define REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 				_0_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define REPEAT_0_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 				Fnnnn( 0 , 0 , 0 , 0 ) _0_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn ) 		_0_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )

#define _0_REPEAT_ZEROTEST0( a , b ) a
#define _0_REPEAT_ZEROTEST1( a , b ) b
#define _0_REPEAT_ZEROTEST2( a , b ) b
#define _0_REPEAT_ZEROTEST3( a , b ) b
#define _0_REPEAT_ZEROTEST4( a , b ) b
#define _0_REPEAT_ZEROTEST5( a , b ) b
#define _0_REPEAT_ZEROTEST6( a , b ) b
#define _0_REPEAT_ZEROTEST7( a , b ) b
#define _0_REPEAT_ZEROTEST8( a , b ) b
#define _0_REPEAT_ZEROTEST9( a , b ) b

#define _0_REPEAT0( Fn )
#define _0_REPEAT1( Fn ) Fn( 1 )
#define _0_REPEAT2( Fn ) _0_REPEAT1( Fn ) Fn( 2 )
#define _0_REPEAT3( Fn ) _0_REPEAT2( Fn ) Fn( 3 )
#define _0_REPEAT4( Fn ) _0_REPEAT3( Fn ) Fn( 4 )
#define _0_REPEAT5( Fn ) _0_REPEAT4( Fn ) Fn( 5 )
#define _0_REPEAT6( Fn ) _0_REPEAT5( Fn ) Fn( 6 )
#define _0_REPEAT7( Fn ) _0_REPEAT6( Fn ) Fn( 7 )
#define _0_REPEAT8( Fn ) _0_REPEAT7( Fn ) Fn( 8 )
#define _0_REPEAT9( Fn ) _0_REPEAT8( Fn ) Fn( 9 )

#define _0_REPEAT_N( n , Fn ) _0_REPEAT##n( Fn )

#define _0_REPEATC0( Fn1 , Fn )
#define _0_REPEATC1( Fn1 , Fn ) Fn1( 1 )
#define _0_REPEATC2( Fn1 , Fn ) _0_REPEATC1( Fn1 , Fn ) Fn( 2 )
#define _0_REPEATC3( Fn1 , Fn ) _0_REPEATC2( Fn1 , Fn ) Fn( 3 )
#define _0_REPEATC4( Fn1 , Fn ) _0_REPEATC3( Fn1 , Fn ) Fn( 4 )
#define _0_REPEATC5( Fn1 , Fn ) _0_REPEATC4( Fn1 , Fn ) Fn( 5 )
#define _0_REPEATC6( Fn1 , Fn ) _0_REPEATC5( Fn1 , Fn ) Fn( 6 )
#define _0_REPEATC7( Fn1 , Fn ) _0_REPEATC6( Fn1 , Fn ) Fn( 7 )
#define _0_REPEATC8( Fn1 , Fn ) _0_REPEATC7( Fn1 , Fn ) Fn( 8 )
#define _0_REPEATC9( Fn1 , Fn ) _0_REPEATC8( Fn1 , Fn ) Fn( 9 )

#define _0_REPEATC_N( n , Fn1 , Fn ) _0_REPEATC##n( Fn1 , Fn )

#define _0__REPEAT0( Fn )
#define _0__REPEAT1( Fn ) Fn( 1 )
#define _0__REPEAT2( Fn ) _0__REPEAT1( Fn ) Fn( 2 )
#define _0__REPEAT3( Fn ) _0__REPEAT2( Fn ) Fn( 3 )
#define _0__REPEAT4( Fn ) _0__REPEAT3( Fn ) Fn( 4 )
#define _0__REPEAT5( Fn ) _0__REPEAT4( Fn ) Fn( 5 )
#define _0__REPEAT6( Fn ) _0__REPEAT5( Fn ) Fn( 6 )
#define _0__REPEAT7( Fn ) _0__REPEAT6( Fn ) Fn( 7 )
#define _0__REPEAT8( Fn ) _0__REPEAT7( Fn ) Fn( 8 )
#define _0__REPEAT9( Fn ) _0__REPEAT8( Fn ) Fn( 9 )

#define _0__REPEAT_N( n , Fn ) _0__REPEAT##n( Fn )

#define _0_REPEATX0( Fxn , X )
#define _0_REPEATX1( Fxn , X )				Fxn( X , 1 )
#define _0_REPEATX2( Fxn , X ) _0_REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _0_REPEATX3( Fxn , X ) _0_REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _0_REPEATX4( Fxn , X ) _0_REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _0_REPEATX5( Fxn , X ) _0_REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _0_REPEATX6( Fxn , X ) _0_REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _0_REPEATX7( Fxn , X ) _0_REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _0_REPEATX8( Fxn , X ) _0_REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _0_REPEATX9( Fxn , X ) _0_REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _0_REPEATX_N( n , Fxn , X ) _0_REPEATX##n( Fxn , X )
#define _0_REPEATX_0_N( n , Fxn , X ) Fxn( X , 0 ) _0_REPEATX##n( Fxn , X )
#define _0_REPEATX_0_9( Fxn , X ) Fxn( X , 0 ) _0_REPEATX9( Fxn , X )

#define _0_REPEATXC0( Fxn1 , Fxn , X )
#define _0_REPEATXC1( Fxn1 , Fxn , X )				Fxn1( X , 1 )
#define _0_REPEATXC2( Fxn1 , Fxn , X ) _0_REPEATXC1( Fxn1 , Fxn , X ) Fxn( X , 2 )
#define _0_REPEATXC3( Fxn1 , Fxn , X ) _0_REPEATXC2( Fxn1 , Fxn , X ) Fxn( X , 3 )
#define _0_REPEATXC4( Fxn1 , Fxn , X ) _0_REPEATXC3( Fxn1 , Fxn , X ) Fxn( X , 4 )
#define _0_REPEATXC5( Fxn1 , Fxn , X ) _0_REPEATXC4( Fxn1 , Fxn , X ) Fxn( X , 5 )
#define _0_REPEATXC6( Fxn1 , Fxn , X ) _0_REPEATXC5( Fxn1 , Fxn , X ) Fxn( X , 6 )
#define _0_REPEATXC7( Fxn1 , Fxn , X ) _0_REPEATXC6( Fxn1 , Fxn , X ) Fxn( X , 7 )
#define _0_REPEATXC8( Fxn1 , Fxn , X ) _0_REPEATXC7( Fxn1 , Fxn , X ) Fxn( X , 8 )
#define _0_REPEATXC9( Fxn1 , Fxn , X ) _0_REPEATXC8( Fxn1 , Fxn , X ) Fxn( X , 9 )

#define _0_REPEATXC_N( n , Fxn1 , Fxn , X ) _0_REPEATXC##n( Fxn , X )

#define _0__REPEATX0( Fxn , X )
#define _0__REPEATX1( Fxn , X )				  Fxn( X , 1 )
#define _0__REPEATX2( Fxn , X ) _0__REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _0__REPEATX3( Fxn , X ) _0__REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _0__REPEATX4( Fxn , X ) _0__REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _0__REPEATX5( Fxn , X ) _0__REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _0__REPEATX6( Fxn , X ) _0__REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _0__REPEATX7( Fxn , X ) _0__REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _0__REPEATX8( Fxn , X ) _0__REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _0__REPEATX9( Fxn , X ) _0__REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _0_I_REPEATX0( Fxn , X ) 
#define _0_I_REPEATX1( Fxn , X ) _0__REPEATX0( Fxn , X )
#define _0_I_REPEATX2( Fxn , X ) _0__REPEATX1( Fxn , X )
#define _0_I_REPEATX3( Fxn , X ) _0__REPEATX2( Fxn , X )
#define _0_I_REPEATX4( Fxn , X ) _0__REPEATX3( Fxn , X )
#define _0_I_REPEATX5( Fxn , X ) _0__REPEATX4( Fxn , X )
#define _0_I_REPEATX6( Fxn , X ) _0__REPEATX5( Fxn , X )
#define _0_I_REPEATX7( Fxn , X ) _0__REPEATX6( Fxn , X )
#define _0_I_REPEATX8( Fxn , X ) _0__REPEATX7( Fxn , X )
#define _0_I_REPEATX9( Fxn , X ) _0__REPEATX8( Fxn , X )

#define _0_REPEAT_NN( n1 , n2 , Fnn ) \
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEATX_N( n2 , Fnn , 0 )\
		 , \
		_0_REPEATX_N( 9 , Fnn , 0 ) _0_I_REPEATX##n1( _0_REPEATX_0_9 , Fnn ) _0_REPEATX_0_N( n2 , Fnn , n1 )\
	 )
#define _0_REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) \
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEATXC_N( n2 , Fnn1 , Fnn , 0 )\
		 , \
		_0_REPEATXC_N( 9 , Fnn1 , Fnn , 0 ) _0_I_REPEATX##n1( _0_REPEATX_0_9 , Fnn ) _0_REPEATX_0_N( n2 , Fnn , n1 )\
	 )

#define _0_REPEATXX0( Fxxn , X1 , X2 )
#define _0_REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _0_REPEATXX2( Fxxn , X1 , X2 ) _0_REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _0_REPEATXX3( Fxxn , X1 , X2 ) _0_REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _0_REPEATXX4( Fxxn , X1 , X2 ) _0_REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _0_REPEATXX5( Fxxn , X1 , X2 ) _0_REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _0_REPEATXX6( Fxxn , X1 , X2 ) _0_REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _0_REPEATXX7( Fxxn , X1 , X2 ) _0_REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _0_REPEATXX8( Fxxn , X1 , X2 ) _0_REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _0_REPEATXX9( Fxxn , X1 , X2 ) _0_REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _0_REPEATXX_N( n , Fxxn , X1 , X2 ) _0_REPEATXX##n( Fxxn , X1 , X2 )
#define _0_REPEATXX_0_N( n , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _0_REPEATXX##n( Fxxn , X1 , X2 )
#define _0_REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _0_REPEATXX9( Fxxn , X1 , X2 )

#define _0_REPEATXXC0( Fxxn1 , Fxxn , X1 , X2 )
#define _0_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 )						Fxxn1( X1 , X2 , 1 )
#define _0_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _0_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _0_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _0_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _0_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _0_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _0_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _0_REPEATXXC9( Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _0_REPEATXXC_N( n , Fxxn1 , Fxxn , X1 , X2 ) _0_REPEATXXC##n( Fxxn1 , Fxxn , X1 , X2 )

#define _0__REPEATXX0( Fxxn , X1 , X2 )
#define _0__REPEATXX1( Fxxn , X1 , X2 )					  Fxxn( X1 , X2 , 1 )
#define _0__REPEATXX2( Fxxn , X1 , X2 ) _0__REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _0__REPEATXX3( Fxxn , X1 , X2 ) _0__REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _0__REPEATXX4( Fxxn , X1 , X2 ) _0__REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _0__REPEATXX5( Fxxn , X1 , X2 ) _0__REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _0__REPEATXX6( Fxxn , X1 , X2 ) _0__REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _0__REPEATXX7( Fxxn , X1 , X2 ) _0__REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _0__REPEATXX8( Fxxn , X1 , X2 ) _0__REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _0__REPEATXX9( Fxxn , X1 , X2 ) _0__REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _0__REPEATXX_N( n , Fxxn , X1 , X2 ) _0__REPEATXX##n( Fxxn , X1 , X2 )
#define _0__REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _0__REPEATXX9( Fxxn , X1 , X2 )

#define _0___REPEATXX0( Fxxn , X1 , X2 )
#define _0___REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _0___REPEATXX2( Fxxn , X1 , X2 ) _0___REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _0___REPEATXX3( Fxxn , X1 , X2 ) _0___REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _0___REPEATXX4( Fxxn , X1 , X2 ) _0___REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _0___REPEATXX5( Fxxn , X1 , X2 ) _0___REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _0___REPEATXX6( Fxxn , X1 , X2 ) _0___REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _0___REPEATXX7( Fxxn , X1 , X2 ) _0___REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _0___REPEATXX8( Fxxn , X1 , X2 ) _0___REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _0___REPEATXX9( Fxxn , X1 , X2 ) _0___REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _0_I_REPEATXX0( Fxxn , X1 , X2 ) 
#define _0_I_REPEATXX1( Fxxn , X1 , X2 ) _0___REPEATXX0( Fxxn , X1 , X2 )
#define _0_I_REPEATXX2( Fxxn , X1 , X2 ) _0___REPEATXX1( Fxxn , X1 , X2 )
#define _0_I_REPEATXX3( Fxxn , X1 , X2 ) _0___REPEATXX2( Fxxn , X1 , X2 )
#define _0_I_REPEATXX4( Fxxn , X1 , X2 ) _0___REPEATXX3( Fxxn , X1 , X2 )
#define _0_I_REPEATXX5( Fxxn , X1 , X2 ) _0___REPEATXX4( Fxxn , X1 , X2 )
#define _0_I_REPEATXX6( Fxxn , X1 , X2 ) _0___REPEATXX5( Fxxn , X1 , X2 )
#define _0_I_REPEATXX7( Fxxn , X1 , X2 ) _0___REPEATXX6( Fxxn , X1 , X2 )
#define _0_I_REPEATXX8( Fxxn , X1 , X2 ) _0___REPEATXX7( Fxxn , X1 , X2 )
#define _0_I_REPEATXX9( Fxxn , X1 , X2 ) _0___REPEATXX8( Fxxn , X1 , X2 )

#define _0_REPEAT_NNN( n1 , n2 , n3 , Fnnn )\
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEATXX_N( n3 , Fnnn , 0 , 0 )\
			 , \
			_0_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _0_I_REPEATXX##n2( _0_REPEATXX_0_9 , Fnnn , 0 ) _0_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_0_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _0__REPEATXX9( _0_REPEATXX_0_9 , Fnnn , 0 ) _0_I_REPEATXX##n1( _0__REPEATXX_0_9 , _0_REPEATXX_0_9 , Fnnn ) \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_0_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _0_I_REPEATXX##n2( _0_REPEATXX_0_9 , Fnnn , n1 ) _0_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )
#define _0_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )\
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEATXXC_N( n3 , Fnnn1 , Fnnn , 0 , 0 )\
			 , \
			_0_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _0_I_REPEATXX##n2( _0_REPEATXX_0_9 , Fnnn , 0 ) _0_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_0_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _0__REPEATXX9( _0_REPEATXX_0_9 , Fnnn , 0 ) _0_I_REPEATXX##n1( _0__REPEATXX_0_9 , _0_REPEATXX_0_9 , Fnnn ) \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_0_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _0_I_REPEATXX##n2( _0_REPEATXX_0_9 , Fnnn , n1 ) _0_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )

#define _0_REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _0_REPEATXXX1( Fxxxn , X1 , X2 , X3 )						  Fxxxn( X1 , X2 , X3 , 1 )
#define _0_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _0_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _0_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _0_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _0_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _0_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _0_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _0_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _0_REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _0_REPEATXXX_0_N( n , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _0_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _0_REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _0_REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _0_REPEATXXXC0( Fxxxn1 , Fxxxn , X1 , X2 , X3 )
#define _0_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 )						  Fxxxn1( X1 , X2 , X3 , 1 )
#define _0_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _0_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _0_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _0_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _0_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _0_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _0_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _0_REPEATXXXC9( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _0_REPEATXXXC_N( n , Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _0_REPEATXXXC##n(Fxxxn1, Fxxxn , X1 , X2 , X3 )

#define _0__REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _0__REPEATXXX1( Fxxxn , X1 , X2 , X3 )							Fxxxn( X1 , X2 , X3 , 1 )
#define _0__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _0__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _0__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _0__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _0__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _0__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _0__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _0__REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _0__REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _0__REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _0__REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _0__REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _0___REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _0___REPEATXXX1( Fxxxn , X1 , X2 , X3 )							  Fxxxn( X1 , X2 , X3 , 1 )
#define _0___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _0___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _0___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _0___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _0___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _0___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _0___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _0___REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _0___REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _0___REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _0___REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _0___REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _0____REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _0____REPEATXXX1( Fxxxn , X1 , X2 , X3 )								Fxxxn( X1 , X2 , X3 , 1 )
#define _0____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _0____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _0____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _0____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _0____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _0____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _0____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _0____REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _0_I_REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _0_I_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX1( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX2( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX3( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX4( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX5( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX6( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX7( Fxxxn , X1 , X2 , X3 )
#define _0_I_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _0____REPEATXXX8( Fxxxn , X1 , X2 , X3 )

#define _0_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )\
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_N( n4 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_0_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_0_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0_I_REPEATXXX##n2( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , 0 )\
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _0_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_0_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0___REPEATXXX9( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , 0 ) _0_I_REPEATXXX##n1( _0___REPEATXXX_0_9 , _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn )\
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _0_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _0_I_REPEATXXX##n2( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , n1 )\
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _0_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )
#define _0_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )\
	_0_REPEAT_ZEROTEST##n1( \
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXXC_N( n4 , Fnnnn1 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_0_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_0_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0_I_REPEATXXX##n2( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , 0 )\
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _0_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_0_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _0___REPEATXXX9( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , 0 ) _0_I_REPEATXXX##n1( _0___REPEATXXX_0_9 , _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn )\
		_0_REPEAT_ZEROTEST##n2( \
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _0_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _0__REPEATXXX9( _0_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _0_I_REPEATXXX##n2( _0__REPEATXXX_0_9 , _0_REPEATXXX_0_9 , Fnnnn , n1 )\
			_0_REPEAT_ZEROTEST##n3( \
				_0_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_0_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _0_I_REPEATXXX##n3( _0_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _0_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )

#endif
