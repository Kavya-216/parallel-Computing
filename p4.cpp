 #include <stdio.h>
 #include <time.h>

 int is_prime(int number)
 {
	 int divisor;

	 if (number < 2)
		 return 0;

	 for (divisor = 2; divisor <= number / divisor; divisor++)
	 {
		 if (number % divisor == 0)
			 return 0;
	 }

	 return 1;
 }

 int main(void)
 {
	 int m, n, number;
	 clock_t start, end;
	 double execution_time;

	 printf("Enter m and n: ");
	 if (scanf("%d %d", &m, &n) != 2)
	 {
		 printf("Invalid input.\n");
		 return 1;
	 }

	 if (m > n)
	 {
		 int temporary = m;
		 m = n;
		 n = temporary;
	 }

	 start = clock();

	 printf("Prime numbers from %d to %d:\n", m, n);
	 for (number = m; number <= n; number++)
	 {
		 if (is_prime(number))
			 printf("%d ", number);
	 }
	 printf("\n");

	 end = clock();
	 execution_time = (double)(end - start) / CLOCKS_PER_SEC;
	 printf("Execution time: %.6f seconds\n", execution_time);

	 return 0;
 }
