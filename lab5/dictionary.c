#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Dictionary create()
{
    Dictionary novi=(Word*)malloc(sizeof(Word));
    novi->next=NULL;
    return novi;
}


void add(Dictionary dict, char *str)
{
    Word* pointer=dict->next;
    Word* rijec;

    rijec=(Word*)malloc(sizeof(Word));
    rijec->word=strdup(str);

    while(pointer)
    {
        if(strcmp(pointer->word, str)>0)
        {
            rijec->next=pointer;
            dict->next=rijec;
            rijec->count=1;
            return;
        }
        if(!strcmp(pointer->word, str))
        {
            pointer->count++;
            free(rijec->word);
            free(rijec);
            return;
        }
        pointer=pointer->next;
        dict=dict->next;
    }
    dict->next=rijec;
    rijec->next=NULL;
    rijec->count=1;
}

void print(Dictionary dict)
{
    dict=dict->next;
    while(dict != NULL)
    {
        printf("Rijec %s se ponavlja %d puta\n", dict->word, dict->count);
        dict=dict->next;
    }
}

void destroy(Dictionary dict)
{
    Dictionary del=dict;
    dict=dict->next;
    free(del);

    while(dict)
    {
        free(dict->word);
        del=dict;
        dict=dict->next;
        free(del);
    }
}

int filter(Word *w)
{
    if((w->count>5) && (w->count<10) && (strlen(w->word)>3))
       return 1;
    else
        return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w))
{
    Dictionary t=indict->next;
    Dictionary p=indict;
    Dictionary tmp;

    while(t)
    {
        if(filter(t))
        {
            p=t;
            t=t->next;
        }
        else
        {
            tmp=t;
            t=t->next;
            p->next=t;
            free(tmp);
        }
    }
    return indict;
}

