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

private:
    ResponsiveLabel* image1;
    ResponsiveLabel* image2;
    ResponsiveLabel* image3;
    ResponsiveLabel* image4;
    ResponsiveLabel* image5;
    ResponsiveLabel* image6;
    ResponsiveLabel* image7;
    ResponsiveLabel* text1;
    ResponsiveLabel* text2;
    ResponsiveLabel* text3;
    ResponsiveLabel* text4;
    ResponsiveLabel* text5;
    ResponsiveLabel* text6;
    ResponsiveLabel* text7;
};

#endif // SEARCHRESULTSWIDGET_H
