#include "komplex.h"

komplex::komplex() //Konstructor
   {
   re = 0;
   im = 0;
   }

komplex::komplex( float x, float y ) //Konstructor
   {
   re = x;
   im = y;
   }

ostream& operator<<( ostream& os, komplex& Z ) //Ausgabe Komplexe Zahl
   {
   os << " " << Z.re << " + " << Z.im << "i " << "\n";

   return os;
   }

komplex komplex::operator+( komplex& Z2 )
   {
   komplex Z;

   Z.re = re + Z2.re;
   Z.im = im + Z2.im;

   return Z;
   }

komplex komplex::operator*( komplex& Z2 )
   {
   komplex Z;

   Z.re = ( re * Z2.re ) - ( im * Z2.im );
   Z.im = ( re * Z2.im ) + ( im * Z2.re );

   return Z;
   }

komplex komplex::operator*( float a )
   {
   komplex Z;

   Z.re = re * a;
   Z.im = im * a;

   return Z;
   }

komplex komplex::operator-( komplex& Z2 )
   {
   komplex Z;

   Z.re = re - Z2.re;
   Z.im = im - Z2.im;

   return Z;
   }

komplex komplex::operator/( float a )
   {
   komplex Z;

   Z.re = re / a;
   Z.im = im / a;

   return Z;
   }

float abs( komplex& Z )
   {
   float abs;

   abs = ( float ) sqrt( ( Z.re*Z.re ) + ( Z.im*Z.im ) );

   return abs;
   }
