#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct add_book
{
    int id;
    char name [20];
    char author [20];
    int quantity;
};
FILE *file;
FILE *file2;

void cover_page()
{
    system("color f0");
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              LIBRARY MANAGEMENT                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n");
    printf("\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");
    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$               Welcome to Library                  $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------\n\n");
    printf("\n\n");
}

void admin_mode()
{
    system("cls");
    printf("\n\t\t1) Add Book\n");
    printf("\n\t\t2) View Book\n");
    printf("\n\t\t3) Search Book By ID\n");
    printf("\n\t\t4) Exit\n");
    printf("\t\t\t\n\n\t\t**********************************************\n");
    printf("\t\tEnter your choice :");
    int n;
    scanf("%d",&n);
        if(n==1)
        {
        add_books();
        }
        else if(n==2)
        {
        view_books();
        }
        else if(n==3)
        {
        search_books();
        }
        else if(n==4)
        {
        exit(0);
    }
        else
        {
        printf("\n\t\tWrong choice");
        printf("\n\t\tTry again :");
    }
}
void add_books()
{
    printf("\n\n \t\t****************** Add Book ******************\n\n");
    int d,count=0;
    printf("\n\t\tBook ID:");
    scanf("%d",&d);
    struct add_book a;
    file = fopen("book.txt","ab+");
    rewind(file);
    while(fread(&a, sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            count=1;
        }
    }
    if(count==1)
    {
        printf("\n\t\tThe book id is already exist");
    }
    else
    {
        printf("\n\t\tYou can add this book");
        printf("\n\t\tBook ID:");
        scanf("%d",&a.id);
        printf("\t\tBook Name : ");
        fflush(stdin);
        scanf("%s",a.name);
        printf("\t\tAuthor : ");
        fflush(stdin);
        scanf("%s",a.author);
        printf("\t\tQuantity : ");
        fflush(stdin);
        scanf("%d",&a.quantity);
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        printf("\n\t\tBooks is added successfully...");
    }

}

void password_admin()
{
    char pass1[20] = "1234";
    char pass2[20];
    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0)
    {
        admin_mode();
    }
    else
    {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_admin();
    }

}
void password_user()
{
    char pass1[20] = "123";
    char pass2[20];

    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0)
    {
        user_mode();
    }
    else
    {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_user();
    }

}

void view_books()
{
    struct add_book a;
    int count=0;
    printf("\n\n\t\t********* View Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQunt\n\n");

    file = fopen("book.txt","rb");
    while( fread(&a,sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t%d\n",a.quantity);

        count=count + a.quantity;

    }
    printf("\n\n\n\t\t Total Book: %d",count);

}
void search_books()
{
    struct add_book a;
    int d,count=0;

    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t searching.....\n\n");
    file = fopen("book.txt","rb");

    printf("\n\t\t Enter ID: ");
    scanf("%d",&d);

    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {

            printf("\n\n\t\t Book is Found\n");
            printf("\t\t ID: %d",a.id);
            printf("\n\t\t Name: %s",a.name);
            printf("\n\t\t Author: %s",a.author);
            printf("\n\t\t Quantity: %d",a.quantity);
                count=1;
        }
    }
    if(count==0)
    {
        printf("\n\n\t\t Book is Not Found");
    }

}

