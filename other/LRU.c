#include <stdio.h>

struct frames{
 int content,count;
}frame[100];

int i,j,k;//looping variables
int p,f;// No. of pages and frames
int pages[100];// to hold the page sequence
int count=1;//Keeps track of current time 
int min;
int pf=0;
int id=0;

void main(){
	printf("\nEnter the number of pages:");
	scanf("%d",&p);
	printf("\nEnter the page sequence:");
	for(i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("\nEnter the number of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		frame[i].content=-1;
		frame[i].count=0;
	}
	
	printf("\n| Referncing Page\t| Status |\tFrame_Contents |\n");
	for(i=0;i<p;i++)
	{
		printf("\t%d\t\t\t",pages[i]);
		for(j=0;j<f;j++)
		{
			if(pages[i]==frame[j].content)
			{
				printf("HIT");
				frame[j].count=count++;
				break;
			}
		}
		if(j==f)
		{
			printf("MISS\t");
			if(id<f)
			{
				frame[id].content=pages[i];
				frame[id].count=count++;
				id++;
			}
			else
			{
				min=0;
				for(j=0;j<f;j++)
				{
					if(frame[j].count<frame[min].count)
					{
						min=j;
					}
				}
				frame[min].content=pages[i];
				frame[min].count=count++;
			}
			pf++;
		}
		for(j=0;j<f;j++)
		{
			if(frame[j].content!=-1)
			{
				printf(" %d ",frame[j].content);
			}
			else
			{
				printf("- ");
			}
		}printf("\n");
	}printf("\nPage Fault: %d\n",pf);
}


