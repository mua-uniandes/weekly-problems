#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
vector< string > tokenize( string a, string b ) {
  const char *q = a.c_str();
  while( count( b.begin(), b.end(), *q ) ) {
    q++;
  }
  vector< string > oot;
  while( *q ) {
    const char *e = q;
    while( *e && !count( b.begin(), b.end(), *e ) ) {
      e++;
    }
    oot.push_back( string( q, e ) );
    q = e;
    while( count( b.begin(), b.end(), *q ) ) {
      q++;
    }
  }
  return oot;
}
 
vector< int > sti( const vector< string > &a ) {
  vector< int > oot;
  for( int i = 0; i < a.size(); i++ ) {
    oot.push_back( atoi( a[ i ].c_str() ) );
  }
  return oot;
}
 
 
long long ans[ 102 ][ 102 ];
 
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
 
class AvoidRoads {
  public:
  long long numWays(int width, int height, vector <string> bad) {
    ans[ 0 ][ 0 ] = 1;
    set< pair< pair< int, int >, pair< int, int > > > nt;
    for( int i = 0; i < bad.size(); i++ ) {
      vector< int > st = sti( tokenize( bad[ i ], " " ) );
      nt.insert( make_pair( make_pair( st[ 0 ], st[ 1 ] ), make_pair( st[ 2 ], st[ 3 ] ) ) );
      nt.insert( make_pair( make_pair( st[ 2 ], st[ 3 ] ), make_pair( st[ 0 ], st[ 1 ] ) ) );
    }
    for( int x = 0; x <= width; x++ ) {
      for( int y = 0; y <= height; y++ ) {
        for( int k = 0; k < 2; k++ ) {
          int tx = x + dx[ k ];
          int ty = y + dy[ k ];
          if( !nt.count( make_pair( make_pair( x, y ), make_pair( tx, ty ) ) ) ) {
            ans[ tx ][ ty ] += ans[ x ][ y ];
          }
        }
      }
    }
    return ans[ width ][ height ];
  }
};
