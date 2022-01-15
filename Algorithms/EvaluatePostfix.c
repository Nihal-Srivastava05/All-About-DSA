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
	return ((int)ele >= 0 && (int)ele <= 9);
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

int evaluate_postfix(char postfix[10])
{
	struct Stack* stack = createStack(10);
	int i, result;
	char output;
	char ele = postfix[0];
	i = 0;
	int op1, op2;
	while(ele != '\0'){
		if(isOperator(ele)){
			op1 = pop(stack) - '0';
			op2 = pop(stack) - '0';
			if(ele == '+'){
				result = (int)op2 + (int)op1;
			}
			else if(ele == '-'){
				result = (int)op2 - (int)op1;
			}
			else if(ele == '/'){
				result = (int)op2 / (int)op1;
			}
			else if(ele == '*'){
				result = (int)op2 * (int)op1;
			}
			output = result + '0';
			push(stack, output);
		}
		else{
			push(stack, ele);
		}
		
		i++;
		ele = postfix[i];
	}
	output = pop(stack) - '0';
	return output;
}

int main()
{
	char postfix[10];
	scanf("%s", &postfix);
	
	printf("Postfix expression is: %s\n", postfix);
	
	int ans = evaluate_postfix(postfix);
	printf("Answer is: %d", ans);

	
	return 0;
}
