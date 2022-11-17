#ifndef ONEGIN_FUNCTIONS_H
#define ONEGIN_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WITHOUT_SPACE

//#define NORMAL_SORT

#define MAXLENGTHOFFILENAME 160

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

#define NEWASSERT(condition)                                                            \
    if ((condition)) {                                                                 \
        printf("Problem with in file %s in function %s, condition %s in line %d\n",     \
               __FILE__, __FUNCTION__, #condition, __LINE__);                           \
        exit(0);                                                                        \
    }

struct indexAndLength 
{
    char** index; 
    int* length;
};

struct TextStruct 
{
    FILE* text;
    FILE* sorted_text;
    int length;
    int line;
    char* allText;
    struct indexAndLength lineInfo;
};

void TextConstructor (struct TextStruct* p_s);

void TextRead (struct TextStruct* p_s);

void countLines (struct TextStruct* p_s);

void setLengths (struct TextStruct* p_s);

void TextSorter (struct TextStruct* p_s, char (*f)(char*,char*));

void TextPrint (struct TextStruct* p_s);

int lenFile (FILE *text);

int linesFile (FILE *text);

void TextDestrustor (struct TextStruct* p_s);

bool checkSpace (char* st);

char comporator (char* cs, char* st);

char comporator_fromback (char* cs, char* st);

#endif // ONEGIN_FUNCTIONS_H