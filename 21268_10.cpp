#include <iostream>
#define MAX 1000
using namespace std;

class Stack {
    int top;

public:
    char arr[MAX];
    Stack() {top = -1;}

    void push(int x) {
        if (top > MAX-1) {
            cout<<"Stack overflow"<<endl;
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top < 0) {
            cout<<"Stack underflow"<<endl;
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout<<"Stack underflow"<<endl;
            return 0;
        } else {
            int x = arr[top];
            return x;
        }
    }

    bool isEmpty() {
        return(top < 0);
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout<<arr[i]<<" "<<endl;
        }
    }
};

int prec(char c) {
    if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string str) {
    Stack st;
    string result;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if (c == '(') {
            st.push('(');
        }
        else if (c == ')') {
            while (st.peek() != '(') {
                result += st.peek();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.isEmpty() && prec(str[i]) <= prec(st.peek())) {
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
    return result;
}

int evaluatePostFix(string exp) {
    Stack st;
    int ans;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9'){
            st.push(c);
        } else {
            int val1 = st.pop() - '0';
            int val2 = st.pop() - '0';
            switch (c)
            {
            case '+': {
                st.push((val2 + val1) + '0');
                break;
            }
            case '-': {
                st.push((val2 - val1) + '0');
                break;
            }
            case '*': {
                st.push((val2 * val1) + '0');
                break;
            }
            case '/': {
                st.push((val2 / val1) + '0');
                break;
            }
            }
        }
    }
    return st.pop() - '0';
}

int main() {
    string exp;
    cout<<"Enter expression ";
    cin>>exp;
    string e = infixToPostfix(exp);
    cout<<"Ans: "<<evaluatePostFix(e)<<endl;
    return 0;
}