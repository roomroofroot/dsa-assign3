#include <iostream>
#include <vector>

using namespace std;

void tree(vector<int>& arr, int lvl, int x, int y) {
	for (int i = 0; i < lvl; i++) cout << " ";
	cout << "Level " << lvl << ": ";
	cout << '[' << arr[x];
	for (int i = x+1; i <= y; i++)
		cout << ", " << arr[i];
	cout << ']' << endl;

	if (y-x < 1) return;
	tree(arr, lvl+1, x, (x+y-1+(x+y)%2)/2);
	tree(arr, lvl+1, (x+y+(x+y)%2)/2, y);
}

void merge_sort_tree(vector<int>& arr) {
	tree(arr, 0, 0, arr.size()-1);
}

int main() {
	vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
	merge_sort_tree(arr);
}

// Questions
// a) There will be 2n-1 nodes
// b) Height is approximately lg n or exactly ceil(lg n)
// c) Using the recursion tree, we can visualise the array input for each sub recursive process, and the height times number of elements will give the worst case time complexity (n * lg n)
