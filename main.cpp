#include <iostream>
#include "Binary.h"
#include "hexadecimal.h"
#include "simpleException.h"

using namespace std;

int main() {
    try {
        Binary b1("10101111111111111");
        Binary b2("0011");

        Binary b3 = b1 + b2;

        cout << "b1 = " << b1 << endl;
        cout << "b2 = " << b2 << endl;
        cout << "b1 + b2 = " << b3 << endl;
        cout<< b1.toDecimal()<<endl;

        if (b1 > b2)
            cout << "b1 > b2\n";

        hexadecimal h1("A");
        hexadecimal h2("5");

        hexadecimal h3 = h1 + h2;

        cout << "h1 = " << h1 << endl;
        cout << "h2 = " << h2 << endl;
        cout << "h1 + h2 = " << h3 << endl;

        Number* n = new Binary("1111");
        cout << "Decimal: " << n->toDecimal() << endl;
        delete n;

    } catch (const simpleException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}