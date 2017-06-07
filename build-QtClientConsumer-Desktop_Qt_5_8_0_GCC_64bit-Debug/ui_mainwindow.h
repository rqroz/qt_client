/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *server_label;
    QLineEdit *server_input;
    QHBoxLayout *horizontalLayout;
    QPushButton *connect_btn;
    QPushButton *disconnect_btn;
    QVBoxLayout *verticalLayout;
    QListView *server_lview;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *update_btn;
    QVBoxLayout *verticalLayout_3;
    QLabel *timing_label;
    QHBoxLayout *horizontalLayout_4;
    QSlider *timing_slider;
    QLabel *timing_output;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start_btn;
    QPushButton *stop_btn;
    QGraphicsView *graph_obj;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(676, 517);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        server_label = new QLabel(centralWidget);
        server_label->setObjectName(QStringLiteral("server_label"));

        verticalLayout_2->addWidget(server_label);

        server_input = new QLineEdit(centralWidget);
        server_input->setObjectName(QStringLiteral("server_input"));

        verticalLayout_2->addWidget(server_input);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        connect_btn = new QPushButton(centralWidget);
        connect_btn->setObjectName(QStringLiteral("connect_btn"));

        horizontalLayout->addWidget(connect_btn);

        disconnect_btn = new QPushButton(centralWidget);
        disconnect_btn->setObjectName(QStringLiteral("disconnect_btn"));

        horizontalLayout->addWidget(disconnect_btn);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        server_lview = new QListView(centralWidget);
        server_lview->setObjectName(QStringLiteral("server_lview"));

        verticalLayout->addWidget(server_lview);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        update_btn = new QPushButton(centralWidget);
        update_btn->setObjectName(QStringLiteral("update_btn"));

        horizontalLayout_3->addWidget(update_btn);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        timing_label = new QLabel(centralWidget);
        timing_label->setObjectName(QStringLiteral("timing_label"));

        verticalLayout_3->addWidget(timing_label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        timing_slider = new QSlider(centralWidget);
        timing_slider->setObjectName(QStringLiteral("timing_slider"));
        timing_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(timing_slider);

        timing_output = new QLabel(centralWidget);
        timing_output->setObjectName(QStringLiteral("timing_output"));

        horizontalLayout_4->addWidget(timing_output);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        start_btn = new QPushButton(centralWidget);
        start_btn->setObjectName(QStringLiteral("start_btn"));

        horizontalLayout_2->addWidget(start_btn);

        stop_btn = new QPushButton(centralWidget);
        stop_btn->setObjectName(QStringLiteral("stop_btn"));

        horizontalLayout_2->addWidget(stop_btn);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_4);

        graph_obj = new QGraphicsView(centralWidget);
        graph_obj->setObjectName(QStringLiteral("graph_obj"));
        graph_obj->setMinimumSize(QSize(430, 430));

        horizontalLayout_5->addWidget(graph_obj);


        verticalLayout_5->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        server_label->setText(QApplication::translate("MainWindow", "server IP:", Q_NULLPTR));
        connect_btn->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        disconnect_btn->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        update_btn->setText(QApplication::translate("MainWindow", "update", Q_NULLPTR));
        timing_label->setText(QApplication::translate("MainWindow", "Timing", Q_NULLPTR));
        timing_output->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        start_btn->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stop_btn->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
