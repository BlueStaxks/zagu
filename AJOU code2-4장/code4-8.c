#include <stdio.h>
int main()
{
	int a[10] = {0};
	int i;
	for (i = 0; i < 9; ++i)
		a[i] = i + 1; //a[0]=1이 되면서 0번 다음에 1번이 온다는 것을 나타냄

	int p = 0, q = NULL, r;
	for (i = 0; i < 10; ++i)
	{
		//2번을 배열로 간단히 구현한 것. 이렇게 하면 역순으로 바뀜.
		//r<q<p 순으로 되어 있다고 보면 됨.
		r = q;
		q = p;
		p = a[p];
		a[q] = r;
	}
	p = q;

	int c = 10;
	while (c--)
	{
		printf("%d ", a[p]);
		p = a[p];
	}
	return 0;

	//2번이 답.
}
/*

	1->2->3->4가 있다고 해보자.

	1을 보니 2로 가는 것이 보인다.
	1에서는 2로 가니까 2를 일단 저장해두고(p=a[p])
	2에서 1로 가게 바꾼다.(a[q]=r)

	그리고 나면 p는 2고 2는 3으로 가는 것이 보인다.
	2에선 3으로 가니까 3을 일단 저장해두고(p=a[p])...... 이런 방식으로 하는거다.

*/