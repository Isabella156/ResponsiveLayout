//
// Created by twak on 07/10/2019.
//

#ifndef RESPONSIVELAYOUT_H
#define RESPONSIVELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>
#include <QScrollArea>
#include "responsive_label.h"
#include "searchresultswidget.h"

class ResponsiveLayout : public QLayout {

public:
    ResponsiveLayout(): QLayout() {
//        addChildLayout()
    }
    ResponsiveLayout(QWidget *parents): QLayout(parents){

    };
    ~ResponsiveLayout();

    // standard functions for a QLayout
    void setGeometry(const QRect &rect);
    void verticalOne(const QRect &r, ResponsiveLabel* label, int &resultCnt);
    void verticalTwo(const QRect &r, ResponsiveLabel* label, int &resultCnt);
    void verticalThree(const QRect &r, ResponsiveLabel* label, int &resultCnt);
    void horizontalOne(const QRect &r, ResponsiveLabel* label, int &resultCnt);
    void setSearchGeometry(const QRect &r, ResponsiveLabel* label, int &resultCnt, int column);
    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);

private:
    QList<QLayoutItem*> list_;
};
#endif // RESPONSIVELAYOUT_H
