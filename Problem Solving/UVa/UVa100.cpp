#include <iostream>
#include <string>

using namespace std;

void getCycleLength(int number, int &cycleLengthContainer) {
    if (number != 1) {
        cycleLengthContainer += 1;
        if (number % 2 != 0) {
            getCycleLength(3 * number + 1, cycleLengthContainer);
        } else {
            getCycleLength(number / 2, cycleLengthContainer);
        }
    } else {
        cycleLengthContainer += 1;
    }
}

int getMaxCycleLength(int num1, int num2){
    int min = num1, max = num2;
    if(min > max)
        min = num2, max = num1;

    int maxLength = 0;
    for(int i = min; i <= max; i++){
        int cycleLengthContainer = 0;
        getCycleLength(i, cycleLengthContainer);
        if(cycleLengthContainer > maxLength){
            maxLength = cycleLengthContainer;
        }
    }

    return maxLength;
}

int main() {
    int min = 0, max = 0;
    while(cin >> min >> max){
        cout << min << string(" ") << max << string(" ") << getMaxCycleLength(min, max) << endl;
    }

    return 0;
}