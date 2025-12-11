#include <stdio.h>
#include <string.h>

void reversestring(char *s, char *e);

int main() {
    char word[30];
    printf("Enter the word you want to enter: ");
    scanf("%s", word);
    int length = strlen(word) - 1; 
    reversestring(word, word + length);
    printf("Reversed:%s",word);
    return 0;
}

void reversestring(char *s, char *e) {
     if(s >= e) {
        return;
     }   
    char temp = *e;
    *e = *s;
    *s = temp;
    reversestring(s + 1, e - 1);
    
}
