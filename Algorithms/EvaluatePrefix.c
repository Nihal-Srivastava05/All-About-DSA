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
	stack->array = (char *)malloc(stack->capacity * sizeof(char));
	
	return stack;
}

int isFull(struct Stack* stack)
{
	if(stack->top == stack->capacity-1){
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
	if(isFull(stack)){
		printf("Stack is full");
	}
	stack->array[++stack->top] = data;
}

char pop(struct Stack* stack)
{
	if(isEmpty(stack)){
		printf("The Stack is empty");
		return '#';
	}
	return stack->array[stack->top--];
}

char peek(struct Stack* stack)
{
	if(isEmpty(stack)){
		printf("The Stack is empty");
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

int evaluate_prefix(char prefix[10])
{
	strrev(prefix);
	struct Stack* stack = createStack(10);
	char ele, output;
	int op1,op2, i, result;
	i = 0;
	ele = prefix[0];
	while(ele != '\0'){
		if(isOperator(ele)){
			op1 = pop(stack) - '0';
			op2 = pop(stack) - '0';
			if(ele == '+'){
				result = op1 + op2;
			}
			else if(ele == '-'){
				result = op1 - op2;
			}
			else if(ele == '*'){
				result = op1 * op2;
			}
			else if(ele == '/'){
				result = op1 / op2;
			}
			output = result + '0';
			push(stack, output);
		}
		else{
			push(stack, ele);
		}
		
		i++;
		ele = prefix[i];
	}
	
	result = pop(stack) - '0';
	
	return result;
}

int main()
{
	char prefix[10];
	scanf("%s", &prefix);
	
	int result = evaluate_prefix(prefix);
	printf("The result is: %d", result);
	
	return 0;
}
