#include "TextItemData.h"

#include "QJsonObject"

TextItemData::TextItemData(QObject* parent)
    : QObject(parent)
{
}

TextItemData::~TextItemData()
{
}

TextItemData::TextItemData(const QString& strText)
{
    this->_text = strText;
}

TextItemData::TextItemData(const TextItemData& item)
{
    *this = item;
}

TextItemData& TextItemData::operator=(const TextItemData& item)
{
    this->_text = item._text;
    this->_fontName = item._fontName;
    this->_fontSize = item._fontSize;
    this->_first_line_indent = item._first_line_indent;
    this->_alignment = item._alignment;
    this->_color = item._color;
    this->_bold = item._bold;
    this->_italic = item._italic;
    this->_level = item._level;
    this->_lineSpacing = item._lineSpacing;
    return *this;
}

TextItemData::operator QJsonObject() const
{
    return this->toJsonObject();
}

QJsonObject TextItemData::toJsonObject() const
{
    QJsonObject json;
    json[TEXT] = this->_text;
    json[FONTNAME] = this->_fontName;
    json[ALIGNMENT] = this->_alignment;
    json[COLOR] = this->_color;
    json[BOLD] = this->_bold;
    json[ITALIC] = this->_italic;
    json[LEVEL] = this->_level;
    json[FONTSIZE] = this->_fontSize;
    json[INDENT] = this->_first_line_indent;
    json[LINESPACING] = this->_lineSpacing;
    return json;
}

TextItemData TextItemData::FromJsonObject(const QJsonObject& json)
{
    TextItemData item;
    item.fromJsonObject(json);
    return item;
}

TextItemData& TextItemData::fromJsonObject(const QJsonObject& json)
{
    if (json.contains(TEXT)) {
        this->_text = json[TEXT].toString();
    } else if (json.contains(FONTNAME)) {
        this->_fontName = json[FONTNAME].toString();
    } else if (json.contains(ALIGNMENT)) {
        this->_alignment = json[ALIGNMENT].toString();
    } else if (json.contains(COLOR)) {
        this->_color = json[COLOR].toString();
    } else if (json.contains(BOLD)) {
        this->_bold = json[BOLD].toBool();
    } else if (json.contains(FONTSIZE)) {
        this->_fontSize = json[FONTSIZE].toInt();
    } else if (json.contains(INDENT)) {
        this->_first_line_indent = json[INDENT].toInt();
    } else if (json.contains(LINESPACING)) {
        this->_lineSpacing = json[LINESPACING].toInt();
    } else if (json.contains(ITALIC)) {
        this->_italic = json[ITALIC].toBool();
    } else if (json.contains(LEVEL)) {
        this->_level = json[LEVEL].toInt();
    }
    return *this;
}

QString TextItemData::text() const
{
    return this->_text;
}

QString TextItemData::fontName() const
{
    return this->_fontName;
}

QString TextItemData::alignment() const
{
    return this->_alignment;
}

int TextItemData::first_line_indent() const
{
    return this->_first_line_indent;
}

int TextItemData::lineSpacing() const
{
    return this->_lineSpacing;
}

QString TextItemData::color() const
{
    return this->_color;
}

bool TextItemData::bold() const
{
    return this->_bold;
}

bool TextItemData::italic() const
{
    return this->_italic;
}

int TextItemData::level() const
{
    return this->_level;
}

int TextItemData::fontSize() const
{
    return _fontSize;
}

void TextItemData::setText(QString text)
{
    this->_text = text;
}

void TextItemData::setAlignment(QString alignment)
{
    this->_alignment = alignment;
}
