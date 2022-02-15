# include <stdio.h>
# include <stdlib.h>


struct node
   {
   struct node *left;
   struct node *right;
   int value;
   };


/* Knoten des Levels 4 */
struct node n08 = { 0, 0, 8 };
struct node n12 = { 0, 0, 12 };
struct node n24 = { 0, 0, 24 };
struct node n28 = { 0, 0, 28 };

/* Knoten des Levels 3 */
struct node n02 = { 0, 0, 2 };
struct node n10 = { &n08, &n12, 10 };
struct node n20 = { 0, 0, 20 };
struct node n26 = { &n24, &n28, 26 };

/* Knoten des Levels 2 */
struct node n04 = { &n02, 0, 4 };
struct node n14 = { &n10, 0, 14 };
struct node n22 = { &n20, &n26, 22 };

/* Knoten des Levels 1 */
struct node n06 = { &n04, &n14, 6 };
struct node n18 = { 0, &n22, 18 };

/* Wurzel */
struct node n16 = { &n06, &n18, 16 };

# undef REKURSIV

# ifdef REKURSIV

void preorder( struct node *n )
   {
   if( n )
      {
      printf( " %2d", n->value );
      preorder( n->left );
      preorder( n->right );
      }
   }

# else

void preorder( struct node *n )
   {
   struct node *stack[100];
   int pos = 0;

   stack[pos++] = n;
   while( pos )
      {
      n = stack[--pos];
      if( n )
         {
         printf( " %2d", n->value );
         stack[pos++] = n->right;
         stack[pos++] = n->left;
         }
      }
   }

# endif

void levelorder( struct node *n )
   {
   struct node *queue[100];
   int first = 0, last = 0;

   queue[last++] = n;
   while( first < last )
      {
      n = queue[first++];
      if( n )
         {
         printf( " %2d", n->value );
         queue[last++] = n->left;
         queue[last++] = n->right;
         }
      }
   }


void inorder( struct node *n )
   {
   if( n )
      {
      inorder( n->left );
      printf( " %2d", n->value );
      inorder( n->right );
      }
   }

void postorder( struct node *n )
   {
   if( n )
      {
      postorder( n->left );
      postorder( n->right );
      printf( " %2d", n->value );
      }
   }

void find( struct node *n, int v )
   {
   while( n )
      {
      if( n->value == v )
         {
         printf( " %d gefunden\n", v );
         return;
         }
      if( v < n->value )
         {
         printf( " %2d->li", n->value );
         n = n->left;
         }
      else
         {
         printf( " %2d->re", n->value );
         n = n->right;
         }
      }
   printf( " %d nicht gefunden\n", v );
   }


void main()
   {
   int i;

   printf( "Preorder:\n" );
   preorder( &n16 );
   printf( "\n\n" );

   printf( "Inorder:\n" );
   inorder( &n16 );
   printf( "\n\n" );

   printf( "Postorder:\n" );
   postorder( &n16 );
   printf( "\n\n" );

   printf( "Levelorder:\n" );
   levelorder( &n16 );
   printf( "\n\n" );

   for( i = 1; i <= 28; i++ )
      {
      printf( "Suche %2d ", i );
      find( &n16, i );
      }
   }
