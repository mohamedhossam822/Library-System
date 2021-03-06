#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//Global Variables
int c=0;  /*to count the number of books Registered*/
int m=0;  /*to count number of members*/
int b=0;  /*to count number of borrowings*/
typedef struct   /*Date Structure*/
{
    int day;
    int month;
    int year;
}Date;

typedef struct  /*Address Structure*/
{
    char build[10];
    char st[50];
    char city[50];
}Address;

struct Books
{
    char title[200];
    char isbn[50];
    char author[200];
    char publisher[200];
    Date book_date_release;
    int nofcopies;
    int current_nofcopies;
    char cat[200];
    int nbor;
}book[100];

struct Members
{
    char name[100];
    char age[3];
    char ID[5];
    char tel[15];
    Address m_address;
    char mail[100];
    int nobor; //Number of borrowings
}member[100];

struct Borrowings
{
    char Isbn_bor[50];
    char ID_bor[50];
    Date date_borrowed;
    Date date_due_to_return;
    Date date_returened;
}Borrowing[100];
//Function Declarations
void read_fbook();
void write_fbook();
void insertnewbook();
void addnewcopy();
void deletebook();
void searchbooks();
void printbooks();
void read_fmember();
void write_fmember();
void addnewmem();
void remove_member();
void printmembers();
void borrow_book();
void return_book();
void show_popbooks();
void print_borrow();
void write_fborrow();
void read_fborrow();
void Overdue_books();
int check_date(char*dd,char*mm,char*yy);
void Generate(char*temi);
int Validate_mail(char*email);
                                /*Main Program*/

int main()
{
    char choice;
    read_fbook();
    read_fmember();
    read_fborrow();
    printf("\t\t\t>> Welcome To Our Library <<\n");
    printf("\t\t\t   **********************\n\n");

    while(1)
    {
        //Printing The main menu
        system("cls");
        printf("Book Management(1)\n\n");
        printf("Member Management(2)\n\n");
        printf("Borrow Management(3)\n\n");
        printf("Administrative Actions(4)\n\n");
        printf("Save Changes(5)\n\n");
        printf("Exit(6)\n\n");
        printf("Please Enter Your Choice : ");
        fflush(stdin); scanf("%c",&choice);

        switch(choice)
        {

            case '1' :          //Book Management menu
            {
                system("cls");
                printf("\t\t\t>> Book Management Department <<\n");
                printf("\t\t\t   ************************** \n\n");
                printf("Insert a new book(1)\n\n");
                printf("Search for a book(2)\n\n");
                printf("Add a new copy(3)\n\n");
                printf("Delete book(4)\n\n");
                printf("Print Books information(5)\n\n");
                printf("Press any other key to go back to the main menu\n\n");
                printf("enter your choice : ");
                fflush(stdin); scanf("%c",&choice);

                switch(choice)
                {
                    case '1' :
                    insertnewbook();
                    break;
                    case '2' :
                    searchbooks();
                    break;
                    case '3' :
                    addnewcopy();
                    break;
                    case '4' :
                    deletebook();
                    break;
                    case '5' :
                    printbooks();
                    break;
                    default :
                    printf("\n\nGoing Back to main menu\n\n");
                    fflush(stdin);

                }

            }break; //Exiting Switch ...
            case '2' :          //Member Management
            {
                system("cls");
                printf("\t\t\t>> Member Management Department <<");
                printf("\n\t\t\t   ****************************\n\n");
                printf("\nAdd a new Member(1)\n\n");
                printf("\nRemove member(2)\n\n");
                printf("\nPrint members(3)\n\n");
                printf("\nPress any other key to go back to main menu\n\n");
                printf("\nenter your choice : ");
                getchar(); scanf("%c",&choice);
                switch (choice)
                {
                    case '1' :
                    addnewmem();
                    break;
                    case '2' :
                    remove_member();
                    break;
                    case '3' :
                    printmembers();
                    break;
                    default :
                    printf("\n\nGoing Back to main menu\n\n");
                    fflush(stdin);
                }
            }break;
            case '3' :          //Borrow Management
            {
                system("cls");
                printf("\t\t\t >> Borrowing Management <<\n");
                printf("\t\t\t    ********************\n\n");
                printf("borrow book(1)\n\n");
                printf("return book(2)\n\n");
                printf("print borrows(3)\n\n");
                printf("Press any other key to go back to main menu\n\n");
                printf("enter your choice : ");
                fflush(stdin); scanf("%c",&choice);
                switch(choice)
                {
                    case '1' :
                    borrow_book();
                    break;
                    case '2' :
                    return_book();
                    break;
                    case '3' :
                    print_borrow();
                    break;
                    default :
                    printf("\n\nGoing Back to main menu\n\n");
                    fflush(stdin);
                }
            }break;
            case '4' :          //Administrative Actions
            {
                system("cls");
                printf("\t\t\t >> Administrative Actions <<\n");
                printf("\t\t\t    **********************\n\n");
                printf("Overdue book(1)\n\n");
                printf("Show most popular books(2)\n\n");
                printf("Press any key to go back to main menu\n\n");
                printf("please enter your choice :");
                getchar(); scanf("%c",&choice);
                switch(choice)
                {
                    case '1' :
                    Overdue_books();
                    break;
                    case '2' :
                    show_popbooks();
                    break;
                    default  :
                    printf("\n\nGoing Back to main menu\n\n");
                    fflush(stdin);
                }
            }break;
            case '5' :          //saving process
            {
                write_fbook();
                write_fmember();
                write_fborrow();
                printf("\nData saved\n");
                printf("\nPress Enter to Continue\n");
                fflush(stdin); getchar();

            }break;
            case '6' :           //Exit process
            {
                printf("\nDo you want to save ?\npress (1) to save\npress (2) to exit\npress any other key to go back to the main menu\n");
                printf("Enter your choice : ");
                fflush(stdin); scanf("%c",&choice);
                if(choice=='1')
                {
                write_fbook();
                write_fmember();
                write_fborrow();
                printf("Data saved\nExiting . . .");
                exit(0);
                }
                else if(choice=='2') {printf("Exiting . . ."); exit(0); }
                else printf("\nGoing back to main menu\n");
                printf("\nPress Enter to Continue\n");
                fflush(stdin); getchar();
            }break;
            default  :
            {
                printf("\n\nInvalid Input! Please Enter a valid choice\n\n");
                fflush(stdin);
            }
        } //Exiting Switch
    }
    return 0;
}
//Primary Functions
                                /*Book Management*/
