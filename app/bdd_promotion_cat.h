#ifndef BDD_PROMOTION_CAT_H
#define BDD_PROMOTION_CAT_H
#include <QFile>

class bdd_PROMOTION_CAT
{
public:
    bdd_PROMOTION_CAT(int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate);
    ~bdd_PROMOTION_CAT();

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

private:
    int _amount;
    bool _addToExistingProm;
    QString _fromDate;
    QString _idPromotionCat;
    QString _toDate;
};

#endif // BDD_PROMOTION_CAT_H
