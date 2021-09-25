#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      regret_count_(3) {
    ui->setupUi(this);
    init();
    menuBar();
    statusBar();
}

void MainWindow::init() {
    scene_.reset(new RehearsalScene());
    ui->chessboard->setScene(scene_.get());
    ui->chessboard->setMouseTracking(true);

    connect(scene_->getRecorder(), &Recorder::recordHistory,
            this, &MainWindow::writeHistory);
    connect(ui->startbutton, SIGNAL(clicked(bool)),
            this, SLOT(startGame()));
    connect(ui->regretbutton, &QPushButton::clicked,
            this->scene_.get(), &RehearsalScene::regret);
    connect(scene_.get(), &ChessScene::nextRound,
            this, &MainWindow::nextRound);
}

void MainWindow::startGame(const QString& path) {
    if (scene_->isStart()) {
        auto but = QMessageBox::information(this, tr("游戏已开始"), tr("游戏已经开始，确定要开始新的一局吗"),
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (but == QMessageBox::Yes) {
            scene_->clear();
            scene_->startGame(path);
        }
    } else {
        ui->historyboard->appendHtml("<h1>中国象棋</h1>");
        scene_->startGame(path);
    }
}


void MainWindow::loadGame() {
    QString path = QFileDialog::getOpenFileName(this, tr("载入游戏"),
                                                ".", tr("Game Files(*.json)"));
    if(path.length() == 0) {
        QMessageBox::information(this, tr("载入游戏"), tr("还未选择游戏文件"),
                                 QMessageBox::Ok);
    } else {
        startGame(path);
        ui->historyboard->appendHtml("游戏加载完成");
    }
}


void MainWindow::saveGame() {
    QString path = QFileDialog::getSaveFileName(this, tr("保存游戏"),
                                                ".", tr("Game Files(*.json)"));
    scene_->saveGame(path);
    ui->historyboard->appendHtml("游戏已经保存");
}

void MainWindow::overGame() {
     auto sure = QMessageBox::information(this, tr("认输"), tr("真的要认输吗"),
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
     if (sure == QMessageBox::Yes) {
         bool isred = scene_->who();
         if (isred)
            QMessageBox::information(this, tr("游戏结束"), tr("游戏结束，黑方胜利"),
                             QMessageBox::Ok);
         else
             QMessageBox::information(this, tr("游戏结束"), tr("游戏结束，红方胜利"),
                              QMessageBox::Ok);
         scene_->clear();
         ui->historyboard->appendHtml("游戏结束");
     }
}

void MainWindow::writeHistory(const QString& str) {
    ui->historyboard->appendHtml(str);
}

void MainWindow::nextRound(bool isred) {
    if (isred)
        ui->label->setText("红方回合");
    else
        ui->label->setText("黑方回合");
}

MainWindow::~MainWindow() {
    delete ui;
}

