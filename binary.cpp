#include <string>
#include "Binary.h"
#include "SimpleException.h"

static bool isBinaryString(const string& s) {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Конструкторы
Binary::Binary() : value("0") {}
Binary::Binary(string v) : value(v) {
    if (!isBinaryString(value)) {
        throw simpleException("Invalid binary number: " + value);
    }
}
Binary::Binary(const Binary& other) {
    value = other.value;
}
Binary::~Binary() {}

int Binary::toDecimal() const {
    int result = 0;
    for (char c : value) {
        result = result * 2 + (c - '0');
    }
    return result;
}

string Binary::toBinary() const {
    return value;
}

string Binary::decimalToBinary(int num) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res = char('0' + num % 2) + res;
        num /= 2;
    }
    return res;
}

string Binary::toHex() const {
    int num = toDecimal();
    string res = "";
    char digits[] = "0123456789ABCDEF";

    while (num > 0) {
        res = digits[num % 16] + res;
        num /= 16;
    }

    return res == "" ? "0" : res;
}

void Binary::print() const {
    cout << "Binary: " << value;
}


Binary Binary::operator+(const Binary& other) {
    int sum = toDecimal() + other.toDecimal();
    return Binary(decimalToBinary(sum));
}

Binary Binary::operator-(const Binary& other) {
    int diff = toDecimal() - other.toDecimal();
    return Binary(decimalToBinary(diff));
}

bool Binary::operator>(const Binary& other) {
    return toDecimal() > other.toDecimal();
}

bool Binary::operator>=(const Binary& other) {
    return toDecimal() >= other.toDecimal();
}

bool Binary::operator<(const Binary& other) {
    return toDecimal() < other.toDecimal();
}

bool Binary::operator<=(const Binary& other) {
    return toDecimal() <= other.toDecimal();
}

bool Binary::operator==(const Binary& other) {
    return toDecimal() == other.toDecimal();
}

bool Binary::operator!=(const Binary& other) {
    return toDecimal() != other.toDecimal();
}

// Потоки
ostream& operator<<(ostream& out, const Binary& obj) {
    out << obj.value;
    return out;
}

istream& operator>>(istream& in, Binary& obj) {
    string temp;
    in >> temp;
    if (!isBinaryString(temp)) {
        throw simpleException("Invalid binary number: " + temp);
    }
    obj.value = temp;
    return in;
}