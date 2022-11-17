#include "OneginFunctions.hpp"

int main()
{
    struct TextStruct st = {};
    struct TextStruct* p_s = &st;
    
    #ifdef NORMAL_SORT
    char (*whichComporator)(char*, char*) = comporator;
    #else
    char (*whichComporator)(char*, char*) = comporator_fromback;    
    #endif

    TextConstructor (p_s);
    TextRead (p_s);
    TextSorter (p_s, whichComporator);
    TextPrint (p_s);
    TextDestrustor (p_s);
    
    return 0;
}