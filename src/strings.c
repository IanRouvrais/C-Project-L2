#include "include/strings.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>



void upper(char string[30]) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }
}

void lower(char string[30]) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

// returns 1 if error, like scanf
int getString(char *string) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (i == 29) {
            printf("String too long\n");
            return 1;
        }
        string[i] = c;
        i++;
    }
    string[i] = '\0';
    return 0;
}
