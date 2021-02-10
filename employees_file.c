#include<stdio.h>
void create_employees_file()
{
	FILE* fp = NULL;
	char user_name, password, security_level, full_name;
	fp = fopen("employees_name", "a+");
	if (fp!= NULL)
	{
		/*Write the user name on the employee file.
		*/
		printf("please enter the employee user name");
		scanf_s("%d", &user_name);
		fputs(fp, "employee_name");
		/*Write the password on the employee file.
		*/
		printf("please enter the employee password");
		scanf_s("%d", &password);
		fputs(fp, "password");
		/*Write the securite level on the employee file.
		*/
		printf("please enter the employee securite level");
		scanf_s("%d", &security_level);
		fputs(fp, "securite_level");
		/*Write the full name on the employee file.
		*/
		printf("please enter the employee full name");
		scanf_s("%d", &full_name);
		fputs(fp, "full_name");
		fclose(fp);// close the file

	}
}