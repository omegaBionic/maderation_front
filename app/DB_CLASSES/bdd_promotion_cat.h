#ifndef BDD_PROMOTION_CAT_H
#define BDD_PROMOTION_CAT_H
#include <QFile>
#include "bdd_global.h"

class bdd_PROMOTION_CAT : public bdd_global
{
public:
    bdd_PROMOTION_CAT(int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate);
    bdd_PROMOTION_CAT();
    virtual ~bdd_PROMOTION_CAT();

    void setAmount(int);
    void setAddToExistingProm(bool);
    void setFromDate(QString);
    void setIdPromotionCat(QString);
    void setToDate(QString);

    int getAmount();
    bool getAddToExistingProm();
    QString getFromDate();
    QString getIdPromotionCat();
    QString getToDate();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;

private:
    int _amount;
    bool _addToExistingProm;
    QString _fromDate;
    QString _idPromotionCat;
    QString _toDate;
};

#endif // BDD_PROMOTION_CAT_H
