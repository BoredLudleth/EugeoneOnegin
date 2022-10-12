#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void TextRead(FILE *text, char* allText, char** index, int line, int length);

void TextSorter(FILE *text, FILE *sorted_text);

int lenFile(FILE *text);

int linesFile(FILE *text);

int main()
{
    FILE* text = fopen("TEXT3.txt", "rb");
    FILE*  sorted_text = fopen("SORTEDTEXT.txt", "wb");
    if (text == NULL) {
        printf("File didn't found");    
    }

    int length = lenFile(text);
    int line = linesFile(text);

    char* allText = (char*) calloc (length, sizeof(char));
    char** index = (char**) calloc (line, sizeof(char*));
    TextRead(text, allText, index, line, length);

    for (int i = 0; i < line; i++)
    {
        fputs(*(index + i), sorted_text);
        fputs("\n", sorted_text);
    }
    fclose(text);
    fclose(sorted_text);

}

void TextRead(FILE *text, char* allText, char** index, int line, int length)
{
    fread(allText, sizeof(char), (size_t) (length + 1), text);
    int count = 0;
    *index = allText;
    for (int i = 0; i < length; i++)
    {
        if (allText[i] == '\n') 
        {
            allText[i] = '\0';
            count++;
        }
        if ((i > 0) && (allText[i - 1] == '\0')) 
        {
            *(index + count) = allText + i;
        }
    }
}

void TextSorter(FILE *text, FILE *sorted_text) 
{

}

int lenFile(FILE *text){
    fseek(text, 0, SEEK_END);
    int length =  ftell(text);
    fseek(text, 0, SEEK_SET);
    return length;    
}

int linesFile(FILE *text){
    int lines = 0;
    int ch = 0;
    while ((ch = fgetc(text)) != EOF) {
        if (ch == '\n')
            lines++;
    }
    fseek(text, 0, SEEK_SET);
    return ++lines;
}