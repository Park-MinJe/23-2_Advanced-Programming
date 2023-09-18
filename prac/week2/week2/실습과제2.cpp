#include <iostream>
#include <string>

using namespace std;

class StringHandler {
private:
    string inputString;
    int upperNum,
        lowerNum,
        decimalNum,
        len;

    void setUpperNum();
    void setLowerNum();
    void setDecimalNum();
    void setLen();

public:
    StringHandler() {
        upperNum = 0;
        lowerNum = 0;
        decimalNum = 0;
        len = 0;
    }

    void setInput(string pInput);

    int getUpperNum();
    int getLowerNum();
    int getDecimalNum();
    int getLen();
};

void StringHandler::setUpperNum() {
    for (int i = 0; i < len; i++) {
        if (inputString[i] >= 65 && inputString[i] <= 90) {
            upperNum++;
        }
    }
}
void StringHandler::setLowerNum() {
    for (int i = 0; i < len; i++) {
        if (inputString[i] >= 97 && inputString[i] <= 122) {
            lowerNum++;
        }
    }
}
void StringHandler::setDecimalNum() {
    for (int i = 0; i < len; i++) {
        if (inputString[i] >= 48 && inputString[i] <= 57) {
            decimalNum++;
        }
    }
}
void StringHandler::setLen() {
    len = inputString.length();
}

void StringHandler::setInput(string pInput) {
    inputString = pInput;

    setLen();
    setUpperNum();
    setLowerNum();
    setDecimalNum();
}

int StringHandler::getUpperNum() {
    return upperNum;
}
int StringHandler::getLowerNum() {
    return lowerNum;
}
int StringHandler::getDecimalNum() {
    return decimalNum;
}
int StringHandler::getLen() {
    return len;
}

int main()
{
    StringHandler sh = StringHandler();
    string input;

    cout << "���ڿ� �Է� : ";
    getline(cin, input);

    sh.setInput(input);

    cout << "���ĺ� �빮���� ���� : " << sh.getUpperNum() << "\n";
    cout << "���ĺ� �ҹ����� ���� : " << sh.getLowerNum() << "\n";
    cout << "������ ���� : " << sh.getDecimalNum() << "\n";
    cout << "���ڿ��� ���� : " << sh.getLen() << "\n";

    return 0;
}


