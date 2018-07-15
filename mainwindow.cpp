#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <String>
#include <QTextCodec>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void Checkincome(int *incomeint1,QString b,int k)//  b-"D:\\ticket1.txt" k-место в database
{
    QFile file("D:\\database.txt");
   if(file.open(QIODevice::ReadWrite |QIODevice::Text))
   {
       while(!file.atEnd())
       {
           QString str1 = file.readLine();
           QStringList lst = str1.split(" ");
            QString income;
           if (lst[k]=="2")
           {
               QFile fileincome1(b);
                  if(fileincome1.open(QIODevice::ReadOnly |QIODevice::Text))
                  {
                      while(!fileincome1.atEnd())
                      {
                          //читаем строку
                          QString str = fileincome1.readLine();
                          //Делим строку на слова разделенные пробелом
                          QStringList lst = str.split(" ");
                            // выводим первых три слова
                          income=lst.at(7);
                          *incomeint1= income.toInt();
                      }

                  }
                fileincome1.close();
           }
       }

 }
}
void Checkplaces(QString &b, QString id){
    QFile file("D:\\database.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str1 = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst2 = str1.split(" ");
                 // находим элементы строки, которые равны 2(место куплено)
               int k=0;
               for(int i=0;i<20;i++)
               {
               if (lst2[i]==id) k++;// считаем количество элементов
               }
               // переводим k из int в string
               b = QString::number(k);

           }

       }
       file.close();
}
//Установка изначальных цветов:
//ui->pushButton->setStyleSheet("background-color:green");
void MainWindow::on_pushButton_clicked()
{


    QString color;
    QStringList lst;
    // предполагается считываение id цветов из файла database.txt. Далее исходя из того,
    // какой цвет у кнопки, выставляем нужный цвет при нажатии. Исходя из database.txt
    // выдается общая информация о количестве проданных билетов,свободных мест и забронированных мест.
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               //читаем строку
               QString str1 = file2.readLine();
               //Делим строку на слова разделенные пробелом
               lst = str1.split(" ");
                 // Выбираем нужную часть строки
               color=lst[0]; // ТРЕБУЕТСЯ ПРЕОБРАЗОВАНИЕ ИЗ STRING В INT
               if (color=="2")
               {
                 ui->pushButton->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }

               if (color=="1")
               {
                 ui->pushButton->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
               if (color=="0")
               {
                 ui->pushButton->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[0]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket5.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));//<< lst.at(1)<<lst.at(2);
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }

}
// после доработки планируется заполнить функционалом остальные кнопки
void MainWindow::on_pushButton_2_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[1];
               if (color=="2")
               {
                 ui->pushButton_2->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_2->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_2->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[1]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket6.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }

}

void MainWindow::on_pushButton_3_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[2];
               if (color=="2")
               {
                 ui->pushButton_3->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_3->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_3->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[2]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket7.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }

}

