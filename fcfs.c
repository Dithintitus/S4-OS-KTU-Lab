#include<stdio.h>
#include<string.h>

struct process{                 //structure to store process details
    char pname[20];
    int at,bt,wt,tt,ct,status;
}p[20],t;

struct name{                    //structure to store gantt chart details
    char name[20];
    int ct,st;
}d[40];

void main()
{
    int num,i,j,k; 
    float sumwt=0.0,sumtt=0.0,avgwt,avgtt;
    //input the number of processes
    printf("\nEnter the number of processes:");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {   //input the process details
        printf("\nEnter the process name:");
        scanf("%s",p[i].pname);
        printf("Enter the arrival time:");
        scanf("%d",&p[i].at);
        printf("Enter the burst time:");
        scanf("%d",&p[i].bt);
        p[i].status=0; //initialize the status to 0 i.e. not executed
    }

    //Sorting processes based on arrival time
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    
    int idle=0; //to check if the cpu is idle
    k=0;        //process index
    int n=0;    //gantt chart index

    //process scheduling
    for(i=0;k<num;)
    {
        if(p[k].status==0 && p[k].at<=i)
        {
            if(idle==1)
            {
                d[n-1].ct=i;
                n++;
            }
            strcpy(d[n].name,p[k].pname);
            d[n].st=i;
            d[n].ct=i+p[k].bt;

            p[k].wt = d[n].st - p[k].at; //calculate waiting time
            p[k].tt = p[k].wt + p[k].bt; //calculate turnaround time
            p[k].ct = d[n].ct;           //calculate completion time

            i=d[n].ct;                   //update the time
            p[k].status=1;        //update the status or marking the process as executed
            k++;
            n++;
            idle=0;               //reset the idle flag
        }
        else if(idle==0)
        {
            strcpy(d[num].name,"idle");
            d[num].st=i;
            i++;
            idle=1;             //set the idle flag
        }
        else{
            i++;
        }
    }
        
    printf("\n__Gant Chart__\n");
       
    for(i=0;i<n;i++)
    {
        printf("----");
        int processtime = d[i].ct - d[i].st;
        for(int x=0;x<processtime;x++)
        {
            printf("-");
        }
    }
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        printf("|%s",d[i].name);
        int processtime = d[i].ct - d[i].st;
        for(int y=1;y<processtime;y++)
        {
            printf(" ");
        }
    }
    printf("|\n");

    for(i=0;i<n;i++)
    {
        printf("----");
        int processtime = d[i].ct - d[i].st;
        for(int x=0;x<processtime;x++)
        {
            printf("-");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",d[i].st);
        int processtime = d[i].ct - d[i].st;
        for(int x=0;x<=processtime;x++)
        {
            printf(" ");
        }
    }
    printf("%d",d[num-1].ct);
    printf("\n");

    //calculate the average waiting time and average turnaround time
    for(i=0;i<num;i++)
    {
        sumwt=sumwt+p[i].wt;
        sumtt=sumtt+p[i].tt;
    }
    avgwt=sumwt/num;
    avgtt=sumtt/num;

    printf("\nAverage Waiting time:%f\n",avgwt);
    printf("\nAverage Turnaround time:%f\n",avgtt);   
}