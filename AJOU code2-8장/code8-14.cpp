/* 14

 C F E B H D G B G H E G ������ �湮�Ѵ�.
    1. �´�.
    2. �´�.
    3. �´�.
    4. 20�̴�.

    4���� ��.

*/
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
bool visited[10001];
int v, e, c, k;

void prim(int v);

int main() {
    scanf("%d %d", &v, &e);
    getchar();
    edge.resize(e);
    char x, y;
    int z;
    for (int i = 0; i < e; i++) {
        scanf("%c %c %d", &x, &y, &z);
        edge[x - 'A'].push_back({ z, y - 'A' });
        edge[y - 'A'].push_back({ z, x - 'A' });
        getchar();
    }
    printf("\n\n");
    prim(0);// 1�� �������� Ʈ���� ����� ����
    printf("%d\n", k);
    return 0;
}

void prim(int v) {
    visited[v] = true;

    for (auto u : edge[v]) {
        if (!visited[u.second]) {
            pq.push({ u.first, u.second });
        }
    }// ���� v�� ����� ������ ť�� ��´�

    while (!pq.empty()) {
        auto w = pq.top();
        printf("%c ", w.second + 'A');
        pq.pop();
        if (!visited[w.second]) {
            k += w.first;
            prim(w.second);
            return;
        }// ������ Ʈ���� ������� �ʾ����� �����Ѵ�
    }// ����ġ�� ���� ������ ���ʴ�� Ž���ϸ鼭
}