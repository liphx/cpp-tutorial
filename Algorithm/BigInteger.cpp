#include "BigInteger.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace { // 此匿名名称空间中的函数仅在此文件中可见
    
template<typename T>
T fromString(const std::string& s) {
    std::istringstream is(s);
    T t;
    is >> t;
    return t;
}

template<typename T>
std::string toString(const T& t) {
    std::ostringstream os;
    os << t;
    return os.str();
}

};

// 构造函数
BigInteger::BigInteger(long long n)
{
    this->data = ::toString(n);
}

// 构造函数
BigInteger::BigInteger(std::string str)
{
    if (str == "")
        data = "0";
    else
        data = str;
}

// 拷贝构造函数
BigInteger::BigInteger(const BigInteger &bi)
{
    data = bi.data;
}

// 赋值运算符
BigInteger& BigInteger::operator=(const BigInteger &bi)
{
    data = bi.data;
    return *this;
}

// 析构函数
BigInteger::~BigInteger()
{
    ;
}

// 转成字符串
std::string BigInteger::toString() const
{
    return data;
}

// 输出流
std::ostream &operator<<(std::ostream &out, const BigInteger &bi)
{
    out << bi.toString();
    return out;
}

// 重载 +
BigInteger& BigInteger::operator+(const BigInteger &bi)
{
    return *this;
}

// 重载 -
BigInteger& BigInteger::operator-(const BigInteger &bi)
{
    return *this;
}

// 重载一元负号
BigInteger BigInteger::operator-()
{
    if (getSign() == 1) {
        data = "-" + data;
    } else if (getSign() == -1) {
        data = std::string(data, 1);
    }
    return BigInteger(*this);
}

// 重载 *
BigInteger& BigInteger::operator*(const BigInteger &bi)
{
    return *this;
}

// 重载 /
BigInteger& BigInteger::operator/(const BigInteger &bi)
{
    return *this;
}

// 重载 ==
bool BigInteger::operator==(const BigInteger &bi)
{
    return data == bi.data;
}

// 重载 <
bool BigInteger::operator<(const BigInteger &bi)
{
    // 相等，包含同为0的情况
    if (data == bi.data) return false; 

    // 异号
    if(this->getSign() < bi.getSign()) return true;
    if(this->getSign() > bi.getSign()) return false;
    

    // 都为正
    if (this->getSign() > 0) {
        if (data.length() > bi.data.length()) {
            return false;
        } else if (data.length() < bi.data.length()) {
            return true;
        } else { // 等长
            return data < bi.data;
        }
    }

    // 都为负
    if (data.length() > bi.data.length()) {
        return true;
    } else if (data.length() < bi.data.length()) {
        return false;
    } else { // 等长
        return data > bi.data;
    }

}

bool BigInteger::operator<=(const BigInteger &bi)
{
    return *this == bi || *this < bi;
}

bool BigInteger::operator>(const BigInteger &bi)
{
    return !(*this <= bi);
}

bool BigInteger::operator>=(const BigInteger &bi)
{
    return !(*this < bi);
}

bool BigInteger::operator!=(const BigInteger &bi)
{
    return !(*this == bi);
}

// 正数返回1，负数返回-1，零返回0
int BigInteger::getSign() const
{
    switch (data[0]) {
        case '0': return 0;
        case '-': return -1;
    }
    return 1;
}
