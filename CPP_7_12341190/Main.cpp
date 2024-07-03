#include <iostream>
#include "Timestamp.h"
using namespace std;

int main() {
    Timestamp timestamp1 (2006,10,8,12,35,10);
    Timestamp timestamp2 (2024,6,6,10,25,20); 
    cout << timestamp1 << endl;

    timestamp1++;
    cout << timestamp1 << endl;
    timestamp1.select(Timestamp::MINUTE);

    timestamp1--;
    cout << timestamp1 << endl;
    timestamp1.select(Timestamp::YEAR);

    ++timestamp1;
    cout << timestamp1 << endl;
    timestamp1.select(Timestamp::MONTH);

    --timestamp1;
    cout << timestamp1 << endl;

    Timestamp timestamp3 = timestamp1 - timestamp2;
    cout << timestamp3 << endl;
}
