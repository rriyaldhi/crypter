#include "rsa.h"

RSAData *RSA::encrypt(const RSAData *data, const RSAKey *key)
{
  RSAData *result = new RSAData();
  result->data = power_mod(data->data, key->getPublicKey(), key->getN());
  return result;
}

RSAData *RSA::decrypt(const RSAData *data, const RSAKey *key)
{
  RSAData *result = new RSAData();
  result->data = power_mod(data->data, key->getPrivateKey(), key->getN());
  return result;
}