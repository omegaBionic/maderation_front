#ifndef BDD_PROMOTION_COMP_H
#define BDD_PROMOTION_COMP_H
#include <QFile>

class bdd_PROMOTION_COMP
{
public:
    bdd_PROMOTION_COMP(int amount, bool addToExistingProm, QString fromDate, QString idPromotionComp, QString toDate);
    bdd_PROMOTION_COMP();
    ~bdd_PROMOTION_COMP();

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

private:
    int _amount;
    bool _addToExistingProm;
    QString _fromDate;
    QString _idPromotionComp;
    QString _toDate;
};

#endif // BDD_PROMOTION_COMP_H
