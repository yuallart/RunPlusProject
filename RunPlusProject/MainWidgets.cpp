#include "MainWidgets.h"

#include <iostream>


/**
 * \brief 主窗口构造函数
 * \param parent 父窗口指针
 */
MainWidgets::MainWidgets(QWidget* parent): QMainWindow(parent)
{
    ui.setupUi(this);
    signalMapper = new QSignalMapper(this);
    mainConfig->initConfig();
    initFirstToolButton();
}

MainWidgets::~MainWidgets() = default;
/**
 * \brief 点击事件
 * \param target 接收的参数
 */
void MainWidgets::onToolButton(const QString& target) const
{
    qDebug() << target;
    QString const dir = selectDialog->selectFolder("选择", R"(C:\ProgramData\RunPlus)");
    ui.lineEdit_1->setText(dir);
}

void MainWidgets::initFirstToolButton() const
{
    connect(ui.toolButton_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.toolButton_1, "true");
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onToolButton(QString)));
}
