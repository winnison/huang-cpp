#ifndef _REPEAT2_H_
#define _REPEAT2_H_

#define __REPEAT_N( n , Fn) 									_2_REPEAT_N( n , Fn )
#define __REPEAT_0_N( n , Fn ) 									Fn( 0 ) _2_REPEAT_N( n , Fn )
#define __REPEATC_N( n , Fn1 , Fn ) 							_2_REPEATC_N( n , Fn1 , Fn )

#define __REPEAT_NN( n1 , n2 , Fnn ) 							_2_REPEAT_NN( n1 , n2 , Fnn )
#define __REPEAT_0_NN( n1 , n2 , Fnn ) 							Fnn( 0 , 0 ) _2_REPEAT_NN( n1 , n2 , Fnn )
#define __REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) 					_2_REPEATC_NN( n1 , n2 , Fnn1 , Fnn )

#define __REPEAT_NNN( n1 , n2 , n3 , Fnnn ) 					_2_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define __REPEAT_0_NNN( n1 , n2 , n3 , Fnnn ) 					Fnnn( 0 , 0 , 0 ) _2_REPEAT_NNN( n1 , n2 , n3 , Fnnn )
#define __REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn ) 			_2_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )

#define __REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 				_2_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define __REPEAT_0_NNNN( n1 , n2 , n3 , n4 , Fnnnn ) 			Fnnnn( 0 , 0 , 0 , 0 ) _2_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )
#define __REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn ) 	_2_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )

#define _2_REPEAT_ZEROTEST0( a , b ) a
#define _2_REPEAT_ZEROTEST1( a , b ) b
#define _2_REPEAT_ZEROTEST2( a , b ) b
#define _2_REPEAT_ZEROTEST3( a , b ) b
#define _2_REPEAT_ZEROTEST4( a , b ) b
#define _2_REPEAT_ZEROTEST5( a , b ) b
#define _2_REPEAT_ZEROTEST6( a , b ) b
#define _2_REPEAT_ZEROTEST7( a , b ) b
#define _2_REPEAT_ZEROTEST8( a , b ) b
#define _2_REPEAT_ZEROTEST9( a , b ) b

#define _2_REPEAT0( Fn )
#define _2_REPEAT1( Fn ) Fn( 1 )
#define _2_REPEAT2( Fn ) _2_REPEAT1( Fn ) Fn( 2 )
#define _2_REPEAT3( Fn ) _2_REPEAT2( Fn ) Fn( 3 )
#define _2_REPEAT4( Fn ) _2_REPEAT3( Fn ) Fn( 4 )
#define _2_REPEAT5( Fn ) _2_REPEAT4( Fn ) Fn( 5 )
#define _2_REPEAT6( Fn ) _2_REPEAT5( Fn ) Fn( 6 )
#define _2_REPEAT7( Fn ) _2_REPEAT6( Fn ) Fn( 7 )
#define _2_REPEAT8( Fn ) _2_REPEAT7( Fn ) Fn( 8 )
#define _2_REPEAT9( Fn ) _2_REPEAT8( Fn ) Fn( 9 )

#define _2_REPEAT_N( n , Fn ) _2_REPEAT##n( Fn )

#define _2_REPEATC0( Fn1 , Fn )
#define _2_REPEATC1( Fn1 , Fn ) Fn1( 1 )
#define _2_REPEATC2( Fn1 , Fn ) _2_REPEATC1( Fn1 , Fn ) Fn( 2 )
#define _2_REPEATC3( Fn1 , Fn ) _2_REPEATC2( Fn1 , Fn ) Fn( 3 )
#define _2_REPEATC4( Fn1 , Fn ) _2_REPEATC3( Fn1 , Fn ) Fn( 4 )
#define _2_REPEATC5( Fn1 , Fn ) _2_REPEATC4( Fn1 , Fn ) Fn( 5 )
#define _2_REPEATC6( Fn1 , Fn ) _2_REPEATC5( Fn1 , Fn ) Fn( 6 )
#define _2_REPEATC7( Fn1 , Fn ) _2_REPEATC6( Fn1 , Fn ) Fn( 7 )
#define _2_REPEATC8( Fn1 , Fn ) _2_REPEATC7( Fn1 , Fn ) Fn( 8 )
#define _2_REPEATC9( Fn1 , Fn ) _2_REPEATC8( Fn1 , Fn ) Fn( 9 )

