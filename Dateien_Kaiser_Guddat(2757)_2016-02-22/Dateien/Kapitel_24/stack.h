template < typename T, int SIZE > class stack
   {
   private:
      T   stck[SIZE];
      int top;

   public:
      stack()
         {
         top = 0;
         }
      int push( T element );
      T pop();

      int isEmpty() {return top == 0; }
   };
   
template < typename T, int SIZE > int stack < T, SIZE > ::push( T element )
   {
   if (top < SIZE)
      {
      stck[top] = element;
      top++;
      return 1;
      }
   return 0;
   }

template < typename T, int SIZE > T stack < T, SIZE > ::pop()
   {
   if (top > 0)
      top--;
   return stck[top];
   }
