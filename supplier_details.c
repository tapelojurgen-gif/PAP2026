
#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];

    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';   /* remove newline */

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    /* Task 2: lengths */
    printf("\nSupplier name length: %zu\n", strlen(supplierName));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    return 0;
}
