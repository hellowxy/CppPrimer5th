#include "rsa.h"
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int rsa_sign(unsigned char* in, int inLen, const string &key_path, char *out, int *plen)
{
    RSA *p_rsa;
    FILE *file;
    if((file = fopen(key_path.c_str(), "r")) == NULL)
    {
        return 0;
    }

    if ((p_rsa = PEM_read_RSAPrivateKey(file, NULL, NULL, NULL)) == NULL)
    {
        return 0;
    }

    if(!RSA_sign(NID_md5, in, inLen,  (unsigned char *)out, (unsigned int *)plen, p_rsa))
    {
        return 0;
    }

    RSA_free(p_rsa);
    fclose(file);
    return 1;
}