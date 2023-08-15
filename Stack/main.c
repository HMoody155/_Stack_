#include "stack_ds.h"

stack_ds_t stack1;
stack_ds_t stack2;

uint32 popvalue = 0, stacktopval = 0, stacksize = 0;

int main()
{
    return_status_t ret = R_NOK;

    ret = stack_init(&stack1);
    if(ret == R_NOK)
    {
       printf("stack1 can`t initialized\n");
    }
    else{
        ret = stack_push(&stack1, 0x11);
        ret = stack_push(&stack1, 0x22);
        ret = stack_push(&stack1, 0x33);
        ret = stack_push(&stack1, 0x44);
        ret = stack_push(&stack1, 0x55);
        ret = stack_display(&stack1);
        ret = stack_push(&stack1, 0x66);
        ret = stack_push(&stack1, 0x77);
        printf("#################################################\n");
        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        ret = stack_display(&stack1);
        ret = stack_pop(&stack1, &popvalue);
         if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }

        ret = stack_pop(&stack1, &popvalue);
        if(R_OK == ret)
        {
            printf("pop value = 0x%X\n", popvalue);
        }
        printf("#################################################\n");
        ret = stack_push(&stack1, 0x66);
        ret = stack_push(&stack1, 0x77);
        ret = stack_push(&stack1, 0x88);
        ret = stack_push(&stack1, 0x99);
        ret = stack_display(&stack1);
        printf("#################################################\n");
        ret = stack_top(&stack1,&stacktopval);
        if(R_OK == ret)
        {
            printf("top value = 0x%X\n", stacktopval);
        }
        ret = stackSize(&stack1,&stacksize);

    }
    ret = stack_init(&stack2);
        if(ret == R_NOK)
    {
       printf("stack2 can`t initialized\n");
    }
    else{}

    return 0;
}
