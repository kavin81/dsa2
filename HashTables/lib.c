#include <stdio.h>
#include <stdlib.h>

#define tab_size 10

typedef struct inventory
{
    int part_id;
    int no_parts;
    int flag;
} parts;

void init(parts *p)
{
    for (int i = 0; i < tab_size; i++)
        p[i].flag = 0;
}

void insert(parts *p, int id, int no, int *count)
{
    int h_id = id % tab_size;

    if (*count == tab_size)
    {
        printf("Hash table is full\n");
        return;
    }

    h_id = id % tab_size;
    while (p[h_id].flag == 1)
        h_id = (h_id + 1) % tab_size;

    p[h_id].part_id = id;
    p[h_id].no_parts = no;
    p[h_id].flag = 1;

    (*count)++;
}

void display(parts *p)
{
    printf("\n");
    printf("Index  PartID  NoOfParts\n");
    printf("-------------------------\n");
    for (int i = 0; i < tab_size; i++)
    {
        printf("%5d", i);
        if (p[i].flag == 1)
        {
            printf("%8d%10d", p[i].part_id, p[i].no_parts);
        }
        else
        {
            printf("      --       ---");
        }
        printf("\n");
    }
    printf("\n");
}

void search(parts *p, int id, int *count)
{
    int h_id, i = 0;

    if (*count == 0)
    {
        printf("empty hash table");
        return;
    }
    h_id = id % tab_size;
    while (p[h_id].flag == 1 && i <= *count)
    {
        h_id = (h_id + 1) % tab_size;
        i++;
    }
    if (p[h_id].part_id == id)
        printf("Part ID: %d\nNo of parts: %d\n", p[h_id].part_id, p[h_id].no_parts);
    else
        printf("Part not found\n");
}

void delete(parts *p, int id, int *count)
{
    int h_id, i = 0;

    if (*count == 0)
    {
        printf("empty hash table");
        return;
    }
    h_id = id % tab_size;
    while (p[h_id].flag == 1 && i <= *count)
    {
        h_id = (h_id + 1) % tab_size;
        i++;
    }
    if (p[h_id].part_id == id)
    {
        p[h_id].flag = 0;
        (*count)--;
    }
    else
        printf("Part not found\n");
};
