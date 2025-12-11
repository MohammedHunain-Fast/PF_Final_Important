#include <stdio.h>
#include <string.h>

int PalindromeCheck(char word[], int s, int e);

int main() {
    char word[20];
    printf("Enter the word: ");
    scanf("%s",word);
    int length = strlen(word) - 1;
    printf("%d\n",PalindromeCheck(word,0,length));
    return 0;
}

int PalindromeCheck(char word[], int s, int e) {
    if(s >= e) {
        return 1;
    }
    if(word[s] != word[e]) {
        return 0;
    }
    else {
        return PalindromeCheck(word, s + 1, e - 1);
    }
}
