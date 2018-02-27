#ifndef __RSA_H__
#define __RSA_H__

#include <string>
using namespace std;

int rsa_sign(unsigned char* in, int inLen, const string &key_path, char *out, int *plen);

#endif 
