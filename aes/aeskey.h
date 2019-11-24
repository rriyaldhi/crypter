#ifndef AES_KEY_H
#define AES_KEY_H

#include <botan/auto_rng.h>
#include <botan/bigint.h>
#include <key/key.h>
#include <cmath>

#define MAX_AES_KEY 512

using namespace Botan;

class AESKey: public Key
{
  private:
    int size;
    BigInt key;
    AutoSeeded_RNG *rng;
  public:
    static AESKey *generateKey(AutoSeeded_RNG *, int);
    AESKey();
    AESKey(AutoSeeded_RNG *rng, int);
    AESKey(const unsigned char []);
    AESKey(BigInt);
    BigInt getKey() const;
    int getSize() const;
    void get16BytesKey(unsigned char []) const;
    void resetKey();
};

#endif