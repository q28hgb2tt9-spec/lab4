#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include "Number.h"
#include <iostream>
using namespace std;

class hexadecimal : public Number {
private:
    string value;

public:
    hexadecimal();
    hexadecimal(string v);
    hexadecimal(const hexadecimal& other);
    ~hexadecimal();

    int toDecimal() const override;
    string toBinary() const override;
    string toHex() const override;
    void print() const override;

    static string decimalToHex(int num);

    hexadecimal operator+(const hexadecimal& other);
    hexadecimal operator-(const hexadecimal& other);

    bool operator>(const hexadecimal& other);
    bool operator==(const hexadecimal& other);

    friend ostream& operator<<(ostream& out, const hexadecimal& obj);
    friend istream& operator>>(istream& in, hexadecimal& obj);
};

#endif