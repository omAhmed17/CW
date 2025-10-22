#include <iostream> 
using namespace std;
int selection_sort(int arr[], int size) {
	int count = 0, min_index;
	for (int i = 0; i < size - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < size; j++) {
			count++;
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);
	}
	return count;
}
int main() {
	int arr[] = { 1, 2, 0 };
	cout << "Comparisons: "
		<< selection_sort(arr, 3) << endl;
}