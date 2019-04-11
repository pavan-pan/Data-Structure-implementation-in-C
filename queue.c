#include <stdio.h>
#include <stdbool.h>

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
    if (queue_front == queue_back)
        return true;
    else
        return false;
}

int main()
{
    printf ("Hello world\n");
    queue_init();
    print_queue();

    int popped_val = 0;

    printf ("add to queue : %d\n", queue_push(20));
    print_queue();
    printf ("add to queue : %d\n", queue_push(21));
    print_queue();
    printf ("add to queue : %d\n", queue_push(22));
    print_queue();
    printf ("add to queue : %d\n", queue_push(23));
    print_queue();
    
    printf ("add to queue : %d\n", queue_push(24));
    print_queue();
    printf ("add to queue : %d\n", queue_push(25));
    print_queue();

    printf ("pop from queue : %d\n", queue_pop(&popped_val));
    printf ("popped value : %d\n", popped_val);
    print_queue();
    printf ("add to queue : %d\n", queue_push(44));
    print_queue();
    printf ("add to queue : %d\n", queue_push(42));
    print_queue();
    printf ("pop from queue : %d\n", queue_pop(&popped_val));
    printf ("popped value : %d\n", popped_val);
    print_queue();
    printf ("pop from queue : %d\n", queue_pop(&popped_val));
    printf ("popped value : %d\n", popped_val);
    print_queue();
    printf ("pop from queue : %d\n", queue_pop(&popped_val));
    printf ("popped value : %d\n", popped_val);
    print_queue();
    printf ("pop from queue : %d\n", queue_pop(&popped_val));
    printf ("popped value : %d\n", popped_val);
    print_queue();
    return 0;
}