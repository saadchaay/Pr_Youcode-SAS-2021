#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    int acc_number;
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float amount;
}bank_acc;

int c ;
int count = 0;

bank_acc insert_acc(bank_acc *accs,int size);
bank_acc * insert_accs(bank_acc *acc,int size);

void display_account_details(bank_acc * acc,int c);
void dis_one_account(bank_acc acc);

bank_acc * d_by_ascending(bank_acc *acc, int c);
bank_acc * d_by_descending(bank_acc *acc, int c);
void d_asce_gr(bank_acc *acc, int c, float amount_en);
void d_desce_gr(bank_acc *acc, int c, float amount_en);

bank_acc *operation_Withdrawal(bank_acc *acc, char cin[20], float val_to_wth, int c);
bank_acc *operation_deposit(bank_acc *acc, char cin[20], float val_to_dep, int c);
bank_acc *three_loyalty(bank_acc *acc,int c);

bank_acc get_account(bank_acc *acc, char cin[20], int c);
int if_exist_acc(bank_acc *acc, char cin[20], int c);
void app_gestion(bank_acc *acc, bank_acc *tmp_acc);
void display_accounts(bank_acc * acc);

int main()
{
    c = 30;
    bank_acc *accounts = (bank_acc*)malloc(c * sizeof(bank_acc));
    bank_acc *tmp_acc = (bank_acc*)malloc(c * sizeof(bank_acc));
    app_gestion(accounts,tmp_acc);
    free(accounts);
    free(tmp_acc);
    return 0;
}

void app_gestion(bank_acc *accounts, bank_acc *tmp_acc)
{
    int i, size, n, ope_n = 1, pos = 0;
    float amount;
    char cin[20];
    char menu[6][200] = { "Enter a bank account (CIN, First name and Last name, Amount).",
                    "Enter several bank accounts (CIN, First name and Last name, Amount).",
                    "Operations: Withdrawal and Deposit.",
                    "Display accounts.",
                    "Accounts loyalty.",
                    "exit the application." };
    system("cls");
    printf("\n\n\t\t################### App ' GESTION BANCAIRE ' welcome !! ###################");
    printf("\n\nThis is the menu of the App!\t\t\t\t\t\t\t\t\t\tAccounts: %d\n",count);
    for(i=0; i<6; i++)
        printf("\n\t%d: %s",i+1,menu[i]);
    printf("\n\n\t### Choose the operation to be performed! (number between 1 and 6) >>>>  ");
    do {
        scanf("%d",&n);
    }while(n < 1 || n > 6) ;

    switch(n)
    {
        case(1):
            system("cls");
            printf("\n\n 1:Please insert the data of a bank account.\n\n");
            accounts[count] = insert_acc(accounts,count);
            count++;
            printf("\n   INSERTION AN ACCOUNT SUCCESSFULLY... \n\n");
            system("pause");
            app_gestion(accounts,tmp_acc);
            break;
        case(2):
            system("cls");
            do {
                printf("\nHow many accounts you want to insert ? (max:20)  ");
                scanf("%d",&size);
                if(size <= 1 || size > 20)
                    printf("\n     ERROR, please choose number between 2 and 20\n");
            }while(size <= 1 || size > 20) ;
            tmp_acc = insert_accs(accounts,size);
            pos = count;
            for(i=count; i<size+count; i++)
            {
                accounts[i] = tmp_acc[i-pos];
            }
            count +=size;
            printf("\n    INSERTION SEVERAL ACCOUNTS SUCCESSFULLY... \n\n");
            system("pause");
            app_gestion(accounts,tmp_acc);
            break;
        case(3):
           system("cls");
           while(ope_n == 1 || ope_n == 2)
           {
               system("cls");
               printf("\nOperations:\n >> 1: Deposit.\n >> 2: Withdrawal.\n >> 3: Return the menu previous.");
               do {
                    printf("\n\n  Which operation: choose number 1 or 2 >> ");
                   scanf("%d",&ope_n);
               }while(ope_n < 0 || ope_n > 3);
               switch(ope_n)
               {
                    case(1):
                        printf("\n Deposit : \n---------- \n Enter the account's identity >> ");
                        scanf("%s",&cin);
                        if(!if_exist_acc(accounts,cin,count))
                        {
                            printf("\n\tOperation failed, the identity does't exist !!\n\n");
                        }
                        else{
                            printf("\nHow much ?  ");
                            scanf("%f",&amount);
                            accounts = operation_deposit(accounts,cin,amount,count);
                            printf("\nOPERATION HAS BEEN SUCCESSFULLY\n\n");
                        }
                        system("pause");
                        break;
                    case(2):
                        printf("\n Widthrawal : \n------------- \n Enter the account's identity >> ");
                        scanf("%s",&cin);
                        if(!if_exist_acc(accounts,cin,count))
                        {
                            printf("\n\tOperation failed, the identity does't exist !!\n\n");
                        }
                        else{
                            printf("\nHow much ?  ");
                            scanf("%f",&amount);
                            accounts = operation_Withdrawal(accounts,cin,amount,count);
                        }
                        system("pause");
                        break;
                    case(3):
                        break;
               }
           }
           app_gestion(accounts,tmp_acc);
           break;
        case(4):
           system("cls");
           display_accounts(accounts);
           printf("\n\n");
           app_gestion(accounts,tmp_acc);
           break;
        case(5):
            system("cls");
            if(strcmp(accounts[0].CIN,""))
            {
                printf("\n %s  \n\n We add 1.3 percentage in amount of the first three account. \n ",menu[4]);
                accounts = three_loyalty(accounts,count);
                printf("\n    ADDITION HAS BEEN SUCCESSFULLY   \n");
            }
            else
                 printf("\n  Addition failed, the bank accounts list is empty...\n");
            printf("\n");
            system("pause");
            app_gestion(accounts,tmp_acc);
            break;
        case(6):
               break;
    }
}

