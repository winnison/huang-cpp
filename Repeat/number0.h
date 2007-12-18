#ifndef _NUMBER0_H_
#define _NUMBER0_H_

#define NUMBERN( prefix, suffix, n )						_0_NUMBERN( prefix, suffix, n )
#define NUMBERNN( prefix, suffix, n1 , n2 )					_0_NUMBERNN( prefix, suffix, n1 , n2 )
#define NUMBERNNN( prefix, suffix, n1 , n2 , n3 )			_0_NUMBERNNN( prefix, suffix, n1 , n2 , n3 )
#define NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 )		_0_NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 )

#define _0_NUMBERN( prefix, suffix, n ) prefix##n

#define _0_NUMBER0( prefix, suffix, n ) _0_NUMBERN( prefix, suffix, n )
#define _0_NUMBER1( prefix, suffix, n ) prefix##1##n##suffix
#define _0_NUMBER2( prefix, suffix, n ) prefix##2##n##suffix
#define _0_NUMBER3( prefix, suffix, n ) prefix##3##n##suffix
#define _0_NUMBER4( prefix, suffix, n ) prefix##4##n##suffix
#define _0_NUMBER5( prefix, suffix, n ) prefix##5##n##suffix
#define _0_NUMBER6( prefix, suffix, n ) prefix##6##n##suffix
#define _0_NUMBER7( prefix, suffix, n ) prefix##7##n##suffix
#define _0_NUMBER8( prefix, suffix, n ) prefix##8##n##suffix
#define _0_NUMBER9( prefix, suffix, n ) prefix##9##n##suffix

#define _0_NUMBERNN( prefix, suffix, n1 , n2 ) _0_NUMBER##n1( prefix, suffix, n2 )

#define _0__NUMBER0( prefix, suffix, n1 , n2 ) _0_NUMBERNN( prefix, suffix, n1 , n2 )
#define _0__NUMBER1( prefix, suffix, n1 , n2 ) prefix##1##n1##n2##suffix
#define _0__NUMBER2( prefix, suffix, n1 , n2 ) prefix##2##n1##n2##suffix
#define _0__NUMBER3( prefix, suffix, n1 , n2 ) prefix##3##n1##n2##suffix
#define _0__NUMBER4( prefix, suffix, n1 , n2 ) prefix##4##n1##n2##suffix
#define _0__NUMBER5( prefix, suffix, n1 , n2 ) prefix##5##n1##n2##suffix
#define _0__NUMBER6( prefix, suffix, n1 , n2 ) prefix##6##n1##n2##suffix
#define _0__NUMBER7( prefix, suffix, n1 , n2 ) prefix##7##n1##n2##suffix
#define _0__NUMBER8( prefix, suffix, n1 , n2 ) prefix##8##n1##n2##suffix
#define _0__NUMBER9( prefix, suffix, n1 , n2 ) prefix##9##n1##n2##suffix

#define _0_NUMBERNNN( prefix, suffix, n1 , n2 , n3 ) _0__NUMBER##n1( prefix, suffix, n2 , n3 )

#define _0___NUMBER0( prefix, suffix, n1 , n2 , n3 ) _0_NUMBERNNN( prefix, suffix, n1 , n2 , n3 )
#define _0___NUMBER1( prefix, suffix, n1 , n2 , n3 ) prefix##1##n1##n2##n3##suffix
#define _0___NUMBER2( prefix, suffix, n1 , n2 , n3 ) prefix##2##n1##n2##n3##suffix
#define _0___NUMBER3( prefix, suffix, n1 , n2 , n3 ) prefix##3##n1##n2##n3##suffix
#define _0___NUMBER4( prefix, suffix, n1 , n2 , n3 ) prefix##4##n1##n2##n3##suffix
#define _0___NUMBER5( prefix, suffix, n1 , n2 , n3 ) prefix##5##n1##n2##n3##suffix
#define _0___NUMBER6( prefix, suffix, n1 , n2 , n3 ) prefix##6##n1##n2##n3##suffix
#define _0___NUMBER7( prefix, suffix, n1 , n2 , n3 ) prefix##7##n1##n2##n3##suffix
#define _0___NUMBER8( prefix, suffix, n1 , n2 , n3 ) prefix##8##n1##n2##n3##suffix
#define _0___NUMBER9( prefix, suffix, n1 , n2 , n3 ) prefix##9##n1##n2##n3##suffix

#define _0_NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 ) _0___NUMBER##n1( prefix, suffix, n2 , n3 , n4 )

#endif
