#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){

    string gunner_1;
    string gunner_2;

    do {
        gunner_1 = get_string("Are you ready? (respond with aye or nay) ");
        gunner_2 = get_string("Are you ready? (respond with aye or nay) ");
    }
    while ((strcmp(gunner_1, "aye") != 0 && strcmp(gunner_1, "nay") != 0) || (strcmp(gunner_2, "aye") != 0 && strcmp(gunner_2, "nay") != 0));

    if (strcmp(gunner_1, "aye") == 0){
        if (strcmp(gunner_2, "aye") != 0){
            printf("Shiver me timbers!\n");
        }
        else {
            printf("Fire!\n");
        }
    }
    else {
        printf("Shiver me timbers!\n");
    }
}
