//
//  tree_3.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 1 ] 위에서 설명한 방식대로 트리 정보와 탐색 정보가 주어졌을 때, 트리를 생성하고 탐색 도중 방문하는 노드의 번호를 차례로 출력하는 프로그램을 작성하시오.
 
 ◦ 트리 1주차 실습에서처럼 모든 노드마다 자신의 위치를 가리키는 포인터변수를 만들어 사용하면 안 됨.
    - 오직 루트(root) 노드에 대해서만 허용. 즉, 트리는 루트 노드를 통해서만 접근 가능
 
 입력 상세:
 ◦ 트리 정보
    - 첫 째 줄에 노드의 개수 n이 주어진다.
    - 다음 n개의 줄에, 전위(선위) 순회 순서로 노드의 정보가 주어진다. (위 설명 참조)
 ◦ 탐색 정보 (트리 정보가 모두 주어진 후)
    - 탐색 횟수 s가 주어진다.
    - 다음 s개의 줄에, 탐색 정보가 주어진다. (각 탐색은 루트 노드에서 새로 시작)
    - 하나의 탐색 정보는 공백없이, ‘L’과 ‘R’로 구성된 문자열(최대 길이 100)로 주어진다.
    - 유효하지 않은 탐색 정보는 주어지지 않는다. 예를 들어, 위 트리에서 “RRR“ 과 같은 탐색 정보는 유효하지 않다. 두 번 오른쪽 자식을 따라 내려가면 노드 10인데, 노드 10의 오른쪽 자식은 정의되지 않았다.
 
 출력 상세:
 ◦ 탐색 시 방문하는 노드의 번호를 순서대로 출력한다. (하나의 줄에 한 번의 탐색 결과 출력)
 
 입력 예시 1                출력 예시 1
 9 ↦ 노드 개수              □5 9 7 12 ↦ 첫 번째 탐색 결과
 5 3 9                    □5 3 8 ↦ 두 번째 탐색 결과
 3 8 15                   □5 3 15 ↦ 두 번째 탐색 결과
 8 0 2
 2 0 0
 15 0 0
 9 7 10
 7 12 0
 12 0 0
 10 0 0
 3 ↦ 탐색 횟수
 RLL
 LL
 LR */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int number;
    struct node *left;
    struct node *right;
};

void freeTree(struct node *tree){
    if (tree == NULL) {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

void preorder(struct node *tree){
    if (tree == NULL) {
        return;
    }
    printf(" %d", tree->number);
    preorder(tree->left);
    preorder(tree->right);
}

void addLeftRight(struct node *tree, int value1, int value2, int value3){
    if (tree == NULL) {
        return;
    }
    struct node *leftchild = (struct node*)malloc(sizeof(struct node));
    struct node *rightchild = (struct node*)malloc(sizeof(struct node));
    leftchild->number = value2;
    rightchild->number = value3;
    leftchild->left = NULL;
    leftchild->right = NULL;
    rightchild->left = NULL;
    rightchild->right = NULL;
    if (tree->number == value1){
        if (value2 == 0){
            tree->left = NULL;
            free(leftchild);
        }
        else{
            tree->left = leftchild;
        }
        if (value3 == 0){
            tree->right = NULL;
            free(rightchild);
        }
        else{
            tree->right = rightchild;
        }
    }
    else{
        free(leftchild);
        free(rightchild);
    }
    addLeftRight(tree->left, value1, value2, value3);
    addLeftRight(tree->right, value1, value2, value3);
}



void search(struct node *root, char tree[100])
{
    printf(" %d", root->number);
    for (int i = 0; i < strlen(tree); i++){
        if (tree[i] == 'R'){
            root = root->right;
        }
        else if (tree[i] == 'L'){
            root = root->left;
        }
        else{
            return;
        }
        printf(" %d", root->number);
    }
    printf("\n");
}

int main(){
    
    int nodeNumber, value1, value2, value3, searchNumber;
    struct node *root, *tree = (struct node*)malloc(sizeof(struct node));
    char searchInfomation[100];
    
    root = tree;
    scanf("%d", &nodeNumber);
    
    for (int i = 0; i < nodeNumber; i++){
        scanf("%d", &value1);
        scanf("%d", &value2);
        scanf("%d", &value3);
        if (i == 0) {
            struct node *leftchild = (struct node*)malloc(sizeof(struct node));
            struct node *rightchild = (struct node*)malloc(sizeof(struct node));
            tree->number = value1;
            leftchild->number = value2;
            rightchild->number = value3;
            leftchild->left = NULL;
            leftchild->right = NULL;
            rightchild->left = NULL;
            rightchild->right = NULL;
            
            if (value2 != 0){
                root->left = leftchild;
            }
            else{
                free(leftchild);
            }
            if (value3 != 0){
                root->right = rightchild;
            }
            else{
                free(rightchild);
            }
        }
        else {
            addLeftRight(root, value1, value2, value3);
        }
    }
    scanf("%d", &searchNumber);
    for (int i = 0; i < searchNumber; i++){
        getchar();
        scanf("%s", searchInfomation);
        search(root, searchInfomation);
    }
    freeTree(root);
}
