#ifndef ONEGIN_FUNCTIONS_H
#define ONEGIN_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WITHOUT_SPACE

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

#define NEWASSERT(condition)                                                            \
    if ((condition)) {                                                                 \
        printf("Problem with in file %s in function %s, condition %s in line %d\n",     \
               __FILE__, __FUNCTION__, #condition, __LINE__);                           \
        exit(0);                                                                        \
    }

// struct TextStruct 
// {
//     FILE* text;
//     FILE*  sorted_text;
//     int length;
//     int line;
//     char* allText;
//     char** index;
// };
//
// void TextConstructor (struct TextStruct* p_s);

void TextRead(FILE *text, char* allText, char** index, int* line, int length);

void TextSorter(char** index, int length, int line);

void TextPrint(FILE *sorted_text, char** index, int line);

int lenFile(FILE *text);

int linesFile(FILE *text);

void TextDestrustor(FILE* text, FILE*  sorted_text, char* allText, char** index);

bool checkSpace (char* st);

char comporator (char* cs, char* st);

#endif // ONEGIN_FUNCTIONS_H