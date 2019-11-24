#include <cstdio>
#include <iostream>
#include <crypto.h>

void testAES()
{
  printf("AES\n");

  unsigned char data[] = "crypter";
  int dataLength = strlen((const char *)data);

  AESData *plain = new AESData(data, dataLength);
  printf("plain-text\t: %s\n", plain->data);

  AutoSeeded_RNG rng;
  AESKey *key = (AESKey *)Crypto::generateKey(&rng, Crypto::AES_KEY, 128);

  AESData *cipher = (AESData *)Crypto::encrypt(Crypto::AES, plain, key);
  printf("cipher-text\t: %s\n", cipher->data);

  AESData *decrypted = (AESData *)Crypto::decrypt(Crypto::AES, cipher, key);
  printf("decrypted-text\t: %s\n", decrypted->data);
}

void testRSA()
{
  printf("RSA\n");

  RSAData *plain = new RSAData(BigInt("12345"));
  cout << "plain-text\t: " << plain->data << endl;

  AutoSeeded_RNG rng;
  RSAKey *rsaKey = (RSAKey *)Crypto::generateKey(&rng, Crypto::RSA_KEY, 2048);

  RSAData *cipher = (RSAData *) Crypto::encrypt(Crypto::RSA, plain, rsaKey);
  cout << "cipher-text\t: " << cipher->data << endl;

  RSAData *decrypted = (RSAData *) Crypto::decrypt(Crypto::RSA, cipher, rsaKey);
  cout << "decrypted-text\t: " << decrypted->data << endl;
}

int main() 
{
  testAES();
  testRSA();
}