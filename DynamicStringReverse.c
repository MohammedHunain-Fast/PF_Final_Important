#include <stdio.h>
#include <stdlib.h>

void ReverseWord(char *r);

int main() {
    int n = 0;
    
    printf("Enter the size of string: ");
    scanf("%d", &n);
    while(getchar() != '\n');
    
    char *word = malloc(n * sizeof(char));
    if(word == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    printf("Enter a word: ");
    scanf("%[^\n]", word);
    while(getchar() != '\n');
    
    ReverseWord(word);

    free(word);
    word = NULL;

    return 0;
}

void ReverseWord(char *r)  {
    if(*r == '\0' || *r == '\n') return ;
    else ReverseWord(r + 1);
    printf("%c", *r);

}
