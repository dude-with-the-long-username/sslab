//C program to implement SCAN disk scheduling algorithm

#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,requests[500],start,size,seek_time,new_requests[500],max_disks,highest_cylinder;
    float avg_seek_time;
    int i,j,temp,temp1,temp2,temp3;
    printf("\n\n\t\tSCAN DISK SCHEDULING\n\n");
    printf("Max number of disks is assumed to be 200 ie; from 0 to 199\n\n");
    printf("Enter start position(cylinder) of disk head: ");
    scanf("%d",&start);
    printf("Enter number of requests:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)     //inputting requests
    {
        printf("Enter request %d: ",i+1);
        scanf("%d",&requests[i]);
    }


    //selection sort array in ascending order
    for(i=0;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(requests[j]<requests[i])
            {
                temp=requests[i];
                requests[i]=requests[j];
                requests[j]=temp;
            }
        }
    }

    /*printing sorted array
    for(i=0;i<=n-1;i++)
        printf("\t%d",requests[i]);*/

   
    seek_time=0;    //initialize
    //originally head goes from 1)start to 0 and then 2)from 0 to highest cylinder while scheduling everything in that path
    seek_time=0+start; //seek time from start position to zero is same as seek time from zero to start position
    //seek_time=seek_time+seek_time; 
    highest_cylinder=requests[n-1]; //coz we already sorted all requests in ascending order
    seek_time=seek_time+highest_cylinder; //coz 

    printf("Seek time is : %d \n",seek_time);
    double fl_seek_time= (float) seek_time;
    float fl_n= (float) n;
    avg_seek_time=fl_seek_time/fl_n;      //   total seek time/no.of requests
    printf("Average seek time is : %f\n",avg_seek_time);

    printf("\n");

}