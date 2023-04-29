#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/geometrysearch.h>
#include <libgeometry/parser.h>

typedef struct figure_info {
    char str[100 + 1];
    float radius;
    float x;
    float y;
    int count_figures;
    int* index_figures;
} figure;

int main(int argc, char* argv[])
{
    char* err_msg; // error message
    int err_smb;   // symbol of error
    int found, s, n, i, j;

    float radius;
    float x;
    float y;
    float a;
    float b;
    float c;

    figure* figures;

    char* c_radius;
    char* c_x;
    char* c_y;

    printf("Enter quantity of figures: ");

    scanf("%d", &n);

    while (getchar() != '\n')
        ;

    figures = malloc(n * sizeof(figure));

    FILE* tfile;
    if (argc == 2) {
        tfile = fopen(argv[1], "r");
        if (tfile == NULL) {
            printf("Can`t open file\n");
            return 1;
        } else {
            printf("File opened succesfully\n\n");

            for (i = 0; i < n; i++) {
                figures[i].count_figures = 0;
                figures[i].index_figures = malloc(n * sizeof(int));
                for (j = 0; j < n; j++)
                    figures[i].index_figures[i] = 0;

                fgets(figures[i].str, 100, tfile);
                printf("%s", figures[i].str);

                c_radius = malloc(100 * sizeof(char));
                c_x = malloc(100 * sizeof(char));
                c_y = malloc(100 * sizeof(char));

                found = find_circle(
                        figures[i].str,
                        &err_msg,
                        &err_smb,
                        &c_radius,
                        &c_x,
                        &c_y);

                if (found == 0) {
                    radius = atof(c_radius);
                    x = atof(c_x);
                    y = atof(c_y);
                    figures[i].x = x;
                    figures[i].y = y;
                    figures[i].radius = radius;
                } else {
                    for (s = 0; s < err_smb; s++)
                        printf(" ");
                    printf("^\n");
                    printf("Error at column %d: %s", err_smb + 1, err_msg);

                    fclose(tfile);
                    printf("File closed\n");
                    printf("Exit program with error...\n");
                    return 1;
                }
            }
        }
    }
    if (argc == 1) {
        for (i = 0; i < n; i++) {
            figures[i].count_figures = 0;
            figures[i].index_figures = malloc(n * sizeof(int));
            for (j = 0; j < n; j++)
                figures[i].index_figures[i] = 0;

            printf("Enter figure #%d: \n\n", i + 1);
            fgets(figures[i].str, 100, stdin);

            c_radius = malloc(100 * sizeof(char));
            c_x = malloc(100 * sizeof(char));
            c_y = malloc(100 * sizeof(char));

            found = find_circle(
                    figures[i].str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

            if (found == 0) {
                radius = atof(c_radius);
                x = atof(c_x);
                y = atof(c_y);
                figures[i].x = x;
                figures[i].y = y;
                figures[i].radius = radius;

                if (argc == 2) {
                    fclose(tfile);
                    printf("File closed\n");
                }
            } else {
                for (s = 0; s < err_smb; s++)
                    printf(" ");
                printf("^\n");
                printf("Error at column %d: %s", err_smb + 1, err_msg);
                printf("Exit program with error...\n");
                return 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            a = figures[i].x - figures[j].x;

            b = figures[i].y - figures[j].y;

            c = sqrt((a * a) + (b * b));

            printf("\n%f %f %f\n", a, b, c);

            if (c < figures[i].radius + figures[j].radius) {
                figures[i].count_figures += 1;
                figures[j].count_figures += 1;

                figures[i].index_figures[j] = 1;
                figures[j].index_figures[i] = 1;
            }

            a = 0;
            b = 0;
            c = 0;
        }

        printf("\n%s\n", figures[i].str);
        printf("  perimeter: = %.4f\n", circle_perimeter(figures[i].radius));
        printf("  area: = %.4f\n", circle_area(figures[i].radius));
        printf("  intersections: %d\n", figures[i].count_figures);
        for (j = 0; j < n; j++) {
            if (figures[i].index_figures[j]) {
                printf("    %d. circle\n", j + 1);
            }
        }
    }
    printf("Exit program...\n");
    return 0;
}
