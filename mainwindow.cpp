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
    scene_.reset(new ChessScene());
    ui->chessboard->setScene(scene_.get());
    ui->chessboard->setMouseTracking(true);

    connect(ui->startbutton, SIGNAL(clicked(bool)),
            this, SLOT(startGame()));
    connect(ui->regretbutton, SIGNAL(clicked(bool)),
            this, SLOT(regret()));
}

void MainWindow::startGame(const QString& path) {
    if (scene_->isStart()) {
        return;
    } else {
        scene_->startGame(path);
    }
}

void MainWindow::regret() {
    if (scene_->isStart()) {

    }
}

MainWindow::~MainWindow() {
    delete ui;
}

