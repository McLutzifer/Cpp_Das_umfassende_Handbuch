#include <iostream>
#include <exception>

using namespace std;


void test1( int i );
void test2( int i );
void test3( int i );

void test1( int i )
   {
   cout << "Aufruf von test2(" << i << ")\n";
   test2( i );
   }


void test2( int i )
   {
   cout << "Aufruf von test3(" << i << ")\n";
   try{
      test3( i );
      }
   catch (runtime_error e)
      {
      cout << "test2 faengt und wirft weiter: " << e.what() << '\n';
      throw;
      }
   }


void test3( int i )
   {
   switch (i % 3)
      {
   case 0:
      return;

   case 1:
      cout << "AUSNAHME1 wird geworfen\n";
      throw runtime_error( "AUSNAHME1" );

   case 2:
      cout << "AUSNAHME2 wird geworfen\n";
      throw logic_error( "AUSNAHME2" );
      }
   }



int main()
   {
   int i;

   for (i = 0; i < 4; i++)
      {
      try{
         cout << "Aufruf von test1(" << i << ")\n";
         test1( i );
         cout << "Kein Ausnahmefall aufgetreten\n";
         }
      catch (exception e)
         {
         cout << "main faengt: " << e.what() << '\n';
         }
      }
   return 0;
   }
