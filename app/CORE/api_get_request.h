#ifndef API_GET_REQUEST_H
#define API_GET_REQUEST_H
#include <QtNetwork>
#include <QObject>
#include "../DB_CLASSES/bdd_status.h"
#include "../DB_CLASSES/bdd_user.h"
#include "../DB_CLASSES/bdd_client.h"
#include "../DB_CLASSES/bdd_address_client.h"
#include "../DB_CLASSES/bdd_address_supplier.h"
#include "../DB_CLASSES/bdd_category.h"
#include "../DB_CLASSES/bdd_chat.h"
#include "../DB_CLASSES/bdd_component.h"
#include "../DB_CLASSES/bdd_gamme.h"
#include "../DB_CLASSES/bdd_invoice_quotation.h"
#include "../DB_CLASSES/bdd_message.h"
#include "../DB_CLASSES/bdd_product.h"
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_promotion_cat.h"
#include "../DB_CLASSES/bdd_promotion_comp.h"
#include "../DB_CLASSES/bdd_quotation.h"
#include "../DB_CLASSES/bdd_role.h"
#include "../DB_CLASSES/bdd_shop.h"
#include "../DB_CLASSES/bdd_stock.h"
#include "../DB_CLASSES/bdd_supplier.h"
#include "../DB_CLASSES/bdd_attribut.h"


class api_get_request : public QObject
{
    Q_OBJECT
public:
    explicit api_get_request(QObject *parent = nullptr);

    void get_status();
    QVector<bdd_STATUS> parse_file_status();

    void get_table_user();
     QVector<bdd_USER> parse_file_user();

     void get_table_client();
     QVector<bdd_CLIENT> parse_file_client();

     void get_table_address_client();
     QVector<bdd_ADDRESS_CLIENT> parse_file_address_client();

     void get_table_address_supplier();
     QVector<bdd_ADDRESS_SUPPLIER> parse_file_address_supplier();

     void get_table_category();
     QVector<bdd_CATEGORY> parse_file_category();

     void get_table_chat();
     QVector<bdd_CHAT> parse_file_chat();

     void get_table_component();
     QVector<bdd_COMPONENT> parse_file_component();

     void get_table_gamme();
     QVector<bdd_GAMME> parse_file_gamme();

     void get_table_invoice_quotation();
     QVector<bdd_INVOICE_QUOTATION> parse_file_invoice_quotation();

     void get_table_message();
     QVector<bdd_MESSAGE> parse_file_message();

     void get_table_product();
     QVector<bdd_PRODUCT> parse_file_product();

     void get_table_project();
     QVector<bdd_PROJECT> parse_file_project();

     void get_table_promotion_cat();
     QVector<bdd_PROMOTION_CAT> parse_file_promotion_cat();

     void get_table_promotion_comp();
     QVector<bdd_PROMOTION_COMP> parse_file_promotion_comp();

     void get_table_quotation();
     QVector<bdd_QUOTATION> parse_file_quotation();

     void get_table_role();
     QVector<bdd_ROLE> parse_file_role();

     void get_table_shop();
     QVector<bdd_SHOP> parse_file_shop();

     void get_table_stock();
     QVector<bdd_STOCK> parse_file_stock();

     void get_table_supplier();
     QVector<bdd_SUPPLIER> parse_file_supplier();

     void get_table_attribut();
     QVector<bdd_ATTRIBUT> parse_file_attribut();

signals:

public slots:
    void downloadFinished(QNetworkReply* reply);

private:
    void get_table(QUrl url);


};

#endif // API_GET_REQUEST_H
