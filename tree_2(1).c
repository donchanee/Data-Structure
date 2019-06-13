//
//  tree_2.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.
//

/*[ 문제 1 ] 위 트리에 대해 순회 방법과 폴더 id가 주어지면, 아래의 트리의 루트노드에서 출발하
 여 해당 노드를 탐색하여 찾고, 이 노드를 시작점으로 순회하며 각 폴더의 용량을 출력하는 프로
 그램을 작성하시오.
 - 노드 id를 저장하기 위해 노드는 다음과 같은 구조체를 만들어 사용함. - 지난주 문제의 F1, F2와 같은 노드별 포인터는 사용할 수 없으며, 주어진 노드를 탐색하여 찾아
 야 함.
 입출력 상세:
 ◦ 순회 방법 종류 (입력) - 1: 전위순회, 2: 중위순회, 3: 후위순회
 ◦ 존재하지 않는 폴더 이름이 입력되는 경우 –1을 출력
 입력 예시 1 출력 예시 1
 1 2 ↦ 1: 전위순회, 노드 id □30 70 90 ↦ F2에서 전위순회 결과 */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int id;
    int data;
    struct node *left;
    struct node *right;
};

void addLeftchild(struct node *parent, int value, int id){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->id = id;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->left = newnode;
}

void addRightchild(struct node *parent, int value, int id){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->id = id;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->right = newnode;
}

void preOrder(struct node *tree){
    if (tree == NULL) {
        return;
    }
    printf(" %d", tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    inOrder(tree->left);
    printf(" %d", tree->data);
    inOrder(tree->right);
}

void postOrder(struct node *tree){
    if (tree == NULL) {
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    printf(" %d", tree->data);
}

void freeTree(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

void treeOrder(struct node *tree, int order, int id) {
    if (tree == NULL) {
        return;
    }
    if (tree->id == id) {
        if (order == 1) {
            preOrder(tree);
        }
        else if (order == 2) {
            inOrder(tree);
        }
        else if (order == 3) {
            postOrder(tree);
        }
    }
    else {
        treeOrder(tree->left, order, id);
        treeOrder(tree->right, order, id);
    }
}

int main(){
    int order, id;
    struct node *root, *p, *tree = (struct node*)malloc(sizeof(struct node));
    root = tree;
    tree->data = 20;
    tree->id = 1;
    tree->left = NULL;
    tree->right = NULL;
    addLeftchild(tree, 30, 2);
    addRightchild(tree, 50, 3);
    addLeftchild(tree->left, 70, 4);
    addRightchild(tree->left, 90, 5);
    addRightchild(tree->right, 120, 6);
    addLeftchild(tree->right->right, 130, 7);
    addRightchild(tree->right->right, 80, 8);
    
    scanf("%d", &order);
    scanf("%d", &id);
    
    if ((1 <= id) && (id <= 8)) {
        treeOrder(root, order, id);
        printf("\n");
    }
    else {
        printf("-1\n");
    }
    freeTree(root);
}
