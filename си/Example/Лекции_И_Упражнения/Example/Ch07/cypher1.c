// cypher1.c -- вносит изменения во входящие данные, сохраняя пробелы
#include <stdio.h>
#define SPACE ' '             // кавычка, пробел, кавычка
int main(void)
{
    char ch;
    
    ch = getchar();           // читать символ         
    while (ch != '\n')        // пока не встретится конец строки
    {
        if (ch == SPACE)      // оставить пробел нетронутым
            putchar(ch);      // символ не меняется       
        else
            putchar(ch + 1);  // изменить другие символы  
        ch = getchar();       // получить следующий символ
    }
    putchar(ch);              // вывести символ новой строки
    
    return 0;
}
