// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char op) {
    switch (op) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    }
}

std::string infx2pstfx(std::string inf) {
    Tstack<char, 100> stack1;
    std::string result = "";
    for (int i = 0; i < inf.size(); i++) {
        if (isdigit(inf[i]) != 0) {
            if (isdigit(inf[i - 1]) || result == "") {
                result += inf[i];
            } else {
                result += " ";
                result += inf[i];
            }
        } else if (getPrior(inf[i]) == 0 || getPrior(inf[i]) > getPrior(stack1.get()) || stack1.isEmpty()) {
            if (getPrior(inf[i]) == 0 && stack1.isEmpty() || !isdigit(inf[i - 1])) {
                stack1.push(inf[i]);
            } else {
                //result += " ";
                stack1.push(inf[i]);
            }
        } else if (getPrior(inf[i]) == 2 || getPrior(inf[i]) == 3) {
            while (getPrior(inf[i]) <= getPrior(stack1.get())) {
                
                result += stack1.pop();
                //result += " ";
            }
            stack1.push(inf[i]);
        } else if (getPrior(inf[i]) == 1) {
            while (getPrior(stack1.get()) != 0) {
                result += " ";
                result += stack1.pop();
            } if (isdigit(inf[i + 1]) || getPrior(inf[i + 1]) == 1) {
                //result += " ";
                stack1.pop();
            } else {
                stack1.pop();
            }
        }
    }
    while (!stack1.isEmpty()) {
        result += " ";
        result += stack1.pop();
    }
    return std::string(result);
}

int eval(std::string post) {
    Tstack<int, 100> stack2;
    for (int i = 0; i < post.size(); i++) {
        if (isdigit(post[i])) {
            int value = post[i] - '0';
            stack2.push(value);
        } else if (getPrior(post[i]) == 2 || getPrior(post[i]) == 3) {
            int value2 = stack2.pop();
            int value1 = stack2.pop();
            switch (post[i]) {
            case '+':
                stack2.push(value1 + value2);
                break;
            case '-':
                stack2.push(value1 - value2);
                break;
            case '*':
                stack2.push(value1 * value2);
                break;
            case '/':
                stack2.push(value1 / value2);
                break;
            }
        }
    }
    return stack2.pop();
}
