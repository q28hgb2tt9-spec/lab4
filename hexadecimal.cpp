#include "hexadecimal.h"
#include "Binary.h"
#include "simpleException.h"
#include <cctype>

static bool isHexString(const string& s) {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c) && !(toupper(c) >= 'A' && toupper(c) <= 'F')) {
            return false;
        }
    }
    return true;
}

hexadecimal::hexadecimal() : value("0") {}
hexadecimal::hexadecimal(string v) : value(v) {
    if (!isHexString(value)) {
        throw simpleException("Invalid hexadecimal number: " + value);
    }
}
hexadecimal::hexadecimal(const hexadecimal& other) {
    value = other.value;
}
hexadecimal::~hexadecimal() {}

int hexadecimal::toDecimal() const {
    int result = 0;
    for (char c : value) {
        result *= 16;

        if (isdigit(c))
            result += c - '0';
        else
            result += toupper(c) - 'A' + 10;
    }
    return result;
}

string hexadecimal::toBinary() const {
    return Binary::decimalToBinary(toDecimal());
}

string hexadecimal::toHex() const {
    return value;
}

string hexadecimal::decimalToHex(int num) {
    if (num == 0) return "0";
    string res = "";
    char digits[] = "0123456789ABCDEF";

    while (num > 0) {
        res = digits[num % 16] + res;
        num /= 16;
    }
    return res;
}

void hexadecimal::print() const {
    cout << "Hex: " << value;
}

hexadecimal hexadecimal::operator+(const hexadecimal& other) {
    int sum = toDecimal() + other.toDecimal();
    return hexadecimal(decimalToHex(sum));
}

hexadecimal hexadecimal::operator-(const hexadecimal& other) {
    int diff = toDecimal() - other.toDecimal();
    return hexadecimal(decimalToHex(diff));
}

bool hexadecimal::operator>(const hexadecimal& other) {
    return toDecimal() > other.toDecimal();
}

bool hexadecimal::operator==(const hexadecimal& other) {
    return toDecimal() == other.toDecimal();
}

ostream& operator<<(ostream& out, const hexadecimal& obj) {
    out << obj.value;
    return out;
}

istream& operator>>(istream& in, hexadecimal& obj) {
    string temp;
    in >> temp;
    if (!isHexString(temp)) {
        throw simpleException("Invalid hexadecimal number: " + temp);
    }
    obj.value = temp;
    return in;
}