#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

struct stack *createStack(int n)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (char *)calloc(sizeof(char), n);
    s->size = n;
    return s;
}

bool isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return true;
    return false;
}

bool isEmpty(struct stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

void push(struct stack *s, char data)
{
    if (!isFull(s))
        s->arr[++s->top] = data;
}

void pop(struct stack *s)
{
    if (!isEmpty(s))
        s->arr[s->top--];
}

char peek(struct stack *s)
{
    if (!isEmpty(s))
        return s->arr[s->top];
    return 'a';
}

bool isValid(char *s)
{

    int lengthOfString = strlen(s);
    struct stack *parStack = createStack(lengthOfString);
    for (int i = 0; i < lengthOfString; i++)
    {
        char curr = s[i];
        if (curr == '(' || curr == '{' || curr == '[')
        {
            push(parStack, curr);
        }
        else
        {
            if (curr == ')' && peek(parStack) == '(')
            {
                pop(parStack);
            }
            else if (curr == ']' && peek(parStack) == '[')
            {
                pop(parStack);
            }
            else if (curr == '}' && peek(parStack) == '{')
            {
                pop(parStack);
            }
            else
                return false;
        }
    }
    if (isEmpty(parStack))
        return true;
    else
        return false;
}
