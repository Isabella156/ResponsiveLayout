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
    void addLabel(ResponsiveLayout* rl);
    void addScroll();

private:
    QScrollArea* scrollArea;
    QWidget* scroll;

};


#endif //RESPONSIVEWINDOW_H
