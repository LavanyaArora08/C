#include<stdio.h>
int main()
{
    int n,i,j,temp,f=0;
    printf("Enter n ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("Empty array");
        return 0;
    }
    int arr[n];
    for(i=0;i<n;i++,f++)
    {
        printf("enter value ");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++,f++)
    {
        for(j=0;j<n-i-1;j++,f++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            for(int k=0;k<n;k++,f++)
            {
                printf("%d ",arr[k]);
            }
            printf("\n");

        }
        printf("Pass %d: ",i+1);
        for(j=0;j<n;j++,f++)
        {
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
    printf("\nSorted array: ");
    for(i=0;i<n;i++,f++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nNumber of steps: %d",f);
}
// find 1. total number of swaps in each pass
//      2. total not swaps in each pass
//      3. total number of steps