#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 계산 결과 구조체
struct History {
    string operation; // 연산자 (+, -, *, / 등)
    double result;    // 계산 결과
};

vector<History> history; // 히스토리 저장 벡터

// 길이 단위 변환 함수
double convertLength(double value, string fromUnit, string toUnit) {
    if (fromUnit == "m" && toUnit == "cm") {
        return value * 100;
    } else if (fromUnit == "m" && toUnit == "km") {
        return value / 1000;
    } else if (fromUnit == "cm" && toUnit == "m") {
        return value / 100;
    } else if (fromUnit == "km" && toUnit == "m") {
        return value * 1000;
    }
    return -1; // 유효하지 않은 변환
}

// 무게 단위 변환 함수
double convertWeight(double value, string fromUnit, string toUnit) {
    if (fromUnit == "kg" && toUnit == "g") {
        return value * 1000;
    } else if (fromUnit == "g" && toUnit == "kg") {
        return value / 1000;
    } else if (fromUnit == "kg" && toUnit == "lb") {
        return value * 2.20462;
    } else if (fromUnit == "lb" && toUnit == "kg") {
        return value / 2.20462;
    }
    return -1; // 유효하지 않은 변환
}

// 온도 단위 변환 함수
double convertTemperature(double value, string fromUnit, string toUnit) {
    if (fromUnit == "C" && toUnit == "F") {
        return (value * 9/5) + 32;
    } else if (fromUnit == "F" && toUnit == "C") {
        return (value - 32) * 5/9;
    } else if (fromUnit == "C" && toUnit == "K") {
        return value + 273.15;
    } else if (fromUnit == "K" && toUnit == "C") {
        return value - 273.15;
    }
    return -1; // 유효하지 않은 변환
}

// 히스토리 출력 함수
void printHistory() {
    if (history.empty()) {
        cout << "히스토리가 없습니다." << endl;
    } else {
        cout << "---- 계산 히스토리 ----" << endl;
        for (size_t i = 0; i < history.size(); ++i) {
            cout << i + 1 << ". " << history[i].operation << " = " << history[i].result << endl;
        }
    }
}

int main() {
    int choice;
    double value, convertedValue;
    string fromUnit, toUnit;
    string operation;
    double result;

    while (true) {
        cout << "계산기 기능 선택:" << endl;
        cout << "1. 사칙연산" << endl;
        cout << "2. 길이 단위 변환" << endl;
        cout << "3. 무게 단위 변환" << endl;
        cout << "4. 온도 단위 변환" << endl;
        cout << "5. 히스토리 보기" << endl;
        cout << "6. 히스토리 삭제" << endl;
        cout << "7. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double num1, num2;
                char op;
                cout << "첫 번째 숫자를 입력하세요: ";
                cin >> num1;
                cout << "연산자를 입력하세요 (+, -, *, /): ";
                cin >> op;
                cout << "두 번째 숫자를 입력하세요: ";
                cin >> num2;

                switch(op) {
                    case '+':
                        result = num1 + num2;
                        operation = to_string(num1) + " + " + to_string(num2);
                        break;
                    case '-':
                        result = num1 - num2;
                        operation = to_string(num1) + " - " + to_string(num2);
                        break;
                    case '*':
                        result = num1 * num2;
                        operation = to_string(num1) + " * " + to_string(num2);
                        break;
                    case '/':
                        if (num2 != 0) {
                            result = num1 / num2;
                            operation = to_string(num1) + " / " + to_string(num2);
                        } else {
                            cout << "오류: 0으로 나눌 수 없습니다!" << endl;
                            continue;
                        }
                        break;
                    default:
                        cout << "유효하지 않은 연산자입니다." << endl;
                        continue;
                }
                cout << "결과: " << result << endl;
                
                // 히스토리에 결과 저장
                history.push_back({operation, result});
                break;
            }
            case 2: {
                cout << "길이 단위 변환:" << endl;
                cout << "변환할 값을 입력하세요: ";
                cin >> value;
                cout << "변환할 단위 (m, cm, km): ";
                cin >> fromUnit;
                cout << "변환할 단위 (m, cm, km): ";
                cin >> toUnit;

                convertedValue = convertLength(value, fromUnit, toUnit);
                if (convertedValue != -1) {
                    cout << value << " " << fromUnit << "은(는) " << convertedValue << " " << toUnit << "입니다." << endl;
                    history.push_back({to_string(value) + " " + fromUnit + " to " + toUnit, convertedValue});
                } else {
                    cout << "유효하지 않은 단위 변환입니다." << endl;
                }
                break;
            }
            case 3: {
                cout << "무게 단위 변환:" << endl;
                cout << "변환할 값을 입력하세요: ";
                cin >> value;
                cout << "변환할 단위 (kg, g, lb): ";
                cin >> fromUnit;
                cout << "변환할 단위 (kg, g, lb): ";
                cin >> toUnit;

                convertedValue = convertWeight(value, fromUnit, toUnit);
                if (convertedValue != -1) {
                    cout << value << " " << fromUnit << "은(는) " << convertedValue << " " << toUnit << "입니다." << endl;
                    history.push_back({to_string(value) + " " + fromUnit + " to " + toUnit, convertedValue});
                } else {
                    cout << "유효하지 않은 단위 변환입니다." << endl;
                }
                break;
            }
            case 4: {
                cout << "온도 단위 변환:" << endl;
                cout << "변환할 값을 입력하세요: ";
                cin >> value;
                cout << "변환할 단위 (C, F, K): ";
                cin >> fromUnit;
                cout << "변환할 단위 (C, F, K): ";
                cin >> toUnit;

                convertedValue = convertTemperature(value, fromUnit, toUnit);
                if (convertedValue != -1) {
                    cout << value << " " << fromUnit << "은(는) " << convertedValue << " " << toUnit << "입니다." << endl;
                    history.push_back({to_string(value) + " " + fromUnit + " to " + toUnit, convertedValue});
                } else {
                    cout << "유효하지 않은 단위 변환입니다." << endl;
                }
                break;
            }
            case 5: {
                printHistory();
                break;
            }
            case 6: {
                history.clear();
                cout << "히스토리가 삭제되었습니다." << endl;
                break;
            }
            case 7:
                cout << "계산기를 종료합니다." << endl;
                return 0;
            default:
                cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
        }
    }
}