#define _2_REPEATC_N( n , Fn1 , Fn ) _2_REPEATC##n( Fn1 , Fn )

#define _2__REPEAT0( Fn )
#define _2__REPEAT1( Fn ) Fn( 1 )
#define _2__REPEAT2( Fn ) _2__REPEAT1( Fn ) Fn( 2 )
#define _2__REPEAT3( Fn ) _2__REPEAT2( Fn ) Fn( 3 )
#define _2__REPEAT4( Fn ) _2__REPEAT3( Fn ) Fn( 4 )
#define _2__REPEAT5( Fn ) _2__REPEAT4( Fn ) Fn( 5 )
#define _2__REPEAT6( Fn ) _2__REPEAT5( Fn ) Fn( 6 )
#define _2__REPEAT7( Fn ) _2__REPEAT6( Fn ) Fn( 7 )
#define _2__REPEAT8( Fn ) _2__REPEAT7( Fn ) Fn( 8 )
#define _2__REPEAT9( Fn ) _2__REPEAT8( Fn ) Fn( 9 )

#define _2__REPEAT_N( n , Fn ) _2__REPEAT##n( Fn )

#define _2_REPEATX0( Fxn , X )
#define _2_REPEATX1( Fxn , X )				Fxn( X , 1 )
#define _2_REPEATX2( Fxn , X ) _2_REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _2_REPEATX3( Fxn , X ) _2_REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _2_REPEATX4( Fxn , X ) _2_REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _2_REPEATX5( Fxn , X ) _2_REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _2_REPEATX6( Fxn , X ) _2_REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _2_REPEATX7( Fxn , X ) _2_REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _2_REPEATX8( Fxn , X ) _2_REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _2_REPEATX9( Fxn , X ) _2_REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _2_REPEATX_N( n , Fxn , X ) _2_REPEATX##n( Fxn , X )
#define _2_REPEATX_0_N( n , Fxn , X ) Fxn( X , 0 ) _2_REPEATX##n( Fxn , X )
#define _2_REPEATX_0_9( Fxn , X ) Fxn( X , 0 ) _2_REPEATX9( Fxn , X )

#define _2_REPEATXC0( Fxn1 , Fxn , X )
#define _2_REPEATXC1( Fxn1 , Fxn , X )				Fxn1( X , 1 )
#define _2_REPEATXC2( Fxn1 , Fxn , X ) _2_REPEATXC1( Fxn1 , Fxn , X ) Fxn( X , 2 )
#define _2_REPEATXC3( Fxn1 , Fxn , X ) _2_REPEATXC2( Fxn1 , Fxn , X ) Fxn( X , 3 )
#define _2_REPEATXC4( Fxn1 , Fxn , X ) _2_REPEATXC3( Fxn1 , Fxn , X ) Fxn( X , 4 )
#define _2_REPEATXC5( Fxn1 , Fxn , X ) _2_REPEATXC4( Fxn1 , Fxn , X ) Fxn( X , 5 )
#define _2_REPEATXC6( Fxn1 , Fxn , X ) _2_REPEATXC5( Fxn1 , Fxn , X ) Fxn( X , 6 )
#define _2_REPEATXC7( Fxn1 , Fxn , X ) _2_REPEATXC6( Fxn1 , Fxn , X ) Fxn( X , 7 )
#define _2_REPEATXC8( Fxn1 , Fxn , X ) _2_REPEATXC7( Fxn1 , Fxn , X ) Fxn( X , 8 )
#define _2_REPEATXC9( Fxn1 , Fxn , X ) _2_REPEATXC8( Fxn1 , Fxn , X ) Fxn( X , 9 )

