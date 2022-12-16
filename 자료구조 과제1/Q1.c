#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, top = -1;
int a[15];
void PUSH(char c)
{
    if (top == N - 1)
    {
        for (int i = 0; i < top; ++i) //땡기기
            a[i] = a[i + 1];
        a[top] = c;
    }
    else   a[++top] = c;
}
void PRINT(int k)
{
    while (top >= 0)   printf("%c ", a[top--]); //끝난 뒤 top은 항상 -1로 고정
    printf("\n");
}
int main()
{
    while (1) //A B C D E F G H I J K
    {
        int i;
        printf("*** 스택크기 (10 이하 자연수), N = ");
        scanf("%d", &N);
        if (!N)
        {
            printf("Bye!!!\n");
            return 0;
        }
        for (i = 0; i < 11; ++i) PUSH((char)(i + 65));
        printf("Chars in Stack [%d]:   ", N);
        PRINT(0);
    }
}