#include<stdio.h>
int main()
{
	int a[50],i,j,n,s,end,beg,mid,swap,flag=0;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			swap=a[j];
		  	a[j]=a[j+1];
			a[j+1]=swap;
	 		}
		}	
	}
	printf("sorted array\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
        printf("enter the search element\n");
        scanf("%d",&s);
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
	for(beg=0,end=n-1;beg<=end;mid=(beg+end)/2)
	{
		if(a[mid]==s)
		{
			printf("the element %d found at position %d",s,mid+1);
			flag=1;
			break;
		}
		else if(a[mid]<s)
			beg=mid+1;
		else
			end=mid-1;
	}if (flag==0)
	printf("search element not found");

}


