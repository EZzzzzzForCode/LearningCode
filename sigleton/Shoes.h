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
        std::cout << "�����Ϳ���Ь���ҵĹ���ust do it" << std::endl;
    }
};

#endif // SHOES_H
