#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "superlong.h"
#include "md5.h"
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QTime>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushEg, SIGNAL( clicked() ), SLOT( El_Gamal()) );
    connect(ui->pushVerify_Eg, SIGNAL( clicked() ), SLOT( Verify_Gamal() ));
    connect(ui->pushButton_m, SIGNAL( clicked() ), SLOT( generate_m() ));
    connect(ui->pushSh, SIGNAL( clicked() ), SLOT( Shnor() ));
    connect(ui->pushVerify_Sh, SIGNAL( clicked() ), SLOT( Verify_Shnor() ));

    // �������������� random
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

//������� ���-������
void MainWindow::El_Gamal()
{
    Inicialization_El(); // ������������� � ��������� ������� ����������

    string str;

    // ������������� ����������
    superlong m, p, g, k, x, y, r, s, p1, k1, temp;
    m.get( ui->Eg_m->text().toStdString() );
    p.get( ui->Eg_p->text().toStdString() );
    g.get( ui->Eg_g->text().toStdString() );
    k.get( ui->Eg_k->text().toStdString() );
    x.get( ui->Eg_x->text().toStdString() );

    // ������� �������� ���� y
    y = powm( g, x, p);

    // ������� ������ �������� ��� - r
    r = powm( g, k, p);

    // ������� ������ ������� ��� - s
    p1 = p - 1;
    k1 = evklid_ext_x( k, p1 ); // k^-1 mod p-1
    temp = x * r;
    m %= p1;
    if ( m < temp ) {
        temp = p1 - ( temp - m ) % p1;
    }
    else {
        temp -= m;
    }
    s = k1 * temp;
    s %= p1;

    // �����
    y.give( str );
    ui->Eg_y->setText( QString::fromStdString( str ) );
    r.give( str );
    ui->Eg_r->setText( QString::fromStdString( str ) );
    s.give(str);
    ui->Eg_s->setText( QString::fromStdString( str ) );
}

// �������� ������� ���-������

void MainWindow::Verify_Gamal()
{
    // ������������� ����������
    superlong m, p, g, k, x, y, r, s, v1, v2;
    m.get( ui->Eg_m->text().toStdString() );
    p.get( ui->Eg_p->text().toStdString() );
    g.get( ui->Eg_g->text().toStdString() );
    k.get( ui->Eg_k->text().toStdString() );
    x.get( ui->Eg_x->text().toStdString() );
    r.get( ui->Eg_r->text().toStdString() );
    y.get( ui->Eg_y->text().toStdString() );
    s.get( ui->Eg_s->text().toStdString() );

    //��������� ��������
    if ( r < 1 || r == p - 1 ) {
        ui->Eg->setText( QString::fromLocal8Bit("������� �����!") );
    }
    else {
        v1 = powm( g, m, p );
        v2 = powm( y, r, p ) * powm( r, s, p ) % p;
        if ( v1 == v2 ) ui->Eg->setText( QString::fromLocal8Bit("������� �����!") );
        else ui->Eg->setText( QString::fromLocal8Bit("������� ���������!") );
    }
}

// ������������� � ��������� ������� ����������
void MainWindow::Inicialization_El() {
    if ( ui->Eg_M->text().isEmpty() ) ui->Eg_M->setText( "baaqab" );
    generate_m();
}

// ��������� ��� ��������� M
void MainWindow::generate_m()
{
    QString str = ui->Eg_M->text();
    str = hash( str );
    ui->Eg_m->setText( str );
}

// ������� �����
void MainWindow::Shnor()
{
    Inicialization_Sh(); // ������������� � ��������� ������� ����������

    string str, M;
    superlong p, q, b, r, a, x, e, y, a1, v;

    // ������������� ����������
    M = ui->Sh_M->text().toStdString();
    p.get( ui->Sh_p->text().toStdString() );
    q.get( ui->Sh_q->text().toStdString() );
    b.get( ui->Sh_b->text().toStdString() );
    r.get( ui->Sh_r->text().toStdString() );
    a.get( ui->Sh_a->text().toStdString() );

    // ��������� ��������� ���� - x
    x = powm( b, r, p );

    // ������� ������ �������� ��� - e
    e.get( hash( QString::fromStdString( M )).toStdString() );

    // ������� ������ �������� ��� - y
    y = ( a * e + r ) % q;

    // ��������� �������� ���� - v
    a1 = q - a;
    v = powm( b, a1, p );

    // �����
    x.give( str );
    ui->Sh_x->setText( QString::fromStdString( str ) );
    e.give( str );
    ui->Sh_e->setText( QString::fromStdString( str ) );
    y.give( str );
    ui->Sh_y->setText( QString::fromStdString( str ) );
    v.give( str );
    ui->Sh_v->setText( QString::fromStdString( str ) );
}

// �������� ������� �����

void MainWindow::Verify_Shnor()
{
    superlong p, q, b, temp, temp2, temp1, x, e, y, v;

    // ������������� ����������
    p.get( ui->Sh_p->text().toStdString() );
    q.get( ui->Sh_q->text().toStdString() );
    x.get( ui->Sh_x->text().toStdString() );
    b.get( ui->Sh_b->text().toStdString() );
    e.get( ui->Sh_e->text().toStdString() );
    y.get( ui->Sh_y->text().toStdString() );
    v.get( ui->Sh_v->text().toStdString() );

    temp1 = powm( v, e, p );
    temp2 = powm( b, y, p );
    temp = temp1 * temp2;
    temp %= p;

    // ��������� ��������
    if ( temp == x ) ui->Sh->setText( QString::fromLocal8Bit("������� �����!") );
    else ui->Sh->setText( QString::fromLocal8Bit("������� ���������!") );
}

// ������������� � ��������� ������� ����������
void MainWindow::Inicialization_Sh() {
    if ( ui->Sh_M->text().isEmpty() ) ui->Sh_M->setText( "baaqab" );
}

MainWindow::~MainWindow()
{
    delete ui;
}
