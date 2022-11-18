/* 2. Write a C program to assign values to each member of the following
structure. Pass the populated structure to a function Using call-by address and
print the value of each member of the structure within that function.
struct info{
int roll_no;
char name[50];
float CGPA;
}
*/

#include <stdio.h>
#include <stdlib.h>
struct info
{
    int roll_no;
    char name[50];
    float CGPA;
};
void print(struct info *student)
{
    printf("\nName: %s\n",student->name);
    printf("Roll number: %d\n",student->roll_no);
    printf("CGPA: %f\n",student->CGPA);
}
int main()
{
    struct info student;
    printf("Enter name: ");
    scanf("%s",&student.name);
    printf("Enter roll no.: ");
    scanf("%d",&student.roll_no);
    printf("Enter CGPA: ");
    scanf("%f",&student.CGPA);
    print(&student);
    return 0;
}