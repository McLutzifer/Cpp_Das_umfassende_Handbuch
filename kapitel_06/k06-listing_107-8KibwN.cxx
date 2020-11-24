#include <iostream> // cerr
#include <fstream>
int main(int argc, char* argv[]) {
    int wert;
    std::ifstream meineEingabe{"input1.txt"};
    if(!meineEingabe) {
        std::cerr << "Fehler beim Öffnen der Datei!\n";
    } else {
        meineEingabe >> wert;
    }
}

