/*

	단순 연결 리스트는 앞으로만 향한다.
	예를 들면 1다음은 2, 2다음은 3 이런식이다.
	1다음에 2인 것은 알지만 2전에 1이 나오는건 모른다.
	2전이 알고싶으면 처음부터 돌면서 다음이 2인 경우를 찾아야 한다.

	원형 연결 리스트는 마지막 노드 다음을 첫 노드로 하는 연결 리스트다.

	이중 연결 리스트는 단순 연결 리스트를 2개 한 것과 비슷하다.
	단순 연결 리스트에선 2전이 1인것을 바로 알 수 없었지만 이중 연결 리스트는 2전이 1인 것을 바로 알 수 있다.
	1다음에 2인 것을 저장할 때 2전이 1인 것도 저장하기 때문이다.

*/