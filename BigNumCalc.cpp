#include "BigNumCalc.h"

std::list<int> bigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> num;
    for (char digit : numString) {
        num.push_back(digit - '0');
    }
    return num;
}

std::list<int> bigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int carry = 0;
    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = (it1 != num1.rend() ? *it1++ : 0) + (it2 != num2.rend() ? *it2++ : 0) + carry;
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> bigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int borrow = 0;
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int diff = (it1 != num1.rend() ? *it1++ : 0) - (it2 != num2.rend() ? *it2++ : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
    }

    // Remove leading zeros from the result
    while (!result.empty() && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> bigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    if (num2.size() > 1) {
        // This implementation assumes num2 is a single digit
        throw std::invalid_argument("num2 should be a single digit for multiplication");
    }

    int multiplier = num2.front();
    std::list<int> result;
    auto it1 = num1.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || carry) {
        int product = (it1 != num1.rend() ? *it1++ : 0) * multiplier + carry;
        result.push_front(product % 10);
        carry = product / 10;
    }

    // Remove leading zeros from the result
    while (!result.empty() && result.front() == 0) {
        result.pop_front();
    }

    return result;
}
