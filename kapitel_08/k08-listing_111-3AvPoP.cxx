#include <iostream>
#include <string>

using std::string; using std::cout;

void rateMonat(unsigned welchenTagHabenwirHeute) {
    switch(welchenTagHabenwirHeute) {
    /* fehlende break-Anweisungen: Fall-through beabsichtigt */
    default:
        if(welchenTagHabenwirHeute>31) {
            cout << "Sie schummeln";
            break;
        }
    case 28:
    case 29:
        cout << "Feb ";
    case 30:
        cout << "Apr Jun Sep Nov ";
    case 31:
        cout << "Jan Mar Mai Jul Aug Okt Dez ";
    }

    cout << ".\n";
}
int main() {
    rateMonat(31); // wenn wir heute den 31. hätten?
    // Ausgabe: Jan Mar Mai Jul Aug Okt Dez .
    rateMonat(30); // wenn es der 30. wäre?
    // Ausgabe: Apr Jun Sep Nov Jan Mar Mai Jul Aug Okt Dez .
    rateMonat(4);
    // Ausgabe: Feb Apr Jun Sep Nov Jan Mar Mai Jul Aug Okt Dez .
    rateMonat(77);
    // Ausgabe: Sie schummeln.
}

