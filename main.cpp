#include "OneginFunctions.hpp"

int main()
{
    struct TextStruct st;
    struct TextStruct* p_s = &st;

    TextConstructor (p_s);
    TextRead(p_s);
    // #ifdef QUICKSORT
    // qsort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));
    // #else
    TextSorter(p_s);
    // #endif //QUICKSORT
    TextPrint(p_s);
    TextDestrustor(p_s);
    
    return 0;
}