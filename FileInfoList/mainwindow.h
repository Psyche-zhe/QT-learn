#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <Qstring>
#include <QDebug>
#include "fileinfo.h"

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
    QString filePath;
  public:
    void setFilePath(QString filepath_){filePath = filepath_;}
    QString getFilePath(){return filePath;}
  private slots:
    void chooseAddFile();
    void openDiglog();
  private:
    Ui::MainWindow *ui;
  };

#endif // MAINWINDOW_H
