#include <iostream>
#include "stack.h"
using namespace std;


class datum {
   friend ostream& operator<<( ostream& os, const datum& d );

   public:
      int tag;
      int monat;
      int jahr;
      void set( int t, int m, int j ) {tag = t; monat = m; jahr = j; }
   };

ostream& operator<<( ostream& os, const datum& d )
   {
   os << d.tag << '.' << d.monat << '.' << d.jahr;
   return os;
   }


int main()
   {
   datum dat;

   stack<datum, 10> dstack;

   for (int i = 1; i <= 5; i++)
      {
      dat.set( i, 1, 2015 );
      dstack.push( dat );
      cout << "push: " << dat << '\n';
      }
   while (!dstack.isEmpty())
      {
      dat = dstack.pop();
      cout << "pop: " << dat << '\n';
      }
   return 0;
   }
