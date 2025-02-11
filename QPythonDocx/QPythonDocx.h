#pragma once

#include "qpythondocx_global.h"

#include "TableItemData.h"

#undef slots
#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;
#define slots Q_SLOTS

class TextItemData;
class MergeItemData;
class TableData;
class QPYTHONDOCX_EXPORT QPythonDocx {
public:
    QPythonDocx();

    /**
     * @brief 添加段落文本
     * @param item
     */
    void addParagraphText(const TextItemData& item, const py::object& paragraph);

    /**
     * @brief 添加段落运行
     * @param item
     * @param paragraph 所属段落
     */
    void addRunText(const TextItemData& item, const py::object& paragraph);

    void setTableCell(const TextItemData& item, const py::object& cell);

    void saveDocx(const QString& path);

    void addTable(const TableData& table);

    py::object addParagraph();

private:
    py::module _docxModule = py::module::import("docx");
    py::module _shared = py::module::import("docx.shared");
    py::module _docx_enum = py::module::import("docx.enum.text");
    py::module _oxml_ns = py::module::import("docx.oxml.ns");

    py::object _document = _docxModule.attr("Document")();
};
