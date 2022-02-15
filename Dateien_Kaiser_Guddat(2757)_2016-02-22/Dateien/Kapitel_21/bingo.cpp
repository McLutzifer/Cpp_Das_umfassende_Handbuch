# include <cstdlib>
# include "set.h"

/*
** Bingo (Kap. 21.4.1
*/

class lostrommel
   {
   private:
      int anzahl;
      set trommel;
   public:
      lostrommel( int max );
      int ziehen();
   };

lostrommel::lostrommel( int max )
   {
   int i;

   anzahl = max + 1;
   for( i = 0; i < anzahl; i++ )
      trommel += i;
   }

int lostrommel::ziehen()
   {
   int z, i, x;

   if( !anzahl )
      return -1;
   z = rand() % anzahl;
   for( x = 0, i = 0; i <= z; x++ )
      {
      if( x < trommel )
         i++;
      }
   x--;
   trommel -= x;
   anzahl--;
   return x;
   }

class spieler
   {
   friend ostream& operator<<( ostream& os, spieler& sp );
   private:
      char name[20];
      set karte;
   public:
      void init( int anz, int max );
      void streiche( int z ) { karte -= z; }
      int bingo() { return !karte; }
      char *get_name() { return name; }
   };

ostream& operator<<( ostream& os, spieler& sp )
   {
   return os << sp.name << ": " << sp.karte;
   }

void spieler::init( int k, int max )
   {
   char inter;
   int z;

   cout << "Name: ";
   cin >> name;
   cout << "Interaktiv (j/n): ";
   cin >> inter;
   if( inter == 'j' )
      {
      while( k )
         {
         cout << "Zahl: ";
         cin >> z;
         if( ( z >= 0 ) && ( z <= max ) && ( z < karte ) )
            {
            karte += z;
            k--;
            }
         }
      }
   else
      {
      lostrommel ltr( max );
      for( ; k; k-- )
         karte += ltr.ziehen();
      }
   cout << *this;
   }


class leiter
   {
   private:
      int anzahl;
      spieler *teilnehmer;
      lostrommel trommel;
   public:
      leiter( int anz, int karte, int max );
      ~leiter();
      void spiel();
   };

leiter::leiter( int anz, int karte, int max ) : trommel( max )
   {
   teilnehmer = new spieler[anz];
   for( anzahl = 0; anzahl < anz; anzahl++ )
      teilnehmer[anzahl].init( karte, max );
   }

leiter::~leiter()
   {
   delete[] teilnehmer;
   }

void leiter::spiel()
   {
   int fertig, sp, z;

   for( fertig = 0; !fertig; )
      {
      z = trommel.ziehen();
      cout << "Gezogen: " << z << '\n';
      for( sp = 0; sp < anzahl; sp++ )
         {
         teilnehmer[sp].streiche( z );
         cout << teilnehmer[sp];
         }
      for( sp = 0; sp < anzahl; sp++ )
         {
         if( teilnehmer[sp].bingo() )
            {
            cout << "BINGO - " << teilnehmer[sp].get_name() << '\n';
            fertig = 1;
            }
         }
      }

   }

void main()
   {
   int seed, anzahl, karte, maximum;

   cout << "Startwert fuer Z-Generator: ";
   cin >> seed;
   srand( seed );
   cout << "Anzahl Teilnehmer: ";
   cin >> anzahl;
   cout << "Kartengroesse: ";
   cin >> karte;
   cout << "Maximum: ";
   cin >> maximum;
   if( maximum > 63 )
      maximum = 63;
   if( karte > maximum + 1 )
      karte = maximum + 1;

   leiter ltr( anzahl, karte, maximum );
   ltr.spiel();
   }