#define _2_REPEATXC_N( n , Fxn1 , Fxn , X ) _2_REPEATXC##n( Fxn , X )

#define _2__REPEATX0( Fxn , X )
#define _2__REPEATX1( Fxn , X )				  Fxn( X , 1 )
#define _2__REPEATX2( Fxn , X ) _2__REPEATX1( Fxn , X ) Fxn( X , 2 )
#define _2__REPEATX3( Fxn , X ) _2__REPEATX2( Fxn , X ) Fxn( X , 3 )
#define _2__REPEATX4( Fxn , X ) _2__REPEATX3( Fxn , X ) Fxn( X , 4 )
#define _2__REPEATX5( Fxn , X ) _2__REPEATX4( Fxn , X ) Fxn( X , 5 )
#define _2__REPEATX6( Fxn , X ) _2__REPEATX5( Fxn , X ) Fxn( X , 6 )
#define _2__REPEATX7( Fxn , X ) _2__REPEATX6( Fxn , X ) Fxn( X , 7 )
#define _2__REPEATX8( Fxn , X ) _2__REPEATX7( Fxn , X ) Fxn( X , 8 )
#define _2__REPEATX9( Fxn , X ) _2__REPEATX8( Fxn , X ) Fxn( X , 9 )

#define _2_I_REPEATX0( Fxn , X ) 
#define _2_I_REPEATX1( Fxn , X ) _2__REPEATX0( Fxn , X )
#define _2_I_REPEATX2( Fxn , X ) _2__REPEATX1( Fxn , X )
#define _2_I_REPEATX3( Fxn , X ) _2__REPEATX2( Fxn , X )
#define _2_I_REPEATX4( Fxn , X ) _2__REPEATX3( Fxn , X )
#define _2_I_REPEATX5( Fxn , X ) _2__REPEATX4( Fxn , X )
#define _2_I_REPEATX6( Fxn , X ) _2__REPEATX5( Fxn , X )
#define _2_I_REPEATX7( Fxn , X ) _2__REPEATX6( Fxn , X )
#define _2_I_REPEATX8( Fxn , X ) _2__REPEATX7( Fxn , X )
#define _2_I_REPEATX9( Fxn , X ) _2__REPEATX8( Fxn , X )

#define _2_REPEAT_NN( n1 , n2 , Fnn ) \
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEATX_N( n2 , Fnn , 0 )\
		 , \
		_2_REPEATX_N( 9 , Fnn , 0 ) _2_I_REPEATX##n1( _2_REPEATX_0_9 , Fnn ) _2_REPEATX_0_N( n2 , Fnn , n1 )\
	 )
#define _2_REPEATC_NN( n1 , n2 , Fnn1 , Fnn ) \
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEATXC_N( n2 , Fnn1 , Fnn , 0 )\
		 , \
		_2_REPEATXC_N( 9 , Fnn1 , Fnn , 0 ) _2_I_REPEATX##n1( _2_REPEATX_0_9 , Fnn ) _2_REPEATX_0_N( n2 , Fnn , n1 )\
	 )

#define _2_REPEATXX0( Fxxn , X1 , X2 )
#define _2_REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _2_REPEATXX2( Fxxn , X1 , X2 ) _2_REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _2_REPEATXX3( Fxxn , X1 , X2 ) _2_REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _2_REPEATXX4( Fxxn , X1 , X2 ) _2_REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _2_REPEATXX5( Fxxn , X1 , X2 ) _2_REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _2_REPEATXX6( Fxxn , X1 , X2 ) _2_REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _2_REPEATXX7( Fxxn , X1 , X2 ) _2_REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _2_REPEATXX8( Fxxn , X1 , X2 ) _2_REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _2_REPEATXX9( Fxxn , X1 , X2 ) _2_REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _2_REPEATXX_N( n , Fxxn , X1 , X2 ) _2_REPEATXX##n( Fxxn , X1 , X2 )
#define _2_REPEATXX_0_N( n , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _2_REPEATXX##n( Fxxn , X1 , X2 )
#define _2_REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _2_REPEATXX9( Fxxn , X1 , X2 )

