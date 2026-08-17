#include <stdio.h>
struct Book {
    int id;
    char title[20];
    int total;
    int available;
};

int main() {
    struct Book b[10];
    int count = 0, choice;

    do {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. Show Unavailable Books\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter ID, Title, Total Copies: ");
            scanf("%d %s %d", &b[count].id, b[count].title, &b[count].total);
            b[count].available = b[count].total;
            count++;
            printf("Book added!\n");
        } 
        else if (choice == 2) {
            int id, found = 0;
            printf("Enter ID to search: ");
            scanf("%d", &id);
            for (int i = 0; i < count; i++) {
                if (b[i].id == id) {
                    printf("Found: %s (Available: %d/%d)\n", b[i].title, b[i].available, b[i].total);
                    found = 1;
                }
            }
            if (!found) printf("Not found.\n");
        } 
        else if (choice == 3) {
            int id, found = 0;
            printf("Enter ID to issue: ");
            scanf("%d", &id);
            for (int i = 0; i < count; i++) {
                if (b[i].id == id) {
                    found = 1;
                    if (b[i].available > 0) {
                        b[i].available--;
                        printf("Book issued successfully!\n");
                    } else {
                        printf("No copies left!\n");
                    }
                }
            }
            if (!found) printf("Not found.\n");
        } 
        else if (choice == 4) {
            int id, found = 0;
            printf("Enter ID to return: ");
            scanf("%d", &id);
            for (int i = 0; i < count; i++) {
                if (b[i].id == id) {
                    found = 1;
                    if (b[i].available < b[i].total) {
                        b[i].available++;
                        printf("Book returned successfully!\n");
                    } else {
                        printf("All copies are already back!\n");
                    }
                }
            }
            if (!found) printf("Not found.\n");
        } 
        else if (choice == 5) {
            printf("\n--- Unavailable Books ---\n");
            int none = 1;
            for (int i = 0; i < count; i++) {
                if (b[i].available == 0) {
                    printf("ID: %d, Title: %s\n", b[i].id, b[i].title);
                    none = 0;
                }
            }
            if (none) printf("All books have available copies.\n");
        }
    } while (choice != 6);

    return 0;
}