void user_mode()
{
    system("cls");
    printf("\n\t\t1) Search Book by ID");
    printf("\n\t\t2) Book list");
    printf("\n\t\t3) Borrow Book");
    printf("\n\t\t4) Deposit Book");
    printf("\n\t\t5) Exit\n");
    printf("\t\t\t\n\n\t\t**********************************************\n");

    printf("\n\t\tEnter your choice : ");
    int t;
    scanf("%d",&t);

    if(t==1)
    {
        search_book();
    }
    else if(t==2)
    {
        book_list();
    }
    else if(t==3)
    {
        borrow_book();
    }
    else if(t==4)
    {
        deposite_books();
    }
    else if(t==5)
    {
        search_books();
    }
    else if(t==6)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\tWrong choice");
        printf("\n\t\tTry again");
    }

}
void borrow_time()
{

    int D,h1,M,h2,Y;
    printf("\t\tEnter The Date of Borrowing Books(DD-MM-YYYY): ");
    scanf("%d %c %d %c %d",&D,&h1,&M,&h2,&Y);
    if(M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12)
    {
        if(D>24)
        {
            if(M==12)
            {
                printf("\t\tThe Deposit Date: %02d-01-%d \n",(D+7)-31,Y+1);
            }
            else
            {
                printf("\t\tThe Deposit Date: %02d-%02d-%d\n",(D+7)-31,M+1,Y);
            }
        }
        else
        {
            printf("\t\tThe Deposit date: %02d-%02d-%d\n",D+7,M,Y);
        }
    }
    else if(M==4 || M==6 || M==9 || M==11)
    {
        if(D>23)
        {
            printf("\t\tThe Deposit Date: %02d-%02d-%d\n",(D+7)-30,M+1,Y);
        }
        else
        {
            printf("\t\tThe Deposit Date: %02d-%02d-%d\n",D+7,M,Y);
        }
    }

    else if(M==2)
    {
        if(Y%4==0)
        {
            if(D>22)
            {
                printf("\t\tThe Deposit Date: %02d-%02d-%d\n",(D+7)-29,M+1,Y);
            }
            else
            {
                printf("\t\tThe Deposit Date: %02d-%02d-%d\n",D+7,M,Y);
            }
        }
        else
        {
            if(D>21)
            {
                printf("\t\tThe Deposit Date: %02d-%02d-%d\n",(D+7)-28,M+1,Y);
            }
            else
            {
                printf("\t\tThe Deposit Date: %02d-%02d-%d\n",D+7,M,Y);
            }

        }

    }
}
void borrow_book()
{
    struct add_book a;
    int d, count = 0 ;
    printf("\n\n\t\t ************* Borrow book *************\n\n");
    printf("\n\n\t\t Enter ID for Borrow Book : ");
    scanf("%d", &d);
    file = fopen("book.txt", "rb+");
    rewind (file);
    while(fread(&a, sizeof(a), 1, file) == 1)
    {
        if(d == a.id)
        {
            count = 1;
        }
    }

    if(count == 0)
    {
        printf("\n\t\t-Book is not Available\n");
    }
    else
    {
        printf("\n\t\t Book is Available!\n");
        file2 = fopen("text.txt", "wb");
        rewind(file);
        while(fread(&a, sizeof(a), 1, file) ==1)
        {
            if(d != a.id)
            {
                fseek(file2, ftell(file2)-sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, file2);

            }
        }
        fclose(file);
        fclose(file2);
        remove("book.txt");
        rename("text.txt", "book.txt");;
        file = fopen("book.txt", "rb");
        fclose(file);
        borrow_time();
        printf("\n");
        printf("\t\tThe book is Borrowed successfully\n");
    }


}
void deposite_books()
{

    printf("\n\n\t\t****************** Deposit Book ******************\n\n");
    int d,count=0;
    printf("\n\t\tBook ID:");
    scanf("%d",&d);
    struct add_book a;
    file = fopen("book.txt","ab+");
    rewind(file);

    while(fread(&a, sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            count=1;
        }
    }

    if(count==1)
    {
        printf("\n\t\tWrong Book ID");
    }
    else
    {

        printf("\n\t\tYou can add this book");
        printf("\n\t\tBook ID:");
        scanf("%d",&a.id);
        printf("\t\tBook Name : ");
        fflush(stdin);
        scanf("%s",a.name);
        printf("\t\tAuthor : ");
        fflush(stdin);
        scanf("%s",a.author);
        printf("\t\tQuantity : ");
        fflush(stdin);
        scanf("%d",&a.quantity);
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        printf("\n\t\tBooks is added successfully...");
    }

}
void select_mode()
{
    int a;
    printf("\n\t\t->> Press 1 : Admin Mode");
    printf("\n\t\t->> Press 2 : User Mode");
    printf("\n\t\t->> Press 3 : Team ");
    printf("\n\t\t->> Press 4 : About us\n");
    scanf("%d",&a);
    if(a==1)
    {

        password_admin();
        back();
    }
    else if (a==2)
    {

        password_user();
        back();
    }
    else if(a==3)
    {
        info();
        back();
    }
    else if(a==4)
    {

        about();
        back();
    }
    else
    {
        printf("\n\t\tINVAILD INPUT");
        printf("\n\t\tTry Again\n");
        select_mode();
    }



}
void back()
{

    char b;
    printf("\n\t\t PRESS y to Return MENU\n\n");
    getchar();
    printf("\t\t\t\t\t PRESS : ");
    scanf("%c",&b);
    if(b=='y')
    {
        select_mode();
    }
    else
    {
        exit(0);
    }


}
void book_list()
{

    struct add_book a;
    int count=0;

    printf("\n\n\t\t********* Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQunt\n\n");

    file = fopen("book.txt","rb");

    while( fread(&a,sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t%d\n",a.quantity);

        count=count + a.quantity;

    }
    printf("\n\n\n\t\t Total Book: %d",count);

}
void search_book()
{
    struct add_book a;
    int d,count=0;


    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t searching.....\n\n");

    file = fopen("book.txt","rb");

    printf("\n\t\t Enter Book ID: ");
    scanf("%d",&d);

    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {

            printf("\n\n\t\t Book is Found\n");
            printf("\t\t ID: %d",a.id);
            printf("\n\t\t Name: %s",a.name);
            printf("\n\t\t Author: %s",a.author);
            printf("\n\t\t Quantity: %d",a.quantity);


            count=1;
        }
    }
    if(count==0)
    {
        printf("\n\n\t\t Book is Not Found");
    }
    printf("\n\n\t\t press any key....");
    fflush(stdin);

    int select;
    printf("\n\t\t1)User mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {

        user_mode();
    }
    else
    {
        exit(0);
    }
}
void info()
{
    system("cls");
    printf("\n\n\t\t****************** REturn 0 ******************\n\n");
    printf("\t\tANUPAM PAL\n\t\tSec: 64_B\n\t\tID: 0242310005101525\n\t\tMobile no: 01706410165\n\t\tMail: pal23105101525diu.edu.bd\n");
    printf("\n");
    printf("\t\tMD. GOLAM RABBANI\n\t\tSec: 64_B\n\t\tID: 02423100005101119\n\t\tMobile no: 01768804069\n\t\tMail: rabbani23105101119diu.edu.bd\n");
    printf("\n");
    printf("\t\tMD AHOSUN HABIB\n\t\tSec: 64_B\n\t\tID: 0242310005101343\n\t\tMobile no: 01300961269\n\t\tMail: nibir23105101343diu.edu.bd\n");
    printf("\n");
    printf("\t\tFAHAD HOSSEN TONMOY\n\t\tSec: 64_B\n\t\tID: 02423100051041037\n\t\tMobile no: 01947867353\n\t\tMail: tonmoy23105101037diu.edu.bd\n");
}
void about()
{
    system("cls");
    printf("\n\n\t\t*****************About Project*****************\n\n");
    printf("\t\tThe Name of Project is \"LIBRARY MANAGEMENT SYSTEM\"\n");
    printf("\t\tCOURSE TITLE:Programming and Problem Solving Lab\n");
    printf("\t\tCOURSE CODE:CSE114\n");
    printf("\t\tCourse  Teacher:Dr. Sheak Rashed Haider Noori\n");
    printf("\t\tFile: we use file to store books data permanently.\n");
    printf("\t\tStructure: we use structure to made data type of book information with varios types of data type.\n");
    printf("\t\tFunction: we use function to divide work,to make it easy,to make it undestandable to others.\n");
    printf("\t\tLoop: we use loop to do same work again.\n");
    printf("\t\tCondional Statement: we use conditional statement for password,to retun menu.\n");
}
int main()
{
    cover_page();
    select_mode();
}
