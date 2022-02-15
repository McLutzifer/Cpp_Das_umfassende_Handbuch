#include <stdio.h>

int stringlaenge( char s[])
{
	int i;
	for ( i = 0; s[i] != 0; i++) ;
	return i;
}

int stringvergleich( char s1[], char s2[])
{
	int i;
	for ( i = 0; (s1[i] != 0) && (s1[i] == s2[i]); i++) ;
	return s1[i] == s2[i];
}

int main()
{
	int l, v;
	l = stringlaenge( "qwert"); printf( "Laenge: %d\n", l);
	v = stringvergleich( "qwert", "qwerz");

	if ( v == 1)
		printf( "gleich\n");
	else
		printf( "ungleich\n");
}