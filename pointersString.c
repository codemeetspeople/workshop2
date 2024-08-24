#include <stdio.h>

int main() {
    char str1[10] = "Hello!";
    char str2[10] = "Devclub";
    char str3[10] = "caiman";

    char* strings[3] = {str1, str2, str3};

    for ( int i = 0; i < 3; i++ ) {
        printf("%s\n", strings[i]);
    }

    printf("%c\n", strings[1][0]);
    printf("%c\n", strings[1][1]);
    printf("%c\n", strings[1][2]);
    printf("%c\n", strings[1][3]);
    printf("%c\n", strings[1][4]);
    printf("%c\n", strings[1][5]);
    printf("%c\n", strings[1][6]);

    return 0;
}
