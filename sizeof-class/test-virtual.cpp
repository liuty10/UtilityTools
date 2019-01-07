#include<iostream>

class CBase
{
  private:
    int a;
    static int b;
    char *p;
  public: 
    CBase(void);
    virtual ~CBase(void);
    void funcA(){
      std::cout << "this is in CBase" << std::endl;
    };
};

int main(){
  std::cout << "sizeof(CBase)=" << sizeof(CBase)<<std::endl;
  return 0;
}
