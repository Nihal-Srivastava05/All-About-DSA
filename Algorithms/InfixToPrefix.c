#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int capacity;
	char *array;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));
	
	return stack;
}

int isFull(struct Stack* stack)
{
	if(stack->top == stack->capacity - 1){
		return 1;
	}
	return 0;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int data)
{
	if( isFull(stack) ){
		printf("1. Stack is full\n");
	}
	stack->array[++stack->top] = data;
}

char pop(struct Stack* stack)
{
	if( isEmpty(stack) ){
		printf("2. Stack is Empty\n");
		return '#';
	}
	return stack->array[stack->top--];
}

char peek(struct Stack* stack)
{
	if( isEmpty(stack) ){
		printf("3. Stack is Empty\n");
		return '#';
	}
	return stack->array[stack->top];
}

int isOperand(char ele)
{
	return ((ele >= 'a' && ele <= 'z') || (ele >= 'A' && ele <= 'Z'));
}

int isOperator(char ele)
{
	if(ele == '+' || ele == '-' || ele == '/' || ele == '*' || ele == '^'){
		return 1;
	}
	else{
		return 0;
	}
}

int precedence(char ele)
{
	if(ele == '^') {
		return 3;
	}
	if(ele == '/' || ele == '*'){
		return 2;
	}
	else if(ele == '+' || ele == '-'){
		return 1;
	}
	else{
		return 0;
	}
}

int associativity(char ele)
{
	if(ele == '+' || ele == '-' || ele == '*' || ele == '/'){
		return 1; //Left to right
	}
	else {
		return 0; //Right to left
	}
}

void infixToPrefix(char infix[])
{
	int length = strlen(infix);
	strrev(infix);
	struct Stack* stack = createStack(length);
	struct Stack* postfix = createStack(length);
	int i;
	char ele, ele1;
	ele = infix[0];
	i = 0;
	while(ele != '\0')
	{
		if(isOperand(ele)){
			push(postfix, ele);
		}
		else if(isOperator(ele)){
			if(isEmpty(stack)){
				push(stack, ele);
			}
			else if(precedence(ele) > precedence(peek(stack))){
				push(stack, ele);
			}
			else if(precedence(ele) < precedence(peek(stack))){
				ele1 = pop(stack);
				push(postfix, ele1);
				while(precedence(ele) < precedence(peek(stack))){
					ele1 = pop(stack);
					push(postfix, ele1);
				}
				push(stack, ele);
			}
			else if(precedence(ele) == precedence(peek(stack))){
				if(associativity(ele)){
					push(stack, ele);
				}
				else{
					push(stack, ele);
				}
			}
		}
		else if(ele == ')'){
			push(stack, ele);
		}
		else if(ele == '('){
			ele1 = pop(stack);
			while(ele1 != ')'){
				push(postfix, ele1);
				ele1 = pop(stack);
			}
		}
		
		i++;
		ele = infix[i];
	}
	
	while(!isEmpty(stack)){
		push(postfix, pop(stack));
	}
	
	int final_length = postfix->top;
	for(i = 0; i<final_length+1; i++){
		printf("%c ", pop(postfix));
	}

}

int main()
{
	char infix[10];
	scanf("%s", &infix);
	printf("The infix expression is: %s\n", infix);
	
	infixToPrefix(infix);
	
	return 0;
}
