/*

	next[0]=1; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=2; prev[2]=1; prev[1]=0; prev[0]=NULL;

	�̷��� ���� ���� ����Ʈ�� �ִ� �ĺ���.

	1�� p, 2�� q��� �ϸ�

	next[prev[p]]=q; == ��
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=2; prev[2]=1; prev[1]=0; prev[0]=NULL;

	prev[next[q]]=p; == ��
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=1; prev[1]=0; prev[0]=NULL;

	prev[q]=prev[p]; == ��
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=0; prev[0]=NULL;

	next[p]=next[q]; == ��
	||
	next[0]=2; next[1]=3; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=0; prev[0]=NULL;

	prev[p]=q; == ��
	||
	next[0]=2; next[1]=3; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=2; prev[0]=NULL;

	next[q]=p; == ��
	||
	next[0]=2; next[1]=3; next[2]=1; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=2; prev[0]=NULL;

	2���� ������� �ϴ� ���� ���� ����� �� �ϳ��� ��, ������ ������ �ƴϴ�.

	�ٸ� ���� ���� ���� �� ������ ���� prev[p]�� ������ ����ϴ� ���� �߸��Ǿ��� Ȯ���� �����Ƿ�
	���� ���տ� ���� 1,3,4���� �����ϰ� 2�� ���� �����ϴ� ���� ������ ���� Ǫ�� ����� ���̴�.

	2���� ��.

*/