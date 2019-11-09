#ifndef API_GET_REQUEST_H
#define API_GET_REQUEST_H
#include <QtNetwork>
#include <QObject>
#include "./database_classes/bdd_status.h"
#include "./database_classes/bdd_user.h"
#include "./database_classes/bdd_client.h"
#include "./database_classes/bdd_address_client.h"
#include "./database_classes/bdd_address_supplier.h"
#include "./database_classes/bdd_category.h"
#include "./database_classes/bdd_chat.h"
#include "./database_classes/bdd_component.h"
#include "./database_classes/bdd_gamme.h"
#include "./database_classes/bdd_invoice_quotation.h"
#include "./database_classes/bdd_message.h"
#include "./database_classes/bdd_product.h"
#include "./database_classes/bdd_project.h"
#include "./database_classes/bdd_promotion_cat.h"
#include "./database_classes/bdd_promotion_comp.h"
#include "./database_classes/bdd_quotation.h"
#include "./database_classes/bdd_role.h"
#include "./database_classes/bdd_shop.h"
#include "./database_classes/bdd_stock.h"
#include "./database_classes/bdd_supplier.h"


class api_get_request : public QObject
{
    Q_OBJECT
public:
    explicit api_get_request(QObject *parent = nullptr);

    static void get_status();
    static QVector<bdd_STATUS> parse_file_status();

    static void get_table_user();
    static QVector<bdd_USER> parse_file_user();

    static void get_table_client();
    static QVector<bdd_CLIENT> parse_file_client();

    static void get_table_address_client();
    static QVector<bdd_ADDRESS_CLIENT> parse_file_address_client();

    static void get_table_address_supplier();
    static QVector<bdd_ADDRESS_SUPPLIER> parse_file_address_supplier();

    static void get_table_category();
    static QVector<bdd_CATEGORY> parse_file_category();

    static void get_table_chat();
    static QVector<bdd_CHAT> parse_file_chat();

    static void get_table_component();
    static QVector<bdd_COMPONENT> parse_file_component();

    static void get_table_gamme();
    static QVector<bdd_GAMME> parse_file_gamme();

    static void get_table_invoice_quotation();
    static QVector<bdd_INVOICE_QUOTATION> parse_file_invoice_quotation();

    static void get_table_message();
    static QVector<bdd_MESSAGE> parse_file_message();

    static void get_table_product();
    static QVector<bdd_PRODUCT> parse_file_product();

    static void get_table_project();
    static QVector<bdd_PROJECT> parse_file_project();

    static void get_table_promotion_cat();
    static QVector<bdd_PROMOTION_CAT> parse_file_promotion_cat();

    static void get_table_promotion_comp();
    static QVector<bdd_PROMOTION_COMP> parse_file_promotion_comp();

    static void get_table_quotation();
    static QVector<bdd_QUOTATION> parse_file_quotation();

    static void get_table_role();
    static QVector<bdd_ROLE> parse_file_role();

    static void get_table_shop();
    static QVector<bdd_SHOP> parse_file_shop();

    static void get_table_stock();
    static QVector<bdd_STOCK> parse_file_stock();

    static void get_table_supplier();
    static QVector<bdd_SUPPLIER> parse_file_supplier();

signals:

public slots:

};

#endif // API_GET_REQUEST_H
