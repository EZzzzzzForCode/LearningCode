#ifndef PRODUCTREGISTRAR_H
#define PRODUCTREGISTRAR_H

#include "IProductRegistrar.h"
#include "iostream"
#include "ProductFactory.h"

template <class ProductType_t, class ProductImpl_t>
class ProductRegistrar : public IProductRegistrar<ProductType_t>
{
public:
   // 构造函数，用于注册产品到工厂，只能显示调用
   explicit ProductRegistrar(std::string name)
   {
      // 通过工厂单例把产品注册到工厂
      ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
   }

   // 创建具体产品对象指针
   ProductType_t *CreateProduct()
   {
      return new ProductImpl_t();
   }
};

#endif // PRODUCTREGISTRAR_H
