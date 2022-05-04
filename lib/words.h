
#ifndef WORDS_H
#define WORDS_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include ".\lib\dynamic.h"


enum RESPONSE_CODES {
    OK = 200, INVALID
};


enum RESERVED_WORDS {
    AND = 0x200, BEGIN, CHAR, DIV, DO, ELSE, END, FUNCTION,
    IF, INT, NOT, OR, PROCEDURE, PROGRAM, READD, READC, REPEAT,
    THEN, UNTIL, VAR, WHILE, WRITED, WRITEC, ATTRIBUTION, DISTINCTION,
    GTE, LTE, POINTER, SEMICOLON, COMMA, MINUS, MORE, MULTIPLICATION,
    OPEN_PARENTHESIS, CLOSE_PARENTHESIS, OPEN_BRACKETS, CLOSE_BRACKETS,
    GREAT, LESS, EQUAL, IDENTIFIER, NUMBER
};

//  Nome do arquivo de sa�da
char output_filename[200];
extern char *word;
extern char *special_word;
extern int lineCount;

// Fun��o para salvar palavras reservadas e identificadores
void save_reserved_word(char *input_word, int code_word, int line_count){

    FILE * file = fopen(output_filename, "a");

    fprintf(file, "%s", input_word);
    fprintf(file, "%c", ';');
    fprintf(file, "%i", code_word);
    fprintf(file, "%c", ';');
    fprintf(file, "%i\n", line_count);

    fclose(file);
}

