#include <iostream> 
using namespace std;
int insertion_sort(int arr[], int size) {
	int count = 0, j, key;
	for (int i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			count++;
			arr[j + 1] = arr[j];
			j--;
		}
		if (j >= 0) count++;
		arr[j + 1] = key;
	}
	return count;
}
int main() {
	int arr[] = { 5, 3, 4 };
	cout << "Comparisons: "
		<< insertion_sort(arr, 3) << endl;
}