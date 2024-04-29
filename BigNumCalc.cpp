#include "BigNumCalc.h"

std::list<int> BigNumCalc::BuildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char digit : numString) {
        if (isdigit(digit)) {
            result.push_back(digit - '0');
        }
    }
    return result;
}

std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    int carry = 0;
    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    return result;
}

std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    int borrow = 0;
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int diff = (it1 != num1.rend() ? *it1 : 0) - (it2 != num2.rend() ? *it2 : 0) - borrow;
        if (it1 != num1.rend()) ++it1;
        if (it2 != num2.rend()) ++it2;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_front(diff);
    }

    // Remove leading zeros
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    if (num2.size() != 1) {
        return result; // For simplicity, assume num2 is only one digit
    }

    int multiplier = num2.front();
    auto it1 = num1.rbegin();

    int carry = 0;
    while (it1 != num1.rend() || carry != 0) {
        int product = (it1 != num1.rend() ? *it1 : 0) * multiplier + carry;
        if (it1 != num1.rend()) ++it1;

        result.push_front(product % 10);
        carry = product / 10;
    }

    return result;
}
