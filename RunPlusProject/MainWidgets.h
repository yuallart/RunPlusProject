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
#include "MainWidgets.h"
#include "ui_MainWidgets.h"
#include "SelectDialog.h"
#include "GetFileInfoMethods.h"
#include "JsonMethods.h"
#include <qsignalmapper.h>
#include <nlohmann/json.hpp>
#include "ConfigParam.h"
#include "WriteFileMethods.h"
#include "ReadFileMethods.h"
/**
 * \brief 主窗口
 */
extern nlohmann::json globalConfig;

class MainWidgets : public QMainWindow
{
    Q_OBJECT

public slots:
    void onToolButton(QString target) const;

public:
    explicit MainWidgets(QWidget* parent = nullptr);
    ~MainWidgets() override;
    void initFirstToolButton() const;
    void initGlobalConfig() const;
private:
    Ui::MainWidgetsClass ui{};
    QSignalMapper* signalMapper;
    GetFileInfoMethods getFileInfoMethods;
    JsonMethods jsonMethods;
    ConfigParam configParam;
    WriteFileMethods writeFileMethods;
    EncodingMethods encodingForm;
    ReadFileMethods readFileMethods;
};
