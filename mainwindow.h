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
    void El_Gamal(); // ���������� ���
    void Shnor(); // ���������� ���
    void Verify_Gamal(); // ��������� ���
    void Verify_Shnor(); // ��������� ���
    void Inicialization_El(); // ������������� � ��������� ������� ����������
    void Inicialization_Sh(); // ������������� � ��������� ������� ����������
    // ������������� ������� ����������
    void generate_m();
};

#endif // MAINWINDOW_H
