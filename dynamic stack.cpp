#define MAX_SIZE 10
#define INCREMENT_SIZE 2
#define MIN_SIZE 6
#define DECREMENT_SIZE 40
#include<iostream>
using namespace std ;
struct DynamicDoubleStack
{
    double* array ;
    long top ;
    long size ;
};
int isEmpty(struct DynamicDoubleStack* stack)
{
    int status = 0;
    if(stack -> top == -1)
    {
        status = 1 ;
    }
    return status;
}

long size(struct DynamicDoubleStack* stack)
{
    long count = -1;
    count = stack->top + 1 ;
    return count;
}
int initialize(struct DynamicDoubleStack* stack)
{
    int status = -1 ;
    stack->top = -1 ;
    stack->array = new double[MAX_SIZE] ;
    stack->size = MAX_SIZE ;
    if(stack->array == '\0')
    {
        stack->size = 0 ;
    }
    else
    {
        stack->size = MAX_SIZE ;
        status = 0 ;
    }
    return status;
}
int grow_stack(struct DynamicDoubleStack* stack)
{
    int status = -1 ;
    stack->size = stack->size * (INCREMENT_SIZE) ;
    double* new_array = new double[stack->size ];
    long size_1 = size(stack);
    for(long i = 0 ; i < size_1 ; i++ )
    {
        new_array[i] = stack->array[i] ;
    }
    delete[]stack->array ;
    stack->array = new_array ;
    status = 0 ;
    return status ;
}

int shrink_stack(struct DynamicDoubleStack* stack)
{
    int status = -1 ;
    stack->size = (MIN_SIZE/stack->size) * 100 ;
    double* new_array = new double[stack->size ];
    cout << "shrink stack " << stack->size << endl ;
    long size_1 = size(stack);
    for(long i = 0 ; i < size_1 ; i++ )
    {
        new_array[i] = stack->array[i] ;
    }
    delete[]stack->array ;
    stack->array = new_array ;
    status = 0 ;
    return status ;
}
int push(struct DynamicDoubleStack* stack, double doubleToPush)
{
    int status = -1;
    if(stack->top == stack->size - 1 )
    {
        status = grow_stack(stack);
        if(status == 0)
        {
            ++stack->top;
            stack->array[stack->top] = doubleToPush ;
            status = 0 ;
        }
        return status ;
    }
    else
    {
        ++stack->top;
        stack->array[stack->top] = doubleToPush ;
        status = 0 ;
    }
    return status;
}
int pop(struct DynamicDoubleStack* stack, double* pdoublePopped)
{
    int status = -1;
    if(isEmpty(stack) == 1)
    {
        return status ;
    }
    else
    {
        *pdoublePopped = stack->array[stack->top];
        stack->top-- ;
        status = 0 ;
        if(stack->size == (DECREMENT_SIZE/stack->size) * 100 )
        {
            shrink_stack(stack) ;
        }
    }
    return status;
}
int isFull(struct DynamicDoubleStack* stack)
{
    int status = 0;
    if(stack -> top == stack->size - 1)
    {
        status = 1 ;
    }
    return status;
}

int main()
{
    double temp , i;
    struct DynamicDoubleStack stack ;
    initialize(&stack);
    cout << size(&stack) << endl ;
    for( i = 0 ; i < 11 ; i++ )
    {
        cout << "Enter the element " << endl ;
        cin >> temp ;
        push(&stack,temp);
        cout << "size ->" << size(&stack) << endl ;
    }
      for( i = 0 ; i < 11 ; i++ )
    {
        pop(&stack,&temp);
        cout << temp << endl ;
        cout << "size ->" << size(&stack) << endl ;
    }
}
