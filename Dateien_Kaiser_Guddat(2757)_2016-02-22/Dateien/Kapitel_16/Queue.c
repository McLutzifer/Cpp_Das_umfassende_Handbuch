# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define OK 1
# define OVERFLOW -1
# define EMPTY 0

struct queue
   {
   char *que;
   int qsize;
   int esize;
   int first;
   int anz;
   };

struct queue *queue_construct( int qsiz, int esiz )
   {
   struct queue *q;
   q = ( struct queue * )malloc( sizeof( struct queue ) );
   q->que = ( char * ) malloc( qsiz*esiz );
   q->qsize = qsiz;
   q->esize = esiz;
   q->first = 0;
   q->anz = 0;
   return q;
   }

void queue_destruct( struct queue *q )
   {
   free( q->que );
   free( q );
   }

int queue_isempty( struct queue *q )
   {
   return q->anz == 0;
   }

int queue_put( struct queue *q, void *v )
   {
   if( q->anz >= q->qsize )
      return OVERFLOW;
   memcpy( q->que + ( ( q->first + q->anz )*q->esize ) % q->qsize, v, q->esize );
   q->anz++;
   return OK;
   }

int queue_get( struct queue *q, void *v )
   {
   if( !q->anz )
      return EMPTY;
   memcpy( v, q->que + q->first*q->esize, q->esize );
   q->first = ( q->first + 1 ) % q->qsize;
   q->anz--;
   return OK;
   }

struct test
   {
   int i1;
   int i2;
   };

void main()
   {
   struct queue *myqueue;
   int i;
   struct test t;

   srand( 12345 );

   myqueue = queue_construct( 100, sizeof( struct test ) );
   for( i = 0; i < 5; i++ )
      {
      t.i1 = rand() % 1000;
      t.i2 = rand() % 1000;
      printf( "(%3d, %3d) ", t.i1, t.i2 );
      queue_put( myqueue, &t );
      }
   printf( "\n" );
   while( !queue_isempty( myqueue ) )
      {
      queue_get( myqueue, &t );
      printf( "(%3d, %3d) ", t.i1, t.i2 );
      }
   printf( "\n" );
   queue_destruct( myqueue );
   }

