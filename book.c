#include <stdio.h>

struct book {
	char *name;
	int year;
	int price;
} bk;

static int func(int n)
{
	int sum = 0,i;
	for(i = 0; i < n; i++)
	{
		sum += i;
	}
	return sum;
}

static void modify_book(void)
{
	int i = 0;
	while(1) {
		bk.name = "linux device driver";
		bk.year = i;
		bk.price = i;
		i++;
		printf("%d\n", i);
		sleep(1);
	};
}

int main(int argc, char **argv)
{
	int i;
	int result = 0;
	for(i = 1; i <= 100; i++)
	{
		result += 1;
	}
	printf("result[1-100] = %d n ",result);
	printf("result[1-250] = %d n ",func(250));

	modify_book();

	return 0;
}
