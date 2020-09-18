// min-heap_upward.c
// 最小堆数据下调使用指针实现
#include <stdio.h>
#include <stdlib.h>
#define MAX 14

// 树节点
struct tree {
    int data;
    struct tree * left;
    struct tree * right;
};

void goDown(struct tree * node);
void swap(struct tree * x, struct tree * y);

void goDown(struct tree * node){
    struct tree * tmp;

    while (node->left != NULL){
        if (node->data > node->left->data)
            tmp = node->left;
        else
            tmp = node;
        if (node->right != NULL)
            if (tmp->data > node->right->data)
                tmp = node->right;
        if (tmp != node){
            swap(tmp, node); // 交换tmp和node指向的节点的值
            node = tmp;
        }
        else
            break;
    }
}

void swap(struct tree * x, struct tree * y){
    int t;

    t = x->data;
    x->data = y->data;
    y->data = t;
}

int main(void){
    int heap_que[100] = {0,1,2,5,12,7,17,25,19,36,99,22,28,46,92};
    int idx = 1, tmp;
    struct tree * ptr_que[100];
    int t = 1;
    struct tree * head, * ptr;

    // 创建二叉树
    head = ptr = (struct tree *)malloc(sizeof(struct tree));
    ptr->data = heap_que[idx];
    ptr_que[t++] = head;
    while (idx <= MAX){
        ptr = ptr_que[idx];
        if (idx * 2 <= MAX){
            tmp = idx * 2;
            ptr->left = (struct tree *)malloc(sizeof(struct tree));
            ptr->left->data = heap_que[tmp];
            ptr_que[t++] = ptr->left;
        } else {
            ptr->left = NULL;
        }
        if (idx * 2 + 1 <= MAX){
            tmp = idx * 2 + 1;
            ptr->right = (struct tree *)malloc(sizeof(struct tree));
            ptr->right->data = heap_que[tmp];
            ptr_que[t++] = ptr->right;
        } else {
            ptr->right = NULL;
        }
        idx++;
    }

    // 输出二叉树
    for (idx = 1; idx < t; idx++){
        printf("%d, ", ptr_que[idx]->data);
    }
    putchar('\n');
    head->data = 23; // 插入新值到堆顶
    goDown(head);
    for (idx = 1; idx < t; idx++){
        printf("%d, ", ptr_que[idx]->data);
    }
    putchar('\n');


    return 0;

}
