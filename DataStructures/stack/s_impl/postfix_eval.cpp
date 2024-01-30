#include <cmath>
#include <iostream>
#include <stack>
#include <string>

void postfix_eval(std::string& input, std::stack<int>& st) {
    // loop throught the stirng from left to right.
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (isdigit(*it)) {
            st.push(*it - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            switch (*it) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1,operand2));
                    break;
            }
        }
    }
}

int main (int argc, char *argv[]) {
    std::string expression = "46+2/5*7+";
    std::stack<int> Stack;
    postfix_eval(expression, Stack);
    std::cout << Stack.top() << std::endl;
}
