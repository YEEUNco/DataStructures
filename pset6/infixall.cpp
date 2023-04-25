
// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
    vector<T> item;

    bool empty() const {
        return item.empty();
    }
    auto size() const {
        return item.size();
    }
    void push(T const& data) {
        item.push_back(data);
    }
    void pop() {
        if (item.empty())
            throw out_of_range("stack<>::pop(): pop stack");
        item.pop_back();
    }
    T top() const {
        if (item.empty())
            throw out_of_range("stack<>::top(): top stack");
        return item.back();
    }
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig) {

    //cout << "Step 2: your code here: copy printStack() template version from postfix.cpp\n";
    //cout << "Step 3: rewrite printStack() using recursion. refer to PDF file\n";
    if(orig.empty()) return;
    T keep=orig.top();
    orig.pop();
    printStack(orig);
    cout << keep << ' ';
    orig.push(keep);
    

    cout << endl;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a,b);
    }
    cout << "Unsupported operator encountered: " << op << endl;
    return 0;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
    double right  = va_stack.top(); va_stack.pop();
    double left = va_stack.top(); va_stack.pop();
    char op = op_stack.top(); op_stack.pop();
    double value = apply_op(left, right, op);

    DPRINT(cout << " va/op_stack.pop: " << value << endl;);
    return value;
}

int precedence(char token){
    if(token == '*' || token == '/'){
        return 2;
    }
    else if(token == '-' || token == '+') return 1;
    
    else return 3;
}

// returns value of expression after evaluation.
double evaluate(string tokens) {
    DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
    stack<double>  va_stack;              // stack to store operands or values
    stack<char> op_stack;                 // stack to store operators.
    double value = 0;

    for (size_t i = 0; i < tokens.length(); i++) {
        // token is a whitespace or an opening brace, skip it.
        if (isspace(tokens[i])) continue;
        
        DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

        // current token is a value(or operand), push it to va_stack.
        if (isdigit(tokens[i])) {
            int count=0;
            double result=0;
            while(isdigit(tokens[i])){
                i++;
                count++;
            }
            i--;
            for(int k=0; k<count; k++){
                
                result+=(tokens[i-k]-'0')*pow(10,k);
                
            }
            va_stack.push(result);
            
            
        }
        else if (tokens[i] == ')') { // compute it, push the result to va_stack
            
            while(op_stack.top() != '('){
                double value = compute(va_stack, op_stack);
                va_stack.push(value);
            }
            op_stack.pop();
            //printStack(op_stack);
            //cout << "$$\n";

        
        }
        else if(tokens[i] == '(') op_stack.push(tokens[i]);
        else { // token is an operator; push it to op_stack.
            
            while(op_stack.size()!=0 && op_stack.top() != '('&& (precedence(tokens[i]) <= precedence(op_stack.top()))){
                //cout << op_stack.top()  <<"&& ";
                //cout << precedence(op_stack.top()) <<"**\n";
                double value = compute(va_stack, op_stack);
                va_stack.push(value);
            }
            
            
            op_stack.push(tokens[i]);
        }
    }

    DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
    
    DPRINT(printStack(va_stack);  cout << endl;);
    DPRINT(printStack(op_stack);  cout << endl;);

    //cout << "your code here: process if !op_stack.empty() \n";
 
    while(!(op_stack.empty())){
        value = compute(va_stack, op_stack);
        va_stack.push(value);
    }

    value = va_stack.top();
    

    //cout << "your code here: post-conditions\n";
    assert(op_stack.size()==0);
    assert(va_stack.size()==1);

    //cout << "your code here: return & clean-up\n";


    return value;
}
