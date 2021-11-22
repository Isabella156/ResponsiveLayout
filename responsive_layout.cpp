//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include <iostream>



// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r ) { // our layout should fit inside r

    QLayout::setGeometry(r);
    int resultCnt = 0, squareWidth, column;
    double spacing = 0.01 * r.width();

    for (int i = 0; i < list_.size(); i++) {
        QLayoutItem *o = list_.at(i);
        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            else if(r.width() < 428)
            // first vertical layout
                verticalOne(r, label, resultCnt, spacing);
            else if(r.width() >= 428 && r.width() <= 620){
                column = 2;
                squareWidth = r.width() / column;
                if(r.height() - 210< squareWidth)
                // horizontal layout
                    horizontalOne(r, label, spacing);
                else
                // second vertical layout
                    verticalTwo(r, label, resultCnt, spacing);
            }else if(r.width() > 620 && r.width() < 890){
                if(r.width() < 890){
                    column = 3;
                    setSearchGeometry(r, label, resultCnt, 3);
                }else{
                    column = 4;
                    setSearchGeometry(r, label, resultCnt, 4);
                }
                squareWidth = r.width() / column;
                if(r.height() - 270< squareWidth)
                    horizontalOne(r, label, spacing);
                else
                // third vertical layout
                    verticalThree(r, label, spacing);
            }else{
                column = 4;
                squareWidth = r.width() / column;
                if(r.height() - 270 < squareWidth)
                    horizontalOne(r, label, spacing);
                else
                // fourth vertical layout
                    verticalFour(r, label, resultCnt, spacing);
            }
        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}

// first vertical layout
void ResponsiveLayout::verticalOne(const QRect &r, ResponsiveLabel* label, \
int &resultCnt, double spacing){
    if(label->text() == kHomeLink)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kShoppingBasket)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSignIn)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kMenu)
        label->setGeometry(spacing, 0, 0.16 * r.width(), 45);
    else if(label->text() == kNavTabs)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kAdvert){
        label->setGeometry(spacing, 45 + spacing, 0.98 * r.width(), 100);
    }else if(label->text() == kSButton)
        label->setGeometry(0.69 * r.width(), 0, 0.3 * r.width(), 45);
    else if(label->text() == kSQuery)
        label->setGeometry(0.18 * r.width(), 0, 0.5 * r.width(), 45);
    else if(label->text() == kSOptions)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSOrders)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSLocation)
        label->setGeometry(0, 0, 0, 0);  
    setSearchGeometry(r, label, resultCnt, 2);
}

// second vertical layout
void ResponsiveLayout::verticalTwo(const QRect &r, ResponsiveLabel* label, \
int &resultCnt, double spacing){
    if(label->text() == kHomeLink)
        label->setGeometry(0.12 * r.width(), 0, 0.15 * r.width(), 45);
    else if(label->text() == kShoppingBasket)
        label->setGeometry(0.83 * r.width(), 0, 0.15 * r.width(), 45);
    else if(label->text() == kSignIn)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kMenu)
        label->setGeometry(spacing, 0, 0.1 * r.width(), 45);
    else if(label->text() == kNavTabs)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kAdvert){
        label->setGeometry(spacing, 45 + spacing, 0.98 * r.width(), 120);
    }else if(label->text() == kSButton)
        label->setGeometry(0.64 * r.width(), 0, 0.18 * r.width(), 45);
    else if(label->text() == kSQuery)
        label->setGeometry(0.28 * r.width(), 0, 0.35 * r.width(), 45);
    else if(label->text() == kSOptions)
        label->setGeometry(spacing, 165 + 2 * spacing, 0.98 * r.width(), 45);
    else if(label->text() == kSOrders)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSLocation)
        label->setGeometry(0, 0, 0, 0);
    setSearchGeometry(r, label, resultCnt, 2);
}

// three vertical layout
void ResponsiveLayout::verticalThree(const QRect &r, ResponsiveLabel* label, \
 double spacing){
    if(label->text() == kHomeLink)
        label->setGeometry(spacing, 0, 0.12 * r.width(), 50);
    else if(label->text() == kShoppingBasket)
        label->setGeometry(0.67 * r.width(), 0, 0.15 * r.width(), 50);
    else if(label->text() == kSignIn)
        label->setGeometry(0.83 * r.width(), 0, 0.15 * r.width(), 50);
    else if(label->text() == kMenu)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kNavTabs)
        label->setGeometry(spacing, 50 + spacing, 0.98 * r.width(), 50);
    else if(label->text() == kAdvert){
        label->setGeometry(spacing, 100 + 2 * spacing, 0.98 * r.width(), 120);
    }else if(label->text() == kSButton)
        label->setGeometry(0.51 * r.width(), 0, 0.15 * r.width(), 50);
    else if(label->text() == kSQuery)
        label->setGeometry(0.14 * r.width(), 0, 0.36 * r.width(), 50);
    else if(label->text() == kSOptions)
        label->setGeometry(spacing, 220 + 3 * spacing, 0.98 * r.width(), 50);
    else if(label->text() == kSOrders)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSLocation)
        label->setGeometry(0, 0, 0, 0);
}

