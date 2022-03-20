#include <stdio.h>
#include <stdlib.h>
#include "sortiranja.h"

void main()
{
    int i, n=1000000;
    int* niz;
    double time;
    /*
    for(i=10000;i<100000;i+=10000)
    {
        choose_pivot=1;
        niz=generiraj(i);
        shuffle(niz, i);
        time=measure(quicksort, niz, i);
        printf("Sa pivoton %lf - ", time);
        free(niz);

        choose_pivot=0;
        niz=generiraj(i);
        shuffle(niz, i);
        time=measure(quicksort, niz, i);
        printf("Bez pivota  %lf\n", time);
        free(niz);
    }

    */
    for(n_min=0;n_min<200;n_min+=5)
    {
        niz=generiraj(n);
        shuffle(niz, n);
        time=measure(newquicksort, niz, n);
        printf("N_min - %d, Time - %lf\n", n_min, time);
        free(niz);
    }

}
