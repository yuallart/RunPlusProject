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
	 * \brief ��һ���ļ�ѡ����dialog
	 * \param directoryTitle ����dialog�ı���
	 * \param configDirectory �ļ�ѡ������Ĭ��·��
	 * \return �����û�ѡ����ļ�·��
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
