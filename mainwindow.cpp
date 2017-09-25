#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->GraphWindow->addGraph();
    ui->GraphWindow->legend->setVisible(true);
    ui->GraphWindow->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->GraphWindow->graph(0)->setPen(QPen(Qt::blue));
    ui->GraphWindow->graph(0)->setName("Distributed");
    ui->GraphWindow->addGraph();
    ui->GraphWindow->graph(1)->setPen(QPen(Qt::red));
    ui->GraphWindow->graph(1)->setName("Centralized");
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->GraphWindow->xAxis->setTicker(timeTicker);
//    ui->GraphWindow->axisRect()->setupFullAxesBox();
    ui->GraphWindow->yAxis->setLabel("u1");
    ui->GraphWindow->yAxis->setRange(-2, 1);

    ui->GraphWindow_2->addGraph();
    ui->GraphWindow_2->legend->setVisible(true);
    ui->GraphWindow_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->GraphWindow_2->graph(0)->setPen(QPen(Qt::blue));
    ui->GraphWindow_2->graph(0)->setName("Distributed");
    ui->GraphWindow_2->addGraph();
    ui->GraphWindow_2->graph(1)->setPen(QPen(Qt::red));
    ui->GraphWindow_2->graph(1)->setName("Centralized");
    ui->GraphWindow_2->xAxis->setTicker(timeTicker);
    ui->GraphWindow_2->yAxis->setLabel("u2");
    ui->GraphWindow_2->yAxis->setRange(-2, 1);

    ui->GraphWindow_3->addGraph();
    ui->GraphWindow_3->legend->setVisible(true);
    ui->GraphWindow_3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->GraphWindow_3->graph(0)->setPen(QPen(Qt::blue));
    ui->GraphWindow_3->graph(0)->setName("Distributed");
    ui->GraphWindow_3->addGraph();
    ui->GraphWindow_3->graph(1)->setPen(QPen(Qt::red));
    ui->GraphWindow_3->graph(1)->setName("Centralized");
    ui->GraphWindow_3->xAxis->setTicker(timeTicker);
    ui->GraphWindow_3->yAxis->setLabel("u3");
    ui->GraphWindow_3->yAxis->setRange(-2, 1);

    ui->GraphWindow_4->addGraph();
    ui->GraphWindow_4->legend->setVisible(true);
    ui->GraphWindow_4->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    ui->GraphWindow_4->graph(0)->setPen(QPen(Qt::blue));
    ui->GraphWindow_4->graph(0)->setName("Distributed");
    ui->GraphWindow_4->addGraph();
    ui->GraphWindow_4->graph(1)->setPen(QPen(Qt::red));
    ui->GraphWindow_4->graph(1)->setName("Centralized");
    ui->GraphWindow_4->xAxis->setTicker(timeTicker);
    ui->GraphWindow_4->yAxis->setLabel("u4");
    ui->GraphWindow_4->yAxis->setRange(-0.1, 0.3);

//    ui->GraphWindow_2->graph(0)->setName("Omega1");
//    ui->GraphWindow_2->graph(1)->setName("Omega2");

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    //connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    //dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->label->setText("HELLO");
    serverSocket = new QTcpSocket(this);
    //    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
//            this, SLOT(displayError(QAbstractSocket::SocketError)));
//    connect(serverSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    qDebug() << "Connecting,..";
    while(!serverSocket->isOpen()){
        serverSocket->abort();
        serverSocket->connectToHost(ui->IP_Addr_Box->text(),ui->Port_Box->text().toInt());
    }
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(processData()));

}

void MainWindow::processData()
{
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    double key1 = time.elapsed()/1500.0; // time elapsed since start of demo, in seconds

    static double lastPointKey1 = 0;
    //static double lastPointKey2 = 0;
    QString datas = serverSocket->readAll();
    ui->textEdit->setText(datas);
    qDebug()<<datas;
    QStringList list = datas.split(",",QString::SkipEmptyParts);
    bool ok = false;
    double cal_error = list[0].toDouble(&ok);
    double omega1 = list[1].toDouble(&ok);
    double omega2 = list[2].toDouble(&ok);
    double omega3 = list[3].toDouble(&ok);

        QStringList strings;
        QFile file("/home/haoqi/visulization2/datau1.txt");
            file.open(QIODevice::ReadOnly);
            QTextStream in(&file);
            while (true) {
                QString line = in.readLine();
                if (line.isNull())
                    break;
                strings += line.split(",");
            }
         QStringList strings1;
         QFile file1("/home/haoqi/visulization2/datau2.txt");
             file1.open(QIODevice::ReadOnly);
             QTextStream in1(&file1);
             while (true) {
                 QString line1 = in1.readLine();
                 if (line1.isNull())
                     break;
                 strings1 += line1.split(",");
             }
          QStringList strings2;
          QFile file2("/home/haoqi/visulization2/datau3.txt");
              file2.open(QIODevice::ReadOnly);
              QTextStream in2(&file2);
              while (true) {
                  QString line2 = in2.readLine();
                  if (line2.isNull())
                      break;
                  strings2 += line2.split(",");
              }
           QStringList strings3;
           QFile file3("/home/haoqi/visulization2/datau4.txt");
               file3.open(QIODevice::ReadOnly);
               QTextStream in3(&file3);
               while (true) {
                   QString line3 = in3.readLine();
                   if (line3.isNull())
                       break;
                   strings3 += line3.split(",");
               }
double yy = strings[count].toDouble(&ok);
double yy1 = strings1[count].toDouble(&ok);
double yy2 = strings2[count].toDouble(&ok);
double yy3 = strings3[count].toDouble(&ok);
//double yy4 = strings[count+4].toDouble(&ok);


      double x,y1,y2,y3;
      double y;
    //int x(34);
      x = count+1;
      y = cal_error;
      y1 = omega1;
      y2 = omega2;
      y3 = omega3;
      count=count+1;

      if (key-lastPointKey1 > 0.002) // at most add point every 2 ms
      {
        // add data to lines:
          ui->GraphWindow->graph(0)->addData(key, y);
          ui->GraphWindow_2->graph(0)->addData(key,y1);
          ui->GraphWindow_3->graph(0)->addData(key,y2);
          ui->GraphWindow_4->graph(0)->addData(key,y3);
                // rescale value (vertical) axis to fit the current data:
        //ui->customPlot->graph(0)->rescaleValueAxis();
        //ui->customPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey1 = key;
      }

//      if((key-lastPointKey2) == 0.1)
//      {
          qDebug()<<yy;
          ui->GraphWindow->graph(1)->addData(key1, yy);
          ui->GraphWindow_2->graph(1)->addData(key1,yy1);
          ui->GraphWindow_3->graph(1)->addData(key1,yy2);
          ui->GraphWindow_4->graph(1)->addData(key1,yy3);
//          lastPointKey2 = key;
//      }
    ui->GraphWindow->xAxis->setRange(key, 11, Qt::AlignRight);
    ui->GraphWindow->replot();


    ui->GraphWindow_2->xAxis->setRange(key, 11, Qt::AlignRight);
    ui->GraphWindow_2->replot();

    ui->GraphWindow_3->xAxis->setRange(key, 11, Qt::AlignRight);
    ui->GraphWindow_3->replot();

    ui->GraphWindow_4->xAxis->setRange(key, 11, Qt::AlignRight);
    ui->GraphWindow_4->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    serverSocket->disconnectFromHost();
}
