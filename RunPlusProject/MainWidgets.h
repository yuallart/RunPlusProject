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
