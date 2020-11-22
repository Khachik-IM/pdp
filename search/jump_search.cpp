// Jump Search 
#include <iostream>
#include <cmath>
using namespace std; 
  
int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0; 
    while (arr[min(step, n)-1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
	}
    } 
  
    while (arr[prev] < x) {
        prev++;

        if (prev == min(step, n)) {
            return -1;
	}
    } 
    if (arr[prev] == x) {
        return prev;
    }
  
    return -1; 
} 
  
int main() {
    int arr[] = { 0, 0, 2, 2, 4, 7, 11, 19, 21, 34, 45, 77 }; 
    int x = 45; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    int index = jumpSearch(arr, x, n); 
  
    cout << "\nFound " << x << " at index " << index << endl; 
    return 0; 
} 
