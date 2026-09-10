#include <iostream>
using namespace std;

// To print the output
void printOutput(vector<int> arr) {
    for (auto x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

// Reverse the given array with SC - O(1)
void reverseArray(vector<int> arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
        swap(arr[i], arr[arr.size() - i - 1]);
    }    
    printOutput(arr);
}    

// Reverse a part of the Array with SC = O(1)
void reversePartOfArray(vector<int> arr, int start, int end) {
    while (start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printOutput(arr);
}

// Rotate the array by k times (forward rotation) with SC = O(1)
void rotateArray(vector<int> arr, int k) {
    int start = 0, end = k - 1;
    // Rotate 0 to k
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    // Rotate k to arr.size()
    start = k;
    end = arr.size() - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    // Rotate entire array
    start = 0;
    end = arr.size() - 1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printOutput(arr);
}

// Sum of elements in the range L to R (Brute Force)
void sumOfElementsInRange(vector<int> arr) {
    vector<int> L = {0, 3, 0};
    vector<int> R = {3, 4, 4};
    cout << "Sum of Elements in the range from L to R:\n";
    for (int i = 0; i < L.size(); i++) {
        int sum = 0;
        for (int j = L[i]; j <= R[i]; j++) {
            sum += arr[j];
        }
        cout << "From " << L[i] << " to " << R[i] << " the sum is: " << sum << '\n';
    }
    
}

// Using Prefix Sum to find the sum of elements in the range L to R (Optimized)
void sumOfElemetsInRangeOptimzed(vector<int> arr) {
    vector<int> L = {0, 3, 0};
    vector<int> R = {3, 4, 4};
    for (int i = 1; i < arr.size(); i++){
        arr[i] += arr[i - 1];
    }
    cout << "Optimized Sum of Elements in the range from L to R:\n";
    for (int i = 0; i < L.size(); i++) {
        cout << "From " << L[i] << " to " << R[i] << " the sum is: " << arr[R[i]] - arr[L[i] - 1] << '\n';    
    }
}

// Equilibrium index of an array
void equilibriumIndex() {
    vector<int> arr = {5, 1, 3, -6, 5, -2, -1};
    for (int i = 1; i < arr.size(); i++) {
        arr[i] = arr[i - 1] + arr[i];
    }
    cout << "Equilibrium Indexes:\n";
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 && arr[arr.size() - 1] - arr[i] == 0) {
            cout << i << ' ';
        } else {
            if (arr[i - 1] == arr[arr.size() - 1] - arr[i]) {
                cout << i << ' ';
            }
        }
    }   
    cout << '\n';
}

void sumofAllSubarraySum (vector<int> arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i] * (i + 1) + (arr.size() - i);
    }
    cout << "Sum of all subarray sums: " << sum << '\n';
}

int main () {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Reverse the entire array\n";
    reverseArray(arr);
    cout << "Reverse the part of the array from 1 to 3:\n";
    reversePartOfArray(arr, 1, 3);
    cout << "Rotate the array by k times (forward rotation):\n";
    rotateArray(arr, 3);
    sumOfElementsInRange(arr);
    sumOfElemetsInRangeOptimzed(arr);
    equilibriumIndex();
    sumofAllSubarraySum(arr);
}
