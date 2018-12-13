/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *loginbutton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *manbtn;
    QRadioButton *womanbtn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(417, 360);
        loginbutton = new QPushButton(Widget);
        loginbutton->setObjectName(QStringLiteral("loginbutton"));
        loginbutton->setGeometry(QRect(0, 10, 131, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/airbnb40x40@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginbutton->setIcon(icon);
        loginbutton->setIconSize(QSize(32, 32));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 110, 66, 88));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        manbtn = new QRadioButton(groupBox);
        manbtn->setObjectName(QStringLiteral("manbtn"));

        verticalLayout_2->addWidget(manbtn);

        womanbtn = new QRadioButton(groupBox);
        womanbtn->setObjectName(QStringLiteral("womanbtn"));

        verticalLayout_2->addWidget(womanbtn);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 100, 79, 88));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 210, 96, 137));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout->addWidget(checkBox_4);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(160, 70, 256, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        loginbutton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        manbtn->setText(QApplication::translate("Widget", "\347\224\267", nullptr));
        womanbtn->setText(QApplication::translate("Widget", "\345\245\263", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\251\232\345\220\246", nullptr));
        radioButton_3->setText(QApplication::translate("Widget", "\345\267\262\345\251\232", nullptr));
        radioButton_4->setText(QApplication::translate("Widget", "\346\234\252\345\251\232", nullptr));
        groupBox_3->setTitle(QApplication::translate("Widget", "\350\260\203\346\237\245\351\227\256\345\215\267", nullptr));
        checkBox->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\217\267", nullptr));
        checkBox_2->setText(QApplication::translate("Widget", "\344\273\267\346\240\274\345\256\236\346\203\240", nullptr));
        checkBox_3->setText(QApplication::translate("Widget", "\345\217\243\345\221\263\344\270\215\351\224\231", nullptr));
        checkBox_4->setText(QApplication::translate("Widget", "\350\200\201\346\235\277\344\272\272\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
