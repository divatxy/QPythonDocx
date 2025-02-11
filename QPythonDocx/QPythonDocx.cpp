#include "QPythonDocx.h"

#include "TextItemData.h"
#include <QDebug>

QPythonDocx::QPythonDocx()
{
}

void QPythonDocx::addParagraphText(const TextItemData& item, const py::object& paragraph)
{
    py::object Pt = _shared.attr("Pt");
    this->addRunText(item, paragraph);
    // 设置段间距 首行缩进 段落对齐方式
    py::object alignment = _docx_enum.attr("WD_ALIGN_PARAGRAPH");
    paragraph.attr("alignment") = alignment.attr(item.alignment().toStdString().c_str());
    paragraph.attr("paragraph_format").attr("first_line_indent") = Pt(item.first_line_indent());
    paragraph.attr("paragraph_format").attr("line_spacing") = Pt(item.lineSpacing());
}

void QPythonDocx::addRunText(const TextItemData& item, const py::object& paragraph)
{
    py::object Pt = _shared.attr("Pt");
    py::object run = paragraph.attr("add_run")(item.text().toStdString());
    // 设置 是否 加粗 倾斜 字体样式 大小
    run.attr("bold") = item.bold();
    run.attr("italic") = item.italic();
    run.attr("font").attr("name") = item.fontName().toStdString();
    run.attr("font").attr("size") = Pt(item.fontSize());
    // 汉字样式
    py::object qn = _oxml_ns.attr("qn");
    run.attr("element").attr("rPr").attr("rFonts").attr("set")(qn("w:eastAsia"), "宋体");
    // 设置颜色
    py::object RGBColor = _shared.attr("RGBColor");
    run.attr("font").attr("color").attr("rgb") = RGBColor.attr("from_string")(item.color().toStdString());
}

void QPythonDocx::setTableCell(const TextItemData& item, const py::object& cell)
{
    // 单位 磅
    py::object Pt = _shared.attr("Pt");
    // 设置文本内容
    auto&& ps = cell.attr("paragraphs");
    int i = 0;
    for (auto&& p : ps) {
        if (!ps.is_none() && py::isinstance<py::list>(ps) && py::len(ps) > 0 && i == 0) {
            this->addParagraphText(item, (*p).cast<py::object>());
        }
    }
}

void QPythonDocx::saveDocx(const QString& path)
{
    _document.attr("save")(path.toStdString());
}

void QPythonDocx::addTable(const TableData& tableData)
{
    py::object Pt = _shared.attr("Pt");
    py::object table = _document.attr("add_table")(tableData.rows(), tableData.columns(), "Table Grid");
    py::list rows = table.attr("rows");

    for (int i = 0; i < tableData.rows(); ++i) {
        py::object row = rows[i];
        // 设置行高
        row.attr("height") = Pt(tableData.height());
        py::list cells = row.attr("cells");
        for (int j = 0; j < tableData.columns(); ++j) {
            py::object cell = cells[j];
            if (tableData.cellItems().size() >= i + 1 || tableData.cellItems()[i].size() >= j + 1) {
                // 设置单元格
                setTableCell(tableData.cellItems()[i][j], cell);
            }
        }
    }

    // 合并单元格
    for (auto&& mergeItem : tableData.mergeCellItems()) {
        int beginRow = mergeItem.beginMergeCell().first;
        int beginColumn = mergeItem.beginMergeCell().second;
        int endRow = mergeItem.endMergeCell().first;
        int endColumn = mergeItem.endMergeCell().second;

        py::object cell_start = table.attr("cell")(beginRow, beginColumn);
        py::object cell_end = table.attr("cell")(endRow, endColumn);
        cell_start.attr("merge")(cell_end);

        // 获取单元格的所有段落
        py::object ps = cell_start.attr("paragraphs");
        py::object first_paragraph = py::none();
        int i = 0;
        auto p_iter = ps.attr("__iter__")(); // 获取段落的迭代器
        while (true) {
            try {
                py::object p = p_iter.attr("__next__")(); // 获取下一个段落
                if (i == 0) {
                    first_paragraph = p;
                } else {
                    if (tableData.rows() >= beginRow + i || tableData.columns() >= beginColumn + i) {
                        // 添加段落运行
                        if (beginRow == endRow) {
                            this->addRunText(tableData.cellItems()[beginRow][beginColumn + i], first_paragraph);
                        } else if (beginColumn == endColumn) {
                            this->addRunText(tableData.cellItems()[beginRow + i][beginColumn], first_paragraph);
                        }
                    }
                    //  删除多余的段落
                    auto&& p_delete = p.attr("_element");
                    p_delete.attr("getparent")().attr("remove")(p_delete);
                }

                i++;
            } catch (py::error_already_set& e) {
                break; // 迭代完成时跳出循环
            }
        }
    }
}

py::object QPythonDocx::addParagraph()
{
    py::object p = _document.attr("add_paragraph")("");
    return p;
}
