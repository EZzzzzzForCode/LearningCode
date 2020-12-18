#ifndef SHOES_H
#define SHOES_H

#include "iostream"

class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};


class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：ust do it" << std::endl;
    }
};

#endif // SHOES_H
