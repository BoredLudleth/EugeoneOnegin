#include <stdio.h>
#include <cstring>
#include <Windows.h>

void TextRead(FILE *text, FILE *sorted_text, char* allText, char* LinedText, char** index);

void TextSorter(FILE *text, FILE *sorted_text);

int lenFile(FILE *text);

int linesFile(FILE *text);

int main(){
    FILE *text;
    FILE *sorted_text;
    text = fopen("TEXT.txt", "r");
    sorted_text = fopen("SORTEDTEXT.txt", "w");
    if (text == NULL || sorted_text == NULL) {
        printf("File didn't found");    
    }

    char* allText = (char*) calloc (lenFile(text), sizeof(char));
    int line = linesFile(text);
    char* LinedText[line] = {};
    char* index[line] = {};

    TextRead(text, sorted_text, (char*) allText, (char*) LinedText, (char**) index);

    TextSorter(text, sorted_text);

    fclose(text);
    fclose(sorted_text);
}

void TextRead(FILE *text, FILE *sorted_text, char* allText, char* LinedText, char** index)
{
    int length = lenFile(text);
    int line = linesFile(text);
    fread(allText, sizeof(char), (size_t) length, text);
    char* StringText = (char*) calloc(length + line, sizeof(char));
    *index = StringText;
    for (int i = 0, count = 0, line = 1; i < length; i++, count++) 
    {
        if (*(allText+i) != '\n')
        {
            StringText[count] = allText[i];
        } else {
            StringText[count] = '\n';
            StringText[(count++)] = '\0';
            *(index + line) = &StringText[(count++)];
            line++;
        }
    }

    for (int free_line = 0; free_line < line; free_line++){
        fputs((const char*) *(index + free_line), sorted_text);
    }
    free(StringText);
}

void TextSorter(FILE *text, FILE *sorted_text) 
{

}

int lenFile(FILE *text){
    fseek(text, 0, SEEK_END);
    int length = ftell(text);
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
    return lines;
}