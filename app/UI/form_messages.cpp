#include "form_messages.h"
#include "ui_form_messages.h"
#include "../UI/dialog_critical.h"
#include <QDebug>
#include <QDate>
#include <QScrollBar>
#include "../CORE/api_post_request.h"
#include "../CORE/core_messages.h"

Form_messages::Form_messages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_messages)
{
    ui->setupUi(this);
}

Form_messages::Form_messages(QWidget *parent, QVector<bdd_MESSAGE>* listMessage, QString title, QString username, QString IDChat) :
    QWidget(parent),
    ui(new Ui::Form_messages)
{

    ui->setupUi(this);
    _author = username;
    _IDChat = IDChat;
    _listMessage = *listMessage;
    ui->label->setText(title);
    _listLabelDate = new QVector<QLabel*>();
    _listLabelAuthor = new QVector<QLabel*>();
    _listLabelMessages = new QVector<QLabel*>();
    qDebug() << "création des labels";
    for (int i = 0; i < _listMessage.count(); i++){

        qDebug() << "création du label " + QString::number(i);
        bdd_MESSAGE m = _listMessage.at(i);
        QLabel* label_Message = new QLabel(ui->scrollAreaWidgetContents);
        label_Message->setText(m.getMessage());
        label_Message->setStyleSheet("font: 12pt \"Futura Md BT\";");
        QLabel* label_Author = new QLabel(ui->scrollAreaWidgetContents);
        label_Author->setText(m.getUserUsername());
        label_Author->setStyleSheet("font: 12pt \"Futura Md BT\";");
        QLabel* label_Date = new QLabel(ui->scrollAreaWidgetContents);
        label_Date->setText(m.getCreationDate());
        label_Date->setStyleSheet("font: 8pt \"Futura Md BT\";");

        qDebug() << "ajout du label " + QString::number(i);
        _listLabelDate->append(label_Date);
        _listLabelAuthor->append(label_Author);
        _listLabelMessages->append(label_Message);
    }
    ui->scrollArea->setWidgetResizable(false);


}

Form_messages::~Form_messages()
{
    delete ui;
}


void Form_messages::resizeAll(){
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->label->setGeometry(64*_width, 2*_height, 20*_width, 4*_height);
    ui->pushButton->setGeometry(118*_width, 66*_height, 10*_width, 10*_height);
    ui->pushButton->setIcon(QPixmap(":/pictures/img/logo_send.png").scaled(10*_width,10*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->pushButton->setIconSize(QSize(10*_width, 10*_height));
    ui->plainTextEdit->setGeometry(2*_width, 66*_height, 100*_width, 10*_height);

    int count = 0;
    if(_listLabelMessages->count() == _listLabelDate->count() && _listLabelMessages->count() == _listLabelAuthor->count()){
        qDebug()<<"affichage des messages";
        for(int i = 0; i<_listLabelMessages->count(); i++){
            qDebug() << "i = " << i;
            int index = _listLabelMessages->count()-1 -i;
            if(_author == _listLabelAuthor->at(i)->text()){
                _listLabelDate->at(i)->setVisible(true);
                _listLabelAuthor->at(i)->setVisible(true);
                _listLabelMessages->at(i)->setVisible(true);
                qDebug()<<"affichage du message " + QString::number(i);

                _listLabelAuthor->at(i)->setGeometry(98*_width, index* 16 *_height, 30*_width, 3*_height);
                _listLabelMessages->at(i)->setGeometry(68*_width, index*16 *_height + 3*_height, 60*_width, 10*_height);
                _listLabelMessages->at(i)->setStyleSheet("border-image: url(:/pictures/img/bg_plaintext.png);font: 12pt \"Futura Lt BT\";padding: 5 5 5 5;");
                _listLabelDate->at(i)->setGeometry(98*_width, index*16 *_height + 13 *_height, 30*_width, 3*_height);
                _listLabelAuthor->at(i)->setAlignment(Qt::AlignRight);
                _listLabelMessages->at(i)->setAlignment(Qt::AlignRight);
                _listLabelMessages->at(i)->setWordWrap(true);
                _listLabelDate->at(i)->setAlignment(Qt::AlignRight);
            }else{
                qDebug()<<"affichage du message " + QString::number(i);
                _listLabelDate->at(i)->setVisible(true);
                _listLabelAuthor->at(i)->setVisible(true);
                _listLabelMessages->at(i)->setVisible(true);
                _listLabelAuthor->at(i)->setGeometry(0*_width, index*16 *_height, 30*_width, 3*_height);
                _listLabelMessages->at(i)->setGeometry(0*_width, index*16 *_height+ 3*_height, 60*_width, 10*_height);
                _listLabelMessages->at(i)->setStyleSheet("border-image: url(:/pictures/img/bg_plaintext.png);font: 12pt \"Futura Lt BT\";padding: 5 5 5 5;");
                _listLabelDate->at(i)->setGeometry(0*_width, index*16 *_height + 13 * _height, 30*_width, 3*_height);

                _listLabelMessages->at(i)->setAlignment(Qt::AlignLeft);
                _listLabelMessages->at(i)->setWordWrap(true);
            }
        count ++;
        }
    }
    ui->scrollAreaWidgetContents->setGeometry(0*_width, 8*_height, 128*_width, count *16*_height);
    ui->scrollArea->setGeometry(0*_width, 8*_height, 128*_width, 55*_height);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

}


void Form_messages::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    this->resizeAll();

}

void Form_messages::on_plainTextEdit_textChanged()
{
 if(ui->plainTextEdit->toPlainText().length() > 200){
     ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText().left(200));
 }
 QTextCursor tmpCursor = ui->plainTextEdit->textCursor();
 tmpCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
 ui->plainTextEdit->setTextCursor(tmpCursor);
}

void Form_messages::on_pushButton_clicked()
{
    qDebug() << _listLabelMessages->count();
    QLabel* label_Message = new QLabel(ui->scrollAreaWidgetContents);
    label_Message->setText(ui->plainTextEdit->toPlainText());
    label_Message->setStyleSheet("font: 12pt \"Futura Md BT\";");
    QLabel* label_Author = new QLabel(ui->scrollAreaWidgetContents);
    label_Author->setText(_author);
    label_Author->setStyleSheet("font: 12pt \"Futura Md BT\";");
    QLabel* label_Date = new QLabel(ui->scrollAreaWidgetContents);
    label_Date->setText(QString::number(QDate::currentDate().day()) + " " + QDate::currentDate().longMonthName(QDate::currentDate().month()) + " " + QString::number(QDate::currentDate().year()));
    label_Date->setStyleSheet("font: 8pt \"Futura Md BT\";");
    core_messages* core = new core_messages();

    bdd_MESSAGE msg = bdd_MESSAGE(core->getTime(), ui->plainTextEdit->toPlainText(),_IDChat,_author, QString::number(core->getIDMsg()));

    msg.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(msg, "add");

    _listLabelDate->append(label_Date);
    _listLabelAuthor->append(label_Author);
    _listLabelMessages->append(label_Message);
    _listMessage.append(msg);
    this->resizeAll();
    this->update();
    ui->plainTextEdit->setPlainText("");
    ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
}
