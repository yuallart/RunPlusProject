#pragma once
#include <iostream>
#include <qstring.h>
#include <nlohmann/json.hpp>
#include "ReadFile.h"
#include "GetFileInfo.h"
#include "JsonParse.h"
#include "WriteFile.h"
using json = nlohmann::json;

/**
 * \brief 主界面配置文件处理类
 */
class MainConfig
{
private:
    /*配置文件的位置*/
    const QString configFolderPath = "./config";
    const QString configFilePath = R"(./config/main.json)";
    json configJson = {
        /*环境变量指向的根目录*/
        {"subjectFolderPath", "C:/Users/Public/RunPlusFolder"},
        /*是否分别存放文件夹*/
        {"isSeparate", true},
        /*分别存放文件夹的位置*/
        {
            "separateDetails", {
                /*快捷方式*/
                {"/shortcut", u8"快捷方式"},
                /*可执行文件*/
                {"/script", u8"脚本文件"},
                /*自定义文件*/
                {"/aliasFolder", u8"别名文件"}
            }
        },
        /*导出配置文件夹位置*/
        {"exportFolderPath", ":desktop"}
    };
    Ui::MainWidgetsClass ui;
    GetFileInfo* getFileInfo;
    ReadFile* readFile;
    JsonParse* jsonParse;
    WriteFile* writeFile;
public:
    explicit MainConfig(Ui::MainWidgetsClass& ui, GetFileInfo* getFileInfo, ReadFile* readFile,
                        WriteFile* writeFile, JsonParse* jsonParse):
        ui(ui), getFileInfo(getFileInfo), readFile(readFile), jsonParse(jsonParse), writeFile(writeFile)
    {
    }

    void initConfig() const
    {
        const bool result = getFileInfo->isDirExist(configFolderPath, true);
        std::cout << result << std::endl;
        if (getFileInfo->isFileExist(configFilePath))
        {
            const QString fileText = readFile->readFileData(configFilePath);
            json jsonData = jsonParse->outputJsonData(fileText).getJsonData();
            
            // verifyJsonData(jsonData);
        }
        else
        {
            const std::string jsonText = jsonParse->outputJsonData(configJson).getJsonText();
            writeFile->writeFile(configFilePath, QByteArray::fromStdString(jsonText));
        }
    }

    void readConfig()
    {
    }

    void verifyJsonData(json& jsonData)
    {
    }

    void writerConfig()
    {
        const std::string jsonText = jsonParse->outputJsonData(configJson).getJsonText();
        writeFile->writeFile(configFilePath, QByteArray::fromStdString(jsonText));
    }
};
