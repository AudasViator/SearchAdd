#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollBar>

#include <cassert>
#include <cmath>

#include "studentnumberselector.h"
#include "helpdialog.h"
#include "attempt.h"
#include "congratulationsdialog.h"
#include "gameoverdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int studentNumber, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkButton_clicked();

    void on_helpButton_clicked();

    void moveScrollBarToBottom(int min, int max);

    void onGameOverRetryButtonClicked();

    void onGameOverRejectButtonClicked();

private:
    Ui::MainWindow *ui;

    const std::size_t maxAttemptCount = 25;

    int studentNumber;

    QWidget *scrollWidget;

    std::vector<Attempt*> attempts;

    std::vector<float> convertAdditionsToProperties(std::vector<float> additionsPercentage, int studentNumber);

    bool isPropertiesCorrect(std::vector<float> properties);

    void addNewAttempt();

    void showHelpDialog();

    void clearWindowState();
};

#endif // MAINWINDOW_H
