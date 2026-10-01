#include <stdio.h>

int main(void)
{
    char studentName[50];
    float test1, test2, assignment, total;

    printf("Enter student name: ");
    scanf("%s", studentName);
    printf("Enter Test 1 mark: ");
    scanf("%f", &test1);
    printf("Enter Test 2 mark: ");
    scanf("%f", &test2);
    printf("Enter Assignment mark: ");
    scanf("%f", &assignment);

    total = test1 + test2 + assignment;

    printf("\nStudent: %s\n", studentName);
    printf("Total: %.2f\n", total);

    if (total < 0 || total > 100)
    {
        printf("Result: Invalid total (must be between 0 and 100)\n");
    }
    else if (total >= 75)
    {
        printf("Result: Distinction\n");
    }
    else if (total >= 60)
    {
        printf("Result: Credit\n");
    }
    else if (total >= 50)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }

    return 0;
}
