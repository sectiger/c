#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN		30
#define OTHER_LEN		15

// 구조체 정의
typedef struct node
{
	char book[NAME_LEN];
	char author[OTHER_LEN];
	char publisher[OTHER_LEN];
	char price[OTHER_LEN];
	char year[OTHER_LEN];
	struct node* next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

NODE *make()
{
	NODE *temp;
	char buff[30] = {};
	//temp = (NODE *)calloc(1, sizeof(NODE));

	temp = (NODE *)malloc(sizeof(NODE));

	memset(temp->book, 0, NAME_LEN);
	memset(temp->author, 0, OTHER_LEN);
	memset(temp->publisher, 0, OTHER_LEN);
	memset(temp->price, 0, OTHER_LEN);
	memset(temp->year, 0, OTHER_LEN);

	printf("도서명 : ");
	//fgets(temp->book, sizeof(NAME_LEN), stdin);
	scanf("%s", buff);
	strncpy(temp->book, buff, strlen(buff));
	printf("저자명 : ");
	//fgets(temp->author, sizeof(OTHER_LEN), stdin);
	scanf("%s", buff);
	strncpy(temp->author, buff, strlen(buff));
	printf("출판사 : ");
	//fgets(temp->publisher, sizeof(OTHER_LEN), stdin);
	scanf("%s", buff);
	strncpy(temp->publisher, buff, strlen(buff));
	printf("판매가 : ");
	//fgets(temp->price, sizeof(OTHER_LEN), stdin);
	scanf("%s", buff);
	strncpy(temp->price, buff, strlen(buff));
	printf("출간년도 : ");
	//fgets(temp->year, sizeof(OTHER_LEN), stdin);
	scanf("%s", buff);
	strncpy(temp->year, buff, strlen(buff));
	//while (getchar() != '\n');

	temp->next = NULL;

	printf("%s %s %s %s %s", temp->book, temp->author, temp->publisher, temp->price, temp->year);

	return temp;
}

int push(NODE *data)

{
	NODE *current = head;

	if(head == NULL){
		head = data;
	} else if(current->next == NULL) {
		head->next = data;
	} else {
		for (current = head; current->next != NULL; current = current->next);

		current->next = data;
	}
	return 0;
}

/*
   void save_file()
   {
   FILE *fp;
   fp = fopen("data.txt", "wb");

   Book *t;

   if (fp == NULL)
   {
   printf("오류\n");
   return;
   }
   t = head->next;
   while (t != NULL)
   {
   fwrite(t, sizeof(BOOK_LEN), 1, fp);
   t = t->next;
   }
   fclose(fp);
   }

   void load_File()
   {
   FILE *fp;
   fp = fopen("BOOK.DBF", "rb");

   Book *p;
   Book *s;

   if (fp == NULL)
   {
   printf(" 오류 \n");
   return;
   }

   p = head->next;
   while (p != tail)
   {
   s = p;
   p = p->next;
   free(s);
   }

   head->next = tail; // head를 tail과 연결 시켜 준다.
   while (1)
   {
   p = (Book*)calloc(1, sizeof(Book));
   if (!fread(p, sizeof(BOOK_LEN), 1, fp))    // EOF까지 구조체를 읽어들이면서 node를 추가한다.
   {
   free(p);
   break;
   }
   p->next = head->next;
   head->next = p;
   }
   fclose(fp);
   }
 */
void Display(NODE *display)
{
	NODE *temp = display;

	printf("도서명 : %s \n", temp->book);
	printf("저자명 : %s \n", temp->author);
	printf("출판사 : %s \n", temp->publisher);
	printf("판매가 : %s \n", temp->price);
	printf("출간년도 : %s \n", temp->year);
	printf("\n");

	return;
}

int free_all()
{
	NODE *next;

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
	int num = 0;
	NODE *temp;
	while (1) {
		printf("[ Menu ]\n");
		printf("1. 도서 입력\n");
		printf("2. 도서 확인\n");
		printf("3. 종료\n");
		printf("4. txt 출력\n");
		printf("--------------\n");
		printf("선택(1 ~ 4) : ");

		scanf("%d", &num);

		printf("\n");

		if (num == 3) {
			break;
		} else if (num == 1) {
			temp = make();
			push(temp);
		} else if (num == 2) {
			Display(temp);
		} else if (num == 4) {

		}
		while (getchar() != '\n');
		printf("\n");
	}
	free_all();
	return 0;
}
