//C program to implement producer consumer problem (bounded buffer problem)
 
#include<stdio.h>
void wait();
void signal();
void printing();
 
 
int size,buffer[5],full,empty,i,j,temp,temp1,temp2,mutex,choice,flag,array_index,value,lower_limit;
//full & empty are counting semaphores and mutex is a binary semaphore
 
 
void main()
{
 
    printf("\n\n\t\t PRODUCER CONSUMER PROBLEM\n\n");
    printf("Enter size of buffer:");
    scanf("%d",&size);
 
    array_index=0;
    flag=0;
    lower_limit=0;
 
    while(flag==0)
    {
        printf("\nEnter choice:\n1.Produce into Buffer\n2.Consume from buffer\n3.Exit\n\nEnter choice: ");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:if(array_index<=size-1)        //we checked with 4 because we consider 0 to 4 and thus 5 spaces in buffer
                    {
                        signal();
                        printing();
                        break;
                    }
 
                    else
                    {
                        printf("\nBuffer Overflow! \nValue can't be added \n");
                        printing();
                        break;
                    }
 
 
            case 2:if(array_index>=lower_limit+1)
                    {
                        wait();
                        printing();
                        break;
                    }
 
                   
                    else
                    {
 
                        printf("\nBuffer Underflow! \nCan't delete from buffer as buffer is empty\n");
                        printing();
                        break;
                    }
 
            case 3: flag=1;
                    break;  
            default:printf("Enter valid choice\n");
                    break;
        }  
    }
 
 
    printf("\n\n");
 
}
 
 
void signal()
{
/*    full+=1;   //Producer produces 1 more resource
    empty-=1; */
    printf("Enter value to insert into buffer: ");
    scanf("%d",&value);
    buffer[array_index]=value;
    array_index=array_index+1;
 
}
 
void wait()
{
/*    empty+=1;   //consumer consumes 1 more resource
    full-=1; */
    printf("Value dropped: %d",buffer[lower_limit]);
    //array_index=array_index-1;
    //lower_limit=lower_limit+1;
    for(i=0;i<=array_index-2;i++)    //moving contents of array one step back after deleting first element
    {
        buffer[i]=buffer[i+1];
    }
    array_index=array_index-1;
 
}
 
void printing()         //Prints contents of buffer
{
    printf("\nContents of buffer is:");
    for(i=array_index-1;i>=lower_limit;i--)
    {
        printf("\t%d",buffer[i]);
    }
    printf("\n\n");
}