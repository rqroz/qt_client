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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *server_input;
    QHBoxLayout *horizontalLayout;
    QPushButton *connect_btn;
    QPushButton *disconnect_btn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *min_label;
    QSlider *min_slider;
    QLCDNumber *minlcd_display;
    QHBoxLayout *horizontalLayout_4;
    QLabel *max_label;
    QSlider *max_slider;
    QLCDNumber *maxlcd_display;
    QHBoxLayout *horizontalLayout_2;
    QLabel *timing_label;
    QSlider *timing_slider;
    QLabel *timing_output;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *start_btn;
    QPushButton *stop_btn;
    QListView *output_lview;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(482, 365);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        server_input = new QLineEdit(centralWidget);
        server_input->setObjectName(QStringLiteral("server_input"));

        verticalLayout->addWidget(server_input);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        connect_btn = new QPushButton(centralWidget);
        connect_btn->setObjectName(QStringLiteral("connect_btn"));

        horizontalLayout->addWidget(connect_btn);

        disconnect_btn = new QPushButton(centralWidget);
        disconnect_btn->setObjectName(QStringLiteral("disconnect_btn"));

        horizontalLayout->addWidget(disconnect_btn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        min_label = new QLabel(centralWidget);
        min_label->setObjectName(QStringLiteral("min_label"));

        horizontalLayout_5->addWidget(min_label);

        min_slider = new QSlider(centralWidget);
        min_slider->setObjectName(QStringLiteral("min_slider"));
        min_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(min_slider);

        minlcd_display = new QLCDNumber(centralWidget);
        minlcd_display->setObjectName(QStringLiteral("minlcd_display"));

        horizontalLayout_5->addWidget(minlcd_display);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        max_label = new QLabel(centralWidget);
        max_label->setObjectName(QStringLiteral("max_label"));

        horizontalLayout_4->addWidget(max_label);

        max_slider = new QSlider(centralWidget);
        max_slider->setObjectName(QStringLiteral("max_slider"));
        max_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(max_slider);

        maxlcd_display = new QLCDNumber(centralWidget);
        maxlcd_display->setObjectName(QStringLiteral("maxlcd_display"));

        horizontalLayout_4->addWidget(maxlcd_display);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timing_label = new QLabel(centralWidget);
        timing_label->setObjectName(QStringLiteral("timing_label"));

        horizontalLayout_2->addWidget(timing_label);

        timing_slider = new QSlider(centralWidget);
        timing_slider->setObjectName(QStringLiteral("timing_slider"));
        timing_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timing_slider);

        timing_output = new QLabel(centralWidget);
        timing_output->setObjectName(QStringLiteral("timing_output"));

        horizontalLayout_2->addWidget(timing_output);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        start_btn = new QPushButton(centralWidget);
        start_btn->setObjectName(QStringLiteral("start_btn"));

        horizontalLayout_3->addWidget(start_btn);

        stop_btn = new QPushButton(centralWidget);
        stop_btn->setObjectName(QStringLiteral("stop_btn"));

        horizontalLayout_3->addWidget(stop_btn);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_2);

        output_lview = new QListView(centralWidget);
        output_lview->setObjectName(QStringLiteral("output_lview"));

        horizontalLayout_6->addWidget(output_lview);


        verticalLayout_3->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        output_lview->raise();
        connect_btn->raise();
        disconnect_btn->raise();
        start_btn->raise();
        stop_btn->raise();
        min_slider->raise();
        max_slider->raise();
        timing_slider->raise();
        min_label->raise();
        timing_label->raise();
        timing_output->raise();
        max_label->raise();
        server_input->raise();
        minlcd_display->raise();
        maxlcd_display->raise();
        min_label->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 482, 25));
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
#ifndef QT_NO_TOOLTIP
        server_input->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Insert the webserver url to which you want to fetch data.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        connect_btn->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        disconnect_btn->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        min_label->setText(QApplication::translate("MainWindow", "Min", Q_NULLPTR));
        max_label->setText(QApplication::translate("MainWindow", "Max", Q_NULLPTR));
        timing_label->setText(QApplication::translate("MainWindow", "Timing", Q_NULLPTR));
        timing_output->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        start_btn->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stop_btn->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
