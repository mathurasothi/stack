#include "destack.h"
#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


struct stack {
  struct destack *des;
};


struct stack *stack_create(void) {
  struct stack *stack = malloc(sizeof(struct stack));
  stack->des = destack_create();
  return stack;
}


bool stack_is_empty(const struct stack *s) {
  assert(s);
  return destack_is_empty(s->des);
}


int stack_top(const struct stack *s) {
  assert(s);
  return destack_top(s->des);
}


int stack_pop(struct stack *s) {
  assert(s);
  return destack_pop_top(s->des);
}


void stack_push(int item, struct stack *s) {
  assert(s);
  destack_push_top(item, s->des);
}


void stack_destroy(struct stack *s) {
  assert(s);
  destack_destroy(s->des);
  free(s);
}


void stack_print(const struct stack *s) {
  assert(s);
  destack_print(s->des);
}