//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_LIST_SIZE 100
//
//typedef int Element;
//Element data[MAX_LIST_SIZE];
//int length = 0;
//
//void error(char* str) {
//	fprintf(stderr, "%s\n", str);
//	exit(1);
//};
//void init_list() { length = 0; }
//void clear_list() { length = 0; }
//int is_empty() { return length == 0; }
//int is_full() { return length == MAX_LIST_SIZE; }
//int get_entry(int id) { return data[id]; }
//void replace(int id, Element e) { data[id] = e; }
//int size() { return length; }
//void insert(int pos, int e) {
//	int i;
//	if (is_full() == 0 && pos >= 0 && pos <= length) {
//		for (i = length; i > pos; i--)
//			data[i] = data[i - 1];
//		data[pos] = e;
//		length++;
//	}
//	else error("포화상태 오류 또는 삽입 위치 오류");
//}
//void delete(int pos) {
//	int i;
//	if (is_empty() == 0 && 0 <= pos && pos < length) {
//		for (i = pos + 1; i < length; i++)
//			data[i - 1] = data[i];
//		length--;
//	}
//	else error("공백상태 오류 또는 삭제 위치 오류");
//}
//int find(Element e) {
//	int i;
//	for (i = 0; i < length; i++)
//		if (data[i] == e) return i;
//	return -1;
//}
//void print_list(char* msg) {
//	int i;
//	printf("%s[%2d]:", msg, length);
//	for (i = 0; i < length; i++)
//		printf("%2d ", data[i]);
//	printf("\n");
//}
//void main() {
//	init_list();
//	insert(0, 10);
//	insert(0, 20);
//	insert(1, 30);
//	insert(size(), 40);
//	insert(2, 50);
//	print_list("배열로 구현한 List(삽입X5)");
//}

//프로그램 6.17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE 1000

typedef struct Line { //라인
	char str[MAX_CHAR_PER_LINE];
}Line;
typedef Line Element;
typedef struct LinkedNode { //연결리스트
	Element data;
	struct LinkedNode* link;
}Node;
Node* head;

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }
Node* get_entry(int pos) { //pos번째 노드를 찾아 반환하는 함수
	Node* p = head;
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL) return NULL;
	return p;
}
int size() { //리스트 안의 요소 개수 반환하는 함수
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}
void replace(int pos, Element val) {		//pos위치에 있는 데이터를 val로 교체하는 함수
	Node* node = get_entry(pos);			//pos번째에 있는 노드를 찾는다
	if (node != NULL)
		node->data = val;
}
void insert_next(Node* prev, Node* n) { //삽입연산
	if (n != NULL) {
		n->link = prev->link;		//노드n의 링크는 이전노드의 링크를 가리킴
		prev->link = n;				 //이전노드의 링크는 노드n을 가리킴
	}
}
void insert(int pos, Element val) { //pos위치에 항목 val 삽입하는 연산
	Node* new_node, * prev;

	new_node = (Node*)malloc(sizeof(Node)); //새로운 노드 동적생성
	new_node->data = val;
	new_node->link = NULL;

	if (pos == 0) { //1.리스트 맨 앞에 넣는 경우
		new_node->link = head;
		head = new_node;
	}
	else { //2.리스트 중간에 삽입
		prev = get_entry(pos - 1); //pos-1(pos이전) 위치의 노드 찾기
		if (prev != NULL)
			insert_next(prev, new_node);
		else free(new_node);
	}
}
Node* remove_next(Node* prev) { //삭제연산
	Node* removed = prev->link; //노드 removed가 삭제할 노드(N)를 가리키도록 함
	if (removed != NULL)
		prev->link = removed->link; //prev의 노드가 after노드를 가리키게 함
	return removed;
}
void delete(int pos) { //pos번째 항목 삭제하는 연산
	Node* prev, * removed;

	if (pos == 0 && is_empty() == 0) { //1. 맨 앞 노드 삭제하는 경우
		removed = head;
		head = head->link;
		free(removed);
	}
	else { //2. pos번째 항목 삭제하는 경우
		prev = get_entry(pos - 1); //pos-1번째(before)을 찾고, remove_next()호출 후, 메모리 해제
		if (prev != NULL) {
			removed = remove_next(prev);
			free(removed);
		}
	}
}
void clear_list() { //리스트를 비우는 연산
	while (is_empty() == 0) //공백상태가 아닌경우 맨 앞 노드를 삭제!
		delete(0);
}

void display(FILE* fp)
{
	int i = 0;
	Node* p;
	for (p = head; p != NULL; p = p->link, i++) {
		fprintf(stderr, "%3d: ", i);
		fprintf(fp, "%s", p->data.str);
	}
}
void my_fflush() { while (getchar() != '\n'); }

void main() {
	char command;
	int pos;
	Line line;
	FILE* fp; //파일 포인터 fp

	init_list();
	do {
		printf("[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료=> ");
		command = getchar();
		switch (command) {
		case 'i':
			printf("	입력행 번호:");
			scanf("%d", &pos);
			printf("	입력행 내용:");
			my_fflush(); //입력 버퍼(키보드)에서 \n을 지움
			fgets(line.str, MAX_CHAR_PER_LINE, stdin); //
			insert(pos, line);
			break;
		case 'd':
			printf("	삭제행 번호:");
			scanf("%d", &pos);
			delete(pos);
			break;
		case 'r':
			printf("	변경행 번호:");
			scanf("%d", &pos);
			printf("	변경행 내용:");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);
			break;
		case 'l':
			fp = fopen("read.txt", "r");
			if (fp != NULL) {
				while (fgets(line.str, MAX_CHAR_PER_LINE, fp))
					insert(size(), line);
				fclose(fp); //파일 닫기
			}
			break;
		case 's':
			fp = fopen("read.txt", "w");
			if (fp != NULL) {
				display(fp);
				fclose(fp);
			}
		case 'p': display(stdout);
		}
		my_fflush();
	} while (command != 'q');
}