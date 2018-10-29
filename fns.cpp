/* 
 * File:   fns.cpp
 * Author: ll118
 *
 * Created on 28 August 2015, 11:58 AM
 */

#include <cstdlib>
#include <fns.h>
using namespace std;

int AllHash(string filename) {
	ifstream ifs(filename.c_str(), ios::binary);
	string s((istreambuf_iterator<char>(ifs.rdbuf())),istreambuf_iterator<char>());
	ifs.close();
        unsigned int a = MurmurHashNeutral2(s.c_str(),s.length(),1);
	return a;
}
unsigned int MurmurHashNeutral2(const void *key, int len, unsigned int seed ) {
    const unsigned int m = 0x5bd1e995;
    const int r = 24;
    unsigned int h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;
    while(len >= 4) {
        unsigned int k;
        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;
        k *= m; 
        k ^= k >> r; 
        k *= m;
        h *= m;
        h ^= k;
        data += 4;
        len -= 4;
    }
    switch(len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
        h *= m;
    };
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;
return h;
}
/*
 * 
 */

