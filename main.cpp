#include "OneginFunctions.hpp"

int main()
{
    struct TextStruct st;
    struct TextStruct* p_s = &st;

    TextConstructor (p_s);
    TextRead(p_s);
    TextSorter(p_s);
    TextPrint(p_s);
    TextDestrustor(p_s);
    
    return 0;
}