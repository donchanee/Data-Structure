//
//  stack_3.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 3 ] 스택을 이용하여 중위수식을 후위수식으로 변환하는 프로그램을 작성하시오
 ◦ 스택은 배열이나 연결리스트로 구현함
 ◦ 수식의 피연산자는 영문자(대문자)로 나타내고, 각 수식의 최대길이는 100으로 함
 ◦ 수식은 아래 우선순위를 갖는 연산자들을 포함함 (숫자가 높을수록 우선순위가 높음)
 
 입력토큰 연산자 우선순위
 ! + - 단항연산자 6
 * 곱셈 5
 / 나눗셈 5
 + 덧셈 4
 - 뺄셈 4
 > 관계연산자 3
 < 관계연산자 3
 && 논리연산자(AND) 2
 || 논리연산자(OR) 1
 
 ◦ 같은 우선순위를 갖는 연산자들은 왼쪽에서 오른쪽으로 계산하도록 함
 ◦ 입출력에 대한 설명 (아래 입출력 예시 참조)
 1) 첫 번째 라인 : 수식의 개수
 2) 두 번째 라인 :
 - 하나의 줄에 수식이 공백 없이 입력됨
 
 입력 예시 1                        출력 예시 1
 5 ↦ 수식의 개수
 A*B+C+(D+E)*F ↦ 첫 번째 수식        AB*C+DE+F*+
 A+B*C ↦ 두 번째 수식                ABC*+
 A/B-C+D*E-F*G ↦ 세 번째 수식        AB/C-DE*+FG*-
 A+(B*C+D)*E ↦ 네 번째 수식          ABC*D+E*+
 A&&B||C||!(E>F) ↦ 다섯 번째 수식     AB&&C||EF>!||*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stackSize, top, sign;

void push(char *stack, char value) {
    stack[++(top)] = value;
}

char pop(char *stack) {
    return stack[(top)--];
}

int operand(char *inArray, int i){
    if ((top != i) && (i == 0) && ((inArray[i] == '+') || (inArray[i] == '-'))){
        sign = 1;
        return 6;
    }
    else if ((top != -1) && ((inArray[i] == '+') || (inArray[i] == '-')) && ((inArray[i - 1] == '|') || (inArray[i - 1] == '&') || (inArray[i - 1] == '<') || (inArray[i - 1] == '>') || (inArray[i - 1] == '-') || (inArray[i - 1] == '+') || (inArray[i - 1] == '*') || (inArray[i - 1] == '/') || (inArray[i - 1] == '!'))){
        return 6;
    }
    else if (inArray[i] == '|'){
        return 1;
    }
    else if (inArray[i] == '&'){
        return 2;
    }
    else if (inArray[i] == '>' || inArray[i] == '<'){
        return 3;
    }
    else if (inArray[i] == '+' || inArray[i] == '-'){
        return 4;
    }
    else if (inArray[i] == '*' || inArray[i] == '/'){
        return 5;
    }
    else if (inArray[i] == '!'){
        return 6;
    }
    else{
        return 0;
    }
}

int main(){
    
    int calculateSize, number;
    char inArray[100], outArray[100], stack[100];
    
    scanf("%d", &calculateSize);
    getchar();
    
    for (int i = 0; i < calculateSize; i++){
        number = 0;
        top = -1;
        sign = 0;
        for (int j = 0; j < 100; j++){
            outArray[j] = '\0';
            stack[j] = '\0';
        }
        scanf("%s", inArray);
        getchar();
        
        for(int j = 0; j < strlen(inArray); j++){
            if (inArray[j] == '('){
                push(stack, inArray[j]);
            }
            else if (inArray[j] == ')'){
                while (stack[top] != '('){
                    outArray[number++] = pop(stack);
                }
                pop(stack);
            }
            else if (operand(inArray, j) == 6){
                push(stack, inArray[j]);
            }
            else if (operand(inArray, j) == 0){
                outArray[number++] = inArray[j];
            }
            else{
                if (sign == 1){
                    outArray[number++] = pop(stack);
                }
                else{
                    while ((top != -1) && (operand(inArray, j) <= operand(stack,top))){
                        outArray[number++] = pop(stack);
                    }
                }
                if ((operand(inArray,j) == 1) || (operand(inArray, j) == 2)){
                    push(stack, inArray[j++]);
                }
                push(stack, inArray[j]);
            }
        }
        while (top != -1){
            outArray[number++] = pop(stack);
        }
        printf("%s\n", outArray);
    }
}

