#include "aeskey.h"

using namespace std;

AESKey *AESKey::generateKey(AutoSeeded_RNG *rng, int size)
{
  AESKey *key = new AESKey(rng, size);
  return key;
}

AESKey::AESKey()
{
  this->size = 128;
}

AESKey::AESKey(AutoSeeded_RNG *rng, int size)
{
  this->rng = rng;
  this->size = size;
  resetKey();
}

AESKey::AESKey(BigInt key)
{
  this->key = key;
  this->size = 128;
}

AESKey::AESKey(const unsigned char result[])
{
  size = 128;
  unsigned char temp[MAX_AES_KEY] = {0};
  for (int i = 0; i < size / 8; i++)
  {
    temp[i * 2] = floor(result[i] / 16);
    temp[i * 2 + 1] = result[i] % 16;
  }
  for (int i = 0; i < size / 4; i++)
  {
    if (temp[i] >= 0 && temp[i] <= 9)
      temp[i] += 48;
    else if (temp[i] >= 10 && temp[i] <= 15)
      temp[i] += 55;
  }
  key = BigInt::decode(temp, size / 4, BigInt::Hexadecimal);
}

BigInt AESKey::getKey() const
{
  return key;
}

int AESKey::getSize() const
{
  return size;
}

void AESKey::get16BytesKey(unsigned char result[]) const
{
  unsigned char temp[MAX_AES_KEY];
  memset(temp, '\0', sizeof(temp));
  BigInt::encode(temp, key, BigInt::Hexadecimal);
  for (int i = 0; i < size / 4; i++)
  {
    if (temp[i] >= 48 && temp[i] <= 57)
      temp[i] -= 48;
    else if (temp[i] >= 65 && temp[i] <= 70)
      temp[i] -= 55;
  }
  for (int i = 0; i < size / 8; i++)
  {
    result[i] = temp[i * 2] * 16 + temp[i * 2 + 1];
  }
}

void AESKey::resetKey()
{
  key.randomize(*rng, size);
}