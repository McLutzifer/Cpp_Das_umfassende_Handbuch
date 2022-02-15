# ifndef __ENIGMA_H__
# define __ENIGMA_H__

//Objekt Steckbrett
class steckbrett
   {
   //friend ostream& operator<<(ostream& os, enigma& e);//Nur für Testausgaben

   private:
      int s[26];

   public:
      steckbrett( int *steck );

      inline int hin( int links );
      inline int zur( int links );
   };

//Objekt Rotor

class rotor
   {
   //friend ostream& operator<<(ostream& os, enigma& e);

   private:
      int r[26];
      int r_akt;
      rotor *next;

   public:
      rotor( int *rr, rotor *n, int r_a );

      void set_pos( int r_a );
      inline int akt() { return r_akt; }

      inline int hin( int links );
      inline int zur( int rechts );
      inline int diff( int val );

      void mov();
   };


//Objekt Reflektor
class reflektor
   {
   //friend ostream& operator<<(ostream& os, enigma& e);

   private:
      int r[26];

   public:
      reflektor( int *ref );

      inline int hin( int links );
   };

//********************************************
//Objekt Enigma
//********************************************

class enigma
   {
   friend ostream& operator<<( ostream& os, enigma& e );

   private:
      steckbrett *steckb;
      rotor *r1;
      rotor *r2;
      rotor *r3;
      reflektor *refl;
      char *text;

   public:
      enigma( int *steck,
              int *r_1, int *r_2, int *r_3,
              int r1_a, int r2_a, int r3_a,
              int *ref );
      ~enigma();

      char* work( char *c );
   };

# endif