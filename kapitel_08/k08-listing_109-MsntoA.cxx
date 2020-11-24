#include <iostream>

int main() {
    /* Summiere 1 bis 100 auf */
    int summe = 0;
    int zahl = 1;                         // Initialisierung vor der Schleife
    for(  ; zahl <= 100; zahl=zahl+1) {   // leere Initialisierung
        summe = summe + zahl;
    }
    std::cout << zahl << std::endl;       // zahl gibt es nun noch außerhalb
}

