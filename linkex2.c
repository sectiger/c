#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cjung
{
	int a;
	char name[20];
	struct cjung *next;
};

struct cjung *head = NULL;

int push(int data, char *str)
{
	struct cjung *temp;
	struct cjung *current;

	// memory allocate
	temp = (struct cjung *)malloc(sizeof(struct cjung));	
	temp->a = data;
	strncpy(temp->name, str, strlen(str));
	temp->next = NULL;

	// link head
	if(head == NULL) {
		head = temp;	
	} else {
		// head 끝까지 
		//for(current = head;current->next =! NULL;current = current->next) {
		current = head;
		while(1) {
			if(current->next == NULL) {
				current->next = temp;
				temp->next = NULL;
				break;
			}
			current = current->next;
		}
	}

	return 0;
	}

	struct cjung*pop()
	{
		struct cjung *temp;

		temp = head;
		head = head->next;

		return temp;
	}

	int main()
	{
		struct cjung *temp;

		push(1, "cjung");
		push(2, "sbpark");
		push(3, "mgyoo");

		printf("head->a = %d\n", head->a);
		printf("head->next->a = %d\n", head->next->a);
		printf("head->next->next->a = %d\n", head->next->next->a);

		temp = pop();

		printf("pop value = %d\n", temp->a);
		printf("pop name = %s\n", temp->name);

		free(temp);
		temp = NULL;

		temp = pop();

		printf("pop value = %d\n", temp->a);
		printf("pop name = %s\n", temp->name);

		free(temp);
		temp = NULL;

		temp = pop();

		printf("pop value = %d\n", temp->a);
		printf("pop name = %s\n", temp->name);

		free(temp);
		temp = NULL;


		return 0;
	}
