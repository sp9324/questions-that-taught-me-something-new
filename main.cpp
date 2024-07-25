#include <iostream>
#include <vector>
using namespace std;

void shift(vector<int>& array, int start, int end) {
    for (int i = end + 1; i > start; --i) {
        array[i] = array[i - 1];
    }
}

void naiveMergeSort(vector<int>& array, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    naiveMergeSort(array, start, mid);
    naiveMergeSort(array, mid + 1, end);

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (array[left] < array[right]) {
            left++;
        } else {
            int temp = array[right];
            shift(array, left, mid);
            array[left] = temp;
            left++;
            mid++;
            right++;
        }
    }
}

int main() {
    vector<int> v = {5, 1, 1, 2, 0, 0};
    naiveMergeSort(v, 0, v.size() - 1);
    for (int num : v) {
        cout << num << " ";
    }
    return 0;
}