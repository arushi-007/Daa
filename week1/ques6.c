#include <stdio.h>
int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int visited[6] = {0}; // Array to keep track of used elements
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget: %d\n", target);
    printf("Output: ");
    int firstPair = 1;
    for (int i = 0; i < n; i++) {
        // If this element is already part of a pair, skip it
        if (visited[i]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            // If the other element is not visited and their sum equals the target
            if (!visited[j] && (arr[i] + arr[j] == target)) {
                if (!firstPair) {
                    printf(", ");
                }
                printf("(%d, %d)", arr[i], arr[j]);
                
                // Mark both elements as visited so they aren't reused
                visited[i] = 1;
                visited[j] = 1;
                firstPair = 0;
                break; // Move to the next outer element
            }
        }
    }
    printf("\n");
    return 0;
}