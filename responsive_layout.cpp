//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>


// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r ) { // our layout should fit inside r



    QLayout::setGeometry(r);
    int resultCnt = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            int spacing = 0.01 * r.width();


            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            // mobile phone vertical
            else if(r.width() < 375){
                if(label->text() == kMenu){
                    label->setGeometry(spacing, 0, 0.1 * r.width(), 40);
                }else if(label->text() == kHomeLink){
                    label->setGeometry(0.12 * r.width(), 0, 0.15 * r.width(), 40);
                }else if(label->text() == kSQuery){
                    label->setGeometry(0.28 * r.width(), 0, 0.45 * r.width(), 40);
                }else if(label->text() == kSButton){
                    label->setGeometry(0.74 * r.width(), 0, 0.25 * r.width(), 40);
                }else if(label->text() == kAdvert){
                    label->setGeometry(spacing, 44, 0.42 * r.width(), 20);
                }else if(label->text() == kSOptions){
                    label->setGeometry(0.44 * r.width(), 44, 0.55 * r.width(), 20);
                }else if(label->text() == kSResultImage){
                    resultCnt++;
                    if (resultCnt % 2 == 1){
                        label->setGeometry(spacing,  70 + (resultCnt - 1) / 2 * 130, 0.48 * r.width(), 100);
                    }else{
                        label->setGeometry(0.51 * r.width(),  70 + (resultCnt - 2) / 2 * 130, 0.48 * r.width(), 100);
                    }
                }else if(label->text() == kSResultText){
                    if(resultCnt % 2 == 1){
                        label->setGeometry(spacing, 174 + (resultCnt - 1) / 2 * 130, 0.48 * r.width(), 20);
                    }else{
                        label->setGeometry(0.51 * r.width(), 174 + (resultCnt - 2) / 2 * 130, 0.48 * r.width(), 20);
                    }
                }
            }
        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
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
