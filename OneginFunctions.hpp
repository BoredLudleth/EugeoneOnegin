#ifndef ONEGIN_FUNCTIONS_H
#define ONEGIN_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

#define NEWASSERT(condition)                                                            \
    if (!(condition)) {                                                                 \
        printf("Problem with in file %s in function %s, condition %s in line %d\n",     \
               __FILE__, __FUNCTION__, #condition, __LINE__);                           \
        exit(1);                                                                        \
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
// void TextConstructor (struct TextStruct* p_s)
// {
//     p_s->text = fopen("TEXT.txt", "rb");
//     p_s->sorted_text = fopen("SORTEDTEXT.txt", "wb");
//     NEWASSERT(text == NULL or sorted_text == NULL); 

//     p_s->length = lenFile(p_s->text);
//     p_s->line = linesFile(p_s->text);
//     p_s->allText = allText = (char*) calloc (length, sizeof(char));
//     p_s index = index = (char**) calloc (line, sizeof(char*));

//     NEWASSERT(p_s->allText == NULL or p_s->index == NULL); 
// }

void TextRead(FILE *text, char* allText, char** index, int line, int length);

void TextSorter(char** index, int length, int line);

void TextPrint(FILE *sorted_text, char** index, int line);

int lenFile(FILE *text);

int linesFile(FILE *text);

void TextDestrustor(FILE* text, FILE*  sorted_text, char* allText, char** index);

#endif // ONEGIN_FUNCTIONS_H