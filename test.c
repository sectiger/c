#include <stdio.h>
#include <stdlib.h>

int ga = 0;
int gb;

int memory_check(int *d)
{
		int *c = (int *)malloc(sizeof(int));

			printf("hi %p\n", "hi");
				printf("a %p\n", &ga);
					printf("b %p\n", &gb);
						printf("c %p\n", c);
							printf("d %p\n", d);
								
								*d = 2;

									return 0;
}

void test_none()
{
		int test = 0;

			++test;

				printf("[%s] test = %d\n", __func__, test);

					return ;
}

void test_static()
{
		static int test = 0;

			++test;

				printf("[%s] test = %d\n", __func__, test);

					return ;
}

int main()
{
		int d;
			const int *a = &d;		// a의 address는 변경 가능, a가 가르키는 곳의 값은 변경 불가능
				int * const b = &d;		// b의 address는 변경 불가, b가 가르키는 곳의 값은 변경 가능

					int c;

						const int e = 5;

							//e = 1;		// error

							char * const hi = "hi";

								//hi = "hello";		//error

								memory_check(&d);

									printf("main d = %p\n", &d);

										//*a = 1;		//error
										*b = 1;

											a = &c;
												//b = &c;		// error

												int i;
													for(i = 0; i < 5; ++i) {
																test_none();
																	}

														for(i = 0; i < 5; ++i) {
																	test_static();
																		}

															return 0;
}
