#include "form_quotation.h"
#include "ui_form_quotation.h"
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "widget_custom.h"
#include <QtPrintSupport/QtPrintSupport>
#include "../CORE/core_quotation.h"
#include "../CORE/core_post_mail_files.h"


#include <QPrinter>


//webView = new QWebEngineView(this);
//webView->setGeometry(QRect(0,100,1920,900));
//webView->load(QUrl("https://survey1.gfkdrive.com/IQ/Daphne.php?RID=TXTIDVkXTJwsFETsQqJGhnD9HNRPLxlS&PID=DaphneCM&A=NEW&L=fra&DOMAIN=LOYALTY"));
//webView->show();

Form_quotation::Form_quotation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_quotation)
{
    ui->setupUi(this);
    this->raise();

}

Form_quotation::Form_quotation(QWidget *parent, bdd_PROJECT project) :
    QWidget(parent),
    ui(new Ui::Form_quotation)
{
    ui->setupUi(this);
    _project = project;
    QFile template_full(":/html_template/template_html.htm");

    template_full.open(QIODevice::ReadOnly);


    ui->scrollArea->setWidgetResizable(false);
    _listComponents = new QMap<QString, QMap<QString, QString>>() ;
    _template_full_html  = "";
    QTextStream in(&template_full);
    in.setCodec(QTextCodec::codecForName("UTF-8"));
    _template_full_html = in.readAll();
    _tva = ui->comboBox_tva->currentText().toDouble();
    _paiement = ui->comboBox->currentText();
    core_quotation* core = new core_quotation();

    ui->lineEdit->setText(core->getClientMail(_project.getIDClient().toInt()));
    _template_full_html.replace("{{date_today}}", this->getTime());
    _template_full_html.replace("{{expiration_date}}", this->getExpirationTime());
    _template_full_html.replace("{{echeance}}", this->getExpirationTime());
    _Facture = _project.getTitle() + "-"+ this->getTime().toLocal8Bit().toBase64();
    _Facture = _Facture.replace(" ","");
    _template_full_html.replace("{{facture_code}}", _Facture);


    _template_full_html.replace("{{client_name}}", core->getClientName(_project.getIDClient().toInt()));
    _template_full_html.replace("{{client_address}}", core->getClientAddress(_project.getIDClient().toInt()));
    _template_full_html.replace("{{client_city}}", core->getClientCity(_project.getIDClient().toInt()));
    _template_full_html.replace("{{client_phone}}", core->getClientPhone(_project.getIDClient().toInt()));
    _template_full_html.replace("{{user_name}}", _project.getUserUserName());
    _template_full_html.replace("{{echeance}}", this->getExpirationTime());



    QVector<bdd_ATTRIBUT> listAttribut = core->getAttributs(_project);
    for(int i =0; i< listAttribut.count(); i++){
        bdd_ATTRIBUT attr = listAttribut.at(i);
        bdd_PRODUCT product = core->getProductByID(attr.getProductIdProduct());
        QVector<bdd_COMPONENT> listCompo = core->getComponents(product);
        for(int j = 0; j < listCompo.count();j++){

            bdd_COMPONENT compo = listCompo.at(j);

            QList<QString> listKeys = _listComponents->keys();
            bool alreadyInKeys = false;
            for(int k = 0; k < listKeys.count(); k ++){
                QString key = listKeys.at(k);
                if(compo.getIdComponent() == key){
                    alreadyInKeys = true;
                }
            }
            if(!alreadyInKeys){
                QMap<QString, QString> dataCompo;
                dataCompo.insert("amount", QString::number(compo.getAmount()));
                dataCompo.insert("label", compo.getLabel());
                dataCompo.insert("price", QString::number(compo.getPrice()));
                _listComponents->insert(compo.getIdComponent(),dataCompo);
            }else{
                QMap<QString,QString> dataCompo = _listComponents->value(compo.getIdComponent());
                dataCompo["amount"] = QString::number(dataCompo["amount"].toInt() + compo.getAmount());
                _listComponents->insert(compo.getIdComponent(),dataCompo);

            }

        }



    }


    template_full.close();

}


Form_quotation::~Form_quotation()
{
    delete ui;
}

