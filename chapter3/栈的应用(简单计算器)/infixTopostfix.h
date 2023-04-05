#ifndef _INFIXTOPOSTFIX_H
#define _INFIXTOPOSTFIX_H
#include "stack.h"

int PriorLevel(char operator);

void InfixToPostfix(const char* Infix, int len, char* Postfix);

#endif 
