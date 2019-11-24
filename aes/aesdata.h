#ifndef AES_DATA_H
#define AES_DATA_H

#define MAX_AES_DATA 1024
#define AES_BIT_DATA 8
#define AES_DATA 16

#include <data/data.h>
#include <cstring>

class AESData: public Data
{
  public:
    int length;
    AESData();
    AESData(const unsigned char []);
    AESData(const unsigned char [], int);
    unsigned char data[MAX_AES_DATA];
};

#endif