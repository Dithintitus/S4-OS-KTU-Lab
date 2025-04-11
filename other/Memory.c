#include<stdio.h>

void firstfit(int size[25],int x,int msi[25],int y);
void worstfit(int size[25],int x,int msi[25],int y);
void bestfit(int size[25],int x,int msi[25],int y);

void main(){
    int psize[25],msize[25],p,m,i,j;
    printf("\nEnter number of processes:");
    scanf("%d",&p);
    printf("\nEnter number of memory partitions:");
    scanf("%d",&m);
    printf("\nRead process sizes:");
    for(i=0;i<p;i++){
        printf("\nEnter size of process %d:",i+1);
        scanf("%d",&psize[i]);
    }
    printf("\nRead partition sizes:");
    for(j=0;j<m;j++){
        printf("\nEnter size of partition %d:",j+1);
        scanf("%d",&msize[j]);
    }
    firstfit(psize,p,msize,m);
    worstfit(psize,p,msize,m);
    bestfit(psize,p,msize,m);
}    

void firstfit(int psize[25],int p,int msize[25],int m)
{
	int i,j,ps[25],ms[25],flag;
	printf("\n\t\tFIRST FIT");
	for(i=0;i<p;i++)
		ps[i]=psize[i];
	for(i=0;i<m;i++)
		ms[i]=msize[i];
	
	for(i=0;i<p;i++)
	{
		flag=0;
		for(j=0;j<m;j++)
		{
			if(ms[j]>=ps[i])
			{
				printf("\n\tThe %d has been allocated to %d\n",ps[i],ms[j]);
				flag=1;
				ms[j]=0;
				break;
			}
		}
		if(flag==0)
			printf("\n\t%d has yet to be allocated\n",ps[i]);
	}
}

void worstfit(int psize[25],int p,int msize[25],int m)
{
        int i,j,ps[25],ms[25],loc,max;
        printf("\n\t\tWORST FIT");
        for(i=0;i<p;i++)
                ps[i]=psize[i];
        for(i=0;i<m;i++)
                ms[i]=msize[i];

        for(i=0;i<p;i++)
        {
                loc=0;
		max=ms[0];
                for(j=0;j<m;j++)
                {
                        if(ms[j]>max)
                        {
                                max=ms[j];
				loc=j;
                        }
			
                }
                if(max>=ps[i])
		{
			printf("\n\t%d has allocated to %d\n",ps[i],ms[loc]);
			ms[loc]=0;
		}
		else
			printf("\n\t%d has to wait to be allocated\n",ps[i]);	
        }
}

void bestfit(int psize[25],int p,int msize[25],int m)
{
        int i,j,ps[25],ms[25],loc;
        printf("\n\t\tBEST FIT");
        for(i=0;i<p;i++)
                ps[i]=psize[i];
        for(i=0;i<m;i++)
                ms[i]=msize[i];

        for(i=0;i<p;i++)
        {
                loc=-1;
                for(j=0;j<m;j++)
                {
                        if(ms[j]>=ps[i])
                        {
                                if(loc==-1)
					loc=j;
				else if(ms[loc]>ms[j])
					loc=j;
                        }
                }
                if(loc!=-1)
		{
			printf("\n\t%d has been allocated at %d\n",ps[i],ms[loc]);
			ms[loc]=0;
		}
		else
			printf("\n\t%d has yet to be allocated\n",ps[i]);
        }
}
