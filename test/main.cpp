#include <QtCore/QCoreApplication>

#include "QPythonDocx.h"
#include "TableItemData.h"
#include "TextItemData.h"

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
int main()
{
    try {

        //// 导入python-docx库
        // py::module docx_module = py::module::import("docx");
        // py::module shared = py::module::import("docx.shared");
        //// 导入oxml_ns
        // py::module oxml_ns = py::module::import("docx.oxml.ns");
        // py::object RGBColor = shared.attr("RGBColor");
        //// py::object document = docx_module.attr("Document")();
        // py::object inches = shared.attr("Inches")(1.25);
        //  保存docx文件
        //  document.attr("save")("demo.docx");
    } catch (py::error_already_set& e) {
        qDebug() << e.what();
        return false;
    } catch (const std::exception& e) {
        qDebug() << e.what();
        return false;
    } catch (...) {
        qDebug() << "unknown exception";
        return false;
    }
    py::scoped_interpreter guard {};
    TextItemData data;
    data.setText("aaaaa从鼠标选中的地方");
    QPythonDocx docx;
    auto&& paragraph1 = docx.addParagraph();
    docx.addParagraphText(data, paragraph1);

    TextItemData a("陶欣渝1111111111");
    a.setAlignment("CENTER");
    TableData table(2, 3, { { a, a, a }, { a, a, a } }, { MergeItemData({ qMakePair(0, 0) }, { qMakePair(0, 2) }) });
    docx.addTable(table);
    docx.saveDocx("demo1.docx");
    return 0;
}