void display_accounts(bank_acc * acc)
{
    int i,n;
    float val;
    char cin[20];
    system("cls");
    bank_acc * tmp_ac = (bank_acc*)malloc(c * sizeof(bank_acc));
    printf("\n### WE HAVE SOME DISPLAY METHODS !!\n");
    char menu[6][200] = { "Display by Ascending Order.",
                    "Display by descending Order.",
                    "Display By Ascending Order (bank accounts with an amount greater than an entered number).",
                    "Display By descending Order (bank accounts with an amount greater than an entered number).",
                    "Search by CIN.",
                    "Return the menu previous." };

    for(i=0; i<6; i++)
        printf("\n\t%d: %s",i+1,menu[i]);

    printf("\n\n Choose the display method to be performed! (number between 1 and 5) >>>>  ");
    do {
        scanf("%d",&n);
    }while(n < 1 || n > 6) ;

    switch(n)
    {
        case(1):
            system("cls");
            display_account_details(d_by_ascending(acc,count),count);
            system("pause");
            display_accounts(acc);
            break;
        case(2):
            system("cls");
            display_account_details(d_by_descending(acc,count),count);
            system("pause");
            display_accounts(acc);
            break;
        case(3):
            system("cls");
            printf("\n%s",menu[2]);
            printf("\n\nEnter an amount >>  ");
            scanf("%f",&val);
            d_asce_gr(acc,count,val);
            system("pause");
            display_accounts(acc);
            break;
        case(4):
            system("cls");
            printf("\n%s",menu[3]);
            printf("\n\nEnter an amount >>  ");
            scanf("%f",&val);
            d_desce_gr(acc,count,val);
            system("pause");
            display_accounts(acc);
            break;
        case(5):
            system("cls");
            printf("\n\tGive the CIN that you're looking for  >>  ");
            scanf("%s",&cin);
            if(if_exist_acc(acc,cin,count))
            {
                dis_one_account(get_account(acc,cin,count));
                system("pause");
                display_accounts(acc);
            }
            else
            {
                printf("\n The identity is invalid: No account in the list ... \n\n");
                system("pause");
                display_accounts(acc);
            }
            break;
        case(6):
            break;
    }
}


