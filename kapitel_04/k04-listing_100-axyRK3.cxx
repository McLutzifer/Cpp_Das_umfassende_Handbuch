#include <iostream>                         // Module/Bibliotheken einbinden
int main()                                  // main() ist der Beginn des Programms
{
    int wert = 100;                         // Variable mit Anfangswert
    std::cout << "Teiler von " << wert << " sind:\n";    // Ausgabe von Text
    for(int teiler=1; teiler <= wert; teiler = teiler+1) // Schleife von 1 bis 100
    {                                       // hier beginnt der Wiederholungsteil
        if(wert % teiler == 0)              // Test für eine bedingte Ausführung
            std::cout << teiler << ", ";    // nur bei positivem Test
    }                                       // Ende der Schleife
    std::cout << "\n";                      // einmalige Ausgabe
    return 0;                               // bedeutet in main() Programmende
}                                           // Ende von main()

