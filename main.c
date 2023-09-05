#include<stdio.h>
int main()
{
	int n,i,beg,mid,end,flag=0,item;
	printf("Enter n ");
	scanf("%d",&n);
    int arr[n];
	for(i=0;i<n;i++)
	{
		printf("enter value ");
		scanf("%d",&arr[i]);
	}
	printf("Enter item");
	scanf("%d",&item);
	beg=0;
	end=n;
	if(end==0)
	{
		printf("Empty array");
		flag=1;
	}
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==item)
		{
			printf("Element found at %d",mid+1);
			flag=1;
			break;
		}
		else
		if(arr[mid]<item)
		{
			beg=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	if(flag==0)
	{
		printf("Element not found");
	}
}