#include <stdio.h>
#include <stdlib.h>
#define N 10000

typedef struct {
    void* podatak;
    int prioritet;
}Element;

Element* create()
{
    Element* niz=(Element*)malloc(sizeof(Element)*N);
    return niz;
}

void ele_add(Element* l, int n, int prioritet)
{
    l[n].prioritet=prioritet;
    prema_gore(l, n);
}

Element* ele_del(Element* l, int n)
{
    Element tmp=l[0];
    l[0].prioritet=l[n].prioritet;
    prema_dnu(l, n, 0);
}
//Prvi if provjerava jesu li i lijevi i desni manji od n, onda provjerava koji je veci i njega uzima kao sljedeci indeks roditelja
void prema_dnu(Element* l, int n, int rod)
{
    if(rod>=n-1)
        return;
    else
    {
        int pravi;
        int lijevi=2*rod+1;
        int desni=2*rod+2;
        if(lijevi<n && desni<n)
        {
            if(l[desni].prioritet>l[lijevi].prioritet)
                pravi=desni;
            else if(l[desni].prioritet<l[lijevi].prioritet)
                pravi=lijevi;
        }
        else if(lijevi<=n)
            pravi=lijevi;
        else if(desni<=n)
            pravi=desni;
        if(l[rod].prioritet<l[pravi].prioritet)
        {
            int temp=l[rod].prioritet;
            l[rod].prioritet=l[pravi].prioritet;
            l[pravi].prioritet=temp;
            prema_dnu(l, n, pravi);
        }
    }
}


void prema_gore(Element* l, int n)
{
    if(n<0)
        return ;
    else
    {
        int r=(n-1)/2;
        if(l[r].prioritet<l[n].prioritet)
        {
            int temp=l[r].prioritet;
            l[r].prioritet=l[n].prioritet;
            l[n].prioritet=temp;
            prema_gore(l, r);
        }
    }
}


void main()
{
    int n=0, prioritet;
    Element* l;
    l=create();
    ele_add(l, n, 20);
    n++;
    ele_add(l, n, 30);
    n++;
    ele_add(l, n, 200);
    n++;
    ele_add(l, n, 100);
    n++;
    ele_add(l, n, 150);
    n++;
    ele_del(l, n);
    n--;
    for(int i=0;i<n;i++)
    {
        printf("%d\n", l[i].prioritet);
    }
}
