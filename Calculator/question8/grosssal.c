#include <stdio.h>

int main()
{
	float basic, gross, da, hra;

	/* Input basic salary of employee */
	printf("Enter basic salary of an employee: ");
	scanf_s("%f", &basic);


	/* Calculate D.A and H.R.A according to specified conditions */
    if (basic <= 4000 && basic >=1)
	{
		da = basic * 0.5;
		hra = basic * 0.1;
	}
	else if (basic >=4001 && basic <= 8000)
	{
		da = basic * 0.6;
		hra = basic * 0.2;
	}
	else if (basic >= 8001 && basic < 12000)
	{
		da = basic * 0.7;
		hra = basic * 0.25;
	}
	else if (basic >= 12000)
	{
		da = basic * 0.8;
		hra = basic * 0.3;
	}
	else
	{
		printf("Error");
	}

	/* Calculate gross salary */
	gross = basic + hra + da;

	printf("GROSS SALARY OF EMPLOYEE = %.2f", gross);
	scanf_s("%d", &basic);
	getchar();
	return 0;
}