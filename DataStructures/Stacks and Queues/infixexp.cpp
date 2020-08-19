#include<bits/stdc++.h>

using namespace std;

int priority(char p) {
    switch(p) {
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
        case '[':
        return 4;
        case '{':
        return 5;
        case '(':
        return 6;
    }
}

int main() {

    stack<char> opstack;
    string res="";
    string str = "(a+{b*c/d-e})";

    for(int i=0; i<str.size(); i++) {
        if(!(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^' || str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]==')' || str[i]=='}' || str[i]==']')) {
            res+=str[i];
        } else {
            if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
                opstack.push(str[i]);
            } else if(str[i]==')' || str[i]=='}' || str[i]==']') {
                char check;
                if(str[i]==')')
                    check='(';
                else if(str[i]=='}')
                    check='{';
                else 
                    check='[';
                while(opstack.top()!=check) {
                    res+=opstack.top();
                    opstack.pop();
                }
                opstack.pop();
            } else {
                if(priority(str[i])<=priority(opstack.top()) && (opstack.top()=='+' || opstack.top()=='-' || opstack.top()=='*' || opstack.top()=='/' || opstack.top()=='^')) {
                    char first=str[i];
                    char second=opstack.top();
                    opstack.pop();
                    res+=second;
                    opstack.push(first);
                } else {
                    opstack.push(str[i]);
                }
            }
        }
    }

    cout<<res<<endl;

    return 0;
}