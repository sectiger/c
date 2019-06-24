#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN		20

typedef struct cjung
{
	int pri;				// priority
	char name[NAME_LEN];
	struct cjung *next;
} CJUNG;

CJUNG *head = NULL;
CJUNG *tail = NULL;

CJUNG *make(int pri, char *name)
{
	CJUNG *temp;

	temp = (CJUNG *)malloc(sizeof(CJUNG));	

	temp->pri = pri;
	memset(temp->name, 0, NAME_LEN);
	strncpy(temp->name, name, strlen(name));
	temp->next = NULL;

	return temp;
}

int push(CJUNG *data)
{
	CJUNG *current = head;

	// link head
	if(head == NULL) {
		head = data;
	} else if(current->next == NULL) {
		head->next = data;	
	} else {
		for(current = head;current->next != NULL;current = current->next);

		current->next = data;
	}

	return 0;
}

int sort_push(CJUNG *data)
{	
	CJUNG *current = head;
	CJUNG *temp;

	// link head
	if(head == NULL) {
		printf("head == NULL\n");
		head = data;
	} else if(current->next == NULL) {
		if(head->pri > data->pri) {
			data->next = head;
			head = data;
			data->next = NULL;
		} else if(head->pri < data->pri) {
			head->next = data;
		} else {
			int ret = strcmp(head->name, data->name);

			if(ret < 0) {
				head->next = data;
			} else {
				data->next = head;
				head = data;
			}
		}
	} else {
		temp = current;
		for(current = head;current->next != NULL;current = current->next) {
			if(current->pri > data->pri) {
				temp->next = data;
				data->next = current;
				break;
			} else if(current->pri == data->pri) {
				int ret = strcmp(current->name, data->name);

				if(ret > 0) {
					temp->next = data;
					data->next = current;
				}
			}
			temp = current;
		}

		if(current->next == NULL && data->pri > current->pri) {
			current->next = data;
		} else if(current->next == NULL && data->pri == current->pri) {
			int ret = strcmp(current->name, data->name);

			if(ret > 0) {
				temp->next = data;
				data->next = current;
				current->next = NULL;
			} else if(ret < 0) {
				current->next = data;
				data->next = NULL;
			}
		}
	}

	return 0;
}

CJUNG *pop_front()
{
	CJUNG *temp;

	temp = head;
	head = head->next;

	return temp;
}

CJUNG *pop_back()
{
	CJUNG *cur;
	CJUNG *pre;

	for(cur = head, pre = head;cur->next != NULL;cur = cur->next) {
		pre = cur;
	}

	pre->next = NULL;

	return cur;
}

void print_list()
{
	CJUNG *cur;

	// NULL pointer exception handling
	if(head == NULL) {
		printf("[%s] No list to output\n", __func__);
		return ;
	}

	printf("================================\n");
	for(cur = head;cur->next != NULL;cur = cur->next) {
		printf("priority %d, name %s\n", cur->pri, cur->name);
	}
	printf("priority %d, name %s\n", cur->pri, cur->name);
	printf("================================\n");

	return ;
}

int free_all()
{
	CJUNG *next;

	while(1) {
		if(head->next != NULL) {
			next = head->next;
		} else {
			free(head);
			head = NULL;
			break;
		}

		free(head);

		head = next;
	}

	return 0;
}

int main()
{
	CJUNG *temp;

	temp = make(1, "cjung");
	sort_push(temp);
	print_list();
	temp = make(1, "amanda");
	sort_push(temp);
	print_list();
	temp = make(1, "zammanbo");
	sort_push(temp);
	print_list();
	temp = make(3, "mgyou");
	sort_push(temp);
	print_list();
	temp = make(4, "jwjeon");
	sort_push(temp);
	print_list();
	temp = make(4, "amang");
	sort_push(temp);
	print_list();
	temp = make(2, "sbpark");
	sort_push(temp);

	print_list();

	temp = pop_back();
	printf("pop_back pri : %d, name : %s\n", temp->pri, temp->name);
	free(temp);

	temp = pop_front();
	printf("pop_front pri : %d, name : %s\n", temp->pri, temp->name);
	free(temp);

	print_list();

	free_all();

	print_list();

	return 0;
}

