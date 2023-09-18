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

    cout << "문자열 입력 : ";
    getline(cin, input);

    sh.setInput(input);

    cout << "알파벳 대문자의 갯수 : " << sh.getUpperNum() << "\n";
    cout << "알파벳 소문자의 갯수 : " << sh.getLowerNum() << "\n";
    cout << "숫자의 갯수 : " << sh.getDecimalNum() << "\n";
    cout << "문자열의 길이 : " << sh.getLen() << "\n";

    return 0;
}


