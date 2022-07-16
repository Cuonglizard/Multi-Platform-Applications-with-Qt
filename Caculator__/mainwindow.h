#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // là lớp cơ sở cho oject

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void NumPressed();
    void MathButtonPress();
    void EqualButtonPress();
    void ChangeNumbersign();
    void ClearButtonPress();
    void ANSButtonPress();

};
#endif // MAINWINDOW_H
