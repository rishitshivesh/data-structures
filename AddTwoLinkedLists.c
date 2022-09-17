#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

struct LinkedList *insertAtEnd(struct LinkedList *head,int val){
    struct LinkedList *ptr,*traverse;
    traverse=head;
    ptr = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ptr->data=val;
    ptr->next=NULL;
    if(head==NULL){
        return ptr;
    }
    while(traverse->next!=NULL)
        traverse=traverse->next;
        traverse->next=ptr;
    return head;
}

void print(struct LinkedList *head){
    if(head==NULL){
        printf("\n");
        return;
    }
    else{
        printf("%d ",head->data);
        print(head->next);
    }
}

struct LinkedList *reverseList(struct LinkedList *head){
    struct LinkedList *prv,*cur,*fwd;
    cur=head;
    prv=NULL;
    while(cur!=NULL){
        fwd=cur->next;
        cur->next=prv;
        prv=cur;
        cur=fwd;
    }
    return prv;
}

struct LinkedList *newNode(int val){
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->next=NULL;
    new->data=val;
    return new;
}

struct LinkedList *addLists(struct LinkedList *first, struct LinkedList *second){
  struct LinkedList * res = NULL;
  struct LinkedList * temp;
  struct LinkedList * prev = NULL;
  int carry = 0, sum = 0;
  
  first = reverseList(first);
  second = reverseList(second);
  while (first != NULL || second != NULL) {
    sum = carry;
    sum += first != NULL ? first -> data : 0;
    sum += second != NULL ? second -> data : 0;
    if (sum >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
    sum %= 10;
    temp = newNode(sum);
    if (res != NULL) {
      prev -> next = temp;
    } else {
      res = temp;
    }
    prev = temp;
    if (first) {
      first = first -> next;
    }
    if (second) {
      second = second -> next;
    }
  }

  if (carry > 0)
    temp -> next = newNode(carry);
  return reverseList(res);

    
}

int main(){
    struct LinkedList *headA=NULL;
    struct LinkedList *headB=NULL;
    headA = insertAtEnd(headA,4);
    headA = insertAtEnd(headA,5);
    headA = insertAtEnd(headA,9);
    headB = insertAtEnd(headB,2);
    headB = insertAtEnd(headB,7);
    headB = insertAtEnd(headB,3);
    
    
    print(headA);
    print(headB);
    struct LinkedList *headC = addLists(headA,headB);
    print(headC);
}