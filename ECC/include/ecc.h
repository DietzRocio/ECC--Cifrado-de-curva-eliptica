// ecc.h
#ifndef ECC_H
#define ECC_H
#include <utility>

class ECPoint {
public:
    int x, y;

    ECPoint(int x, int y) : x(x), y(y) {} //constructor, asigna valores iniciales a x-y
};

class ECC {
public:
    static ECPoint generateKeyPair();
    static std::pair<ECPoint, int> encrypt(const ECPoint& publicKey, int message);
    static int decrypt(const ECPoint& c1, int c2, int privateKey);

private:
    static ECPoint scalarMultiply(const ECPoint& point, int scalar);
    static ECPoint addPoints(const ECPoint& p1, const ECPoint& p2);
    static int modInverse(int a, int m);
};

#endif // ECC_H
