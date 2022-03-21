#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int* gen(int n)
{
    int i;
    int *niz = (int*) malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (i = 1; i < n; i++) {
		niz[i] = niz[i-1] + rand() % 5 + 1;
	}
	return niz;
}

void shuffle(int* niza, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int k1 = rand() % n;
		int tmp = niza[i];
		niza[i] = niza[k1];
		niza[k1] = tmp;
    }
}


int* presjek(int* niza, int* nizb, int a)
{
    int i,j,k=0;
    int* pres=(int*)malloc(sizeof(int) * a);
    for(i=0;i<a;i++)
    {
        for(j=0;j<30000;j++)
        {
            if(niza[i]==nizb[j])
            {
                pres[k]=niza[i];
                k++;
            }
        }
    }
    return pres;
}

int* presjek_sort(int* niza, int* nizb, int a, int b)
{
    int i,j,k=0;
    int* pres_sort=(int*)malloc(sizeof(int) * a);
    for(i=0;i<a;i++)
    {
        int key=niza[i];
        int *p = (int *)bsearch(&key, niza, 10, sizeof(int), cmp);
        if (p != NULL)
        {
            pres_sort[k] = niza[i];
            k++;
        }
    }
    return pres_sort;
}


void main()
{
   srand(time(0));
   int* niza;
   int* nizb;
   int* novi;
   int i;
   /*for(i=10000;i<50000;i+=5000)
   {
       int p, k;
       niza=gen(i);
       shuffle(niza, i);
       nizb=gen(30000);
       shuffle(nizb,i);
       p=clock();
       novi=presjek(niza, nizb, i);
       k=clock();
       free(niza);
       free(nizb);
       free(novi);
       printf("Vrijeme ne sortiranih je : %d\n", k-p);
   }
   */

   /*for(i=10000;i<50000;i+=5000)
   {
       int p,k;
       niza=gen(i);
       shuffle(niza, i);
       nizb=gen(30000);
       qsort(nizb, 30000, sizeof(int), cmp);
       p=clock();
       novi=presjek(niza, nizb, i);
       k=clock();
       free(niza);
       free(nizb);
       free(novi);
       printf("Vrijeme presjeka nesortiranog i sortiranog niza : %d\n", k-p);
   }
   */
   for(i=10000;i<50000;i+=5000)
   {
       int p, k;
       niza=gen(i);
       shuffle(niza, i);
       nizb=gen(30000);
       p=clock();
       qsort(nizb, 30000, sizeof(int), cmp);
       novi=presjek(niza, nizb, i);
       k=clock();
       free(niza);
       free(nizb);
       free(novi);
       printf("Vrijeme presjeka nesortiranog i sortiranog niza ukljucujuci qsort : %d\n", k-p);
   }
}
