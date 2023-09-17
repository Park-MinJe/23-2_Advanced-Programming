#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Calculator {
private:
    int num1,
        num2;
    string _operator;

public:
    void setNum1(int pNum);
    void setNum2(int pNum);
    void setOperator(string pOperator);

    int getNum1();
    int getNum2();
    string getOperator();
    string getResult();
};

void Calculator::setNum1(int pNum) {
    num1 = pNum;
}
void Calculator::setNum2(int pNum) {
    num2 = pNum;
}
void Calculator::setOperator(string pOperator) {
    _operator = pOperator;
}

int Calculator::getNum1() {
    return num1;
}
int Calculator::getNum2() {
    return num2;
}
string Calculator::getOperator() {
    return _operator;
}
string Calculator::getResult() {
    if (_operator == "+")
        return to_string(num1 + num2);
    if (_operator == "-")
        return to_string(num1 - num2);
    if (_operator == "*")
        return to_string(num1 * num2);
    if (_operator == "/") {
        if (num2 == 0) return "#DIV/0!";
        else return to_string(num1 / num2);
    }
    if (_operator == "%") {
        if (num2 == 0) return "#DIV/0!";
        else return to_string(num1 % num2);
    }

    return "Error::Not Valid Operator";
}

int main()
{
    Calculator calc = Calculator();
    int lNum1, lNum2, lOperator;
    string input;

    while (1) {
        cout << "수식을 입력하시오. 종료를 원하는 경우 'exit'을 입력하시오.: ";
        getline(cin, input);

        if (input == "exit") {
            cout << "종료합니다...\n";
            break;
        }

        stringstream ss(input);
        string s;
        vector<string> inputSplit;
        while (getline(ss, s, ' ')) {
            inputSplit.push_back(s);
        }
        calc.setNum1(stoi(inputSplit[0]));
        calc.setOperator(inputSplit[1]);
        calc.setNum2(stoi(inputSplit[2]));

        cout << calc.getNum1() << " " << calc.getOperator() << " " << calc.getNum2() << " = " << calc.getResult() << "\n\n";
    }

    return 0;
}