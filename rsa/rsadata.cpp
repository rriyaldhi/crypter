#include "rsadata.h"

RSAData::RSAData()
{
  this->data = 0;
}

RSAData::RSAData(BigInt data)
{
  this->data = data;
}

RSAData::RSAData(unsigned char result[], int size)
{
  unsigned char temp[768] = {0};
  memset(temp, '\0', sizeof(temp));
  for (int i = 0; i < size / 2; i++)
  {
    temp[i * 2] = floor(result[i] / 16);
    temp[i * 2 + 1] = result[i] % 16;
  }
  for (int i = 0; i < size; i++)
  {
    if (temp[i] >= 0 && temp[i] <= 9)
      temp[i] += 48;
    else if (temp[i] >= 10 && temp[i] <= 15)
      temp[i] += 55;
  }
  data = BigInt::decode(temp, size, BigInt::Hexadecimal);
}

void RSAData::encodeData(unsigned char result[], int size)
{
  unsigned char temp[1024];
  memset(temp, '\0', sizeof(temp));
  BigInt::encode(temp, data, BigInt::Hexadecimal);
  for (int i = 0; i < size; i++)
  {
    if (temp[i] >= 48 && temp[i] <= 57)
      temp[i] -= 48;
    else if (temp[i] >= 65 && temp[i] <= 70)
      temp[i] -= 55;
  }
  for (int i = 0; i < size / 2; i++)
  {
    result[i] = temp[i * 2] * 16 + temp[i * 2 + 1];
  }
}