/********************************************************************************
** Form generated from reading UI file 'pluginmain.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINMAIN_H
#define UI_PLUGINMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlugInMainClass
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hlay;

    void setupUi(QWidget *PlugInMainClass)
    {
        if (PlugInMainClass->objectName().isEmpty())
            PlugInMainClass->setObjectName(QStringLiteral("PlugInMainClass"));
        PlugInMainClass->resize(600, 400);
        horizontalLayoutWidget = new QWidget(PlugInMainClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 581, 381));
        hlay = new QHBoxLayout(horizontalLayoutWidget);
        hlay->setSpacing(6);
        hlay->setContentsMargins(11, 11, 11, 11);
        hlay->setObjectName(QStringLiteral("hlay"));
        hlay->setContentsMargins(0, 0, 0, 0);

        retranslateUi(PlugInMainClass);

        QMetaObject::connectSlotsByName(PlugInMainClass);
    } // setupUi

    void retranslateUi(QWidget *PlugInMainClass)
    {
        PlugInMainClass->setWindowTitle(QApplication::translate("PlugInMainClass", "PlugInMain", 0));
    } // retranslateUi

};

namespace Ui {
    class PlugInMainClass: public Ui_PlugInMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINMAIN_H
