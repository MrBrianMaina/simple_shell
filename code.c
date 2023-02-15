#include <stdio.h>
/**
  *main - grades
  *
  *Return: Always 0
  */
int main(void)
{
	int grade[] = {65, 98, 54, 65, 76};

	for (int i = 0; i < 5; i++)
		printf("grade[%d] = %d\n", i,  grade[i]);
			return (0);
}
