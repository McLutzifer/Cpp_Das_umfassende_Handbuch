# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct gegner
   {
   char *name;
   int spiele;
   };

struct hashentry
   {
   struct hashentry *nxt;
   struct gegner *geg;
   };

struct hashtable
   {
   int size;
   struct hashentry **table;
   };

unsigned int hash1( char *name, unsigned int size )
   {
   return *name % size;
   }

unsigned int hashfunktion( char *name, unsigned int size )
   {
   unsigned int h;

   for( h = 0; *name; name++ )
      h = ( ( h << 6 ) | ( *name - '@' ) ) % size;
   return h;
   }



struct hashtable *hash_create( int siz )
   {
   struct hashtable *h;

   h = ( struct hashtable * )malloc( sizeof( struct hashtable ) );
   h->size = siz;
   h->table = ( struct hashentry ** )calloc( siz, sizeof( struct hashentry * ) );
   return h;
   }

int hash_insert( struct hashtable *h, struct gegner *g )
   {
   unsigned int ix;
   struct hashentry **e, *neu;

   ix = hashfunktion( g->name, h->size );

   for( e = h->table + ix; *e; e = &( ( *e )->nxt ) )
      {
      if( !strcmp( g->name, ( *e )->geg->name ) )
         return 0;
      }
   neu = ( struct hashentry * )malloc( sizeof( struct hashentry ) );
   neu->nxt = *e;
   neu->geg = g;
   *e = neu;
   return 1;
   }


struct gegner *hash_find( struct hashtable *h, char *name )
   {
   unsigned int index;
   struct hashentry *e;

   index = hashfunktion( name, h->size );
   for( e = h->table[index]; e; e = e->nxt )
      {
      if( !strcmp( name, e->geg->name ) )
         return e->geg;
      }
   return 0;
   }


void hash_show( struct hashtable *h )
   {
   int ix, k;
   struct hashentry *e;
   float dcount = 0;

   for( ix = h->size - 1; ix >= 0; ix-- )
      {
      printf( "%4d:", ix );
      for( k = 0, e = h->table[ix]; e; e = e->nxt )
         {
         dcount += ++k;
         printf( " %s%c", e->geg->name, e->nxt ? ',' : '.' );
         }
      printf( "\n" );
      }
   printf( "Mittlere Suchtiefe: %f\n", dcount / 50 );
   }


void hash_free( struct hashtable *h )
   {
   unsigned int ix;
   struct hashentry *e;

   for( ix = 0; ix < h->size; ix++ )
      {
      while( e = h->table[ix] )
         {
         h->table[ix] = e->nxt;
         free( e->geg->name );
         free( e->geg );
         free( e );
         }
      }
   free( h->table );
   free( h );
   }

struct hashtable *hash_load( char *datei )
   {
   FILE *pf;
   char land[100];
   struct hashtable *h;
   struct gegner *g;

   pf = fopen( datei, "r" );
   h = hash_create( 200 );

   for( ;; )
      {
      fscanf( pf, "%s", land );
      if( feof( pf ) )
         break;
      g = ( struct gegner * )malloc( sizeof( struct gegner ) );
      g->name = ( char * ) malloc( strlen( land ) + 1 );
      strcpy( g->name, land );
      fscanf( pf, "%d", &g->spiele );

      hash_insert( h, g );
      }

   fclose( pf );
   return h;
   }

void main()
   {
   struct hashtable *h;
   char land[100];
   struct gegner *g;
   int i;

   h = hash_load( "Laenderspiele50.txt" );


   hash_show( h );

   for( i = 0; i < 5; i++ )
      {
      printf( "Land: " );
      scanf( "%s", land );
      g = hash_find( h, land );
      if( g )
         printf( "Gegen %s gab es bisher %d Spiele\n", g->name, g->spiele );
      else
         printf( "Land %s nicht gefunden\n", land );
      }

   hash_free( h );
   }

