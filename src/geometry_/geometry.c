#include <ctype.h>
#include <libgeometry/geometrysearch.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("You have not entered FILE\n");
        return 1;
    }
    FILE* file;
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Couldn't open the FILE\n");
        return 2;
    }
    char str[100 + 1];
    fgets(str, 100, file);
    printf("%s", str);
    int s;
    char* err_msg; // error message
    int err_smb;   // symbol of error
    int found = find_circle(str, &err_msg, &err_smb);
    if (found == 0) {
        printf("\nRight entry");
        fclose(file);
        printf("\nFile closed\n");
        printf("Exit program...\n");
        return 0;
    } else {
        for (s = 0; s < err_smb; s++)
            printf(" ");
        printf("^\n");
        printf("Error at column %d: %s", err_smb + 1, err_msg);
        fclose(file);
        printf("\nFile closed\n");
        printf("Exit program with error\n");
        return 1;
    }
    return 0;
}