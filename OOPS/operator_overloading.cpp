#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    void print() {
        cout << real << "+" << imag << "i" << endl;
    }

    Complex operator+(Complex c) { // Operator overloading
        Complex temp;
        temp.real = c.real + real;
        temp.imag = c.imag + imag;
        return temp;
    }
};

int main() {
    Complex c1(5, 4);
    Complex c2(2, 5);
    Complex c3(1, 1);

    Complex c4; // Corrected: Declare c4 without parentheses
    c4 = c1 + c2 + c3; // Perform addition

    c4.print(); // Print the result

    return 0;
}
