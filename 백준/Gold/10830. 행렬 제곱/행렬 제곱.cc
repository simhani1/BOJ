#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N, B;
long long A[5][5];
long long temp[5][5];
long long ans[5][5];


// 배열 출력
void print_arr(long long arr[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

// 행렬 곱셈
void Matrix_multi(long long X[5][5], long long Y[5][5])
{

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0; // 행렬 초기화
			for (int k = 0; k < N; k++)
				temp[i][j] += (X[i][k] * Y[k][j]);

			temp[i][j] %= 1000;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			X[i][j] = temp[i][j];
}

int main()
{
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
		ans[i][i] = 1; // 정답행렬은 단위행렬로
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			Matrix_multi(ans, A); // 정답행렬에 A행렬 곱하기
		}
		Matrix_multi(A, A);
		B /= 2;
	}

	print_arr(ans); // A를 B번 곱한 결과

}