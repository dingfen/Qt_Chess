#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "chessboard.h"
#include "resourcemanager.h"
#include "rehearsalscene.h"

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
    void loadGame();
    void saveGame();
    void overGame();
    void writeHistory(const QString &str);
    void nextRound(bool);
private:
    void init();

    Ui::MainWindow *ui;
    int regret_count_;
    QSharedPointer<RehearsalScene> scene_;
};
#endif // MAINWINDOW_H
