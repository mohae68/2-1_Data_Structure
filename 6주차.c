#pragma region 프로그램4.6
//프로그램 4.6 p.155
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 100
//
//typedef int Element;
//typedef struct CircularQueue {
//	Element data[MAX_QUEUE_SIZE];
//	int front;
//	int rear;
//} Queue;
//Element data[MAX_QUEUE_SIZE];
//int rear, front;
//
//void error(char* str)
//{
//	printf("%s\n", str);
//	exit(1);
//}
//
//void init_queue(Queue* q) { q->front = q->rear = 0; }
//int is_empty(Queue* q) { return q->front == q->rear; }
//int is_full(Queue* q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }
//int size(Queue* q) { return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
//
//void enqueue(Queue* q, Element e) {
//	if (is_full(q))
//		error("큐 포화 에러");
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = e;
//}
//
//Element dequeue(Queue* q) {
//	if (is_empty(q))
//		error("큐 공백 에러");
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	return data[q->front];
//}
//
//Element peek(Queue* q) {
//	if (is_empty(q))
//		error("큐 공백 에러");
//	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//
//void print_queue(Queue* q, char msg[]) {
//	int i, maxi = q->rear;
//	if (q->front == q->rear) maxi += MAX_QUEUE_SIZE;
//	printf("%s[%d]= ", msg, size(q));
//
//	for (i = q->front + 1; i <= maxi; i++)
//		printf("%2d ", q->data[i % MAX_QUEUE_SIZE]);
//	printf("\n");
//}
//
//void main()
//{
//	int i;
//	Queue q;
//
//	init_queue(&q);
//	for (i = 1; i < 10; i++)
//		enqueue(&q, i);
//
//	print_queue(&q, "선형큐 enqueue 9회");
//	printf("\tdequeue() --> %d\n", dequeue(&q));
//	printf("\tdequeue() --> %d\n", dequeue(&q));
//	printf("\tdequeue() --> %d\n", dequeue(&q));
//	print_queue(&q, "선형큐 dequeue 3회");
//
//}
#pragma endregion

#pragma region 프로그램4.2
//프로그램 4.2 p.134
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_DEQUE_SIZE 100
//
//typedef int Element;
//Element data[MAX_DEQUE_SIZE];
//int rear;
//int front;
//
//void error(char str[]) {
//	printf("\s\n", str);
//	exit(1);
//}
//void init_deque() { front = rear = 0; }
//int is_empty() { return front == rear; }
//int is_full() { return (rear + 1) % MAX_DEQUE_SIZE == front; }
//int size() { return (rear - front + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; }
//
//void enqueue(Element e) {
//	if (is_full())
//		error("스택 포화 에러");
//	rear = (rear + 1) % MAX_DEQUE_SIZE;
//	data[rear] = e;
//}
//int dequeue() {
//	if (is_empty())
//		error("스택 공백 에러");
//	front = (front + 1) % MAX_DEQUE_SIZE;
//	return data[front];
//}
//int peek() {
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[(front + 1) % MAX_DEQUE_SIZE];
//}
//void print_queue(char msg[]) {
//	int i, maxi = rear;
//	if (front >= rear) maxi += MAX_DEQUE_SIZE;
//	printf("%s[%d]= ", msg, size());
//	for (i = front + 1; i <= maxi; i++)
//		printf("%2d ", data[i % MAX_DEQUE_SIZE]);
//	printf("\n");
//}
//void add_rear(Element e) { enqueue(e); }
//Element delete_front() { return dequeue(); }
//Element get_front() { return peek(); }
//void add_front(Element e) {
//	if (is_full())
//		error("덱 포화 에러");
//	data[front] = e;
//	front = (front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
//}
//Element delete_rear() {
//	int prev = rear;
//	if (is_empty())
//		error("덱 공백 에러");
//	rear = (rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
//	return data[prev];
//}
//Element get_rear()
//{
//	if (is_empty())
//		error("덱 공백 에러");
//	return data[rear];
//}
//void print_deque(char msg[]) { print_queue(msg); }
//void main()
//{
//	int i;
//	init_deque();
//	for (i = 1; i < 10; i++)
//	{
//		if (i % 2) add_front(i);
//		else add_rear(i);
//	}
//	print_deque("원형 덱 홀수-짝수");
//	printf("\tdelete_front() --> %d\n", delete_front());
//	printf("\tdelete_rear() --> %d\n", delete_rear());
//	printf("\tdelete_front() --> %d\n", delete_front());
//	print_deque("원형 덱 삭제-홀짝홀");
//}
#pragma endregion

#include <stdio.h>
#define MAX_QUEUE_SIZE 100

