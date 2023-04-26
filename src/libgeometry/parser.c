#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_circle(char* str, char** err_msg, int* err_smb)
{
    size_t i, j;
    if (strncmp(str, "circle(", 7) == 0) { // circle

        for (i = 7; i < strlen(str); i++) { // founding number 1
            if (str[i] == 32) {             // " "
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        break;
                    }
                    *err_msg = "expected digit, dot or space\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "expected digit, dot or space\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    *err_msg = "expected digit or space\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit or space\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }

        for (i = j + 1; i < strlen(str); i++) { // founding number 2
            if (str[i] == 32) {                 // " "
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        break;
                    }
                    *err_msg = "expected digit, dot, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "expected digit, dot, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    *err_msg = "expected digit, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit, space or comma\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 44) { // ","
                break;
            }
            if (str[j] == 32) { // " "
                continue;
            }
            *err_msg = "expected space or comma\n";
            *err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            *err_msg = "expected comma\n";
            *err_smb = j;
            return 1;
        }
        for (i = j + 1; i < strlen(str); i++) { // founding number 3
            if (str[i] == 32) {                 // " "
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    *err_msg = "expected digit, dot, space or bracket\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "expected digit, dot, bracket or space\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    *err_msg = "expected digit, space or bracket\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit, bracket or space\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 32) { // " "
                continue;
            }
            if (str[j] == 41) { // ")"
                break;
            }
            *err_msg = "expected space or bracket\n";
            *err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            *err_msg = "expected bracket\n";
            *err_smb = j;
            return 1;
        }

    } else {
        if (strncmp(str, "circle", 6) == 0) {
            *err_msg = "expected '('\n";
            *err_smb = 6;
            return 1;
        } else {
            *err_msg = "expected 'circle'\n";
            *err_smb = 0;
            return 1;
        }
    }
    return 0;
}
