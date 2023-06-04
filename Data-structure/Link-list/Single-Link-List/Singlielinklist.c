#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void print_list(struct Node *ptr) {

  printf("Elements in List are ");
  while (ptr) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void add_begin(struct Node **ptr, int data) {

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  newNode->next = *ptr;
  *ptr = newNode;
}

void add_middle(struct Node **ptr, int data) {

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *tmpNode;
  newNode->data = data;

  if (*ptr == 0 || newNode->data < (*ptr)->data) {
    newNode->next = *ptr;
    *ptr = newNode;
  } else {
    tmpNode = *ptr;
    while (tmpNode) {
      if (tmpNode->next == 0) {
        newNode->next = tmpNode->next;
        tmpNode->next = newNode;
        break;
      }
      if (tmpNode->next->data > newNode->data) {
        newNode->next = tmpNode->next;
        tmpNode->next = newNode;
        break;
      }
      tmpNode = tmpNode->next;
    }
  }
}

void add_end(struct Node **ptr, int data) {

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *prevNode;
  newNode->data = data;

  if (*ptr == NULL) {
    newNode->next = *ptr;
    *ptr = newNode;
  } else {
    prevNode = *ptr;

    while (prevNode->next)
      prevNode = prevNode->next;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
  }
}

void delete_node(struct Node **ptr) {

  int num;
  printf("Enter element you want to delete(int)\n");
  scanf("%d", &num);

  printf("Deleted Node is %d", num);
  struct Node *currNode = *ptr;
  struct Node *prevNode = NULL;

  while (currNode) {

    if (currNode->data == num) {
      if (currNode == *ptr) {
        *ptr = currNode->next;
        free(ptr);
      } else {
        prevNode->next = currNode->next;
        free(currNode);
      }
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  printf("\n");
}

void freeMemory(struct Node *hptr) {

  struct Node *tmpNode;
  while (hptr) {
    tmpNode = hptr;
    hptr = hptr->next;
    free(tmpNode);
  }
}
/*
int countNumberOfNode(struct Node *hptr)
{

	int count = 0;
	while(hptr)
	{
		count++;
		hptr = hptr->next;	
	}
	
	return count;

}

void reverse_data(struct Node *hptr)
{
        struct Node *tmpNode = hptr;
        int countNode = countNumberOfNode(tmpNode);
        printf("Count :: %d\n", countNode);

        int middleCount = (countNode/2);

        struct Node *middleNode = hptr;
        for(int i = 0; i < middleCount; i++){
                        middleNode = middleNode->next;
        }

        int temp;
        struct Node *firstNode = hptr;
        struct Node *lastNode = NULL;
        for(int i = 0; i < middleCount; i++){

                  lastNode = middleNode;
                  for(int j = 0; j < (middleCount - i - 1); j++){
                                lastNode = lastNode->next;
                  }

                  temp = lastNode->data;
                  lastNode->data = firstNode->data;
                  firstNode->data = temp;

                  firstNode = firstNode->next;
        }

}
*/
int main() {
  struct Node *hptr = 0;
  char ch;
  int num, n;

  do {

    printf("Select \n1) add_begin\n2) add_middle\n3) add_end\n4) delete\n5) "
           "printlist\n");
    scanf("%d", &n);

    //    printf("Do you want to add element \n");
    //    scanf(" %c", &ch);

    if (n == 1) {
      /* Elements in List are 55 44 33 22 11 */

      add_begin(&hptr, 11);
      add_begin(&hptr, 22);
      add_begin(&hptr, 33);
      add_begin(&hptr, 44);
//      add_begin(&hptr, 55);
    } else if (n == 2) {
      /* Elements in List are 11 22 33 44 55 */

      add_middle(&hptr, 11);
      add_middle(&hptr, 33);
      add_middle(&hptr, 22);
      add_middle(&hptr, 55);
      add_middle(&hptr, 44);
    } else if (n == 3) {

      /* Elements in List are 11 33 22 55 44 */
      add_end(&hptr, 11);
      add_end(&hptr, 33);
      add_end(&hptr, 22);
      add_end(&hptr, 55);
      add_end(&hptr, 44);
    } else if (n == 4)
      delete_node(&hptr);
    else if (n == 5)
      print_list(hptr);

  } while (ch == 'Y' || ch == 'y');

  print_list(hptr);
  reverse_data(hptr);
  print_list(hptr);
  freeMemory(hptr);
}
