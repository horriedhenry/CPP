#include <cmath>
#include <iostream>
#include <stack>
#include <string>

void prefix_eval(std::string& input, std::stack<int>& st) {
    // loop throught the stirng from right to left
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        if (isdigit(*it)) {
            st.push(*it - '0');
        } else {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
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
    std::string expression = "-+7*45+20";
    std::stack<int> Stack;
    prefix_eval(expression, Stack);
    std::cout << Stack.top() << std::endl;
}
