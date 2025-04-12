#include<stdio.h>

void main()
{
	int i,j,p=0,n,m,h,t[50],k,a[50],temp,total=0;
	printf("\n\t\tCSCAN\n");

	printf("\nEnter the number of tracks:");
	scanf("%d",&n);
	printf("\nEnter the head position:");
	scanf("%d",&h);
	printf("\nEnter the tracks:->\n");
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(t[j]>t[j+1])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(t[i]>=h)
		{
			k=i;
			break;
		}
	}

	p = 0;  // Reset p before starting traversal
	// From head position to largest track
	for(i=k;i<n;i++,p++)
		a[p]=t[i];
	// From smallest track to position before head (circular behavior)
	for(i=0;i<k;i++,p++)
		a[p]=t[i];

	printf("\n\t\tTraversing Order\n");
	for(i=0;i<p;i++) 
	{
		printf("%d", a[i]);
		if(i < p-1)  // Proper termination of output
			printf(" -> ");
	}
	
	for(total=0,j=0;j<p-1;j++)
	{
		int diff=0;
		if(a[j]>a[j+1])
			diff=a[j]-a[j+1];
		else
			diff=a[j+1]-a[j];
		total=total+diff;
	}
	printf("\n\n\tTotal Head Movement:%d\n",total);
}
