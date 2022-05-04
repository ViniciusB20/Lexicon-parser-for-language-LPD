
#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <string.h>
#include <stdlib.h>

// Variaveis
char *word = "\0";
char *special_word = "\0";
long int stack_parenthesis = 0;
long int stack_brackets = 0;

// Função para desalocar e limpar uma string dinâmica WORD e SPECIAL_WORD
void free_string_word(void) {
    free(word);
    word = (char * ) malloc(sizeof(char));
    word[0] = '\0';
}

void free_string_special_word(void) {
    free(special_word);
    special_word = (char * ) malloc(sizeof(char));
    special_word[0] = '\0';
}

// Função para redimensionar dinamicamente uma string WORD e SPECIAL_WORD
void resize_string(void) {
    int size = (int) strlen(word);
    char * old_word = (char * ) malloc(size * sizeof(char));

    strcpy(old_word, word);
    word = (char * ) malloc((size + 1) * sizeof(char));

    strcpy(word, old_word);
    free(old_word);

    word[(size + 1)] = '\0';
}

void resize_string_special_word(void) {
    int size = (int) strlen(special_word);
    char * old_word = (char * ) malloc(size * sizeof(char));

    strcpy(old_word, special_word);
    special_word = (char * ) malloc((size + 1) * sizeof(char));

    strcpy(special_word, old_word);
    free(old_word);

    special_word[(size + 1)] = '\0';
}

// Função para identificar o erro
int error_found(char input_char, int error_code, int line_count){
    printf("parenthesis stack {%li}, brackets stack {%li}\n",stack_parenthesis,stack_brackets);
    printf("Unexpected char {%c}, exiting with code {%i} found on line {%i}\n",input_char,error_code,line_count);
    return EXIT_FAILURE;

}
#endif
