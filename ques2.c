#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array is empty.\n");
        return 0;
    }
    int arr[n];
    int visited[n]; // Array to keep track of counted elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited array to 0 (false)
    }
    printf("\nFrequency of each distinct element:\n");
    for (int i = 0; i < n; i++) {
        // If the element is already visited, skip it
        if (visited[i] == 1) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark duplicate element as visited
            }
    }
        printf("%d occurs %d time(s)\n", arr[i], count);
    }
    return 0;
}