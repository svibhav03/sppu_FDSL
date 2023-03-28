#include <iostream>
using namespace std;
#define size 50

class stackexp
{
    int top;
    char stk[size];
public:
    stackexp()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stackexp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stackexp::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stackexp::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stackexp s1;
    char exp[20],ch;
    int i=0;
    bool flag = 0;
    cout << "*********** Parenthesis checker *************" << endl;
    cout<<"\nEnter the expression to to check if it's balanced or not: ";
    cin>>exp;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
        	s1.push(exp[i]);
        }
        if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
        	ch = s1.pop();
        	if((exp[i]==')'&& ch!='(') || (exp[i]==']'&& ch!='[') || (exp[i]=='}'&& ch!='{')){
        		flag = 1;
        		cout<<"Mismatched brackets!";
        		break;
        	}
        }
        i=i+1;
    }
    if((s1.isempty() && flag == 0))
    {
        cout<<"\nExpression is well parenthesized!\n";
    }
    else
    {
        cout<<"\nThe expression is unbalanced! \n";
    }
    return 0;
}
