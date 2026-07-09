#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using namespace std;

class Number {
public:
    virtual int toDecimal() const = 0;
    virtual string toBinary() const = 0;
    virtual string toHex() const = 0;
    virtual void print() const = 0;

    virtual ~Number() = default;
};

#endif