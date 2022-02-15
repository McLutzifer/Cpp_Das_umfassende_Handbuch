# include <iostream>
# include <cstdlib>
# include <cstring>
# include <cmath>

using namespace std;


/*
** Partnervermittlung (Kap. 22.3.2)
*/


/*
** profil
*/

class profil {
public:
   int alter;
   double groesse;
   double vermoegen;
   profil( int a = 0, double gr = 0, double v = 0 ) { set( a, gr, v ); }
   void set( int a, double gr, double v ) { alter = a; groesse = gr; vermoegen = v; }
   };

/*
** Funktionen zur Messung der Profilabweichung
*/

double abweichung( double a, double b )
   {
   if( !a )
      return 0;
   return ( double ) fabs( a - b ) / a;
   }

double abweichung( profil &wunsch, profil &real ) {
   double sum = 0;
   sum = abweichung( wunsch.alter, real.alter );
   sum += abweichung( wunsch.groesse, real.groesse );

   if( wunsch.vermoegen > real.vermoegen )
      sum += abweichung( wunsch.vermoegen, real.vermoegen );

   return sum / 3;
   }

/*
** person
*/

class person
   {
   private:
      char name[20];
      char geschlecht;
   public:
      profil eigenprofil;
      person( char * n, char g, int a, double gr, double v );
      char *getName() { return name; }
      char getGeschlecht() { return geschlecht; }
   };

person::person( char * n, char g, int a, double gr, double v ) : eigenprofil( a, gr, v )
   {
   strcpy( name, n );
   geschlecht = g;
   }

/*
** kunde
*/

class kunde: public person
   {
   friend ostream& operator<<( ostream & os, kunde &k );
   protected:
      kunde* partner;
      double abw;
      void neuerPartner( kunde *k );
      virtual int akzeptiert( kunde *k );
      virtual int verbesserung( kunde *k );
   public:
      profil partnerprofil;
      kunde( char * n, char g, int a, double gr, double v );
      void trennung();
      int antrag( kunde *k );
      virtual int angebot( kunde *k );
   };


kunde::kunde( char *n, char g, int a, double gr, double v )
: person( n, g, a, gr, v ), partnerprofil()
   {
   partner = 0;
   }

int kunde::akzeptiert( kunde *k )
   {
   return abweichung( partnerprofil, k->eigenprofil ) < 0.25;
   }

void kunde::trennung()
   {
   cout << "Trennung: " << getName() << " >< " << partner->getName() << '\n';
   partner = 0;
   }

void kunde::neuerPartner( kunde *k )
   {
   if( partner )
      partner->trennung();
   partner = k;
   abw = abweichung( partnerprofil, k->eigenprofil );
   }

int kunde::verbesserung( kunde *k )
   {
   if( !akzeptiert( k ) )
      return 0;
   if( !partner )
      return 1;
   if( abweichung( partnerprofil, k->eigenprofil ) < abw )
      return 1;
   return 0;
   }

int kunde::angebot( kunde *k )
   {
   cout << "Angebot: " << getName() << " ?? " << k->getName() << '\n';
   if( !verbesserung( k ) )
      return 0;
   if( !k->antrag( this ) )
      return 0;
   neuerPartner( k );
   cout << "Partner: " << *this; return 1;
   }

int kunde::antrag( kunde *k )
   {
   if( !verbesserung( k ) )
      return 0;
   neuerPartner( k );
   return 1;
   }

ostream& operator << ( ostream &os, kunde &k )
   {
   os << k.getName();
   os << " == ";
   if( k.partner )
      os << k.partner->getName();
   else
      os << '-';
   os << '\n';
   return os;
   }

/*
** anspruchsvollerKunde
*/

class anspruchsvollerKunde: public kunde {
private:
   int akzeptiert( kunde *k );
public:
   anspruchsvollerKunde( char *n, char g, int a, double gr, double v ) : kunde( n, g, a, gr, v ) {}
   };

