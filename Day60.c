#include <iostream>
using namespace std;

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left])
            return false;

        // Check right child
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isMinHeap(arr, n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}