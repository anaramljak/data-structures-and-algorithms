#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Element{
    char *word;
    struct _Element *next;
}Element;

void print(Element *l)
{
    while(l!=NULL)
    {
        printf("%s -> ", l->word);
        l=l->next;
    }
    printf("NULL");
}

Element *uglavu(Element *l, char *rijec)
{
    Element *prvo=(Element*)malloc(sizeof(Element));
    prvo->word=strdup(rijec);
    prvo->next=l;
    l=prvo;
    return l;
}

Element *end(Element *l, char *rijec)
{
    Element *kraj=(Element*)malloc(sizeof(Element));
    kraj->word=strdup(rijec);
    kraj->next=NULL;
    Element *temp=l;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=kraj;
    return l;
}

Element *pass(Element *l)
{
    Element *temp=l;
    while(temp->next!=NULL)
        if(temp->next=="bbb")
        {
            Element *novi=(Element*)malloc(sizeof(Element));
            novi->word=strdup("lll");
            temp->next=novi;
            novi->next=temp->next;
        }
        else
            temp=temp->next;
    return l;
}




void main()
{
    Element *l=NULL;
    l=uglavu(l, "ddd");
    l=uglavu(l, "ccc");
    l=uglavu(l, "bbb");
    l=uglavu(l, "aaa");
    l=end(l, "aaa");
    l=pass(l);
    print(l);
}
