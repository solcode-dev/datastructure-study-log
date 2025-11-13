#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

typedef struct tag_node
{
  element_type data;
  struct tag_node *next_node;
} node;

// 함수 원형 선언
node *create_node(element_type data);
void destroy_node(node *node);
void append_node(node **head, node *new_node);
void insert_new_head(node **head, node *new_head);
void insert_after(node *current, node *new_node);
void insert_before(node **head, node *current, node *new_head);
void destroy_all_nodes(node **list);
void remove_node(node **head, node *remove);
node *get_node_at(node *head, int location);
int get_node_count(node *head);

#endif