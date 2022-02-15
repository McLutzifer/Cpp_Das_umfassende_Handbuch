#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "enigma.h"


void read_steck( char *filename, int *steck )
   {
   int i;
   int zahl;
   FILE *datei = fopen( filename, "r" );

   if( !datei )
      cout << "Dateifehler!" << endl;
   else
      {
      for( i = 0; i < 26; i++ )
         {
         fscanf( datei, "%d", &zahl );

         if( feof( datei ) )
            break;

         steck[i] = zahl;
         }
      fclose( datei );
      }
   }

void read_rs( char *filename, int *r1, int *r2, int *r3 )
   {
   int i;
   int zahl1, zahl2, zahl3;
   FILE *datei = fopen( filename, "r" );

   if( !datei )
      cout << "Dateifehler!" << endl;
   else
      {
      for( i = 0; i < 26; i++ )
         {
         fscanf( datei, "%d %d %d", &zahl1, &zahl2, &zahl3 );

         if( feof( datei ) )
            break;

         r1[i] = zahl1;
         r2[i] = zahl2;
         r3[i] = zahl3;
         }
      fclose( datei );
      }
   }

void read_refl( char *filename, int *refl )
   {
   int i;
   int zahl;
   FILE *datei = fopen( filename, "r" );

   if( !datei )
      cout << "Dateifehler!" << endl;
   else
      {
      for( i = 0; i < 26; i++ )
         {
         fscanf( datei, "%d", &zahl );

         if( feof( datei ) )
            break;

         refl[i] = zahl;
         }
      fclose( datei );
      }
   }

void main()
   {
   int steck[26];
   int r1[26], r2[26], r3[26];
   int refl[26];
   char steck_datei[100];
   char rotoren_datei[100];
   char refl_datei[100];

   cout << "Config-Datei des Steckbretts: ";
   cin >> steck_datei;
   cout << "Config-Datei der Rotoren:     ";
   cin >> rotoren_datei;
   cout << "Config-Datei des Reflektors:  ";
   cin >> refl_datei;
   cout << '\n';

   read_steck( steck_datei, steck );
   read_rs( rotoren_datei, r1, r2, r3 );
   read_refl( refl_datei, refl );

   enigma e( steck, r1, r2, r3, 4, 7, 11, refl );

   //Test: cout << e << endl;

   cout << e.work( "PJS UGGQFP LTV" ) << '\n';
   cout << e.work( "PHAZBRXE VKE YYWLBTBORYC" ) << '\n';
   cout << e.work( "MGU QA BNQXXK FZL GJ TWGNQKJWR" ) << '\n';
   cout << e.work( "PQV DXQWINKGGLXKP" ) << '\n';
   cout << e.work( "ZTMMM GZVCAIVNCQI AGSHRY" ) << '\n';







   /*cout << e.work( "DIE WUERDE DES" ) << '\n';
   cout << e.work( "MENSCHEN IST UNANTASTBAR" ) << '\n';
   cout << e.work( "SIE ZU ACHTEN UND ZU SCHUETZEN" ) << '\n';
   cout << e.work( "IST VERPFLICHTUNG" ) << '\n';
   cout << e.work( "ALLER STAATLICHEN GEWALT" ) << '\n';*/


   /*cout << e.work("JSOZL FFZPW OPMPZVJ") << '\n';
   cout << e.work("WYG LLW") << '\n';
   cout << e.work("OY WNVJL FQVLQFY") << '\n';
   cout << e.work("VNCGVMGW PT") << '\n';
   cout << e.work("UPJH DZUQY URFYV") << '\n';
   cout << e.work("RPX CCKPGVAQ PFMTRTSQX VN HTILX") << '\n';
   cout << e.work("QJVFG ZBL HSZPV") << '\n';
   cout << e.work("XWTGOD WD QRMB") << '\n'; */
   }
