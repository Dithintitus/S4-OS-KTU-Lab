#include<stdio.h>

void main()
{
	int i,j,p,f,pg[100],fr[100],k=0,found,count=0;
	printf("\nEnter the number of pages:");
	scanf("%d",&p);
	printf("\nEnter the reference pages:\n");
	for(i=0;i<p;i++)
	{
		scanf("%d",&pg[i]);
	}
	printf("\nEnter the number of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		fr[i]=-1;
	}
	
	printf("\n\tReference String |\t| Status |\t| Frame contents\n");
	for(i=0;i<p;i++)
	{	
		found=0;
		printf("\t\t%d\t\t",pg[i]);
		for(j=0;j<f;j++)
		{
			if(fr[j]==pg[i])
			{
				found=1;
			}
		}
		if(found==0)
		{
			fr[k]=pg[i];
			k=(k+1)%f;
			count++;
		}
		for(j=0;j<f;j++)
		{
			if(fr[j]!=-1)
			{
				printf("%d ",fr[j]);
			}
			else
				printf("-");
		}
		if(found==1)
		{
			printf("\t\t HIT \n");
		}
		else
		{
			printf("\t\t MISS \n");
		}
	}
	printf("\nPage faults:%d\n",count);
}
