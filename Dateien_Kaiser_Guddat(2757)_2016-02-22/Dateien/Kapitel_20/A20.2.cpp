
#include <cstdlib>
#include <iostream>

#include "datum.h"

using namespace std;

void main()
   {
   int i;

   cout << "Test der Konstruktoren und der Ausgabe:\n";
   datum dat1;
   datum dat2( 24, 12, 2014 );
   datum dat3( 28, 12, 2014, 1 );
   cout << dat1 << '\n' << dat2 << '\n' << dat3 << '\n';

   cout << "\nTest des \"+\" Operators:\n";
   for( i = 0; i < 6; i++ )
      {
      dat3 = dat3 + 1;
      cout << dat3 << '\n';
      }

   cout << "\nTest des \"-\" Operators zwischen zwei Daten:\n";
   cout << dat3 << " - " << dat2 << " = " << dat3 - dat2 << '\n';

   cout << "\nTest der Vergleichoperatoren \"== < >\"\n";
   cout << dat3 << " == " << dat2 << " : " << ( dat3 == dat2 ) << '\n';
   cout << dat3 << "  < " << dat2 << " : " << ( dat3 < dat2 ) << '\n';
   cout << dat3 << "  > " << dat2 << " : " << ( dat3 > dat2 ) << '\n';

   cout << "\nTest der Wochentagsberechnung:\n";
   cout << dat2 << " ist ein ";
   switch( dat2.wochentag() )
      {
      case 0: cout << "Montag\n";     break;
      case 1: cout << "Dienstag\n";   break;
      case 2: cout << "Mittwoch\n";   break;
      case 3: cout << "Donnerstag\n"; break;
      case 4: cout << "Freitag\n";    break;
      case 5: cout << "Samstag\n";    break;
      case 6: cout << "Sonntag\n";    break;
      }

   cout << "\nTest der Feiertagsbestimmung:\n";
   dat1.setDatum( 25, 12, 2002 );
   cout << "Der " << dat1 << ( dat1.feiertag() ? " ist ein" : " ist kein" ) << " Feiertag\n";
   cout << "Der " << dat2 << ( dat2.feiertag() ? " ist ein" : " ist kein" ) << " Feiertag\n";
   cout << "Der " << dat3 << ( dat3.feiertag() ? " ist ein" : " ist kein" ) << " Feiertag\n";
   cout << "Der " << ( dat3 + ( -2 ) ) << ( ( dat3 + ( -2 ) ).feiertag() ? " ist ein" : " ist kein" ) << " Feiertag\n";
   cout << '\n';
   }
