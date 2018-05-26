/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *BtnPrevious;
    QPushButton *BtnPause;
    QPushButton *BtnNext;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *sliderProgress;
    QLabel *label_2;
    QSlider *sliderVolume;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QListWidget *panel;
    QPushButton *BtnAdd;
    QPushButton *Remove;
    QPushButton *BtnRefresh;
    QPushButton *BtnShuffle;
    QListWidget *playlist;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *positionLabel;
    QLabel *backslashlabel;
    QLabel *totalLabel;
    QLabel *imageLabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(736, 463);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 430, 435, 27));
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

        BtnPrevious = new QPushButton(layoutWidget);
        BtnPrevious->setObjectName(QStringLiteral("BtnPrevious"));

        horizontalLayout->addWidget(BtnPrevious);

        BtnPause = new QPushButton(layoutWidget);
        BtnPause->setObjectName(QStringLiteral("BtnPause"));

        horizontalLayout->addWidget(BtnPause);

        BtnNext = new QPushButton(layoutWidget);
        BtnNext->setObjectName(QStringLiteral("BtnNext"));

        horizontalLayout->addWidget(BtnNext);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 374, 711, 67));
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
        layoutWidget2->setGeometry(QRect(440, 30, 281, 321));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        panel = new QListWidget(layoutWidget2);
        panel->setObjectName(QStringLiteral("panel"));

        gridLayout->addWidget(panel, 1, 1, 1, 1);

        BtnAdd = new QPushButton(layoutWidget2);
        BtnAdd->setObjectName(QStringLiteral("BtnAdd"));

        gridLayout->addWidget(BtnAdd, 2, 1, 1, 1);

        Remove = new QPushButton(layoutWidget2);
        Remove->setObjectName(QStringLiteral("Remove"));

        gridLayout->addWidget(Remove, 2, 0, 1, 1);

        BtnRefresh = new QPushButton(layoutWidget2);
        BtnRefresh->setObjectName(QStringLiteral("BtnRefresh"));

        gridLayout->addWidget(BtnRefresh, 0, 1, 1, 1);

        BtnShuffle = new QPushButton(layoutWidget2);
        BtnShuffle->setObjectName(QStringLiteral("BtnShuffle"));

        gridLayout->addWidget(BtnShuffle, 0, 0, 1, 1);

        playlist = new QListWidget(layoutWidget2);
        playlist->setObjectName(QStringLiteral("playlist"));

        gridLayout->addWidget(playlist, 1, 0, 1, 1);

        layoutWidget3 = new QWidget(Dialog);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 350, 139, 19));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        positionLabel = new QLabel(layoutWidget3);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));

        horizontalLayout_2->addWidget(positionLabel);

        backslashlabel = new QLabel(layoutWidget3);
        backslashlabel->setObjectName(QStringLiteral("backslashlabel"));

        horizontalLayout_2->addWidget(backslashlabel);

        totalLabel = new QLabel(layoutWidget3);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));

        horizontalLayout_2->addWidget(totalLabel);

        imageLabel = new QLabel(Dialog);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(20, 20, 391, 301));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "Stop", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Start", nullptr));
        BtnPrevious->setText(QApplication::translate("Dialog", "Previous", nullptr));
        BtnPause->setText(QApplication::translate("Dialog", "Pause", nullptr));
        BtnNext->setText(QApplication::translate("Dialog", "Next", nullptr));
        label->setText(QApplication::translate("Dialog", "Progress", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Volume", nullptr));
        BtnAdd->setText(QApplication::translate("Dialog", "Add to Playlist", nullptr));
        Remove->setText(QApplication::translate("Dialog", "Remove ", nullptr));
        BtnRefresh->setText(QApplication::translate("Dialog", "Refresh List", nullptr));
        BtnShuffle->setText(QApplication::translate("Dialog", "Shuffle List", nullptr));
        positionLabel->setText(QApplication::translate("Dialog", "00:00:00", nullptr));
        backslashlabel->setText(QApplication::translate("Dialog", "/", nullptr));
        totalLabel->setText(QApplication::translate("Dialog", "00:00:00", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
