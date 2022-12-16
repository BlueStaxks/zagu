/* 16


 4���� ��.


 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �θ� ��带 ������
int getParent(int set[], int x) {
    if (set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

// �θ� ��带 ����
void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    // �� ���ڰ� ���� �θ�� ����
    if (a < b) set[b] = a;
    else set[a] = b;
}

// ���� �θ� �������� Ȯ��
int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if (a == b) return 1;
    else return 0;
}

// ���� Ŭ���� ����
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    //bool operator <(Edge &edge) {
      //  return this->distance < edge.distance;
    //}
};
bool cmp(Edge a, Edge b)
{
    return a.distance < b.distance;
}
int main(void) {
    int n = 7;
    int m = 11;

    vector<Edge> v;
    v.push_back(Edge(1, 2, 4));
    v.push_back(Edge(1, 4, 9));
    v.push_back(Edge(2, 3, 13));
    v.push_back(Edge(3, 4, 11));
    v.push_back(Edge(2, 5, 7));
    v.push_back(Edge(3, 6, 9));
    v.push_back(Edge(4, 7, 3));
    v.push_back(Edge(3, 5, 8));
    v.push_back(Edge(5, 6, 4));
    v.push_back(Edge(6, 7, 14));
    v.push_back(Edge(3, 7, 10));


    // ������ ������� �������� ����
    sort(v.begin(), v.end(), cmp);

    // �� ������ ���Ե� �׷����� ������� ����
    int set[10];
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }

    // �Ÿ��� ���� 0���� �ʱ�ȭ
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        // ������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ�� �߻����� ���� ���� ����
        if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            printf("%d %d\n", v[i].node[0], v[i].node[1]);
            unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }

    printf("%d\n", sum);
}