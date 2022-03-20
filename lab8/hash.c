#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable *table=(HashTable*)malloc(sizeof(HashTable));
	table->load=0;
	table->size=size;
	table->table=(Bin**)malloc(sizeof(Bin*)*size);
	int i;
	for(i=0;i<size;i++)
        table->table[i]=NULL;
	return table;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	int slot= hash(word) % ht->size;
	Bin* new=(Bin*)malloc(sizeof(Bin));
	new->word=word;
	new->next=ht->table[slot];
	ht->table[slot]=new;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	int slot= hash(word) % ht->size;
	Bin* temp=ht->table[slot];
	while(temp!=NULL)
    {
        if(strcmp(temp->word,word)==0)
        {
            return 1;
        }
        temp=temp->next;
    }
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	int i=0;
	while(i!=ht->size)
    {
        Bin* temp=ht->table[i];
        while(temp->next!=NULL)
        {
            Bin* del=temp->next;
            temp=del->next;
            free(del->word);
            free(del);
        }
        free(temp->word);
        free(temp);
    }
    free(ht->table);
    free(ht);
}
