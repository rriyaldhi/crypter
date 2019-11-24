#include "crypto.h"
#include "implementation.h"

Data *Crypto::encrypt(const int type, const Data *data, const Key *key)
{
  return Implementation::encrypt(type, data, key);
}

Data *Crypto::decrypt(const int type, const Data *data, const Key *key)
{
  return Implementation::decrypt(type, data, key);
}

Key *Crypto::generateKey(AutoSeeded_RNG *rng, const int type, int size)
{
  return Implementation::generateKey(rng, type, size);
}