#define _2_REPEATXXC0( Fxxn1 , Fxxn , X1 , X2 )
#define _2_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 )						Fxxn1( X1 , X2 , 1 )
#define _2_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC1( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _2_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC2( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _2_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC3( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _2_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC4( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _2_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC5( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _2_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC6( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _2_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC7( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _2_REPEATXXC9( Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC8( Fxxn1 , Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _2_REPEATXXC_N( n , Fxxn1 , Fxxn , X1 , X2 ) _2_REPEATXXC##n( Fxxn1 , Fxxn , X1 , X2 )

#define _2__REPEATXX0( Fxxn , X1 , X2 )
#define _2__REPEATXX1( Fxxn , X1 , X2 )					  Fxxn( X1 , X2 , 1 )
#define _2__REPEATXX2( Fxxn , X1 , X2 ) _2__REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _2__REPEATXX3( Fxxn , X1 , X2 ) _2__REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _2__REPEATXX4( Fxxn , X1 , X2 ) _2__REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _2__REPEATXX5( Fxxn , X1 , X2 ) _2__REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _2__REPEATXX6( Fxxn , X1 , X2 ) _2__REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _2__REPEATXX7( Fxxn , X1 , X2 ) _2__REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _2__REPEATXX8( Fxxn , X1 , X2 ) _2__REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _2__REPEATXX9( Fxxn , X1 , X2 ) _2__REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _2__REPEATXX_N( n , Fxxn , X1 , X2 ) _2__REPEATXX##n( Fxxn , X1 , X2 )
#define _2__REPEATXX_0_9( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 0 ) _2__REPEATXX9( Fxxn , X1 , X2 )

#define _2___REPEATXX0( Fxxn , X1 , X2 )
#define _2___REPEATXX1( Fxxn , X1 , X2 )						Fxxn( X1 , X2 , 1 )
#define _2___REPEATXX2( Fxxn , X1 , X2 ) _2___REPEATXX1( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 2 )
#define _2___REPEATXX3( Fxxn , X1 , X2 ) _2___REPEATXX2( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 3 )
#define _2___REPEATXX4( Fxxn , X1 , X2 ) _2___REPEATXX3( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 4 )
#define _2___REPEATXX5( Fxxn , X1 , X2 ) _2___REPEATXX4( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 5 )
#define _2___REPEATXX6( Fxxn , X1 , X2 ) _2___REPEATXX5( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 6 )
#define _2___REPEATXX7( Fxxn , X1 , X2 ) _2___REPEATXX6( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 7 )
#define _2___REPEATXX8( Fxxn , X1 , X2 ) _2___REPEATXX7( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 8 )
#define _2___REPEATXX9( Fxxn , X1 , X2 ) _2___REPEATXX8( Fxxn , X1 , X2 ) Fxxn( X1 , X2 , 9 )

#define _2_I_REPEATXX0( Fxxn , X1 , X2 ) 
#define _2_I_REPEATXX1( Fxxn , X1 , X2 ) _2___REPEATXX0( Fxxn , X1 , X2 )
#define _2_I_REPEATXX2( Fxxn , X1 , X2 ) _2___REPEATXX1( Fxxn , X1 , X2 )
#define _2_I_REPEATXX3( Fxxn , X1 , X2 ) _2___REPEATXX2( Fxxn , X1 , X2 )
#define _2_I_REPEATXX4( Fxxn , X1 , X2 ) _2___REPEATXX3( Fxxn , X1 , X2 )
#define _2_I_REPEATXX5( Fxxn , X1 , X2 ) _2___REPEATXX4( Fxxn , X1 , X2 )
#define _2_I_REPEATXX6( Fxxn , X1 , X2 ) _2___REPEATXX5( Fxxn , X1 , X2 )
#define _2_I_REPEATXX7( Fxxn , X1 , X2 ) _2___REPEATXX6( Fxxn , X1 , X2 )
#define _2_I_REPEATXX8( Fxxn , X1 , X2 ) _2___REPEATXX7( Fxxn , X1 , X2 )
#define _2_I_REPEATXX9( Fxxn , X1 , X2 ) _2___REPEATXX8( Fxxn , X1 , X2 )

