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

MainWidgets::~MainWidgets() = default;
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

void MainWidgets::initFirstToolButton() const
{
    connect(ui.toolButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.toolButton, "true");
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onToolButton(QString)));
}

void MainWidgets::initGlobalConfig() const
{
    const bool isFileExist = getFileInfoMethods.isFileExist(configParam.configFilePath);
    if (!isFileExist)
    {
        const std::string jsonStr = jsonMethods.outputJsonStr(configParam.configJson);
        writeFileMethods.writeFile(configParam.configFilePath, QString::fromUtf8(jsonStr.c_str()));
    }
    else
    {
        QString fileText;
        const QString errorText = readFileMethods.readFileAllData(configParam.configFilePath, fileText);
    }
}
