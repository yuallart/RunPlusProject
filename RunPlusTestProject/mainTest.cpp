/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ©∞©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©¥
 * ©¶°°\author: Yuallart                                                  
 * ©¶°°\version: 1.0.0
 * ©¶  \saying: ≤ªæ≠“ª∑¨∫Æ≥ππ«£¨‘ıµ√√∑ª®∆À±«œ„
 * ©¶  \deprecated: The project must be described...°°°°°°°°°°°°°°°°°°°°°°°°                        
 * ©∏©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©º
 */

#include "mainTest.h"

void mainTest::jsonMethods() const
{
    JsonMethodsTest json_methods_test;
    QTest::qExec(&json_methods_test);
}

void main()
{
    mainTest main_test;
    main_test.jsonMethods();
    char a = getchar();
}