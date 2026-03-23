#pragma region 프로젝트 1
//1.1차원 배열을 이용한 우선순위 큐(최대 큐:우선순위가 높은 순으로 출력)
//#include <stdio.h>
//#include <stdlib.h>
//#define	MAX_ELEMENT 100
//
////우선순위 큐 구조체 정의
//typedef struct MaxPriorityQueue {
//	int elsm[MAX_ELEMENT]; //데이터 배열
//	int size; //현재 큐 크기
//}MaxPriorityQueue;
//
//void error(char str[]) {
//	printf("%s", str);
//	error(1);
//}
////우선순위 큐 초기화
//void init(MaxPriorityQueue* pq) { pq->size = 0; }
////큐 공백검사
//int is_empty(MaxPriorityQueue* pq) {
//	return (pq->size == 0);}
//
////큐 포화검사
//int is_full(MaxPriorityQueue* pq) { 
//	return pq->size == MAX_ELEMENT+1; }
//
////삽입함수
//void insertMaxPQ(MaxPriorityQueue* pq, int val) {
//	if (is_full(pq)) error("우선순위 큐 포화 에러");
//
//	pq->elsm[pq->size] = val;
//	pq->size++;
//}
////최대 항목 삭제 함수
//int removeMaxPQ(MaxPriorityQueue* pq) {
//	if (is_empty(pq)) error("우선순위 큐 공백 에러");
//
//	int max_value=pq->elsm[0];
//	int max_index = 0;
//
//	//삭제할 가장 큰 값과 인덱스 찾기
//	for (int i = 0; i < pq->size; i++) {
//		if (pq->elsm[i] > max_value) {
//			max_value = pq->elsm[i];
//			max_index = i;
//		}
//	}
//	//삭제 후, 뒤에 있는 요소들 앞으로 한 칸씩 이동
//	for (int i = max_index; i < pq->size - 1; i++) {
//		pq->elsm[i] = pq->elsm[i + 1];
//	}
//
//	pq->size--; 
//	return max_value;
//
//}
////최대 항목 반환 함수
//int findMaxPQ(MaxPriorityQueue* pq) {
//	if (is_empty) error("우선순위 큐 공백 에러");
//
//	int max_value = pq->elsm[0];
//
//	//삭제(예정)될 가장 큰 값과 인덱스 찾기
//	for (int i = 0; i < pq->size; i++) {
//		if (pq->elsm[i] > max_value) {
//			max_value = pq->elsm[i];
//		}
//	}
//	return max_value;
//}
////모든 항목 출력
//void displayMaxPQ(MaxPriorityQueue* pq) {
//	printf(" [%2d]= ", pq->size);
//
//	for(int i=0;i<pq->size;i++)
//		printf("%2d ", pq->elsm[i]);
//}
//
//void main() {
//	MaxPriorityQueue q;
//	MaxPriorityQueue* pq = &q;
//	init(pq);
//
//	insertMaxPQ(pq, 4);
//	insertMaxPQ(pq, 20);
//	insertMaxPQ(pq, 8);
//	insertMaxPQ(pq, 10);
//	insertMaxPQ(pq, 5);
//	printf("최대 우선순위 큐 5회 삽입");
//	displayMaxPQ(pq);
//	printf("\n");
//
//	removeMaxPQ(pq);
//	removeMaxPQ(pq);
//	printf("최대 우선순위 큐 2회 삭제");
//	displayMaxPQ(pq);
//	
//}
#pragma endregion

