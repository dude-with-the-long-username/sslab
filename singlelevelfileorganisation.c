//C program to implement single level file organisation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    //char name[]="ls";
    //system(name);   executes bash script
    //exit(0);      exit program with success
    //exit(1);      exit program with error code
    //ls -I file_you_don't_want_to_display
    int i,j,temp,choice;
    char name[50],command[50];
    printf("\n\nSingle Level File Organisation\n\n");
    
    while(1)
    {
        printf("What do you want to do?\n1.Create file\n2.Delete file\n3.Display files\n4.Search files\n5.Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter name of file to be created: ");
                strcpy(command,"touch ");
                scanf("%s",name);
                strcat(command,name);
                system(command);
                break;

            case 2: printf("\nEnter name of file to be deleted: ");
                strcpy(command,"rm ");
                scanf("%s",name);
                strcat(command,name);
                system(command);
                break;

            case 3: //strcpy(command,"ls | grep -v single-level-file-organisation.c a.out");
                system("ls -I single-level-file-organisation.c -I a.out");
                break;
            
            case 4: printf("\nEnter name of file to find: ");
                strcpy(command,"find ");
                scanf("%s",name);
                strcat(command,name);
                system(command);
                break;

            case 5: exit(0);
        
                
        }
    }


}