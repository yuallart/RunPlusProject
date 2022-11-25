#pragma once
#include <QWidget>
#include <QFileDialog>
#include <QDebug>
class SelectDialog
{
private:
	QWidget* parent = nullptr;
	QFileDialog* fileDialog;
public:

	explicit SelectDialog(QWidget* parent = nullptr)
		: parent(parent)
	{
		fileDialog = new QFileDialog(parent);
	}

	~SelectDialog() = default;
	
	/**
	 * \brief 打开一个文件选择器dialog
	 * \param directoryTitle 弹出dialog的标题
	 * \param configDirectory 文件选择器的默认路径
	 * \return 返回用户选择的文件路径
	 */
	QString selectFolder(const char* directoryTitle = nullptr, const char* configDirectory = nullptr) const
	{
		fileDialog->setFileMode(QFileDialog::Directory);
		fileDialog->setDirectory(QString::fromLocal8Bit(configDirectory));
		QString dir = fileDialog->getExistingDirectory(parent, QString::fromLocal8Bit(directoryTitle));
		delete fileDialog;
		return dir;
	}
};