void insertnewbook()
{
    fflush(stdin);
    int n,i,z;
    char tn,temp[40];
    char dd[5],ml[5],yy[5];
    printf("Enter number of books you want to enter (Note you can't enter more than 9 books at on time) : ");
    fflush(stdin); scanf("%c",&tn);
    while(atoi(&tn)<0 || !isdigit(tn))
    {
        printf("\ninvalid input! Try again : ");
        fflush(stdin); scanf("%c",&tn);
    }
    n=atoi(&tn);
    for(i=c;i<(n+c);i++) //Scanning book info.
    {
            printf("Enter name of book %d : ",i+1);
            fflush(stdin); scanf("%[^\n]s",temp);
            for(z=0;z<strlen(temp);z++)
            {
            while(ispunct(temp[z]))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(book[i].title,temp);


            printf("Enter the author name of book %d : ",i+1);
            fflush(stdin); scanf("%[^\n]s",temp);
            for(z=0;z<strlen(temp);z++)
            {
            while(ispunct(temp[z]) || isdigit(temp[z]))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(book[i].author,temp);


            printf("Enter name of the publisher of book %d : ",i+1);
            fflush(stdin); scanf("%[^\n]s",temp);
            for(z=0;z<strlen(temp);z++)
            {
            while((ispunct(temp[z]) && temp[z]!='.') || isdigit(temp[z] ))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(book[i].publisher,temp);


            printf("Enter ISBN of book %d : ",i+1);
            fflush(stdin); scanf("%[^\n]s",temp);
            for(z=0;z<strlen(temp);z++)
            {
            while( temp[z]!='-' && !isdigit(temp[z]))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(book[i].isbn,temp);


            printf("Enter date of publication of book %d (DD/MM/YYYY): ",i+1);
            fflush(stdin); scanf("%[^/]/",dd); scanf("%[^/]/",ml); scanf("%[^\n]",yy);
            while(!check_date(dd,ml,yy))
            {
                printf("\nInvalid Date , Please make sure you enter the date in this format DD/MM/YY :");
                 fflush(stdin); scanf("%[^/]/",dd); scanf("%[^/]/",ml); scanf("%[^\n]",yy);
            }
            book[i].book_date_release.day=atoi(dd);
            book[i].book_date_release.month=atoi(ml);
            book[i].book_date_release.year=atoi(yy);


            printf("\nenter number of copies of book %d : ",i+1);
            fflush(stdin); scanf("%c",&tn);
            while(atoi(&tn)>-1 && !isdigit(tn))
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%c",&tn);
            }
            book[i].nofcopies=atoi(&tn);


            printf("enter available no of copies of book %d : ",i+1);
            fflush(stdin); scanf("%c",&tn);
            while(atoi(&tn)>-1 && !isdigit(tn))
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%c",&tn);
            }
            book[i].current_nofcopies=atoi(&tn);


            printf("enter the category of book %d : ",i+1);
            fflush(stdin); scanf("%[^\n]s",temp);
            for(z=0;z<strlen(temp);z++)
            {
            while(ispunct(temp[z]) || isdigit(temp[z]))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(book[i].cat,temp);
            book[i].nbor=0;
    }
    if(n!=0) c=i;
    printf("\nPress Enter to Continue\n");
    getchar(); getchar();
}
void addnewcopy()
{
fflush(stdin);
int flag=0,i,j;
char temp[50];
printf("\nenter the ISBN for the book you want to add a copy from : ");
scanf("%s",temp);
for(i=0;i<c;i++) //Searching for book
{
  if(strcmp(book[i].isbn,temp)==0) {flag=1; break;}
}
if(flag==1) //if book found
{
    printf("\nenter no. of copies to add : ");
    scanf("%d",&j);
    book[i].nofcopies=book[i].nofcopies+j;
    book[i].current_nofcopies=book[i].current_nofcopies+j;
    printf("\nBook Copied successfully\n");
}
else printf("Book Not found"); //if book not found
printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void deletebook()
{
fflush(stdin);
int flag=0,n,i;
char j;
char temp[50];
printf("Enter the ISBN of the book to delete : ");
scanf("%s",temp); //Scanning The ISBN of the book
for(i=0;i<c;i++)
{
    if(strcmp(temp,book[i].isbn)==0) {flag=1; break;} //Checking if the book is on the library
}
if(flag==1) //Book Found
{
    printf("Do you want to delete the entire data of the book and all it's copies(1) OR delete no. of copies(2) ? \n");
    fflush(stdin); scanf("%c",&j);
    if(j=='1') //Deleting all the data about the books from the file
    {
    book[i]=book[c-1];
    c--;
    printf("\nBook Deleted Successfully\n");
    }
    else if(j=='2') //Deleting number of copies but keeping the main data of the book
    {
    if(book[i].nofcopies==0)  printf("\nThere are no copies available\n");
    else if(book[i].current_nofcopies==0) printf("\nThere are no copies available at the moment\n");
    else
    {
        printf("\nThere are %d available right now\n",book[i].current_nofcopies);
        printf("\nEnter number of copies you like to delete : ");
        fflush(stdin); scanf("%d",&n);
        if(n>book[i].current_nofcopies || n<=0) //Checking number of copies the user want to delete
            printf("\nInvalid data,Terminating Process\n");
        else //Deleting number of copies
        {
            book[i].nofcopies=book[i].nofcopies-n;
            book[i].current_nofcopies=book[i].current_nofcopies-n;
        }
    }
    }else printf("\nInvalid Data,Terminating Process\n");
}else printf("\nISBN not found!\n"); //Book Not found
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void searchbooks()
{
    char ch,temp[100];
    char q[2]=" ";
    char name[5][10];
    char temp2[50];
    char *token;
    char temp3[40],temp4[40];
    int i,j,k,x,f=0,flag[20];
    for(i=0;i<20;i++) flag[i]=-1;
    printf("to search with the book name(1)\n");
    printf("to search with the author name(2)\n");
    printf("to search with the book ISBN(3)\n");
    printf("to search with the Category(4)\n");
    printf("write any key to go back to the main menu\n");
    printf("Enter your choice : "); fflush(stdin); scanf("%c",&ch);
    switch(ch)
    {
        case '1': //Searching by book name
        {
            printf("\nEnter Book name : ");
            fflush(stdin); scanf("%[^\n]s",temp);
            strlwr(temp);
            token=strtok(temp,q); /*Divides String into Tokens*/
            i=0;
            while(token!=NULL) /*Divides String into Tokens and putting it in an array of strings*/
            {
                    strcpy(name[i],token);
                    token=strtok(NULL,q);
                    i++;
            }
            x=0;
            for(j=0;j<i;j++)
            {
                for(k=0;k<c;k++)
                {
                if(k!=flag[0] || k!=flag[1] || k!=flag[2])
                {

                strcpy(temp2,book[k].title);
                strlwr(temp2);
                token=strtok(temp2,q);
                strcpy(temp4,name[j]);
                strcat(temp4,"  ");
                while(token!=NULL)
                {
                    strcpy(temp3,token);
                    strcat(temp3,"  ");
                    if(temp4[0]==temp3[0] && temp4[1]==temp3[1] && temp4[2]==temp3[2])
                    {
                        if(f==0){printf("\nResults :\n\n");}
                        f=1;
                        printf("%s\n",book[k].title);
                        flag[x]=k; x++;
                        break;
                    }
                    token=strtok(NULL,q);
                }
                }
                }
            }


            if(f==0) printf("\nThe name you entered didn't match any Book name\n");

        }break;
        case '2' : //Searching by author name
        {
            printf("\nEnter author name : ");
            fflush(stdin); scanf("%[^\n]s",temp);
            strlwr(temp);
            i=0;
            token=strtok(temp,q);
            while(token!=NULL)
            {
                strcpy(name[i],token);
                token=strtok(NULL,q);
                i++;
            }
            x=0;
            for(j=0;j<i;j++)
            {
                for(k=0;k<c;k++)
                {
                    if(k!=flag[0] && k!=flag[1] && k!=flag[2])
                    {
                        strcpy(temp2,book[k].author);
                        strlwr(temp2);
                        token=strtok(temp2,q);
                        strcpy(temp4,name[j]);
                        strcat(temp4,"  ");
                        while(token!=NULL)
                        {
                            strcpy(temp3,token);
                            strcat(temp3,"  ");
                            if(name[j][0]==temp3[0] && name[j][1]==temp3[1] && name[j][2]==temp3[2])
                            {
                                if(f==0){printf("\nResults :\n\n");}
                                f=1;
                                printf("%s and his book : %s \n",book[k].author,book[k].title);
                                flag[x]=k; x++;
                                break;
                            }
                            token=strtok(NULL,q);
                        }
                    }
                }
            }

            if(f==0) printf("\nThe name you entered didn't match any author name\n");

        }break;
        case '3' : //Searching by ISBN
        {
            printf("\nEnter ISBN : ");
            fflush(stdin); scanf("%[^\n]s",temp);
            for(i=0;i<c;i++)
            {
                 if(strcmp(book[i].isbn,temp)==0) {printf("\nBook found !\n"); f=1; break; }
            }
            if(f==1) printf("\nBook Name : %s\n",book[i].title);
            else printf("\nThere is no book with this ISBN\n");
        }break;
        case '4' : //Searching by Category
        {
            printf("\nEnter Category : ");
            fflush(stdin); scanf("%[^\n]s",temp);
            strlwr(temp);
            i=0;
            token=strtok(temp,q);
            while(token!=NULL)
            {
                strcpy(name[i],token);
                token=strtok(NULL,q);
                i++;
            }
            x=0;
            for(j=0;j<i;j++)
            {
                for(k=0;k<c;k++)
                {
                    if(k!=flag[0] && k!=flag[1] && k!=flag[2])
                    {
                        strcpy(temp2,book[k].cat);
                        strlwr(temp2);
                        token=strtok(temp2,q);
                        strcpy(temp4,name[j]);
                        strcat(temp4,"  ");
                        while(token!=NULL)
                        {
                            strcpy(temp3,token);
                            strcat(temp3,"  ");
                            if(name[j][0]==temp3[0] && name[j][1]==temp3[1] && name[j][2]==temp3[2])
                            {
                                if(f==0){printf("\nResults (Books from these category) :\n\n");}
                                f=1;
                                printf("%s : %s\n",book[k].cat,book[k].title);
                                flag[x]=k; x++;
                                break;
                            }
                            token=strtok(NULL,q);
                        }
                    }
                }
            }

            if(f==0) printf("\nThere are no books in this category\n");
        }break;
        default :
            printf("\nGoing Back to main menu\n");
    }
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void printbooks()
{
    int i;
    for(i=0;i<c;i++)
    {
        printf("%s,%s,%s,%s",book[i].title,book[i].author,book[i].publisher,book[i].isbn);
        printf(",%d/%d/%d,",book[i].book_date_release.day,book[i].book_date_release.month,book[i].book_date_release.year);
        printf("%d,%d,%s\n",book[i].nofcopies,book[i].current_nofcopies,book[i].cat);
    }
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
                                /*Member Transactions*/
void addnewmem()
{
int n,i,z,f,j;
char tn,temp[50],temp2[50];
printf("enter no of users you want to add :");
fflush(stdin); scanf("%c",&tn);
    while(atoi(&tn)<0 || !isdigit(tn))
    {
        printf("\ninvalid input! Try again : ");
        fflush(stdin); scanf("%c",&tn);
    }
n=atoi(&tn);
for(i=m;i<(n+m);i++) //Scanning Member Information
{
    printf("Information OF User %d\n\n",i+1);

    printf("Enter The name of user : ");
    fflush(stdin); scanf("%[^\n]s",temp);
    for(z=0;z<strlen(temp);z++)
            {
            while(ispunct(temp[z]) || isdigit(temp[z]))
            {
                printf("invalid input try again :");
                fflush(stdin); scanf("%s",temp); z=0;
            }
            }
            strcpy(member[i].name,temp);


    printf("\nEnter User phone no : ");
    fflush(stdin); gets(temp);
    for(z=0;z<strlen(temp);z++)
    {
            while(!isdigit(temp[z]) || strlen(temp)>14)
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); gets(temp); z=0;
            }

    }strcpy(member[i].tel,temp);
    printf("\n\nEnter User Address \n");
    printf("\n\nBuilding Number : ");
    fflush(stdin); scanf("%s",temp);
    for(z=0;z<strlen(temp);z++)
    {
            while(!isdigit(temp[z]))
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%s",temp); z=0;
            }
    }
            strcpy(member[i].m_address.build,temp);


    printf("\n\nstreet Name : ");
    fflush(stdin); scanf("%[^\n]s",temp);
        for(z=0;z<strlen(temp);z++)
            while(!isalpha(temp[z]) && temp[z]!=' ')
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%[^\n]s",temp); z=0;
            }
    strcpy(member[i].m_address.st,temp);


    printf("\n\nCity : ");
    fflush(stdin); gets(temp);
        for(z=0;z<strlen(temp);z++)
        {
            while(!isalpha(temp[z]) && temp[z]!=' ')
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%[^\n]s",temp); z=0;
            }
        }
    strcpy(member[i].m_address.city,temp);

    f=0;
    printf("\nEnter User ID : ");
    fflush(stdin); gets(temp2);
    for(z=0;z<strlen(temp2);z++)
    {

            for(j=0;j<m;j++) if(strcmp(member[j].ID,temp2)==0) f=1;
            while(!isdigit(temp2[z]) || f==1)
            {
            printf("\nInvalid input! Try again : ");
            fflush(stdin); gets(temp2); z=0; f=0;
            }
    }
    strcpy(member[i].ID,temp2);
    printf("\n\nenter your age : ");
    fflush(stdin); scanf("%s",temp);
    for(z=0;z<strlen(temp);z++)
    {
            while(!isdigit(temp[z]) || strlen(temp)>3)
            {
            printf("\ninvalid input! Try again : ");
            fflush(stdin); scanf("%s",temp); z=0;
            }

    }strcpy(member[i].age,temp);

    printf("\n\nenter a Valid email address : ");
    fflush(stdin); scanf("%s",temp);
    while(!Validate_mail(temp))
    {
        printf("\nInvalid E-mail Address , Pleas try again : ");
        fflush(stdin);gets(temp);
    }
    strcpy(member[i].mail,temp);
    member[i].nobor=0;
}
if(n!=0) m=i;

   printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void remove_member()
{
    int i,flag;
    char z,x[10];
    printf("enter the ID of the User to delete : ");
    scanf("%s",x);
    for(i=0;i<m;i++)
    {
        if(strcmp(member[i].ID,x)==0) {flag=1; break;}
    }
    if(flag==1)
    {
    if(member[i].nobor==0)
        {
        printf("press (1) to delete \n");
        printf("press any key to go back to menu\n");
        printf("enter your choice : ");
        getchar(); scanf("%c",&z);
        switch (z)
        {
            case '1':
            {
            member[i]=member[m-1];
            m--;
            printf("\nUser's Info was deleted Successfully\n");
            break;
            }
            default : printf("\nGoing Back to main menu\n"); break;
        }
        }else printf("\nyou can't remove this member he has unreturned books\n");
    }else printf("\nID wasn't found\n");
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void printmembers()
{
    int i;
    for(i=0;i<m;i++)
        {
            printf("%s,",member[i].name);
            printf("%s,",member[i].ID);
            printf("%s,%s,%s",member[i].m_address.build,member[i].m_address.st,member[i].m_address.city);
            printf(",%s,%s,%s\n",member[i].tel,member[i].age,member[i].mail);

        }
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}

                                /*Borrowing and Returning Books*/

void borrow_book()
{
time_t t = time(NULL);   //Some variables for time XD
struct tm tm = *localtime(&t);
int i,j,fb=0,fm=0;
char y,temp[100],temp2[50];
printf("Enter User ID and ISBN of book \n");
printf("Book ISBN : "); fflush(stdin); scanf("%[^\n]s",temp);    //Scanning Book ISBN
printf("User ID   : "); fflush(stdin); scanf("%[^\n]s",temp2);  //Scanning User id
for(i=0;i<c;i++) {if(strcmp(book[i].isbn,temp)==0) {fb=1; break;}}  //Searching book
for(j=0;j<m;j++) {if(strcmp(member[j].ID,temp2)==0) {fm=1; break;}}  //Searching user id
if(fb==1) //book found
{
if(fm==1) //id found
{
if(member[j].nobor<3) //if member borrowed more than 3 books
{
if(book[i].current_nofcopies>0)   // if there are no available copies
{
    printf("Date Borrowed : %d/%d/%d\n",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900); //Date right now
    printf("Write 1 to confirm : "); fflush(stdin); scanf("%c",&y);
    if(y=='1')
    {
    Borrowing[b].date_borrowed.day=tm.tm_mday;
    Borrowing[b].date_borrowed.month=tm.tm_mon+1;
    Borrowing[b].date_borrowed.year=tm.tm_year+1900;
    printf("Enter Date due to return (dd/mm/yyyy) : ");
    fflush(stdin); scanf("%d/%d/%d",&Borrowing[b].date_due_to_return.day,&Borrowing[b].date_due_to_return.month,&Borrowing[b].date_due_to_return.year);
    Borrowing[b].date_returened.day=0;
    Borrowing[b].date_returened.month=0;
    Borrowing[b].date_returened.year=0;
    strcpy(Borrowing[b].Isbn_bor,book[i].isbn);
    strcpy(Borrowing[b].ID_bor,member[j].ID);
    book[i].current_nofcopies--;
    book[i].nbor++;
    member[j].nobor++;
    b++;
    }else printf("\nReturning to main menu\n");
}else printf("\nThere are no available copies right now\n");
}else printf("\nUser has already the maximum Number of borrowings\n");
}else printf("\nUser ID was not found\n");
}else printf("\nBook ISBN was not found\n");
    printf("\nPress any key to Continue\n");
    fflush(stdin); getchar();
}
void return_book()
{
    time_t t = time(NULL);   //Some variables for time XD
    struct tm tm = *localtime(&t);
    int i,f=0;
    char temp[50],temp2[50];
    printf("Enter the ISBN of the book you want to return :");
    getchar(); scanf("%[^\n]",temp);
    printf("Enter member ID : ");
    getchar(); scanf("%[^\n]",temp2);
    for(i=0;i<b;i++)
        {
        if((strcmp(Borrowing[i].Isbn_bor,temp)==0) && (strcmp(Borrowing[i].ID_bor,temp2)==0)) {
                f=1;
        if(Borrowing[i].date_returened.day==0) break;} /**Edited**/
        }

    if(f==1)
    {
    if(Borrowing[i].date_returened.day==0)
    {
    Borrowing[i].date_returened.day=tm.tm_mday;
    Borrowing[i].date_returened.month=tm.tm_mon+1;
    Borrowing[i].date_returened.year=tm.tm_year+1900;
    for(i=0;i<c;i++) if(strcmp(book[i].isbn,temp)==0) break;
    book[i].current_nofcopies++;
    for(i=0;i<m;i++) if(strcmp(member[i].ID,temp2)==0) break;
    member[i].nobor--;
    printf("\nBook returned successfully\n");
    }
    else printf("\nThis Book has already been returned\n");
    }
    else printf("\nUser ID or Book ISBN wasn't found in the borrowing data\n");

    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void print_borrow()
{
    int i;
    for(i=0;i<b;i++)
        {
            printf("%s,",Borrowing[i].Isbn_bor);
            printf("%s,",Borrowing[i].ID_bor);
            printf("%d/%d/",Borrowing[i].date_borrowed.day,Borrowing[i].date_borrowed.month);
            printf("%d,",Borrowing[i].date_borrowed.year);
            printf("%d/%d/",Borrowing[i].date_due_to_return.day,Borrowing[i].date_due_to_return.month);
            printf("%d,",Borrowing[i].date_due_to_return.year);
            printf("%d/%d/",Borrowing[i].date_returened.day,Borrowing[i].date_returened.month);
            printf("%d\n",Borrowing[i].date_returened.year);
        }
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
                                /*administrative Actions */
void show_popbooks()
{
    int i,j;
    struct Books temp;
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
        {
            if(book[j].nbor<book[j+1].nbor)
            {
                temp=book[j];
                book[j]=book[j+1];
                book[j+1]=temp;
            }
        }
    }
    i=0;
    if(book[0].nbor!=0)
    {
        while(i<5 && i<c)
        {
            if(book[i].nbor==0) break;
            printf("%d - %s \n",(i+1),book[i].title);
            i++;
        }
    }
    else printf("\nThere are no borrowed books yet");
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();
}
void Overdue_books()
{
    time_t t = time(NULL);   //Some variables for time XD
    struct tm tm = *localtime(&t);
    int f=0,h=0,i,j;
    if(b!=0)
    {
        for(i=0;i<b;i++)
        {
            if(Borrowing[i].date_returened.day==0)
            {
            h=1;
             for(j=0;j<c;j++) {if(strcmp(book[j].isbn,Borrowing[i].Isbn_bor)==0) break;}
             if(Borrowing[i].date_due_to_return.year<tm.tm_year+1900)
             {
                 printf("Book : %s  ISBN : %s borrowed by user : %s Date Due to return : %d/%d/%d\n",book[j].title,Borrowing[i].Isbn_bor,Borrowing[i].ID_bor,Borrowing[i].date_due_to_return.day,Borrowing[i].date_due_to_return.month,Borrowing[i].date_due_to_return.year); f=1;
             }
             else if(Borrowing[i].date_due_to_return.year==tm.tm_year+1900)
             {
                 if(Borrowing[i].date_due_to_return.month<tm.tm_mon+1)
                 {
                 printf("Book : %s  ISBN : %s borrowed by user : %s Date Due to return : %d/%d/%d \n",book[j].title,Borrowing[i].Isbn_bor,Borrowing[i].ID_bor,Borrowing[i].date_due_to_return.day,Borrowing[i].date_due_to_return.month,Borrowing[i].date_due_to_return.year); f=1;
                 printf("Checked by month\n");
                 }
                 else if(Borrowing[i].date_due_to_return.month==tm.tm_mon+1)
                {
                    if(Borrowing[i].date_due_to_return.day<tm.tm_mday)
                    {
                    printf("Book : %s  ISBN : %s borrowed by user : %s Date Due to return : %d/%d/%d \n",book[j].title,Borrowing[i].Isbn_bor,Borrowing[i].ID_bor,Borrowing[i].date_due_to_return.day,Borrowing[i].date_due_to_return.month,Borrowing[i].date_due_to_return.year); f=1;
                    }
                }
             }
            }
        }
    if(h==0) printf("\nAll Books have been returned\n");
    else if(f==0) printf("\nNo Books Have crossed the due return date \n");
    }
    else printf("There are no borrowed books yet");
    printf("\nPress Enter to Continue\n");
    fflush(stdin); getchar();

}
                                /*Read and write functions*/


void read_fbook()
{
    FILE*fbooks;
    fbooks=fopen("Books.txt","r");
    if(fbooks!=NULL)
    {
        while(getc(fbooks)!=EOF)
        {
            long offset = ftell(fbooks)-sizeof(char);
            fseek(fbooks, offset, SEEK_SET);
            fscanf(fbooks,"%[^,],%[^,],%[^,],%[^,]",book[c].title,book[c].author,book[c].publisher,book[c].isbn);
            fscanf(fbooks,",%d/%d/%d,",&book[c].book_date_release.day,&book[c].book_date_release.month,&book[c].book_date_release.year);
            fscanf(fbooks,"%d,%d,%[^,],%d\n",&book[c].nofcopies,&book[c].current_nofcopies,book[c].cat,&book[c].nbor);

            c++;
        }
    }
    fclose(fbooks);

}

void read_fmember()
{
    FILE*fmember;
    fmember=fopen("Member.txt","r");
    if(fmember!=NULL)
    {
        while(getc(fmember)!=EOF)
        {
            long offset = ftell(fmember)-sizeof(char);
            fseek(fmember, offset, SEEK_SET);
            fscanf(fmember,"%[^,],",member[m].name);
            fscanf(fmember,"%[^,]",member[m].ID);
            fscanf(fmember,",%[^,],%[^,],%[^,],",member[m].m_address.build,member[m].m_address.st,member[m].m_address.city);
            fscanf(fmember,"%[^,],%[^,],%[^,],%d\n",member[m].tel,member[m].age,member[m].mail,&member[m].nobor);
            m++;
        }
    }
    fclose(fmember);
}

void read_fborrow()
{
    FILE*fborrow;
    fborrow=fopen("borrow.txt","r");
    if(fborrow!=NULL)
    {
        while(getc(fborrow)!=EOF)
        {
            long offset = ftell(fborrow)-sizeof(char);
            fseek(fborrow, offset, SEEK_SET);
            fscanf(fborrow,"%[^,],",Borrowing[b].Isbn_bor);
            fscanf(fborrow,"%[^,],",Borrowing[b].ID_bor);
            fscanf(fborrow,"%d/%d/",&Borrowing[b].date_borrowed.day,&Borrowing[b].date_borrowed.month);
            fscanf(fborrow,"%d,",&Borrowing[b].date_borrowed.year);
            fscanf(fborrow,"%d/%d/",&Borrowing[b].date_due_to_return.day,&Borrowing[b].date_due_to_return.month);
            fscanf(fborrow,"%d,",&Borrowing[b].date_due_to_return.year);
            fscanf(fborrow,"%d/%d/",&Borrowing[b].date_returened.day,&Borrowing[b].date_returened.month);
            fscanf(fborrow,"%d\n",&Borrowing[b].date_returened.year);
            b++;
        }
    }
    fclose(fborrow);

}

void write_fmember()
{
    int i;
    FILE*fmember;
    fmember=fopen("Member.txt","w");
        for(i=0;i<m;i++)
        {
            fprintf(fmember,"%s,",member[i].name);
            fprintf(fmember,"%s,",member[i].ID);
            fprintf(fmember,"%s,%s,%s,",member[i].m_address.build,member[i].m_address.st,member[i].m_address.city);
            fprintf(fmember,"%s,%s,%s,%d\n",member[i].tel,member[i].age,member[i].mail,member[i].nobor);
        }
    fclose(fmember);
}

void write_fbook()
{
    int i;
    FILE*fbooks;
    fbooks=fopen("Books.txt","w");
        for(i=0;i<c;i++)
        {
            fprintf(fbooks,"%s,%s,%s,%s",book[i].title,book[i].author,book[i].publisher,book[i].isbn);
            fprintf(fbooks,",%d/%d/%d,",book[i].book_date_release.day,book[i].book_date_release.month,book[i].book_date_release.year);
            fprintf(fbooks,"%d,%d,%s,%d\n",book[i].nofcopies,book[i].current_nofcopies,book[i].cat,book[i].nbor);
        }
    fclose(fbooks);
}

void write_fborrow()
{
    int i;
    FILE*fborrow;
    fborrow=fopen("borrow.txt","w");
        for(i=0;i<b;i++)
        {
            fprintf(fborrow,"%s,",Borrowing[i].Isbn_bor);
            fprintf(fborrow,"%s,",Borrowing[i].ID_bor);
            fprintf(fborrow,"%d/%d/",Borrowing[i].date_borrowed.day,Borrowing[i].date_borrowed.month);
            fprintf(fborrow,"%d,",Borrowing[i].date_borrowed.year);
            fprintf(fborrow,"%d/%d/",Borrowing[i].date_due_to_return.day,Borrowing[i].date_due_to_return.month);
            fprintf(fborrow,"%d,",Borrowing[i].date_due_to_return.year);
            fprintf(fborrow,"%d/%d/",Borrowing[i].date_returened.day,Borrowing[i].date_returened.month);
            fprintf(fborrow,"%d\n",Borrowing[i].date_returened.year);
        }
    fclose(fborrow);

}

    //Secondary functions
int check_date(char*dd,char*mm,char*yy)
{
    int f=1,i;
    if(strlen(dd)>2 || strlen(mm)>2 || strlen(yy)>4) {f=0;}
    else
    {
    f=1;
    for(i=0;i<strlen(dd);i++) if(isdigit(dd[i])==0) f=0;
    for(i=0;i<strlen(mm);i++)if(isdigit(mm[i])==0) f=0;
    for(i=0;i<strlen(yy);i++)if(isdigit(yy[i])==0) f=0;
    if(f==1)
    {
        if(atoi(dd)>31 || atoi(dd)<0 || atoi(mm)>12 || atoi(mm)<0 || atoi(yy)<0 ) f=0;
    }
    }
    return f;

}


int Validate_mail(char*email)
{
    int l,i,flag=0,count1=0,count2=0,dot,at;
    l=strlen(email);
    for(i=0;i<l;i++) if(email[i]==' ') flag=1;
    if(flag==0)
    {
        for(i=0;i<l;i++) if(email[i]=='@') {count1++; at=i;}
        if(count1==1)
        {
            for(i=at;i<l;i++) if(email[i]=='.') {count2++; dot=i;}
            if(email[at]==email[dot-1]) return 0;
            else if(count2==1)
            {
                if(email[l-1]=='m' && email[l-2]=='o' && email[l-3]=='c' && email[l-4]=='.') return 1;
                else return 0;
            }
            else return 0;
        }
        else return 0;

    }
    else return 0;
}
