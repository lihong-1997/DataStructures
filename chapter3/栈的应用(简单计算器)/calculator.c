#include <stdio.h>
#include <stdlib.h>
#include "infixTopostfix.h"
#include "IntStack.h"
#include<math.h>

int Calculator(char* postfix, int len)
{
	Stack calculator = CreateIntStack(50);
	int num, popNum1, popNum2;

	for (int i = 0;i < len;i++)
	{
		if (postfix[i] == '^' || postfix[i] == '+' || postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '/')
		{
			popNum1 = TopInt(calculator);
			PopInt(calculator);
			popNum2 = TopInt(calculator);
			PopInt(calculator);
			switch (postfix[i])
			{
			case '+': 
				PushInt(popNum2 + popNum1, calculator);
				break;
			case '*': 
				PushInt(popNum2 * popNum1, calculator);
				break;
			case '-':
				PushInt(popNum2 - popNum1, calculator);
				break;
			case '/':
				PushInt(popNum2 / popNum1, calculator);
				break;
			case '^':
				PushInt((int)pow(popNum2, popNum1), calculator);
				break;
			default:
				break;
			}
		}
		else
		{
			num = (int)postfix[i] - 48;
			PushInt(num, calculator);
		}
	}
	int result;
	result = TopInt(calculator);
	DisposeIntStack(calculator);
	return result;
}

int main()
{
	//中缀表达式
	//char expression[] = { "(8-2)*3+(2^3^2)/2\0" };
	char expression[] = { "((1+2)*(3*(4+5)))\0"};
	const int len = sizeof(expression) / sizeof(expression[0]) - 2;
	int len2 = len;
	printf("infix expression: ");
	for (int i = 0; i < len; i++)
	{
		if (expression[i] == '(' || expression[i] == ')') --len2;
		printf("%c", expression[i]);
	}
	printf("\n");

	char* output = malloc(sizeof(char) * (len2));
	//中缀转后缀
	InfixToPostfix(expression, len, output);
	printf("postfix expression: ");
	for (int i = 0; i < len2; i++)//括号个数
	{
		printf("%c", output[i]);
	}
	printf("\n");
	int result = Calculator(output, len2);
	printf("result:%d", result);
}