#include "OneginFunctions.hpp"

int main()
{
    //struct TextStruct st;
    FILE* text = fopen("TEXT.txt", "rb");
    FILE*  sorted_text = fopen("SORTEDTEXT.txt", "wb");
    if (text == NULL) 
    {
        printf("File didn't found");    
    }

    int length = lenFile(text);
    int line = linesFile(text);

    char* allText = (char*) calloc (length, sizeof(char));
    char** index = (char**) calloc (line, sizeof(char*));

    TextRead(text, allText, index, line, length);
    TextSorter(index, length, line);
    TextPrint(sorted_text, index, line);
}
