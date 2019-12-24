//
//  que_2.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.
//

/* [ 문제 2-데크 ] 데크는 큐의 전단(front)과 후단(rear)에서 모두 삽입과 삭제가 가능한 자료구조다. 헤드 노드와 테일 노드가 없는 이중연결리스트를 사용하여 
                 아래에 정의된 데크 함수들을 구현하시오.
 
 ◦ 초기 상태
    - 주의 : 연산 수행 도중 원소가 모두 삭제되어 데크가 비는 경우에도, 아래 초기 상태가 되어야 함.
 ◦ 데크 연산
    - add_front(deque, X) : deque의 앞에 원소 X를 추가 (주교재의 push와 동일).
    - add_rear(deque, X) : deque의 뒤에 원소 X를 추가 (주교재의 inject와 동일).
    - delete_front(deque) : deque의 앞에 있는 원소를 반환한 다음 삭제 (주교재의 pop과 동일).
    - delete_rear(deque) : deque의 뒤에 있는 원소를 반환한 다음 삭제 (주교재의 eject와 동일).
    - print(deque) : deque의 모든 원소들을 전단부터 후단까지 차례로 출력.
 ◦ 입출력 형식:
    1) 첫 번째 라인 : 연산의 개수 n
    2) 두 번째 이후 라인: n개의 연산이 한 줄에 하나씩 차례로 입력됨. - 하나의 줄에는 연산의 종류, 추가인 경우 원소가 주어짐 (원소는 양의 정수로 표기). 
    - 연산의 종류: 다음의 연산 이름이 대문자로 주어짐. AF (add_front), AR (add_rear), DF (delete_front), DR (delete_rear), P (print)
    ※ underflow 발생 시, 화면에 underflow를 출력하고 프로그램 종료.
 
 입력 예시 1                                출력 예시 1
 7 ↦ 연산의 개수
 AF 10 ↦ add_front(deque, 10)            □20 10 30 ↦ 4번째 연산(P)에 의한 출력
 AF 20 ↦ add_front(deque, 20)            □10 ↦ 7번째 연산(P)에 의한 출력
 AR 30 ↦ add_rear(deque, 30)
 P ↦ print(deque)
 DF ↦ delete_front(deque)
 DR ↦ delete_rear(deque)
 P ↦ print(deque) */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int element;
    struct node *next;
    struct node *prev;
};

int dequeNumber;
struct node *deque, *rear, *front;

void delete_front(){
    struct node *p;
    if (dequeNumber == 0){
        printf("underflow\n");
        exit(1);
    }
    else{
        p = front;
        if (dequeNumber == 1){
            free(p);
        }
        else{
            front = front->next;
            front->prev = NULL;
            free(p);
        }
    }
}

void delete_rear(){
    struct node *p;
    if (dequeNumber == 0) {
        printf("underflow\n");
        exit(1);
    }
    else{
        p = rear;
        if (dequeNumber == 1){
            free(p);
        }
        else{
            rear = rear->prev;
            rear->next = NULL;
            free(p);
        }
    }
}

void add_front(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->element = value;
    newnode->prev = NULL;
    newnode->next = front;
    newnode->next->prev = newnode;
    front = newnode;
}

void add_rear(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->element = value;
    newnode->prev = rear;
    newnode->next = NULL;
    newnode->prev->next = newnode;
    rear = newnode;
}

void print(){
    struct node *p = front;
    while (p != NULL){
        printf(" %d", p->element);
        p = p->next;
    }
    printf("\n");
}

void freeDeque() {
    struct node *temp = front;
    while (temp != NULL) {
        front = front->next;
        free(temp);
        temp = front;
    }
}

int main(){
    int calculateSize, value;
    char calculate[5];
    dequeNumber = 0;
    
    scanf("%d", &calculateSize);
    getchar();
    
    for (int i = 0; i < calculateSize; i++){
        scanf("%s", calculate);
        getchar();
        if (strcmp(calculate, "AF") == 0){
            scanf("%d", &value);
            getchar();
            if (dequeNumber == 0){
                deque = (struct node*)malloc(sizeof(struct node));
                deque->element = value;
                deque->next = NULL;
                deque->prev = NULL;
                front = deque;
                rear = deque;
                dequeNumber++;
            }
            else{
                add_front(value);
                dequeNumber++;
            }
        }
        else if (strcmp(calculate, "AR") == 0){
            scanf("%d", &value);
            getchar();
            
            if (dequeNumber == 0) {
                deque = (struct node*)malloc(sizeof(struct node));
                deque->element = value;
                deque->next = NULL;
                deque->prev = NULL;
                front = deque;
                rear = deque;
                dequeNumber++;
            }
            else {
                add_rear(value);
                dequeNumber++;
            }
        }
        else if (strcmp(calculate, "DF") == 0){
            delete_front();
            dequeNumber--;
        }
        
        else if (strcmp(calculate, "DR") == 0){
            delete_rear();
            dequeNumber--;
        }
        
        else if (strcmp(calculate, "P") == 0){
            print();
        }
    }
    freeDeque();
}
