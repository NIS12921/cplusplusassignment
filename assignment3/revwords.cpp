#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end){ 
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
  if(i == 0){
    return i;}
    else if(!isalpha(str[i]) && isalpha(str[i+1])){
    return (i+1);}
    else if(!isalpha(str[i-1])){
     return i;}
     else if (i == len) {
        return -1;}
      else {
          while(i < len ){
          i++;
          if(!isalpha(str[i]))
          break;
      }
       if (i == len-1) {
        return -1;}
    
    return (i+1);}
    }
    

int find_next_end(char str[], int len, int i) {
  int j = find_next_start(str, len, i);
      if(j==-1){
         return -1;}
         else{
  while (j < len && isalpha(str[j])) {
        j++;
    }
    return (j-1);}
}


void reverse_words(char ss[]) { 
  int len = strlen(ss);
    int start = find_next_start(ss, len, 0);
    while (start != -1) {
        int end = find_next_end(ss, len, start);
        reverse_substring(ss, start, end);
        start = find_next_start(ss, len, end);
    }
}
