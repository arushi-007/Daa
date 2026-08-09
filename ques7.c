#include <stdio.h>
// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    // Handle cases where k is greater than the array size
    k = k % n;
    if (k != 0) {
        // Reverse the entire array
        reverse(arr, 0, n - 1);
        // Reverse the first k elements
        reverse(arr, 0, k - 1);
        //  Reverse the remaining n - k elements
        reverse(arr, k, n - 1);
    }

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}