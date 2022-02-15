# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define REKURSIV

struct gegner
   {
   char *name;
   int spiele;
   };

struct treapnode
   {
   struct treapnode *left;
   struct treapnode *right;
   struct gegner *geg;
   unsigned int prio;
   };

struct treap
   {
   struct treapnode *root;
   };

struct treap *treap_create()
   {
   struct treap *t;

   t = ( struct treap * )malloc( sizeof( struct treap ) );
   t->root = 0;
   return t;
   }

void treap_rotate_right( struct treapnode **node )
   {
   struct treapnode *tn;

   tn = ( *node )->left;
   ( *node )->left = tn->right;
   tn->right = *node;
   *node = tn;
   }

void treap_rotate_left( struct treapnode **node )
   {
   struct treapnode *tn;

   tn = ( *node )->right;
   ( *node )->right = tn->left;
   tn->left = *node;
   *node = tn;
   }

# ifdef REKURSIV

int treap_insert_rek( struct treapnode **node, struct gegner *g )
   {
   int cmp;

   if( *node )
      {
      cmp = strcmp( g->name, ( *node )->geg->name );
      if( cmp > 0 )
         {
         if( !treap_insert_rek( &( ( *node )->right ), g ) )
            return 0;
         if( ( *node )->prio < ( *node )->right->prio )
            treap_rotate_left( node );
         return 1;
         }
      if( cmp < 0 )
         {
         if( !treap_insert_rek( &( ( *node )->left ), g ) )
            return 0;
         if( ( *node )->prio < ( *node )->left->prio )
            treap_rotate_right( node );
         return 1;
         }
      return 0;
      }
   *node = ( struct treapnode * ) malloc( sizeof( struct treapnode ) );
   ( *node )->left = 0;
   ( *node )->right = 0;
   ( *node )->geg = g;
   ( *node )->prio = rand();
   return 1;
   }

int treap_insert( struct treap *t, struct gegner *g )
   {
   return treap_insert_rek( &( t->root ), g );
   }

# else

struct stackentry
   {
   struct treapnode **node;
   int direction;
   };

int treap_insert( struct treap *t, struct gegner *g )
   {
   struct treapnode **node, *neu, *tn;
   int cmp;
   struct stackentry stack[256];
   int pos;

   for( pos = 0, node = &( t->root ); *node; pos++ )
      {
      stack[pos].node = node;
      cmp = strcmp( g->name, ( *node )->geg->name );
      if( !cmp )
         return 0;
      if( cmp < 0 )
         {
         node = &( ( *node )->left );
         stack[pos].direction = 0;
         }
      else
         {
         node = &( ( *node )->right );
         stack[pos].direction = 1;
         }
      }
   neu = ( struct treapnode * )malloc( sizeof( struct treapnode ) );
   neu->left = 0;
   neu->right = 0;
   neu->geg = g;
   neu->prio = rand();
   *node = neu;
   while( pos )
      {
      node = stack[--pos].node;
      if( stack[pos].direction == 0 )
         {
         if( ( *node )->prio < ( *node )->left->prio )
            {
            tn = ( *node )->left;
            ( *node )->left = tn->right;
            tn->right = *node;
            *node = tn;
            }
         }
      else
         {
         if( ( *node )->prio < ( *node )->right->prio )
            {
            tn = ( *node )->right;
            ( *node )->right = tn->left;
            tn->left = *node;
            *node = tn;
            }
         }
      }
   return 1;
   }



# endif

struct gegner *treap_find( struct treap *t, char *name )
   {
   struct treapnode *tn;
   int cmp;

   for( tn = t->root; tn; )
      {
      cmp = strcmp( name, tn->geg->name );
      if( cmp == 0 )
         return tn->geg;
      if( cmp < 0 )
         tn = tn->left;
      else
         tn = tn->right;
      }
   return 0;
   }

float dcount;

void treap_shownode( struct treapnode *tn, int lvl, char *pfad )
   {
   int i;

   if( !tn )
      return;
   pfad[lvl] = 1;
   dcount += lvl + 1;
   treap_shownode( tn->right, lvl + 1, pfad );
   for( i = 0; i < lvl - 1; i++ )
      printf( pfad[i] == pfad[i + 1] ? "     " : "  |  " );
   if( lvl )
      printf( pfad[lvl - 1] ? "  /--" : "  \\--" );
   printf( "%s\n", tn->geg->name );
   pfad[lvl] = 0;
   treap_shownode( tn->left, lvl + 1, pfad );
   }

void treap_show( struct treap *t )
   {
   char pfad[100];
   dcount = 0;
   treap_shownode( t->root, 0, pfad );
   printf( "Mittlere Tiefe: %f\n", dcount / 50 );
   }

void treap_freenode( struct treapnode *tn )
   {
   if( !tn )
      return;
   treap_freenode( tn->left );
   treap_freenode( tn->right );
   free( tn->geg->name );
   free( tn->geg );
   free( tn );
   }

void treap_free( struct treap *t )
   {
   treap_freenode( t->root );
   free( t );
   }

struct treap *treap_load( char *datei )
   {
   FILE *pf;
   char land[100];
   struct treap *t;
   struct gegner *g;

   pf = fopen( datei, "r" );
   t = treap_create();
   srand( 654321 );
   for( ;; )
      {
      fscanf( pf, "%s", land );
      if( feof( pf ) )
         break;
      g = ( struct gegner * )malloc( sizeof( struct gegner ) );
      g->name = ( char * ) malloc( strlen( land ) + 1 );
      strcpy( g->name, land );
      fscanf( pf, "%d", &g->spiele );

      treap_insert( t, g );
      }
   fclose( pf );
   return t;
   }

void main()
   {
   struct treap *t;
   char land[100];
   struct gegner *g;
   int i;

   t = treap_load( "Laenderspiele50s.txt" );
   treap_show( t );

   for( i = 0; i < 5; i++ )
      {
      printf( "Land: " );
      scanf( "%s", land );
      g = treap_find( t, land );
      if( g )
         printf( "Gegen %s gab es bisher %d Spiele\n", g->name, g->spiele );
      else
         printf( "Land %s nicht gefunden\n", land );
      }
   treap_free( t );
   }

