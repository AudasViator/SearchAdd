#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int studentNumber, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->studentNumber = studentNumber;
    ui->setupUi(this);
    setWindowTitle("Поиск добавок");

    ui->studentNumberLabel->setText("Студент №" + QString::number(studentNumber));

    scrollWidget = new QWidget;
    scrollWidget->setLayout(new QVBoxLayout);
    ui->attemptsScrollArea->setWidget(scrollWidget);

    QScrollBar* scrollbar = ui->attemptsScrollArea->verticalScrollBar();
    QObject::connect(scrollbar, &QScrollBar::rangeChanged, this, &MainWindow::moveScrollBarToBottom);

    addNewAttempt();

    showHelpDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewAttempt() {
    Attempt* attempt = new Attempt();

    scrollWidget->layout()->addWidget(attempt);
    if (attempts.size() == 0) {
        scrollWidget->layout()->setAlignment(attempt, Qt::AlignTop);
    }

    attempts.push_back(attempt);

    attempt->setAttemptNumber(attempts.size());
    ui->attemptNumber->display((int) attempts.size());
}

std::vector<float> MainWindow::convertAdditionsToProperties(std::vector<float> additionsPercentage, int studentNumber)
{
    assert (additionsPercentage.size() == 4);

    std::vector<float> properties(additionsPercentage.size());
    srand(studentNumber);

    const float Q=0.20f;
    const float W=(3.0f+Q)*Q*Q*10.0f;
    const float V=-(Q*Q*10.0f);

    float A[4][4], Z[4];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            A[i][j]=V;
        }
    }

    for(int i=0;i<4;i++)
    {
        A[i][i]=W;
    }

    const float R=rand()/32767.0f;

    Z[0]=R*additionsPercentage[0]/(1+R*additionsPercentage[0]);
    Z[1]=1-exp(-(additionsPercentage[1]*additionsPercentage[1]*additionsPercentage[1]*additionsPercentage[1]*(1-R)));
    Z[2]=1-exp(-additionsPercentage[2]*R);
    Z[3]=(1-R)*additionsPercentage[3]*additionsPercentage[3]/(1+(1-R)*additionsPercentage[3]*additionsPercentage[3]);

    for(int i=0;i<4;i++)
    {
        properties[i]=0;
        for(int j=0;j<4; j++)
        {
            properties[i]=properties[i]+A[i][j]*Z[j];
        }
    }

    return properties;
}

bool MainWindow::isPropertiesCorrect(std::vector<float> properties) {
    assert (properties.size() == 4);

    for (const auto property : properties) {
        if (property <= 0.0f) {
            return false;
        }
    }

    return true;
}

void MainWindow::on_checkButton_clicked()
{
    auto lastAttempt = attempts.back();

    if (!lastAttempt->isAdditionsEntered()) {
        return;
    }

    auto lastAdditions = lastAttempt->getAdditionsPercentage();

    if (lastAdditions[1] > 2.0f) {
        QMessageBox::information(this, "Ошибка", "Слишком много титана", QMessageBox::Yes);
        return;
    }

    float sumOfAdditions = 0.0f;
    for (auto addition : lastAdditions) {
        sumOfAdditions += addition;
    }
    if (sumOfAdditions > 20) {
        QMessageBox::information(this, "Ошибка", "Слишком много добавок", QMessageBox::Yes);
        return;
    }

    lastAttempt->disableEditing();
    auto properties = convertAdditionsToProperties(lastAdditions, studentNumber);
    lastAttempt->setProperties(properties);

    if (isPropertiesCorrect(properties)) {
        ui->checkButton->hide();
        auto congratulations = new CongratulationsDialog();
        congratulations->setAttempt(attempts.back());
        congratulations->exec();
    } else {
        if (attempts.size() < maxAttemptCount) {
            addNewAttempt();
        } else {
            ui->checkButton->hide();

            auto gameOverDialog = new GameOverDialog();
            QObject::connect(gameOverDialog, &GameOverDialog::accepted, this, &MainWindow::onGameOverRetryButtonClicked);
            QObject::connect(gameOverDialog, &GameOverDialog::rejected, this, &MainWindow::onGameOverRejectButtonClicked);
            gameOverDialog->exec();
        }
    }
}

void MainWindow::onGameOverRejectButtonClicked() {
    QApplication::quit();
}

void MainWindow::onGameOverRetryButtonClicked() {
    MainWindow* mainWindow = new MainWindow(studentNumber);
    mainWindow->show();
    this->hide();
}

void MainWindow::on_helpButton_clicked()
{
    showHelpDialog();
}

void MainWindow::showHelpDialog(){
    HelpDialog* helpDialog = new HelpDialog();
    helpDialog->exec();
}

void MainWindow::moveScrollBarToBottom(int min, int max)
{
    Q_UNUSED(min);
    ui->attemptsScrollArea->verticalScrollBar()->setValue(max);
}
