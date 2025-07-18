#include "TableItemData.h"

MergeItemData::MergeItemData(QObject* parent)
    : QObject(parent)
{
}

MergeItemData::MergeItemData(QPair<int, int> begin, QPair<int, int> end)
{
    this->_beginMergeCell = begin;
    this->_endMergeCell = end;
}

MergeItemData& MergeItemData::operator=(const MergeItemData& item)
{
    this->_beginMergeCell = item._beginMergeCell;
    this->_endMergeCell = item._endMergeCell;
    return *this;
}

MergeItemData::MergeItemData(const MergeItemData& item)
{
    *this = item;
}

MergeItemData::~MergeItemData()
{
}

void MergeItemData::setBeginMergeCell(int beginRow, int beginColumn)
{
    this->_beginMergeCell.first = beginRow;
    this->_beginMergeCell.second = beginColumn;
}

void MergeItemData::setEndMergeCell(int endRow, int endColumn)
{
    this->_endMergeCell.first = endRow;
    this->_endMergeCell.second = endColumn;
}

QPair<int, int> MergeItemData::beginMergeCell() const
{
    return this->_beginMergeCell;
}

QPair<int, int> MergeItemData::endMergeCell() const
{
    return this->_endMergeCell;
}

TableData::TableData(QObject* parent)
{
}

TableData::TableData(int rows, int columns, QList<QList<TextItemData>> cellItems, QList<MergeItemData> mergeCellItems)
{
    this->setRows(rows);
    this->setColumns(columns);
    this->setCellItems(cellItems);
    this->setMergeCellItems(mergeCellItems);
}

TableData::~TableData()
{
}

TableData& TableData::operator=(const TableData& item)
{
    this->_columns = item._columns;
    this->_rows = item._rows;
    this->_height = item._height;
    this->_cellItems = item._cellItems;
    this->_mergeCellItems = item._mergeCellItems;
    return *this;
}

TableData::TableData(const TableData& item)
{
    *this = item;
}

int TableData::columns() const
{
    return this->_columns;
}
int TableData::rows() const
{
    return this->_rows;
}
double TableData::height() const
{
    return this->_height;
}

QList<QList<TextItemData>> TableData::cellItems() const
{
    return this->_cellItems;
}

QList<MergeItemData> TableData::mergeCellItems() const
{
    return this->_mergeCellItems;
}

void TableData::setColumns(int columns)
{
    this->_columns = columns;
}

void TableData::setRows(int rows)
{
    this->_rows = rows;
}

void TableData::setHeight(double height)
{
    this->_height = height;
}

void TableData::setCellItems(const QList<QList<TextItemData>>& cellItems)
{
    this->_cellItems = cellItems;
}

void TableData::setMergeCellItems(const QList<MergeItemData>& mergeCellItems)
{
    this->_mergeCellItems = mergeCellItems;
}