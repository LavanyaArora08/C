#include<stdio.h>
#include<string.h>
int main()
{
    char text[100],pattern[100];
    int i,j,n,m;
    printf("Enter text ");
    scanf("%s",text);
    printf("Enter pattern ");
    scanf("%s",pattern);
    if(strlen(pattern)>strlen(text))
    {
        printf("Pattern longer than text");
        return 0;
    }
    n=strlen(text);
    m=strlen(pattern);
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
                break;
        }
        if(j==m)
        {
            printf("Pattern found at %d",i);
            return 0;
        }
    }
    printf("Pattern not found");
    return 0;
}


