#ifndef _NUMBER2_H_
#define _NUMBER2_H_

#define NUMBERN( prefix, suffix, n )						_2_NUMBERN( prefix, suffix, n )
#define NUMBERNN( prefix, suffix, n1 , n2 )					_2_NUMBERNN( prefix, suffix, n1 , n2 )
#define NUMBERNNN( prefix, suffix, n1 , n2 , n3 )			_2_NUMBERNNN( prefix, suffix, n1 , n2 , n3 )
#define NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 )		_2_NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 )

#define _2_NUMBERN( prefix, suffix, n ) prefix##n

#define _2_NUMBER2( prefix, suffix, n ) _2_NUMBERN( prefix, suffix, n )
#define _2_NUMBER1( prefix, suffix, n ) prefix##1##n##suffix
#define _2_NUMBER2( prefix, suffix, n ) prefix##2##n##suffix
#define _2_NUMBER3( prefix, suffix, n ) prefix##3##n##suffix
#define _2_NUMBER4( prefix, suffix, n ) prefix##4##n##suffix
#define _2_NUMBER5( prefix, suffix, n ) prefix##5##n##suffix
#define _2_NUMBER6( prefix, suffix, n ) prefix##6##n##suffix
#define _2_NUMBER7( prefix, suffix, n ) prefix##7##n##suffix
#define _2_NUMBER8( prefix, suffix, n ) prefix##8##n##suffix
#define _2_NUMBER9( prefix, suffix, n ) prefix##9##n##suffix

#define _2_NUMBERNN( prefix, suffix, n1 , n2 ) _2_NUMBER##n1( prefix, suffix, n2 )

#define _2__NUMBER2( prefix, suffix, n1 , n2 ) _2_NUMBERNN( prefix, suffix, n1 , n2 )
#define _2__NUMBER1( prefix, suffix, n1 , n2 ) prefix##1##n1##n2##suffix
#define _2__NUMBER2( prefix, suffix, n1 , n2 ) prefix##2##n1##n2##suffix
#define _2__NUMBER3( prefix, suffix, n1 , n2 ) prefix##3##n1##n2##suffix
#define _2__NUMBER4( prefix, suffix, n1 , n2 ) prefix##4##n1##n2##suffix
#define _2__NUMBER5( prefix, suffix, n1 , n2 ) prefix##5##n1##n2##suffix
#define _2__NUMBER6( prefix, suffix, n1 , n2 ) prefix##6##n1##n2##suffix
#define _2__NUMBER7( prefix, suffix, n1 , n2 ) prefix##7##n1##n2##suffix
#define _2__NUMBER8( prefix, suffix, n1 , n2 ) prefix##8##n1##n2##suffix
#define _2__NUMBER9( prefix, suffix, n1 , n2 ) prefix##9##n1##n2##suffix

#define _2_NUMBERNNN( prefix, suffix, n1 , n2 , n3 ) _2__NUMBER##n1( prefix, suffix, n2 , n3 )

#define _2___NUMBER2( prefix, suffix, n1 , n2 , n3 ) _2_NUMBERNNN( prefix, suffix, n1 , n2 , n3 )
#define _2___NUMBER1( prefix, suffix, n1 , n2 , n3 ) prefix##1##n1##n2##n3##suffix
#define _2___NUMBER2( prefix, suffix, n1 , n2 , n3 ) prefix##2##n1##n2##n3##suffix
#define _2___NUMBER3( prefix, suffix, n1 , n2 , n3 ) prefix##3##n1##n2##n3##suffix
#define _2___NUMBER4( prefix, suffix, n1 , n2 , n3 ) prefix##4##n1##n2##n3##suffix
#define _2___NUMBER5( prefix, suffix, n1 , n2 , n3 ) prefix##5##n1##n2##n3##suffix
#define _2___NUMBER6( prefix, suffix, n1 , n2 , n3 ) prefix##6##n1##n2##n3##suffix
#define _2___NUMBER7( prefix, suffix, n1 , n2 , n3 ) prefix##7##n1##n2##n3##suffix
#define _2___NUMBER8( prefix, suffix, n1 , n2 , n3 ) prefix##8##n1##n2##n3##suffix
#define _2___NUMBER9( prefix, suffix, n1 , n2 , n3 ) prefix##9##n1##n2##n3##suffix

#define _2_NUMBERNNNN( prefix, suffix, n1 , n2 , n3 , n4 ) _2___NUMBER##n1( prefix, suffix, n2 , n3 , n4 )

#endif
