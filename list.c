#include "list.h"
#include <stdio.h>
#include <stdlib.h>
struct node {
  element_type element;
  position next;
};
/* Return true if l is empty */
int is_empty(list l) { return l->next == NULL; }

/* Return true if p is the last position in list l */
/* parameter l is unused in this implementation */
int is_last(position p, list l) { return p->next == NULL; }

/* Return position of x in l; NULL if not found */
position find(element_type x, list l) {
  position p;
  p = l->next;
  while (p != NULL && p->element != x)
    p = p->next;
  return p;
}
/* If x is not found, then next field of returned position is NULL*/
/* Assumes a header */
position find_previous(element_type x, list l) {
  position p;
  p = l;
  while (p->next != NULL && p->next->element != x)
    p = p->next;
  return p;
}
/* Delete first occurence of x from a list */
/* Assume use of a header node */
void delete_element(element_type x, list l) {
  position p, tmp_cell;
  p = find_previous(x, l);
  if (!is_last(p, l)) { /* Assumption os header use ,x is found ,delete it*/
    tmp_cell = p->next;
    p->next = tmp_cell->next; /* Bypass deleted cell */
    free(tmp_cell);
  }
}
