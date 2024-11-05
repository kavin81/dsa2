#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

int main()
{
    int ch, id, no, count = 0;
    parts ht[tab_size];
    init(ht);

    while(ch != 5)
    {
        printf("\n1. Insert\n2. display\n3. Search\n4. delete\n5. exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter part ID and number of parts: ");
            scanf("%d %d", &id, &no);
            insert(ht, id, no, &count);
            break;
        case 2:
            display(ht);
            break;
        case 3:
            printf("enter the part id u want to search");
            scanf("%d", &id);
            search(ht, id, &count);

        case 4:
            printf("Enter the part id to delete: ");
            scanf("%d", &id);
            delete(ht, id, &count);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}