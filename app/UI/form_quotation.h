#ifndef FORM_QUOTATION_H
#define FORM_QUOTATION_H

#include <QWidget>
#include <QGraphicsScene>
#include "../DB_CLASSES/bdd_invoice_quotation.h"
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_client.h"
#include "../DB_CLASSES/bdd_address_client.h"
#include "../DB_CLASSES/bdd_attribut.h"
#include "../DB_CLASSES/bdd_product.h"
#include "../DB_CLASSES/bdd_component.h"

namespace Ui {
class Form_quotation;
}

class Form_quotation : public QWidget
{
    Q_OBJECT

public:
    explicit Form_quotation(QWidget *parent = nullptr);
    explicit Form_quotation(QWidget *parent = nullptr, bdd_PROJECT project = bdd_PROJECT());
    ~Form_quotation();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_tva_currentTextChanged(const QString &arg1);

    void on_pushButton_validate_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Form_quotation *ui;
    void refreshScene();
    QString getTime();
    QString getExpirationTime();
    void resizeEvent(QResizeEvent * event);
    QGraphicsScene* _scene;
    int _width;
    int _height;
    QString _template_full_html;
    QString _paiement;
    QString _Facture;
    double _tva;
    double _total;
    bdd_INVOICE_QUOTATION _invoice;
    bdd_PROJECT _project;
    QMap<QString, QMap<QString, QString>>* _listComponents;
};

#endif // FORM_QUOTATION_H
