#include "MainWidgets.h"

/**
 * \brief 主窗口GUI函数
 * \param parent 父窗口指针
 */
MainWidgets::MainWidgets(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.toolButton, SIGNAL(clicked()), this, SLOT(onToolButton()));
    GetFileMethods methods;
    QFileInfoList fileList;
    methods.GetFileInfo(R"(C:\Users\PathFolder)", &fileList);
    methods.toJsonList();
}

void MainWidgets::onToolButton() const
{
    const auto* select_dialog = new SelectDialog();
    QString const dir = select_dialog->selectFolder("选择", R"(C:\ProgramData\RunPlus)");
    ui.lineEdit->setText(dir);
    delete select_dialog;
}

MainWidgets::~MainWidgets() = default;