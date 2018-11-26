//implement SJF(non-preemptive) scheduling and find avg. turnaround time and avg. waiting time.
 
 
#include<stdio.h>
void main()
{
    double start_time,time,temp,temp1,temp2,temp3,temp4,burst[50],turnaround[50],waiting[50],completion[50],arrival[50];
    int i,j,n,order[50];
    printf("\t\t\t SJF\n\n");
    printf("Enter number of processes:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("Enter burst time of process %d:",i+1);
        scanf("%lf",&burst[i]);
        printf("Enter arrival time of process %d:",i+1);
        scanf("%lf",&arrival[i]);
        order[i]=i+1;
    }
   
    //finding shortest arrival time
    temp=arrival[0];
    for(i=0;i<=n-1;i++)
    {
        if(arrival[i]<temp)
        {
            temp=arrival[i];
        }
    }
 
    time=temp;
    start_time=time;
 
 
 
    //ordering by arrival time
    for(i=0;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(arrival[j]<arrival[i])
            {
                temp=arrival[i];
                temp2=burst[i];
                temp3=order[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;
                burst[i]=burst[j];
                burst[j]=temp2;
                order[i]=order[j];
                order[j]=temp3;
 
            }
        }
    }
 
 
    //ordering by burst time taking arrival time into account  [scheduling]
    for(i=0;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(burst[j]<burst[i] && arrival[j]<=time)
            {
                temp=arrival[i];
                temp2=burst[i];
                temp3=order[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;
                burst[i]=burst[j];
                burst[j]=temp2;
                order[i]=order[j];
                order[j]=temp3;
 
            }
        }
 
    time=time+burst[i];
    }
 
   
    //Executing processes
    time=start_time;
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
    printf("Process \t Arrival \t\t Burst \t\t\t Completion \t\t turnaround \t\t waiting \t \n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t \n",order[i],arrival[i],burst[i],completion[i],turnaround[i],waiting[i]);
    }
 
 
//Calculating average
    double turnaround_sum=0,waiting_sum=0;
    for(i=0;i<=n-1;i++)
    {
        turnaround_sum=turnaround_sum+turnaround[i];
        waiting_sum=waiting_sum+waiting[i];
    }
 
    printf("\n Average Turnaround time= %lf",turnaround_sum/n);
    printf("\n Average Waiting time= %lf",waiting_sum/n);
 
printf("\n\n");
 
}