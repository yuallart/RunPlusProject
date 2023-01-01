#pragma once
#include <qstring.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct ConfigParam
{
    /*配置文件的位置*/
    QString configFilePath = u8"./config.json";
    json configJson = {
        /*环境变量指向的根目录*/
        {"subjectPathFolder", "C:/Users/Public/RunPlusFolder"},
        {
            /*文件夹分类*/
            "isSeparate", {
                {
                    /*是否将文件分类存放*/
                    {"condition", true},
                    {
                        "details", {
                            {u8"快捷方式", "/shortcut"},
                            /*可执行文件文件夹*/
                            {u8"脚本文件", "/script"},
                            /*自定义文件名文件夹*/
                            {u8"别名文件", "/aliasFolder"}
                        }
                    }
                }
            }
        }
    };
};
