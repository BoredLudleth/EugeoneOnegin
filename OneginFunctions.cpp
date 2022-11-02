#include "OneginFunctions.hpp"

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

void TextRead(FILE *text, char* allText, char** index, int* line, int length)
{
    length = fread(allText, sizeof(char), (size_t) (length), text);
    allText = (char*) realloc(allText, (length + 1) * sizeof(char));
    int count = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (allText[i] == '\n')
        {
            (*line)++;
        }
    }

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
            if (comporator(*(index + j), *(index + j +1)) > 0) 
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
#ifdef WITHOUT_SPACE
        if (comporator(*(index + i), (char*) "\0") > 0)
#endif //WITHOUT_SPACE
        {
            fputs(*(index + i), sorted_text);
            fputs("\n", sorted_text);
        }
    }
}

int lenFile(FILE *text)
{
    fseek(text, 0, SEEK_END);
    int length =  ftell(text);
    fseek(text, 0, SEEK_SET);

    return length;    
}

// int linesFile(FILE *text)
// {
//     int lines = 0;
//     int ch = 0;

//     while ((ch = fgetc(text)) != EOF) 
//     {
//         if (ch == '\n')
//         {
//             lines++;
//         }
//     }

//     fseek(text, 0, SEEK_SET);
    
//     return ++lines;
// }

void TextDestrustor(FILE* text, FILE*  sorted_text, char* allText, char** index)
{
    free(index);
    free(allText);

    fclose(text);
    fclose(sorted_text);
}

char comporator (char* cs, char* st)
{
    int i = 0;
    int j = 0;

    while (!isalpha(cs[i]) && cs[i] != '\0')
    {
        i++;
    }

    while (!isalpha(st[j]) && st[j] != '\0')
    {
        j++;
    }

    for ( ; cs[i] == st[j] && cs[i] != '\0'; i++, j++)
    {
        if (cs[i] != '\0' && st[j] != '\0')
            break;
        while (!isalpha(cs[i]))
        {
            i++;
        }

        while (!isalpha(st[j]))
        {
            j++;
        } 
    }

    return cs[i] - st[j]; 
}