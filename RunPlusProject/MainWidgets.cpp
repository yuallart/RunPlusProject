#include "MainWidgets.h"

/**
 * \brief ������GUI����
 * \param parent ������ָ��
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
    QString const dir = select_dialog->selectFolder("ѡ��", R"(C:\ProgramData\RunPlus)");
    ui.lineEdit->setText(dir);
    delete select_dialog;
}

MainWidgets::~MainWidgets() = default;