#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void menu();
struct date
{
    int day,month,year;
};

struct bank
{
    char name[30];
    int accno,age;
    char address[50];
    double phone;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    float amount;

}add,remove1,update,see1,tran,check;


void newacc()
{
    int n;
    FILE *acc;
    acc=fopen("record.dat","a+");
    number:
        system("cls");
    printf("Add a Record");
    printf("Enter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.accno);
    while(fscanf(acc,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    if (check.accno==add.accno)
            {
                printf("The Account no.is already in use!");
                goto number;
                system("cls");
            }

    add.accno=check.accno;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:");
    scanf("%f",&add.amount);
    fprintf(acc,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    system("cls");
     fclose(acc);
     printf("\nAccount created successfully!");
    invalid:
    printf("1)menu \n2)exit");
    scanf("%d",&n);
    system("cls");
    if (n==1)
        menu();
    else if(n==2)
            printf("Goodbye!");
    else
        {
            printf("\nInvalid!");
            goto invalid;
        }

}
void editacc()
{
    int choice,n=0,m;
    FILE *oldf,*newf;
    oldf=fopen("record.dat","r");
    newf=fopen("new.dat","w");

    printf("\nEnter the account no. which is to be edited:");
    scanf("%d",&update.accno);
    while(fscanf(oldf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
       {if (add.accno==update.accno)
        {   n=1;
            printf("\nWhat do you want to change?\n1.Address\n2.Phone\n\nEnter your choice:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",update.address);
                fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,update.address,add.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Done!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&update.phone);
                 fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,update.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Done!");
                }

        }
        else
           fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(oldf);
    fclose(newf);
    remove("record.dat");
    rename("new.dat","record.dat");

if(n!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            einvalid:
              printf("\n0)Try again \n1) Main meny \n2)Exit:");
              scanf("%d",&m);
              system("cls");
                 if (m==1)
                 {
                   system("cls");
                    menu();
                 }
                else if (m==2)
                     printf("Goodbye!");
                else if(m==0)
                    editacc();
                else
                    {printf("\nInvalid!\a");
                    goto einvalid;}
        }
    else
        {printf("\n1)main menu \n2)exit:");
        scanf("%d",&m);
        system("cls");
        if (m==1)
            menu();
        else
            printf("Goodbye!");
        }


}
void transact()
{
    int choice,n=0,m;
    FILE *oldf,*newf;
    oldf=fopen("record.dat","r");
    newf=fopen("new.dat","w");
     printf("\nEnter the account no. :");
    scanf("%d",&tran.accno);
    while(fscanf(oldf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
      if(add.accno==tran.accno)
            {   n=1;
            printf("\n\nDo you want to\n1)Deposit\n2)Withdraw?\n:");
                scanf("%d",&choice);
                if(choice==1)
                {
                    printf("Enter the amount you want to deposit: ");
                    scanf("%f",&tran.amount);
                    add.amount+=tran.amount;
                    fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nDone!");
                }
                else if (choice==2)
                {
                    printf("Enter the amount you want to withdraw: ");
                    scanf("%f",&tran.amount);
                    add.amount-=tran.amount;
                    fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nDone!");
                }
            }
                else
                {
                    fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.day,add.deposit.month,add.deposit.year);

                }
                system("cls");

     }
    fclose(oldf);
    fclose(newf);
    remove("record.dat");
    rename("new.dat","record.dat");

if(n!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            einvalid:
              printf("\nEnter 0)try again,1)main menu \n2)exit:");
              scanf("%d",&m);
              system("cls");
                 if (m==1)

                    menu();
                else if (m==2)
                     printf("Goodbye!");
                else if(m==0)
                    editacc();
                else
                    {printf("\nInvalid!");
                    goto einvalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&m);
        system("cls");
        if (m==1)
            menu();
        else
            printf("Goodbye!");
        }


}
void see()
{
    int n=0,choice,m;
    FILE *acc;
    acc=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&see1.accno);

    while(fscanf(acc,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(add.accno==see1.accno)
            {   system("cls");
                n=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%.0lf  \nAmount deposited: %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,
                add.amount,add.deposit.day,add.deposit.month,add.deposit.year);


            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",see1.name);
          while(fscanf(acc,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,see1.name)==0)
            {   system("cls");
                n=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s  \nPhone number:%.0lf \nAmount deposited:%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accno,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.phone,
                add.amount,add.deposit.day,add.deposit.month,add.deposit.year);

            }
        }
    }


    fclose(acc);
    if(n!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            einvalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&m);
              system("cls");
                 if (m==1)

                    menu();
                else if (m==2)
                     printf("Goodbye!");
                else if(m==0)
                    editacc();
                else
                    {printf("\nInvalid!\a");
                    goto einvalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&m);
        system("cls");
        if (m==1)
            menu();
        else
            printf("Goodbye!");
        }




}

void removeacc()
{
    int n,m,o;
    FILE *oldf,*newf;
    oldf=fopen("record.dat","r");
    newf=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&remove1.accno);
        while(fscanf(oldf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
           {
               if(add.accno!=remove1.accno)
               {
                 fprintf(newf,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);

               }
               else
            {
                  n++;
                  printf("\nRecord deleted successfully!\n");
            }
           }
            fclose(oldf);
            fclose(newf);
            remove("record.dat");
            rename("new.dat","record.dat");
            if(n==0)
        {
            printf("\nRecord not found!!\a\a\a");
            rinvalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&m);

                 if (m==1)
                    menu();
                else if (m==2)
                    printf("Goodbye!");
                else if(m==0)
                    removeacc();
                else
                    {printf("\nInvalid!\a");
                    goto rinvalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&o);

        if (o==1)
            menu();
        else
            printf("Goodbye!");
        }

}
void viewlist()
{
   FILE *abc;
   abc=fopen("record.dat","r");
   int n=0,m;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
            while(fscanf(abc,"%d %s %d/%d/%d %d %s %lf %f %d/%d/%d\n",&add.accno,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
          {
           printf("\n%d\t %s\t\t\t%s\t\t%.0lf",add.accno,add.name,add.address,add.phone);
           n++;
          }
          fclose(abc);
           if (n==0)
        {   system("cls");
            printf("\nNO RECORDS!\n");}

    vinvalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&m);
        system("cls");
        if (m==1)
            menu();
        else if(m==0)
            printf("Goodbye!");
        else
        {
            printf("\nInvalid!\a");
            goto vinvalid;
        }
}

void menu()
{
    int choice;
    printf("Bank Management System");
    printf("\n1.Create new account\n2.Updatean account\n3.For transactions\n4.View existing account\n5.Remove existing account\n6.View list\n7.Exit\n :");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1:newacc();
        break;
        case 2:editacc();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:removeacc();
        break;
        case 6:viewlist();
        break;
        case 7:printf("Goodbye!");
        break;

    }
    system("cls");
}




int main()
{
    int m;
    char pass[30],password[30]="banksystem";
    printf("\nEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {
            printf("\n\nPassword Match!\n");
            Sleep(300);
            system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!");
            login:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&m);
            if (m==1)
                    {

                        system("cls");
                        main();
                    }

            else if (m==0)
                    {
                    system("cls");
                    printf("Goodbye!");
                    }
            else
                    {printf("\nInvalid!");
                    system("cls");
                    goto login;}

        }
    return 0;
}
