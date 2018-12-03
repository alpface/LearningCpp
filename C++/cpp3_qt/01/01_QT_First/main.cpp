#include "mywidget.h"
#include <QApplication> // 包含头文件 应用程序

/// 程序的入口
/// @param argc 命令行变量数量
/// @param argv 命令行变量数组
int main(int argc, char *argv[])
{
    // a是应用程序对象，程序中有且仅有一个
    QApplication a(argc, argv);
    // 窗口 创建MyWidget对象，MyWidget的基类是QWidget
    MyWidget w;
    // 窗口默认是不会弹出的，需要调用show弹出
    w.show();

    // exec让app进入死循环状态，保持app一直在运行
    return a.exec();
}
