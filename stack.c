#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5
int stack_arr[SIZE];   //Array which acts like a stack
int top_of_stack = -1; //to track the top of the stack


void print_stack()
{
    printf ("Stack contents\n");
    for (int i=0; i<SIZE; i++)
    {
        printf ("%d ", stack_arr[i]);
    }
    printf ("\n");
}

bool stack_empty()
{
    if (top_of_stack < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool stack_push (int *val)
{   
    top_of_stack ++;

    if (top_of_stack >= SIZE)
    {
        return false;
    }
    else
    {
        stack_arr[top_of_stack] = *val;
        return true;
    }
}

bool stack_pop (int *val)
{
    if (stack_empty())
    {
        return false;
    }
    else
    {   
        printf ("top of the stack : %d\n", top_of_stack);
        *val = stack_arr[top_of_stack];
        stack_arr[top_of_stack] = 0;
        top_of_stack--;
        return true;
    }
}

void push_into_stack ()
{
    int tmp = 0;
    printf ("Enter the value to be pushed \n");
    scanf ("%d", &tmp);

    if (stack_push(&tmp))
    {
        printf ("Stack push successfull\n");
    }
    else
    {
        printf ("Stack push unsucccessfull\n");
    }
}

void pop_from_stack()
{
    int tmp = 0;

    if (stack_pop(&tmp))
    {
        printf ("Stack pop successfull, popped value is : %d\n", tmp);
    }
    else
    {
        printf ("Stack pop unsuccessfull\n");
    }
}

int main()
{
    printf ("Stack\n");
    int input_val=0;
    while (1)
    {
        printf ("Enter 1 to Push into the Queue\n");
        printf ("Enter 2 to Pop from the Queue\n");
        printf ("Enter 3 to Print the Queue\n");
        printf ("Enter 4 to Exit\n");
        scanf ("%d", &input_val);

        switch (input_val)
        {
            case 1:
                push_into_stack();
                break;
            case 2:
                pop_from_stack();
                break;
            case 3:
                print_stack();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}