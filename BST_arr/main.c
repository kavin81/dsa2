#include <stdio.h>
#include <stdlib.h>
#include "lib/headers/main.h"

init();

int main()
{

    int choice1, choice2;
    int data, n, result, arr[MAX];

    while (choice1 != 4)
    {
        printf("\n1. Operations\n2. Properties\n3. Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice2)
        {
        case 1:
            while (choice2 != 5)
            {
                printf("\n1. Insert\n2. Delete\n3. Find\n4. Display\n5. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    printf("Enter number of elements: ");
                    scanf("%d", &n);
                    printf("Enter elements: ");
                    for (int i = 0; i < n; i++)
                        scanf("%d", &arr[i]);
                    insertFromArray(arr, n);
                    break;
                case 2:
                    printf("Enter element to delete: ");
                    scanf("%d", &data);
                    del(data);
                    break;
                case 3:
                    printf("Enter element to search: ");
                    scanf("%d", &data);
                    result = find(data, 1);
                    if (result == -1)
                        printf("Element not found\n");
                    else
                        printf("Element found\n");
                    break;
                case 4:
                    display(1, 0);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            choice2 = 0;
            break;
        case 2:
            while (choice2 != 4)
            {
                printf("\n1. countNodes\n2. countLeafNodes\n3. height\n4. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    printf("Number of nodes: %d\n", countNodes(0));
                    break;
                case 2:
                    printf("Number of leaf nodes: %d\n", countLeafNodes(0));
                    break;
                case 3:
                    printf("Height of tree: %d\n", height(0));
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            choice2 = 0;
            break;
        case 3:
            while (choice2 != 5)
            {
                printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    // left -> root -> right
                    inorder(1);
                    break;
                case 2:
                    // root -> left -> right
                    preorder(1);
                    break;
                case 3:
                    // left -> right -> root
                    postorder(1);
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            choice2 = 0;
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}