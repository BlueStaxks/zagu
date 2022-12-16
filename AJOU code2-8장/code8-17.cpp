/* 17


    ó�� ���ö� 0,2,4������ �ִܰŸ��� �����ȴ�.

    3���� ��.

*/
#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

// ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
// ����� ������ �ִ� 100,000����� ����
int n, m, start;

vector<pair<int, int> > graph[100001]; // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭

bool visited[100001]; // �湮�� ���� �ִ��� üũ�ϴ� ������ �迭 �����

int d[100001]; // �ִ� �Ÿ� ���̺� �����

int getSmallestNode() // �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ.
{
    int min_value = INF;
    int index = 0; // ���� �ִ� �Ÿ��� ª�� ���(�ε���)

    for (int i = 1; i <= n; i++)
    {
        if (d[i] < min_value && !visited[i])
        {
            min_value = d[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int start)
{
    d[start] = 0;
    visited[start] = true;

    for (int j = 0; j < graph[start].size(); j++)
    {
        int adjindex = graph[start][j].first;
        d[adjindex] = graph[start][j].second; // �ִܰŸ� ���̺� �ʱⰪ ����
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", d[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int now = getSmallestNode();
        visited[now] = true;

        for (int j = 0; j < graph[now].size(); j++)
        {
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first])
            {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main()
{
    graph[1].push_back({ 5, 30 });
    graph[0].push_back({ 1, 10 });
    graph[0].push_back({ 2, 3 });
    graph[2].push_back({ 3, 15 });
    graph[3].push_back({ 4, 6 });
    graph[4].push_back({ 5, 3 });
    graph[0].push_back({ 4, 20 });
    graph[2].push_back({ 1, 6 });
    graph[3].push_back({ 1, 15 });

    // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
    fill_n(d, 100001, INF);
    start = 0;
    n = 6;
    dijkstra(start);

    // ��� ���� ���� ���� �ִ� �Ÿ��� ���
    printf("\n-------------------------\n\n");
    for (int i = 0; i < n; i++)
    {
        // ������ �� ���� ���, ����(INFINITY)�̶�� ���
        if (d[i] == INF)
        {
            cout << "INFINITY" << '\n';
        }
        // ������ �� �ִ� ��� �Ÿ��� ���
        else
        {
            cout << d[i] << '\n';
        }
    }
    return 0;
}