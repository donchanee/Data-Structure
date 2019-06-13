//
//  tree_1.c
//  Hello World!
//
//  Created by 설동찬 on 13/06/2019.
//  Copyright © 2019 설동찬. All rights reserved.
//

/* [ 문제 1 ] 위 트리를 연결리스트를 이용해서 구현하고, 주어진 노드에 대해 자신과 왼쪽 자식, 우측 자식의 용량을 순서대로 출력하시오.
 ※ 참고사항: 실습 및 테스트 용이성을 위해 본 문제에서는 고정된 트리를 사용하지만, 일반적으로 동적으로 삽입, 삭제 가능한 트리를 사용함
 
 ◦ 루트노드 삽입 함수를 만들어 사용하며, data(폴더 용량), left (왼쪽 자식 링크), right (오른쪽 자식 링크) 를 인수로 받음.
 ◦ 모든 노드는 아래 그림과 같이 자신의 위치를 가리키는 포인터변수를 만들어 사용함.
 ◦ 단말 노드부터 생성하고, 부모노드를 붙여가는 방식으로 트리를 구성함. - 예를 들어, F7과 F8을 생성하고, 이를 이용해 F6 생성하여 F6, F7, F8로 구성된 트리 생성
    - 비슷한 방법으로 트리를 확장해 나감
 
 출력:
 ◦ 자식 및 노드 존재 여부에 따라 출력 내용이 달라짐
    - 한쪽 자식만 존재하는 경우, 자신과 해당 자식 노드의 용량 2개 값만 출력
    - 자식 노드가 없는 경우, 자신의 용량 1개 값만 출력
    - 존재하지 않는 노드번호가 입력되는 경우 –1을 출력
 
 입력 예시 1                출력 예시 1
 2 ↦ 노드번호 (F2을 의미)     30 70 90 ↦ 자신, 왼쪽, 오른쪽 순으로 출력 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void addLeftchild(struct node *parent, int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->left = newnode;
}

void addRightchild(struct node *parent, int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->right = newnode;
}

int main() {
    int number;
    struct node *root = (struct node*)malloc(sizeof(struct node));
    struct node *F[8];
    
    root->data = 20;
    root->left = NULL;
    root->right = NULL;
    
    addLeftchild(root, 30);
    addRightchild(root, 50);
    addLeftchild(root->left, 70);
    addRightchild(root->left, 90);
    addRightchild(root->right, 120);
    addLeftchild(root->right->right, 130);
    addRightchild(root->right->right, 80);
    
    F[0] = root;
    F[1] = root->left;
    F[2] = root->right;
    F[3] = root->left->left;
    F[4] = root->left->right;
    F[5] = root->right->right;
    F[6] = root->right->right->left;
    F[7] = root->right->right->right;
    
    scanf("%d", &number);
    
    for (int i = 0; i < 8; i++) {
        if (i == number - 1) {
            printf("%d", F[i]->data);
            if (F[i]->left != NULL) {
                printf(" %d", F[i]->left->data);
            }
            if (F[i]->right != NULL) {
                printf(" %d", F[i]->right->data);
            }
            printf("\n");
            break;
        }
        if (i == 7) {
            printf("-1\n");
        }
    }
    for (int i = 0; i < 8; i++) {
        free(F[i]);
    }
    
    return 0;
}
