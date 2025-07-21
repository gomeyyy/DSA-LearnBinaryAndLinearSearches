/* Linear search with timing */
#include <iostream>
#include <vector>
#include <chrono> 
using namespace std;
using namespace std::chrono;

int search(vector<int>& arr, int target) {
	int i = 0;
	for (int val : arr) {
		if (val == target)
			return i;
		i++;
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

	cout << "\nEnter the value to search: ";
	cin >> target;

	// Start timing
	auto start = high_resolution_clock::now();

	int index = search(arr, target);

	// Stop timing
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	if (index != -1) {
		cout << "Element found at index " << index << "." << endl;
	}
	else {
		cout << "Element not found in the array." << endl;
	}

	cout << "Time taken for search: " << duration.count() << " microseconds." << endl;

	return 0;
}

