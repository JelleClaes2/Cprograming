#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  float x;
  float y;
  float z;
  float dist;
  struct Node *next;
  struct Node *prev;
} Node;

// Functie om een nieuw punt aan te maken in de lijst
Node *newNode(float x, float y, float z) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->x = x;
  temp->y = y;
  temp->z = z;
  temp->dist = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  temp->next = temp->prev = NULL;
  return temp;
}

// Functie om da punt in een linked list te smijten
void insertNode(Node **head_ref, Node *new_node) {
  new_node->next = *head_ref;
  if (*head_ref != NULL)
    (*head_ref)->prev = new_node;
  *head_ref = new_node;
}

// Functie om die te laten switchen van plaats in de linked list
void swapNodes(Node *a, Node *b) {
  float tempX = a->x;
  float tempY = a->y;
  float tempZ = a->z;
  float tempDist = a->dist;

  a->x = b->x;
  a->y = b->y;
  a->z = b->z;
  a->dist = b->dist;

  b->x = tempX;
  b->y = tempY;
  b->z = tempZ;
  b->dist = tempDist;
}

// Functie om die doubly linked list te sorteren door te kijken naar de
// oorsprong daarvan :))
void sortList(Node **head_ref) {
  int swapped;
  Node *ptr1;
  Node *lptr = NULL;

  if (head_ref == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = *head_ref;

    while (ptr1->next != lptr) {
      if (ptr1->dist > ptr1->next->dist) {
        swapNodes(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

// Functie om de mediaan van de doubly linked list te vinden
Node *findMedian(Node *head) {
  Node *slow_ptr = head;
  Node *fast_ptr = head;

  while (fast_ptr != NULL && fast_ptr->next != NULL) {
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
  }

  return slow_ptr;
}

// Functie om de oorsprong bij te werken en punt coordinaten aan te passen
void updateOrigin(Node **head_ref) {
  Node *temp = *head_ref;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  int mid = count / 2;
  temp = *head_ref;
  while (mid--) {
    temp = temp->next;
  }
  float new_origin_x = temp->x;
  float new_origin_y = temp->y;
  float new_origin_z = temp->z;

  temp = *head_ref;
  while (temp != NULL) {
    temp->x -= new_origin_x;
    temp->y -= new_origin_y;
    temp->z -= new_origin_z;
    temp->dist = sqrt(pow(temp->x, 2) + pow(temp->y, 2) + pow(temp->z, 2));
    temp = temp->next;
  }
}

// Functie om de inhoud van de doubly linked list af te drukken
void printList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("(%.2f, %.2f, %.2f)\n", temp->x, temp->y, temp->z);
    temp = temp->next;
  }
}

int main() {
  Node *head = NULL;

  // Voeg punten toe aan de doubly linked list
  insertNode(&head, newNode(1.0, 2.0, 3.0));
  insertNode(&head, newNode(4.0, 5.0, 6.0));
  insertNode(&head, newNode(7.0, 8.0, 9.0));

  printf("Before sorting:\n");
  printList(head);
  sortList(&head);

  printf("After sorting:\n");
  printList(head);
  Node *median = findMedian(head);
  printf("Median: (%.2f, %.2f, %.2f)\n", median->x, median->y, median->z);
  updateOrigin(&head);

  printf("After updating origin:\n");
  printList(head);

  return 0;
}
