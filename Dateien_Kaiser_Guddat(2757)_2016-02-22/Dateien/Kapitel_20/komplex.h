# ifndef __KOMPLEX_HPP
# define __KOMPLEX_HPP

# include <cmath>
# include <cstdlib>
# include <iostream>

using namespace std;

class komplex
   {
   friend ostream& operator<<( ostream& os, komplex& Z );
   friend float abs( komplex& Z );
   private:
      float re;
      float im;
   public:
      komplex();
      komplex( float x, float y );
      float getRe() { return re; }
      float getIm() { return im; }
      komplex operator+( komplex& Z2 );
      komplex operator*( komplex& Z2 );
      komplex operator*( float a );
      komplex operator-( komplex& Z2 );
      komplex operator/( float a );
   };

# endif