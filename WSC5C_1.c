#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
   int data;
   struct linked_list *next;
}   element;

typedef element * elementptr;

void trav_and_print(elementptr);
int count_elems(elementptr, int);
void just_checkin(elementptr, elementptr, elementptr, int);

int main()
{
   elementptr first = NULL,
	           last = NULL,
              current;
   int counter = 0;

   /* Create a linked list with one element            */
   /* NOTE: the first element is always a special case */
   first = (elementptr) malloc(sizeof(element));
   current = first;
   last = first;
   last -> data = 5;
   last -> next = NULL;

   /* Add another element to the end of the list */
   last -> next = (elementptr) malloc(sizeof(element));
   last = last -> next;
   last -> data = 12;
   last -> next = NULL;

   while (counter < 5){
      last -> next = (elementptr) malloc(sizeof(element));
      last = last -> next;
      printf("Enter an integer data value: ");
      scanf("%d", last);
      last -> data;
      last -> next = NULL;
      counter = count_elems(current, counter);
   }

   just_checkin(current, first, last, counter);

   free(first);
   free(last);

   return 0;
}

void trav_and_print(elementptr current)
{
   while(current != NULL)
   {
      printf("The data value is %d.\n", current -> data);
      current = current -> next;
   }
}

int count_elems(elementptr current, int counter)
{
   counter = 0;
   while(current != NULL)
   {
      current = current -> next;
      counter = ++counter;
   }
   return counter;
}

void just_checkin(elementptr current, elementptr first, elementptr last, int counter)
{
   trav_and_print(current);
   counter = count_elems(current, counter);
   printf("There are %d elements in the linked list.\n", counter);
   printf("first->data is %d\n", first->data);
   printf("last->data is %d\n", last->data);
}