//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVEWINDOW_H
#define RESPONSIVEWINDOW_H

#include <QWidget>
#include "responsive_layout.h"
#include <QScrollArea>

class ResponsiveWindow: public QWidget {

public:
    ResponsiveWindow();

protected:
    void resizeEvent(QResizeEvent *event);
    void createWidgets();
    void horizontalScroll(double &areaX, double &areaY, double &areaWidth, double &areaHeight, \
        double &scrollX, double &scrollY, double &scrollWidth, double &scrollHeight, double spacing, \
        double width, double height, int column);
    void verticalOneScroll(double &areaX, double &areaY, double &areaWidth, \
        double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
        double &scrollHeight, double width, double height);
    void verticalTwoScroll(double &areaX, double &areaY, double &areaWidth, \
        double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
        double &scrollHeight, double width, double height);
    void verticalThreeScroll(double &areaX, double &areaY, double &areaWidth, \
        double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
        double width, double height);

private:
    QScrollArea* scrollArea;
    QWidget* scroll;

};




#endif //RESPONSIVEWINDOW_H
