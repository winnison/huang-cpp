#ifndef _REPEAT1_H_
#define _REPEAT1_H_

#define _REPEAT_N( n , Fn) 										_1_REPEAT_N( n , Fn )
#define _REPEAT_0_N( n , Fn ) 									Fn( 0 ) _1_REPEAT_N( n , Fn )
#define _REPEATC_N( n , Fn1 , Fn ) 								_1_REPEATC_N( n , Fn1 , Fn )

#define _REPEAT_NN( n1 , n2 , Fnn ) 							_1_REPEAT_NN( n1 , n2 , Fnn )
#define _REPEAT_0_NN( n1 , n2 , Fnn ) 							Fnn( 0 , 0 ) _1_REPEAT_NN( n1 , n2 , Fnn )
#define _REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) 					_1_REPEATC_NN( n1 , n2 , Fnn1 , Fnn )

#define _REPEAT_NNN( n1 , n2 , n3 , Fnnn ) 						_1_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define _REPEAT_0_NNN( n1 , n2 , n3 , Fnnn ) 					Fnnn( 0 , 0 , 0 ) _1_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define _REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn ) 			_1_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )

#define _REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 				_1_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define _REPEAT_0_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 			Fnnnn( 0 , 0 , 0 , 0 ) _1_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define _REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn ) 	_1_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )

#define _1_REPEAT_ZEROTEST0( a , b ) a
#define _1_REPEAT_ZEROTEST1( a , b ) b
#define _1_REPEAT_ZEROTEST2( a , b ) b
#define _1_REPEAT_ZEROTEST3( a , b ) b
#define _1_REPEAT_ZEROTEST4( a , b ) b
#define _1_REPEAT_ZEROTEST5( a , b ) b
#define _1_REPEAT_ZEROTEST6( a , b ) b
#define _1_REPEAT_ZEROTEST7( a , b ) b
#define _1_REPEAT_ZEROTEST8( a , b ) b
#define _1_REPEAT_ZEROTEST9( a , b ) b

#define _1_REPEAT0( Fn )
#define _1_REPEAT1( Fn ) Fn( 1 )
#define _1_REPEAT2( Fn ) _1_REPEAT1( Fn ) Fn( 2 )
#define _1_REPEAT3( Fn ) _1_REPEAT2( Fn ) Fn( 3 )
#define _1_REPEAT4( Fn ) _1_REPEAT3( Fn ) Fn( 4 )
#define _1_REPEAT5( Fn ) _1_REPEAT4( Fn ) Fn( 5 )
#define _1_REPEAT6( Fn ) _1_REPEAT5( Fn ) Fn( 6 )
#define _1_REPEAT7( Fn ) _1_REPEAT6( Fn ) Fn( 7 )
#define _1_REPEAT8( Fn ) _1_REPEAT7( Fn ) Fn( 8 )
#define _1_REPEAT9( Fn ) _1_REPEAT8( Fn ) Fn( 9 )

#define _1_REPEAT_N( n , Fn ) _1_REPEAT##n( Fn )

#define _1_REPEATC0( Fn1 , Fn )
#define _1_REPEATC1( Fn1 , Fn ) Fn1( 1 )
#define _1_REPEATC2( Fn1 , Fn ) _1_REPEATC1( Fn1 , Fn ) Fn( 2 )
#define _1_REPEATC3( Fn1 , Fn ) _1_REPEATC2( Fn1 , Fn ) Fn( 3 )
#define _1_REPEATC4( Fn1 , Fn ) _1_REPEATC3( Fn1 , Fn ) Fn( 4 )
#define _1_REPEATC5( Fn1 , Fn ) _1_REPEATC4( Fn1 , Fn ) Fn( 5 )
#define _1_REPEATC6( Fn1 , Fn ) _1_REPEATC5( Fn1 , Fn ) Fn( 6 )
#define _1_REPEATC7( Fn1 , Fn ) _1_REPEATC6( Fn1 , Fn ) Fn( 7 )
#define _1_REPEATC8( Fn1 , Fn ) _1_REPEATC7( Fn1 , Fn ) Fn( 8 )
#define _1_REPEATC9( Fn1 , Fn ) _1_REPEATC8( Fn1 , Fn ) Fn( 9 )

#define _1_REPEATC_N( n , Fn1 , Fn ) _1_REPEATC##n( Fn1 , Fn )

#define _1__REPEAT0( Fn )
#define _1__REPEAT1( Fn ) Fn( 1 )
#define _1__REPEAT2( Fn ) _1__REPEAT1( Fn ) Fn( 2 )
#define _1__REPEAT3( Fn ) _1__REPEAT2( Fn ) Fn( 3 )
#define _1__REPEAT4( Fn ) _1__REPEAT3( Fn ) Fn( 4 )
#define _1__REPEAT5( Fn ) _1__REPEAT4( Fn ) Fn( 5 )
#define _1__REPEAT6( Fn ) _1__REPEAT5( Fn ) Fn( 6 )
#define _1__REPEAT7( Fn ) _1__REPEAT6( Fn ) Fn( 7 )
#define _1__REPEAT8( Fn ) _1__REPEAT7( Fn ) Fn( 8 )
#define _1__REPEAT9( Fn ) _1__REPEAT8( Fn ) Fn( 9 )

