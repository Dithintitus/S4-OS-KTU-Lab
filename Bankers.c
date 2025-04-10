#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int avail[100];
int resmax[100];
int maxalloc[100];
int req[100];
struct process
{
  char name[100];
  int max[100];
  int alloc[100];
  int need[100];
  int done;
}p[20],temp;

void main()
{
  int i,j,r,pr,flag,ls,ml=0,g=0,id;
  char name[100],str[100] = "";
  printf("Enter the number of resources : ");
  scanf("%d",&r);
  printf("Max count of resources: \n");
  for(j=0;j<r;j++)
  {
    printf("\tRESOURCE %d : ",j+1);
    scanf("%d",&resmax[j]);
  }
  printf("\nEnter the no of process : ");
  scanf("%d",&pr);
  for(i=0;i<pr;i++)
  {
    printf("\nEnter the process name: ");
    scanf(" %s",p[i].name);
    printf("\nDetails of process %s",p[i].name);
    for(j=0;j<r;j++)
    {
      printf("\n\tMax allocation of resource %d : ",j+1);
      scanf("%d",&p[i].max[j]);

      printf("\tAllocated resource %d : ",j+1);
      scanf("%d",&p[i].alloc[j]);

      maxalloc[j] = maxalloc[j] + p[i].alloc[j];
      p[i].need[j] = p[i].max[j] - p[i].alloc[j];
    }
    p[i].done = 0;
  }
  for (i=0;i<r;i++)
  {
    avail[i] = resmax[i] - maxalloc[i];
  }
  printf("\nEnter a request :-  \n\n");
  printf("Enter name of process : ");
  scanf("%s",name);
  for(j=0;j<r;j++)
  {
      printf("\t Request of resource %d : ",j+1);
      scanf("%d",&req[j]);
  }
  for (i=0;i<pr;i++)
  {
      if(strcmp(p[i].name,name)==0)
      {
          id = i;
          break;
      }
  }
  for(flag=0,i=0;i<r;i++)
  {
      if(req[i] <= p[id].need[i])
      {
          flag++;
      }
  }
  if(flag !=r)
  {
      printf("RESOURCE NOT GRANTED!! \nNOT A VALID REQUEST");
      exit(0);
  }
  else if(flag == r)
  {
      for(i=0;i<r;i++)
      {
          p[id].alloc[i] =  p[id].alloc[i] + req[i];
          p[id].need[i] =  p[id].need[i] - req[i];
          avail[i] = avail[i] - req[i];
      }
  }
  printf("\n  PROCESS \tMAXIMUM \tALLOCATED \tREMAINING\n");
  for(i=0;i<pr;i++)
  {
    printf("\n     %s      \t ",p[i].name);
    for(j=0;j<r;j++)    //Max
    {
      printf("%d ",p[i].max[j]);
    }
    printf(" \t  ");
    for(j=0;j<r;j++)    //Alloc
    {
      printf("%d ",p[i].alloc[j]);
    }
    printf("\t  ");
    for(j=0;j<r;j++)    //Need
    {
      printf("%d ",p[i].need[j]);
    }
  }

  printf("\n\nOrder of execution :- \n");
  for(i=0,ls=0;ls<pr;)
  {
    for(flag = 0,j=0;j<r;j++)
    {
      if(avail[j]>=p[i].need[j])
      {
        flag++;
      }
    }
    if(flag == r && p[i].done == 0)
    {
      p[i].done = ls+1;
      for(ml=0,j=0;j<r;j++)
      {
        avail[j] = avail[j] + p[i].alloc[j];
        if(avail[j]==resmax[j])
        {
          ml++;
        }
      }
      g++;
      ls++;
      printf("\t\t%s has been visited \n",p[i].name);
      strcat(str,p[i].name);
      strcat(str,", ");
    }
    else
    {
      i++;
      if(i==pr)
      {
        if(g==0)
        {
          printf("\t\tREQUEST NOT ALLOCATED -- DEADLOCK OCCURED\n");
          break;
        }
        i=0;
        g=0;
      }
    }
  }
  if(ml==r && ls == pr)
  {
    printf("\nSAFE STATE\n");
    printf("\nSAFE STATE SEQUENCE : %s",str);
    printf("\b\b.  \n");
  }
  else if(g==0)
  {
    printf("\nUNSAFE STATE\n");
  }
}