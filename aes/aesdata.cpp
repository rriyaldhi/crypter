#include "aesdata.h"
#include <cstdio>

AESData::AESData()
{
  memcpy(this->data, "", MAX_AES_DATA);
}

AESData::AESData(const unsigned char data[])
{
  memcpy(this->data, data, MAX_AES_DATA);
}

AESData::AESData(const unsigned char data[], int length)
{
  memcpy(this->data, data, ((length % 16 == 0) ? length : (length / 16 + 1) * 16));
  this->length = length;
}