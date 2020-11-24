#include <array>
#include <iostream>
using std::cout; using std::array; using std::string;
int main() {
  array<string,7> wotag = { "Montag", "Dienstag",        // definieren
      "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag" };
  cout << "Die Woche beginnt mit " << wotag[0] << ".\n"; // Werte lesen
  cout << "Sie endet mit " << wotag.at(6) << ".\n";      // Werte sicher lesen
  /* nordisch? */
  wotag[5] = "Sonnabend";                                // Werte verändern
}

