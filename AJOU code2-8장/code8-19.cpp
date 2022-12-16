/* 19


    A B C G F D E

    4번이 답.

*/
#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열

bool visited[100001]; // 방문한 적이 있는지 체크하는 목적의 배열 만들기

int d[100001]; // 최단 거리 테이블 만들기

int getSmallestNode() // 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환.
{
    int min_value=INF;
    int index = 0; // 가장 최단 거리가 짧은 노드(인덱스)

    for(int i=1; i<=n; i++)
    {
        if(d[i] <min_value && !visited[i])
        {
            min_value = d[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int start)
{
    d[start]=0;
    visited[start]= true;

    for(int j=0; j<graph[start].size(); j++)
    {
        int adjindex = graph[start][j].first;
        d[adjindex] = graph[start][j].second; // 최단거리 테이블에 초기값 세팅
    }
    for(int i=0; i<n-1; i++)
    {
        int now = getSmallestNode();
        visited[now]=true;

        for(int j=0; j<graph[now].size(); j++)
        {
            int cost = d[now] + graph[now][j].second;
            if(cost<d[graph[now][j].first])
            {
                d[graph[now][j].first]=cost;
            }
        }
    }
}

int main()
{
    int map[7][7]={{0,4,9,999,999,999,999},{4,0,4,10,999,999,999},{9,4,0,999,8,999,1},{999,10,999,0,2,5,999},{999,999,8,2,0,999,6},{999,999,999,5,999,0,3},{999,999,1,999,6,3,0}};
    for(int i=0; i<7; ++i)
        for(int j=0; j<7; ++j)
        {
            graph[i].push_back({j,map[i][j]});
        }

    // 최단 거리 테이블을 모두 무한으로 초기화
    n=6;

    fill_n(d, 100001, INF);
    start = 0;
    dijkstra(start);
    for(int i=0; i<7; ++i)
        printf("%d ", d[i]);
    return 0;
}