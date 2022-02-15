# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define OK 1
# define OVERFLOW -1
# define EMPTY 0

struct stack
   {
   char *stck;
   int ssize;
   int esize;
   int pos;
   };

struct stack *stack_construct( int ssiz, int esiz )
   {
   struct stack *s;
   s = ( struct stack * )malloc( sizeof( struct stack ) );
   s->stck = ( char * ) malloc( ssiz*esiz );
   s->ssize = ssiz;
   s->esize = esiz;
   s->pos = 0;
   return s;
   }

void stack_destruct( struct stack *s )
   {
   free( s->stck );
   free( s );
   }

int stack_isempty( struct stack *s )
   {
   return s->pos == 0;
   }

int stack_push( struct stack *s, void *v )
   {
   if( s->pos >= s->ssize )
      return OVERFLOW;
   memcpy( s->stck + s->pos*s->esize, v, s->esize );
   s->pos++;
   return OK;
   }

int stack_pop( struct stack *s, void *v )
   {
   if( !s->pos )
      return EMPTY;
   s->pos--;
   memcpy( v, s->stck + s->pos*s->esize, s->esize );
   return OK;
   }

struct test
   {
   int i1;
   int i2;
   };

void main()
   {
   struct stack *mystack;
   struct test t;
   int i;

   srand( 12345 );

   mystack = stack_construct( 100, sizeof( struct test ) );
   for( i = 0; i < 5; i++ )
      {
      t.i1 = rand() % 1000;
      t.i2 = rand() % 1000;
      printf( "(%3d, %3d) ", t.i1, t.i2 );
      stack_push( mystack, &t );
      }
   printf( "\n" );
   while( !stack_isempty( mystack ) )
      {
      stack_pop( mystack, &t );
      printf( "(%3d, %3d) ", t.i1, t.i2 );
      }
   printf( "\n" );

   stack_destruct( mystack );
   }

