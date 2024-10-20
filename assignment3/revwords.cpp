#include <cctype>
#include <cstring>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--; 
    }
}

int find_next_start(char str[], int len, int i) { 
    while (i < len && !isalpha(str[i])) {
        i++;
    }
    return (i < len) ? i : -1;
}

int find_next_end(char str[], int len, int i) {
    while (i < len && isalpha(str[i])) {
        i++;
    }
    return (i > 0) ? (i - 1) : -1; 
}

void reverse_words(char ss[]) { 
    int len = strlen(ss);
    int start = find_next_start(ss, len, 0);
    
    while (start != -1) {
        int end = find_next_end(ss, len, start);
        reverse_substring(ss, start, end);
        start = find_next_start(ss, len, end + 1); 
    }
} 
