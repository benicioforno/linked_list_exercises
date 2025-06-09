#include <stdio.h>
#include <stdlib.h>

struct list {
  int value;
  struct list *next;
};

typedef struct list List;

List *insert(List *l, int value);

void print(List *l);

int main() {
  List *myList = NULL;

  myList = insert(myList, 3);
  print(myList);

  myList = insert(myList, 2);
  print(myList);

  myList = insert(myList, 1);
  print(myList);
  return 0;
}

List *insert(List *l, int value) {
  List *current = l;
  List *previous = NULL;
  while (current != NULL && value > current->value) {
    previous = current;
    current = current->next;
  }

  // Insert in beggining
  List *newNode = (List *)malloc(sizeof(List));
  newNode->value = value;
  newNode->next = current;
  if (previous == NULL)
    return newNode;
  else {
    previous->next = newNode;
    return l;
  }
}

void print(List *l) {
  List *current = l;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("\n");
}