#define _1__REPEAT_N( n , Fn ) _1__REPEAT##n( Fn )

#define _1_REPEATX0( Fxn , X )
#define _1_REPEATX1( Fxn , X )				Fxn( X , 1 )
#define _1_REPEATX2( Fxn , X ) _1_REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _1_REPEATX3( Fxn , X ) _1_REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _1_REPEATX4( Fxn , X ) _1_REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _1_REPEATX5( Fxn , X ) _1_REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _1_REPEATX6( Fxn , X ) _1_REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _1_REPEATX7( Fxn , X ) _1_REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _1_REPEATX8( Fxn , X ) _1_REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _1_REPEATX9( Fxn , X ) _1_REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _1_REPEATX_N( n , Fxn , X ) _1_REPEATX##n( Fxn , X )
#define _1_REPEATX_0_N( n , Fxn , X ) Fxn( X , 0 ) _1_REPEATX##n( Fxn , X )
#define _1_REPEATX_0_9( Fxn , X ) Fxn( X , 0 ) _1_REPEATX9( Fxn , X )

#define _1_REPEATXC0( Fxn1 , Fxn , X )
#define _1_REPEATXC1( Fxn1 , Fxn , X )				Fxn1( X , 1 )
#define _1_REPEATXC2( Fxn1 , Fxn , X ) _1_REPEATXC1( Fxn1 , Fxn , X ) Fxn( X , 2 )
#define _1_REPEATXC3( Fxn1 , Fxn , X ) _1_REPEATXC2( Fxn1 , Fxn , X ) Fxn( X , 3 )
#define _1_REPEATXC4( Fxn1 , Fxn , X ) _1_REPEATXC3( Fxn1 , Fxn , X ) Fxn( X , 4 )
#define _1_REPEATXC5( Fxn1 , Fxn , X ) _1_REPEATXC4( Fxn1 , Fxn , X ) Fxn( X , 5 )
#define _1_REPEATXC6( Fxn1 , Fxn , X ) _1_REPEATXC5( Fxn1 , Fxn , X ) Fxn( X , 6 )
#define _1_REPEATXC7( Fxn1 , Fxn , X ) _1_REPEATXC6( Fxn1 , Fxn , X ) Fxn( X , 7 )
#define _1_REPEATXC8( Fxn1 , Fxn , X ) _1_REPEATXC7( Fxn1 , Fxn , X ) Fxn( X , 8 )
#define _1_REPEATXC9( Fxn1 , Fxn , X ) _1_REPEATXC8( Fxn1 , Fxn , X ) Fxn( X , 9 )

#define _1_REPEATXC_N( n , Fxn1 , Fxn , X ) _1_REPEATXC##n( Fxn , X )

#define _1__REPEATX0( Fxn , X )
#define _1__REPEATX1( Fxn , X )				  Fxn( X , 1 )
#define _1__REPEATX2( Fxn , X ) _1__REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _1__REPEATX3( Fxn , X ) _1__REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _1__REPEATX4( Fxn , X ) _1__REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _1__REPEATX5( Fxn , X ) _1__REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _1__REPEATX6( Fxn , X ) _1__REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _1__REPEATX7( Fxn , X ) _1__REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _1__REPEATX8( Fxn , X ) _1__REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _1__REPEATX9( Fxn , X ) _1__REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _1_I_REPEATX0( Fxn , X ) 
#define _1_I_REPEATX1( Fxn , X ) _1__REPEATX0( Fxn , X )
#define _1_I_REPEATX2( Fxn , X ) _1__REPEATX1( Fxn , X )
#define _1_I_REPEATX3( Fxn , X ) _1__REPEATX2( Fxn , X )
#define _1_I_REPEATX4( Fxn , X ) _1__REPEATX3( Fxn , X )
#define _1_I_REPEATX5( Fxn , X ) _1__REPEATX4( Fxn , X )
#define _1_I_REPEATX6( Fxn , X ) _1__REPEATX5( Fxn , X )
#define _1_I_REPEATX7( Fxn , X ) _1__REPEATX6( Fxn , X )
#define _1_I_REPEATX8( Fxn , X ) _1__REPEATX7( Fxn , X )
#define _1_I_REPEATX9( Fxn , X ) _1__REPEATX8( Fxn , X )

