#include "OneginFunctions.hpp"

void TextRead(FILE *text, char* allText, char** index, int line, int length)
{
    length = fread(allText, sizeof(char), (size_t) (length), text);
    allText = (char*) realloc(allText, (length + 1) * sizeof(char));
    int count = 0;

    *index = allText;
    allText[length] = '\0';
    length = strlen(allText) + 1;

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

void TextSorter(char** index, int length, int line) 
{
    char* buffer = NULL;

    for (int i = 0; i < line; i++) 
    {
        for (int j = 0; j < (line - 1 - i); j++) 
        {
            if (strcmp(*(index + j), *(index + j +1)) > 0) 
            {
                buffer = *(index + j);
                *(index + j) = *(index + j +1);
                *(index + j + 1) = buffer;
            }
        }
    }
}//почекать

void TextPrint(FILE *sorted_text, char** index, int line)
{
    for (int i = 0; i < line; i++)
    {
        fputs(*(index + i), sorted_text);
        fputs("\n", sorted_text);
    }
}//fprintf

int lenFile(FILE *text)
{
    fseek(text, 0, SEEK_END);
    int length =  ftell(text);
    fseek(text, 0, SEEK_SET);

    return length;    
}

int linesFile(FILE *text)
{
    int lines = 0;
    int ch = 0;

    while ((ch = fgetc(text)) != EOF) 
    {
        if (ch == '\n')
        {
            lines++;
        }
    }

    fseek(text, 0, SEEK_SET);
    
    return ++lines;
}

void TextDestrustor(FILE* text, FILE*  sorted_text, char* allText, char** index)
{
    free(index);
    free(allText);

    fclose(text);
    fclose(sorted_text);
}
