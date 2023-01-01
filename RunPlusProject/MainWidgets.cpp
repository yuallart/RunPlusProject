#include "MainWidgets.h"

#include <iostream>
nlohmann::json globalConfig({});
/**
 * \brief 主窗口构造函数
 * \param parent 父窗口指针
 */
MainWidgets::MainWidgets(QWidget* parent): QMainWindow(parent)
{
    ui.setupUi(this);
    signalMapper = new QSignalMapper(this);
    initGlobalConfig();
    initFirstToolButton();
}

/**
 * \brief 点击事件
 * \param target 接收的参数
 */
void MainWidgets::onToolButton(QString target) const
{
    qDebug() << target;
    const auto* select_dialog = new SelectDialog();
    QString const dir = select_dialog->selectFolder("选择", R"(C:\ProgramData\RunPlus)");
    ui.lineEdit->setText(dir);
    delete select_dialog;
}

MainWidgets::~MainWidgets() = default;

void MainWidgets::initFirstToolButton() const
{
    connect(ui.toolButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.toolButton, "true");
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onToolButton(QString)));
}

void MainWidgets::initGlobalConfig() const
{
    EncodingForm
    const std::string jsonStr = jsonMethods.outputJsonStr(configParam.configJson, false);
    std::cout <<  << std::endl;
    putFileMethods.writeFile(configParam.configFilePath.toLatin1(), jsonStr.c_str());
}
