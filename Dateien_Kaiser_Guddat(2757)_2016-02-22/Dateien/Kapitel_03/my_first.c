# include <stdio.h>
# include <stdlib.h>

void main()
    {
        float hoehe = 13.5;
        int a, b = 0, c;

        a = 1;
        hoehe = a;
        a = 2;
        float x = (float)a;

        printf(" a is %d\n", a);
        printf(" hoehe ist %f\n", hoehe);
        printf(" b ist %d\n", b);
        printf(" c is %f\n", x);


        int i, summe = 0;

        for (i = 1; i <5; i++)
            summe += 1;

        printf(" summe is %d\n", summe);
    }