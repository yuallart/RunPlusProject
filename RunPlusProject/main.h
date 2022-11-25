#pragma once
class WidgetInit
{
private:
	MainWidgets* win = nullptr;
public:

	MainWidgets* get_win() const
	{
		return win;
	}

	void set_win(MainWidgets* win)
	{
		this->win = win;
	}

	void initWidgets() const
	{
		this->initTitle();
		this->initBackgroundColor();
		win->show();
	}

	void initTitle() const
	{
		win->setWindowTitle(QString::fromLocal8Bit("运行增强器"));
	}

	void initBackgroundColor() const
	{
		QPalette pal(win->palette());
		pal.setColor(QPalette::Background, "#f1f2f6");
		win->setAutoFillBackground(true);
		win->setPalette(pal);
		win->show();
	}
};
