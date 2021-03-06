//
//  stack_1.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 1 ] 다음의 스택 ADT를 배열로 구현하고 테스트하는 프로그램을 작성하세요
 ◦ 데이터: 영문자
 ◦ 다음의 연산을 지원해야 함
    - push(stack, ‘c’) : stack의 top에 데이터를 추가한다. stack이 이미 꽉 차있으면 해당 데이터 는 스택에 저장하지 않고 “Stack FULL”을 출력한다.
    - pop (stack) : stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. stack이 비어 있으면 “Stack Empty”를 출력한다.
    - peek(stack): stack의 top에 있는 데이터를 화면에 출력한다. stack은 변화하지 않는다. stack이 비어 있으면 “Stack Empty”를 출력한다.
    - duplicate(stack): stack의 top에 있는 데이터를 pop해서 두 번 push 한다. stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
    - upRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 
    저장되어 있으면 데이터를 하나씩 위쪽으로 이동시킨다. 맨 위쪽 (top)의 std1은 n-1번 아래쪽으로 이동해서 스택의 결과는 elem2, elem3, elem1, ...이된다. 
    단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
    - downRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, ...이 
    저장되어 있으면 데이터를 하나씩 d 아래쪽으로 이동시킨다. top에서부터 n번째의 데이터는 top으로 이동해서, 스택의 결과는 elem3, elem1, elem2, ...이된다.    
    단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다. - print(stack) : stack의 모든 데이터를 top에서부터 순서대로 공간없이 출력한다.
 
 ◦ 입력에 대한 설명 (아래 입출력 예시 참조)
    - 각 연산의 내용이 한 줄에 하나씩 입력되고, 하나의 줄에는 연산의 종류와 그에 필요한 데이터가 입력된다.
    - 연산의 종류: 각 연산 이름은 POP, PUSH , PEEK, DUP, UpR, DownR, PRINT로 주어진다. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stackSize, top;

void push(char *stack, char value){
    if (top >= stackSize - 1){
        printf("Stack FULL\n");
        return;
    }
    stack[++(top)] = value;
}

char pop(char *stack){
    if (top <= -1){
        printf("Stack Empty\n");
        return;
    }
    return stack[(top)--];
}

void peek(char *stack){
    if (top <= -1){
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", stack[top]);
}

void duplicate(char *stack){
    if (top >= stackSize){
        printf("Stack FULL\n");
        return;
    }
    push(stack,pop(stack));
    push(stack,stack[top]);
}

void upRotate(char *stack, int number){
    char *tempArray = (char*)malloc(sizeof(char)*number);
    if (number > (top + 1)) {
        free(tempArray);
        return;
    }
    for (int i = 0; i < number; i++) {
        tempArray[i] = pop(stack);
    }
    push(stack, tempArray[0]);
    for (int i = number - 1; i > 0; i--) {
        push(stack, tempArray[i]);
    }
    free(tempArray);
}

void downRotate(char *stack, int number){
    char *tempArray = (char*)malloc(sizeof(char)*number);
    if (number > (top + 1)) {
        free(tempArray);
        return;
    }
    for (int i = 0; i < number; i++) {
        tempArray[i] = pop(stack);
    }
    for (int i = number - 2; i > -1; i--) {
        push(stack, tempArray[i]);
    }
    push(stack, tempArray[number - 1]);
    free(tempArray);
}

void print(char *stack){
    for (int i = (top); i > -1; i--){
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main(){
    
    int calculateSize, number;
    char *stack, calculate[10], value;
    
    scanf("%d", &stackSize);
    stack = (char*)malloc(sizeof(char)*stackSize);
    top = -1;
    
    scanf("%d", &calculateSize);
    getchar();
    
    for (int i = 0; i < calculateSize; i++){
        scanf("%s", calculate);
        getchar();
        
        if (strcmp(calculate, "PUSH") == 0){
            scanf("%c", &value);
            getchar();
            push(stack, value);
        }
        else if (strcmp(calculate, "POP") == 0){
            pop(stack);
        }
        else if (strcmp(calculate, "PEEK") == 0){
            peek(stack);
        }
        else if (strcmp(calculate, "DUP") == 0){
            duplicate(stack);
        }
        else if (strcmp(calculate, "UpR") == 0){
            scanf("%d", &number);
            getchar();
            upRotate(stack, number);
        }
        else if (strcmp(calculate, "DownR") == 0){
            scanf("%d", &number);
            getchar();
            downRotate(stack, number);
        }
        else if (strcmp(calculate, "PRINT") == 0){
            print(stack);
        }
    }
    free(stack);
}
