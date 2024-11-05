#include <stdio.h>
#include <stdlib.h>
#include "headers/main.h"

#define MAX 100

int BST[MAX];

void init() {
    for (int i = 0; i < MAX; i++) {
        BST[i] = -1;
    }
}