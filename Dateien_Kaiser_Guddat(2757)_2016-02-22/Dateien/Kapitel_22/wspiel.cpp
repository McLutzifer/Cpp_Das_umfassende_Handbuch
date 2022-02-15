# include <iostream>
# include <cstdlib>
# include <cstring>
# include <cmath>

using namespace std;

/*
** Wuerfelspiel (Kap. 22.3.1)
*/


/*
** wuerfel
*/
class wuerfel
   {
   public:
      wuerfel( int seed ) { srand( seed ); }
      int wurf() { return rand() % 6 + 1; }
   };

/*
** feld
*/

class feld {
private:
   feld *nxt;
   feld *prv;
protected:
   int besetzt[4];
   virtual feld *step( int fig, int steps );
public:
   feld( feld *ende );
   feld* getNext() { return nxt; }
   virtual char getTyp() { return '.'; }
   feld * figurSetzen( int fi, int wurf );
   virtual int blockiert( int fig ) { return 0; }
   };

feld::feld( feld *ende )
   {
   nxt = 0;
   prv = ende;
   if( ende )
      ende->nxt = this;
   besetzt[0] = besetzt[1] = besetzt[2] = besetzt[3] = 0;
   }

feld *feld::figurSetzen( int fig, int wurf )
   {
   if( !besetzt[fig] || blockiert( fig ) ) return 0;
   besetzt[fig] = 0;
   return step( fig, wurf );
   }

feld* feld::step( int fig, int steps ) {
   if( steps == 0 ) {
      besetzt[fig] = 1;
      return this;
      }

   if( ( ( steps > 0 ) && !nxt ) || ( ( steps<0 ) && !prv ) )
      steps = -steps;

   if( steps>0 )
      return nxt->step( fig, steps - 1 );
   else
      return prv->step( fig, steps + 1 );
   }

/*
** ziel
*/

class ziel: public feld
   {
   public:
      ziel( feld* ende ) : feld( ende ) {};
      char getTyp() { return 'Z'; }
   };

/*
** start
*/

class start: public feld
   {
   public:
      start() : feld( 0 ) {};
      char getTyp() { return 'S'; }
      void figurAufstellen( int fig ) { besetzt[fig] = 1; }
   };


/*
** sprung
*/

class sprung: public feld
   {
   private:
      int offset;
      feld *step( int fig, int steps );
   public:
      sprung( feld * ende, int off ) : feld( ende ) { offset = off; } char getTyp() { return offset > 0 ? '+' : '-'; }
   };

feld* sprung::step( int fig, int steps )
   {
   if( steps == 0 ) steps = offset;
   return feld::step( fig, steps );
   }

/*
** warte
*/

class warte: public feld
   {
   protected:
      int timeout;
      int wait[4];
      feld *step( int fig, int steps );
   public:
      warte( feld* ende, int t ) : feld( ende ) { timeout = t; } char getTyp() { return 'W'; }
      int blockiert( int fig );
   };

int warte::blockiert( int fig )
   {
   if( wait[fig] )
      {
      wait[fig]--;
      return 1;
      }
   return 0;
   }

feld * warte::step( int fig, int steps )
   {
   if( steps == 0 )
      wait[fig] = timeout;
   return feld::step( fig, steps );
   }

/*
** figur
*/
class figur {
   friend class spiel;
private:
   feld * pos;
   int nummer;
public:
   figur() { pos = 0; }
   void ziehen( int wurf ) {
      pos = pos->figurSetzen( nummer, wurf );
      }
   };

/*
** spieler
*/

class spieler
   {
   private:
      char name[20];
      spiel * game;
      figur *fig;
   public:
      spieler( char *n, spiel *s );
      char * getName() { return name; }
      void zug();
   };

/*
** spiel
*/

class spiel {
private:
   int anzSpieler;
   spieler *player[4];
   start *startfeld;
   int spielrunde();
public:
   wuerfel w;
   figur fig[4];
   spiel( int seed );
   figur *anmeldung( spieler *sp );
   void spielstand();
   void partie();
   ~spiel();
   };

spiel::spiel( int seed ) : w( seed ) {
   feld *last;
   last = startfeld = new start();
   last = new feld( last );
   last = new feld( last );
   last = new warte( last, 2 );
   last = new feld( last );
   last = new feld( last );
   last = new sprung( last, -3 );
   last = new feld( last );
   last = new feld( last );
   last = new sprung( last, +3 );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new warte( last, 2 );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new warte( last, 2 );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new feld( last );
   last = new sprung( last, -3 );
   last = new ziel( last );
   anzSpieler = 0;
   }

spiel::~spiel()
   {
   feld *f, *t;
   for( f = startfeld; t = f; )
      {
      f = f->getNext();
      delete t;
      }
   }

int spiel::spielrunde()
   {
   int sp;
   for( sp = 0; sp < anzSpieler; sp++ )
      {
      if( !fig[sp].pos->blockiert( sp ) )
         {
         player[sp]->zug();
         if( fig[sp].pos->getTyp() == 'Z' )
            {
            cout << '\n';
            return 0;
            }
         }
      }
   cout << '\n';
   return 1;
   }

void spiel::partie()
   {
   do {
      spielstand();
      } while( spielrunde() );
   spielstand();
   }

void spiel::spielstand()
   {
   feld *fld;
   int fg;
   for( fld = startfeld; fld; fld = fld->getNext() )
      cout << fld->getTyp();
   cout << '\n';
   for( fg = 0; fg < 4; fg++ )
      {
      for( fld = startfeld; fld; fld = fld->getNext() )
         {
         if( fld == fig[fg].pos )
            cout << *( player[fg]->getName() );
         else
            cout << '-';
         }
      cout << '\n';
      }
   cout << '\n';
   }


figur * spiel::anmeldung( spieler *sp ) {
   if( anzSpieler >= 4 ) return 0;
   player[anzSpieler] = sp;
   fig[anzSpieler].nummer = anzSpieler;
   startfeld->figurAufstellen( anzSpieler );
   fig[anzSpieler].pos = startfeld;
   cout << anzSpieler + 1 << ".ter Spieler ist " << sp->getName() << '\n';

   anzSpieler++;
   return fig + anzSpieler - 1;
   }

/*
** Methoden von spieler, die Methoden von spiel aufrufen
*/

spieler::spieler( char *n, spiel *s )
   {
   strcpy( name, n );
   game = s;
   fig = game->anmeldung( this );
   }

void spieler::zug()
   {
   int wurf;
   wurf = game->w.wurf();
   cout << *name << '=' << wurf << ' ';
   fig->ziehen( wurf );
   }

/*
** Hauptprogramm
*/

int main() {
   spiel sp( 1234 );
   spieler anton( "Anton", &sp ); spieler berta( "Berta", &sp ); spieler claus( "Claus", &sp ); spieler doris( "Doris", &sp ); cout << '\n';
   sp.partie(); return 0;
   }

