#include <stdlib.h>
#include <stdbool.h>

#include "disemvowel.h"

int is_vowel( char c){
  int result;
  if ( c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||  c == 'i' ||  c == 'O' ||  c == 'o' ||  c == 'U' ||  c == 'u'){
    result = 1;
  }
  else { 
    result = 0;
  }
  return result;
}

char* disemvowel(char* str) {
  char* new_string;
  int counter = 0;
  int length = 0;
  int index = 0;
  int index2 = 0;
  //for loop for counting all the vowels and the length of the string
  while( str[length] != '\0'){
    length += 1;
    if ( is_vowel(str[length]) == 1){
      counter += 1;
    }
  }
  new_string = calloc(length+1-counter, sizeof(char));
  // Transfer all non-vowel characters
  while( str[index] != '\0'){
    if ( is_vowel(str[length]) == 0){
      new_string[index2] = str[index];
      index2 += 1;
    }
    index += 1;
  }
  new_string[index2 + 1] = '\0';
  
  return new_string;
}

