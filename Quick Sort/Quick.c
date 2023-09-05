//Quick sort
#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int low,int high,int *f)
{
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
            (*f)++;
        }
        while(arr[j]>pivot)
        {
            j--;
            (*f)++;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int arr[],int low,int high,int *f)
{
    if(low<high)
    {
        int j=partition(arr,low,high,f);
        quicksort(arr,low,j-1,f);
        quicksort(arr,j+1,high,f);
    }
}
// int main()
// {
//     int n,i,j,temp,f=0;
//     printf("Enter n ");
//     scanf("%d",&n);
//     if(n==0)
//     {
//         printf("Empty array");
//         return 0;
//     }
//     int arr[n];
//     for(i=0;i<n;i++,f++)
//     {
//         printf("enter value ");
//         scanf("%d",&arr[i]);
//     }
//     quicksort(arr,0,n-1,&f);
//     printf("\nSorted array: ");
//     for(i=0;i<n;i++,f++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\nNumber of steps: %d",f);
// }