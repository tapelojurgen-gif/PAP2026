
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS  10
#define NUM_REGS     20

int main(void)
{
    float salaries[NUM_SALARIES];
    float budgets[NUM_BUDGETS];
    char registrations[NUM_REGS][20];
    int salariesDone = 0, budgetsDone = 0, regsDone = 0;
    int choice;

    do
    {
        printf("\n===== MUNICIPAL INFORMATION MANAGEMENT SYSTEM =====\n");
        printf("A. EMPLOYEE SALARIES\n");
        printf(" 1. Capture salaries\n");
        printf(" 2. Display salaries + average, highest, lowest\n");
        printf(" 3. Search for a salary\n");
        printf("B. DEPARTMENT BUDGETS\n");
        printf(" 4. Capture budgets\n");
        printf(" 5. Display budgets + total and average\n");
        printf(" 6. Sort budgets (lowest to highest)\n");
        printf("C. VEHICLE REGISTRATIONS\n");
        printf(" 7. Capture registrations\n");
        printf(" 8. Display registrations\n");
        printf(" 9. Search for a registration\n");
        printf(" 0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < NUM_SALARIES; i++)
            {
                printf("Enter salary %d: ", i + 1);
                scanf("%f", &salaries[i]);
            }
            salariesDone = 1;
            break;

        case 2:
            if (!salariesDone) { printf("Capture salaries first.\n"); break; }
            {
                float total = 0, highest = salaries[0], lowest = salaries[0];
                printf("\nEmployee Salaries\n");
                for (int i = 0; i < NUM_SALARIES; i++)
                {
                    printf("%d. %.2f\n", i + 1, salaries[i]);
                    total += salaries[i];
                    if (salaries[i] > highest) highest = salaries[i];
                    if (salaries[i] < lowest)  lowest = salaries[i];
                }
                printf("Average: %.2f\n", total / NUM_SALARIES);
                printf("Highest: %.2f\n", highest);
                printf("Lowest : %.2f\n", lowest);
            }
            break;

        case 3:
            if (!salariesDone) { printf("Capture salaries first.\n"); break; }
            {
                float target;
                int found = 0;
                printf("Enter salary to search for: ");
                scanf("%f", &target);
                for (int i = 0; i < NUM_SALARIES; i++)
                {
                    if (salaries[i] == target)
                    {
                        printf("Salary found at position %d (employee %d)\n", i, i + 1);
                        found = 1;
                    }
                }
                if (!found) printf("Salary not found.\n");
            }
            break;

        case 4:
            for (int i = 0; i < NUM_BUDGETS; i++)
            {
                printf("Enter budget for department %d: ", i + 1);
                scanf("%f", &budgets[i]);
            }
            budgetsDone = 1;
            break;

        case 5:
            if (!budgetsDone) { printf("Capture budgets first.\n"); break; }
            {
                float total = 0;
                printf("\nDepartment Budgets\n");
                for (int i = 0; i < NUM_BUDGETS; i++)
                {
                    printf("Department %d: %.2f\n", i + 1, budgets[i]);
                    total += budgets[i];
                }
                printf("Total budget  : %.2f\n", total);
                printf("Average budget: %.2f\n", total / NUM_BUDGETS);
            }
            break;

        case 6:
            if (!budgetsDone) { printf("Capture budgets first.\n"); break; }
            {
                float temp;
                /* Bubble sort, ascending */
                for (int i = 0; i < NUM_BUDGETS - 1; i++)
                {
                    for (int j = 0; j < NUM_BUDGETS - i - 1; j++)
                    {
                        if (budgets[j] > budgets[j + 1])
                        {
                            temp = budgets[j];
                            budgets[j] = budgets[j + 1];
                            budgets[j + 1] = temp;
                        }
                    }
                }
                printf("\nBudgets sorted (lowest to highest):\n");
                for (int i = 0; i < NUM_BUDGETS; i++)
                    printf("%.2f\n", budgets[i]);
            }
            break;

        case 7:
            for (int i = 0; i < NUM_REGS; i++)
            {
                printf("Enter vehicle registration %d: ", i + 1);
                scanf("%19s", registrations[i]);
            }
            regsDone = 1;
            break;

        case 8:
            if (!regsDone) { printf("Capture registrations first.\n"); break; }
            printf("\nVehicle Registrations\n");
            for (int i = 0; i < NUM_REGS; i++)
                printf("%d. %s\n", i + 1, registrations[i]);
            break;

        case 9:
            if (!regsDone) { printf("Capture registrations first.\n"); break; }
            {
                char target[20];
                int found = 0;
                printf("Enter registration to search for: ");
                scanf("%19s", target);
                for (int i = 0; i < NUM_REGS; i++)
                {
                    if (strcmp(registrations[i], target) == 0)
                    {
                        printf("Registration found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Registration not found.\n");
            }
            break;

        case 0:
            printf("Goodbye.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
