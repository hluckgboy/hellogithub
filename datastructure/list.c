#include <stdio.h>
#include <stdlib.h>

/**
 * @brief node type
 *
 * @param 节点值val,链接的下一个节点next
 */
typedef struct Node {
  int val;
  struct Node *next;
} Node;

/**
 * @brief init node
 *
 * @param 节点值val
 *
 * @return 返回值：初始化之后的节点
 */
Node *init_node(int val) {
  Node *tmpNode = (Node *)malloc(sizeof(Node));
  tmpNode->val = val;
  tmpNode->next = NULL;
  return tmpNode;
}

/**
 * @brief add node
 *
 * @param
 * 链表的头节点head,要添加到链表尾或者头的节点node，头或尾的标志flag【0为头】
 *
 */
void add_node(Node *head, Node *node, int flag) {
  if (flag == 0) {
    node->next = head->next;
    head->next = node;
  } else {
    Node *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = node;
  }
}

/**
 * @brief insert node
 *
 * @param 源节点snode,目的基点dnode;
 */
void insert_node(Node *snode, Node *dnode) {
  if (dnode->next != NULL) {
    Node *tmp = dnode->next;
    dnode->next = snode;
    snode->next = tmp;
  } else {
    dnode->next = snode;
  }
}

/**
 * @brief delete node
 *
 * @param 要删除的节点的前节点node
 */
void delete_node(Node *node) {
  if (!node->next) {
    return;
  }
  Node *tmp = node->next;
  node->next = node->next->next;
  free(tmp);
}

/**
 * @brief search node
 *
 * @param 节点的值val，链表头节点head
 *
 * @return 返回值：返回首个索引,失败返回-1
 */
int search_node(int val, Node *head) {
  int index = 0;
  Node *tmp = head;
  while (!tmp->next) {
    if (tmp->val == val) {
      return index;
    }
    tmp = tmp->next;
    index++;
  }
  return -1;
}

/**
 * @brief traverse list
 *
 * @param 链表头结点head
 */
void traverse_node(Node *head) {
  printf("here is some thing\n");
  Node *tmp = head;
  while (tmp->next) {
    printf("%d\t", tmp->val);
    tmp = tmp->next;
  }
}

/**
 * @brief access node
 * @details 访问节点索引为index的节点
 * @param 链表头结点head,索引index
 */
void access_node(Node *head, int index) {
  Node *tmp = head;
  for (int i = 0; i < index; i++) {
    tmp = tmp->next;
  }
  printf("node value is:%d\n", tmp->val);
}

int main(int argc, char **argv) {
  Node *head = init_node(1);
  Node *tmp = NULL;
  tmp = head;
  for (int i = 2; i < 6; i++) {
    tmp->next = init_node(i);
    tmp = tmp->next;
  }
  printf("head value is %d", head->val);
  traverse_node(head);
  search_node(3, head);
  access_node(head, 2);
  return 0;
}