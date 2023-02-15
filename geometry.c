#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("You have not entered FILE\n");
        return 1;
    }
    FILE* ptr;
    ptr = fopen(argv[1], "r");
    if (ptr == NULL) {
        printf("Couldn't open the FILE\n");
        return 2;
    }
    char* figure_type = malloc(7 * sizeof(char));
    fgets(figure_type, 7, ptr);
    if (figure_type == NULL) {
        printf("Figure type is dead\n");
        return 3;
    }
    /*for (int i = 0; i < strlen(figure_type); i++) {
        printf("%c\n", figure_type[i]);
    }*/
    char* point = malloc(6 * sizeof(char));
    fgets(point, 5, ptr);
    int points [2];
    char x = point[1];
    char y = point[3];
    points[0] = atoi(x);
    points[1] = atoi(y);
    printf("x: %i, y: %i\n", points[0], points[1]);
    free(figure_type);
    free(point);
    return 0;
}
