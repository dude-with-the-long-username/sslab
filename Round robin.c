//implement round robin and find avg. turnaround time and avg. waiting time.
 
 
#include<stdio.h>
void main()
{
    double quantum,start_time,time,temp,temp1,temp2,temp3,temp4,burst[50],turnaround[50],waiting[50],completion[50],arrival[50],burst_temp[50];
    int i,j,n,order[50];
    printf("\t\t\t ROUND ROBIN\n\n");
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter time quantum:");
    scanf("%lf",&quantum);
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
 
 
    
    //copying burst[i] into burst_temp[i]
    for(i=0;i<=n-1;i++)
    {
        burst_temp[i]=burst[i];
    }
   
    //Executing processes
    time=start_time;
    float check_zero;               //checks if all remaining burst_temp are zero
    check_zero=burst[0];
    while(check_zero!=0)
    {
    
        for(i=0;i<=n-1;i++)
        {
            if(burst_temp[i]>=quantum)
            {
                completion[i]=time+quantum;
                time=time+quantum;
                burst_temp[i]=burst_temp[i]-quantum;
            }
        
            else if(burst_temp[i]<quantum && burst_temp[i]>0)
            {
                completion[i]=time+burst_temp[i];
                time=time+burst_temp[i];
                burst_temp[i]=0;
            }
        
            else
                continue;
        
        }
                
        check_zero=0;
        //for loop to check if sum of burst is zero to check if execution finished
        for(i=0;i<=n-1;i++)
        {
            check_zero=check_zero+burst_temp[i];
        }
            
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