#include <stdio.h>
#include <string.h>

int main() {
    float balance = 1000.00;
    int choice;
    char history[5][30]; // Store up to 5 transaction strings
    int count = 0;       // Number of stored transactions

    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Last 5 Transactions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Current Balance: $%.2f\n", balance);
        } 
        else if (choice == 2) {
            float amt;
            printf("Enter amount to deposit: $");
            scanf("%f", &amt);

            if (amt > 0) {
                balance += amt;
                printf("Successfully deposited $%.2f\n", amt);

                // Add to history (Shift if full)
                if (count < 5) {
                    sprintf(history[count], "Deposit: +$%.2f", amt);
                    count++;
                } else {
                    for (int i = 0; i < 4; i++) {
                        strcpy(history[i], history[i + 1]);
                    }
                    sprintf(history[4], "Deposit: +$%.2f", amt);
                }
            } else {
                printf("Invalid amount!\n");
            }
        } 
        else if (choice == 3) {
            float amt;
            printf("Enter amount to withdraw: $");
            scanf("%f", &amt);

            if (amt > balance) {
                printf("Transaction Failed: Insufficient balance!\n");
            } else if (amt > 0) {
                balance -= amt;
                printf("Successfully withdrew $%.2f\n", amt);

                // Add to history (Shift if full)
                if (count < 5) {
                    sprintf(history[count], "Withdraw: -$%.2f", amt);
                    count++;
                } else {
                    for (int i = 0; i < 4; i++) {
                        strcpy(history[i], history[i + 1]);
                    }
                    sprintf(history[4], "Withdraw: -$%.2f", amt);
                }
            } else {
                printf("Invalid amount!\n");
            }
        } 
        else if (choice == 4) {
            printf("\n--- Last Transactions ---\n");
            if (count == 0) {
                printf("No transactions yet.\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("%d. %s\n", i + 1, history[i]);
                }
            }
        }
    } while (choice != 5);

    printf("Thank you for using the ATM!\n");
    return 0;
}