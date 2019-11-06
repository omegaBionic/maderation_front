signals:
#ifndef API_GET_REQUEST_H
#define API_GET_REQUEST_H
#include <QtNetwork>
#include <QObject>


class api_get_request : public QObject
{
    Q_OBJECT
public:
    explicit api_get_request(QObject *parent = nullptr);

    static void get_status();
    static void parse_file_status();

    static void get_table_user();
    static void parse_file_user();

    static void get_table_client();
    static void parse_file_client();

    static void get_table_address_client();
    static void parse_file_address_client();

    static void get_table_address_supplier();
    static void parse_file_address_supplier();

    static void get_table_category();
    static void parse_file_category();

    static void get_table_chat();
    static void parse_file_chat();

    static void get_table_component();
    static void parse_file_component();

    static void get_table_gamme();
    static void parse_file_gamme();

    static void get_table_invoice_quotation();
    static void parse_file_invoice_quotation();

    static void get_table_message();
    static void parse_file_message();

    static void get_table_product();
    static void parse_file_product();

    static void get_table_project();
    static void parse_file_project();

    static void get_table_promotion_cat();
    static void parse_file_promotion_cat();

    static void get_table_promotion_comp();
    static void parse_file_promotion_comp();

    static void get_table_quotation();
    static void parse_file_quotation();

    static void get_table_role();
    static void parse_file_role();

    static void get_table_shop();
    static void parse_file_shop();

    static void get_table_stock();
    static void parse_file_stock();

    static void get_table_supplier();
    static void parse_file_supplier();

signals:

public slots:

};

#endif // API_GET_REQUEST_H
