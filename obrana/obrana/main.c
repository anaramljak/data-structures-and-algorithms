#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int broj;
	struct _Element *next;
} Element;

int treci(Element *lista)
{
    Element *tmp=lista->next;
    Element *drugi=tmp->next;
    while(tmp!=NULL)
    {
        while(drugi!=NULL)
        {
            if(tmp->broj==drugi->broj)
                return 1;
            drugi=drugi->next;
        }
        drugi=tmp->next->next;
        tmp=tmp->next;
    }
    return 0;
}



void print(Element *lista)
{
    while(lista != NULL)
    {
        printf("%d -> ", lista->broj);
        lista=lista->next;
    }
    printf("NULL\n");
}

Element* nakraj(Element *lista, int n)
{
    Element *broj=(Element*)malloc(sizeof(Element));
    broj->broj=n;
    broj->next=NULL;
    if (lista == NULL)
		return broj;
    Element *tmp=lista;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=broj;
    return lista;
}

Element* uglavu(Element *lista, int n)
{
    Element *temp=(Element*)malloc(sizeof(Element));
    temp->broj=n;
    temp->next=lista;
    lista=temp;
    return lista;
}

int brojrij(Element *lista)
{
    int c=0;
    while(lista != NULL)
    {
        c++;
        lista=lista->next;
    }
    return c;
}

int najveci(Element *lista)
{
    int top=0;
    while(lista!=NULL)
    {
        if((lista->broj) > top)
        {
            top=lista->broj;
        }
        lista=lista->next;
    }
    return top;
}

Element *ukl_prvi(Element *lista)
{
    Element *brisi=lista;
    lista=lista->next;
    free(brisi);
    return lista;
}

Element *ukl_kraj(Element *lista)
{
    Element *temp=(Element*)malloc(sizeof(Element));
    temp=lista;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return lista;
}

Element *ukl_broj(Element *lista, int broj)
{
    if(lista=NULL)
        return NULL;
    if(lista->broj==broj)
    {
        Element *brisi=lista;
        lista=lista->next;
        free(brisi);
        return lista;
    }
    Element *temp=lista;
    while(temp->next != NULL)
    {
        if(temp->next->broj==broj)
        {
            Element *brisi=temp->next;
            temp->next=temp->next->next;
            free(brisi);
            return lista;
        }
        temp=temp->next;
    }
    return lista;
}

Element *poredu(Element *lista, Element *novi)
{
    if (lista == NULL) {
		novi->next = NULL;
		return novi;
	}
	if (lista->broj > novi->broj) {
		novi->next = lista;
		return novi;
	}
	Element *tmp = lista;
	while (tmp->next != NULL) {
		if (tmp->next->broj > novi->broj) {
			novi->next = tmp->next;
			tmp->next = novi;
			return lista;
		}
		tmp = tmp->next;
	}

	novi->next = NULL;
	tmp->next = novi;
	return lista;
}

Element *zamjena(Element *lista)
{
    Element *prvi=(Element*)malloc(sizeof(Element));
    prvi->broj=lista->broj;
    prvi->next=NULL;
    Element *temp=lista;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    lista->broj=temp->broj;
    temp->broj=prvi->broj;
    free(prvi);
    return lista;
}

Element *dod_ispr(Element *lista, int n)
{
    //dodati n isprid svake 2
    Element *temp=lista;
    while(temp != NULL)
    {
        if(temp->next->broj==2)
        {
            Element *trica=(Element*)malloc(sizeof(Element));
            trica->broj=n;
            trica->next=temp->next;
            temp->next=trica;
            temp=temp->next->next;
        }
        else
            temp=temp->next;
    }
    return lista;
}

void main()
{
    Element *l=NULL;
    Element *k=NULL;
    l = nakraj(l, 5);
    l = uglavu(l, 6);
    l = uglavu(l, 3);
    l = uglavu(l, 5);
    l = uglavu(l, 1);
    k = uglavu(k, 1);
    k = uglavu(k, 3);
    k = uglavu(k, 5);
    k = uglavu(k, 6);
    k = uglavu(k, 2);

    //l = ukl_broj(l, 8);
    print(k);
    printf("%d", treci(l));

    //printf("%d", najveci(l));
    //printf("%d", brojrij(l));
}
