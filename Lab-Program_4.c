/*
NAME :- AYUSH KUMAR
BRANCH :- ECE A
ROLL NUMBER :- 2023ECE099
EXAM ROLL NUMBER :- 23294917099
ENROLLMENT NUMBER :- 23DOECBTEC000099
*/
#include <stdio.h>

// Function to find the length of a string
int str_length(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to reverse a string
void str_reverse(char* str) {
    int len = str_length(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to compare two strings
int str_compare(char* str1, char* str2) {
    int len1 = str_length(str1);
    int len2 = str_length(str2);
    int min_len = (len1 < len2) ? len1 : len2;
    for (int i = 0; i < min_len; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return len1 - len2;
}

// Function to concatenate two strings
void str_concatenate(char* dest, char* src) {
    int len1 = str_length(dest);
    int len2 = str_length(src);
    for (int i = 0; i < len2; i++) {
        dest[len1+i] = src[i];
    }
    dest[len1+len2] = '\0';
}

// Function to copy a string
void str_copy(char* dest, char* src) {
    int len = str_length(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int main() {
    char str1[100] = "hello";
    char str2[100] = "world";
    char str3[100];

    printf("Length of %s: %d\n", str1, str_length(str1));

    str_reverse(str1);
    printf("Reversed: %s\n", str1);

    if (str_compare(str1, str2) == 0) {
        printf("Strings are equal.\n");
    } else if (str_compare(str1, str2) < 0) {
        printf("%s comes before %s.\n", str1, str2);
    } else {
        printf("%s comes after %s.\n", str1, str2);
    }

    str_concatenate(str3, str1);
    str_concatenate(str3, " ");
    str_concatenate(str3, str2);
    printf("Concatenated: %s\n", str3);

    str_copy(str1, str2);
    printf("Copied: %s\n", str1);

    return 0;
}
