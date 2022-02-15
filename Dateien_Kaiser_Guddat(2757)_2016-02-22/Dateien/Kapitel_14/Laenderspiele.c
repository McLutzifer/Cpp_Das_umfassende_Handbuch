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
   char name[30];
   struct spiele ergebnisse;
   struct tore treffer;
   struct datum erstes;
   struct datum letztes;
   };

struct daten
   {
   int anzahl;
   struct bilanz land[100];
   };


static int lies_bilanz( FILE *pf, struct bilanz *pb )
   {
   fscanf( pf, "%s", pb->name );
   if( feof( pf ) )
      return 0;
   fscanf( pf, "%d %d %d %d", &pb->ergebnisse.gesamt, &pb->ergebnisse.gew, &pb->ergebnisse.unent, &pb->ergebnisse.verl );
   fscanf( pf, "%d:%d", &pb->treffer.dfb, &pb->treffer.gegner );
   fscanf( pf, "%d.%d.%d", &pb->erstes.tag, &pb->erstes.monat, &pb->erstes.jahr );
   fscanf( pf, "%d.%d.%d", &pb->letztes.tag, &pb->letztes.monat, &pb->letztes.jahr );
   return 1;
   }

static int lies_datei( struct daten *pd, char *dateiname )
   {
   FILE *pf;
   int anz;

   pd->anzahl = 0;
   pf = fopen( dateiname, "r" );
   if( !pf )
      return 0;
   for( anz = 0; lies_bilanz( pf, pd->land + anz ); anz++ )
      ;
   fclose( pf );
   pd->anzahl = anz;
   return anz;
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

static void print_daten( struct daten *pd )
   {
   int i;

   for( i = 0; i < pd->anzahl; i++ )
      print_bilanz( pd->land + i );
   }


static int datumsvergleich( struct datum *pd1, struct datum *pd2 )
   {
   if( pd1->jahr != pd2->jahr )
      return pd1->jahr - pd2->jahr;
   if( pd1->monat != pd2->monat )
      return pd1->monat - pd2->monat;
   return pd1->tag - pd2->tag;
   }


static int lieblingsgegner( struct daten *pd )
   {
   int i;
   int index;
   int max = -1;

   for( i = 0; i < pd->anzahl; i++ )
      {
      if( pd->land[i].ergebnisse.gesamt > max )
         {
         max = pd->land[i].ergebnisse.gesamt;
         index = i;
         }
      }
   return index;
   }


# if 0

void randomwrite( struct daten ls )
   {
   int i, n;
   FILE *pf;

   pf = fopen( "laenderpiele1.txt", "w" );
   srand( 123456 );

   while( ls.anzahl )
      {
      n = rand() % ls.anzahl;
      fprintf( pf, "%-25s", ls.land[n].name );
      fprintf( pf, " %3d %3d %3d %3d", ls.land[n].ergebnisse.gesamt, ls.land[n].ergebnisse.gew, ls.land[n].ergebnisse.unent, ls.land[n].ergebnisse.verl );
      fprintf( pf, " %4d:%-4d", ls.land[n].treffer.dfb, ls.land[n].treffer.gegner );
      fprintf( pf, " %02d.%02d.%4d", ls.land[n].erstes.tag, ls.land[n].erstes.monat, ls.land[n].erstes.jahr );
      fprintf( pf, " %02d.%02d.%4d", ls.land[n].letztes.tag, ls.land[n].letztes.monat, ls.land[n].letztes.jahr );
      fprintf( pf, "\n" );
      for( i = n; i < ls.anzahl - 1; i++ )
         ls.land[i] = ls.land[i + 1];
      ls.anzahl--;
      }
   fclose( pf );
   }

# endif

void main()
   {
   struct daten dat;
   int i;

   lies_datei( &dat, "Laenderspiele.txt" );
   print_daten( &dat );
   printf( "\nLieblingsgegner\n" );
   i = lieblingsgegner( &dat );
   print_bilanz( dat.land + i );
   }

