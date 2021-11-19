/*
 * @Author: your name
 * @Date: 2021-11-15 20:55:08
 * @LastEditTime: 2021-11-19 09:57:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \responsive\scroll_layout.h
 */
#ifndef SCROLLLAYOUT_H
#define SCROLLLAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>

class ScrollLayout : public QLayout
{
public:
    ScrollLayout(): QLayout(){};
    ScrollLayout(QWidget *parents): QLayout(parents){};
    ~ScrollLayout();

    // standard functions for a QLayout
    void setGeometry(const QRect &rect);

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);

private:
    QList<QLayoutItem*> list_;
};

#endif // SCROLLLAYOUT_H
