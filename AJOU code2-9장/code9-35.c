/*

	선택 정렬은 가장 작은 원소를 첫 번째에, 두번 째로 작은 원소를 둘 째 배열에 넣는 방식이다.
	이를 위해 2중 for문을 사용하여 시간 복잡도가 nn이다.

	반면 셸 정렬은 버블 정렬과 비슷한데 매개변수 h를 사용한다.
	h만큼 떨어진 원소들 끼리 버블 정렬을 한다고 생각하면 된다.
	h는 처음에 배열 길이의 반으로 했다가 계속 반으로 줄여 나간다.
	이렇게 되면 nn이 아니라 n^1.25정도에 작업을 마칠 수 있다.

*/