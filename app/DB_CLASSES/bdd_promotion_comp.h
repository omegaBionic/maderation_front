#ifndef BDD_PROMOTION_COMP_H
#define BDD_PROMOTION_COMP_H
#include <QFile>
#include "bdd_global.h"

class bdd_PROMOTION_COMP : public bdd_global
{
public:
    bdd_PROMOTION_COMP(int amount, bool addToExistingProm, QString fromDate, QString idPromotionComp, QString toDate);
    bdd_PROMOTION_COMP();
    virtual ~bdd_PROMOTION_COMP();

    void setAmount(int);
    void setAddToExistingProm(bool);
    void setFromDate(QString);
    void setIdPromotionComp(QString);
    void setToDate(QString);

    int getAmount();
    bool getAddToExistingProm();
    QString getFromDate();
    QString getIdPromotionComp();
    QString getToDate();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    int _amount;
    bool _addToExistingProm;
    QString _fromDate;
    QString _idPromotionComp;
    QString _toDate;
};

#endif // BDD_PROMOTION_COMP_H
