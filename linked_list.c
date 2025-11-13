#include "linked_list.h"

// 노드 생성
node *create_node(element_type new_data)
{
  node *new_node = (node *)malloc(sizeof(node));

  new_node->data = new_data;
  new_node->next_node = NULL;

  return new_node;
}

// 노드 소멸
void destroy_node(node *node)
{
  // node->data는 int 타입이므로 free 불필요
  // malloc으로 할당된 node 구조체만 해제
  free(node);
}

// 노드 추가
void append_node(node **head, node *new_node)
{
  // head node가 NULL이라면 새로 추가된 node가 head가 된다
  if ((*head) == NULL)
  {
    *head = new_node;
  }
  else
  {
    // tail을 찾아서 새 노드를 연결한다
    node *tail = (*head);
    while (tail->next_node != NULL)
    {
      tail = tail->next_node;
    }
    tail->next_node = new_node;
  }
}

// 노드 삽입
void insert_after(node *current, node *new_node)
{
  new_node->next_node = current->next_node;
  current->next_node = new_node;
}

void insert_before(node **head, node *current, node *new_node)
{

  // 현재 노드가 head라면
  if ((*head) == current)
  {
    // 새로운 노드가 head가 된다
    new_node->next_node = *head;
    *head = new_node;
  }
  else
  {
    // current 바로 앞 노드를 찾아야 함
    node *prev = *head;

    while (prev != NULL && prev->next_node != current)
    {
      prev = prev->next_node;
    }

    if (prev != NULL)
    {
      new_node->next_node = current;
      prev->next_node = new_node; // 이전 노드가 새 노드를 가리키게 변경
    }
  }
}

void insert_new_head(node **head, node *new_head)
{
  if ((*head) == NULL)
  {
    (*head) = new_head;
  }
  else
  {
    new_head->next_node = (*head);
    (*head) = new_head;
  }
}

// 노드 제거 (리스트에서만 분리, 메모리 해제는 호출자가 담당)
void remove_node(node **head, node *remove)
{
  // 제거할 노드가 head라면 remove의 다음 노드가 head가 된다
  if ((*head) == remove)
  {
    *head = remove->next_node;
  }
  else
  {
    node *current = *head;
    while (current != NULL && current->next_node != remove)
    {
      current = current->next_node;
    }

    if (current != NULL)
      current->next_node = remove->next_node;
  }
  // 주의: destroy_node는 호출하지 않음 (이중 해제 방지)
  // 호출자가 remove_node 후 destroy_node를 직접 호출해야 함
}

void destroy_all_nodes(node **list)
{
  node *curr = *list;
  node *next = NULL;

  while (curr != NULL)
  {
    next = curr->next_node;  // 다음 노드 주소를 미리 저장
    destroy_node(curr);       // 현재 노드 메모리 해제
    curr = next;              // 다음 노드로 이동
  }

  *list = NULL;  // 호출자의 포인터를 NULL로 설정 (dangling pointer 방지)
}

// 노드 탐색
node *get_node_at(node *head, int location)
{
  node *current = head;

  while (current != NULL && (--location) >= 0)
  {
    current = current->next_node;
  }

  return current;
}

// 노드 개수 세기
int get_node_count(node *head)
{
  int count = 0;
  node *current = head;

  while (current != NULL)
  {
    current = current->next_node;
    count++;
  }

  return count;
}