void Form_quotation::refreshScene(){
    _listComponents = new QMap<QString, QMap<QString, QString>>();
    core_quotation* core = new core_quotation();
    int lines = 20;
    QString text = "Récapitulatif du devis : \n\n";
    text += "N° Facture " + _Facture + "\n";
    text += "Date : " + this->getTime()+ "\n";
    text += "Date d'échéance : " + this->getExpirationTime()+ "\n";
    text += "Client : " + core->getClientName(_project.getIDClient().toInt())+ "\n";
    text += "Adress du client : " + core->getClientAddress(_project.getIDClient().toInt()) + ", " + core->getClientCity(_project.getIDClient().toInt())+ "\n";
    text += "Téléphone du client : " +  core->getClientPhone(_project.getIDClient().toInt())+ "\n";
    text += "Email du client : " + core->getClientMail(_project.getIDClient().toInt()) + "\n";

    text += "Details : \n\n\n";
    text += "Méthode de paiement : "+ui->comboBox->currentText()+" \n\n";

    QVector<bdd_ATTRIBUT> listAttribut = core->getAttributs(_project);
    double total = 0;

    for(int i =0; i< listAttribut.count(); i++){

        lines += 6;
        bdd_ATTRIBUT attr = listAttribut.at(i);
        bdd_PRODUCT product = core->getProductByID(attr.getProductIdProduct());
        QVector<bdd_COMPONENT> listCompo = core->getComponents(product);
        for(int j = 0; j < listCompo.count();j++){

            bdd_COMPONENT compo = listCompo.at(j);

            QList<QString> listKeys = _listComponents->keys();
            bool alreadyInKeys = false;
            for(int k = 0; k < listKeys.count(); k ++){
                QString key = listKeys.at(k);
                if(compo.getIdComponent() == key){
                    alreadyInKeys = true;
                }
            }
            if(!alreadyInKeys){
                QMap<QString, QString> dataCompo;
                dataCompo.insert("amount", QString::number(compo.getAmount()));
                dataCompo.insert("label", compo.getLabel());
                dataCompo.insert("price", QString::number(compo.getPrice()));
                _listComponents->insert(compo.getIdComponent(),dataCompo);
            }else{
                QMap<QString,QString> dataCompo = _listComponents->value(compo.getIdComponent());
                dataCompo["amount"] = QString::number(dataCompo["amount"].toInt() + compo.getAmount());
                _listComponents->insert(compo.getIdComponent(),dataCompo);

            }

        }



    }
    for(int j = 0; j <_listComponents->keys().count(); j++){
        QString key = _listComponents->keys().at(j);
        int totalValue = _listComponents->value(key).value("amount").toInt() * _listComponents->value(key).value("price").toDouble();
        text += "-- " + _listComponents->value(key).value("label")  + "\n";
        text += "   - Quantité : " + _listComponents->value(key).value("amount")  + "\n";
        text += "   - Prix unitaire : " + _listComponents->value(key).value("price")  + "\n";
        text += "   - Total : " + QString::number(totalValue) + "€"  + "\n";
        total += totalValue;
    }



    text += "\n\nSous-total : " + QString::number(total) + "€" + "\n";
    text += "TVA : " + ui->comboBox_tva->currentText() + "\n";
    double tva =  1 + ui->comboBox_tva->currentText().toDouble()/100;
    text += "\nTOTAL : " + QString::number(total * tva) + " €\n";

    ui->label_2->setText(text);

    ui->label_2->setGeometry(0*_width, 0*_height, 90*_width, lines * _height);
    ui->scrollAreaWidgetContents->setGeometry(0*_width, 0*_height, 90*_width, lines * _height);

}

void Form_quotation::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    ui->scrollArea->setGeometry(0*_width, 0*_height, 90*_width, 74*_height);
    ui->scrollAreaWidgetContents->setGeometry(0*_width, 0*_height, 90*_width, 74*_height);
    ui->pushButton_cancel->setGeometry(QRect(103*_width, 64*_height, 10*_width, 10*_height));
    ui->pushButton_validate->setGeometry(115*_width, 64*_height, 10*_width, 10 *_height);
    ui->label->setGeometry(95*_width, 16*_height, 30*_width, 4*_height);
    ui->lineEdit->setGeometry(95*_width, 40*_height, 30*_width, 4*_height);
    ui->comboBox->setGeometry(95*_width, 20*_height, 30*_width, 4*_height);
    ui->comboBox_tva->setGeometry(95*_width, 30*_height, 30*_width, 4*_height);
    this->refreshScene();
}


