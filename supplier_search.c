
#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";
    char searchName[100];

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';   /* otherwise strcmp fails */

    if (strcmp(supplier1, searchName) == 0 || strcmp(supplier2, searchName) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    return 0;
}
