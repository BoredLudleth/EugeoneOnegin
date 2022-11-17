#include "OneginFunctions.hpp"

void TextConstructor (struct TextStruct* p_s)
{
    char readFileName[MAXLENGTHOFFILENAME] = "";
    printf("Which file do you want to open? Please write NAME_OF_FILE.type\n");
    scanf("%s", readFileName);
    p_s->text = fopen(readFileName, "rb+");

    char writeFileName[MAXLENGTHOFFILENAME] = "";
    printf("Which file do you want to use for output? Please write NAME_OF_FILE.type\n");
    scanf("%s", writeFileName);    
    p_s->sorted_text = fopen(writeFileName, "wb+");

    NEWASSERT(p_s->text == NULL or p_s->sorted_text == NULL); 

    p_s->length = lenFile(p_s->text);
    p_s->allText = (char*) calloc (p_s->length, sizeof(char));
    int howManySymbolRead = fread(p_s->allText, sizeof(char), (size_t) (p_s->length), p_s->text);

    NEWASSERT(howManySymbolRead == 0);

    countLines(p_s);

    p_s->lineInfo.index = (char**) calloc (p_s->line, sizeof(char*));
    p_s->lineInfo.length = (int*) calloc (p_s->line, sizeof(int));

    NEWASSERT(p_s->allText == NULL or p_s->lineInfo.index == NULL or p_s->lineInfo.length == NULL); 
}

void TextRead(struct TextStruct* p_s)
{
    int count = 0;

    p_s->allText[p_s->length] = '\0';
    p_s->lineInfo.index[0] = &(p_s->allText[0]);

    for (int i = 0; i < p_s->length; i++)
    {
        if (p_s->allText[i] == '\n') 
        {
            p_s->allText[i] = '\0';
            count++;
        }

        if ((i > 0) && (p_s->allText[i - 1] == '\0')) 
        {
            p_s->lineInfo.index[count] = p_s->allText + i;
        }
    }

    setLengths(p_s);
}

void countLines (struct TextStruct* p_s)
{
    p_s->line = 1;

    for (int i = 0; i < (p_s->length); i++)
    {
        if (p_s->allText[i] == '\n')
        {
            (p_s->line) += 1;
        }
    }
}

void setLengths (struct TextStruct* p_s)
{
    for (int i = 0; i < (p_s->line); i++)
    {
        p_s->lineInfo.length[i] = strlen(p_s->lineInfo.index[i]);
    }
}

void TextSorter(struct TextStruct* p_s, char (*f)(char*,char*))
{
    char* buffer = NULL;

    for (int i = 0; i < (p_s->line); i++) 
    {
        for (int j = 0; j < (p_s->line - i- 1); j++) 
        {
            if (f(p_s->lineInfo.index[j], p_s->lineInfo.index[j +1]) > 0) 
            {
                buffer = p_s->lineInfo.index[j];
                p_s->lineInfo.index[j] = p_s->lineInfo.index[j + 1];
                p_s->lineInfo.index[j + 1] = buffer;
            }
        }
    }
}

void TextPrint(struct TextStruct* p_s)
{
    for (int i = 0; i < p_s->line; i++)
    {   
#ifdef WITHOUT_SPACE
        if (comporator(p_s->lineInfo.index[i], (char*) "\0") > 0)
#endif //WITHOUT_SPACE
        {
            fputs(p_s->lineInfo.index[i], p_s->sorted_text);
            fputs("\n", p_s->sorted_text);
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

void TextDestrustor(struct TextStruct* p_s)
{
    free(p_s->lineInfo.index);
    free(p_s->lineInfo.length);
    free(p_s->allText);

    fclose(p_s->text);
    fclose(p_s->sorted_text);
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

char comporator_fromback(char* cs, char* st)
{
    int i = strlen(cs) - 1;
    int j = strlen(st) - 1;

    while (!isalpha(cs[i]) && i >= 0)
    {
        i--;
    }

    while (!isalpha(st[j]) && j >= 0)
    {
        j--;
    }

    for ( ; (tolower (cs[i]) == tolower (st[j])) || i < 0 || j < 0; i--, j--)
    {
        if (i < 0 || j < 0)
            break;

        while (!isalpha(cs[i]) && i >=0)
        {
            i--;
        }

        while (!isalpha(st[j]) && j >=0)
        {
            j--;
        } 
    }

    return tolower(cs[i]) - tolower(st[j]); 
}