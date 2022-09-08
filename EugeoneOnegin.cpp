#include <stdio.h>
#include <cstring>
#include <Windows.h>


void TextSorter(FILE *text, FILE *sorted_text);

int main(){
    SetConsoleCP (1251); 
    SetConsoleOutputCP (1251);

    FILE *text;
    FILE *sorted_text;

    text = fopen("TEXT.txt", "r");
    sorted_text = fopen("SORTEDTEXT.txt", "w");
    if (text == NULL || sorted_text == NULL) {
        printf("File didn't found");    
    }
    TextSorter(text, sorted_text);

    fclose(text);
    fclose(sorted_text);
}

void TextSorter(FILE *text, FILE *sorted_text) {
    fseek(text, 0, SEEK_END);
    int length = ftell(text);
    char allstr[length][1000] = {0};
    fseek(text, 0, SEEK_SET);

    for (int k = 0; !feof(text); k++){
        fgets(allstr[k], sizeof(allstr[k]), text);
    }
    char time_str[1000] = {0};
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (strcmp(allstr[i], allstr[j]) < 0 ) {
                strcpy(time_str, allstr[i]);
                strcpy(allstr[i], allstr[j]);
                strcpy(allstr[j], time_str);
            }
        }
    }
    for (int count = 0; count < length; count++) {
        fputs(allstr[count], sorted_text);
    }
}