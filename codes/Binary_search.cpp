/* Binary search with timing */
#include <iostream>
#include <vector>
#include <algorithm>  
#include <chrono>   
using namespace std;
using namespace std::chrono;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;      // Found target
        else if (arr[mid] < target)
            left = mid + 1;  // Search right half
        else
            right = mid - 1; // Search left half
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

    // Sort the array for binary search
    sort(arr.begin(), arr.end());
    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Enter the value to search: ";
    cin >> target;

    // Start timing
    auto start = high_resolution_clock::now();

    int index = binarySearch(arr, target);

    // Stop timing
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Output result
    if (index != -1) {
        cout << "Element found at index " << index << " (in sorted array)." << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    cout << "Time taken for binary search: " << duration.count() << " microseconds." << endl;

    return 0;
}
