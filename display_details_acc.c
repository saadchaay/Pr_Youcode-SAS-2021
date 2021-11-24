#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    int acc_number;
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float amount;
}bank_acc;

                                  /*   display all accounts details    */

void display_account_details(bank_acc * acc, int c)
{
    int i;
    if(!strcmp(acc[0].CIN,""))
        printf("\n\n\t List of the bank accounts is empty !! \n\n\n");
    else
    {
        printf("\n\n\t\t\t List of the bank accounts:\n");
        for(i=0; i<c; i++)
        {
            printf("\n\t>>> Account number: ' %d '\n\n",acc[i].acc_number);
            printf("\t\t The identity: %s\n",acc[i].CIN);
            printf("\t\t First name: %s\n",acc[i].first_name);
            printf("\t\t Last name: %s\n",acc[i].last_name);
            printf("\t\t Amount: %.2f\n",acc[i].amount);
        }
        printf("\n\n");
    }
}
                                       /*   display one account    */

void dis_one_account(bank_acc acc)
{
        printf("\n>>> Data of this account: ' %d '\n\n",acc.acc_number);
        printf("\t The identity: %s\n",acc.CIN);
        printf("\t First name: %s\n",acc.first_name);
        printf("\t Last name: %s\n",acc.last_name);
        printf("\t Amount: %.2f\n\n",acc.amount);
}
              /* display By Ascending Order (bank accounts with an amount greater than an entered number)   */

void d_asce_gr(bank_acc *acc, int c, float amount_en)
{
    int i,j,pos;
    bank_acc * tmp_acc = d_by_descending(acc,c);
    if(amount_en > tmp_acc[0].amount)
        printf("\n     The amount you entered is greater than all amounts....\n\n");
    else
    {
        for(i=0; i<c; i++)
        {
            if(tmp_acc[i].amount > amount_en)
            {
                pos = i;
            }
        }
        display_account_details(d_by_ascending(tmp_acc,pos+1),pos+1);
    }
}
        /*   display By descending Order (bank accounts with an amount greater than an entered number)    */

void d_desce_gr(bank_acc *acc, int c, float amount_en)
{
    int i,j,pos;
    bank_acc * tmp_acc = d_by_descending(acc,c);
    if(amount_en > tmp_acc[0].amount)
        printf("\n     The amount you entered is greater than all amounts....\n\n");
    else
    {
        for(i=0; i<c; i++)
    {
        if(tmp_acc[i].amount > amount_en)
        {
            pos = i;
        }
    }
    display_account_details(d_by_descending(tmp_acc,pos+1),pos+1);
    }
}
