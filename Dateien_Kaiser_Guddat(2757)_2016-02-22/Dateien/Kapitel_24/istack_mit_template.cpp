#include <iostream>
#include "stack.h"
using namespace std;

int main()
   {
   stack<int, 3> istack;
   for (int i = 1; i <= 5; i++)
      {
      istack.push( i );
      cout << "push: " << i << '\n';
      }
   while (!istack.isEmpty())
      {
      int i = istack.pop();
      cout << "pop: " << i << '\n';
      }

   return 0;
   }
