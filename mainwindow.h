#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void El_Gamal(); // выработать Ё÷ѕ
    void Shnor(); // выработать Ё÷ѕ
    void Verify_Gamal(); // проверить Ё÷ѕ
    void Verify_Shnor(); // проверить Ё÷ѕ
    void Inicialization_El(); // инициализаци€ и генераци€ входных параметров
    void Inicialization_Sh(); // инициализаци€ и генераци€ входных параметров
    // генерирование входных параметров
    void generate_m();
};

#endif // MAINWINDOW_H
