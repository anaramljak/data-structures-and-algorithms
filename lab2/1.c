#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x,y,z;
}Vrh;

typedef struct {
    float i,j,k;
    Vrh v1,v2,v3;
    unsigned short boja;
}Trokut;

typedef struct {
    unsigned int broj;
    Trokut *niz;
}Object3d;

Object3d* BinCit()
{
    FILE *fp=fopen("primjerbin.stl", "r+b");
    fseek(fp,80,SEEK_SET);
    unsigned total;
    fread(&total, sizeof(unsigned), 1, fp);
    Object3d* novi_obj=(Object3d*)malloc(sizeof(Object3d));
    Trokut* tr;
    novi_obj->niz=(Trokut*)malloc(sizeof(Trokut) * total);
    novi_obj->broj=total;
    tr=novi_obj->niz;

    for(total;total!=0;total--)
    {
        fread(&tr->i,sizeof(unsigned), 1, fp);
        fread(&tr->j,sizeof(unsigned), 1, fp);
        fread(&tr->k,sizeof(unsigned), 1, fp);
        fread(&tr->v1,sizeof(Vrh), 1, fp);
        fread(&tr->v2,sizeof(Vrh), 1, fp);
        fread(&tr->v3,sizeof(Vrh), 1, fp);
        fread(&tr->boja,sizeof(unsigned short), 1, fp);
        tr++;
    }
    fclose(fp);
    return novi_obj;
}

void BinPis(Object3d *obj)
{
    int i;
    FILE *fp=fopen("bin.stl", "w+b");
    for(i=0;i<80;i++)
        putc('0', fp);
    fwrite(&(obj->broj),sizeof(unsigned), 1, fp);
    int t;
    for(t=obj->broj;t!=0;t--)
    {
        fwrite(&(obj->niz->i),sizeof(float), 1, fp);
        fwrite(&(obj->niz->j),sizeof(float), 1, fp);
        fwrite(&(obj->niz->k),sizeof(float), 1, fp);
        fwrite(&(obj->niz->v1),sizeof(Vrh), 1, fp);
        fwrite(&(obj->niz->v2),sizeof(Vrh), 1, fp);
        fwrite(&(obj->niz->v3),sizeof(Vrh), 1, fp);
        fwrite(&(obj->niz->boja),sizeof(unsigned short), 1, fp);
        (obj->niz)++;
    }
    fclose(fp);
}

void Text_pis(Object3d* obj)
{
    FILE *fp=fopen("txt.stl", "w+t");
    fprintf(fp, "solid MyFile \n");
    int t;
    for(t=obj->broj;t!=0;t--)
    {
        fprintf(fp, "  facet normal %f %f %f\n", obj->niz->i, obj->niz->j, obj->niz->k);
        fprintf(fp, "    outer loop \n");
        fprintf(fp, "      vertex %f %f %f  \n", obj->niz->v2.x, obj->niz->v1.y, obj->niz->v1.z);
        fprintf(fp, "      vertex %f %f %f  \n", obj->niz->v2.x, obj->niz->v2.y, obj->niz->v2.z);
        fprintf(fp, "      vertex %f %f %f  \n", obj->niz->v3.x, obj->niz->v3.y, obj->niz->v3.z);
        fprintf(fp, "    endloop \n");
        fprintf(fp, "  endfacet \n");
        (obj->niz)++;
    }
    fclose(fp);
}


void main()
{
    Object3d* obj= BinCit();
    BinPis(obj);
    Text_pis(obj);
}
