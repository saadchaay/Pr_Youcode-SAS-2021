#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    int acc_number;
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float amount;
}bank_acc;

int if_exist_acc(bank_acc *acc, char cin[20], int c);

                           /*     insert one account      */

bank_acc insert_acc(bank_acc *accs,int size)
{
    bank_acc acc ;

        acc.acc_number = rand() % 9999999 +100000 ;
        do {
            printf("\t>>Give the identity (CIN): ");
            scanf("%s",&acc.CIN);
                if(if_exist_acc(accs,acc.CIN,size) == 1)
                    printf("\n This identity is ready exists...\n\n");
        }while(if_exist_acc(accs,acc.CIN,size) == 1);


        printf("\t>>Give the first name: ");
        scanf("%s",&acc.first_name);

        printf("\t>>Give the last name: ");
        scanf("%s",&acc.last_name);

        printf("\t>>Give the amount : ");
        scanf("%f",&acc.amount);

    return acc;
}
                           /*    insert many accounts     */

bank_acc * insert_accs(bank_acc *accs,int size)
{
    int i,j;
    bank_acc *acc = (bank_acc*)malloc(size * sizeof(bank_acc));

    for(i=0; i<size; i++)
    {
        if(i == 0)
            printf("\n%d er account: \n",i+1);
        else printf("%d eme account: \n",i+1);

        acc[i].acc_number = rand() % 9999999 +100000 ;
        do {
            printf("\t>>>Give the identity (CIN): ");
            scanf("%s",&acc[i].CIN);
                if(if_exist_acc(accs,acc[i].CIN,size) == 1 || if_exist_acc(acc,acc[i].CIN,i) == 1)
                    printf("\n This identity is ready exists...\n\n");
        }while(if_exist_acc(accs,acc[i].CIN,size) == 1 || if_exist_acc(acc,acc[i].CIN,i) == 1);

        printf("\t>>>Give the first name: ");
        scanf("%s",&acc[i].first_name);

        printf("\t>>>Give the last name: ");
        scanf("%s",&acc[i].last_name);

        printf("\t>>>Give the amount : ");
        scanf("%f",&acc[i].amount);

    }

    return acc;
}