#pragma region 프로젝트 2
//#include <stdio.h>
//#include <stdlib.h>
//
//#define Element int
//typedef struct LinkedNode {
//    Element data;
//    struct LinkedNode* link;
//} Node;
//Node* head = NULL;
//
//typedef struct {
//    Node* head;
//} List;
//
//typedef List MinPriorityQueue;
//
//void initMinPriorityQueue(MinPriorityQueue* pq) {
//    pq->head = NULL;
//}
//void insertMinPQ(MinPriorityQueue* pq, int val) // 삽입
//{
//    Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
//    newNode->data = val;
//    newNode->link = NULL;
//
//    if (pq->head == NULL || val < pq->head->data) // 우선순위 큐가 비었거나 삽입할 값이 우선순위 큐의 가장 작은 값보다 작을 경우
//    {
//        newNode->link = pq->head; // 1.head 가 가리키던 것을 삽입한 값이 가리킴
//        pq->head = newNode; // 2.head는 삽입한 값을 가리킴
//
//        // head -> [3| ]-> NULL # 기존
//        // 1 삽입
//        // head [1| ] {->} [3| ]-> NULL # 1번
//        // head {->} [1| ]-> [3| ]-> NULL # 2번
//    }
//    else {
//        Node* current = pq->head; // current 라는 노드가 head가 가리키던것을 가리킴
//        while (current->link && !(val < current->link->data)) // current 가 가리키는 값이 NULL 이 아니며, current가 가리키는 값이 삽일할 값 보다 작지 않을시 반복
//        {
//            current = current->link;
//        }
//        newNode->link = current->link;
//        current->link = newNode;
//
//        // head -> [3| ] -> [5| ] -> [8| ]->NULL
//        // 7 삽입
//        // head {->} [3| ] -> [5| ] -> [8| ]->NULL / current 는 {}
//        // 7 과 3 비교 - 7이 3보다 작지 않음 - 반복
//        // head -> [3| ] {->} [5| ] -> [8| ]->NULL / current 는 {}
//        // ...
//        // head -> [3| ] -> [5| ] {->} [8| ]->NULL / current 는 {}
//        // 7과 8 비교 - 7이 8보다 작음
//        // 이제 위의 if 문 과정을 그대로 함
//    }
//}
//int removeMinPQ(MinPriorityQueue* pq)            // 최소 항목 삭제
//{
//    if (pq->head == NULL) // 우선순위 큐가 비었을때
//    {
//        printf("Priority Queue is empty\n");
//    }
//
//    int data = pq->head->data;
//    Node* temp = pq->head;
//    pq->head = pq->head->link;
//    free(temp);
//    return data;
//}
//int findMinPQ(MinPriorityQueue* pq)              // 최소 항목 반환
//{
//    if (pq->head == NULL) {
//        printf("Priority Queue is empty\n");
//    }
//    return pq->head->data;
//}
//void displayMinPQ(MinPriorityQueue* pq)          // 모든 항목 출력
//{
//    Node* current = pq->head;
//    while (current != NULL) {
//        printf("%d ", current->data);
//        current = current->link;
//    }
//    printf("\n");
//}
//
//
//void my_fflush() { while (getchar() != '\n'); }
//
//void main() {
//    MinPriorityQueue pq;
//    int num;
//    char command;
//
//    initMinPriorityQueue(&pq);
//    insertMinPQ(&pq, 10);
//    insertMinPQ(&pq, 30);
//    insertMinPQ(&pq, 7);
//    insertMinPQ(&pq, 45);
//    insertMinPQ(&pq, 11);
//    printf("최소 우선순위 큐 5회 삽입: ");
//    displayMinPQ(&pq);
//    removeMinPQ(&pq);
//    removeMinPQ(&pq);
//    printf("최소 우선순위 큐 2회 삭제: ");
//    displayMinPQ(&pq);
//
//}
#pragma endregion
#pragma region 프로젝트 3
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_HEAP_NODE 200
//
//void print_list(int a[], int size) {
//    for (int i = 1; i < size; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//
//int isMinHeapRecur(int a[], int size, int id) {
//    if (id >= size / 2)
//        return 1;
//
//    int leftChild = 2 * id;
//    int rightChild = 2 * id + 1;
//
//    if ((leftChild < size && a[id] > a[leftChild]) || (rightChild < size && a[id] > a[rightChild]))
//        return 0;
//
//    return isMinHeapRecur(a, size, leftChild) && isMinHeapRecur(a, size, rightChild);
//}
//
//int isMaxHeapRecur(int a[], int size, int id) {
//    if (id >= size / 2)
//        return 1;
//
//    int leftChild = 2 * id;
//    int rightChild = 2 * id + 1;
//
//    if ((leftChild < size && a[id] < a[leftChild]) || (rightChild < size && a[id] < a[rightChild]))
//        return 0;
//
//    return isMaxHeapRecur(a, size, leftChild) && isMaxHeapRecur(a, size, rightChild);
//}
//
//int main() {
//    int arr1[MAX_HEAP_NODE];
//    int arr2[MAX_HEAP_NODE];
//    int arr3[MAX_HEAP_NODE];
//    int size = 11;
//
//    // -------------- 배열 1 -------------------
//    for (int i = 1, value = 0; i < size; i++, value += 10)
//        arr1[i] = value;
//
//    print_list(arr1, size);
//    if (isMinHeapRecur(arr1, size, 1))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapRecur(arr1, size, 1))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    // --------------- 배열 2 ----------------------
//    for (int i = 1, value = 100; i < size; i++, value -= 10)
//        arr2[i] = value;
//
//    print_list(arr2, size);
//    if (isMinHeapRecur(arr2, size, 1))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapRecur(arr2, size, 1))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    // --------------- 배열 3-------------------------
//    srand(time(NULL));
//    for (int i = 1; i < size; i++)
//        arr3[i] = rand() % 100;
//
//    print_list(arr3, size);
//    if (isMinHeapRecur(arr3, size, 1))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapRecur(arr3, size, 1))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    return 0;
//}

