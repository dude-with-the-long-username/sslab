//not mine
//C program to implement FIFO page replacement algorithm

/*#include<stdio.h>

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

}*/

#include <stdio.h> 
int main(){
      int reference_string[10], page_faults = 0, m, n, s, pages, frames;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++){
            printf(" [%d]:\t", m + 1);
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames:\t");{
            scanf("%d", &frames);
      }
      int temp[frames];
      for(m = 0; m < frames; m++){
            temp[m] = -2;
      }
      for(m = 0; m < pages; m++){
            s = 0;
            for(n = 0; n < frames; n++){
                  if(reference_string[m] == temp[n]){
                        s++;
                        page_faults--;
                  }
            }
            page_faults++;
            if((page_faults <= frames) && (s == 0)){
                  temp[m] = reference_string[m];
            }
            else if(s == 0){
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
/*            printf("\n");
            for(n = 0; n < frames; n++){
                  printf("%d\t", temp[n]);
          }*/
      }
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
	}