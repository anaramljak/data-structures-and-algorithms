#include <stdio.h>

int retrn(char *str1)
{
    int i=0;
    while(*str1 != '\0')
    {
        str1++;
        i++;
    }
    return i;
}

int compere(char *str1, char *str2)
{
    while(1)
    {

        if((*str1>*str2) || (*str1!='\0' && *str2=='\0'))
            return 1;
        if((*str2>*str1) || (*str2!='\0' && *str1=='\0'))
            return -1;
        if(*str1==*str2 && *str1!='\0')
        {
            str1++;
            str2++;
        }
        if(*str1=='\0' && *str2=='\0')
            return 0;
    }
}


void copy(char *str1, char *str2)
{
    while(*str2!='\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1='\0';
}

void cat(char *str1, char *str2)
{
    while(*str1!='\0')
    {
        str1++;
    }
    while(*str2!='\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }
}


void reverse(char *str1, char *str2)
{
    int i=0;
    while(*str2!='\0')
    {
        str2++;
        i++;
    }
    str2--;

    while(i!=0)
    {
        *str1=*str2;
        str2--;
        str1++;
        i--;
    }
    *str1='\0';
}


int point(char *str1, char *str2)
{
    char *x=str1;
    char *y=str2;
    printf("%d\n", x);
    for( ; *str1!='\0';str1++)
    {
        x=str1;
        while(1)
        {
            if(*y=='\0')
                return str1;
            else if(*x++!=*y++)
                break;
        }
        y=str2;
    }
    return 0;
}

int main() {
    char str1[10]="aaabcaaabcasd";
    char str2[10]="abc";
    printf("%d", point(str1,str2));
}

