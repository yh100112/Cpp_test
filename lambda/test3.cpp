#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

bool compare (int a, int b)
{
	return a > b;
}

int main() {
	std::array<int, 10> arr1 = { 5, 4, 2, 1, 100, 32, 2,4,6,9};
	std::array<int, 10> arr2 = { 5, 4, 2, 1, 100, 32, 2,4,6,9};
	std::array<int, 10> arr3 = { 5, 4, 2, 1, 100, 32, 2,4,6,9};

	// sort함수
	sort(arr1.begin(), arr1.end());
	for (int val : arr1) {
		cout << val << " ";
	}

	cout << endl << endl;

	// sort함수와 일반함수 이용 ( 큰 수부터 )
	sort(arr2.begin(), arr2.end(), compare);
	for (int val : arr2) {
    cout << val << " ";
	}

	cout << endl << endl;

	// sort함수와 람다 함수 이용 ( 큰 수부터 )
	sort(arr3.begin(), arr3.end(), [](int a, int b) {return a > b;});
	for (int val : arr3) {
    cout << val << " ";
	}
}
