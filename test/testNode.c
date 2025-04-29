#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *KEY;
    char *VALUE;
} CONFIGURATION_NODE;

int main()
{
    CONFIGURATION_NODE *node = (CONFIGURATION_NODE *)malloc(sizeof(CONFIGURATION_NODE));
    // char *K = (char *)malloc(10 * sizeof(char));
    // char *V = (char *)malloc(10 * sizeof(char));
    // node->KEY = K;
    // node->VALUE = V;
    node->KEY= (char *)malloc(10 * sizeof(char));
    node->VALUE = (char *)malloc(10 * sizeof(char));
    strcpy(node->KEY, "color");
    strcpy(node->VALUE, "off");
    printf("node->KEY: %s\n", node->KEY);
    printf("node->VALUE: %s\n", node->VALUE);
    free(node->KEY);
    free(node->VALUE);
    free(node);
    return 0;
}
