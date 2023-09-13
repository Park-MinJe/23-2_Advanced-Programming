#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculator {
private:
    int num1,
        num2;
    char _operator;

public:
    void setNum1(int pNum);
    void setNum2(int pNum);
    void setOperator(char pOperator);

    int getNum1();
    int getNum2();
    int getOperator();
    string getResult();
};

void Calculator::setNum1(int pNum) {
    num1 = pNum;
}
void Calculator::setNum2(int pNum) {
    num2 = pNum;
}
void Calculator::setOperator(char pOperator) {
    _operator = pOperator;
}

int Calculator::getNum1() {
    return num1;
}
int Calculator::getNum2() {
    return num2;
}
int Calculator::getOperator() {
    return _operator;
}
string Calculator::getResult() {
    if (_operator == '+')
        return to_string(num1 + num2);
    if (_operator == '-')
        return to_string(num1 - num2);
    if (_operator == '*')
        return to_string(num1 * num2);
    if (_operator == '/') {
        if (num2 == 0) return "#DIV/0!";
        else return to_string(num1 / num2);
    }
}

int main()
{
    Calculator calc = Calculator();
    int lNum1, lNum2, lOperator;
    string input;

    while (1) {
        cout << "수식을 입력하시오. 종료를 원하는 경우 'exit'을 입력하시오.: ";
        cin >> lNum1 >> lOperator >> lNum2;
        getchar();

        /*
        if(input == "exit"){
            break;
        }*/

        //vector<string> inputSplit = split(input, ' ');
        calc.setNum1(lNum1);
        calc.setOperator(lOperator);
        calc.setNum2(lNum2);

        cout << calc.getNum1() << " " << calc.getOperator() << " " << calc.getNum2() << " = " << calc.getResult() << "\n\n";
    }

    return 0;
}


