#include "boolean.h"
#include <iostream>
using namespace std;

int main()
{

    Boolean falseBoolean,
            trueBoolean(1); //true

    Boolean resultFalseAndTrue = falseBoolean._and(trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean._or(trueBoolean);
    Boolean resultNotFalse = falseBoolean._not();
    Boolean resultFalseAndTrue2 = falseBoolean * trueBoolean;
    Boolean resultTrueOrTrue2 = trueBoolean + trueBoolean;
//
    cout << "resultFalseAndTrue:" << resultFalseAndTrue.getValue() << endl;
    cout << "resultTrueAndTrue :" << resultTrueOrTrue.getValue() << endl;
    cout << "resultNotFalse    :" << resultNotFalse.getValue() << endl;
    cout << "resultFalseAndTrue2:" << resultFalseAndTrue2.getValue() << endl;
    cout << "resultTrueAndTrue2 :" << resultTrueOrTrue2.getValue() << endl;
    return 0;
}
