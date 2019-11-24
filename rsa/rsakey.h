#ifndef RSA_KEY_H
#define RSA_KEY_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <botan/numthry.h>
#include <botan/auto_rng.h>
#include <botan/rng.h>
#include <key/key.h>

using namespace std;
using namespace Botan;

class RSAKey: public Key
{
  private:
    BigInt p, q, n, m, t;
    BigInt privateKey;
    BigInt publicKey;
    AutoSeeded_RNG *rng;
    int size;
  public:
    static RSAKey *generateKey(AutoSeeded_RNG *, int);
    static RSAKey *generateKey(int);
    RSAKey();
    RSAKey(const unsigned char [], int);
    BigInt getN() const;
    BigInt getT() const;
    BigInt getP() const;
    BigInt getQ() const;
    BigInt getPrivateKey() const;
    BigInt getPublicKey() const;
    int getSize() const;
    void getBytesPublicKey(unsigned char []);
    void encodeN(unsigned char []) const;
    void setN(const unsigned char []);
};

#endif