// fourth vertical layout
void ResponsiveLayout::verticalFour(const QRect &r, ResponsiveLabel* label, \
int &resultCnt, double spacing){
    if(label->text() == kHomeLink)
        label->setGeometry(0.12 * r.width(), 0, 0.1 * r.width() , 50);
    else if(label->text() == kShoppingBasket)
        label->setGeometry(0.56 * r.width(), 0, 0.1 * r.width(), 50);
    else if(label->text() == kSignIn)
        label->setGeometry(0.67 * r.width(), 0, 0.1 * r.width(), 50);
    else if(label->text() == kMenu)
        label->setGeometry(spacing, 0, 0.1 * r.width(), 50);
    else if(label->text() == kNavTabs)
        label->setGeometry(spacing, 50 + spacing, 0.98 * r.width(), 50);
    else if(label->text() == kAdvert){
        label->setGeometry(spacing, 100 + 2 * spacing, 0.98 * r.width(), 120);
    }else if(label->text() == kSButton)
        label->setGeometry(0.45 * r.width(), 0, 0.1 * r.width(), 50);
    else if(label->text() == kSQuery)
        label->setGeometry(0.23 * r.width(), 0, 0.21 * r.width(), 50);
    else if(label->text() == kSOptions)
        label->setGeometry(spacing, 220 + 3 * spacing, 0.98 * r.width(), 50);
    else if(label->text() == kSOrders)
        label->setGeometry(0.78 * r.width(), 0, 0.1 * r.width(), 50);
    else if(label->text() == kSLocation)
        label->setGeometry(0.89 * r.width(), 0, 0.1 * r.width(), 50);
    setSearchGeometry(r, label, resultCnt, 4);
}

// horizontal layout
void ResponsiveLayout::horizontalOne(const QRect &r, ResponsiveLabel* label, double spacing){
    double widgetHeight = (r.height() - 4 * spacing) / 5;
    if(label->text() == kHomeLink)
        label->setGeometry(spacing, widgetHeight + spacing, 80, widgetHeight);
    else if(label->text() == kShoppingBasket)
        label->setGeometry(spacing, (widgetHeight +spacing) * 2, 80, widgetHeight);
    else if(label->text() == kSignIn)
        label->setGeometry(spacing, (widgetHeight +spacing) * 3, 80, widgetHeight);
    else if(label->text() == kMenu)
        label->setGeometry(spacing, 0, 80, widgetHeight);
    else if(label->text() == kNavTabs)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kAdvert){
        label->setGeometry(80 + 2 * spacing, 0, 100, r.height());
    }else if(label->text() == kSButton)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSQuery)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSOptions)
        label->setGeometry(0, 0, 0, 0);
    else if(label->text() == kSOrders)
        label->setGeometry(spacing, widgetHeight * 4 + spacing * 4, 80, widgetHeight);
    else if(label->text() == kSLocation)
        label->setGeometry(0, 0, 0, 0);
}

// set geometry for widgets in scroll area
void ResponsiveLayout::setSearchGeometry(const QRect &r, ResponsiveLabel* label, int &resultCnt, int column){
    double spacing = 0.01 * r.width();
    double squareWidth = (0.99 * r.width() - spacing * column) / column;
    double imageHeight = (squareWidth - spacing) * 0.8;
    double textHeight = (squareWidth - spacing) * 0.2;
    if(label->text() == kSResultImage){
        resultCnt++;
        int remainder = resultCnt % column;
        int divisor = resultCnt / column;
        if(!remainder){
            remainder = column;
            divisor --;
        }
        double imageX = spacing * remainder + (remainder - 1) * squareWidth;
        double imageY = divisor * (squareWidth + spacing);
        label->setGeometry(imageX, imageY , squareWidth, imageHeight);
    }else if(label->text() == kSResultText){
        int remainder = resultCnt % column;
        int divisor = resultCnt / column;
        if(!remainder){
            remainder = column;
            divisor --;
        }
        double textX = spacing * remainder + (remainder - 1) * squareWidth;
        double textY = divisor* (squareWidth + spacing) + imageHeight + spacing;
        label->setGeometry(textX, textY, squareWidth, textHeight);
    }else if(label->text() == kSBackward){
        double backwardX = 0.495 * r.width() - textHeight;
        double backwardY = (resultCnt / column + 1) * (squareWidth + spacing);
        label->setGeometry(backwardX, backwardY, textHeight, textHeight);
    }else if(label->text() == kSForward){
        double forwardX = 0.505 * r.width();
        double forwardY = (resultCnt / column + 1) * (squareWidth + spacing);
        label->setGeometry(forwardX, forwardY, textHeight, textHeight);
    }
}



// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {

    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {

    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {

    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {

    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {

    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {

    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {

    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
