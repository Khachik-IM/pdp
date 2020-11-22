// recursive Binary Search 
#include <iostream> 
using namespace std; 
  
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) {
            return mid;
	}

        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
	}
  
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1; 
} 
  
int main(void) {
    int arr[] = { 7, 11, 24, 50, 0 , 9, 35}; 
    int x = 50; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? cout << "Not found" << endl : cout << "Found at index " << result << endl; 
    return 0; 
} 
