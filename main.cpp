#include "OneginFunctions.hpp"

int main()
{
    //struct TextStruct st;
    FILE* text = fopen("TEXT.txt", "rb");
    FILE*  sorted_text = fopen("SORTEDTEXT.txt", "wb");

    NEWASSERT(text == NULL or sorted_text == NULL); 

    int length = lenFile(text);
    int line = 0;

    char* allText = (char*) calloc (length, sizeof(char));
    char** index = (char**) calloc (line, sizeof(char*));

    NEWASSERT(allText == NULL or index == NULL); 

    TextRead(text, allText, index, &line, length);
    
    TextSorter(index, length, line);
    
    TextPrint(sorted_text, index, line);
    
    return 0;
}