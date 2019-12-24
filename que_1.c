//
//  que_1.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 1-큐 ] 배열로 구성된 원형 큐를 위한 삽입, 삭제 프로그램을 작성하시오. ◦ 주요 전략 : 본 문제의 원형 큐에서는 포화 상태와 공백 상태를 
        구분하기 위해 한 자리를 비워둠. - front, rear, 배열의 초기 값은 0
    - 삽입 시 rear 값을 하나 증가시킨 후 데이터를 큐에 삽입 (출력 예시 1 참고) - 삭제 시 front 값을 하나 증가시킨 후 front가 가리키는 데이터를 삭제
    - front = rear면 공백 상태로 정의하고, front가 rear보다 하나 앞에 있으면 포화 상태로 정의함
 
 ※ 주의 : 주교재가 제시하는 전략에서는 front와 rear가 각각 큐의 맨 앞과 맨 뒤의 원소 위치를 직접 가리키는 방식으로 정의되어 있으나 위 전략은 front가 
    맨 앞 원소 위치보다 한 셀 앞 위치를 가리키는 방식으로 정의되었다. 주교재의 방식으로 변경하여 작성해도 무방하지만, 초기 상태에서 맨 처음 삽입되는 
    위치는 0번이 아니고, 1번이 되어야 함 (그렇지 않으면 본 문제의 입출력 예시와 다른 결과가 나올 수 있음).
 
 ◦ 입출력 형식:
    1) 첫 번째 라인 : 양의 정수 q (원형 큐의 크기)
    ※ q 값에는 제한이 없다. 또한, 동적 할당을 사용할 것.
    2) 두 번째 라인 : 양의 정수 n (연산의 개수)
    3) 세 번째 이후 라인: n개의 연산이 차례로 입력됨.
 ※ 연산의 종류는 I (삽입), D (삭제), P (출력)
    - I 10 : 원형 큐에 원소 10을 삽입 (큐 원소는 양의 정수).
    - D : 원형 큐에서 원소를 삭제한 후 해당 배열 원소 값을 0으로 치환.
    - P : 배열 원소 전체를 차례로 화면에 출력 (입출력 예시 참조).
 ※ overflow 발생 시 (즉, 포화 상태에서 삽입을 시도한 경우), 화면에 overflow와 배열 값들을 모두 출력하고 프로그램 종료.
 ※ underflow 발생 시 (즉, 공백 상태에서 삭제를 시도한 경우), 화면에 underflow를 출력하고 프로그램 종료. */

#include<stdio.h>
#include<stdlib.h>

int *queue, queueSize, rear, front;

void printQueue() {
    for (int i = 0; i < queueSize; i++){
        printf(" %d", queue[i]);
    }
    printf("\n");
}

void enqueue(int value) {
    if ((rear + 1) % queueSize == front % queueSize){
        printf("overflow");
        printQueue();
        free(queue);
        exit(1);
    }
    rear = ++rear % queueSize;
    queue[rear] = value;
}

int dequeue() {
    int value;
    if (rear % queueSize == front % queueSize){
        printf("underflow");
        free(queue);
        exit(1);
    }
    else {
        front = (++(front)) % queueSize;
        value = queue[front - 1];
        queue[front] = 0;
        return value;
    }
}

int main(){
    char select;
    int calculateSize, value;
    rear = 0;
    front = 0;
    
    scanf("%d", &queueSize);
    queue = (int *)malloc(sizeof(int)*queueSize);
    
    for (int i = 0; i < queueSize; i++){
        queue[i] = 0;
    }
    scanf("%d", &calculateSize);
    
    for (int i = 0; i < calculateSize; i++){
        getchar();
        scanf("%c", &select);
        if (select == 'I'){
            scanf("%d", &value);
            enqueue(value);
        }
        else if (select == 'D'){
            dequeue();
        }
        else if (select == 'P'){
            printQueue();
        }
    }
    free(queue);
}



