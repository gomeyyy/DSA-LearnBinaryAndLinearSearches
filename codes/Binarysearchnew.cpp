/* Binary Search */
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearch(vector<int>& arr, int target, int& steps) {
    int left = 0, right = arr.size() - 1;
    steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  
        else if (arr[mid] < target)
            left = mid + 1; 
        else
            right = mid - 1; 
    }
    return -1;
}

int main() {
    vector<int> arr;
    int target, n, num;

    cout << "Insert the number of elements: ";
    cin >> n;
    cout << "Insert the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Enter the value to search: ";
    cin >> target;

    int steps;
    auto start = high_resolution_clock::now();
    int index = binarySearch(arr, target, steps);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n--- BINARY SEARCH ---\n";
    if (index != -1)
        cout << "Element found at index " << index << " in the sorted array." << endl;
    else
        cout << "Element not found." << endl;

    cout << "Steps taken: " << steps << endl;
    cout << "Time taken: " << duration.count() << " microseconds." << endl;

    cout << "\nSteps for Binary Search:\n";
    cout << "1) Firstly, make sure the array is sorted.\n";
    cout << "2) Divide the search space into two halves by finding the middle index, mid = (low + high) / 2.\n";
    cout << "3) Compare the mid element with the target.\n";
    cout << "4) If the mid equals the target, the search ends.\n";
    cout << "5) If the target is larger than mid, search the right half (low = mid + 1).\n";
    cout << "6) If the target is smaller than mid, search the left half (high = mid - 1).\n";
    cout << "7) Repeat until the target is found or the search space is empty.\n";

    return 0;
}
