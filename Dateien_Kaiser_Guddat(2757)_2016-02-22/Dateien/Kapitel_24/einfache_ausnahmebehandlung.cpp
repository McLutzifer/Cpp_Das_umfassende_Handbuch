#include <iostream>
using namespace std;

int eingabe()
   {
   int i;

   cout << "Bitte eine positive Zahl eingeben: ";
   cin >> i;
   if (i < 0)
      throw 'N';
   return i;
   }


int main()
   {
   try {
      int i = eingabe();
      }

   catch (char ausnahme)
      {
      if (ausnahme == 'N')
         cout << "Ausnahme 'Negativer Wert' abgefangen\n";
      else
         cout << "Unbekannte Ausnahme abgefangen\n";
      }
   return 0;
   }
