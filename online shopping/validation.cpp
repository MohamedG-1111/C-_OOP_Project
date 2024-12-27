
#include "repo.cpp"
class vaild : public repoimp{
  public:
  int  vaildation(Products product){
  if(product.getQuantity() == 0){
  cout<<"Quantity should more than 0 \n";	
    return -1;	
  } 
  else
  return 1;	
  }
  
  int vaildShow(int pecode){
  if(pecode < 1000)
  {
cout<<"pecode is more than 2213085 \n";
return -1;
}
else 
return 1;	
  }	
};
