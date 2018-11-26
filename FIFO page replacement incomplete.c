//C program to implement FIFO page replacement algorithm

#include<stdio.h>

void main()
{
    int frames,n,i,j,temp,page_faults=0,flag=0;
    printf("\n\nFIFO page replacement algorithm \n\n");
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int RAM[frames];  //array to represent pages in actual RAM
    int requests[n];
    printf("\n");
    
    //inputting the requests
    for(i=0;i<=n-1;i++)
    {
        printf("Enter request %d: ",i+1);
        scanf("%d",&requests[i]);
    }

    //filling the pages in RAM with -1
    for(i=0;i<=n-1;i++)
    {
        requests[i]=-1;
    }

    for(i=0;i<=n-1;i++)
    {
        
    }

}