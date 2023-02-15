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
#include <qsignalmapper.h>
#include <nlohmann/json.hpp>
#include "MainConfig.h"
#include "MainConfig.h"
#include "SelectDialog.h"
#include "GetFileInfo.h"
#include "JsonParse.h"
#include "ReadFile.h"
#include "WriteFile.h"
using json = nlohmann::json;

/**
 * \brief 主窗口
 */
class MainWidgets : public QMainWindow
{
    Q_OBJECT
public slots:
    void onToolButton(QString target) const;

public:
    explicit MainWidgets(QWidget* parent = nullptr);
    ~MainWidgets() override;
    void initFirstToolButton() const;
private:
    Ui::MainWidgetsClass ui{};
    QSignalMapper* signalMapper;
    ReadFile* readFile = new ReadFile();
    GetFileInfo* getFileInfo = new GetFileInfo();
    JsonParse* jsonParse = new JsonParse();
    WriteFile* writeFile = new WriteFile();
    MainConfig* mainConfig = new MainConfig(ui, getFileInfo, readFile, writeFile, jsonParse);
};
