//3장
#pragma region p.18
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100 //스택 요소 저장을 위한 배열의 크기
//typedef int Element; //스택 요소의 자료형 정의
//
//Element data[MAX_STACK_SIZE]; //실제 스택 요소의 배열
//int top; //실제 스택의 top
//
////오류 상황 처리를 위한 함수. 메세지 출력 후 프로그램 종료.
//void error(char str[])
//{
//	printf("%s\n", str);
//	exit(1);
//}
//
//void init_stack() { top = -1; }
//int is_empty() { return top == -1; }
//int is_full() { return top == MAX_STACK_SIZE; }
//int size() { return top + 1; }
//
//void push(Element e)
//{
//	if (is_full())
//		error("스택 포화 에러");
//	data[++top] = e;
//}
//
//Element pop()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top--];
//}
//
//Element peek()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top];
//}
//
////스택 테스트를 위한 코드: 요소 종류마다 수정
//void print_stack(char msg[]) {
//	int i;
//	printf("%s[%2d]", msg, size());
//	for (i = 0; i < size(); i++)
//		printf("%2d", data[i]);
//	printf("\n");
//}
//
//void main()
//{
//	int i;
//	init_stack();
//	for (i = 1; i < 10; i++)
//		push(i);
//
//	print_stack("스택 push 9회");
//	printf("/tpop() --> %d\n", pop());
//	printf("/tpop() --> %d\n", pop());
//	printf("/tpop() --> %d\n", pop());
//	print_stack("스택 pop 3회");
//}
#pragma endregion

#pragma region p.20
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100 //스택 요소 저장을 위한 배열 크기
//
//typedef struct Student { //스택에 저장할 요소의 자료형
//	int id; //학번
//	char name[32]; //이름
//	char dept[32]; //소속 학과
//} Student; //스택 요소 저장을 위한 배열의 크기
//
//typedef Student Element; //스택 요소의 자료형 정의
//Element data[MAX_STACK_SIZE]; //실제 스택 요소의 배열
//int top; //실제 스택의 top
//
//void error(char str[])
//{
//	printf("%s\n", str);
//	exit(1);
//}
//
//void init_stack() { top = -1; }
//int is_empty() { return top == -1; }
//int is_full() { return top == MAX_STACK_SIZE; }
//int size() { return top + 1; }
//
//void push(Element e)
//{
//	if (is_full())
//		error("스택 포화 에러");
//	data[++top] = e;
//}
//
//Element pop()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top--];
//}
//
//Element peek()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top];
//}
//
//void print_stack(char msg[])
//{
//	int i;
//	printf("%s[%2d]= ", msg, size());
//	for (i = 0; i < size(); i++)
//		printf("\n\t%-15d %-10s %-20s",
//			data[i].id, data[i].name, data[i].dept);
//	printf("\n");
//}
//
//Student get_student(int id, char name[], char dept[])
//{
//	Student s;
//	s.id = id;
//	strcpy(s.name, name); //문자열 복사, s.name = name 은 오류
//	strcpy(s.dept, dept); //문자열 복사, s.dept = dept 은 오류
//	return s;
//}
//
//void main()
//{
//	int stack();
//	push(get_student(201813007, "홍길동", "컴퓨터공학과"));
//	push(get_student(201813008, "홍길동2", "컴퓨터공학과2"));
//	push(get_student(201813009, "홍길동3", "컴퓨터공학과3"));
//	push(get_student(201813010, "홍길동4", "컴퓨터공학과4"));
//
//	print_stack("친구 4명 삽입 후");
//	pop();
//	print_stack("친구 1명 삭제 후");
//}
#pragma endregion

#pragma region p.27
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 //스택 요소 저장을 위한 배열의 크기
typedef int Element; //스택 요소의 자료형 정의

Element data[MAX_STACK_SIZE]; //실제 스택 요소의 배열
int top; //실제 스택의 top

//오류 상황 처리를 위한 함수. 메세지 출력 후 프로그램 종료.
void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE; }
int size() { return top + 1; }

void push(Element e)
{
	if (is_full())
		error("스택 포화 에러");
	data[++top] = e;
}

Element pop()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top--];
}

Element peek()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top];
}

int check_matching(char expr[])
{
	int i = 0, prev;
	char ch;
	init_stack();
	while (expr[i] != '\0') {
		ch = expr[i++];
		if (ch == '[' || ch == '(' || ch == '{')
			push(ch);
		else if (ch == ']' || ch == '}' || ch == ")") {
			if (is_empty())
				return 2;

			prev = pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				return 3;
			}
		}
	}
	if (is_empty() == 0) return 1;
	return 0;
}

void main()
{
	char expr[4][80] = { "{A[(i+1)]=0;}", "if((if==0) && (j==0)",
						"A[(i+1])=0;", "A[i] = f)(;" };
	int errCode, i;

	for (i = 0; i < 4; i++) {
		errCode = check_matching(expr[i]);
		if (errCode == 0)
			printf(" 정상: %s\n", expr[i]);
		else
			printf(" 오류: %s (조건%d 위반)\n", expr[i], errCode);
	}

	}
#pragma endregion