#pragma endregion

#pragma region 프로젝트 4
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_HEAP_NODE 200
//
//void print_list(int a[], int size) {
//    for (int i = 1; i < size; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//
//int isMinHeapIter(int a[], int size) {
//    for (int i = 1; i <= size / 2; i++) {
//        int leftChild = 2 * i;
//        int rightChild = 2 * i + 1;
//
//        if (leftChild < size && a[i] > a[leftChild])
//            return 0;  // Not a min heap
//
//        if (rightChild < size && a[i] > a[rightChild])
//            return 0;  // Not a min heap
//    }
//    return 1;  // Min heap
//}
//
//int isMaxHeapIter(int a[], int size) {
//    for (int i = 1; i <= size / 2; i++) {
//        int leftChild = 2 * i;
//        int rightChild = 2 * i + 1;
//
//        if (leftChild < size && a[i] < a[leftChild])
//            return 0;  // Not a max heap
//
//        if (rightChild < size && a[i] < a[rightChild])
//            return 0;  // Not a max heap
//    }
//    return 1;  // Max heap
//}
//
//int main() {
//    int arr1[MAX_HEAP_NODE];
//    int arr2[MAX_HEAP_NODE];
//    int arr3[MAX_HEAP_NODE];
//    int size = 11;
//
//    // -------------- 배열 1 -------------------
//    for (int i = 1, value = 0; i < size; i++, value += 10)
//        arr1[i] = value;
//
//    print_list(arr1, size);
//    if (isMinHeapIter(arr1, size))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapIter(arr1, size))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    // --------------- 배열 2 ----------------------
//    for (int i = 1, value = 100; i < size; i++, value -= 10)
//        arr2[i] = value;
//
//    print_list(arr2, size);
//    if (isMinHeapIter(arr2, size))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapIter(arr2, size))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    // --------------- 배열 3-------------------------
//    srand(time(NULL));
//    for (int i = 1; i < size; i++)
//        arr3[i] = rand() % 100;
//
//    print_list(arr3, size);
//    if (isMinHeapIter(arr3, size))
//        printf("해당 배열은 최소힙입니다.\n");
//    else
//        printf("해당 배열은 최소힙이 아닙니다.\n");
//
//    if (isMaxHeapIter(arr3, size))
//        printf("해당 배열은 최대힙입니다.\n\n");
//    else
//        printf("해당 배열은 최대힙이 아닙니다.\n\n");
//
//    return 0;
//}
#pragma endregion