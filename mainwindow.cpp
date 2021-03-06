#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), is_start_(false), ui(new Ui::MainWindow),
      regret_count_(3) {
    ui->setupUi(this);
    init();
    menuBar();
    statusBar();
}


void MainWindow::setUpConnect() {
    connect(scene_->getRecorder(), &Recorder::recordHistory,
            this, &MainWindow::writeHistory);
    connect(ui->regretbutton, SIGNAL(clicked()),
            this->scene_.get(), SLOT(regret()));
    connect(scene_.get(), &ChessScene::nextRound,
            this, &MainWindow::nextRound);
    connect(scene_.get(), &ChessScene::remainTime,
            this, &MainWindow::showTime);
}

void MainWindow::init() {
    scene_.reset(new AIScene());
    ui->chessboard->setScene(scene_.get());
    ui->chessboard->setMouseTracking(true);
    connect(ui->startbutton, SIGNAL(clicked(bool)),
            this, SLOT(startGame()));
    setUpConnect();
}

void MainWindow::_startReh(const QString& path) {
    if(!dynamic_cast<RehearsalScene*>(scene_.get())) {
        scene_->clear();
        scene_.reset(new RehearsalScene());
        ui->chessboard->setScene(scene_.get());
        ui->chessboard->setMouseTracking(true);
        setUpConnect();
    }
    ui->historyboard->appendHtml("<h1>中国象棋</h1>");
    scene_->clear();
    scene_->startGame(path);
}

void MainWindow::startReh(const QString& path) {
    if (is_start_) {
        auto but = QMessageBox::information(this, tr("游戏已开始"), tr("游戏已经开始，确定要开始新的一局吗"),
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (but == QMessageBox::Yes) {
            _startReh(path);
        }
    } else {
        _startReh(path);
    }
}

void MainWindow::_startGame(const QString &path) {
    if(!dynamic_cast<AIScene*>(scene_.get())) {
        scene_->clear();
        scene_.reset(new AIScene());
        ui->chessboard->setScene(scene_.get());
        ui->chessboard->setMouseTracking(true);
        setUpConnect();
    }
    ui->historyboard->appendHtml("<h1>中国象棋</h1>");
    scene_->clear();
    scene_->startGame(path);
}

void MainWindow::startGame(const QString& path) {
    if (is_start_) {
        auto but = QMessageBox::information(this, tr("游戏已开始"), tr("游戏已经开始，确定要开始新的一局吗"),
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (but == QMessageBox::Yes) {
            _startGame(path);
        }
    } else {
        _startGame(path);
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
         is_start_ = false;
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

void MainWindow::showTime(int time) {
    ui->timerlabel->setText(QString::number(time));
}

MainWindow::~MainWindow() {
    delete ui;
}