#define _2_REPEAT_NNN( n1 , n2 , n3 , Fnnn )\
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEATXX_N( n3 , Fnnn , 0 , 0 )\
			 , \
			_2_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _2_I_REPEATXX##n2( _2_REPEATXX_0_9 , Fnnn , 0 ) _2_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_2_REPEATXX_N( 9 , Fnnn , 0 , 0 ) _2__REPEATXX9( _2_REPEATXX_0_9 , Fnnn , 0 ) _2_I_REPEATXX##n1( _2__REPEATXX_0_9 , _2_REPEATXX_0_9 , Fnnn ) \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_2_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _2_I_REPEATXX##n2( _2_REPEATXX_0_9 , Fnnn , n1 ) _2_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )
#define _2_REPEATC_NNN( n1 , n2 , n3 , Fnnn1 , Fnnn )\
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEATXXC_N( n3 , Fnnn1 , Fnnn , 0 , 0 )\
			 , \
			_2_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _2_I_REPEATXX##n2( _2_REPEATXX_0_9 , Fnnn , 0 ) _2_REPEATXX_0_N( n3 , Fnnn , 0 , n2 )\
		 )\
		 , \
		_2_REPEATXXC_N( 9 , Fnnn1 , Fnnn , 0 , 0 ) _2__REPEATXX9( _2_REPEATXX_0_9 , Fnnn , 0 ) _2_I_REPEATXX##n1( _2__REPEATXX_0_9 , _2_REPEATXX_0_9 , Fnnn ) \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEATXX_0_N( n3 , Fnnn , n1 , 0 )\
			 , \
			_2_REPEATXX_0_N( 9 , Fnnn , n1 , 0 )  _2_I_REPEATXX##n2( _2_REPEATXX_0_9 , Fnnn , n1 ) _2_REPEATXX_0_N( n3 , Fnnn , n1 , n2 )\
		 )\
	 )

#define _2_REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _2_REPEATXXX1( Fxxxn , X1 , X2 , X3 )						  Fxxxn( X1 , X2 , X3 , 1 )
#define _2_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _2_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _2_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _2_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _2_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _2_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _2_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _2_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _2_REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _2_REPEATXXX_0_N( n , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _2_REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _2_REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _2_REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _2_REPEATXXXC0( Fxxxn1 , Fxxxn , X1 , X2 , X3 )
#define _2_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 )						  Fxxxn1( X1 , X2 , X3 , 1 )
#define _2_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC1( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _2_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC2( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _2_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC3( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _2_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC4( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _2_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC5( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _2_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC6( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _2_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC7( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _2_REPEATXXXC9( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC8( Fxxxn1 , Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _2_REPEATXXXC_N( n , Fxxxn1 , Fxxxn , X1 , X2 , X3 ) _2_REPEATXXXC##n( Fxxxn , X1 , X2 , X3 )

#define _2__REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _2__REPEATXXX1( Fxxxn , X1 , X2 , X3 )							Fxxxn( X1 , X2 , X3 , 1 )
#define _2__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _2__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _2__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _2__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _2__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _2__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _2__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _2__REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _2__REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _2__REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _2__REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _2__REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _2___REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _2___REPEATXXX1( Fxxxn , X1 , X2 , X3 )							  Fxxxn( X1 , X2 , X3 , 1 )
#define _2___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _2___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _2___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _2___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _2___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _2___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _2___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _2___REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _2___REPEATXXX_N( n , Fxxxn , X1 , X2 , X3 ) _2___REPEATXXX##n( Fxxxn , X1 , X2 , X3 )
#define _2___REPEATXXX_0_9( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 0 ) _2___REPEATXXX9( Fxxxn , X1 , X2 , X3 )

