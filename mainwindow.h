#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "chessboard.h"
#include "resourcemanager.h"
#include "rehearsalscene.h"
#include "aiscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Recorder;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startGame(const QString& path = ":/game/savegame/opening.json");
    void startReh(const QString& path = ":/game/savegame/opening.json");
    void loadGame();
    void saveGame();
    void overGame();
    void writeHistory(const QString &str);
    void nextRound(bool);
    void showTime(int);
private:
    void init();
    void setUpConnect();
    void _startReh(const QString& path);
    void _startGame(const QString& path);

    bool is_start_;
    Ui::MainWindow *ui;
    int regret_count_;
    QSharedPointer<ChessScene> scene_;
};
#endif // MAINWINDOW_H
