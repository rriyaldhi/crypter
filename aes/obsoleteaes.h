#ifndef OBSOLETE_AES_H
#define OBSOLETE_AES_H

#define AES_BIT_DATA 8
#define AES_DATA 16

#include <aes/aeskey.h>
#include <aes/aesdata.h>

class ObsoleteAES
{
  private:
    static const int sbox[][AES_DATA];
    static const int inversesbox[][AES_DATA];
    static const int rcon[15];
    static void expandKey(const unsigned char [], unsigned char [], int, int);
    static void g(const unsigned char [], unsigned char [], int);
    static void subByte(unsigned char []);
    static void inverseSubByte(unsigned char []);
    static void shiftRow(unsigned char []);
    static void inverseShiftRow(unsigned char []);
    static void mixColumn(unsigned char []);
    static void inverseMixColumn(unsigned char [], int);
    static void addRoundKey(unsigned char [], const unsigned char [], int);
  public:
    static AESData *encrypt(const AESData *, const AESKey *);
    static AESData *decrypt(const AESData *, const AESKey *);
};

#endif