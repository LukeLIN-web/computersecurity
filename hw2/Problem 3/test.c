#include <string.h>
#include <stdio.h>
#include "aes.h"

#define AES_ENC_MAX_LEN 512

int check_password(char* input, char* password) {
    if (strlen(input) != strlen(password)) {
        return 0;
    } else {
        if (strcmp(input, password) != 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

int main(void)
{

    char* password1 = "******************"; // The password1 has been masked
    char input1[AES_ENC_MAX_LEN] = {0};
    printf("input password 1->");
    scanf("%s", input1);

    if( check_password(input1, password1)) {
        printf("password 1 is correct\n");
    } else {
        printf("password 1 is wrong\n");
        printf("Bye!\n");
        system("pause");
        return 0;
    }
    char cipher[] = {0x63,0xaf,0x56,0x62,0x67,0x51,0x89,0x76,0xf8,0xb2,0x02,0x85,0xe4,0x1f,0x8a,0xe5};
    char* password2 = (char*)malloc(AES_ENC_MAX_LEN);

    DecryptCipherTxtToData(cipher, password2, 16);
    
    char input2[AES_ENC_MAX_LEN] = {0};
    printf("input password 2->");
    scanf("%s", input2);
    
    if (check_password(input2, password2)) {
        printf("password 2 is correct\n");
        printf("Nice!!!!!!!!!!!!!");
        system("pause");
    } else {
        printf("password 2 is wrong\n");
        printf("Bye!\n");
        system("pause");
        return 0;
    }
}
