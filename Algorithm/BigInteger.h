#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_

#include <string>
#include <iostream>

// 仅用string实现大整数
class BigInteger {
public:
    BigInteger(long long n = 0);
    BigInteger(std::string str);
    BigInteger(const BigInteger &bi);
    BigInteger& operator=(const BigInteger &bi);
    BigInteger& operator+(const BigInteger &bi);
    BigInteger& operator-(const BigInteger &bi);
    BigInteger operator-();
    BigInteger& operator*(const BigInteger &bi);
    BigInteger& operator/(const BigInteger &bi);
    bool operator==(const BigInteger &bi);
    bool operator<(const BigInteger &bi);
    bool operator<=(const BigInteger &bi);
    bool operator!=(const BigInteger &bi);
    bool operator>(const BigInteger &bi);
    bool operator>=(const BigInteger &bi);

    std::string toString() const;
    ~BigInteger();
    friend std::ostream &operator<<(std::ostream &out, const BigInteger &bi);
private:
    int getSign() const;
    std::string data;
};

#endif
