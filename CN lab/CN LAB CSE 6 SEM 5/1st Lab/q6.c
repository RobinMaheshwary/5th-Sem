#include <stdio.h>
#include <stdlib.h>
struct Employee
{
    char name[20];
    int employee_id;
    int salary;
};
struct Organisation
{
    char name[20];
    char number[20];
    struct Employee emp;
};
int main()
{
    struct Organisation org;
    printf("Enter Organisation Name: ");
    scanf("%s",org.name);
    printf("Enter Organisation Number: ");
    scanf("%s",org.number);
    printf("Enter Employee Name: ");
    scanf("%s",org.emp.name);
    printf("Enter Employee id: ");
    scanf("%d",&org.emp.employee_id);
    printf("Enter Employee Salary: ");
    scanf("%d",&org.emp.salary);

    printf("\nPrinting Details:\n");
    printf("Organisation Name: %s\n",org.name);
    printf("Organisation Number: %s\n",org.number);
    printf("Employee Name: %s\n",org.emp.name);
    printf("Employee id: %d\n",org.emp.employee_id);
    printf("Employee Salary: %d\n",org.emp.salary);
    return 0;
}