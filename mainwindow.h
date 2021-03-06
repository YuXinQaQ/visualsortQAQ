#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Bubble.h"
#include <QPainter>
#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void changes();//修改顺序
    void speed(int index);
    void bubblesort();//冒泡排序
    void selectsort();
    void quicksort();
    void insertsort();
    void mergesort();
    void ban();
signals:
    void start();       //开启子线程
    void indexs(int value);
public slots:
    void deal(int); //处理来自子线程的消息
    void release();
private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    int flag;       //判断顺序
    double blockH;     //绘图方块的高
    double blockW;     //绘图方块的宽
    int length;     //数组长度
    double *data;      //数组
    int cur;        //当前排序的位子
    QThread *thread;
    Bubble *bubble;
    int begin;
    int time;
    bool check;
};

#endif // WIDGET_H
