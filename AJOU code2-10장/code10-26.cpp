#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
void f1(string a)
{
	int s = 0, i;
	for (i = 0; i < a.length(); ++i)	s += (int)a[i];
	s *= s; //s는 18개의 비트를 씀
	s = s >> 8; //8개는 내맘임.
	s = s % (1 << 8); //버킷이 256개이므로 비트 8개로 위치를 나타내야함.
	cout << a << " : " << s << '\n';
}
void f2(string a)
{
	int s = 0, i;
	for (i = 0; i < a.length(); ++i)	s += (int)a[i];
	s = s % (1 << 8); //버킷이 256개이므로 비트 8개로 위치를 나타내야함.
	cout << a << " : " << s << '\n';
}
void f3(string a)
{
	int s = 0, i;
	for (i = 0; i < a.length(); ++i)	s += (int)a[i];
	double k = (double)s;
	k *= 0.001;
	k = k - (double)(int)k;
	k *= 256.0;
	cout << a << " : " << (int)k;
	k = (double)s;
	k *= 0.618;
	k = k - (double)(int)k;
	k *= 256.0;
	cout << " or " << (int)k << '\n';
}
void main()
{
	vector<string> v = { "tree","heap","deap","list" };
	int i;
	for (i = 0; i < v.size(); ++i)	f1(v[i]);
	printf("\n-------------------------------\n\n");
	for (i = 0; i < v.size(); ++i)	f2(v[i]);
	printf("\n-------------------------------\n\n");
	for (i = 0; i < v.size(); ++i)	f3(v[i]);

	//출력 해보면 됨
}