// Bryan Aneyro Hernandez

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StringType 
{
    char *string;
    int length;
} StringType;

typedef struct Employee 
{
    StringType *ename;
    double salary;
} Employee;

Employee* createEmployees(char names[][50], double *salaries, int empCount)
{
    // Allocate memory for empCount number of Employee structures
    Employee* employees = malloc(empCount * sizeof(Employee));
    if (employees == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Iterate over each employee
    for (int i = 0; i < empCount; i++) 
    {
        // Allocate memory for StringType
        employees[i].ename = malloc(sizeof(StringType));
        if (employees[i].ename == NULL) {
            printf("Memory allocation failed.\n");
            // Free memory allocated so far
            for (int j = 0; j < i; j++) 
            {
                free(employees[j].ename);
            }
            free(employees);
            return NULL;
        }

        // Calculate length of the name
        employees[i].ename->length = strlen(names[i]);

        // Allocate memory for the string
        employees[i].ename->string = malloc((employees[i].ename->length + 1) * sizeof(char));
        if (employees[i].ename->string == NULL) 
        {
            printf("Memory allocation failed.\n");
            // Free memory allocated so far
            for (int j = 0; j < i; j++) 
            {
                free(employees[j].ename->string);
                free(employees[j].ename);
            }
            free(employees);
            return NULL;
        }

        // Copy the name into the allocated memory
        strcpy(employees[i].ename->string, names[i]);

        // Assign the salary
        employees[i].salary = salaries[i];
    }

    // Return the dynamically allocated array of Employee structures
    return employees;  
}

int main() 
{
    const int EMPLOYEE_COUNT = 4;
    //array of employees’ names
    char nameList[][50] = {"Bill", "Mary", "Kevin", "Denise"};
    //array of salaries, where 15.80 is the salary of Bill, 13.50 is
    // the salary of Mary, etc.
    double salaries[] = {15.80, 13.5, 20.9, 12.99};
    Employee *pEmployees = createEmployees(nameList, salaries, EMPLOYEE_COUNT);
    // Print Employees
    int e = 0;
    Employee *pEmployee = pEmployees;
    printf("\tEMPLOYEE NAME\t\tSALARY\n");
    for (e=0;e<EMPLOYEE_COUNT;++e) 
    {
        printf("\t%s\t\t\t%.2lf\n",pEmployee->ename->string,pEmployee->salary);
        pEmployee++;
    }
    // Deallocate memory
    pEmployee = pEmployees;
    for (e=0;e<EMPLOYEE_COUNT;++e) 
    {
        free(pEmployee->ename->string);
        pEmployee->ename->string = NULL;
        free(pEmployee->ename);
        pEmployee->ename = NULL;
        pEmployee++;
    }
    free(pEmployees);
    pEmployees = NULL;
    return 0;
}