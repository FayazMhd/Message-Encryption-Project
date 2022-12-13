
// Author: Fayaz Mahmood
// Date: 23/11/2022

#ifndef ASSIGN4_CRYPT_H
#define ASSIGN4_CRYPT_H

/* Include the standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARRAY_SIZE 256                                                                                              // Define maximum array size
#define ENCRYPT(numeric_char,m) (numeric_char^m)                                                                        // Defining encrypt macro to perform xor bitwise

enum op{                                                                                                                // Naming 1 as encrypt and 2 as decrypt to prevent magic numbers
    encrypt = 1,                                                                                                        // using enumeration
    decrypt = 2
};


void encrypt_txt( char *buffer, unsigned int * numeric_seq, int buffer_length);                                         // function encrypts string
void decrypt_txt ( char *buffer, unsigned int * numeric_seq);                                                           // function decrypt the int


#endif //ASSIGN4_CRYPT_H