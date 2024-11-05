#include "headers/traversal.h"

extern int BST[100];

// left -> root -> right
void inorder(int index)
{
    if (BST[index] == -1)
        return;

    inorder(2 * index);
    printf("%d ", BST[index]);
    inorder(2 * index + 1);

    // implementing without recursion
    /*
    int stack[100], top = -1;
    stack[++top] = index;
    while (top != -1) {
        int curr = stack[top--];
        if (BST[2 * curr + 1] != -1)
            stack[++top] = 2 * curr + 1;
        if (BST[2 * curr] != -1)
            stack[++top] = 2 * curr;
        printf("%d ", BST[curr]);
    }
    */
}

// root -> left -> right
void preorder(int index)
{
    if (BST[index] == -1)
        return;

    printf("%d ", BST[index]);
    preorder(2 * index);
    preorder(2 * index + 1);

    // implementing without recursion
    /*
    int stack[100], top = -1;
    stack[++top] = index;
    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", BST[curr]);
        if (BST[2 * curr + 1] != -1)
            stack[++top] = 2 * curr + 1;
        if (BST[2 * curr] != -1)
            stack[++top] = 2 * curr;
    }
    */
}

// left -> right -> root
void postorder(int index)
{
    if (BST[index] == -1)
        return;

    postorder(2 * index);
    postorder(2 * index + 1);
    printf("%d ", BST[index]);

    // implementing without recursion
    /*
    int stack[100], top = -1;
    stack[++top] = index;
    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", BST[curr]);
        if (BST[2 * curr + 1] != -1)
            stack[++top] = 2 * curr + 1;
        if (BST[2 * curr] != -1)
            stack[++top] = 2 * curr;
    }
    */

}