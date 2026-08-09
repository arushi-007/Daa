#include <stdio.h>

struct Student {
    int roll;
    char name[20];
    int marks[5];
    int total;
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n); 
    struct Student s[n];
    float totalClassPercentage = 0;
    int topperIndex = 0;
    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;
        printf("Enter marks for 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;
        totalClassPercentage += s[i].percentage;

        // Track topper
        if (s[i].total > s[topperIndex].total) {
            topperIndex = i;
        }
    }

    // Display Individual Results
    printf("\n\n--- Individual Results ---\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Total: %d/500 | Percentage: %.2f%%\n", 
            s[i].roll, s[i].name, s[i].total, s[i].percentage);
    }

    // Display Class Analysis
    printf("\n\n--- Class Analysis ---\n");
    
    //. Class Topper
    printf("Topper: %s (Roll: %d) with Total: %d\n", 
        s[topperIndex].name, s[topperIndex].roll, s[topperIndex].total);
    printf("Students who failed (less than 40 in any subject):\n");
    int failedCount = 0;
    for (int i = 0; i < n; i++) {
        int hasFailed = 0;
        for (int j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                hasFailed = 1;
                break;
            }
        }
        if (hasFailed) {
            printf(" - %s (Roll: %d)\n", s[i].name, s[i].roll);
            failedCount++;
        }
    }
    if (failedCount == 0) {
        printf(" - None (Everyone passed!)\n");
    }
    printf("Class Average Percentage: %.2f%%\n", totalClassPercentage / n);

    return 0;
}