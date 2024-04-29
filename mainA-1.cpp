#include <iostream>
#include <sstream>
#include "bigNumCalc.h"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string num1, op, num2;

    iss >> num1 >> op >> num2;

    bigNumCalc calculator;
    auto listNum1 = calculator.buildBigNum(num1);
    auto listNum2 = calculator.buildBigNum(num2);

    std::list<int> result;

    if (op == "+") {
        result = calculator.add(listNum1, listNum2);
    }
