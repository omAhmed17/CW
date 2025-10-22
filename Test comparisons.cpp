#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

void test_comparisons() {
    srand(time(0));
    ofstream fileComparisons("comparisons.csv");
    ofstream fileTimes("times.csv");

    fileComparisons << "Size,Type,Bubble,Selection,Insertion\n";
    fileTimes << "Size,Type,Bubble,Selection,Insertion\n";

    for (int size = 1; size <= 30; size++) {
        vector<string> types = { "Random", "Sorted", "Reverse" };
        for (string type : types) {
            long long bubbleCmp = 0, selectCmp = 0, insertCmp = 0;
            double bubbleTime = 0, selectTime = 0, insertTime = 0;

            for (int test = 0; test < 30; test++) {
                vector<int> arr(size);
                for (int i = 0; i < size; i++) arr[i] = rand() % 100;

                if (type == "Sorted") sort(arr.begin(), arr.end());
                if (type == "Reverse") sort(arr.begin(), arr.end(), greater<int>());

                vector<int> tmp = arr;
                auto s = high_resolution_clock::now();
                bubbleCmp += bubble_sort_count(tmp.data(), size);
                auto e = high_resolution_clock::now();
                bubbleTime += duration<double>(e - s).count();

                tmp = arr;
                s = high_resolution_clock::now();
                selectCmp += selection_sort(tmp.data(), size);
                e = high_resolution_clock::now();
                selectTime += duration<double>(e - s).count();

                tmp = arr;
                s = high_resolution_clock::now();
                insertCmp += insertion_sort(tmp.data(), size);
                e = high_resolution_clock::now();
                insertTime += duration<double>(e - s).count();
            }

            fileComparisons << size << "," << type << ","
                << bubbleCmp / 30 << ","
                << selectCmp / 30 << ","
                << insertCmp / 30 << "\n";

            fileTimes << size << "," << type << ","
                << bubbleTime / 30.0 << ","
                << selectTime / 30.0 << ","
                << insertTime / 30.0 << "\n";
        }
    }
    cout << "Results saved to CSV files.\n";
}

int main() {
    test_comparisons();
    return 0;
}
