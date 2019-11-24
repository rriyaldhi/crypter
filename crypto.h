#ifndef CRYPTO_H
#define CRYPTO_H

#include <aes/aeskey.h>
#include <aes/aesdata.h>
#include <rsa/rsakey.h>
#include <rsa/rsadata.h>
#include <botan/auto_rng.h>

using namespace Botan;

class Implementation;

class Crypto
{
  public:
    static const int AES = 0;
    static const int OBSOLETE_AES = 1;
    static const int RSA = 2;
    static const int AES_KEY = 0;
    static const int RSA_KEY = 1;
    static Data *encrypt(const int, const Data *, const Key *);
    static Data *decrypt(const int, const Data *, const Key *);
    static Key *generateKey(AutoSeeded_RNG *, const int, int);
};

#endif