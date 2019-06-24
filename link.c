#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE *next;
	int data;
};

void addFirst(struct NODE *target, int data) // 기준 노드 뒤에 노드를 추가하는 함수
{
	struct NODE *newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;

	target->next = newNode;
}

void removeFirst(struct NODE *target)
{
	struct NODE *removeNode = target->next;
	target->next = removeNode->next;

	free(removeNode);
}
int main()
{
	struct NODE *head = malloc(sizeof(struct NODE));

	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);

	removeFirst(head);

	struct NODE *curr = head->next;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	
	curr = head->next;
	while (curr != NULL)
	{
		struct NODE *next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);

	return 0;
}

