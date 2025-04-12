#include<stdio.h>

void main()
{
	int i,n,m,tr[20],sum=0,new;

	printf("\nEnter the number of tracks:");
	scanf("%d",&n);
	printf("\nEnter the head postion:");
	scanf("%d",&m);
	printf("\nEnter the tracks:->\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&tr[i]);
		new=m-tr[i];
		if(new<0)
			new=tr[i]-m;
		m=tr[i];
		sum+=new;
	}
	printf("\n\tTraversing Order\n");
	for(i=0;i<n;i++)
	{
		printf("%d",tr[i]);
		if(i<n-1)
			printf(" => ");
		else
			printf(".");
	}
	printf("\nTotal head:%d",sum);
}
