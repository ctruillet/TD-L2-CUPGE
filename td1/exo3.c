#include <stdio.h>
#include <stdlib.h>

int main(){
    char * str;

    str = (char*)malloc(64*sizeof(char));

    char c = ' ';
    int i = 0;
    while(c != '\n'){
        scanf("%c", &c);
        str[i] = c;
        i++;
    }

    printf("%s\n", str);
    


    return 0;
}