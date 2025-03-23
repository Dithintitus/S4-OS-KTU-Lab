#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct process{
    char pname[10];
    int pt,at,bt,wt,tt,ct,status;
}p[20];

struct gantt{
    char name[20];
    int st,ct;
}g[20];

void main()
{
    int i,num;

    printf("Enter how many process that you want to enter:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("\nEnter the process name");
        scanf("%c",p[i].pname);
        printf("Enter the arrival time:");
        scanf("%d",&p[i].at);
        printf("Enter the Burst time:");
        scanf("%d",&p[i].bt); 
        printf("Enter the Priority of the process:");
        scanf("%d",&p[i].pt);
        printf("\nThe process has been added.\n");
    }
    int idle=0,cp=0,flag;

    for(i=0,idle=0,cp=0;cp<num;i++)
    {
        flag=0;
        for(int j=0;j<num;j++)
        {

        }
    }