#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == -1) {
        printf("No second largest distinct element found.\n");
    } 
    else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}