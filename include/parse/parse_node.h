#ifndef PARSER_NODE_H
#define PARSER_NODE_H
/**
 * func descp: 本阶段针对语法报错，不针对语义报错，语义报错在执行阶段，比如典型的id越界、id不存在等
 */
#include "../include.h"

void parse_node(N_node node, C_command command, T_date date);

#endif