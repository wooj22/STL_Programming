// 다차원 vector

#include <iostream>
#include <vector>

using namespace std;

int main() {

	// vector 의 초기화 ------------------------------------------

	vector<int> vec = { -1,-1,-1 };							// int형 vector, -1, 3개로 초기화	

	vector<int> vec(3);										// 3개짜리 int형 vector, 0 초기화
	vector<int> vec(3, -1);									// 3개짜리 int형 vector, -1 로 초기화	

	vector<int> vec; vec.assign(3, -1);						// assign, 3개의 원소 할당

	vector<int> vec(3);	
	fill(vec.begin(), vec.end(), -1);						// fill 함수로 초기화

	int arr[3];	memset(arr, -1, sizeof(arr)); 
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));	// 배열로 초기화
	
	vector<int> vec1(vec);									// vector로 초기화
	

	// 다차원 vector ---------------------------------------------

	vector<vector<int>> vec(3, vector<int>(3, -1));		//3개, vector<int>(3, -1) 초기화

	vector<vector<int>> vec(3, vector<int>(3));			//3개, vector<int>(3) 로 초기화
	fill(vec.begin(), vec.end(), vector<int>(3, -1));	//fill 함수로 초기화


	//벡터의 2차원 배열

	vector<vector<int>> scores = { {1,2,3}, {4,5,6} };

	cout << scores[0][2] << endl;						//출력은?

	cout << scores.size() << endl;
	cout << scores[0].size() << endl;	

	vector<int> scores2 = scores[0];					//첫번째 벡터 배열
	for (size_t i = 0; i < scores2.size(); i++)
		cout << scores2[i] << " ";


	//2차원 벡터 출력하기 ***
	//vector<vector<int>> scores = { {1,2,3,4}, {4,5,6}, {1}, {1,2} };

	for (size_t i = 0; i < scores.size(); i++) {
		for (size_t j = 0; j < scores[i].size(); j++) {
			cout << scores[i][j] << " ";
		}
		cout << endl;
	}

}
