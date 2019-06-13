//
//  stack_2.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.
//
/* [ 문제 2 ] 스택의 응용으로 키보드로부터 입력된 한 줄의 수식문장에서 괄호 짝의 유효성을 검사하는 프로그램을 작성하세요.
    괄호짝은 { }, [ ] , ( ) 의 3 종류를 갖는다.
    주의: 수식문장은 1000개의 문자를 넘지 않는다. 수식문장은 공백문자를 포함할 수 있다. 출력은 유효하지 않으면 ‘Wrong_N’ 유효하면 ‘OK_N’를 출력한다. 여기서 N은 문장안의 괄호의 개수이다.
 
 입력 예시 1                출력 예시 1
 (3+40*(2+(30-7)*2133)      Wrong_5  */

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

void push(char value) {
    if (top >= 999) {
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

int isBalanced(char *sentence) {
    char popItem;
    
    for (int i = 0; i < strlen(sentence); i++) {
        if ((sentence[i] == '(') || (sentence[i] == '{') || (sentence[i] == '[')) {
            push(sentence[i]);
        }
        else if ((sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')) {
            if (isEmpty()) {
                return 0;
            }
            popItem = pop();
            if (sentence[i] == ')') {
                if (popItem != '(') {
                    return 0;
                }
            }
            else if (sentence[i] == '}') {
                if (popItem != '{') {
                    return 0;
                }
            }
            else if (sentence[i] == ']') {
                if (popItem != '[') {
                    return 0;
                }
            }\
        }
    }
    return isEmpty();
}


int main() {
    int count = 0;
    char *sentence = (char*)malloc(sizeof(char) * 1000);
    stack = (char*)malloc(sizeof(char) * 1000);
    top = -1;
    
    gets(sentence);
    
    for (int i = 0; i < strlen(sentence); i++) {
        if ((sentence[i] == '(') || (sentence[i] == '{') || (sentence[i] == '[') || (sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')) {
            count++;
        }
    }
    
    if (isBalanced(sentence)) {
        printf("OK_%d", count);
    }
    
    else {
        printf("Wrong_%d", count);
    }
    
    free(sentence);
    free(stack);
    
    return 0;
}
