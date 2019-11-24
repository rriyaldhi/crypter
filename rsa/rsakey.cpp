#include "rsakey.h"

RSAKey *RSAKey::generateKey(int size)
{
  // srand(time(0));
  RSAKey *key = new RSAKey();
  key->rng = new AutoSeeded_RNG();
  key->size = size;
  key->p = random_prime(*(key->rng), size / 2);
  do
  {
    key->q = random_prime(*(key->rng), size / 2);
  }
  while (key->q == key->p);
  key->n = key->p * key->q;
  key->t = (key->p - 1) * (key->q - 1);
  bool valid;
  do
  {
    valid = true;
    // key->publicKey = rand() % (key->n - 3) + 3;
    key->publicKey.randomize(*(key->rng), size);
    key->publicKey %= key->n;
    if (key->publicKey % 2 != 0 && gcd(key->publicKey, key->t) == 1)
    {
      if ((key->privateKey = inverse_mod(key->publicKey, key->t)) == 0)
        valid = false;
    }
    else
      valid = false;
  }
  while (!valid);
  return key;
}

RSAKey *RSAKey::generateKey(AutoSeeded_RNG *rng, int size)
{
  // srand(time(0));
  RSAKey *key = new RSAKey();
  key->rng = rng;
  key->size = size;
  key->p = random_prime(*rng, size / 2);
  do
  {
    key->q = random_prime(*rng, size / 2);
  }
  while (key->q == key->p);
  key->n = key->p * key->q;
  key->t = (key->p - 1) * (key->q - 1);
  bool valid;
  do
  {
    valid = true;
    // key->publicKey = rand() % (key->n - 3) + 3;
    key->publicKey.randomize(*rng, size);
    key->publicKey %= key->n;
    if (key->publicKey % 2 != 0 && gcd(key->publicKey, key->t) == 1)
    {
      if ((key->privateKey = inverse_mod(key->publicKey, key->t)) == 0)
        valid = false;
    }
    else
      valid = false;
  }
  while (!valid);
  return key;
}

BigInt RSAKey::getN() const
{
  return n;
}
BigInt RSAKey::getP() const
{
  return p;
}
BigInt RSAKey::getQ() const
{
  return q;
}
BigInt RSAKey::getT() const
{
  return t;
}
BigInt RSAKey::getPrivateKey() const
{
  return privateKey;
}
BigInt RSAKey::getPublicKey() const
{
  return publicKey;
}

RSAKey::RSAKey()
{

}

RSAKey::RSAKey(const unsigned char publicKey[], int size)
{
  int maxRsaKey = size / 4;
  this->size = size;
  unsigned char temp[512] = {0};
  for (int i = 0; i < maxRsaKey / 2; i++)
  {
    temp[i * 2] = floor(publicKey[i] / 16);
    temp[i * 2 + 1] = publicKey[i] % 16;
  }
  for (int i = 0; i < maxRsaKey; i++)
  {
    if (temp[i] >= 0 && temp[i] <= 9)
      temp[i] += 48;
    else if (temp[i] >= 10 && temp[i] <= 15)
      temp[i] += 55;
  }
  this->publicKey = BigInt::decode(temp, maxRsaKey, BigInt::Hexadecimal);
}

void RSAKey::getBytesPublicKey(unsigned char result[])
{
  int maxRsaKey = size / 4;
  unsigned char temp[512];
  memset(temp, '\0', sizeof(temp));
  BigInt::encode(temp, publicKey, BigInt::Hexadecimal);
  for (int i = 0; i < maxRsaKey; i++)
  {
    if (temp[i] >= 48 && temp[i] <= 57)
      temp[i] -= 48;
    else if (temp[i] >= 65 && temp[i] <= 70)
      temp[i] -= 55;
  }
  for (int i = 0; i < maxRsaKey / 2; i++)
  {
    result[i] = temp[i * 2] * 16 + temp[i * 2 + 1];
  }
}

int RSAKey::getSize() const
{
  return size;
}

void RSAKey::encodeN(unsigned char result[]) const
{
  int maxN = size / 4;
  unsigned char temp[512];
  memset(temp, '\0', sizeof(temp));
  memset(result, '\0', sizeof(temp));
  BigInt::encode(temp, n, BigInt::Hexadecimal);
  for (int i = 0; i < maxN; i++)
  {
    if (temp[i] >= 48 && temp[i] <= 57)
      temp[i] -= 48;
    else if (temp[i] >= 65 && temp[i] <= 70)
      temp[i] -= 55;
  }
  for (int i = 0; i < maxN / 2; i++)
  {
    result[i] = temp[i * 2] * 16 + temp[i * 2 + 1];
  }
}

void RSAKey::setN(const unsigned char value[])
{
  int maxN = size / 4;
  this->size = size;
  unsigned char temp[512] = {0};
  for (int i = 0; i < maxN / 2; i++)
  {
    temp[i * 2] = floor(value[i] / 16);
    temp[i * 2 + 1] = value[i] % 16;
  }
  for (int i = 0; i < maxN; i++)
  {
    if (temp[i] >= 0 && temp[i] <= 9)
      temp[i] += 48;
    else if (temp[i] >= 10 && temp[i] <= 15)
      temp[i] += 55;
  }
  this->n = BigInt::decode(temp, maxN, BigInt::Hexadecimal);
}