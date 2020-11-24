#include <iostream>                 // cin
#include <string>
int main() {
    std::string line;
    do {                            // mindestens einmal getline ausführen
       std::getline(std::cin, line);
       if(!std::cin) break;         // Fehler oder Dateiende
    } while(line != "quit");        // Ende bei bestimmter Eingabe
}

