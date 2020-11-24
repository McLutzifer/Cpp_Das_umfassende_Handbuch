#include <iostream>
#include <iomanip>                 // fixed, setprecision
using std::cout;                   // Abkürzung cout
int main() {
    cout << std::fixed             // Punktschreibweise, nicht wissenschaftlich
         << std::setprecision(15); // 15 Nachkommastellen
    cout << 0.5 << "\n";           // Ausgabe: 0.500000000000000
    cout << std::setprecision(5);  // 5 Nachkommastellen
    cout << 0.25 << "\n";          // Ausgabe: 0.25000
    return 0;
}

