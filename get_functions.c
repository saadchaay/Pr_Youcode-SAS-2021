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


                                /*   if exists an account function */

int if_exist_acc(bank_acc *acc, char cin[20], int c)
{
    int i,poss = -1;
    for(i=0; i<c; i++)
    {
        if(!strcmp(acc[i].CIN, cin))
            poss = i;
    }
    return (poss != -1)?1:0;
}
                            /*   get an account function   */

bank_acc get_account(bank_acc *acc, char cin[20], int c)
{
    int i,poss = -1;
    for(i=0; i<c; i++)
    {
        if(!strcmp(acc[i].CIN, cin))
            poss = i;
    }
    return acc[poss];
}
                              /*   tri accounts by ascending order    */

bank_acc * d_by_ascending(bank_acc *acc, int c)
{
    int i,j,pmin;
    bank_acc tmp_acc;
    for(i=0; i<c; i++)
    {
        pmin = i;
        for(j=i+1; j<c ; j++)
        {
            if(acc[j].amount < acc[pmin].amount)
                pmin=j;
        }
        tmp_acc = acc[i];
        acc[i] = acc[pmin];
        acc[pmin] = tmp_acc ;
    }
    return acc ;
}
                            /*    tri accounts By Descending Order     */

bank_acc * d_by_descending(bank_acc *acc, int c)
{
    int i,j,pmax;
    bank_acc tmp_acc;
    for(i=0; i<c; i++)
    {
        pmax = i;
        for(j=i+1; j<c ; j++)
        {
            if(acc[j].amount > acc[pmax].amount)
                pmax=j;
        }
        tmp_acc = acc[i];
        acc[i] = acc[pmax];
        acc[pmax] = tmp_acc ;
    }
    return acc ;
}
