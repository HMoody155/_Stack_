#ifndef _STACK_DS_H
#define _STACK_DS_H
#define STACK_MAX_SIZE 5
#define STACK_DEBUG
#include "types.h"

typedef struct stack_ds{
    uint32 stack_pointer;
    uint32 data[STACK_MAX_SIZE];

}stack_ds_t;

typedef enum stack_status{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL,
}stack_status_t;

return_status_t stack_init(stack_ds_t *my_stack);
return_status_t stack_push(stack_ds_t *my_stack, uint32 value);
return_status_t stack_pop(stack_ds_t *my_stack, uint32 *value);
return_status_t stack_top(stack_ds_t *my_stack, uint32 *value);
return_status_t stack_display(stack_ds_t *my_stack);
return_status_t stackSize(stack_ds_t *mystack, uint32 *stacksize);

#endif // _STACK_DS_H
