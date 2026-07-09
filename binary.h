#ifndef BINARY_H
#define BINARY_H

#include "Number.h"
#include <iostream>
using namespace std;

class Binary : public Number {
private:
    string value;

public:
    Binary();
    Binary(string v);
    Binary(const Binary& other);
    ~Binary() override;

    int toDecimal() const override;
    string toBinary() const override;
    string toHex() const override;
    void print() const override;

    static string decimalToBinary(int num);

    Binary operator+(const Binary& other);
    Binary operator-(const Binary& other);

    bool operator>(const Binary& other);
    bool operator>=(const Binary& other);
    bool operator<(const Binary& other);
    bool operator<=(const Binary& other);
    bool operator==(const Binary& other);
    bool operator!=(const Binary& other);

    friend ostream& operator<<(ostream& out, const Binary& obj);
    friend istream& operator>>(istream& in, Binary& obj);
};

#endif