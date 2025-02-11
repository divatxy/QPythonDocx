#pragma once

#include <QObject>

#include "qpythondocx_global.h"

class QPYTHONDOCX_EXPORT TextItemData : public QObject {
    Q_OBJECT

public:
    TextItemData(QObject* parent = nullptr);
    ~TextItemData();

    TextItemData(const QString& strText);
    TextItemData(const TextItemData& item);

    TextItemData& operator=(const TextItemData& item);

    operator QJsonObject() const;

    QJsonObject toJsonObject() const;

    static TextItemData FromJsonObject(const QJsonObject& json);

    TextItemData& fromJsonObject(const QJsonObject& json);

    QString text() const;
    QString fontName() const;
    QString alignment() const;
    int first_line_indent() const;
    int lineSpacing() const;
    QString color() const;
    bool bold() const;
    bool italic() const;
    int level() const;

    int fontSize() const;

    void setText(QString text);

    void setAlignment(QString alignment);

private:
    // 文本内容
    QString _text = "";
    // 字体大小 (磅)
    int _fontSize = 12;
    // 字体样式
    QString _fontName = "Times New Roman";
    // 段落对齐(大写)
    QString _alignment = "LEFT";
    // 首行缩进 （磅）
    int _first_line_indent = 21;
    // 行间距（磅）
    int _lineSpacing = 18;
    // 字体颜色
    QString _color = "000000";
    // 粗体
    bool _bold = false;
    // 斜体
    bool _italic = false;
    // 标题等级
    int _level = 5;

    constexpr static const char* TEXT = "text";
    constexpr static const char* FONTSIZE = "fontSize";
    constexpr static const char* FONTNAME = "fontName";
    constexpr static const char* ALIGNMENT = "alignment";
    constexpr static const char* INDENT = "indent";
    constexpr static const char* LINESPACING = "lineSpacing";
    constexpr static const char* COLOR = "color";
    constexpr static const char* BOLD = "bold";
    constexpr static const char* ITALIC = "italic";
    constexpr static const char* LEVEL = "level";
};
