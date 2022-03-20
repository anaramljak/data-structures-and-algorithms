#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
}Tocka;

typedef struct{
    Tocka *niz;
    int n;
}Poligon;

Poligon* novi_pol(float *a, float *b, int n)
{
    int i;
    Tocka* nizovi=(Tocka*)malloc(n * sizeof(Tocka));
    Poligon* poly=(Poligon*)malloc(sizeof(Poligon));
    poly->niz=nizovi;
    for(i=0;i<n;i++)
    {
        nizovi[i].x=a[i];
        nizovi[i].y=b[i];
        printf("%1f, %1f\n", poly->niz[i].x, poly->niz[i].y);
    }
    poly->n=n;
    return poly;
}

Tocka** pozitivni(Poligon* novi_pol, int *np)
{
    int i,j=0;
    for(i=0;i<novi_pol->n;i++)
    {
        if((novi_pol->niz[i].x>0) && (novi_pol->niz[i].y>0))
        {
            (*np)++;
        }
    }

    Tocka **pozitivni=(Tocka*)malloc((*np) * sizeof(Tocka));

    for(i=0;i<novi_pol->n;i++)
    {
        if((novi_pol->niz[i].x>0) && (novi_pol->niz[i].y>0))
        {
            pozitivni[j]=&(novi_pol->niz[i]);
            j++;
            printf("%d\n", pozitivni[j]);
        }
    }
    return pozitivni;
}


int main()
{
    float a[4]={1.5,2.0,2.5,-2.0};
    float b[4]={4.2,1.0,-3.4,3.0};
    int np=0;

    Poligon *poligon1=novi_pol(a,b,4);
    Tocka **positive=pozitivni(poligon1,&np);


    return 0;
}
