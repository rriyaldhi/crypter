#include <key/key.h>
#include <data/data.h>
#include <aes/aes.h>
#include <aes/obsoleteaes.h>
#include <aes/aeskey.h>
#include <aes/aesdata.h>
#include <rsa/rsa.h>
#include <rsa/rsakey.h>
#include <rsa/rsadata.h>
#include <botan/auto_rng.h>

using namespace Botan;

class Implementation
{
  private:
    static const int AES = 0;
    static const int OBSOLETE_AES = 1;
    static const int RSA = 2;
    static const int AES_KEY = 0;
    static const int RSA_KEY = 1;
  public:
    static Data *encrypt(const int type, const Data *data, const Key *key)
    {
      switch (type)
      {
        case AES:
          return AES::encrypt((AESData *)data, (AESKey *)key);
        case OBSOLETE_AES:
          return ObsoleteAES::encrypt((AESData *)data, (AESKey *)key);
        case RSA:
          return RSA::encrypt((RSAData *)data, (RSAKey *)key);
      }
      return NULL;
    }
    static Data *decrypt(const int type, const Data *data, const Key *key)
    {
      switch (type)
      {
        case AES:
          return AES::decrypt((AESData *)data, (AESKey *)key);
        case OBSOLETE_AES:
          return ObsoleteAES::decrypt((AESData *)data, (AESKey *)key);
        case RSA:
          return RSA::decrypt((RSAData *)data, (RSAKey *)key);
      }
      return NULL;
    }
    static Key *generateKey(AutoSeeded_RNG *rng, const int type, int size)
    {
      switch (type)
      {
        case AES_KEY:
          return AESKey::generateKey(rng, size);
        case RSA_KEY:
          return RSAKey::generateKey(rng, size);
      }
      return NULL;
    }
};