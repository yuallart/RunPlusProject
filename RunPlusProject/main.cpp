/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...　　　　　　　　　　　　
 * └──────────────────────────────────┘
 */
#include "MainWidgets.h"
#include "main.h"

/**
 * \brief 启动类
 */
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWidgets win;
    const WidgetInit* methods = new WidgetInit(&win);
    methods->initWidgets();
    win.show();
    return QApplication::exec();
}

void WidgetInit::initWidgets() const
{
    this->initTitle();
    this->initBackgroundColor();
}

void WidgetInit::initTitle() const
{
    win->setWindowTitle(u8"运行管理器");
}

void WidgetInit::initBackgroundColor() const
{
    QPalette pal(win->palette());
    pal.setColor(QPalette::Background, "#f1f2f6");
    win->setAutoFillBackground(true);
    win->setPalette(pal);
}
