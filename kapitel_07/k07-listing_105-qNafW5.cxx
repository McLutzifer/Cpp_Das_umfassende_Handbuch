#include <iostream>
double verdopple(double zahl) {     // Wertparameter und Rückgabewert
    return zahl * 2.0;
}
int main() {
    double zahl = 7.25;
    zahl = verdopple(zahl);        // Änderung ausgedrückt durch Rückgabewert
    std::cout << zahl << "\n";     // auch 14.5
}

