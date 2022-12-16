/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget_1;
    QVBoxLayout *PointsLayout;
    QLabel *pointsLabelTitle;
    QLabel *currentPointsLabel;
    QWidget *layoutWidget_2;
    QVBoxLayout *timeLayout;
    QLabel *timePassedLabel;
    QGridLayout *Min_SecLayout;
    QLCDNumber *lcdSeconds;
    QLabel *secondsLabel;
    QLCDNumber *lcdMinutes;
    QLabel *minutesLabel;
    QWidget *layoutWidget_3;
    QVBoxLayout *DifficultyLayout;
    QLabel *difficultyLabel;
    QRadioButton *easyRadio;
    QRadioButton *normalRadio;
    QRadioButton *hardRadio;
    QWidget *layoutWidget_4;
    QVBoxLayout *pointsToLeaderboardsLayout;
    QTextBrowser *infoBox;
    QHBoxLayout *usernameLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QCheckBox *canSave;
    QWidget *layoutWidget_5;
    QVBoxLayout *controlsLayout;
    QLabel *controlsLabel;
    QGridLayout *controlButtonsLayout;
    QPushButton *left_button;
    QPushButton *down_button;
    QPushButton *right_button;
    QPushButton *rotate_button;
    QWidget *layoutWidget_6;
    QVBoxLayout *leaderboardsLayout;
    QLabel *leaderboardsLabel;
    QVBoxLayout *hardLayout;
    QLabel *Leaderboard_hard;
    QGridLayout *hardTopGrid;
    QLabel *hard1;
    QLabel *H1Name;
    QLabel *H1Points;
    QLabel *hard2;
    QLabel *H2Name;
    QLabel *H2Points;
    QLabel *hard3;
    QLabel *H3Name;
    QLabel *H3Points;
    QVBoxLayout *normalLayout;
    QLabel *Leaderboard_normal;
    QGridLayout *normalTopGrid;
    QLabel *N3Name;
    QLabel *N3Points;
    QLabel *N1Name;
    QLabel *N1Points;
    QLabel *N2Points;
    QLabel *normal3;
    QLabel *normal2;
    QLabel *N2Name;
    QLabel *normal1;
    QVBoxLayout *easyLayout;
    QLabel *Leaderboard_easy;
    QGridLayout *easyGrid;
    QLabel *E3Name;
    QLabel *E3Points;
    QLabel *E1Name;
    QLabel *E1Points;
    QLabel *E2Points;
    QLabel *easy3;
    QLabel *easy2;
    QLabel *E2Name;
    QLabel *easy1;
    QWidget *layoutWidget_7;
    QVBoxLayout *buttonsLayout;
    QPushButton *create_button;
    QPushButton *close_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(701, 699);
        MainWindow->setMinimumSize(QSize(701, 699));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(100, 150, 240, 480));
        layoutWidget_1 = new QWidget(centralWidget);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(10, 150, 123, 68));
        PointsLayout = new QVBoxLayout(layoutWidget_1);
        PointsLayout->setSpacing(6);
        PointsLayout->setContentsMargins(11, 11, 11, 11);
        PointsLayout->setObjectName(QString::fromUtf8("PointsLayout"));
        PointsLayout->setContentsMargins(0, 0, 0, 0);
        pointsLabelTitle = new QLabel(layoutWidget_1);
        pointsLabelTitle->setObjectName(QString::fromUtf8("pointsLabelTitle"));
        pointsLabelTitle->setMinimumSize(QSize(121, 39));

        PointsLayout->addWidget(pointsLabelTitle);

        currentPointsLabel = new QLabel(layoutWidget_1);
        currentPointsLabel->setObjectName(QString::fromUtf8("currentPointsLabel"));
        currentPointsLabel->setMinimumSize(QSize(20, 21));

        PointsLayout->addWidget(currentPointsLabel);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(380, 20, 264, 103));
        timeLayout = new QVBoxLayout(layoutWidget_2);
        timeLayout->setSpacing(6);
        timeLayout->setContentsMargins(11, 11, 11, 11);
        timeLayout->setObjectName(QString::fromUtf8("timeLayout"));
        timeLayout->setContentsMargins(0, 0, 0, 0);
        timePassedLabel = new QLabel(layoutWidget_2);
        timePassedLabel->setObjectName(QString::fromUtf8("timePassedLabel"));

        timeLayout->addWidget(timePassedLabel);

        Min_SecLayout = new QGridLayout();
        Min_SecLayout->setSpacing(6);
        Min_SecLayout->setObjectName(QString::fromUtf8("Min_SecLayout"));
        lcdSeconds = new QLCDNumber(layoutWidget_2);
        lcdSeconds->setObjectName(QString::fromUtf8("lcdSeconds"));
        lcdSeconds->setMaximumSize(QSize(170, 27));

        Min_SecLayout->addWidget(lcdSeconds, 2, 1, 1, 1);

        secondsLabel = new QLabel(layoutWidget_2);
        secondsLabel->setObjectName(QString::fromUtf8("secondsLabel"));

        Min_SecLayout->addWidget(secondsLabel, 2, 2, 1, 1);

        lcdMinutes = new QLCDNumber(layoutWidget_2);
        lcdMinutes->setObjectName(QString::fromUtf8("lcdMinutes"));
        lcdMinutes->setMaximumSize(QSize(170, 27));

        Min_SecLayout->addWidget(lcdMinutes, 1, 1, 1, 1);

        minutesLabel = new QLabel(layoutWidget_2);
        minutesLabel->setObjectName(QString::fromUtf8("minutesLabel"));

        Min_SecLayout->addWidget(minutesLabel, 1, 2, 1, 1);


        timeLayout->addLayout(Min_SecLayout);

        layoutWidget_3 = new QWidget(centralWidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 500, 81, 118));
        DifficultyLayout = new QVBoxLayout(layoutWidget_3);
        DifficultyLayout->setSpacing(6);
        DifficultyLayout->setContentsMargins(11, 11, 11, 11);
        DifficultyLayout->setObjectName(QString::fromUtf8("DifficultyLayout"));
        DifficultyLayout->setContentsMargins(0, 0, 0, 0);
        difficultyLabel = new QLabel(layoutWidget_3);
        difficultyLabel->setObjectName(QString::fromUtf8("difficultyLabel"));

        DifficultyLayout->addWidget(difficultyLabel);

        easyRadio = new QRadioButton(layoutWidget_3);
        easyRadio->setObjectName(QString::fromUtf8("easyRadio"));

        DifficultyLayout->addWidget(easyRadio);

        normalRadio = new QRadioButton(layoutWidget_3);
        normalRadio->setObjectName(QString::fromUtf8("normalRadio"));

        DifficultyLayout->addWidget(normalRadio);

        hardRadio = new QRadioButton(layoutWidget_3);
        hardRadio->setObjectName(QString::fromUtf8("hardRadio"));

        DifficultyLayout->addWidget(hardRadio);

        layoutWidget_4 = new QWidget(centralWidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 19, 361, 131));
        pointsToLeaderboardsLayout = new QVBoxLayout(layoutWidget_4);
        pointsToLeaderboardsLayout->setSpacing(6);
        pointsToLeaderboardsLayout->setContentsMargins(11, 11, 11, 11);
        pointsToLeaderboardsLayout->setObjectName(QString::fromUtf8("pointsToLeaderboardsLayout"));
        pointsToLeaderboardsLayout->setContentsMargins(0, 0, 0, 0);
        infoBox = new QTextBrowser(layoutWidget_4);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));

        pointsToLeaderboardsLayout->addWidget(infoBox);

        usernameLayout = new QHBoxLayout();
        usernameLayout->setSpacing(6);
        usernameLayout->setObjectName(QString::fromUtf8("usernameLayout"));
        usernameLabel = new QLabel(layoutWidget_4);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        usernameLayout->addWidget(usernameLabel);

        usernameLineEdit = new QLineEdit(layoutWidget_4);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        usernameLayout->addWidget(usernameLineEdit);


        pointsToLeaderboardsLayout->addLayout(usernameLayout);

        canSave = new QCheckBox(layoutWidget_4);
        canSave->setObjectName(QString::fromUtf8("canSave"));

        pointsToLeaderboardsLayout->addWidget(canSave);

        layoutWidget_5 = new QWidget(centralWidget);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(350, 510, 331, 113));
        controlsLayout = new QVBoxLayout(layoutWidget_5);
        controlsLayout->setSpacing(6);
        controlsLayout->setContentsMargins(11, 11, 11, 11);
        controlsLayout->setObjectName(QString::fromUtf8("controlsLayout"));
        controlsLayout->setContentsMargins(0, 0, 0, 0);
        controlsLabel = new QLabel(layoutWidget_5);
        controlsLabel->setObjectName(QString::fromUtf8("controlsLabel"));

        controlsLayout->addWidget(controlsLabel);

        controlButtonsLayout = new QGridLayout();
        controlButtonsLayout->setSpacing(6);
        controlButtonsLayout->setObjectName(QString::fromUtf8("controlButtonsLayout"));
        left_button = new QPushButton(layoutWidget_5);
        left_button->setObjectName(QString::fromUtf8("left_button"));

        controlButtonsLayout->addWidget(left_button, 1, 0, 1, 1);

        down_button = new QPushButton(layoutWidget_5);
        down_button->setObjectName(QString::fromUtf8("down_button"));

        controlButtonsLayout->addWidget(down_button, 1, 1, 1, 1);

        right_button = new QPushButton(layoutWidget_5);
        right_button->setObjectName(QString::fromUtf8("right_button"));

        controlButtonsLayout->addWidget(right_button, 1, 2, 1, 1);

        rotate_button = new QPushButton(layoutWidget_5);
        rotate_button->setObjectName(QString::fromUtf8("rotate_button"));

        controlButtonsLayout->addWidget(rotate_button, 0, 1, 1, 1);


        controlsLayout->addLayout(controlButtonsLayout);

        layoutWidget_6 = new QWidget(centralWidget);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(350, 150, 331, 357));
        leaderboardsLayout = new QVBoxLayout(layoutWidget_6);
        leaderboardsLayout->setSpacing(6);
        leaderboardsLayout->setContentsMargins(11, 11, 11, 11);
        leaderboardsLayout->setObjectName(QString::fromUtf8("leaderboardsLayout"));
        leaderboardsLayout->setContentsMargins(0, 0, 0, 0);
        leaderboardsLabel = new QLabel(layoutWidget_6);
        leaderboardsLabel->setObjectName(QString::fromUtf8("leaderboardsLabel"));

        leaderboardsLayout->addWidget(leaderboardsLabel);

        hardLayout = new QVBoxLayout();
        hardLayout->setSpacing(6);
        hardLayout->setObjectName(QString::fromUtf8("hardLayout"));
        Leaderboard_hard = new QLabel(layoutWidget_6);
        Leaderboard_hard->setObjectName(QString::fromUtf8("Leaderboard_hard"));

        hardLayout->addWidget(Leaderboard_hard);

        hardTopGrid = new QGridLayout();
        hardTopGrid->setSpacing(6);
        hardTopGrid->setObjectName(QString::fromUtf8("hardTopGrid"));
        hard1 = new QLabel(layoutWidget_6);
        hard1->setObjectName(QString::fromUtf8("hard1"));

        hardTopGrid->addWidget(hard1, 0, 0, 1, 1);

        H1Name = new QLabel(layoutWidget_6);
        H1Name->setObjectName(QString::fromUtf8("H1Name"));

        hardTopGrid->addWidget(H1Name, 0, 1, 1, 1);

        H1Points = new QLabel(layoutWidget_6);
        H1Points->setObjectName(QString::fromUtf8("H1Points"));

        hardTopGrid->addWidget(H1Points, 0, 2, 1, 1);

        hard2 = new QLabel(layoutWidget_6);
        hard2->setObjectName(QString::fromUtf8("hard2"));

        hardTopGrid->addWidget(hard2, 1, 0, 1, 1);

        H2Name = new QLabel(layoutWidget_6);
        H2Name->setObjectName(QString::fromUtf8("H2Name"));

        hardTopGrid->addWidget(H2Name, 1, 1, 1, 1);

        H2Points = new QLabel(layoutWidget_6);
        H2Points->setObjectName(QString::fromUtf8("H2Points"));

        hardTopGrid->addWidget(H2Points, 1, 2, 1, 1);

        hard3 = new QLabel(layoutWidget_6);
        hard3->setObjectName(QString::fromUtf8("hard3"));

        hardTopGrid->addWidget(hard3, 2, 0, 1, 1);

        H3Name = new QLabel(layoutWidget_6);
        H3Name->setObjectName(QString::fromUtf8("H3Name"));

        hardTopGrid->addWidget(H3Name, 2, 1, 1, 1);

        H3Points = new QLabel(layoutWidget_6);
        H3Points->setObjectName(QString::fromUtf8("H3Points"));

        hardTopGrid->addWidget(H3Points, 2, 2, 1, 1);


        hardLayout->addLayout(hardTopGrid);


        leaderboardsLayout->addLayout(hardLayout);

        normalLayout = new QVBoxLayout();
        normalLayout->setSpacing(6);
        normalLayout->setObjectName(QString::fromUtf8("normalLayout"));
        Leaderboard_normal = new QLabel(layoutWidget_6);
        Leaderboard_normal->setObjectName(QString::fromUtf8("Leaderboard_normal"));

        normalLayout->addWidget(Leaderboard_normal);

        normalTopGrid = new QGridLayout();
        normalTopGrid->setSpacing(6);
        normalTopGrid->setObjectName(QString::fromUtf8("normalTopGrid"));
        N3Name = new QLabel(layoutWidget_6);
        N3Name->setObjectName(QString::fromUtf8("N3Name"));

        normalTopGrid->addWidget(N3Name, 2, 1, 1, 1);

        N3Points = new QLabel(layoutWidget_6);
        N3Points->setObjectName(QString::fromUtf8("N3Points"));

        normalTopGrid->addWidget(N3Points, 2, 2, 1, 1);

        N1Name = new QLabel(layoutWidget_6);
        N1Name->setObjectName(QString::fromUtf8("N1Name"));

        normalTopGrid->addWidget(N1Name, 0, 1, 1, 1);

        N1Points = new QLabel(layoutWidget_6);
        N1Points->setObjectName(QString::fromUtf8("N1Points"));

        normalTopGrid->addWidget(N1Points, 0, 2, 1, 1);

        N2Points = new QLabel(layoutWidget_6);
        N2Points->setObjectName(QString::fromUtf8("N2Points"));

        normalTopGrid->addWidget(N2Points, 1, 2, 1, 1);

        normal3 = new QLabel(layoutWidget_6);
        normal3->setObjectName(QString::fromUtf8("normal3"));

        normalTopGrid->addWidget(normal3, 2, 0, 1, 1);

        normal2 = new QLabel(layoutWidget_6);
        normal2->setObjectName(QString::fromUtf8("normal2"));

        normalTopGrid->addWidget(normal2, 1, 0, 1, 1);

        N2Name = new QLabel(layoutWidget_6);
        N2Name->setObjectName(QString::fromUtf8("N2Name"));

        normalTopGrid->addWidget(N2Name, 1, 1, 1, 1);

        normal1 = new QLabel(layoutWidget_6);
        normal1->setObjectName(QString::fromUtf8("normal1"));

        normalTopGrid->addWidget(normal1, 0, 0, 1, 1);


        normalLayout->addLayout(normalTopGrid);


        leaderboardsLayout->addLayout(normalLayout);

        easyLayout = new QVBoxLayout();
        easyLayout->setSpacing(6);
        easyLayout->setObjectName(QString::fromUtf8("easyLayout"));
        Leaderboard_easy = new QLabel(layoutWidget_6);
        Leaderboard_easy->setObjectName(QString::fromUtf8("Leaderboard_easy"));

        easyLayout->addWidget(Leaderboard_easy);

        easyGrid = new QGridLayout();
        easyGrid->setSpacing(6);
        easyGrid->setObjectName(QString::fromUtf8("easyGrid"));
        E3Name = new QLabel(layoutWidget_6);
        E3Name->setObjectName(QString::fromUtf8("E3Name"));

        easyGrid->addWidget(E3Name, 2, 1, 1, 1);

        E3Points = new QLabel(layoutWidget_6);
        E3Points->setObjectName(QString::fromUtf8("E3Points"));

        easyGrid->addWidget(E3Points, 2, 2, 1, 1);

        E1Name = new QLabel(layoutWidget_6);
        E1Name->setObjectName(QString::fromUtf8("E1Name"));

        easyGrid->addWidget(E1Name, 0, 1, 1, 1);

        E1Points = new QLabel(layoutWidget_6);
        E1Points->setObjectName(QString::fromUtf8("E1Points"));

        easyGrid->addWidget(E1Points, 0, 2, 1, 1);

        E2Points = new QLabel(layoutWidget_6);
        E2Points->setObjectName(QString::fromUtf8("E2Points"));

        easyGrid->addWidget(E2Points, 1, 2, 1, 1);

        easy3 = new QLabel(layoutWidget_6);
        easy3->setObjectName(QString::fromUtf8("easy3"));

        easyGrid->addWidget(easy3, 2, 0, 1, 1);

        easy2 = new QLabel(layoutWidget_6);
        easy2->setObjectName(QString::fromUtf8("easy2"));

        easyGrid->addWidget(easy2, 1, 0, 1, 1);

        E2Name = new QLabel(layoutWidget_6);
        E2Name->setObjectName(QString::fromUtf8("E2Name"));

        easyGrid->addWidget(E2Name, 1, 1, 1, 1);

        easy1 = new QLabel(layoutWidget_6);
        easy1->setObjectName(QString::fromUtf8("easy1"));

        easyGrid->addWidget(easy1, 0, 0, 1, 1);


        easyLayout->addLayout(easyGrid);


        leaderboardsLayout->addLayout(easyLayout);

        layoutWidget_7 = new QWidget(centralWidget);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 630, 114, 64));
        buttonsLayout = new QVBoxLayout(layoutWidget_7);
        buttonsLayout->setSpacing(6);
        buttonsLayout->setContentsMargins(11, 11, 11, 11);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        create_button = new QPushButton(layoutWidget_7);
        create_button->setObjectName(QString::fromUtf8("create_button"));

        buttonsLayout->addWidget(create_button);

        close_button = new QPushButton(layoutWidget_7);
        close_button->setObjectName(QString::fromUtf8("close_button"));

        buttonsLayout->addWidget(close_button);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(close_button, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(canSave, &QCheckBox::toggled, usernameLineEdit, &QLineEdit::setEnabled);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pointsLabelTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Points</span></p></body></html>", nullptr));
        currentPointsLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        timePassedLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600;\">Time passed:</span></p></body></html>", nullptr));
        secondsLabel->setText(QCoreApplication::translate("MainWindow", "Seconds", nullptr));
        minutesLabel->setText(QCoreApplication::translate("MainWindow", "Minutes", nullptr));
        difficultyLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; font-style:italic;\">Difficulty:</span></p></body></html>", nullptr));
        easyRadio->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        normalRadio->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        hardRadio->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        infoBox->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you want to save your score to the leaderboards:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. Check box below</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. Insert your username on the text box</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. Play the game to the end</p></body></html>", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        canSave->setText(QCoreApplication::translate("MainWindow", "Save points to leaderboards", nullptr));
        controlsLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Controls:</span></p></body></html>", nullptr));
        left_button->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        down_button->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        right_button->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        rotate_button->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        leaderboardsLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-style:italic;\">Leaderboards</span></p></body></html>", nullptr));
        Leaderboard_hard->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Hard</span></p></body></html>", nullptr));
        hard1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">1st</span></p></body></html>", nullptr));
        H1Name->setText(QString());
        H1Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        hard2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">2nd</span></p></body></html>", nullptr));
        H2Name->setText(QString());
        H2Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        hard3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">3rd</span></p></body></html>", nullptr));
        H3Name->setText(QString());
        H3Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Leaderboard_normal->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Normal</span></p></body></html>", nullptr));
        N3Name->setText(QString());
        N3Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        N1Name->setText(QString());
        N1Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        N2Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        normal3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">3rd</span></p></body></html>", nullptr));
        normal2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">2nd</span></p></body></html>", nullptr));
        N2Name->setText(QString());
        normal1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">1st</span></p></body></html>", nullptr));
        Leaderboard_easy->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Easy</span></p></body></html>", nullptr));
        E3Name->setText(QString());
        E3Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        E1Name->setText(QString());
        E1Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        E2Points->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        easy3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">3rd</span></p></body></html>", nullptr));
        easy2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">2nd</span></p></body></html>", nullptr));
        E2Name->setText(QString());
        easy1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" text-decoration: underline;\">1st</span></p></body></html>", nullptr));
        create_button->setText(QCoreApplication::translate("MainWindow", "Start new game", nullptr));
        close_button->setText(QCoreApplication::translate("MainWindow", "Close the game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
