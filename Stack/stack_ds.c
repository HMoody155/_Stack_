#include "stack_ds.h"

static stack_status_t stack_full(stack_ds_t *my_stack)
{

    if((my_stack->stack_pointer ) == (STACK_MAX_SIZE -1))
    {
        return STACK_FULL;
    }
    else {return STACK_NOT_FULL;}
}
static stack_status_t stack_empty(stack_ds_t *my_stack)
{

    if(-1 == my_stack->stack_pointer)
    {
        return STACK_EMPTY;
    }
    else {return STACK_NOT_FULL;}
}

return_status_t stack_init(stack_ds_t *my_stack)
{
    return_status_t ret = R_NOK;

    if(NULL == my_stack)
    {
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_pointer = -1;
        ret = R_OK;
    }
    return ret;
}

return_status_t stack_push(stack_ds_t *my_stack, uint32 value)
{
    return_status_t ret = R_NOK;

    if((NULL == my_stack) || (STACK_FULL == stack_full(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("Error !! stack is full can`t pus (0x%X)\n", value);
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer] = value;
        #ifdef STACK_DEBUG
        printf("value (0x%X) pushed to stack \n", value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
}
return_status_t stack_pop(stack_ds_t *my_stack, uint32 *value)
{
        return_status_t ret = R_NOK;

    if((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("Stack is empty can`t pop any value\n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        *value = my_stack->data[my_stack->stack_pointer];
        my_stack->stack_pointer--;
        #ifdef STACK_DEBUG
        printf("value (0x%X) poped from stack\n", *value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}
return_status_t stack_top(stack_ds_t *my_stack, uint32 *value)
{
        return_status_t ret = R_NOK;

    if((NULL == my_stack) || (STACK_FULL == stack_full(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("Error !! stack is empty\n", value);
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
       *value = my_stack->data[my_stack->stack_pointer];
        #ifdef STACK_DEBUG
        printf("stack top value (0x%X)\n", *value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}
return_status_t stackSize(stack_ds_t *mystack, uint32 *stacksize)
{
    return_status_t ret = R_NOK;
    if((NULL == mystack) || (NULL == stacksize))
    {
        ret = R_NOK;
    }
    else
    {
        *stacksize = mystack->stack_pointer + 1;
        #ifdef STACK_DEBUG
        printf("stack size = %i\n", *stacksize);
        #endif // STACK_DEBUG
        ret = R_OK;
    }
    return ret;
}
return_status_t stack_display(stack_ds_t *my_stack)
{
    return_status_t ret = R_NOK;
    sint32 l_counter = ZERO_INIT;
    if((NULL == my_stack) || (STACK_EMPTY == stack_empty(my_stack)))
    {
        #ifdef STACK_DEBUG
        printf("Error !! stack is empty\n");
        #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        printf("stack data : ");
        for(l_counter = (my_stack->stack_pointer); l_counter >= ZERO; l_counter--)
        {
            printf("0x%X\t", my_stack->data[l_counter]);
        }
        printf("\n");
        ret = R_OK;
    }
    return ret;
}
