//p.7 배열의 복사
#include <stdio.h>

void main()
{
	int A[5] = { 10, 20, 30 };
	int B[5], i;
	int x = 2018;
	int y = 0;

	y = x;
	for (i = 0; i < 5; i++)
	{
		B[i] = A[i];
	}

	printf("변수 복사 결과: x=%d y=%d\n", x, y);
	printf("배열 복사 결과: \n");

	for (i = 0; i < 5; i++)
	{
		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d]=%d\n", i, B[i]);
	}
}

//p.10 변수의 전달, 값을 복사(call by value) 
#include <stdio.h>

void copy_variable(int a, int b)
{
	b = a;
	printf("Subprogram에서 복사한 결과: x=%d y=%d\n", a, b);
}

void main()
{
	int i;
	int x = 2018;
	int y = 0;
	copy_variable(x, y);
	printf("main함수 변수 복사 결과: x=%d y=%d\n", x, y);

}

//p.11 배열의 전달, 주소 복사(call by reference)
#include <stdio.h>

void copy_array(int a[], int b[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		b[i] = a[i]; 
	}
}

void main()
{
	int A[5] = { 10, 20, 30 };
	int B[5];
	int i;

	copy_array(A, B, 5);
	printf("배열 복사 결과: \n");
	for (i = 0; i < 5; i++)
	{
		printf("A[%d]=%d\t", i, A[i]);
		printf("B[%d]=%d\n", i, B[i]);
	}

}

//p.12 프로그램 2.2
#include <stdio.h>

void copy_array(int a[], int b[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		b[i] = a[i]; 
	}
}

void copy_variable(int a, int b)
{
	b = a;
}

void main()
{
	int A[5] = { 10, 20, 30 };
	int B[5];
	int i;
	int x = 2018;
	int y = 0;

	copy_variable(x, y); //변수 복사 실패
	copy_array(A, B, 5); //배열 복사 성

	printf("변수 복사 결과: x=%d y=%d\n ", x, y);
	printf("배열 복사 결과: \n");
	for (i = 0; i < 5; i++)
	{
		printf("A[%d]=%d\t", i, A[i]);
		printf("B[%d]=%d\n", i, B[i]);
	}

}

p.20 프로그램 2.3 복소수 - 실수부와 허수부로 
#include <stdio.h>

typedef struct {
	double real; //실수부
	double imag; //허수부
} Complex;

void print_complex(Complex c) {
	printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

void reset_complex(Complex c) {
	c.real = c.imag = 0;
}

void main()
{
	Complex a = { 1.0, 2.0 };
	printf("초기화 이전: ");
	print_complex(a);
	reset_complex(a);
	printf("초기화 이후: ");
	print_complex(a);
}

//프로그램 2.7 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree; //차수
	float coef[MAX_DEGREE]; //계수
} Polynomial;

Polynomial read_poly() {
	int i;
	Polynomial p;

	printf("다항식의 최고 차수를 입력하시오: ");
	scanf("%d", &p.degree);
	
	printf("각 항의 계수를 입력하시오 (총 %d개): ", p.degree + 1);
	for (i = 0; i <= p.degree; i++)
	{
		scanf("%f", p.coef + 1);

		return p;
	}
}

void print_poly(Polynomial p, char str[])
{
	int i;
	printf("\t%s", str);
	for (i = 0; i < p.degree; i++)
	{
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
	}
	printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial add_poly(Polynomial a, Polynomial b)
{
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++)
			p.coef[i + (p.degree - b.degree)] += a.coef[i];
	}
	return p;
}

void main()
{
	Polynomial a, b, c;
	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);
	print_poly(a, "A= ");
	print_poly(b, "B= ");
	print_poly(c, "A+B= ");
}

