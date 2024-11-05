#include "headers/operations.h"

extern int BST[100];

void insert(int data, int index)
{
    // empty tree
    if (BST[index] == -1)
        BST[index] = data;
    // less than root -> left subtree
    else if (data < BST[index])
        insert(data, 2 * index);
    // greater than root -> right subtree
    else
        insert(data, 2 * index + 1);
}

void insertFromArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        insert(arr[i], 1);
}

void del(int data)
{
    printf("Delete not implemented\n");
}

// root node is at index 1 , to search from root node call `find(data, 1)`
int find(int data, int index)
{
    // empty tree case
    if (BST[index] == -1)
        return -1;
    // traverse left subtree if data is less than root
    else if (data < BST[index])
        return find(data, 2 * index);
    // traverse right subtree if data is greater than root
    else if (data > BST[index])
        return find(data, 2 * index + 1);
    else
        return 1; // element found
}

void display(int index, int level)
{
    if (BST[index] == -1)
        return;

    display(2 * index + 1, level + 1); // right child

    // space increase for each level
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", BST[index]);

    display(2 * index, level + 1); // left child
}