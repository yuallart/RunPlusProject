#pragma once
#include <QTextStream>
#include <utility>
#include <QDebug>
#include <QFile>
/**
 * \brief 文件读取类
 */
class ReadFile
{
private:
    QString errorText = "";
    QByteArray* fileCodec = new QByteArray("UTF-8");
public:
    explicit ReadFile(QByteArray* fileCodec) : fileCodec(fileCodec)
    {
    }

    ReadFile() = default;

    QString getErrorText() const
    {
        return errorText;
    }

    /**
     * \brief 文件内容读取方法
     * \param filePath 文件路径
     * \return 返回读取到的文件内容
     */
    QString readFileData(const QByteArray& filePath);

    QString readFileData(const QString& filePath);
};
