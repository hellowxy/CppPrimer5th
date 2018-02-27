#include <iostream> 
#include <string> 
#include <base64.h>
#include "rsa.h"

using namespace std; 

int main(int argc, char** argv) 
{ 
    char szSign[2048] = {0};
    char szB64Sign[2048] = {0};
    int len = sizeof(szSign);

    //string strContent = "hello world";
	unsigned char content[] = {94,182,59,187,224,30,238,208,147,203,34,187,143,90,205,195};
    int iRet = rsa_sign(content, 16, "./30000012_2048.pem", szSign, &len);

    cout << iRet << ", " << len << endl;

    int b64len = sizeof(szB64Sign);
    iRet = Base64_Encode((const unsigned char*)szSign, len, szB64Sign, b64len, &b64len);
    cout << iRet << ", " << szB64Sign << ", " << b64len << endl;
    return 0;
}
