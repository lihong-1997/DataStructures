#include "stack.h"
#include <stdio.h>
#define ERROR (0)
#define RIGHT (1)

int IsPair(char s1, char s2)
{
	if((s1=='('&&s2==')') || (s1=='['&&s2==']') || (s1=='{'&&s2 =='}'))
	{
		return 1;
	}
	return 0;
}

int checkSymbols(char *S, int len)
{

    Stack charStack = CreateStack();
	char TmpChar;
    for(int i = 0;i < len;i++)
    {
	    if (S[i] == '(' || S[i] == '[' || S[i] == '{')
	    {
            Push(S[i], charStack);
	    }
	    else if (S[i] == ')' || S[i] == ']' || S[i] == '}')
	    {
            if (IsEmpty(charStack))
                return ERROR;
			TmpChar = Pop(charStack);
			if (!IsPair(TmpChar, S[i]))
				return ERROR;
	    }
		else if (S[i] == '/' && S[i + 1] == '*')
		{
			Push(S[i], charStack);
			Push(S[i + 1], charStack);
		}
		else if (S[i] == '/' && S[i - 1] == '*')
		{
			char tmp1 = Pop(charStack);
			char tmp2 = Pop(charStack);
			if (tmp1!='*'||tmp2!='/')
				return ERROR;
			
		}
	    else
			return ERROR;
	    
    }
	if (!IsEmpty(charStack)) return ERROR;

	return RIGHT;
}

int main()
{
	char String[] = { "{([])}/*{[]}*/\0" };
	int len = sizeof(String) / sizeof(String[0]) - 2;
	printf("string=%s\nlen=%d\n", String, len);
	int IsBalance = checkSymbols(String, len);
	printf("symbols balance? %d", IsBalance);
}