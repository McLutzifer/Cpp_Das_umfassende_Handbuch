#include <iostream> // cout, cerr
#include <fstream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::cerr;

int zaehleWoerter(const string& filename) { // Rückgabe kleiner 0 bei Fehler
    std::ifstream file{filename};
    if(!file) {          // Gab es einen Fehler beim Öffnen der Datei?
        cerr << "Fehler beim Oeffnen von " << filename << "\n";
        return -1;       // dem Aufrufer einen Fehler mittels besonderem Wert anzeigen
    }
    int count = 0;
    string wort;
    while(!file.eof()) { // noch nicht am Ende?
        file >> wort;
        ++count;
    }
    return count-1;      // @MINUS@1: am EOF wurde noch ein Wort gelesen
}
bool process(const vector<string>& args) { // Rückgabe true bei alles okay
    if(args.size() == 0) {  // erwarten Parameter
        cerr << "Kommandozeilenargument fehlt\n";
        return false;       // mittels Rückgabe einen Fehler mitteilen
    } else {
        bool result = true; // fürs Endergebnis
        for(const string filename : args) {
            cout << filename << ": ";
            int count = zaehleWoerter(filename);
            if(count < 0) { // besondere Rückgabe zeigt Fehler an
                cout << "Fehler!\n";
                result = false;              // mindestens ein Fehler
            } else {
                cout << count << "\n";       // normales Ergebnis ausgeben
            }
        }
        return result;      // Gesamtergebnis zurückgeben
    }
}

int main(int argc, const char* argv[]) {
    bool result = process(  // Rückgabewert enthält Fehlerindikator
        {argv+1, argv+argc} ); // const char*[] nach vector<string>
    if(result) {            // Rückgabewert auswerten
        return 0;
    } else {
        cerr << "Es trat ein Fehler auf.\n";
        return 1;           // außen Fehler anzeigen
    }
}

