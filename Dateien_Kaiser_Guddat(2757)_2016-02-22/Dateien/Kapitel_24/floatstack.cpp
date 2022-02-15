#include <iostream>
using namespace std;

class floatStack
   {
   private:
      float stck[100];
      int   top;

   public:
      floatStack() {top = 0; }
      int push( float element );
      float pop();

      int isEmpty() {return top == 0; }
   };

int floatStack::push( float element )
   {
   if (top < 100)
      {
      stck[top] = element;
      top++;
      return 1;
      }
   return 0;
   }


float floatStack::pop()
   {
   if (top > 0)
      top--;
   return stck[top];
   }


int  main()
   {
   floatStack fstack;

   for (int i = 1; i <= 5; i++)
      {
      float value = 1.1 * i;
      fstack.push( value );
      cout << "push: " << value << '\n';
      }

   while (!fstack.isEmpty())
      {
      float value = fstack.pop();
      cout << "pop: " << value << '\n';
      }

   return 0;
   }
