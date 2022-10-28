#ifndef ONEGIN_FUNCTIONS_H
#define ONEGIN_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void TextRead(FILE *text, char* allText, char** index, int line, int length);

void TextSorter(char** index, int length, int line);

void TextPrint(FILE *sorted_text, char** index, int line);

int lenFile(FILE *text);

int linesFile(FILE *text);

#endif // ONEGIN_FUNCTIONS_H