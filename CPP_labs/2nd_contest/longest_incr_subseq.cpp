#include <iostream>
#include <algorithm>
#include <vector>

void print_array(std::vector<int> arr, int n ) {
    for (int i = 0 ;i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int max(std::vector<int> arr) {
    return *std::max_element(arr.begin(), arr.end());
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int LengthOfLIS(int* arr, int n) {
    std::vector<int> LIS (n, 1);
    for (int i = n - 1; i >= 0; i --) {
        for (int j = i; j < n; j ++){
            if (arr[i] < arr[j]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }
    // print_array(LIS, n);
    return max(LIS);
}

int main() {
    int n, num;
    std::cin >> n;
    int* nums = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        nums[i] = num;
    }

    std::cout << LengthOfLIS(nums, n) << std::endl;
    delete[] nums;
    return 0;
}