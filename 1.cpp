#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int number;
  Node *next;
} *head, *tail;
Node *createNode(int number) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->number = number;
  newNode->next = NULL;
  return newNode;
}
void push(Node** head, int number) {
    Node* node = (Node*) malloc(sizeof(Node)); 
    node->number = number; 
    node->next = *head; 
    *head = node; 
}
void printLinkedList(Node* head) {
  Node *curr = head;                                  
  while(curr) {
    printf("%d -> ", curr->number);
    curr = curr->next;
  }
  puts("NULL");
}
Node* merge(Node* l, Node* r) 
{ 
    if (!l) return r;
    if (!r) return l;

    if (l->number < r->number) { 
        l->next = merge(l->next, r); 
        return l; 
    }
    else { 
        r->next = merge(l, r->next); 
        return r;
    } 
} 
int main(){
  Node *head1 = NULL, *head2 = NULL;
  push(&head1, 5);
  push(&head1, 3);
  push(&head1, 1);
  push(&head2, 6);
  push(&head2, 4);
  push(&head2, 2);
  Node *sorted = merge(head1,head2);
  printLinkedList(sorted);
}
