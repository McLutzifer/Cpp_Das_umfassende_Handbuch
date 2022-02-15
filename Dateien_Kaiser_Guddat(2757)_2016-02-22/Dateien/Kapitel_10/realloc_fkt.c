# include <stdlib.h>
# include <stdio.h>

int main()
   {
   int size = 0, increment = 2;
   int anz, i, z;
   int *p = 0;

   for (anz = 0; ; anz++)
      {
      printf( "%d. Zahl: ", anz + 1 );
      scanf( "%d", &z );
      if (z == -1)
         break;
      if (anz >= size)
         {
         size = size + increment;
         p    = (int *)realloc( p, size * sizeof(int));
         printf( "Array auf %d Elemente vergroessert\n", size );
         }
      p[anz] = z;
      }
   for (i = anz - 1; i >= 0; i--)
      printf( "%d\n", p[i] );
   free( p );
   }
