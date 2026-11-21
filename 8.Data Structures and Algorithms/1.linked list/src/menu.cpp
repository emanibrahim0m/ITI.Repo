#include <iostream>
#include "../include/lib.h"

using namespace std;

int main() {
    LinkedList start;

    start.appendHeadData(5);
    start.getDataByIndex(0);
    start.insertAfter(5, 60);
    start.insertBefore(60, 90);
    start.getDataByIndex(90);
    cout << start.GetCount() << endl;


    return 0;   
}

