/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ������������������������������������������������������������������������
 * ����\author: Yuallart                                                  
 * ����\version: 1.0.0
 * ��  \saying: ����һ�������ǣ�����÷���˱���
 * ��  \deprecated: The project must be described...������������������������                        
 * ������������������������������������������������������������������������
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