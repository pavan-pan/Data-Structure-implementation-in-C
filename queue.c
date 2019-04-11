#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE  5

int queue_arr[SIZE];
int queue_front, queue_back;//To track the front and back of the queue
int capacity;//To track the number of elements in the queue

void queue_init()
{
    queue_front = 0;
    queue_back = 0;
    capacity = 0;
}

void print_queue()
{
    int tmp=0;
    printf ("printing queue\n");
    for (int i=0; i<SIZE; i++)
    {
        tmp = (queue_front + i) % SIZE;
        printf ("%d ", queue_arr[tmp]);
    }
    printf ("\n");
}

bool queue_push(int val)
{
    if (capacity >= SIZE)
    {
        printf ("Queue already full\n");
        return false;
    }
    else
    {
        queue_arr[queue_back] = val;
        queue_back = (queue_back + 1) % SIZE;
        capacity++;
        return true;
    }   
}

int queue_pop(int *val)
{
    int tmp = 0;

    if (capacity <=0)
    {
        printf ("Queue already empty\n");
        return false;
    }
    else
    {
        tmp = queue_arr[queue_front];
        queue_arr[queue_front] = 0;
        queue_front = (queue_front + 1) % SIZE;
        *val = tmp;
        capacity--;
        return true;
    }  
}

bool queue_empty()
{
    if (capacity == 0)
        return true;
    else
        return false;
}

void push_into_queue()
{
    int tmp = 0;
    printf ("Enter value to push into the queue\n");
    scanf ("%d", &tmp);
    if (queue_push(tmp))
        printf ("push successfull\n");
    else
        printf ("push unsuccessfull\n");
}

void pop_from_queue()
{
    int tmp = 0;
    if (queue_pop(&tmp))
        printf ("pop successfull, popped value is : %d\n", tmp);
    else
        printf ("pop unsuccessfull\n");
}

int main()
{
    printf ("Hello world\n");
    queue_init();
    print_queue();

    int popped_val = 0;
    int input_val = 0;

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
                push_into_queue();
                break;
            case 2:
                pop_from_queue();
                break;
            case 3:
                print_queue();
                break;
            case 4:
                exit;
            default:
                printf("Invalid option");
        }
    }
    return 0;
}