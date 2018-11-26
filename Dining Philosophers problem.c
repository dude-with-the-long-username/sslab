//C program to implement dining philosopher's problem

#include<stdio.h>

void wait();
void signal();

void main()
{   
    int i,j,temp,n,flag=0;
    printf("\n\nDining Philosopher's Problem\n\n");
    printf("Enter number of philosophers: ");
    scanf("%d",&n);
    int philosopher[n];
    
    for(i=0;i<=n-1;i++)
    {
        philosopher[i]=0;   //putting all values as 0(thinking)
    }

    philosopher[0]=-1; //first philosopher is hungry
    philosopher[n-1]=1; //last philosopher is eating

    i=n-1;

    while(flag==0)
    {
        for(j=0;j<=n-1;j++)
        {
            if(philosopher[j]==1)
                printf("\nPhilosopher %d is eating ",j+1);
            else if(philosopher[j]==0)
                printf("\nPhilosopher %d is thinking ",j+1);
            else if(philosopher[j]==-1)
                printf("\nPhilosopher %d is hungry ",j+1);
            else
                printf("This condition should not occur");  //simply a check statement
        }
        philosopher[i]=0;
        philosopher[(i+1)%n]=1;
        philosopher[(i+2)%n]=-1;

        i=(i+1)%n;

        printf("\nDo you want to continue?\n1.yes\n2.no\nchoice: ");
        scanf("%d",&temp);
        if(temp==2)
            flag=1;
    }

}