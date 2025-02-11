#pragma once

#include "qpythondocx_global.h"
#include <QObject>

#include "TextItemData.h"

class MergeItemData;
class QPYTHONDOCX_EXPORT TableData : public QObject {
    Q_OBJECT

public:
    TableData(QObject* parent = nullptr);

    TableData(int rows, int columns, double height, QList<QList<TextItemData>> cellItems, QList<MergeItemData> mergeCellItems);

    ~TableData();

    TableData& operator=(const TableData& item);

    TableData(const TableData& item);

    int columns() const;
    int rows() const;
    double height() const;
    QList<QList<TextItemData>> cellItems() const;
    QList<MergeItemData> mergeCellItems() const;

    void setColumns(int columns);
    void setRows(int rows);
    void setHeight(double height);
    void setCellItems(const QList<QList<TextItemData>>& cellItems);
    void setMergeCellItems(const QList<MergeItemData>& mergeCellItems);

private:
    int _columns = 0;

    int _rows = 0;

    double _height = 10;

    QList<QList<TextItemData>> _cellItems;

    QList<MergeItemData> _mergeCellItems;
};

class QPYTHONDOCX_EXPORT MergeItemData : public QObject{
    Q_OBJECT

public:
    MergeItemData(QObject* parent);

    MergeItemData(QPair<int, int> begin, QPair<int, int> end);

    MergeItemData& operator=(const MergeItemData& item);

    MergeItemData(const MergeItemData& item);

    ~MergeItemData();

    void setBeginMergeCell(int beginRow, int beginColumn);
    void setEndMergeCell(int endRow, int endColumn);
    QPair<int, int> beginMergeCell() const;
    QPair<int, int> endMergeCell() const;

private:
    QPair<int, int> _beginMergeCell {};
    QPair<int, int> _endMergeCell {};
};
