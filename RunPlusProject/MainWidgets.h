#pragma once
#include <QDebug>
#include "MainWidgets.h"
#include "ui_MainWidgets.h"
#include "SelectDialog.h"
#include "GetFileMethods.h"

class MainWidgets : public QMainWindow
{
    Q_OBJECT

public slots:
    void onToolButton() const;

public:
    explicit MainWidgets(QWidget* parent = nullptr);
    ~MainWidgets() override;

private:
    Ui::MainWidgetsClass ui;
};