void MainWindow::on_pushButton_4_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[3];
               if (color=="2")
               {
                 ui->pushButton_4->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_4->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_4->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[3]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket8.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[4];
               if (color=="2")
               {
                 ui->pushButton_5->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_5->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_5->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[4]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket9.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[5];
               if (color=="2")
               {
                 ui->pushButton_6->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_6->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_6->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[5]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket10.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[6];
               if (color=="2")
               {
                 ui->pushButton_7->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_7->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_7->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[6]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket11.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[7];
               if (color=="2")
               {
                 ui->pushButton_8->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_8->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_8->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[7]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket12.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[8];
               if (color=="2")
               {
                 ui->pushButton_9->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_9->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_9->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[8]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket13.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_10_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[9];
               if (color=="2")
               {
                 ui->pushButton_10->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_10->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_10->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[9]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket14.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_11_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[10];
               if (color=="2")
               {
                 ui->pushButton_11->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_11->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_11->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[10]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket15.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_12_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[11];
               if (color=="2")
               {
                 ui->pushButton_12->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_12->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_12->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[11]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket16.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_13_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[12];
               if (color=="2")
               {
                 ui->pushButton_13->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_13->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_13->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[12]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket17.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_14_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[13];
               if (color=="2")
               {
                 ui->pushButton_14->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_14->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_14->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[13]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket18.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_15_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[14];
               if (color=="2")
               {
                 ui->pushButton_15->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_15->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_15->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[14]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket19.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_pushButton_16_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[15];
               if (color=="2")
               {
                 ui->pushButton_16->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->pushButton_16->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->pushButton_16->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[15]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket20.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_businessklassticket1_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[16];
               if (color=="2")
               {
                 ui->businessklassticket1->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->businessklassticket1->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->businessklassticket1->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[16]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket1.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_businessklassticket2_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[17];
               if (color=="2")
               {
                 ui->businessklassticket2->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->businessklassticket2->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->businessklassticket2->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[17]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket2.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_businessklassticket3_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[18];
               if (color=="2")
               {
                 ui->businessklassticket3->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->businessklassticket3->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->businessklassticket3->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[18]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket3.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_businessklassticket4_clicked()
{
    QString color;
    QStringList lst;
    QFile file2("D:\\database.txt");
       if(file2.open(QIODevice::ReadWrite |QIODevice::Text))
       {
           while(!file2.atEnd())
           {
               QString str1 = file2.readLine();
               lst = str1.split(" ");
               color=lst[19];
               if (color=="2")
               {
                 ui->businessklassticket4->setStyleSheet("background-color:green");
                 color="0";
                 goto labal;
               }
               if (color=="1")
               {
                 ui->businessklassticket4->setStyleSheet("background-color:red");
                 color="2";
                 goto labal;
               }
               if (color=="0")
               {
                 ui->businessklassticket4->setStyleSheet("background-color:yellow");
                 color="1";
               }
               labal:
               lst[19]= color; // запись цвета обрато в файл


           }

     }
       QFile file3("D:\\database.txt");
       file3.open(QIODevice::WriteOnly |QIODevice::Text);
       QTextStream writer (&file3);
       for (int i=0;i<20;i++)
       {
       writer << lst[i]<<" ";
       }
    // выбор цвета исходя из того, какой цвет у кнопки на данный момент

    // Также при нажатии на кнопку выдается информация о месте.
    // Открываем текстовый файл, который является и билетом и базой данных.
    QFile file("D:\\ticket4.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text))
       {
           while(!file.atEnd())
           {
               //читаем строку
               QString str = file.readLine();
               //Делим строку на слова разделенные пробелом
               QStringList lst = str.split(" ");
                 // выводим первых три слова
               ui->info->setText(lst.at(0));
               ui->info2->setText(lst.at(1));
               ui->info3->setText(lst.at(3));
               ui->info4->setText(lst.at(4));
               ui->info5->setText(lst.at(5));
               ui->info6->setText(lst.at(6));
               ui->info7->setText(lst.at(7));
           }

       }
}

void MainWindow::on_ticketdataok_clicked()
{
    // считываение данных при нажатии на кнопку ОК и занос этих данных в файлы ticket1, ticket2 и т.д.
  //  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QString klass = ui->klass->text(); //запись в klass данных, которые ввел пользователь в окно "Klass"
    QString numberticket = ui->numberticket->text();
    QString date = ui->date->text();
    QString time = ui->time->text();
    QString flight = ui->flight->text();
    QString price = ui->price->text();
    QString name = ui->nameline->text();
    QString surname = ui->surnameline->text();
    //int numberticket=QString.toInt(numberticket);
    QStringList lstdata;
   // Сбор данных для подсчета суммы, на которую купили билеты
    if(klass=="business" && numberticket=="1")
            {
            QFile file1("D:\\ticket1.txt");
            file1.open( QIODevice :: WriteOnly | QIODevice::Text);
            QTextStream writer (&file1);
            writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
            file1.close();

            }
    if(klass=="business" && numberticket=="2")
            {
            QFile file2("D:\\ticket2.txt");
            file2.open( QIODevice :: WriteOnly | QIODevice::Text);
            QTextStream writer (&file2);
            writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
            file2.close();

            }
    if(klass=="business" && numberticket=="3")
            {
            QFile file3("D:\\ticket3.txt");
            file3.open( QIODevice :: WriteOnly | QIODevice::Text);
            QTextStream writer (&file3);
            writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
             file3.close();

    }
    if(klass=="business" && numberticket=="4")
            {
            QFile file4("D:\\ticket4.txt");
            file4.open( QIODevice :: WriteOnly | QIODevice::Text);
            QTextStream writer (&file4);
            writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file4.close();

    }
    if (klass=="economy" && numberticket=="1")
    {
        QFile file5("D:\\ticket5.txt");
        file5.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file5);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file5.close();

    }
    if (klass=="economy" && numberticket=="2")
    {
        QFile file6("D:\\ticket6.txt");
        file6.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file6);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file6.close();

    }
    if (klass=="economy" && numberticket=="3")
    {
        QFile file7("D:\\ticket7.txt");
        file7.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file7);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file7.close();

    }
    if (klass=="economy" && numberticket=="4")
    {
        QFile file8("D:\\ticket8.txt");
        file8.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file8);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file8.close();

    }
    if (klass=="economy" && numberticket=="5")
    {
        QFile file9("D:\\ticket9.txt");
        file9.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file9);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file9.close();

    }
    if (klass=="economy" && numberticket=="6")
    {
        QFile file10("D:\\ticket10.txt");
        file10.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file10);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file10.close();

    }
    if (klass=="economy" && numberticket=="7")
    {
        QFile file11("D:\\ticket11.txt");
        file11.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file11);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file11.close();

    }
    if (klass=="economy" && numberticket=="8")
    {
        QFile file12("D:\\ticket12.txt");
        file12.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file12);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file12.close();

    }
    if (klass=="economy" && numberticket=="9")
    {
        QFile file13("D:\\ticket13.txt");
        file13.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file13);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file13.close();

    }
    if (klass=="economy" && numberticket=="10")
    {
        QFile file14("D:\\ticket14.txt");
        file14.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file14);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
         file14.close();

    }
    if (klass=="economy" && numberticket=="11")
    {
        QFile file15("D:\\ticket15.txt");
        file15.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file15);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
        file15.close();

    }
    if (klass=="economy" && numberticket=="12")
    {
        QFile file16("D:\\ticket16.txt");
        file16.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file16);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
        file16.close();

    }
    if (klass=="economy" && numberticket=="13")
    {
        QFile file17("D:\\ticket17.txt");
        file17.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file17);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
        file17.close();

    }
    if (klass=="economy" && numberticket=="14")
    {
        QFile file18("D:\\ticket18.txt");
        file18.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file18);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
        file18.close();    
    }
    if (klass=="economy" && numberticket=="15")
    {
        QFile file19("D:\\ticket19.txt");
        file19.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file19);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file19.close();
    }
    if (klass=="economy" && numberticket=="16")
    {
        QFile file20("D:\\ticket20.txt");
        file20.open( QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream writer (&file20);
        writer <<name<<" "<<surname<<" "<< klass<<" "<<numberticket<<" "<<date<<" "<<time<<" "<<flight<<" "<<price;
    file20.close();

    }




}

void MainWindow::on_dataupdate_clicked()
{
    // в файле database.txt хранится информация о цветах кнопок.0-место свободно, 1- место забронировано,
    // 2- место куплено. исходя их этого, делает подсчет
    int income=0;
    int incomeint1=0,incomeint2=0,incomeint3=0,incomeint4=0,incomeint5=0,incomeint6=0,incomeint7=0,incomeint8=0;
    int incomeint9=0,incomeint10=0,incomeint11=0,incomeint12=0,incomeint13=0,incomeint14=0,incomeint15=0,incomeint16=0,incomeint17=0,incomeint18=0,incomeint19=0,incomeint20=0;
    Checkincome(&incomeint1,"D:\\ticket1.txt",16);//  b-"D:\\ticket1.txt" k-место в database
    income+=incomeint1;
    Checkincome(&incomeint2,"D:\\ticket2.txt",17);
    income+=incomeint2;
    Checkincome(&incomeint3,"D:\\ticket3.txt",18);//  b-"D:\\ticket1.txt" k-место в database
    income+=incomeint3;
   Checkincome(&incomeint4,"D:\\ticket4.txt",19);
    income+=incomeint4;
    Checkincome(&incomeint5,"D:\\ticket5.txt",0);
    income+=incomeint5;
    Checkincome(&incomeint6,"D:\\ticket6.txt",1);
    income+=incomeint6;
    Checkincome(&incomeint7,"D:\\ticket7.txt",2);
    income+=incomeint7;
    Checkincome(&incomeint8,"D:\\ticket8.txt",3);
    income+=incomeint8;
    Checkincome(&incomeint9,"D:\\ticket9.txt",4);
    income+=incomeint9;
    Checkincome(&incomeint10,"D:\\ticket10.txt",5);
    income+=incomeint10;
    Checkincome(&incomeint11,"D:\\ticket11.txt",6);
    income+=incomeint11;
    Checkincome(&incomeint12,"D:\\ticket12.txt",7);
    income+=incomeint12;
    Checkincome(&incomeint13,"D:\\ticket13.txt",8);
    income+=incomeint13;
    Checkincome(&incomeint14,"D:\\ticket14.txt",9);
    income+=incomeint14;
    Checkincome(&incomeint15,"D:\\ticket15.txt",10);
    income+=incomeint15;
    Checkincome(&incomeint16,"D:\\ticket16.txt",11);
    income+=incomeint16;
    Checkincome(&incomeint17,"D:\\ticket17.txt",12);
    income+=incomeint17;
    Checkincome(&incomeint18,"D:\\ticket18.txt",13);
    income+=incomeint18;
    Checkincome(&incomeint19,"D:\\ticket19.txt",14);
    income+=incomeint19;
    Checkincome(&incomeint20,"D:\\ticket20.txt",15);
    income+=incomeint20;
    QString m111 = QString::number(income);
    ui->income1->setText(m111);
    // подсчет  проданных билетов
    QString b;
    QString b1;
    QString b2;
    Checkplaces(b,"2");
    ui->buyticket->setText(b);
    Checkplaces(b1,"0");
    ui->free_place->setText(b1);
    Checkplaces(b2,"1");
    ui->busy_places->setText(b2);
}
