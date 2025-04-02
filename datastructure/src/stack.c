#include <stdio.h>
#include <stdlib.h>

/*构造链表节点和栈节点*/
typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct {
  Node *pop;
  int size;
} LinkNode;

/**
 * @brief 构造头结点
 */
LinkNode *generate_node() {
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->pop = NULL;
  s->size = 0;
  return s;
}

/**
 * @brief 删除节点，这里注意的是从头部开始删
 */
void del_node(LinkNode *s) {
  while (s->pop) {
    Node *tmp = s->pop->next;
    free(s->pop);
    s->pop = tmp;
  }
}

/**
 * @brief 获取栈的大小
 * @param 栈头s
 * @return 返回值：栈的大小
 */
int get_stack_size(LinkNode *s) { return s->size; }

/**
 * @brief 判断栈是否为空
 * @param 栈头s
 * @return 返回值：空为0，否则为-1；
 */
int is_stack_empty(LinkNode *s) {
  if (s->size == 0) {
    return 0;
  }
  return -1;
}

/**
 * @brief 访问栈顶元素
 * @param 栈头s
 */
void access_stack(LinkNode *s) {
  printf("the value of head is %d\n", s->pop->val);
}

/**
 * @brief 入栈
 * @param 栈头s,需要入栈的值num
 */
void push_stack(LinkNode *s, int num) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->next = s->pop;
  tmp->val = num;
  s->pop = tmp;
  s->size++;
}

/**
 * @brief 出栈
 * @param 栈头s
 */
void pop_stack(LinkNode *s) {
  Node *tmp;
  tmp = s->pop;
  s->pop = s->pop->next;
  printf("要取出栈的元素是：%d\n", tmp->val);
  free(tmp);
  tmp = NULL;
  s->size--;
}

/**
 * @brief 遍历栈
 * @param 栈头s
 */
void traverse_stack(LinkNode *s) {
  Node *tmp;
  tmp = s->pop;
  while (tmp->next) {
    printf("%d\t", tmp->val);
    tmp = tmp->next;
  }
  printf("%d\n", tmp->val);
}

/**
 * @brief 程序入口
 */
int main(int argc, char **argv) {
  LinkNode *head = generate_node();
  for (int i = 0; i < 5; i++) {
    push_stack(head, i);
  }
  int j = get_stack_size(head);
  printf("栈的大小是：%d\n", j);

  j = is_stack_empty(head);
  if (j == 0) {
    printf("栈为空\n");
  } else {
    printf("栈不为空\n");
  }
  traverse_stack(head);
  pop_stack(head);
  return 0;
}