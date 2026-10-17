#include "../my_stl/stack.hpp"
#include "../my_stl/string.hpp"
#include <iostream>
#include <iomanip>

using namespace gyx;

double calc(double a, double b, char op)
{
    double ret = 0;
    switch (op)
    {
    case '+':
        ret = a + b;
        break;
    case '-':
        ret = a - b;
        break;
    case '*':
        ret = a * b;
        break;
    case '/':
        ret = a / b;
        break;
    default:
        break;
    }
    return ret;
}

// 符号入栈时，如果栈顶的优先级大于等于自己(等于也包含，因为同优先级从左往右计算，左边实际还是优先级更高)
// 那么必须先算栈顶，直到要入栈的符号优先级比栈顶高
void calc_one_expression()
{
    // 由于对括号有特判，可以给表达式两端加上括号，这样最终结果就在栈顶
    stack<double> nums;
    stack<char> ops;
    string expression;
    std::cin >> expression;
    ops.push('(');
    for (int i = 0; i <= expression.size(); i++)
    {
        int num = 0;
        bool is_num = false;
        char token = i == expression.size() ? ')' : expression[i];
        while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9') // 数字入数栈
        {
            num = num * 10 + expression[i] - '0';
            is_num = true;
            i++;
        }
        if (is_num)
        {
            nums.push(num);
            i--; // 由于最后会i++，导致多加一次，所以这里-1
        }
        else if (token == '+' || token == '-')
        {
            while (!ops.empty() && ops.top() != '(') // 栈顶优先级大于等于自己
            {
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.push(calc(a, b, ops.top()));
                ops.pop();
            }
            ops.push(token);
        }
        else if (token == '*' || token == '/')
        {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) // 栈顶优先级大于等于自己
            {
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.push(calc(a, b, ops.top()));
                ops.pop();
            }
            ops.push(token);
        }
        else if (token == '(')
        {
            ops.push(token);
        }
        else if (token == ')') // 一直算，直到最近左括号
        {
            while (ops.top() != '(')
            {
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.push(calc(a, b, ops.top()));
                ops.pop();
            }
            ops.pop();
        }
    }
    std::cout << std::fixed << std::setprecision(2) << nums.top() << '\n';
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        calc_one_expression();
    }
}
