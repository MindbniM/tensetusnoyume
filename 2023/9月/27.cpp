#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include <ctype.h>
#define MAX 10
typedef struct {
	double* arr;
	int base;
	int top;
	int capacity;
}sqStack;
void initStack(sqStack* S) {
	double*p = (double*)malloc(sizeof(double) * MAX);
	assert(p);
	S->arr = p;
	S->base = 0;
	S->top = 0;
	S->capacity = MAX;
}
void Push(sqStack* S, double e) {     //向栈顶插入元素
	if (S->top >= S->capacity) {
		double* tmp = (double*)realloc(S->arr, 2 * S->capacity);
		if (tmp == NULL)return;
		S->arr = tmp;
		S->capacity *= 2;
	}
	S->arr[S->top++] = e;
	

}
double GetTop(sqStack* S) {   //返回栈顶元素

	assert(S->base != S->top);
	return  S->arr[S->top - 1];
}
void Pop(sqStack* S, double* e) {   //删除栈顶元素
	assert(S->base != S->top);
	*e = S->arr[S->top - 1];
	S->top--;
}
double Operate(double a, double theta, double b) {
	
		a = a- '0';
	
		b = b - '0';
	switch ((char)theta) {
	case '*':return a * b;
	case '/':return a / b;
	case'+':return a + b;
	case'-':return a - b;
	}
}

int Precede(char op1, char op2)
{
	switch (op1) {
	case '+':
	case '-':
		if (op2 == '+' || op2 == '-' || op2 == ')')
			return '>';
		if (op2 == '*' || op2 == '/' || op2 == '(')
			return '<';
		break;
	case '*':
	case '/':
		if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')')
			return '>';
		if (op2 == '(')
			return '<';
		break;
	case '(':
		if (op2 == ')')
			return '=';
		else
			return '<';
		break;
	case ')':
		return '>';
		break;
	case '#':
		if (op2 == '#')
			return '=';
		else
			return '<';
		break;
	default:
		break;
	}
	return -1;
}

double EvaluateExpression() {
	sqStack OPTR, OPND;
	initStack(&OPTR);     Push(&OPTR, '#');       //创建运算符栈,并加入#
	initStack(&OPND);     int c = getchar();     //创建运算数栈,用c获取一个字符
	while (c != '#' || GetTop(&OPTR) != '#')
	{
		if (c >= 48 && c <= 57)     //不是运算符就进栈
		{
			Push(&OPND,c);
			c = getchar();
		}
		else {

			switch (Precede(GetTop(&OPTR), c)) {  //输入的是运算符,则出栈上一个运算符进行比较
			case'<':                      //栈顶元素优先权低,则将c压入运算符栈
				Push(&OPTR, c);
				c = getchar();
				break;
			case'=':            //优先权相等,则删除上一运算符
				double x;
				Pop(&OPTR, &x);
				c = getchar();
				break;
			case'>':
				double theta,a, b;
				Pop(&OPTR, &theta);
				Pop(&OPND, &b);
				Pop(&OPND, &a);
				Push(&OPND, Operate(a, theta, b)+'0');
				break;
			}
		}
	}
	return GetTop(&OPND);
}
int main() {

	double a=EvaluateExpression();
	printf("%.2lf", a-'0');
}