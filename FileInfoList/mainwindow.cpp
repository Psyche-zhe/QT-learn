#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
  {
    ui->setupUi(this);
    QObject::connect(ui->choosefile,SIGNAL(clicked(bool)),this,SLOT(chooseAddFile()));
    QObject::connect(ui->exit, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(ui->filelist, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openDiglog()));
  }

MainWindow::~MainWindow()
  {
    delete ui;
  }


void MainWindow::chooseAddFile()
  {

    QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              "E://",
                              "files (*.*)");
   ui->filelist->addItems(files);
  }

void MainWindow::openDiglog()
{
   qDebug() <<"item : " <<  ui->filelist->currentRow();
   qDebug() <<"item info : " << ui->filelist->item(ui->filelist->currentRow())->text();
   setFilePath(ui->filelist->item(ui->filelist->currentRow())->text());
    fileinfo *filediglog = new fileinfo(0,ui->filelist->item(ui->filelist->currentRow())->text());
    filediglog->show();

}
