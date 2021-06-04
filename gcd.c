/* Author: John Do
 * Date: May 11, 2021
 * Purpose: To find the greatest common denominator of N numbers
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int array[1000];
	int number_of_numbers;
	int elements;
	int m;
	int n;
	int remainder_mn;
	int robust;



	for (int i = 1; i <= 1000; i++) 
	{
		printf("Enter number #%d (Enter 0 to stop inputting): ", i);
		scanf_s("%d", &elements);
		array[i - 1] = elements;
		if (elements == 0)
		{
			break;
		}
	}

	for (int z = 1; z <= 1000; z++)
	{
		if (array[z - 1] == 0)
		{
			number_of_numbers = z-1;
			break;
		}
	}

	for (int j = 0; j <= (number_of_numbers - 2); j++)
	{
		//if (array[j] > array[j + 1])
		//{
		//	m = array[j];
		//	n = array[j + 1];
		//}
		//if (array[j] < array[j + 1])
		//{
		//	n = array[j];
		//	m = array[j + 1];
		//}
		m = max(array[j], array[j + 1]);
		n = min(array[j], array[j + 1]);
		remainder_mn = m % n;
		if (remainder_mn == 0)
		{
			array[j + 1] = n;
		}
		else
		{
			robust = remainder_mn;
			for (;;)
			{
				if (robust > n)
				{
					m = robust;
				}
				if (robust < n)
				{
					m = n;
					n = robust;
				}
				robust = m % n;
				if (robust == 0)
				{
					break;
				}
			}
			array[j + 1] = n;
		}
	}
	printf("GCD: %d \n\n", n);
	system("PAUSE");
}