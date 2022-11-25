/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ������������������������������������������������������������������������
 * ����\author: Yuallart
 * ����\version: 1.0.0
 * ��  \saying: ����һ�������ǣ�����÷���˱���
 * ��  \deprecated: The project must be described...������������������������
 * ������������������������������������������������������������������������
 */
#include <QtWidgets/QApplication>
#include <QDebug>
#include "MainWidgets.h"
#include "main.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWidgets win;
	WidgetInit methods;
	methods.set_win(&win);
	methods.initWidgets();
	return a.exec();
}
