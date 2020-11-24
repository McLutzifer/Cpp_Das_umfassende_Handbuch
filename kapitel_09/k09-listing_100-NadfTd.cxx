#include <iostream>                 // cout
#include <string>
void drucke(int n) {                // Funktion drucke für Typ int
    std::cout << "Zahl:" << n << "\n";
}
void drucke(std::string s) {        // gleicher Name, anderer Typ
    std::cout << "Zeichenkette:" << s << "\n";
}
int main() {
    int zahl = 10;
    std::string name = "Bilbo";
    drucke(zahl);                   // ruft drucke(int) auf, zahl ist int
    drucke(name);                   // ruft drucke(string) auf, name ist string
    drucke(11 + 22);                // Ausdruck ist int
    drucke(name + " Baggins");      // Ausdruck ist string
}