#define _1_REPEAT_NN( n1 , n2 , Fnn ) \
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEATX_N( n2 , Fnn , 0 )\
		 , \
		_1_REPEATX_N( 9 , Fnn , 0 ) _1_I_REPEATX##n1( _1_REPEATX_0_9 , Fnn ) _1_REPEATX_0_N( n2 , Fnn , n1 )\
	 )
#define _1_REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) \
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEATXC_N( n2 , Fnn1 , Fnn , 0 )\
		 , \
		_1_REPEATXC_N( 9 , Fnn1 , Fnn , 0 ) _1_I_REPEATX##n1( _1_REPEATX_0_9 , Fnn ) _1_REPEATX_0_N( n2 , Fnn , n1 )\
	 )

#define _1_REPEATXX0( Fxxn , X1 , X2 )
#define _1_REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _1_REPEATXX2( Fxxn , X1 , X2 ) _1_REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _1_REPEATXX3( Fxxn , X1 , X2 ) _1_REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _1_REPEATXX4( Fxxn , X1 , X2 ) _1_REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _1_REPEATXX5( Fxxn , X1 , X2 ) _1_REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _1_REPEATXX6( Fxxn , X1 , X2 ) _1_REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _1_REPEATXX7( Fxxn , X1 , X2 ) _1_REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _1_REPEATXX8( Fxxn , X1 , X2 ) _1_REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _1_REPEATXX9( Fxxn , X1 , X2 ) _1_REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _1_REPEATXX_N( n , Fxxn , X1 , X2 ) _1_REPEATXX##n( Fxxn , X1 , X2 )
#define _1_REPEATXX_0_N( n , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _1_REPEATXX##n( Fxxn , X1 , X2 )
#define _1_REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _1_REPEATXX9( Fxxn , X1 , X2 )

#define _1_REPEATXXC0( Fxxn1 , Fxxn , X1 , X2 )
#define _1_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 )						Fxxn1( X1 , X2 , 1 )
#define _1_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _1_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _1_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _1_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _1_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _1_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _1_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _1_REPEATXXC9( Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _1_REPEATXXC_N( n , Fxxn1 , Fxxn , X1 , X2 ) _1_REPEATXXC##n( Fxxn1 , Fxxn , X1 , X2 )

#define _1__REPEATXX0( Fxxn , X1 , X2 )
#define _1__REPEATXX1( Fxxn , X1 , X2 )					  Fxxn( X1 , X2 , 1 )
#define _1__REPEATXX2( Fxxn , X1 , X2 ) _1__REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _1__REPEATXX3( Fxxn , X1 , X2 ) _1__REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _1__REPEATXX4( Fxxn , X1 , X2 ) _1__REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _1__REPEATXX5( Fxxn , X1 , X2 ) _1__REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _1__REPEATXX6( Fxxn , X1 , X2 ) _1__REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _1__REPEATXX7( Fxxn , X1 , X2 ) _1__REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _1__REPEATXX8( Fxxn , X1 , X2 ) _1__REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _1__REPEATXX9( Fxxn , X1 , X2 ) _1__REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _1__REPEATXX_N( n , Fxxn , X1 , X2 ) _1__REPEATXX##n( Fxxn , X1 , X2 )
#define _1__REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _1__REPEATXX9( Fxxn , X1 , X2 )

#define _1___REPEATXX0( Fxxn , X1 , X2 )
#define _1___REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _1___REPEATXX2( Fxxn , X1 , X2 ) _1___REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _1___REPEATXX3( Fxxn , X1 , X2 ) _1___REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _1___REPEATXX4( Fxxn , X1 , X2 ) _1___REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _1___REPEATXX5( Fxxn , X1 , X2 ) _1___REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _1___REPEATXX6( Fxxn , X1 , X2 ) _1___REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _1___REPEATXX7( Fxxn , X1 , X2 ) _1___REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _1___REPEATXX8( Fxxn , X1 , X2 ) _1___REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _1___REPEATXX9( Fxxn , X1 , X2 ) _1___REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _1_I_REPEATXX0( Fxxn , X1 , X2 ) 
#define _1_I_REPEATXX1( Fxxn , X1 , X2 ) _1___REPEATXX0( Fxxn , X1 , X2 )
#define _1_I_REPEATXX2( Fxxn , X1 , X2 ) _1___REPEATXX1( Fxxn , X1 , X2 )
#define _1_I_REPEATXX3( Fxxn , X1 , X2 ) _1___REPEATXX2( Fxxn , X1 , X2 )
#define _1_I_REPEATXX4( Fxxn , X1 , X2 ) _1___REPEATXX3( Fxxn , X1 , X2 )
#define _1_I_REPEATXX5( Fxxn , X1 , X2 ) _1___REPEATXX4( Fxxn , X1 , X2 )
#define _1_I_REPEATXX6( Fxxn , X1 , X2 ) _1___REPEATXX5( Fxxn , X1 , X2 )
#define _1_I_REPEATXX7( Fxxn , X1 , X2 ) _1___REPEATXX6( Fxxn , X1 , X2 )
#define _1_I_REPEATXX8( Fxxn , X1 , X2 ) _1___REPEATXX7( Fxxn , X1 , X2 )
#define _1_I_REPEATXX9( Fxxn , X1 , X2 ) _1___REPEATXX8( Fxxn , X1 , X2 )