int anspruchsvollerKunde::akzeptiert( kunde *k ) {
   return abweichung( partnerprofil, k->eigenprofil ) < 0.10;
   }


/*
** bescheidenerKunde
*/

class bescheidenerKunde: public kunde {
private:
   int akzeptiert( kunde *k ) { return 1; }
public:
   bescheidenerKunde( char *n, char g, int a, double gr, double v ) : kunde( n, g, a, gr, v ) {}
   };


/*
** heiratsschwindler
*/

class heiratsschwindler: public kunde
   {
   private:
      int akzeptiert( kunde *k );
      int verbesserung( kunde *k );
   public:
      heiratsschwindler( char *n, char g, int a, double gr, double v ) : kunde( n, g, a, gr, v ) {}
      int angebot( kunde *k );
   };

int heiratsschwindler::akzeptiert( kunde *k ) {
   return k->eigenprofil.vermoegen >= 50000.00;
   }

int heiratsschwindler::verbesserung( kunde *k ) {
   if( !akzeptiert( k ) ) return 0;
   if( !partner ) return 1;
   return k->eigenprofil.vermoegen > partner->eigenprofil.vermoegen;
   }

int heiratsschwindler::angebot( kunde *k )
   {
   eigenprofil.set( k->partnerprofil.alter, eigenprofil.groesse,
                    k->partnerprofil.vermoegen );

   return kunde::angebot( k );
   }

/*
** partnervermittlung
*/

class partnervermittlung
   {
   private:
      kunde  *frauen[100];
      int anzahlF;
      kunde *maenner[100];
      int anzahlM;
   public:
      partnervermittlung();
      void anmeldung( kunde *k );
      void vermittlung();
      void ergebnis();
   };

partnervermittlung::partnervermittlung() {
   anzahlF = 0;
   anzahlM = 0;
   }

void partnervermittlung::anmeldung( kunde *k )
   {
   if( k->getGeschlecht() == 'm' )
      maenner[anzahlM++] = k;
   else
      frauen[anzahlF++] = k;
   }

void partnervermittlung::ergebnis()
   {
   int i;
   cout << "\nFrauen:\n";
   for( i = 0; i < anzahlF; i++ ) cout << " " << *frauen[i];
   cout << "\nMaenner:\n";
   for( i = 0; i < anzahlM; i++ )
      cout << "   " << *maenner[i];
   cout << '\n';
   }

void partnervermittlung::vermittlung()
   {
   int i, j;
   for( i = 0; i < anzahlM; i++ )
      {
      for( j = 0; j < anzahlF; j++ ) maenner[i]->angebot( frauen[j] );
      }
   for( i = 0; i < anzahlF; i++ )
      {
      for( j = 0; j < anzahlM; j++ ) frauen[i]->angebot( maenner[j] );
      }
   }

/*
** Hauptprogramm
*/

void main() {
   partnervermittlung pv;
   kunde anton( "Anton", 'm', 55, 1.75, 100000 );
   anton.partnerprofil.set( 50, 1.70, 0 );
   pv.anmeldung( &anton );

   kunde berta( "Berta", 'w', 50, 1.70, 60000 );
   berta.partnerprofil.set( 50, 1.80, 10000 );
   pv.anmeldung( &berta );

   heiratsschwindler claus( "Claus", 'm', 30, 1.80, 10000 );
   claus.partnerprofil.set( 25, 1.70, 0 );
   pv.anmeldung( &claus );

   anspruchsvollerKunde doris( "Doris", 'w', 60, 1.65, 100000 );
   doris.partnerprofil.set( 65, 1.80, 10000 );
   pv.anmeldung( &doris );

   bescheidenerKunde ernst( "Ernst", 'm', 50, 1.80, 8000 );
   ernst.partnerprofil.set( 50, 1.80, 20000 );
   pv.anmeldung( &ernst );

   pv.ergebnis();
   pv.vermittlung();
   pv.ergebnis();
   }