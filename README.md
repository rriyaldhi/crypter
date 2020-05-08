### Crypter

Crypter module provides a capability to encrypt a message using combination of AES-RSA hybrid encryption.

![aes-rsa encryption schema](https://user-images.githubusercontent.com/10885503/81422441-40945f00-9153-11ea-8736-cbe9b60ba0fb.png)

AES algorithm is implemented based on:

[Improvement of Advanced Encryption Standard
Algorithm with Shift Row and S.Box Modification
Mapping In Mix Column](https://pdf.sciencedirectassets.com/280203/1-s2.0-S1877050917X0015X/1-s2.0-S1877050917321294/main.pdf?X-Amz-Security-Token=IQoJb3JpZ2luX2VjEA4aCXVzLWVhc3QtMSJIMEYCIQCa%2Bte%2BRTghLPwWbxq7MDWnynlN0AqXblKhtZdVL%2FaRJgIhAKa6FOYRgFOgJcBbs9i6EFHabevIIzt%2B19nsPMsJiSHhKs8CCEcQAhoMMDU5MDAzNTQ2ODY1Igzti4z67oh1GR92C7sqrAJKPuKy8Lm7t2fSDrWI6pTzz3nCtEqg%2B3bhORNCkyQioB5DQQkb57VmQj%2FfJUbjjBl4T6Bmu9LPmRt8kKsw%2BjSPGm7EMottF141bNdCENY%2FI%2B8rTatL2oKHxW954WRcL7avwzr26YwA%2FH4hK7xt5gOZlcyeslr1HxVSSBICxrPzrKlmMWNWsy%2BgTK86H24ffGqQ7xZzSe900AY%2FtT6g4YoFzMQ7lvsbRhEON%2B%2FzYKa5oxMfOx%2BAkvD5G54pDFvTofNbiGv7swtvTEW8utcfcwG7Y5GvpQh7kRFtZr%2FSqANEwDnH7rjqr0W5coNPqPlXG6YOI6%2BVv7Y2rmPXTXqL7y9xS8on23G9sCkm1CxMiMMXRGiqEV72Yw%2Fm4WBV8cOxpOQZ8uupQYUwE%2F9SWF8wrZrq7gU6zwJt4Y7RQvR5jNqhG77j7CP4fuPS%2Fq%2BhYcxIqP7BoV9DmBH9BWJTtUYIFI9vwrZg8AuXS8xwHMXKwuyLNLMLao%2B66tXYHukciAUEejBtnAtQNmkP2mGfiqfbhPJJObagmyFFhicjMwwHLr7%2FQoeYVuzShHYiIkMYVA0vEwA1rsyHPbDusm02CIaTgiBlRBCJm8uqna6VRTUTUhrntHhUwkJPXkWcAMcns3qbPT2r7e02dLcFM6L8U9cH7PQxNlHtiEXFhz0WEA9AgXB9FEADIEADbLUAVYh%2FzjhHenDmcKnswbUiGBzraQBBjy2lEKhtfsVBzP2lNgPOYOwCPYZ1o7f7GN3Z2gLQjS3iKOa4hGJ43r92KZTlGAO0TI3lOYC9VSAMZEmGhx4vxxsboTFebUxyIqgHplVIIMK0wX2cgD2UIOeRM0VFQo7bi8u8P9I%2FKA%3D%3D&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20191124T151620Z&X-Amz-SignedHeaders=host&X-Amz-Expires=300&X-Amz-Credential=ASIAQ3PHCVTYTPNB2ORU%2F20191124%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=38b06e54b843a6b96e7c9c5064058f24f2e166827c2a385071f8153356356476&hash=4cab7c1e5b5e18e6189d3c55c98e9e999e1d9e366e92b3f3156fc7ddf770ad7a&host=68042c943591013ac2b2430a89b270f6af2c76d8dfd086a07176afe7c76c2c61&pii=S1877050917321294&tid=spdf-418146b8-2519-4c38-be89-8054cd726eaf&sid=2894affc6c180143c76843784352a3d726d6gxrqb&type=client)

#### Dependencies

##### Botan - Crypto and TLS for Modern C++

https://botan.randombit.net/


#### Usage Example

##### AES
```
unsigned char data[] = "crypter";
int dataLength = strlen((const char *)data);

AESData *plain = new AESData(data, dataLength);

AutoSeeded_RNG rng;
AESKey *key = (AESKey *)Crypto::generateKey(&rng, Crypto::AES_KEY, 128);

AESData *cipher = (AESData *)Crypto::encrypt(Crypto::AES, plain, key);

AESData *decrypted = (AESData *)Crypto::decrypt(Crypto::AES, cipher, key);
```

##### RSA
```
RSAData *plain = new RSAData(BigInt("12345"));

AutoSeeded_RNG rng;
RSAKey *rsaKey = (RSAKey *)Crypto::generateKey(&rng, Crypto::RSA_KEY, 2048);

RSAData *cipher = (RSAData *) Crypto::encrypt(Crypto::RSA, plain, rsaKey);

RSAData *decrypted = (RSAData *) Crypto::decrypt(Crypto::RSA, cipher, rsaKey);
```
