#pragma region 실습1
//p.31 프로그램3.4
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef double Element; //스택 요소의 자료형 정의
//
//Element data[MAX_STACK_SIZE];
//int top;
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
//double calc_postfix(char expr[])
//{
//	char c;
//	int i = 0;
//	double val, val1, val2;
//
//	init_stack();
//
//	while(expr[i] != '\0') {
//		c = expr[i++];
//		if (c >= '0' && c <= '9') {
//			val = c - '0';
//			push(val);
//		}
//		else if (c == '+' || c == '-' || c == '*' || c == '/') {
//			val2 = pop();
//			val1 = pop();
//			switch(c) {
//				case '+': push(val1 + val2); break;
//				case '-': push(val1 - val2); break;
//				case '*': push(val1 * val2); break;
//				case '/': push(val1 / val2); break;
//			}
//		}
//	}
//	return pop();
//}
//
//void main()
//{
//	char expr[2][80] = { "8 2 / 3 - 3 2 * +", "1 2 / 4 * 1 4 / *" };
//
//	printf("수식: %s = %lf\n", expr[0], calc_postfix(expr[0]));
//	printf("수식: %s = %lf\n", expr[1], calc_postfix(expr[1]));
//}
#pragma endregion

//p.107 프로그램 3.5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 101

typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void error(char str[]) { printf("%s\n", str); }
void init_stack() { top = -1; }
int size() { return top + 1; }
int is_full() { return(top == MAX_STACK_SIZE - 1); }
int is_empty() { return (top == -1); }
Element pop() {
	if (is_empty())
		error("스택 공백 에러");
	return data[top--];
}
Element peek() {
	if (is_empty())
		error("스택 공백 에러");
	return data[top];
}
Element push(Element e) {
	if (is_full())
		error("스택 포화 에러");
	return data[++top] = e;
}

int precedence(char op) //우선순위가 높을 수록 리턴값 큼
{
	switch (op) {
	case '(': case ')': return 0; //제일 낮은 연산자
	case '+': case '-': return 1;
	case '*': case '/': return 2; //가장 높은 연산자
	}
}

void Infix_to_Postfix(char expr[]) {
	int i = 0;
	char c, op;

	init_stack();
	while (expr[i] != '\0') {
		c = expr[i++];
		if (c >= '0' && c <= '9') {
			printf("%c ", c);
		}
		else if (c == '(')
			push(c);
		else if (c == ')') {
			while (is_empty() == 0) {
				op = pop();
				if (op == '(') break;
				else printf("%c ", op);
			}

		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (is_empty() == 0) {
				op = peek(); //top 엿보기
				if (precedence(c) <= precedence(op)) {
					printf("%c ", op);
				}
				else break;
			}
			push(c);
		}

	}
	while (is_empty() == 0) {
		printf("%c ", pop());
	}
	printf("\n");
}

int main()
{
	char expr[2][80] = { "8 / 2 - 3 + (3*2)", "1 / 2 * 4 * (1 / 4)" };

	printf("중위수식: %s ==> 후위수식:", expr[0]);
	Infix_to_Postfix(expr[0]);

	printf("중위수식: %s ==> 후위수식:", expr[1]);
	Infix_to_Postfix(expr[1]);

	return 0;
}