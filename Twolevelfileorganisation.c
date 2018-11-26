//C program to implement Two level file organisation
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
    printf("\n\nTwo Level File Organisation\n\n");
    
    while(1)
    {
        printf("What do you want to do?\n1.Create file\n2.Delete file\n3.Display files\n4.Search files\n5.Create Directory\n6.Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter name of directory to create file in: ");
                scanf("%s",name);
                strcpy(command,"cd ");
                strcat(command,name);
                strcat(command," ; ");
                printf("\nEnter name of file to be created: ");
                strcat(command,"touch ");
                scanf("%s",name);
                strcat(command,name);
                system(command);
                break;

            case 2: printf("Enter name of directory to delete file from: ");
                scanf("%s",name);
                strcpy(command,"cd ");
                strcat(command,name);
                strcat(command," ; ");
                printf("\nEnter name of file to be deleted: ");
                strcat(command,"rm ");
                scanf("%s",name);
                strcat(command,name);
                system(command);
                break;

            case 3: //strcpy(command,"ls | grep -v single-level-file-organisation.c a.out");
                system("cd /home/ritcsos/.mine/two-level-file-organisation");
                system("ls -R -I single-level-file-organisation.c -I a.out -I two-level-file-organisation.c");
                printf("\n");
                break;
            
            case 4: printf("\nEnter name of file to find: ");
                strcpy(command,"find . -name ");
                scanf("%s",name);
                strcat(command,name);
                system("cd /home/ritcsos/.mine/two-level-file-organisation");
                system(command);
                break;

            case 5: printf("Enter name of directory to create: ");
                    strcpy(command,"mkdir ");
                    scanf("%s",name);
                    strcat(command,name);
                    system(command);
                    break;

            case 6: exit(0);
        
                
        }
    }


}