// Fun��o para validar a palavra reservada AND
int is_and(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'A': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, AND, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_begin(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'B': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'G': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 5) {
        save_reserved_word(local_word, BEGIN, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_char(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'C': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 4) {
        save_reserved_word(local_word, CHAR, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_div(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'D': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'V': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, DIV, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_do(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'D': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 2) {
        save_reserved_word(local_word,  DO, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_else(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';


    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];


        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'E': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'S': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 4) {
        save_reserved_word(local_word, ELSE, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_end(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'E': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, END, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_function(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'F': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'U': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else if (state == 7) {
                    local_word[i] = toupper(chr);
                    state = 8;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 6) {
                    local_word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 8) {
        save_reserved_word(local_word, FUNCTION, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_if(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'I': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'F': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 2) {
        save_reserved_word(local_word,  IF, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_int(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'I': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, INT, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_not(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];


        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'N': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, NOT, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_or(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'O': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 2) {
        save_reserved_word(local_word,  OR, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_procedure(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'P': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else if (state == 7) {
                    local_word[i] = toupper(chr);
                    state = 8;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else if (state == 8) {
                    local_word[i] = toupper(chr);
                    state = 9;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'U': {
                if (state == 6) {
                    local_word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 9) {
        save_reserved_word(local_word, PROCEDURE, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_program(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';


    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];


        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'P': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'G': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'M': {
                if (state == 6) {
                    local_word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 7) {
        save_reserved_word(local_word, PROGRAM, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_readd(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 5) {
        save_reserved_word(local_word, READD, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_readc(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 5) {
        save_reserved_word(local_word, READC, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_repeat(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'P': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 6) {
        save_reserved_word(local_word, REPEAT, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_then(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'T': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 4) {
        save_reserved_word(local_word, THEN, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_until(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'U': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 5) {
        save_reserved_word(local_word, UNTIL, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_var(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'V': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 3) {
        save_reserved_word(local_word, VAR, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_while(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 5) {
        save_reserved_word(local_word, WHILE, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada WRITED
int is_writed(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Validando palavra reservada
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Valide se � char ou n�mero
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Escrevendo palavra reservada
    if (state == 6) {
        save_reserved_word(local_word, WRITED, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada WRITEC
int is_writec(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Validando palavra reservada
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Valide se � char ou n�mero
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    local_word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    local_word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    local_word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 3) {
                    local_word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    local_word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 5) {
                    local_word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 6) {
        save_reserved_word(local_word, WRITEC, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

int is_identifier(char * input_word, int size_word, int line_count) {
    int i;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (i== 0 && !isdigit(chr)) {
            local_word[i] = chr;
        } else if(i > 0 && isalnum(chr)){
            local_word[i] = chr;
        } else {
            i = size_word;
            return INVALID;
        }

        local_word[i] = chr;

    }

    save_reserved_word(local_word, IDENTIFIER, line_count);
    return OK;

}

int is_number(char * input_word, int size_word, int line_count) {
    int i;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if (isdigit(chr)) {
            local_word[i] = chr;
        } else {
            i = size_word;
            return INVALID;
        }

        local_word[i] = chr;
    }

    save_reserved_word(local_word, NUMBER, line_count);
    return OK;

}

// Fun��o para validar palavra reservada
int is_attribution(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if ((int)chr != 58 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case ':': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    local_word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        save_reserved_word(local_word, ATTRIBUTION, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada
int is_distinction(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';


    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if ((int)chr != 60 && (int)chr != 62) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '>': {
                if (state == 1) {
                    local_word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 2) {
        save_reserved_word(local_word, DISTINCTION, line_count);
        return OK;
    } else {
        return INVALID;
    }
}


int is_great_than_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';


    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        if ((int)chr != 62 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '>': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    local_word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    if (state == 2) {
        save_reserved_word(local_word, GTE, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada
int is_less_than_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Validando palavra reservada
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Valida se n�o � um caractere especial
        if ((int)chr != 60 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    local_word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Escrevendo palavra reservada
    if (state == 2) {
        save_reserved_word(local_word, LTE, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada
int is_great(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Validando palavra reservada
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Valida se n�o � um caractere especial
        if ((int)chr != 62) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '>': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Escrevendo palavra reservada
    if (state == 1) {
        save_reserved_word(local_word, GREAT, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada
int is_less(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Valida se n�o � um caractere especial
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Valida se n�o � um caractere especial
        if ((int)chr != 60) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Escrevendo palavra reservada
    if (state == 1) {
        save_reserved_word(local_word, LESS, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

// Fun��o para validar palavra reservada
int is_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    char chr, local_word[size_word + 1];
    local_word[0] = '\0';

    // Validando palavra reservada
    for (i = 0; i < size_word; i++) {
        local_word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '=': {
                if (state == 0) {
                    local_word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Escrevendo palavra reservada
    if (state == 1) {
        save_reserved_word(local_word, EQUAL, line_count);
        return OK;
    } else {
        return INVALID;
    }
}

//Fun��o para validar caracteres especiais
void save_special_chars(char input_word, int code, int line_count) {
    FILE * file;

    file = fopen(output_filename, "a");
    fprintf(file, "%c", input_word);
    fprintf(file, "%c", ';');
    fprintf(file, "%i", code);
    fprintf(file, "%c", ';');
    fprintf(file, "%i\n", line_count);
    fclose(file);

}

// Fun��o para listar palavras reservadas
void reserved_words(void) {
	printf("INVALID: { %i } \n", INVALID);
	printf("OK: { %i } \n", OK);
	printf("AND: { 0x%X } | { %i } \n", AND, AND);
	printf("BEGIN: { 0x%X } | { %i } \n", BEGIN, BEGIN);
	printf("CHAR: { 0x%X } | { %i } \n", CHAR, CHAR);
	printf("DIV: { 0x%X } | { %i } \n", DIV, DIV);
	printf("DO: { 0x%X } | { %i } \n", DO, DO);
	printf("ELSE: { 0x%X } | { %i } \n", ELSE, ELSE);
	printf("END: { 0x%X } | { %i } \n", END, END);
	printf("FUNCTION: { 0x%X } | { %i } \n", FUNCTION, FUNCTION);
	printf("IF: { 0x%X } | { %i } \n", IF, IF);
	printf("INT: { 0x%X } | { %i } \n", INT, INT);
	printf("NOT: { 0x%X } | { %i } \n", NOT, NOT);
	printf("OR: { 0x%X } | { %i } \n", OR, OR);
	printf("PROCEDURE: { 0x%X } | { %i } \n", PROCEDURE, PROCEDURE);
	printf("PROGRAM: { 0x%X } | { %i } \n", PROGRAM, PROGRAM);
	printf("READD: { 0x%X } | { %i } \n", READD, READD);
	printf("READC: { 0x%X } | { %i } \n", READC, READC);
	printf("REPEAT: { 0x%X } | { %i } \n", REPEAT, REPEAT);
	printf("THEN: { 0x%X } | { %i } \n", THEN, THEN);
	printf("UNTIL: { 0x%X } | { %i } \n", UNTIL, UNTIL);
	printf("VAR: { 0x%X } | { %i } \n", VAR, VAR);
	printf("WHILE: { 0x%X } | { %i } \n", WHILE, WHILE);
	printf("WRITED: { 0x%X } | { %i } \n", WRITED, WRITED);
	printf("WRITEC: { 0x%X } | { %i } \n", WRITEC, WRITEC);
    printf("ATTRIBUTION: { 0x%X } | { %i } \n", ATTRIBUTION, ATTRIBUTION);
    printf("DISTINCTION: { 0x%X } | { %i } \n", DISTINCTION, DISTINCTION);
    printf("GTE: { 0x%X } | { %i } \n", GTE, GTE);
    printf("LTE: { 0x%X } | { %i } \n", LTE, LTE);
    printf("POINTER: { 0x%X | { %i } \n", POINTER, POINTER);
    printf("SEMICOLON: { 0x%X | { %i } \n", SEMICOLON, SEMICOLON);
    printf("COMMA: { 0x%X | { %i } \n", COMMA, COMMA);
    printf("MINUS: { 0x%X | { %i } \n", MINUS, MINUS);
    printf("MORE: { 0x%X | { %i } \n", MORE, MORE);
    printf("MULTIPLICATION: { 0x%X | { %i } \n", MULTIPLICATION, MULTIPLICATION);
    printf("OPEN_PARENTHESIS: { 0x%X | { %i } \n", OPEN_PARENTHESIS, OPEN_PARENTHESIS);
    printf("CLOSE_PARENTHESIS: { 0x%X | { %i } \n", CLOSE_PARENTHESIS, CLOSE_PARENTHESIS);
    printf("OPEN_BRACKETS: { 0x%X | { %i } \n", OPEN_BRACKETS, OPEN_BRACKETS);
    printf("CLOSE_BRACKETS: { 0x%X | { %i } \n", CLOSE_BRACKETS, CLOSE_BRACKETS);
    printf("GREAT: { 0x%X | { %i } \n", GREAT, GREAT);
    printf("LESS: { 0x%X | { %i } \n", LESS, LESS);
    printf("EQUAL: { 0x%X | { %i } \n", EQUAL, EQUAL);
    printf("IDENTIFIER: { 0x%X | { %i } \n", IDENTIFIER, IDENTIFIER);
    printf("NUMBER: { 0x%X | { %i } \n", NUMBER, NUMBER);
}

// Verifica��o de fun��o e cria��o de arquivo de sa�da
void check_out_file(void) {
    FILE * file;

    if ((file = fopen(output_filename, "r")) == NULL) {
        file = fopen(output_filename, "w");
        fprintf(file, "%s", "WORD");
        fprintf(file, "%c", ';');
        fprintf(file, "%s", "CODE");
        fprintf(file, "%c", ';');
        fprintf(file, "%s", "LINE\n");
        fclose(file);
    }
}

// Fun��o para verificar e validar palavras identificadas
int check_words(char * input, int size_word, int line_count) {
    int response;

    check_out_file();

    if (size_word > 0) {
        if (is_and(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_begin(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_char(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_div(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_do(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_else(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_end(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_function(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_if(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_int(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_not(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_or(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_procedure(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_program(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_readd(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_readc(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_repeat(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_then(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_until(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_var(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_while(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_writed(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_writec(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_attribution(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_distinction(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_great_than_equal(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_less_than_equal(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_great(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_less(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if (is_equal(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if(is_identifier(input, size_word, line_count) == OK) {
            response = OK;
        }
        else if(is_number(input, size_word, line_count) == OK) {
            response = OK;
        }
    } else {
        response = INVALID;
    }

    return response;
}

// Fun��o para validar os caracteres de termina��o mais comuns e verificar SPECIAL_WORD
void validate_end_of_word(char read_chr, int lineCount) {
    switch (read_chr) {
        case ' ': {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            break;
        }

        case '\n': {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            lineCount++;
            break;
        }

        case EOF: {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            break;
        }
    }
}

// Fun��o para concatar novos caracteres em WORD
void is_not_eof_or_new_line(int input_char) {
    if ((int)input_char != 13 && input_char != EOF) {
        word[(int) strlen(word)] = input_char;
    }
}

// Fun��o para validar caracteres reservados SPECIAL_WORD
void is_special_chars(char input_char, int lineCount) {
    switch (input_char) {
        case ':': {
            special_word[(int) strlen(special_word)] = input_char;
            break;
        }

        case '>': {
            special_word[(int) strlen(special_word)] = input_char;
            break;
        }

        case '<': {
            special_word[(int) strlen(special_word)] = input_char;
            break;
        }

        case '=': {
            special_word[(int) strlen(special_word)] = input_char;
            break;
        }

        default:
            if (strlen(special_word) == 2) {
                validate_end_of_word(input_char, lineCount);
            } else if (strlen(special_word) == 1) {
                validate_end_of_word(input_char, lineCount);
            }
    }
}

# endif
