#include "mywidget.h"
#include "QPushButton.h"

//命名规范 以及 快捷键
// 类名 首字母大写 单词与单词之间 首字母大写
// 函数、变量  首字母小写 单词与单词之间 首字母大写
// 快捷键
// 运行  ctrl + R
// 编译  ctrl + B
// 查找  ctrl + F
// 帮助文档 F1
// 字体缩放  ctrl + 鼠标滚轮
// 自动对齐  ctrl + i
// 整行移动 ctrl+ shift + ↑ 或者 ↓
// 同名之间的 .h .cpp切换  F4
// 帮助文档 第一种 ： F1  第二种 ：左侧按钮  第三种：C:\Qt\Qt5.6.0\5.6\mingw49_32\bin
// 注释快捷键  ctrl + /

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) // 初始化列表
{
}

MyWidget::~MyWidget()
{

}
