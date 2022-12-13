
// Author: Fayaz Mahmood
// Date: 23/11/2022

#include "../inc/crypt.h"

int main (void) {                                                                                                       // main/driver function

    int operation;                                                                                                      // Operation variable

    char buffer[MAX_ARRAY_SIZE];                                                                                        // Declaring buffer array of size 256
    unsigned int numeric_seq[MAX_ARRAY_SIZE];                                                                           // Declaring buffer of encrypted int data


    printf("What operation would you like to perform (1 - Encrypt, 2 - Decrypt)?\n");                                   // prompting users to encrypt or decrypt
    scanf("%d%*c", &operation);                                                                                         // scans users input
    if(operation == encrypt) {                                                                                          // if user selects encrypt then execute
        // Encrypt
        printf("\nSo, you want to encrypt the message!\n");                                                             // prints user choice to terminal
        printf("Please enter your message:\n");                                                                         // prompts user to enter message
        fgets(buffer, MAX_ARRAY_SIZE , stdin);                                                                          // gets user input and stores into buffer
        encrypt_txt (buffer, numeric_seq, strlen(buffer));                                                              // calls encrypt function and passes 3 parameters through it

    } else if   (operation == decrypt) {                                                                                // if user selects decrypt then execute
        // Decrypt
        printf("\nSo, you want to decrypt the message!\n");                                                             // prints user choice to terminal
        printf("Please enter your message:\n");                                                                         // prompts user to enter message
        fgets(buffer, MAX_ARRAY_SIZE , stdin);                                                                          // gets users input and stores into buffer
        decrypt_txt(buffer, numeric_seq);                                                                               // calls decrypt function and passes 3 parameters through it
    } else {
        printf("\nSo, you do not know what you want!\n");                                                               // if user inputs something else
        exit(1);                                                                                                        // then print and exit with error code 1
    }
    return 0;
}


