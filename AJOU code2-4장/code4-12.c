/*

	next[0]=1; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=2; prev[2]=1; prev[1]=0; prev[0]=NULL;

	이렇게 이중 연결 리스트가 있다 쳐보자.

	1이 p, 2가 q라고 하면

	next[prev[p]]=q; == ㄱ
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=2; prev[2]=1; prev[1]=0; prev[0]=NULL;

	prev[next[q]]=p; == ㄴ
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=1; prev[1]=0; prev[0]=NULL;

	prev[q]=prev[p]; == ㅁ
	||
	next[0]=2; next[1]=2; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=0; prev[0]=NULL;

	next[p]=next[q]; == ㅂ
	||
	next[0]=2; next[1]=3; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=0; prev[0]=NULL;

	prev[p]=q; == ㄷ
	||
	next[0]=2; next[1]=3; next[2]=3; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=2; prev[0]=NULL;

	next[q]=p; == ㄹ
	||
	next[0]=2; next[1]=3; next[2]=1; next[3]=NULL;
	prev[3]=1; prev[2]=0; prev[1]=2; prev[0]=NULL;

	2번의 순서대로 하는 것은 여러 방법들 중 하나일 뿐, 유일한 정답은 아니다.

	다만 ㄷ과 ㅁ을 봤을 때 ㄷ에서 변한 prev[p]를 ㅁ에서 사용하는 것은 잘못되었을 확률이 높으므로
	ㄷ이 ㅁ앞에 오는 1,3,4번을 제외하고 2번 먼저 검토하는 것이 적절한 문제 푸는 방법일 것이다.

	2번이 답.

*/