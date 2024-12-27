
#include<string>
using namespace std;
class users{
private:
string _username;
string _password;
string _phone;
int _age;
public:
users(){}
users(string username,string password,string phone=0,int age=0){
	_username=username;
	_password=password;
	_phone=phone;
	_age=age;
}
void setphone(string phone){
_phone=phone;	
}
void setusername(string username){
_username=username;	
}
void setpassword(string password)
{
	_password=password;
}
void setAge(int age)
{
	_age=age;
	}
string getusername(){
return _username;	
}
string getphone(){
return _phone;	
}
string getpassword(){
return _password;	
}
int age(){
return _age;	
}		
};
  
  ///////////   Product  
  
class Products{
  private:
  string _name;
  int _pcode;
  string _category;
  double _price;
  int  _quantity;
  public:	
  Products(){}
  Products(int pcode ,string name,string category,  int quantity,double price){
         _pcode=pcode;
         _name=name;
         _category=category;
         _quantity=quantity;
         _price=price;
  }
  void setID(int id){
  	_pcode=id;
  }
  void setName(string name){
  	_name=name;
  }
  void setCategory(string kind){
  	_category=kind;
  }	
  void setPrice(double price){
  	_price=price;
  }
  void setQuantity( int quantity){
  	_quantity=quantity;
  }
  
  string getName(){
  	return _name;
  }
  string getCategory(){
  	return _category;
  }	
   double getPrice(){
                                return _price;
  }
   int getQuantity(){
                               return _quantity;
  }
  int getID(){
  	return _pcode;
  }
  
};





