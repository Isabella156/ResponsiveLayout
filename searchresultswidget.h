#ifndef SEARCHRESULTSWIDGET_H
#define SEARCHRESULTSWIDGET_H

#include <QWidget>
#include "responsive_layout.h"
#include "responsive_label.h"


class SearchResultsWidget: public QWidget
{
    Q_OBJECT
public:
    explicit SearchResultsWidget(QWidget *parent = 0);
    void initWidget(QLayout *layout);

};

#endif // SEARCHRESULTSWIDGET_H