//프로그램 4.1 원형 큐 프로그
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;
Element data[MAX_QUEUE_SIZE];
int rear;
int front;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}
void init_queue() { rear = front = 0; }
int is_empty() { return rear == front; }
int is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
void enqueue(Element e) {
	if (is_full()) error("큐 포화 상태");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = e;
}
Element dequeue() {
	if (is_empty()) error("큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek() {
	if (is_empty()) error("큐 공백에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}
void print_queue(char msg[]) {
	int i, maxi = rear;

	if (front >= rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size());

	for (i = front+1; i <= maxi; i++)
		printf("%2d ", data[i % MAX_QUEUE_SIZE]);
	printf("\n");
}

void main() {

}

//3장 연습문제 2번
import java.util.*;
public class EEx3_22 {

	public static void main(String[] args) {
		int a; int b; 
		Scanner scan = new Scanner(System.in);
		
		System.out.print("첫번째 정수를 입력하세요!: ");
		a = scan.nextInt();
		System.out.print("두번째 정수를 입력하세요!:");
		b = scan.nextInt();
		
		if(a>b)
			System.out.println("큰 값은 "+a+" 작은 값은 "+b);
		
		else if(a == b)
			System.out.println("두 정수의 값은 같습니다.");
		
		else
			System.out.println("큰 값은 "+b+" 작은 값은 "+a);
		
		// TODO Auto-generated method stub

	}

}

public class IdentifyMyParts {
	
	public static int x=7; //클래스 변수
	public int y=3; //인스턴스 변수

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IdentifyMyParts a=new IdentifyMyParts(); //객체 a 생성
		IdentifyMyParts b=new IdentifyMyParts(); //객체 b 생성
		
		a.y=5;  
		b.y=6;  
		a.x=1;
		b.x=2;
		
		System.out.println("a.y = "+a.y);
		System.out.println("b.y = "+b.y);
		System.out.println("a.x = "+a.x);
		System.out.println("b.x = "+b.x);
		System.out.println("IdentifyMyParts.x = "+IdentifyMyParts.x);
	}

}

//덧셈 클래스
public class Add {

		int a; int b; //인스턴스 변수 2개 선언
		
		void setValue(int x, int y) {
			a=x; b=y; //매개변수로 받은 변수를 인스턴스 변수에 저장한다
		}
		int calculate() { //저장된 변수의 덧셈값을 반환
			return a+b;
		}

}

//뺄셈 클래스
public class Sub {
		int a; int b; //인스턴스 변수 2개 선언
		void setValue(int x, int y) {
			a=x; b=y; //매개변수로 받은 변수를 인스턴스 변수에 저장한다.
		}
		int calculate() { //저장된 변수의 뺄셈값을 반환
			return a-b; }

}

//나누기 클래스
public class Div {

		
		int a; int b; //인스턴스 변수
		void setValue(int x, int y) { 
			a=x; b=y; //매개변수로 받은 변수를 인스턴스 변수에 저장하는 메소드
		}
		int calculate() {
			return a/b; //저장된 변수의 나누기 값을 반환
		}	
}

#include <stdlib.h>
#includ <stdio.h>
#define MAX_LIST_SIZE 100

typedef int Element;
Element data[MAX_LISE_SIZE];
int length=0;

void init_list() {length=0;}
void clear_list() {length=0;}
int is_empty() {return length==0;}
int is_full() {return length==MAX_LIST_SIZE;}
int size() {return length;}
int get_entry(int pos) {return data[pos];}
void replace(int pos, Element e) {data[pos]=e;}

void insert(int pos, int e){
int i;
//오버헤드 삽입할 공간 만들기 맨 뒤부터 한칸씩 보내
if(is_full()==0&&pos>=0&&pos<=length){
for(i=length; i>pos; i--)
 data[i]=data[i-1];

//삽입하고 length++
data[pos]=e;
length++;
}else error("포화상태에러 또는 삽입위치오류")
}

void delete(int pos){
int i;
//오버헤드(맨 앞에서부터)
if(is_empty()==0&&pos>=0&&pos<length){
for(i=pos+1; i<length; i++)
 data[i-1]=data[i];

//length--
length--;
} else error("공백상태 에러 또는 삭제 위치 오류")
}

int find(Element e){
int i;
for(i=0;i<length;i++){
 if(data[i]==e) return i;}
return -1; 
}

void print_list(char* msg){
int i;
printf("%s[%d]= ", msg, length);
for(i=0;i<length;i++)
 printf("%d ", data[i]);
printf("\n");
}

void main() {
 init_list();
 insert(0,10);
 insert(0, 20);
 insert(1, 30);
 insert(size(), 40);
 insert(2, 50);
 print_list("배열로 구현한 list(삽입x5)");

 replace(2, 90);
 print_list("배열로 구현한 list(교체x1)");

 delete(2);
 delete(size()-1);
 delete(0);
 print_list("배열로 구현한 list(삭제x3)");

 clear_list();
 print_list("배열로 구현한 list(정리후)"); 
}

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
}Node;
Node* head = NULL;

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }
int size() {
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link) {
		count++;
	}
	return count;
}
Node* get_entry(int pos) {

	Node* p = head;
	for (int i = 0; i < pos; i++, p = p->link) {
		if (p == NULL) return NULL;
	}
	return p;
}
Node* find(Element e) {
	Node* p;
	for (p = head; p != NULL; p = p->link) {
		if (p->data == e) return p;
	}

	return NULL;
}
void replace(int pos, Element e) {
	Node* node = get_entry(pos);
	if (node != NULL)
		node->data = e;
}

void insert_next(Node* prev, Node* node) {
	if (node != NULL) {
		node->link = prev->link;
		prev->link = node;
	}
}
void insert(int pos, Element val) {
	Node* prev;
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->link = NULL;

	if (pos == 0 && is_empty()) {
		new_node->link = head;
		head = new_node;
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			insert_next(prev, new_node);
		} free(new_node);
	}
}
Node* delete_next(Node* prev) {
	Node* removed = prev->link;
	if (removed != NULL)
		prev->link = removed->link;
	return removed;
}
void delete(int pos) {
	Node* prev, * removed;
	if (pos == 0 && is_empty()) {
		removed = head;
		head = removed->link;
		free(removed);
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			removed = removed_next(prev);
			free(removed);
		}
	}
}
void clear_list() {
	while (is_empty() == 0) {
		delete(0);
	}
}
void print_list(char* msg) {
	Node* p;
	printf("%s[%d]: ", msg, size());
	for (p = head; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

void main() {
	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);
	print_list("단순연결리스트로 구현한 list(삽입x5)");

	replace(2, 90);
	print_list("단순연결리스트로 구현한 list(교체x1)");

	delete(2);
	delete(size() - 1);
	delete(0);
	print_list("단순연결리스트로 구현한 list(삭제x3)");

	clear_list();
	print_list("단순연결리스트로 구현한 list(정리후)");
}
