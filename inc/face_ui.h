/********************************************************************************
** Form generated from reading UI file 'face.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_H
#define UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Face
{
public:
    QWidget *centralwidget;
    QStackedWidget *Page;
    QWidget *face_recognition_page;
    QLabel *label;
    QWidget *log_page;
    QTableWidget *log_table;
    QPushButton *next_page_of_log;
    QWidget *new_face_page;
    QLabel *new_face_label;
    QPushButton *ok;
    QMenuBar *menubar;
    QMenu *face_recognition;
    QMenu *log;
    QMenu *new_face;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Face)
    {
        if (Face->objectName().isEmpty())
            Face->setObjectName(QString::fromUtf8("Face"));
        Face->resize(480, 640);
        centralwidget = new QWidget(Face);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Page = new QStackedWidget(centralwidget);
        Page->setObjectName(QString::fromUtf8("Page"));
        Page->setGeometry(QRect(0, 0, 480, 612));
        face_recognition_page = new QWidget();
        face_recognition_page->setObjectName(QString::fromUtf8("face_recognition_page"));
        label = new QLabel(face_recognition_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 421, 541));
        label->setAlignment(Qt::AlignCenter);
        Page->addWidget(face_recognition_page);
        log_page = new QWidget();
        log_page->setObjectName(QString::fromUtf8("log_page"));
        log_table = new QTableWidget(log_page);
        if (log_table->columnCount() < 3)
            log_table->setColumnCount(3);
        if (log_table->rowCount() < 10)
            log_table->setRowCount(10);
        log_table->setObjectName(QString::fromUtf8("log_table"));
        log_table->setGeometry(QRect(30, 100, 392, 375));
        log_table->setAutoScroll(false);
        log_table->setAutoScrollMargin(0);
        log_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        log_table->setTabKeyNavigation(false);
        log_table->setProperty("showDropIndicator", QVariant(false));
        log_table->setDragDropOverwriteMode(false);
        log_table->setShowGrid(true);
        log_table->setSortingEnabled(false);
        log_table->setWordWrap(true);
        log_table->setCornerButtonEnabled(false);
        log_table->setRowCount(10);
        log_table->setColumnCount(3);
        log_table->horizontalHeader()->setCascadingSectionResizes(false);
        log_table->horizontalHeader()->setDefaultSectionSize(130);
        log_table->verticalHeader()->setVisible(false);
        log_table->verticalHeader()->setDefaultSectionSize(35);
        next_page_of_log = new QPushButton(log_page);
        next_page_of_log->setObjectName(QString::fromUtf8("next_page_of_log"));
        next_page_of_log->setGeometry(QRect(330, 510, 88, 27));
        Page->addWidget(log_page);
        new_face_page = new QWidget();
        new_face_page->setObjectName(QString::fromUtf8("new_face_page"));
        new_face_label = new QLabel(new_face_page);
        new_face_label->setObjectName(QString::fromUtf8("new_face_label"));
        new_face_label->setGeometry(QRect(30, 30, 421, 541));
        new_face_label->setAlignment(Qt::AlignCenter);
        ok = new QPushButton(new_face_page);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(195, 460, 90, 80));
        Page->addWidget(new_face_page);
        Face->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Face);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 28));
        face_recognition = new QMenu(menubar);
        face_recognition->setObjectName(QString::fromUtf8("face_recognition"));
        log = new QMenu(menubar);
        log->setObjectName(QString::fromUtf8("log"));
        new_face = new QMenu(menubar);
        new_face->setObjectName(QString::fromUtf8("new_face"));
        Face->setMenuBar(menubar);
        statusbar = new QStatusBar(Face);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Face->setStatusBar(statusbar);

        menubar->addAction(face_recognition->menuAction());
        menubar->addAction(log->menuAction());
        menubar->addAction(new_face->menuAction());

        retranslateUi(Face);

        Page->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Face);
    } // setupUi

    void retranslateUi(QMainWindow *Face)
    {
        Face->setWindowTitle(QCoreApplication::translate("Face", "MainWindow", nullptr));
        label->setText(QString());
        next_page_of_log->setText(QCoreApplication::translate("Face", "Next", nullptr));
        new_face_label->setText(QString());
        ok->setText(QCoreApplication::translate("Face", "\345\275\225\345\205\245", nullptr));
        face_recognition->setTitle(QCoreApplication::translate("Face", "\344\272\272\350\204\270\350\257\206\345\210\253", nullptr));
        log->setTitle(QCoreApplication::translate("Face", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        new_face->setTitle(QCoreApplication::translate("Face", "\345\275\225\345\205\245\346\226\260\344\272\272\350\204\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Face: public Ui_Face {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_H
