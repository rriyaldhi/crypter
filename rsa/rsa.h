#ifndef RSA_H
#define RSA_H

#include <rsa/rsakey.h>
#include <rsa/rsadata.h>

using namespace std;

class RSA
{
  public:
    static RSAData *encrypt(const RSAData *, const RSAKey *);
    static RSAData *decrypt(const RSAData *, const RSAKey *);
};

#endif