#include "../../include/include.h"
// #include "node.h"

N_node N_node_init(N_node n)
{
    N_node node = (N_node)checked_malloc(sizeof(*n));
    return node;
}