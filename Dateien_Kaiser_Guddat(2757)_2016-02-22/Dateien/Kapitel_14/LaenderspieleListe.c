# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct datum
   {
   int tag;
   int monat;
   int jahr;
   };

struct spiele
   {
   int gesamt;
   int gew;
   int unent;
   int verl;
   };

struct tore
   {
   int dfb;
   int gegner;
   };

struct bilanz
   {
   struct bilanz *next;
   char *name;
   struct spiele ergebnisse;
   struct tore treffer;
   struct datum erstes;
   struct datum letztes;
   };


static struct bilanz *lies_bilanz( FILE *pf )
   {
   char land[100];
   struct bilanz *pb;

   fscanf( pf, "%s", land );
   if( feof( pf ) )
      return NULL;
   pb = ( struct bilanz * )malloc( sizeof( struct bilanz ) );
   pb->name = ( char * ) malloc( strlen( land ) + 1 );
   strcpy( pb->name, land );
   fscanf( pf, "%d %d %d %d", &pb->ergebnisse.gesamt, &pb->ergebnisse.gew, &pb->ergebnisse.unent, &pb->ergebnisse.verl );
   fscanf( pf, "%d:%d", &pb->treffer.dfb, &pb->treffer.gegner );
   fscanf( pf, "%d.%d.%d", &pb->erstes.tag, &pb->erstes.monat, &pb->erstes.jahr );
   fscanf( pf, "%d.%d.%d", &pb->letztes.tag, &pb->letztes.monat, &pb->letztes.jahr );
   return pb;
   }

static struct bilanz *lies_datei( char *dateiname )
   {
   FILE *pf;
   struct bilanz *liste, *pb;

   pf = fopen( dateiname, "r" );
   if( !pf )
      return NULL;
   for( liste = NULL; pb = lies_bilanz( pf ); )
      {
      pb->next = liste;
      liste = pb;
      }
   fclose( pf );
   return liste;
   }

static struct bilanz *lies_datei2( char *dateiname )
   {
   FILE *pf;
   struct bilanz *liste;
   struct bilanz **ppb;

   pf = fopen( dateiname, "r" );
   if( !pf )
      return NULL;
   for( ppb = &liste; *ppb = lies_bilanz( pf ); ppb = &( ( *ppb )->next ) )
      ;
   fclose( pf );
   return liste;
   }

static void freigabe( struct bilanz *liste )
   {
   struct bilanz *pb;

   while( liste )
      {
      pb = liste;
      liste = liste->next;
      free( pb->name );
      free( pb );
      }
   }

static void print_bilanz( struct bilanz *pb )
   {
   printf( "%-25s", pb->name );
   printf( " %3d %3d %3d %3d", pb->ergebnisse.gesamt, pb->ergebnisse.gew, pb->ergebnisse.unent, pb->ergebnisse.verl );
   printf( " %4d:%-4d", pb->treffer.dfb, pb->treffer.gegner );
   printf( " %02d.%02d.%4d", pb->erstes.tag, pb->erstes.monat, pb->erstes.jahr );
   printf( " %02d.%02d.%4d", pb->letztes.tag, pb->letztes.monat, pb->letztes.jahr );
   printf( "\n" );
   }


static int datumsvergleich( struct datum *pd1, struct datum *pd2 )
   {
   if( pd1->jahr != pd2->jahr )
      return pd1->jahr - pd2->jahr;
   if( pd1->monat != pd2->monat )
      return pd1->monat - pd2->monat;
   return pd1->tag - pd2->tag;
   }


static struct bilanz *select_land( struct bilanz *pb, char *land )
   {
   for( ; pb; pb = pb->next )
      {
      if( !strcmp( land, pb->name ) )
         return pb;
      }
   return NULL;
   }

static struct bilanz *select_buchstabe( struct bilanz *pb, char buchstabe )
   {
   for( ; pb; pb = pb->next )
      {
      if( pb->name[0] == buchstabe )
         return pb;
      }
   return NULL;
   }

static struct bilanz *select( struct bilanz *pb, int testfkt( struct bilanz *, void *data ), void *p )
   {
   for( ; pb; pb = pb->next )
      {
      if( testfkt( pb, p ) )
         return pb;
      }
   return NULL;
   }

static int test( struct bilanz *pb, void *p )
   {
   int d1, d2;
   struct datum *pd = ( struct datum * )p;

   d1 = ( ( pd->jahr * 12 ) + pd->monat ) * 31 + pd->tag;
   d2 = ( ( pb->letztes.jahr * 12 ) + pb->letztes.monat ) * 31 + pb->letztes.tag;

   return d2 >= d1;
   }

void main()
   {
   struct bilanz *liste;
   struct bilanz *pb;
   struct datum dat = { 1, 1, 2013 };

   liste = lies_datei2( "Laenderspiele.txt" );

   printf( "\n ******************* Gesamtbilanz\n" );
   for( pb = liste; pb; pb = pb->next )
      print_bilanz( pb );


   printf( "\n ******************* Bilanz gegen Italien\n" );
   pb = select_land( liste, "Italien" );
   if( pb )
      print_bilanz( pb );

   printf( "\n ******************* Bilanz gegen Laender mit B\n" );
   for( pb = liste; pb = select_buchstabe( pb, 'B' ); pb = pb->next )
      print_bilanz( pb );


   printf( "\n ******************* Bilanz 2013\n" );
   for( pb = liste; pb = select( pb, test, ( void * ) &dat ); pb = pb->next )
      print_bilanz( pb );

   freigabe( liste );
   }

