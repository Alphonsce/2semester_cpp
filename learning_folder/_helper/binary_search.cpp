#include <iostream>

// it works only for a sorted array, and it us useless to implement for bubble sorted array: O(N^2 + NlogN)=O(N^2)

// key is a number to search
bool bool_binary_search(int* data, unsigned size, int key) {
    unsigned l_idx = 0, r_idx = size;

    while (l_idx < r_idx) {
        auto pivot_idx = (l_idx + r_idx) / 2;
        if (key < data[pivot_idx])
            r_idx = pivot_idx;
        else if (key > data[pivot_idx])
            l_idx = pivot_idx + 1;
        else 
            return true;
    }

    return false;
}

// recursive way
int idx_binary_search(int* data, unsigned left, unsigned right, int key) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] == key)
            return mid;
        
        else if (data[mid] < key)
            idx_binary_search(data, mid + 1, right, key);   // + 1, because it is already > data[mid]

        else if (data[mid] > key)
            idx_binary_search(data, left, right - 1, key);   // - 1, because it is already < data[mid]
    }
    return -1;
}

int main()
{   

    return 0;
}