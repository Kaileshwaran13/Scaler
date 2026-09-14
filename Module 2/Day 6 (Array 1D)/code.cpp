#include<iostream>
using namespace std;

void prefixSumOperations () {
    cout << "Prefix Sum Operations:\n";
    vector<vector<int>> operations = {
        {1, 3},
        {4, 2},
        {3, -1}
    };
    vector<int> arr = {0, 0, 0, 0, 0, 0};
    for(int i = 0; i < operations.size(); i++) {
        arr[operations[i][0]] += operations[i][1];
    }
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
    }
    for(auto x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

void prefixSumOperationsRange() {
    cout << "Prefix Sum Operations with Range:\n";
    vector<vector<int>> operations = {
        {1, 3, 2}, 
        {2, 5, 1},
        {5, 6, -1}
    };
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < operations.size(); i++) {
        arr[operations[i][0]] += operations[i][2];
        arr[operations[i][1] + 1] -= operations[i][2];
    }
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
    }
    for (auto x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

void maxPrefixSubarraySumFromIndexZero() {
    cout << "Max Prefix Subarray Sum from Index Zero:\n";
    vector<int> arr = {-1, -5, -1, -3};
    int maxSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
        maxSum = max(maxSum, arr[i]);
    }
    cout << maxSum << '\n';
}

void maxSubarraySumBruteForce() {
    vector<int> arr = {10, -5, 7, 8, -1, 2};
    int maxSum = INT_MIN, sum;
    for (int i = 0; i < arr.size(); i++) {
        sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
    }
    cout << "Max Subarray Sum: " << maxSum << '\n';
}

void maxSubarraySumOptimized() {
    vector<int> arr = {10, -5, 7, 8, -11, 2, -20, 10, -3, -8, 15, 12};
    int maxSum = INT_MIN, sum = 0;
    int start = 0, end = arr.size();
    while (start < end) {
        if (sum > 0) {
            sum += arr[start];
        } else {
            sum = arr[start];
        }
        maxSum = max(sum, maxSum);
        start++;
    }
    cout << "Max Subarray Sum using Kandane\'s Algo: " << maxSum << '\n';
}

void maxValuePair(){
    vector<int> arr = {1, 3, -2};
    int maxVal = 0, minVal = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        } else {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
    }
    cout << "Max Value Pair:" << maxVal - minVal << '\n';
}

void maxValuePairFromFunction() {
    vector<int> arr = {1, 3, -2};
    int xMax = arr[0], xMin = arr[0], yMax = arr[0], yMin = arr[0];
    int xi = 0, yi = 0;
    for (int i = 0; i < arr.size(); i++) {
        xi = arr[i] + i;
        xMax = max(xMax, xi);
        xMin = min(xMin, xi);
        yi = arr[i] - i;
        yMax = max(yMax, yi);
        yMin = min(yMin, yi);
    }
    cout << "Max Value Pair from Function: " << max(xMax - xMin, yMax - yMin) << '\n';
}


int main() {
    prefixSumOperations();
    prefixSumOperationsRange();
    maxPrefixSubarraySumFromIndexZero();
    maxSubarraySumBruteForce();
    maxSubarraySumOptimized();
    maxValuePair();
    maxValuePairFromFunction(); 
}
