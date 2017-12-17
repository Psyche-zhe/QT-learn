#include "fileinfo.h"
#include "ui_fileinfo.h"

fileinfo::fileinfo(QWidget *parent, QString file_name) :
  QDialog(parent),filePath(file_name),
  ui(new Ui::fileinfo)
  {
    ui->setupUi(this);
    qDebug()<< "diglog fileName: " << filePath;
    QObject::connect(ui->showinfo, SIGNAL(clicked(bool)), this, SLOT(showFileInfo()));
  }

fileinfo::~fileinfo()
  {
    delete ui;
  }

void fileinfo::on_pushButton_2_clicked()
{
    this->close();
}

void fileinfo::showFileInfo()
{
    QFileInfo info(filePath);
    qDebug() << "fileName : " << filePath.mid(filePath.lastIndexOf('/')+1);
    ui->fileName->setText(filePath.mid(filePath.lastIndexOf('/')+1));
    ui->filePlace->setText(filePath.mid(0, filePath.lastIndexOf('/')+1));
    ui->fileSize->setText(QString::number(info.size()));
    QDateTime create = info.created();
    ui->fileCreateTime->setText(create.toString("yyyy-MM-dd hh:mm:ss"));
}
