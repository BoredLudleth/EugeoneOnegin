#ifndef ONEGIN_FUNCTIONS_H
#define ONEGIN_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct TextStruct 
// {
//     FILE* text;
//     FILE*  sorted_text;
//     int length;
//     int line;
//     char* allText;
//     char** index;
// };

void TextRead(FILE *text, char* allText, char** index, int line, int length);

void TextSorter(char** index, int length, int line);

void TextPrint(FILE *sorted_text, char** index, int line);

int lenFile(FILE *text);

int linesFile(FILE *text);

void TextDestrustor(FILE* text, FILE*  sorted_text, char* allText, char** index);

#endif // ONEGIN_FUNCTIONS_H