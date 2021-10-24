#include <iostream>
#include <queue>
#include <stack>
#include <string>

int from_infix_to_num(std::string &infix) {
    std::stack<std::string> stack;
    std::queue<std::string> queue;
    std::string postfix;

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            stack.push(infix.substr(i, 1));
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            if (stack.empty() || stack.top() == "(") {
                stack.push(infix.substr(i, 1));
            } else if ((infix[i] == '*' || infix[i] == '/') && (stack.top() == "+" || stack.top() == "-")) {
                stack.push(infix.substr(i, 1));
            } else {
                queue.push(stack.top());
                stack.pop();
                stack.push(infix.substr(i, 1));
            }
        } else if (infix[i] == ')') {
            while (true) {
                if (stack.top() == "(") {
                    stack.pop();
                    break;
                }
                queue.push(stack.top());
                stack.pop();
            }
        } else {
            int j = 0;
            while ((infix[i + j] <= '9') && (infix[i + j] >= '0')) {
                j++;
            }
            queue.push(infix.substr(i, j));
            i += j - 1;
        }
    }

    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }

    // из постфиксной в число
    int operand1, operand2;
    std::stack<int> stack_;

    while (!queue.empty()) {
        if ((queue.front()[0] >= '0') && (queue.front()[0] <= '9')) {
            stack_.push(std::stoi(queue.front()));
            queue.pop();
        } else if (queue.front() == "+") {
            operand1 = stack_.top();
            stack_.pop();
            operand2 = stack_.top();
            stack_.pop();
            stack_.push(operand1 + operand2);
            queue.pop();
        } else if (queue.front() == "-") {
            operand1 = stack_.top();
            stack_.pop();
            operand2 = stack_.top();
            stack_.pop();
            stack_.push(operand2 - operand1);
            queue.pop();
        } else if (queue.front() == "*") {
            operand1 = stack_.top();
            stack_.pop();
            operand2 = stack_.top();
            stack_.pop();
            stack_.push(operand2 * operand1);
            queue.pop();
        } else if (queue.front() == "/") {
            operand1 = stack_.top();
            stack_.pop();
            operand2 = stack_.top();
            stack_.pop();
            stack_.push(operand2 / operand1);
            queue.pop();
        }
    }
    return stack_.top();
}

int main() {
    std::string infix, postfix;
    std::cin >> infix;
    std::cout << from_infix_to_num(infix);
    return 0;
}

//https://contest.yandex.ru/contest/29755/run-report/54097174/
