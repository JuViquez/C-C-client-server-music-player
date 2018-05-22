/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *sliderProgress;
    QLabel *label_2;
    QSlider *sliderVolume;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QListWidget *panel;
    QListWidget *playlist;
    QPushButton *BtnAdd;
    QPushButton *Remove;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(504, 341);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 300, 168, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 244, 491, 42));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sliderProgress = new QSlider(layoutWidget1);
        sliderProgress->setObjectName(QStringLiteral("sliderProgress"));
        sliderProgress->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, sliderProgress);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sliderVolume = new QSlider(layoutWidget1);
        sliderVolume->setObjectName(QStringLiteral("sliderVolume"));
        sliderVolume->setValue(99);
        sliderVolume->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, sliderVolume);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 20, 231, 211));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        panel = new QListWidget(layoutWidget2);
        panel->setObjectName(QStringLiteral("panel"));

        gridLayout->addWidget(panel, 0, 1, 1, 1);

        playlist = new QListWidget(layoutWidget2);
        playlist->setObjectName(QStringLiteral("playlist"));

        gridLayout->addWidget(playlist, 0, 0, 1, 1);

        BtnAdd = new QPushButton(layoutWidget2);
        BtnAdd->setObjectName(QStringLiteral("BtnAdd"));

        gridLayout->addWidget(BtnAdd, 1, 1, 1, 1);

        Remove = new QPushButton(layoutWidget2);
        Remove->setObjectName(QStringLiteral("Remove"));

        gridLayout->addWidget(Remove, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "Stop", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Start", nullptr));
        label->setText(QApplication::translate("Dialog", "Progress", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Volume", nullptr));
        BtnAdd->setText(QApplication::translate("Dialog", "Add to Playlist", nullptr));
        Remove->setText(QApplication::translate("Dialog", "Remove ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
