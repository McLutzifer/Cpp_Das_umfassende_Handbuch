#include <iostream>
#include <exception>
using namespace std;

int eingabe()
   {
   int i;

   cout << "Bitte eine positive Zahl eingeben: ";
   cin >> i;
   if (i < 0)
      throw out_of_range( "Negativer Wert eingegeben" );

   return i;
   }


int main()
   {
   try {
      int i = eingabe();
      cout << "Erfolg: " << i << '\n';
      }

   catch (out_of_range ausnahme)
      {
      cout << "Ausnahme 'Out of range'  abgefangen: "
           << ausnahme.what() << '\n';
      }
      
   catch (exception ausnahme)
      {
      cout << "Unbekannte Ausnahme abgefangen: " << ausnahme.what() << '\n';
      }
   return 0;
   }
