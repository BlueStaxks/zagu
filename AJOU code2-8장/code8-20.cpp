/* 20


    0 3 8 4 -4
    * 0 * 1 7
    * 4 0 5 11
    2 -1 -5 0 -2
    * * * 6 0

    1번이 답.

*/
#include<iostream>
#define NUMBER 5
#define INF 200000000
#define LIM 2
using namespace std;

int table[NUMBER][NUMBER] = {
 {0,3,8,INF,-4}
,{INF,0,INF,1,7}
,{INF,4,0,INF,INF}
,{2,INF,-5,0,INF}
,{INF,INF,INF,6,0}
};


void FloydFunction()
{
for (int k = 0; k <= LIM; k++) { //K에 제한 걸면 됨

    for (int i = 0; i < NUMBER; i++)
    {
        for (int j = 0; j < NUMBER; j++)
        {
            int temp = table[i][k] + table[k][j];
            if (temp < table[i][j])
                table[i][j] = temp;

        }
    }
}
}
void printTable()
{
for (int i = 0; i < NUMBER; i++)
{
    for (int j = 0; j < NUMBER; j++)
    {
        if(table[i][j]==INF)
            printf("* ");
        else
            cout << table[i][j]<<" ";
    }
    cout << endl;
}
}

int main()
{

    FloydFunction();
    printTable();

    return 0;
}