#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    //void readyRead();
    void processData();
    //void readTcpData();
    //void bytesWritten(qint64 bytes);


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket * serverSocket;
    double count=0;

};

#endif // MAINWINDOW_H
