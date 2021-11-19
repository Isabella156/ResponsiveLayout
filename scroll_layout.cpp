
#include "scroll_layout.h"
#include "responsive_label.h"
#include <iostream>

void ScrollLayout::setGeometry(const QRect &r ){
    QLayout::setGeometry(r);
    for(int i = 0; i < list_.size(); i ++){
        int resultCnt = 0;
        int squareWidth = r.width();
        int imageHeight = 0.9 * squareWidth;
        int textHeight = 0.1 * squareWidth;
        int spacing = 20;
        int imageY = (r.width() + spacing) * resultCnt;
        int textY = (r.width() + spacing) * resultCnt + 0.9 * imageHeight;
        QLayoutItem *o = list_.at(i);
        try{
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            if(label == NULL){
                std::cout<< "warning, unknown widget class in layout" << std::endl;
            }
            if(label->text() == kSResultImage){
                label->setGeometry(r.x(), imageY, squareWidth, imageHeight); 
                resultCnt++;
            }else if(label->text() == kSResultText){
                label->setGeometry(r.x(), textY, squareWidth, textHeight);
            }
        }
        catch(std::bad_cast){
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}

// following methods provide a trivial list-based implementation of the QLayout class
int ScrollLayout::count() const {

    return list_.size();
}

QLayoutItem *ScrollLayout::itemAt(int idx) const {

    return list_.value(idx);
}

QLayoutItem *ScrollLayout::takeAt(int idx) {

    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ScrollLayout::addItem(QLayoutItem *item) {

    list_.append(item);
}

QSize ScrollLayout::sizeHint() const {

    return minimumSize();
}

QSize ScrollLayout::minimumSize() const {

    return QSize(320,320);
}

ScrollLayout::~ScrollLayout() {

    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
