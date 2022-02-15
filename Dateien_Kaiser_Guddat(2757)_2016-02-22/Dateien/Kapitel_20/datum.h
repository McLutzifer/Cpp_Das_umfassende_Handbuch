#ifndef __DATUM__H
#define __DATUM__H

using namespace std;

class datum
   {
   friend ostream& operator<<( ostream& os, const datum& dat );

   private:
      int tag;
      int mon;
      int jahr;
      short modus;

      int schaltjahr( int j );
      int datumOk( int tag, int mon, int jahr );
      unsigned int tageDesMonats( int mon, int jahr );
      unsigned int dat2Tage();
      void tage2Dat( unsigned long int tage );

   public:
      datum();
      datum( int t, int m, int j );
      datum( int t, int m, int j, int mod );

      void setDatum( int t, int m, int j );
      void setDatum( datum& neu );
      void setModus( int mod );

      datum operator+( int t );
      int operator-( datum& dat );
      int operator==( datum& dat );
      int operator>( datum& dat );
      int operator<( datum& dat );

      int wochentag();
      int feiertag();
   };

#endif