QString Form_quotation::getTime()
{

        // recupération de la date et de l'horloge actuelle
            QDate currentDate = QDate::currentDate();
            qDebug()<<currentDate;
            QTime currentTime = QTime::currentTime();
            qDebug()<<currentTime;
        // transformation en QString
            QString currentDateString = currentDate.toString();
            QString currentTimeString = currentTime.toString();
        // concaténation
            QString currentDateTime = currentDateString + " " + currentTimeString;

            qDebug()<<currentDateTime;

            return  currentDateTime;


}

QString Form_quotation::getExpirationTime()
{

        // recupération de la date et de l'horloge actuelle
            QDate currentDate = QDate::currentDate().addDays(15);
            QTime currentTime = QTime::currentTime();
        // transformation en QString
            QString currentDateString = currentDate.toString();
            QString currentTimeString = currentTime.toString();
        // concaténation
            QString currentDateTime = currentDateString + " " + currentTimeString;

            return  currentDateTime;


}


void Form_quotation::on_comboBox_currentTextChanged(const QString &arg1)
{
    _paiement = arg1;
    this->refreshScene();
}

void Form_quotation::on_comboBox_tva_currentTextChanged(const QString &arg1)
{
    _tva = arg1.toDouble();
    this->refreshScene();
}

void Form_quotation::on_pushButton_validate_clicked()
{
    QFile template_line(":/html_template/template_line.html");

    template_line.open(QIODevice::ReadOnly);

    QString linesToAdd = "";
    QString lineTemplate = "";

    QTextStream lines(&template_line);
    lines.setCodec(QTextCodec::codecForName("UTF-8"));
    lineTemplate = lines.readAll();
    double total = 0;

        _template_full_html.replace("{{paiement_method}}", _paiement);
        _template_full_html.replace("{{tva}}", QString::number(_tva) );
    for(int j = 0; j <_listComponents->keys().count(); j++){
        QString key = _listComponents->keys().at(j);
        linesToAdd += lineTemplate;
        int totalValue = _listComponents->value(key).value("amount").toInt() * _listComponents->value(key).value("price").toDouble();
        linesToAdd.replace("{{quantite}}",  _listComponents->value(key).value("amount"));
        linesToAdd.replace("{{description}}", _listComponents->value(key).value("label"));
        linesToAdd.replace("{{prix_unitaire}}", _listComponents->value(key).value("price"));
        linesToAdd.replace("{{lineTotal}}", QString::number(totalValue) + "€");
        total += totalValue;
    }





    _template_full_html.replace("{{data_component}}", linesToAdd);

    _template_full_html.replace("{{sous_total}}", QString::number(total));
    _template_full_html.replace("{{total}}", QString::number(total * _tva/100));

    QFile temp("DATA_IMG/" + _Facture + ".html");
    temp.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&temp);
    out << _template_full_html;

    temp.flush();
    temp.close();

    QTextDocument document;

    document.setHtml(_template_full_html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPaperSize(QPrinter::A3);
    printer.setOutputFileName("DATA_IMG/" + _Facture + ".pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

    core_quotation* quot = new core_quotation();
    core_post_mail_files* core = new core_post_mail_files();
    core->sendFile("DATA_IMG/" + _Facture + ".pdf",  _Facture.split("-")[0] + ".pdf", "pdf");
    core->sendFile("DATA_IMG/" + _Facture + ".html",  _Facture.split("-")[0] + ".html", "html");

    QString body =
    "Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera :<br> "
    "<a href='https://maderationpictures.s3-eu-west-1.amazonaws.com/"+_Facture + ".pdf'>Au format PDF</a><br>"
    "<a href='https://maderationpictures.s3-eu-west-1.amazonaws.com/"+_Facture + ".html'>Au format HTML</a>"
    "<br><br>Cordialement,<br>L'équipe Madera" ;
    qDebug() << body;
    core->send(ui->lineEdit->text(),quot->getUserMail(_project.getUserUserName()),"Votre devis de " + _project.getTitle(),body,"");
}

void Form_quotation::on_pushButton_cancel_clicked()
{
    emit cancelled();
    this->close();
}
