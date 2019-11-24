#ifndef AES_H
#define AES_H

#include <aes/aesdata.h>
#include <aes/aeskey.h>

class AES
{
  private:
    static const unsigned char sbox[][AES_DATA];
    static const unsigned char sbox2[][AES_DATA];
    static const unsigned char sbox3[][AES_DATA];
    static const int inversesbox[][AES_DATA];
    static const int rcon[15];
    static const int shift[AES_DATA];
    static const int inverseshift[AES_DATA];
    static void expandKey(const unsigned char [], unsigned char [], int, int);
    static void g(const unsigned char [], unsigned char [], int);
  public:
    static AESData *encrypt(const AESData *, const AESKey *);
    static AESData *decrypt(const AESData *, const AESKey *);
};

#endif