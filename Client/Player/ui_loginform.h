/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QPushButton *BtnEnter;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *userBox;
    QLabel *label_2;
    QLineEdit *passwordBox;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->resize(344, 175);
        BtnEnter = new QPushButton(LoginForm);
        BtnEnter->setObjectName(QStringLiteral("BtnEnter"));
        BtnEnter->setGeometry(QRect(130, 120, 89, 25));
        widget = new QWidget(LoginForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 50, 219, 58));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        userBox = new QLineEdit(widget);
        userBox->setObjectName(QStringLiteral("userBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordBox = new QLineEdit(widget);
        passwordBox->setObjectName(QStringLiteral("passwordBox"));
        passwordBox->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordBox);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", nullptr));
        BtnEnter->setText(QApplication::translate("LoginForm", "Sign In", nullptr));
        label->setText(QApplication::translate("LoginForm", "User:", nullptr));
        label_2->setText(QApplication::translate("LoginForm", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
