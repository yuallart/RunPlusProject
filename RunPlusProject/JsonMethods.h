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
#include <nlohmann/json.hpp>
#include "EncodingForm.h"

class JsonMethods : public EncodingForm
{
public:
    /**
     * \brief 生成JSON字符串方法
     * \param jsonStr 接收一个json对象
     * \return 返回一个json格式string字符串
     */
    std::string outputJsonStr(const nlohmann::json& jsonStr) const
    {
        return encodingToGBK(jsonStr.dump());
    }

    /**
     * \brief 生成JSON字符串方法
     * \param jsonStr 接收一个json字符串
     * \return 返回一个json格式的string字符串
     */
    std::string outputJsonStr(const std::string& jsonStr) const
    {
        return encodingToGBK(nlohmann::json::parse(jsonStr).dump());
    }

    /**
     * \brief 生成JSON字符串方法
     * \param jsonStr 接收一个json字符串
     * \return 返回一个json格式的string字符串
     */
    std::string outputJsonStr(const char* jsonStr) const
    {
        const nlohmann::json str = nlohmann::json::parse(jsonStr);
        return encodingToGBK(str.dump());
    }
};
