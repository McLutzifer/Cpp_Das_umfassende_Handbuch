#include <iostream>
int main() {
    int a = 3;
    int b = 7 + (a = 12) + 6;   // enthält eine Zuweisung
    std::cout << a << std::endl;
}

