//C program to implement FCFS scheduling
 
#include<stdio.h>
void main()
{
    int j,temp1,temp2,n,i,burst[50],arrival[50],turnaround[50],waiting[50],completion[50];
    printf("Enter number of processes:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("Enter Burst time of process %d :",i+1);
        scanf("%d",&burst[i]);
        printf("Enter arrival time of process %d :",i+1);
        scanf("%d",&arrival[i]);
    }
 
 
//Scheduling assuming arrival time is zero for all
    int time;
    time=arrival[0];
    for(i=0;i<=n-1;i++)
    {
        completion[i]=time+burst[i];
        time=completion[i];
    }
 
//Turnaround time
 
    for(i=0;i<=n-1;i++)
    {
        turnaround[i]=completion[i]-arrival[i];
    }
 
//Waiting time
 
    for(i=0;i<=n-1;i++)
    {
        waiting[i]=turnaround[i]-burst[i];
    }
 
 
//Printing
    printf("Process \t Arrival \t Burst \t Completion \t turnaround \t waiting \t \n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t \n",i+1,arrival[i],burst[i],completion[i],turnaround[i],waiting[i]);
    }
 
 
//Calculating average
    int turnaround_sum=0,waiting_sum=0;
    for(i=0;i<=n-1;i++)
    {
        turnaround_sum=turnaround_sum+turnaround[i];
        waiting_sum=waiting_sum+waiting[i];
    }
 
    printf("\n Average Turnaround time= %d",turnaround_sum/n);
    printf("\n Average Waiting time= %d",waiting_sum/n);
 
printf("\n\n");
}