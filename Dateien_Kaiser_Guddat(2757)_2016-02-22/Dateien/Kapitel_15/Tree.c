# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# undef REKURSIV

struct gegner
   {
   char *name;
   int spiele;
   };

struct treenode
   {
   struct treenode *left;
   struct treenode *right;
   struct gegner *geg;
   };

struct tree
   {
   struct treenode *root;
   };

struct tree *tree_create()
   {
   struct tree *t;

   t = ( struct tree * )malloc( sizeof( struct tree ) );
   t->root = 0;
   return t;
   }

# ifdef REKURSIV

int tree_insert_rek( struct treenode **node, struct gegner *g )
   {
   int cmp;

   if( *node )
      {
      cmp = strcmp( g->name, ( *node )->geg->name );
      if( cmp > 0 )
         return tree_insert_rek( &( ( *node )->right ), g );
      if( cmp < 0 )
         return tree_insert_rek( &( ( *node )->left ), g );
      return 0;
      }
   *node = ( struct treenode * ) malloc( sizeof( struct treenode ) );
   ( *node )->left = 0;
   ( *node )->right = 0;
   ( *node )->geg = g;
   return 1;
   }

int tree_insert( struct tree *t, struct gegner *g )
   {
   return tree_insert_rek( &( t->root ), g );
   }



# else

int tree_insert( struct tree *t, struct gegner *g )
   {
   struct treenode **node, *neu;
   int cmp;

   for( node = &( t->root ); *node; )
      {
      cmp = strcmp( g->name, ( *node )->geg->name );
      if( !cmp )
         return 0;
      if( cmp < 0 )
         node = &( ( *node )->left );
      else
         node = &( ( *node )->right );
      }
   neu = ( struct treenode * )malloc( sizeof( struct treenode ) );
   neu->left = 0;
   neu->right = 0;
   neu->geg = g;
   *node = neu;
   return 1;
   }

# endif

struct gegner *tree_find( struct tree *t, char *name )
   {
   struct treenode *tn;
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

void tree_shownode( struct treenode *tn, int lvl, char *pfad )
   {
   int i;

   if( !tn )
      return;
   pfad[lvl] = 1;
   dcount += lvl + 1;
   tree_shownode( tn->right, lvl + 1, pfad );
   for( i = 0; i < lvl - 1; i++ )
      printf( pfad[i] == pfad[i + 1] ? "     " : "  |  " );
   if( lvl )
      printf( pfad[lvl - 1] ? "  /--" : "  \\--" );
   printf( "%s\n", tn->geg->name );
   pfad[lvl] = 0;
   tree_shownode( tn->left, lvl + 1, pfad );
   }

void tree_show( struct tree *t )
   {
   char pfad[100];
   dcount = 0;
   tree_shownode( t->root, 0, pfad );
   printf( "Mittlere Tiefe: %f\n", dcount / 50 );
   }


void tree_freenode( struct treenode *tn )
   {
   if( !tn )
      return;
   tree_freenode( tn->left );
   tree_freenode( tn->right );
   free( tn->geg->name );
   free( tn->geg );
   free( tn );
   }

void tree_free( struct tree *t )
   {
   tree_freenode( t->root );
   free( t );
   }

struct tree *tree_load( char *datei )
   {
   FILE *pf;
   char land[100];
   struct tree *t;
   struct gegner *g;

   pf = fopen( datei, "r" );
   t = tree_create();

   for( ;; )
      {
      fscanf( pf, "%s", land );
      if( feof( pf ) )
         break;
      g = ( struct gegner * )malloc( sizeof( struct gegner ) );
      g->name = ( char * ) malloc( strlen( land ) + 1 );
      strcpy( g->name, land );
      fscanf( pf, "%d", &g->spiele );

      tree_insert( t, g );
      }

   fclose( pf );
   return t;
   }

void main()
   {
   struct tree *t;
   char land[100];
   struct gegner *g;
   int i;

   t = tree_load( "Laenderspiele50s.txt" );
   tree_show( t );

   for( i = 0; i < 5; i++ )
      {
      printf( "Land: " );
      scanf( "%s", land );
      g = tree_find( t, land );
      if( g )
         printf( "Gegen %s gab es bisher %d Spiele\n", g->name, g->spiele );
      else
         printf( "Land %s nicht gefunden\n", land );
      }

   tree_free( t );
   }

