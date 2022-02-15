# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct gegner
   {
   char *name;
   int spiele;
   };

struct listentry
   {
   struct listentry *nxt;
   struct gegner *geg;
   };

struct liste
   {
   struct listentry *first;
   };


struct liste *list_create()
   {
   struct liste *l;


   l = ( struct liste * )malloc( sizeof( struct liste ) );
   l->first = 0;
   return l;
   }

int list_insert( struct liste *l, struct gegner *g )
   {
   struct listentry **e, *neu;
   int cmp;

   for( e = &( l->first ); *e; e = &( ( *e )->nxt ) )
      {
      cmp = strcmp( g->name, ( *e )->geg->name );
      if( !cmp )
         return 0;
      else if( cmp < 0 )
         break;
      }
   neu = ( struct listentry * )malloc( sizeof( struct listentry ) );
   neu->nxt = *e;
   neu->geg = g;
   *e = neu;
   return 1;
   }

struct gegner *list_find( struct liste *l, char *name )
   {
   struct listentry *e;
   int cmp;

   for( e = l->first; e; e = e->nxt )
      {
      cmp = strcmp( name, e->geg->name );
      if( !cmp )
         return e->geg;
      else if( cmp < 0 )
         break;
      }
   return 0;
   }

# if 0

void list_show( struct liste *l )
   {
   struct listentry *e;

   for( e = l->first; e; e = e->nxt )
      printf( "%s %d\n", e->geg->name, e->geg->spiele );
   printf( "\n" );
   }
# endif

float dcount;

void shw( struct listentry *le, int lvl )
   {
   int k;

   if( !le )
      return;
   dcount += lvl + 1;
   shw( le->nxt, lvl + 1 );

   for( k = 0; k < lvl; k++ )
      printf( " " );
   if( lvl )
      printf( "+-" );
   printf( "%s\n", le->geg->name );
   }

void list_show( struct liste *l )
   {
   dcount = 0;
   shw( l->first, 0 );
   printf( "Mittlere Tiefe: %f\n", dcount / 50 );
   }

void list_free( struct liste *l )
   {
   struct listentry *e;

   while( e = l->first )
      {
      l->first = e->nxt;
      free( e->geg->name );
      free( e->geg );
      free( e );
      }
   free( l );
   }

struct liste *list_load( char *datei )
   {
   FILE *pf;
   char land[100];
   struct liste *l;
   struct gegner *g;

   pf = fopen( datei, "r" );
   l = list_create();

   for( ;; )
      {
      fscanf( pf, "%s", land );
      if( feof( pf ) )
         break;
      g = ( struct gegner * )malloc( sizeof( struct gegner ) );
      g->name = ( char * ) malloc( strlen( land ) + 1 );
      strcpy( g->name, land );
      fscanf( pf, "%d", &g->spiele );

      list_insert( l, g );
      }

   fclose( pf );
   return l;
   }

void main()
   {
   struct liste *l;
   char land[100];
   struct gegner *g;
   int i;

   l = list_load( "Laenderspiele50.txt" );
   list_show( l );

   for( i = 0; i < 3; i++ )
      {
      printf( "Land: " );
      scanf( "%s", land );
      g = list_find( l, land );
      if( g )
         printf( "Gegen %s gab es bisher %d Spiele\n", g->name, g->spiele );
      else
         printf( "%s nicht gefunden\n", land );
      }

   list_free( l );
   }

