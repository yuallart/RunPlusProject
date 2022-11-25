/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...　　　　　　　　　　　　
 * └──────────────────────────────────┘
 */
#pragma once
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
