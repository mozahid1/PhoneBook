#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
    char name[35];
    long int mble_no;
    char gender[8];
    };
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()

{
    system("color 1f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\n\t\tWELCOME TO THE PHONEBOOK");
printf("\n\t\t^-^-^-^-^-^-^-^-^-^-^-^-^");

printf("\n\nEnter your choice number");
printf("\n\n\t1. Add New   \n\n\t2. List of Contacts   \n\n\t3.Delete Contacts   \n\n\t4. Modify Contacts \n\n\t5. Search for Contacts\n\n\t6. Exit Menu\n");

switch(getch())
{
    case '1':
             addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': deleterecord();
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': exit(0);
    break;
    default:
                //system("cls");
                printf("\nEnter a number from 1 to 6 only");
                printf("\n Enter any key");
                getch();
menu();
}
}
        void addrecord()
{
        //We add the record of contacts here
        //system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\nEnter name: ");
        got(p.name);

        printf("\nEnter phone number:");
        scanf("%ld",&p.mble_no);
        printf("Enter gender:");
        got(p.gender);

        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    //system("cls");
    menu();
}
void listrecord()
{
    //We can see the list of contacts
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\nYour record is\n");
        printf("\nName=%s\nMobile no=%ld\nGender=%s\n\nPress 1 to 6 for next contact\n",p.name,p.mble_no,p.gender);

	 getch();
	 //system("cls");
}
fclose(f);
 printf("\nEnter any key");
 getch();
    //system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\nNo Contacts.\n");
    exit(1);

}
printf("\nEnter name of person to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\nMobile no:%ld\ngender:%s:%s",p.name,p.mble_no,p.gender);
    }
        else
        printf("file not found");
}
 fclose(f);
  printf("\nEnter any key");

	 getch();
    //system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		ft=fopen("temp", "wb+");
		if(ft==NULL)

            printf("No Contact. ");
		else
        {
		printf("Enter Contact's name:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONTACTS RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("\nRECORD DELETED SUCCESSFULLY.");
		}
	}
}
 printf("\nEnter any key");
getch();
    //system("cls");
menu();
}
void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{
printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);
		}
	else
	{
    //system("cls");
		printf("\nEnter contact's name to modify:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {
                    printf("\nEnter name:");
                    got(s.name);

                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);

                    printf("\nEnter gender:");
                    got(s.gender);

                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
                }
                fflush(stdin);
                }
            if(flag==1)
            {
                printf("\nYour data ID modified");

            }
            else
            {
                    printf(" \nData not found");
            }
            fclose(f);
	}
	 printf("\nEnter any key");
	 getch();
    //system("cls");
	menu();
}
void got(char *name)
{
int i=0,j;
    char c,ch;
    do
    {
    c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    //system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);
                    }
                }
    }while(c!=13);
      *(name+i)='\0';
}
