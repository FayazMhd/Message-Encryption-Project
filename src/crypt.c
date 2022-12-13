
// Author: Fayaz Mahmood
// Date: 23/11/2022

#include "../inc/crypt.h"

unsigned int mask = 0xa5;                                                                                               // declaring variable
char *start = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&():;?.,/";                                                     // declaring start variable
char *sub = ":;?.,/0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&()";                                                       // declaring sub variable


void encrypt_txt(char *buffer, unsigned int * numeric_seq, int buffer_length)                                           // This function encrypt string
{
    for(int i = 0; i < buffer_length-1; i++) {
        if(buffer[i] != ' ') {                                                                                          // ignore space characters
            char *e = strchr(start, toupper(buffer[i]));                                                                // find the first occurrence of buffer[i] char in string start
            int index = (int)(e-start);                                                                                 // find the index of the first occurrence of buffer[i] in start
            buffer[i] = sub[index];                                                                                     // copy sub[index] to buffer[i]
        }
        numeric_seq[i] = ENCRYPT((int)buffer[i],mask);                                                                  // encrypt using bitwise XOR
        if(i == 0)
        {
            printf("\nThe encrypted message is:\n");
        }
        printf("%u ",numeric_seq[i]);                                                                                   // prints user encrypted message
    }
    printf("\n");
}


void decrypt_txt(char *buffer, unsigned int * numeric_seq)                                                              // This function decrypts string
{
    char *token;
    char *delim = " ";
    int numeric_seq_index = 0;
    token = strtok(buffer, delim);                                                                                      // parse the string omitting the delimiter
    while(token != NULL) {
        numeric_seq[numeric_seq_index++] = atoi(token);                                                                 // convert string to integer and copy it to numeric_seq array
        token = strtok(NULL,delim);
    }
    int numeric_seq_size = numeric_seq_index;                                                                           // get numeric_seq array size
    for(int i = 0; i < numeric_seq_size; i++) {
        buffer[i] = (char) ENCRYPT(numeric_seq[i],mask);                                                                // decrypt using bitwise XOR
        if(buffer[i] != ' ') {
            char *e = strchr(sub, toupper(buffer[i]));                                                                  // find the first occurrence of buffer[i] char in string sub
            int index = (int)(e-sub);                                                                                   // find the index of the first occurrence of buffer[i] in sub
            buffer[i] = start[index];                                                                                   // copy start[index] to buffer[i]
        }
    }

    printf("\nThe decrypted message is:\n");
    for(int i=0;i < strlen(buffer); i++)
    {
        printf("%c", buffer[i]);                                                                                        // prints the decrypted message
        if (buffer[i] == '.') {
            break;
        }

    }
}
