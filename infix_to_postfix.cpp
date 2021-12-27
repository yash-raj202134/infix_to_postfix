// Infix to postfix conversion....
#include <iostream>
#include <string.h>
using namespace std;

class stack
{
public:
    char *expression;
    int size;
    int top;
};
int isEmpty(class stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFull(class stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
char stackTop(class stack *st)
{
    return (st->expression[st->top]);
}
char pop(class stack *st)
{
    int value;
    if (isEmpty(st))
    {
        cout << "Stack Underflow! cannot pop from the stack";
        return -1;
    }
    else
    {
        value = st->expression[st->top];
        st->top--;
        return value;
    }
}
void push(class stack *st, char element)
{
    if (isFull(st))
        cout << "Stack Overflow!\n";
    else
    {
        st->top++;
        st->expression[st->top] = element;
    }
}
int is_operator(char ch)   //A function to detect an operator.
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
int precedance(char ch)          //A function to assign precedence to operators.
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

char *infix_to_postfix(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size=strlen(infix);
    sp->top = -1;
    sp->expression = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedance(infix[i]) > precedance(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return (postfix);
}
int main(void)
{
    char expression[100];
    cout<<"Enter the infix expression : ";
    cin >>expression;
    cout << "Post fix expression is " << infix_to_postfix(expression);

    return 0;
}