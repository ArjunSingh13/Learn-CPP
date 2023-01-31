// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "console.h"

#include "1Constructor.h"
#include "2Inheritance.h"
#include "3Polymorphism.h"
#include "4SmartPtrs.hpp"//
#include "5Stl.h"
#include "6Stl.h"
#include "7Lambda.h"

using namespace std;


int main()
{
    cout << __FILE__ << ">------- Welcome to CPP training -------<\r\n"; 

#ifdef PLAYER
    //Player file test
    testDefaultConstructor();
    test2ParamConstructor();
    testPointerConstructor();
#endif 

#ifdef PLAYER1
    // Player1 file test
    testConstructorParamAndDefaultValue();
    testCopyConstructor();
#endif

#ifdef PLAYER2
    // Player2 file test
    printData(__FILE__, "testing Deep Copy Constructor:\n", SKY_BLUE);
    testDeepCopyConstructor();

    printData(__FILE__, "testing Move Constructor:\n", SKY_BLUE);
    testMoveConstructor();
    testDisplayActivePlayers();
#endif

#ifdef PLAYER3 // assignment operator

    testAssignmentOperator();
    testMoveOperator();
#endif

#ifdef BASE
    testBasicInheritance();
    testInheritance_CorrectBaseConstructorCall();
    testOperators();
#endif

#ifdef ACCOUNT
    testStaticBinding();
#endif

#ifdef ACCOUNT1
    testDynamicBinding();
#endif

#ifdef ACCOUNT2
    testVectorDynamicBinding();
    testInterfacePrintable();
#endif

#ifdef SMART_PTR
    testSharedPtr();

#endif // SMART_PTR

   // testFunctionTemplate();
   // testClassTemplate();
   // testArrayTemplate();
   // testIterator();
   // testIteratorSet();
   // testIterators1();
   // testIteratorList();
   // testIteratorMap();

   // testAlgoFind();
   // testAlgoCountIf();
   // testAlgoTransform();

   // testMultiplyClass();
    
    testLambda();
    return 1;
}
