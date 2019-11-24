#ifndef RSA_DATA_H
#define RSA_DATA_H

#include <botan/bigint.h>
#include <data/data.h>
#include <cmath>

using namespace Botan;

class RSAData: public Data
{
  public:
    RSAData();
    RSAData(BigInt);
    RSAData(unsigned char [], int);
    BigInt data;
    void encodeData(unsigned char [], int);
};

#endif