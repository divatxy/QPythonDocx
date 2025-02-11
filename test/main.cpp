#include <QtCore/QCoreApplication>

// #include <pybind11/embed.h>
// #include <pybind11/pybind11.h>
//
#include "QPythonDocx.h"
#include "TableItemData.h"
#include "TextItemData.h"
//
// namespace py = pybind11;

int main()
{
    // py::scoped_interpreter guard {};

    // 导入python-docx库
    // py::module docx_module = py::module::import("docx");
    // 导入docx.shared模块
    // py::module shared = py::module::import("docx.shared");
    //// 导入oxml_ns
    // py::module oxml_ns = py::module::import("docx.oxml.ns");

    // py::object RGBColor = shared.attr("RGBColor");
    // py::object document = docx_module.attr("Document")();
    // py::object inches = shared.attr("Inches")(1.25);

    // 保存docx文件
    // document.attr("save")("demo.docx");

    // TextItemData data;
    // data.setText("aaaaa从鼠标选中的地方");
    // QPythonDocx docx;
    // auto&& paragraph1 = docx.addParagraph();
    // docx.addParagraphText(data, paragraph1);

    // TextItemData a("陶欣渝");
    // a.setAlignment("CENTER");
    // TableData table(2, 3, 10, { { a, a, a }, { a, a, a } }, { MergeItemData({ qMakePair(0, 0) }, { qMakePair(0, 2) }) });
    // docx.addTable(table);
    // docx.saveDocx("demo1.docx");

    return 0;
}
