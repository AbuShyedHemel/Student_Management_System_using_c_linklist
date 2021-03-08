#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct student{
char name[100];
char roll[10];
int a;
struct student *next;
};
struct student *first=NULL,*last=NULL,*k;
void create(int n)
{
int i;
first=(struct student*)malloc(sizeof(struct student));
printf("\nEnter the first name of the student:");
scanf("%s",first->name);
printf("\nEnter the roll number of the student:");
scanf("%s",first->roll);
printf("\nEnter the Contact:");
scanf("%d",&first->a);
first->next=NULL;
last=first;
for(i=1;i<n;i++)
    {
k=(struct student*)malloc(sizeof(struct student));
printf("\nYou Can Add More...............\n");
printf("\nEnter the first name of the student:");
scanf("%s",k->name);
printf("\nEnter the roll number of the student:");
scanf("%s",k->roll);
printf("\nEnter the Contact:");
scanf("%d",&k->a);
k->next=NULL;
last->next=k;
last=k;
}
}


void display()
{
struct student *t;
t=first;
while(t!=NULL)
{
printf("\nThe Details Of The Student!!!\n\n\n");
printf("Name                      Contact                    \tRoll\n");
printf("%s",t->name);
printf("                                                 \t%s\n",t->roll);
printf("                          %d",t->a);
t=t->next;
}
}


void insertafter()
{
char r[10];

printf("\nEnter the Roll number u wanna insert after that:");
scanf("%s",r);
struct student *t;
t=first;
while(t!=NULL)
{
  if(strcmp(r,t->roll)==0)
{
    k=(struct student*)malloc(sizeof(struct student));
    printf("\nEnter The Name Of The Student:");
    scanf("%s",k->name);
    printf("\nEnter The Roll Of The Student:");
    scanf("%s",k->roll);
    printf("\nEnter the Contact:");
    scanf("%d",&k->a);
    k->next=t->next;
    t->next=k;

break;
}
    t=t->next;
}
    printf("\nThe element not found!!!");
}

void del()
{
struct student *temp = first ;
char r[10];
    printf("\nEnter the roll number u wanna delete:");
    scanf("%s",r);
if(strcmp(temp->roll,r)==0)
{
    first = temp->next;
    free(temp);
}
else
{
    while(temp->next!=NULL && strcmp(temp->roll,r)!=0 )
    {
        temp = temp->next;
    }
    if ( temp->next == NULL )
    {
        printf("Data Not Found\n");
    }
    else
    {
        struct student *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}
}




void search()
{
char r[10];
printf("\nEnter the roll number u wanna search:");
scanf("%s",r);
struct student *t;
t=first;
while(t!=NULL)
{
if(strcmp(r,t->roll)==0)
{
printf("\nThe roll number found in the list!!!\n\n\n");
printf("Name:                                         \tRoll:\n");
printf("%s",t->name);
printf("                                            \t%s\n",t->roll);
printf("............................................................");
printf("\nContact                                             :%d",t->a);

break;
}
t=t->next;
}
printf("\n\n\n\nThe roll number not in database!!");
}

void password()
{
    char master_pass[100] = "1234" , pass[100] = "\0" , c ;
    int i = 0 ;

    while( 1 )
    {
        printf("\nEnter your password : ");

        while( ( c = getch() ) != 13  )
        {
            if ( c == 8 )
            {
                continue;
            }
            else
            {
                pass[i] = c ;
                printf("*");
                i++;
            }

        }
        i = 0 ;

        if ( strcmp(master_pass,pass)==0 )
        {
            break;
        }
        else
        {
            printf("\nWrong Password.\n");
        }
    }

}
void loading_anim()
{
    int x , y ;


    printf("                   L O A D I N G \n");
    for(x = 0; x<=50; x++ , y++ )
    {

        printf("\xB2");
        Sleep(rand() % 20 + 30 );
    }
}

break_loop = 0 ;

int main()
{
int n,o;

if (break_loop == 0 )
{
    loading_anim();
    password();
    break_loop++;
}

while(o!=0)
{
printf("\n                 MENU");
printf("\n******************************************\n");
printf("\n1. For creating database \t                2. For displaying database\n");
printf("Press 1                                   \tPress 2\n");

printf("\n3. For inserting an record after another\t4. For deleting a record");
printf("\nPress 3                                   \tPress 4\n");
printf("\n5. For searching a record");
printf("\nPress 5\n");
printf("\nEnter 0 for exit!\n");
printf("\n\n*******************************************\n");
printf("             Enter the choice:");
scanf("%d",&o);
switch(o)
{
case 1:printf("\nEnter the maximum size of the database:");
scanf("%d",&n);
create(n);
break;
case 2:display();break;
case 3:insertafter();break;
case 4:del();break;
case 5:search();break;
case 0:exit(0);break;
default:printf("\nYou have entered a wrong choice!!!");
}
}
getche();
}
