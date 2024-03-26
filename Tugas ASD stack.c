#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->items[stack->top--];
}

char isBalanced(char *exp) {
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(&stack)) {
                return 'N';
            }
            char popped = pop(&stack);
            if ((exp[i] == ')' && popped != '(') || (exp[i] == '}' && popped != '{') || (exp[i] == ']' && popped != '[')) {
                return 'N';
            }
        }
    }
    if (!isEmpty(&stack)) {
        return 'N';
    }
    return 'Y';
}

int main() {
    char exp[100];
    scanf("%s", exp);
    char result = isBalanced(exp);
    if (result == 'Y') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
