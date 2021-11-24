#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    int acc_number;
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float amount;
}bank_acc;

                             /*     Withdrawal function      */

bank_acc * operation_Withdrawal(bank_acc *acc, char cin[20], float val_to_wth, int c)
{
    int i,pos;
    bank_acc *accou = (bank_acc*)malloc(30 * sizeof(bank_acc));;
    for(i=0; i<c; i++)
    {
        if(!strcmp(acc[i].CIN, cin))
        {
            if(acc[i].amount < val_to_wth)
            {
                printf("\nInsufficient balance !!\n\n");
                accou[i].acc_number = acc[i].acc_number;
                strcpy(accou[i].first_name, acc[i].first_name);
                strcpy(accou[i].last_name, acc[i].last_name);
                strcpy(accou[i].CIN, acc[i].CIN);
                accou[i].amount = acc[i].amount;
            }
             else
            {
                accou[i].acc_number = acc[i].acc_number;
                strcpy(accou[i].first_name, acc[i].first_name);
                strcpy(accou[i].last_name, acc[i].last_name);
                strcpy(accou[i].CIN, acc[i].CIN);
                accou[i].amount = acc[i].amount-val_to_wth;
                printf("\n\nOPERATION HAS BEEN SUCCESSFULLY\n\n");
             }
        }
        else
        {
            accou[i].acc_number = acc[i].acc_number;
            strcpy(accou[i].first_name, acc[i].first_name);
            strcpy(accou[i].last_name, acc[i].last_name);
            strcpy(accou[i].CIN, acc[i].CIN);
            accou[i].amount = acc[i].amount;
        }
    }
    return accou;
}
                               /*     Deposit function      */

bank_acc * operation_deposit(bank_acc *acc, char cin[20], float val_to_dep, int c)
{
    int i,pos;
    bank_acc *accou = (bank_acc*)malloc(30 * sizeof(bank_acc));
    for(i=0; i<c; i++)
    {
        if(!strcmp(acc[i].CIN, cin))
        {
            accou[i].acc_number = acc[i].acc_number;
            strcpy(accou[i].first_name, acc[i].first_name);
            strcpy(accou[i].last_name, acc[i].last_name);
            strcpy(accou[i].CIN, acc[i].CIN);
            accou[i].amount = acc[i].amount+val_to_dep;
        }
        else
        {
            accou[i].acc_number = acc[i].acc_number;
            strcpy(accou[i].first_name, acc[i].first_name);
            strcpy(accou[i].last_name, acc[i].last_name);
            strcpy(accou[i].CIN, acc[i].CIN);
            accou[i].amount = acc[i].amount;
        }
    }
    return accou;
}
// remarque, the user entered number and does not exist amounts great than that number(to fix)

