#include "headers/properties.h"

extern int BST[100];

int countNodes(int count)
{
    if (BST[count] == -1)
        return 0;
    return countNodes(2 * count) + countNodes(2 * count + 1) + 1;
}

int countLeafNodes(int count)
{
    if (BST[count] == -1)
        return 0;

    int
        left = 2 * count,
        right = 2 * count + 1;

    if (BST[left] == -1 && BST[right] == -1)
        return 1;

    return countLeafNodes(left) + countLeafNodes(right);
}

int height(int count)
{
    if (BST[count] == -1)
        return 0;

    int
        left = 2 * count,
        right = 2 * count + 1;

    int leftHeight = height(left);
    int rightHeight = height(right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