#define _1_REPEAT_NNN( n1 , n2 , n3 , Fnnn )\
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEATXX_N( n3 , Fnnn , 0 , 0 )\
			 , \
			_1_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _1_I_REPEATXX##n2( _1_REPEATXX_0_9 , Fnnn , 0 ) _1_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_1_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _1__REPEATXX9( _1_REPEATXX_0_9 , Fnnn , 0 ) _1_I_REPEATXX##n1( _1__REPEATXX_0_9 , _1_REPEATXX_0_9 , Fnnn ) \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_1_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _1_I_REPEATXX##n2( _1_REPEATXX_0_9 , Fnnn , n1 ) _1_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )
#define _1_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )\
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEATXXC_N( n3 , Fnnn1 , Fnnn , 0 , 0 )\
			 , \
			_1_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _1_I_REPEATXX##n2( _1_REPEATXX_0_9 , Fnnn , 0 ) _1_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_1_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _1__REPEATXX9( _1_REPEATXX_0_9 , Fnnn , 0 ) _1_I_REPEATXX##n1( _1__REPEATXX_0_9 , _1_REPEATXX_0_9 , Fnnn ) \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_1_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _1_I_REPEATXX##n2( _1_REPEATXX_0_9 , Fnnn , n1 ) _1_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )

#define _1_REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _1_REPEATXXX1( Fxxxn , X1 , X2 , X3 )						  Fxxxn( X1 , X2 , X3 , 1 )
#define _1_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _1_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _1_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _1_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _1_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _1_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _1_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _1_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _1_REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _1_REPEATXXX_0_N( n , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _1_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _1_REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _1_REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _1_REPEATXXXC0( Fxxxn1 , Fxxxn , X1 , X2 , X3 )
#define _1_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 )						  Fxxxn1( X1 , X2 , X3 , 1 )
#define _1_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _1_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _1_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _1_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _1_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _1_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _1_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _1_REPEATXXXC9( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _1_REPEATXXXC_N( n , Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _1_REPEATXXXC##n( Fxxxn , X1 , X2 , X3 )

#define _1__REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _1__REPEATXXX1( Fxxxn , X1 , X2 , X3 )							Fxxxn( X1 , X2 , X3 , 1 )
#define _1__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _1__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _1__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _1__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _1__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _1__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _1__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _1__REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _1__REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _1__REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _1__REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _1__REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _1___REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _1___REPEATXXX1( Fxxxn , X1 , X2 , X3 )							  Fxxxn( X1 , X2 , X3 , 1 )
#define _1___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _1___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _1___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _1___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _1___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _1___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _1___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _1___REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _1___REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _1___REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _1___REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _1___REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _1____REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _1____REPEATXXX1( Fxxxn , X1 , X2 , X3 )								Fxxxn( X1 , X2 , X3 , 1 )
#define _1____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _1____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _1____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _1____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _1____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _1____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _1____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _1____REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _1_I_REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _1_I_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX1( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX2( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX3( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX4( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX5( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX6( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX7( Fxxxn , X1 , X2 , X3 )
#define _1_I_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _1____REPEATXXX8( Fxxxn , X1 , X2 , X3 )

#define _1_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )\
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_N( n4 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_1_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_1_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1_I_REPEATXXX##n2( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , 0 )\
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _1_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_1_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1___REPEATXXX9( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , 0 ) _1_I_REPEATXXX##n1( _1___REPEATXXX_0_9 , _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn )\
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _1_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , n1 , 0 , 0 ) _1_I_REPEATXXX##n2( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , n1 )\
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _1_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )
#define _1_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )\
	_1_REPEAT_ZEROTEST##n1( \
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXXC_N( n4 , Fnnnn1 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_1_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_1_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1_I_REPEATXXX##n2( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , 0 )\
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _1_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_1_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _1___REPEATXXX9( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , 0 ) _1_I_REPEATXXX##n1( _1___REPEATXXX_0_9 , _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn )\
		_1_REPEAT_ZEROTEST##n2( \
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _1_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _1__REPEATXXX9( _1_REPEATXXX_0_9 , Fnnnn , n1 , 0 , 0 ) _1_I_REPEATXXX##n2( _1__REPEATXXX_0_9 , _1_REPEATXXX_0_9 , Fnnnn , n1 )\
			_1_REPEAT_ZEROTEST##n3( \
				_1_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_1_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _1_I_REPEATXXX##n3( _1_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _1_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )

#endif
