#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if(!(*bst))
    {
        Node* new=(Node*)malloc(sizeof(Node));
        new->left=NULL;
        new->right=NULL;
        new->word=word;
        *bst=new;
    }
    else if(strcmp((*bst)->word,word)<0)
        AddNode(&(*bst)->right, word);
    else if(strcmp((*bst)->word,word)>0)
        AddNode(&(*bst)->left, word);
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
    if (!bst)
        return 0;
    int left=BSTHeight(bst->left) + 1;
    int right=BSTHeight(bst->right) + 1;
    if(left>right)
        return left;
    else if(right>left)
        return right;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
	if(!bst)
        return;
    PrintBSTree(bst->left);
    printf("%s ", bst->word);
    PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if(!bst)
        return;
    fprintf(fd, "%s ", bst->word);
    SaveBSTree(bst->left, fd);
    SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	if(!bst)
        return NULL;
    free(bst->word);
    DeleteBSTree(bst->left);
    DeleteBSTree(bst->right);
    free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().
	BSTree bst=NewBSTree();
	char buffer[1024];
	while(fscanf(fd, "%s", buffer)!=EOF)
        AddNode(&bst, strdup(buffer));
	return bst;
}

char* longest(BSTree bst){
	if(!bst)
        return "";

	char* rw = longest(bst->right);
	char* lw = longest(bst->left);
	char* cw = bst->word;

	if(strlen(rw) > strlen(cw))
		cw = rw;

	if(strlen(lw) > strlen(cw))
		cw = lw;

	return cw;
}

void Prema_krit(BSTree bst)
{
    if(!bst)
        return;
    else if(strcmp(bst->word,"brane")>0)
        printf("\n%s\n", bst->word);
    Prema_krit(bst->right);
    Prema_krit(bst->left);
}

void Listovi(BSTree bst)
{
    if(!bst)
        return;
    else if((bst->right==NULL) && (bst->left==NULL))
    {
        printf("\n \n%s", bst->word);
    }
    Listovi(bst->left);
    Listovi(bst->right);
}

void Cvorovi(BSTree bst)
{
    if(!bst)
        return;
    else if((bst->right!=NULL && bst->left==NULL) || (bst->right==NULL && bst->left!=NULL) || (bst->right!=NULL && bst->left!=NULL))
    {
        printf("%s\n", bst->word);
    }
    Cvorovi(bst->left);
    Cvorovi(bst->right);
}

void Dod_Listovi(BSTree *bst, char *word)
{
    if(!(*bst))
        return;
    else if((*bst)->right==NULL && (*bst)->left==NULL)
    {
        Node* new=(Node*)malloc(sizeof(Node));
        new->left=NULL;
        new->right=NULL;
        new->word=word;
        if(strcmp((*bst)->word,word)<0)
        {
            (*bst)->right=new;
            printf("%s desno %s\n", (*bst)->word, (*bst)->right->word);
        }
        else if(strcmp((*bst)->word,word)>0)
        {
            (*bst)->left=new;
            printf("%s livo %s\n", (*bst)->word, (*bst)->left->word);
        }
    }
    Dod_Listovi(&(*bst)->right, word);
    Dod_Listovi(&(*bst)->left, word);
}

void printListovi(BSTree bst)
{
    if(!bst)
        return;
    else if(bst->right==NULL && bst->left==NULL)
        printf("%s ", bst->word);
    printListovi(bst->left);
    printListovi(bst->right);
}

void Bris_list(BSTree *bst)
{
    if(!(*bst))
        return;
    else if((*bst)->right==NULL && (*bst)->left==NULL)
    {
        free((*bst)->word);
        free(*bst);
        *bst=NULL;
        return (*bst);
    }
    Bris_list(&(*bst)->right);
    Bris_list(&(*bst)->left);
}

void Bris_Odr_list(BSTree *bst)
{
    if(!(*bst))
        return;
    else if((*bst)->right==NULL && (*bst)->left==NULL && strcmp((*bst)->word, "ceva")>0)
    {
        free((*bst)->word);
        free(*bst);
        *bst=NULL;
        return (*bst);
    }
    Bris_Odr_list(&(*bst)->right);
    Bris_Odr_list(&(*bst)->left);
}

void Bris_podstablo(BSTree *bst)
{
    if(!(*bst))
        return;
    if(strcmp((*bst)->word,"bane")==0)
    {
        free((*bst)->word);
        free(*bst);
        *bst=NULL;
        return bst;
    }
    Bris_podstablo(&(*bst)->right);
    Bris_podstablo(&(*bst)->left);
}

int broj_cvorova(BSTree bst)
{
    if(!bst)
        return 0;
    if(bst->right!=NULL || bst->left!=NULL)
        return 1 + broj_cvorova(bst->right) + broj_cvorova(bst->left);
    broj_cvorova(bst->right);
    broj_cvorova(bst->left);
}
int numberOfElements(BSTree bst){
	if(!bst)	return 0;

	return 1 + numberOfElements(bst->left) + numberOfElements(bst->right);
}
