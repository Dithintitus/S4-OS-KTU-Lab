#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct process{
    int at,wt,bt,tt,ct,status;
    char name[5];
}p[40];

struct Gantt{
    char name[5];
    int st,ct;
}g[40];

void main()
{
    int i,j,num;
    float avgwt=0.0, avgtt=0.0;

    printf("Enter the number of processes: ");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        printf("\nEnter the name of the process:");
        scanf("%s",p[i].name);
        printf("Enter Arrival time:");
        scanf("%d",&p[i].at);
        printf("Enter Burst time:");
        scanf("%d",&p[i].bt);
        p[i].status=0;
    }
    int min=0,idle=0,fp=0; //fp->found process

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(p[j].at<=i&&p[j].status==0)
            {
                if(!fp||p[j].bt<p[min].bt)
                {
                    min=j;
                    fp=1;
                }
                else if(p[j].bt==p[min].bt)
                {
                    if(p[j].at<p[min].at)
                    {
                        min=j;
                        fp=1;
                    }
                }
            }
        }   
    }
    
    
    if(fp)
    {

    }
}