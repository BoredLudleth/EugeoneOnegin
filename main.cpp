#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "OneginFunctions.hpp"

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
    TextSorter(index, length, line);
    TextPrint(sorted_text, index, line);
    free(index);
    free(allText);
    fclose(text);
    fclose(sorted_text);

}
