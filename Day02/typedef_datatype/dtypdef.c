

#include<stdio.h>
#include<string.h>


int main(void)
{
    typedef struct emp{
        int emp_id;
        char emp_name[10];
    }empdata_t;

    empdata_t emp1;

    printf("Enter Employe Id::\n");
    scanf("%d", &emp1.emp_id);
    printf("Enter Employee name::\n");
    scanf("%s", emp1.emp_name);

    printf("Employee Id and Name:: %d %s\n", emp1.emp_id, emp1.emp_name);

}
