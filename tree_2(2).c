//
//  tree_2(2).c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.

/* [ 문제 2 ] 위 트리에 대해 폴더 id가 주어지면, 해당 폴더의 서브트리의 용량의 합을 계산하는 프
 로그램을 작성하시오. ◦ 트리 순회를 이용하여 구현
 ◦ 합을 계산할 때 입력된 노드의 용량도 포함
 ◦ 존재하지 않는 폴더 이름이 입력되는 경우 –1을 출력
 입력 예시 1        출력 예시 1
 3 ↦ 노드 id      380 ↦ 50+120+130+80
 입력 예시 2        출력 예시 2
 4 ↦ 노드 id      70 ↦ 70 (F4)
 입력 예시 3        출력 예시 3
 9 ↦ 노드         id -1                                                    */

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

int preOrder(struct node *tree){
    if (tree == NULL) {
        return 0;
    }
    return tree->data + preOrder(tree->left) + preOrder(tree->right);
}

void freeTree(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

void treeOrder(struct node *tree, int id) {
    if (tree == NULL) {
        return;
    }
    if (tree->id == id) {
        printf("%d\n",preOrder(tree));
    }
    else {
        treeOrder(tree->left, id);
        treeOrder(tree->right, id);
    }
}

int main(){
    int id;
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
    
    scanf("%d", &id);
    
    if ((1 <= id) && (id <= 8)) {
        treeOrder(root, id);
    }
    else {
        printf("-1\n");
    }
    freeTree(root);
}
