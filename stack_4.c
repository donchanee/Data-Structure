//
//  stack_4.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 4 ] 후위로 변환된 수식을 입력받아 스택을 사용하여 계산한 후 결과 값을 출력하는 프로그램을 작성하시오
 ◦ 스택은 배열이나 연결리스트로 구현함
 ◦ 수식의 피연산자는 0에서 9사이의 정수이고, 각 수식의 최대길이는 100으로 함
 ◦ 수식의 연산자는 곱하기, 나누기, 더하기, 빼기로 구성되며, 정수 연산 수행
 - 즉, 나누기의 경우, 몫 계산
 
 ◦ 입출력에 대한 설명 (아래 입출력 예시 참조)
    1) 첫 번째 라인 : 수식의 개수
    2) 두 번째 라인 :
        - 하나의 줄에 후위수식이 공백 없이 입력됨
 
 입력 예시 1                        출력 예시 1
 4 ↦ 수식의 개수
 53*2+63+2*+ ↦ 첫 번째 수식          35 ↦ 5*3+2+(6+3)*2의 결과
 234*+ ↦ 두 번째 수식                14 ↦ 2+3*4의 결과
 72/3-42*+21*- ↦ 세 번째 수식        6 ↦ 7/2-3+4*2-2*1의 결과
 923*1+2*+ ↦ 네 번째 수식            23 ↦ 9+(2*3+1)*2의 결과*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *stack;
int top;

char pop() {
    
    if (top <= -1) {
        printf("Stack Empty\n");
        return 0;
    }
    return stack[(top)--];
}

char peek() {
    
    if (top <= -1) {
        printf("Stack Empty\n");
        return 0;
    }
    return stack[top];
}

void push(char value) {
    if (top >= 99) {
        printf("Stack FULL\n");
        return;
    }
    stack[++(top)] = value;
}

int isEmpty() {
    if ((top) == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int prec(char op)
{
    switch(op)
    {
        case '(' : case ')' : return 0;
        case '|' : return  1;
        case '&' : return  2;
        case '<' : case '>' : return 3;
        case '+' : case '-' : return 4;
        case '*' : case '/' : return 5;
        case '!' : return 6;
    }
    
    return -1;
}

void postfix (char *sentence) {
    int i;
    char ch, top_op;
    
    for(i=0;i<strlen(sentence);i++) {
        ch = sentence[i];
        
        switch (ch) {
            case '|': case '&':
            case '<' : case '>' : case'!' :
            case '+' : case '-' : case '*' : case '/' :
                while (!isEmpty() && prec(ch) <= prec(peek())) {
                    printf("%c", pop());
                }
                push(ch);
                break;
            case '(':
                push(ch);
                break;
            case ')':
                top_op = pop();
                
                while(top_op != '('){
                    printf("%c",top_op);
                    top_op= pop();
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    
    while (!isEmpty()) {
        printf("%c", pop());
    }
}

int calculate (char *sentence) {
    int i, value, a, b;
    char ch;
    
    for(i=0;i<strlen(sentence);i++) {
        ch = sentence[i];
        
        if(ch >= '0' && ch <= '9') {
            value = ch - '0';
            push(value);
        }
        else {
            b = pop();
            a = pop();
            
            switch (ch) {
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '*':
                    push(a*b);
                    break;
                case '/':
                    push(a/b);
                    break;
                default:
                    break;
            }
        }
    }
    
    return pop();
}

int main () {
    char *sentence = (char*)malloc(sizeof(char) * 100);
    stack = (char*)malloc(sizeof(char) * 100);
    top = -1;
    int i, num;
    
    scanf("%d", &num);
    for(i=0;i<num;i++) {
        scanf("%s", sentence);
        printf("%d", calculate(sentence));
        printf("\n");
    }
    
    return 0;
}

