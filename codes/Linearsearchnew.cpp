/* Linear Search*/
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearch(vector<int>& arr, int target, int& steps) {
    steps = 0;
    for (int i = 0; i < arr.size(); i++) {
        steps++;
        if (arr[i] == target)
            return i;
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

    cout << "Enter the value to search: ";
    cin >> target;

    int steps;
    auto start = high_resolution_clock::now();
    int index = linearSearch(arr, target, steps);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n--- LINEAR SEARCH ---\n";
    if (index != -1)
        cout << "Element found at index " << index << "." << endl;
    else
        cout << "Element not found." << endl;

    cout << "Steps taken: " << steps << endl;
    cout << "Time taken: " << duration.count() << " microseconds." << endl;

    cout << "\nSteps for Linear Search:\n";
    cout << "1) Start from the first element of the array or list.\n";
    cout << "2) Compare the current element with the target value.\n";
    cout << "3) If the current element matches the target, the search is successful and stops.\n";
    cout << "4) If the current element does not match, move to the next element.\n";
    cout << "5) Continue the process until the target element is found or the end of the array is reached.\n";
    cout << "6) If the target is not found by the time the loop ends, the search is unsuccessful.\n";

    return 0;
}
