#include <iostream> 
using namespace std;
int bubble_sort_count(int arr[], int size) {
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return count;
}
int main() {
	int arr[] = { 5, 3, 8, 4, 2 };
	int n = 5;
	cout << "Number of comparisons: "
		<< bubble_sort_count(arr, n) << endl;
}