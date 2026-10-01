
#include <stdio.h>

#define EMPLOYEES 50

int main(void)
{
    float salaries[EMPLOYEES];
    float total = 0, average, highest, lowest, temp, target;
    int found = 0;

    for (int i = 0; i < EMPLOYEES; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\n--- All Salaries ---\n");
    for (int i = 0; i < EMPLOYEES; i++)
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);


    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 0; i < EMPLOYEES; i++)
    {
        total += salaries[i];
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest = salaries[i];
    }
    average = total / EMPLOYEES;

    printf("\n--- Salary Report ---\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary : %.2f\n", lowest);


    printf("\nEnter a salary to search for: ");
    scanf("%f", &target);
    for (int i = 0; i < EMPLOYEES; i++)
    {
        if (salaries[i] == target)
        {
            printf("Salary found at position %d (employee %d)\n", i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) printf("Salary not found.\n");


    for (int i = 0; i < EMPLOYEES- 1; i++)
    {
        for (int j = 0; j < EMPLOYEES - i - 1; j++)
        {
            if (salaries[j] > salaries[j + 1])
            {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }


    printf("\n--- Salaries Sorted (lowest to highest) ---\n");
    for (int i = 0; i < EMPLOYEES; i++)
        printf("%.2f\n", salaries[i]);

    return 0;
}
