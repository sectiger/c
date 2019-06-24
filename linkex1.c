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
		head = data;
	} else if(current->next == NULL) {
		if(head->pri > data->pri) {
			data->next = head;
			head->next = data;
		} else if(head->pri < data->pri) {
			head->next = data;
		} else {
			int ret = strcmp(head->name, data->name);

			if(ret < 0) {
				head->next = data;
			} else {
				data->next = head;
				head->next = data;
			}
		}
	} else {
		temp = current;
		for(current = head;current->next != NULL;current = current->next) {
			if(current->pri > data->pri) {
				temp->next = data;
				data->next = current;
			}
			temp = current;
		}

		if(current->next == NULL && data->pri > current->pri) {
			current->next = data;
		}
	}

	return 0;
}

CJUNG *pop_front()
{
	struct cjung *temp;

	temp = head;
	head = head->next;

	return temp;
}

CJUNG *pop_back()
{
	struct cjung *temp;

	return temp;
}

void print_list()
{
	struct cjung *cur;

	for(cur = head;cur->next != NULL;cur = cur->next) {
		printf("priority %d, name %s\n", cur->pri, cur->name);
	}
	printf("priority %d, name %s\n", cur->pri, cur->name);

	return ;
}

int main()
{
	struct cjung *temp;

	temp = make(1, "cjung");
	sort_push(temp);
	temp = make(3, "mgyou");
	sort_push(temp);
	temp = make(4, "jwjeon");
	sort_push(temp);
	temp = make(2, "sbpark");
	sort_push(temp);

	print_list();


	return 0;
}