#define _2____REPEATXXX0( Fxxxn , X1 , X2 , X3 )	
#define _2____REPEATXXX1( Fxxxn , X1 , X2 , X3 )								Fxxxn( X1 , X2 , X3 , 1 )
#define _2____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX1( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 2 )
#define _2____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX2( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 3 )
#define _2____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX3( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 4 )
#define _2____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX4( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 5 )
#define _2____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX5( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 6 )
#define _2____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX6( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 7 )
#define _2____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX7( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 8 )
#define _2____REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX8( Fxxxn , X1 , X2 , X3 ) Fxxxn( X1 , X2 , X3 , 9 )

#define _2_I_REPEATXXX0( Fxxxn , X1 , X2 , X3 ) 
#define _2_I_REPEATXXX1( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX0( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX2( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX1( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX3( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX2( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX4( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX3( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX5( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX4( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX6( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX5( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX7( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX6( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX8( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX7( Fxxxn , X1 , X2 , X3 )
#define _2_I_REPEATXXX9( Fxxxn , X1 , X2 , X3 ) _2____REPEATXXX8( Fxxxn , X1 , X2 , X3 )

#define _2_REPEAT_NNNN( n1 , n2 , n3 , n4 , Fnnnn )\
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_N( n4 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_2_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_2_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2_I_REPEATXXX##n2( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , 0 )\
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _2_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_2_REPEATXXX_N( 9 , Fnnnn , 0 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2___REPEATXXX9( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , 0 ) _2_I_REPEATXXX##n1( _2___REPEATXXX_0_9 , _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn )\
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _2_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , n1 , 0 , 0 ) _2_I_REPEATXXX##n2( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , n1 )\
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _2_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )
#define _2_REPEATC_NNNN( n1 , n2 , n3 , n4 , Fnnnn1 , Fnnnn )\
	_2_REPEAT_ZEROTEST##n1( \
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXXC_N( n4 , Fnnnn1 , Fnnnn , 0 , 0 , 0 )\
				 , \
				_2_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2_REPEATXXX_0_N( n4 , Fnnnn , 0 , 0 , n3 )\
			 )\
			 , \
			_2_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2_I_REPEATXXX##n2( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , 0 )\
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , 0 , n2 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , 0 , n2 ) _2_REPEATXXX_0_N( n4 , Fnnnn , 0 , n2 , n3 )\
			 )\
		 )\
		 , \
		_2_REPEATXXXC_N( 9 , Fnnnn1 , Fnnnn , 0 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , 0 , 0 ) _2___REPEATXXX9( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , 0 ) _2_I_REPEATXXX##n1( _2___REPEATXXX_0_9 , _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn )\
		_2_REPEAT_ZEROTEST##n2( \
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , n1 , 0 ) _2_REPEATXXX_0_N( n4 , Fnnnn , n1 , 0 , n3 )\
			 )\
			 , \
			_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , 0 , 0 ) _2__REPEATXXX9( _2_REPEATXXX_0_9 , Fnnnn , n1 , 0 , 0 ) _2_I_REPEATXXX##n2( _2__REPEATXXX_0_9 , _2_REPEATXXX_0_9 , Fnnnn , n1 )\
			_2_REPEAT_ZEROTEST##n3( \
				_2_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , 0 )\
				 , \
				_2_REPEATXXX_0_N( 9 , Fnnnn , n1 , n2 , 0 ) _2_I_REPEATXXX##n3( _2_REPEATXXX_0_9 , Fnnnn , n1 , n2 ) _2_REPEATXXX_0_N( n4 , Fnnnn , n1 , n2 , n3 )\
			 )\
		 )\
	 )

#endif
