#include "infixTopostfix.h"

int PriorLevel(char operator)
{
	switch (operator)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 4;
	default:
		return 0;
	}
}

void InfixToPostfix(const char *Infix, int len, char *Postfix)
{
	int outIndex = 0;
	Stack OperatorStack = CreateStack(50);
	char top;
	for (int i = 0; i < len;i++)
	{
		if (Infix[i] == '^' || Infix[i] == '*' || Infix[i] == '+' || Infix[i] == '-' || Infix[i] == '/' || Infix[i] == '(')
		{
			if (IsEmpty(OperatorStack))
				Push(Infix[i], OperatorStack);
			else
			{
				top = Top(OperatorStack);
				//需注意幂运算的特殊性!!!
				if ((PriorLevel(top) < PriorLevel(Infix[i])) || (top == '^' && Infix[i] == '^'))
					Push(Infix[i], OperatorStack);
				else
				{
					//除非处理闭括号，开括号不弹出
					while(top != '(' && PriorLevel(top) >= PriorLevel(Infix[i]))
					{
						Postfix[outIndex++] = top;
						Pop(OperatorStack);
						if (IsEmpty(OperatorStack)) break;
						top = Top(OperatorStack);
					}
					Push(Infix[i], OperatorStack);
				}
			}
		}
		else if(Infix[i] == ')')
		{
			top = Top(OperatorStack);
			//printf("top:%c", top);
			//依次弹出栈元素，写入Postfix，直至遇到'('
			while (top != '(')
			{
				Postfix[outIndex++] = top;
				Pop(OperatorStack);
				top = Top(OperatorStack);
			}
			Pop(OperatorStack); // 将 '('弹出
		}
		else
			Postfix[outIndex++] = Infix[i]; //读到数字立即输出
	}
	//输入为空，将栈元素全部弹出
	while (!IsEmpty(OperatorStack))
	{
		top = Top(OperatorStack);
		Postfix[outIndex++] = top;
		Pop(OperatorStack);
	}
	DisposeStack(OperatorStack);
}