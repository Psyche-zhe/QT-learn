#ifndef FILEINFO_H
#define FILEINFO_H

#include <QDialog>
#include "mainwindow.h"
#include <QFileInfo>
#include <QDateTime>

namespace Ui {
    class fileinfo;
  }

class fileinfo : public QDialog
  {
    Q_OBJECT

  public:
    fileinfo(QWidget *parent,QString file_name);
    ~fileinfo();

  private slots:
    void on_pushButton_2_clicked();
    void showFileInfo();
  private:
    Ui::fileinfo *ui;
  private:
    QString filePath;

  };

#endif // FILEINFO_H
