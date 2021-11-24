#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    int acc_number;
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float amount;
}bank_acc;

bank_acc * d_by_descending(bank_acc *acc, int c);
void display_account_details(bank_acc * acc, int c);
int if_exist_acc(bank_acc *acc, char cin[20], int c);

bank_acc *three_loyalty(bank_acc *acc,int c)
{
    int i;
    acc = d_by_descending(acc,c);
    bank_acc *th_loyalty = (bank_acc*)malloc(30 * sizeof(bank_acc));

    for(i=0; i<3; i++)
    {
        if(if_exist_acc(acc,acc[i].CIN,c))
        {
            th_loyalty[i].acc_number = acc[i].acc_number;
            th_loyalty[i].amount = acc[i].amount + (1.3 * acc[i].amount / 100);
            strcpy(th_loyalty[i].first_name, acc[i].first_name);
            strcpy(th_loyalty[i].last_name, acc[i].last_name);
            strcpy(th_loyalty[i].CIN, acc[i].CIN);
        }
        else break;
    }
    for(i=3; i<c; i++)
    {
        if(if_exist_acc(acc,acc[i].CIN,c))
        {
            th_loyalty[i].acc_number = acc[i].acc_number;
            th_loyalty[i].amount = acc[i].amount;
            strcpy(th_loyalty[i].first_name, acc[i].first_name);
            strcpy(th_loyalty[i].last_name, acc[i].last_name);
            strcpy(th_loyalty[i].CIN, acc[i].CIN);
        }
        else break;
    }
    return th_loyalty;
    /*for(i=0; i<c; i++)
    {
        if(if_exist_acc(acc,acc[i].CIN,c) == 1)
        {
            if(i < 3)
            {
                th_loyalty[i].acc_number = acc[i].acc_number;
                th_loyalty[i].amount = acc[i].amount + (1.3 * acc[i].amount / 100);
                strcpy(th_loyalty[i].first_name, acc[i].first_name);
                strcpy(th_loyalty[i].last_name, acc[i].last_name);
                strcpy(th_loyalty[i].CIN, acc[i].CIN);
                if(i=2)
                    printf("\n\t'  ADDITION HAS BEEN SUCCESSFULLY  ' \n");
            }
            else
            {
                th_loyalty[i].acc_number = acc[i].acc_number;
                th_loyalty[i].amount = acc[i].amount;
                strcpy(th_loyalty[i].first_name, acc[i].first_name);
                strcpy(th_loyalty[i].last_name, acc[i].last_name);
                strcpy(th_loyalty[i].CIN, acc[i].CIN);
            }
        }
        else break;

    }*/

}

