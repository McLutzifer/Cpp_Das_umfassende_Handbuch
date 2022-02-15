# include <stdio.h>
# include <stdlib.h>

# define ANZAHL 4

struct ergebnis
   {
   int tore;
   int gegentore;
   };

struct auswertung
   {
   int team;
   int spiele;
   int punkte;
   int tore;
   int gegentore;
   };

struct turnier
   {
   char mannschaft[ANZAHL][20];
   struct ergebnis resultat[ANZAHL][ANZAHL];
   struct auswertung tabelle[ANZAHL];
   };

void daten_einlesen( struct turnier *t )
   {
   int z, s;

   for( z = 0; z < ANZAHL; z++ )
      {
      printf( "Mannschaft %d: ", z + 1 );
      scanf( "%s", t->mannschaft[z] );
      }
   for( z = 0; z < ANZAHL; z++ )
      {
      for( s = 0; s < ANZAHL; s++ )
         {
         if( z == s )
            continue;
         printf( "%s : %s: ", t->mannschaft[z], t->mannschaft[s] );
         scanf( "%d:%d", &( t->resultat[z][s].tore ), &( t->resultat[z][s].gegentore ) );
         }
      }
   }

void daten_ausgeben( struct turnier *t )
   {
   int z, s;

   printf( "\nMannschaften\n" );
   for( z = 0; z < ANZAHL; z++ )
      printf( "%d. %s\n", z, t->mannschaft[z] );
   printf( "\nSpiele\n" );
   for( z = 0; z < ANZAHL; z++ )
      {
      for( s = 0; s < ANZAHL; s++ )
         {
         if( z == s )
            continue;
         if( t->resultat[z][s].tore > 0 )
            printf( "%s : %s %d:%d\n", t->mannschaft[z], t->mannschaft[s], t->resultat[z][s].tore, t->resultat[z][s].gegentore );
         }
      }
   printf( "\nTabelle\n" );
   for( z = 0; z < ANZAHL; z++ )
      {
      printf( "%-10s", t->mannschaft[t->tabelle[z].team] );
      printf( "%2d %2d %2d:%2d\n", t->tabelle[z].spiele, t->tabelle[z].punkte, t->tabelle[z].tore, t->tabelle[z].gegentore );
      }
   }

int vergleich( struct auswertung *a1, struct auswertung *a2 )
   {
   int d1, d2;

   if( a1->punkte > a2->punkte )
      return 1;
   if( a1->punkte < a2->punkte )
      return -1;
   d1 = a1->tore - a1->gegentore;
   d2 = a2->tore - a2->gegentore;
   if( d1 > d2 )
      return 1;
   if( d1 < d2 )
      return -1;
   if( a1->tore > a2->tore )
      return 1;
   if( a1->tore < a2->tore )
      return -1;
   return 0;
   }

void bubblesort( int n, struct auswertung *daten )
   {
   int i, k;
   struct auswertung t;

   for( i = n - 1; i > 0; i-- )
      {
      for( k = 0; k < i; k++ )
         {
         if( vergleich( daten + k, daten + k + 1 ) < 0 )
            {
            t = daten[k];
            daten[k] = daten[k + 1];
            daten[k + 1] = t;
            }
         }
      }
   }

void tabelle_berechnen( struct turnier *t )
   {
   int z, s;

   for( z = 0; z < ANZAHL; z++ )
      {
      t->tabelle[z].team = z;
      t->tabelle[z].spiele = 0;
      t->tabelle[z].punkte = 0;
      t->tabelle[z].tore = 0;
      t->tabelle[z].gegentore = 0;
      }

   for( z = 0; z < ANZAHL; z++ )
      {
      for( s = 0; s < ANZAHL; s++ )
         {
         if( z == s )
            continue;
         if( t->resultat[z][s].tore < 0 )
            continue;
         t->tabelle[z].spiele++;
         t->tabelle[s].spiele++;
         if( t->resultat[z][s].tore == t->resultat[z][s].gegentore )
            {
            t->tabelle[z].punkte++;
            t->tabelle[s].punkte++;
            }
         else
            {
            if( t->resultat[z][s].tore > t->resultat[z][s].gegentore )
               t->tabelle[z].punkte += 3;
            else
               t->tabelle[s].punkte += 3;
            }
         t->tabelle[z].tore += t->resultat[z][s].tore;
         t->tabelle[z].gegentore += t->resultat[z][s].gegentore;
         t->tabelle[s].tore += t->resultat[z][s].gegentore;
         t->tabelle[s].gegentore += t->resultat[z][s].tore;
         }
      }
   bubblesort( ANZAHL, t->tabelle );
   }

void main()
   {
   struct turnier turn;

   daten_einlesen( &turn );
   tabelle_berechnen( &turn );
   daten_ausgeben( &turn );
   }