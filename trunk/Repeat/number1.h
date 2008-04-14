#ifndef _NUMBER_N

#define _NUMBER_N( prefix, suffix, n )						_1_NUMBER_N( prefix, suffix, n )
#define _NUMBER_NN( prefix, suffix, n1 , n2 )					_1_NUMBER_NN( prefix, suffix, n1 , n2 )
#define _NUMBER_NNN( prefix, suffix, n1 , n2 , n3 )			_1_NUMBER_NNN( prefix, suffix, n1 , n2 , n3 )
#define _NUMBER_NNNN( prefix, suffix, n1 , n2 , n3 , n4 )		_1_NUMBER_NNNN( prefix, suffix, n1 , n2 , n3 , n4 )

#define _1_NUMBER_N( prefix, suffix, n ) prefix##n##suffix

#define _1_NUMBER0( prefix, suffix, n ) _1_NUMBER_N( prefix, suffix, n )
#define _1_NUMBER1( prefix, suffix, n ) prefix##1##n##suffix
#define _1_NUMBER2( prefix, suffix, n ) prefix##2##n##suffix
#define _1_NUMBER3( prefix, suffix, n ) prefix##3##n##suffix
#define _1_NUMBER4( prefix, suffix, n ) prefix##4##n##suffix
#define _1_NUMBER5( prefix, suffix, n ) prefix##5##n##suffix
#define _1_NUMBER6( prefix, suffix, n ) prefix##6##n##suffix
#define _1_NUMBER7( prefix, suffix, n ) prefix##7##n##suffix
#define _1_NUMBER8( prefix, suffix, n ) prefix##8##n##suffix
#define _1_NUMBER9( prefix, suffix, n ) prefix##9##n##suffix

#define _1_NUMBER_NN( prefix, suffix, n1 , n2 ) _1_NUMBER##n1( prefix, suffix, n2 )

#define _1__NUMBER0( prefix, suffix, n1 , n2 ) _1_NUMBER_NN( prefix, suffix, n1 , n2 )
#define _1__NUMBER1( prefix, suffix, n1 , n2 ) prefix##1##n1##n2##suffix
#define _1__NUMBER2( prefix, suffix, n1 , n2 ) prefix##2##n1##n2##suffix
#define _1__NUMBER3( prefix, suffix, n1 , n2 ) prefix##3##n1##n2##suffix
#define _1__NUMBER4( prefix, suffix, n1 , n2 ) prefix##4##n1##n2##suffix
#define _1__NUMBER5( prefix, suffix, n1 , n2 ) prefix##5##n1##n2##suffix
#define _1__NUMBER6( prefix, suffix, n1 , n2 ) prefix##6##n1##n2##suffix
#define _1__NUMBER7( prefix, suffix, n1 , n2 ) prefix##7##n1##n2##suffix
#define _1__NUMBER8( prefix, suffix, n1 , n2 ) prefix##8##n1##n2##suffix
#define _1__NUMBER9( prefix, suffix, n1 , n2 ) prefix##9##n1##n2##suffix

#define _1_NUMBER_NNN( prefix, suffix, n1 , n2 , n3 ) _1__NUMBER##n1( prefix, suffix, n2 , n3 )

#define _1___NUMBER0( prefix, suffix, n1 , n2 , n3 ) _1_NUMBER_NNN( prefix, suffix, n1 , n2 , n3 )
#define _1___NUMBER1( prefix, suffix, n1 , n2 , n3 ) prefix##1##n1##n2##n3##suffix
#define _1___NUMBER2( prefix, suffix, n1 , n2 , n3 ) prefix##2##n1##n2##n3##suffix
#define _1___NUMBER3( prefix, suffix, n1 , n2 , n3 ) prefix##3##n1##n2##n3##suffix
#define _1___NUMBER4( prefix, suffix, n1 , n2 , n3 ) prefix##4##n1##n2##n3##suffix
#define _1___NUMBER5( prefix, suffix, n1 , n2 , n3 ) prefix##5##n1##n2##n3##suffix
#define _1___NUMBER6( prefix, suffix, n1 , n2 , n3 ) prefix##6##n1##n2##n3##suffix
#define _1___NUMBER7( prefix, suffix, n1 , n2 , n3 ) prefix##7##n1##n2##n3##suffix
#define _1___NUMBER8( prefix, suffix, n1 , n2 , n3 ) prefix##8##n1##n2##n3##suffix
#define _1___NUMBER9( prefix, suffix, n1 , n2 , n3 ) prefix##9##n1##n2##n3##suffix

#define _1_NUMBER_NNNN( prefix, suffix, n1 , n2 , n3 , n4 ) _1___NUMBER##n1( prefix, suffix, n2 , n3 , n4 )

#endif
