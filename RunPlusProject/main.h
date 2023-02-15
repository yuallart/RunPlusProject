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
class WidgetInit
{
private:
    MainWidgets* win = nullptr;
public:
    explicit WidgetInit(MainWidgets* const win): win(win)
    {
    }

    MainWidgets* get_win() const
    {
        return win;
    }

    void set_win(MainWidgets* win)
    {
        this->win = win;
    }

    void initWidgets() const;

    void initTitle() const;

    void initBackgroundColor() const;
};
