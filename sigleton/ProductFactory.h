#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "stdlib.h"
#include "iostream"
#include "map"
#include "IProductRegistrar.h"

using namespace std;

template <class ProductType_t>
class ProductFactory
{
public:
   // 获取工厂单例，工厂的实例是唯一的
   static ProductFactory<ProductType_t> &Instance()
   {
      static ProductFactory<ProductType_t> instance;
      return instance;
   }

   // 产品注册
   void RegisterProduct(IProductRegistrar<ProductType_t> *registrar, std::string name)
   {
      m_ProductRegistry[name] = registrar;
   }

   // 根据名字name，获取对应具体的产品对象
   ProductType_t *GetProduct(std::string name)
   {
      // 从map找到已经注册过的产品，并返回产品对象
      if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
      {
         return m_ProductRegistry[name]->CreateProduct();
      }

      // 未注册的产品，则报错未找到
      std::cout << "No product found for " << name << std::endl;

      return NULL;
   }

private:
   // 禁止外部构造和虚构
   ProductFactory() {}
   ~ProductFactory() {}

   // 禁止外部拷贝和赋值操作
   ProductFactory(const ProductFactory &);
   const ProductFactory &operator=(const ProductFactory &);

   // 保存注册过的产品，key:产品名字 , value:产品类型
   std::map<std::string, IProductRegistrar<ProductType_t> *> m_ProductRegistry;
};

#endif // PRODUCTFACTORY_H
