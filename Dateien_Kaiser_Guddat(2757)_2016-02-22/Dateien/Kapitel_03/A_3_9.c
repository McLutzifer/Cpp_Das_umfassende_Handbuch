# include <stdio.h>
# include <stdlib.h>


void main()
    {
    int p;
    int t;

    printf( "Gib eine Zahl ein: ");
    scanf( "%d", &p);

    for( t = 2; t < p; t++)
        {
        if( p%t == 0)
            break;
        }
    if( t == p)
        printf( "%d ist eine Primzahl\n", p);
    else
        printf( "%d ist keine Primzahl\n", p);
    }
