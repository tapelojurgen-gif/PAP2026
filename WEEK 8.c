
#include <stdio.h>

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void  displayMenu(void);
int   searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);

    do
    {
        displayMenu();
        if (scanf("%d", &choice) != 1) break;

        switch (choice)
        {
        case 1:
        {
            float amount;
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("VAT: %.2f\n", calculateVAT(amount));
            break;
        }
        case 2:
        {
            float basic, housing, transport;
            printf("Basic salary: ");        scanf("%f", &basic);
            printf("Housing allowance: ");   scanf("%f", &housing);
            printf("Transport allowance: "); scanf("%f", &transport);
            printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
            break;
        }
        case 3:
        {
            float revenue, expenses, result;
            printf("Revenue: ");  scanf("%f", &revenue);
            printf("Expenses: "); scanf("%f", &expenses);
            result = calculateBudget(revenue, expenses);
            printf("Budget balance: %.2f\n", result);
            if (result > 0)      printf("SURPLUS\n");
            else if (result < 0) printf("DEFICIT\n");
            else                 printf("BALANCED\n");
            break;
        }
        case 4:
        {
            int id, pos;
            printf("Enter employee ID: ");
            scanf("%d", &id);
            pos = searchEmployee(id, employeeIDs, size);
            if (pos != -1) printf("Employee found at position %d.\n", pos);
            else           printf("Employee not found.\n");
            break;
        }
        case 5:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void displayMenu(void)
{
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}
