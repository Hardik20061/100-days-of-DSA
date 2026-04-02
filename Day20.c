#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Simple frequency array (adjust size if needed)
    int freq[20001] = {0};  // to handle negative sums
    int offset = 10000;

    freq[offset] = 1; // for prefix_sum = 0

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // If this sum appeared before
        if (freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    printf("%d", count);

    return 0;
}