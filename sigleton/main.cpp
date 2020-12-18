#include <QCoreApplication>
#include "ProductRegistrar.h"
#include "Shoes.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


        ProductRegistrar<Shoes, NiKeShoes> nikeShoes("nike");
       // 从工厂获取产品种类为Shoes，名称为nike的产品对象
       Shoes *pNiKeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");
       // 显示产品的广告语
       pNiKeShoes->Show();
       // 释放资源
       if (pNiKeShoes)
       {
          delete pNiKeShoes;
       }

    return a.exec();
}
