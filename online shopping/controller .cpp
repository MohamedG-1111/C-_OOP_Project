#include "services.cpp"
class control : public serviceImp{
public:
    virtual void Add(Products product)=0;
    virtual void Remove(int pecode)=0;
    virtual void Edit(Products product)=0;
    virtual void Show(int pecode)=0;
    virtual void ShowAll()=0;
    virtual void SearchProduct(int pecode,string name);
};
class controlIMP : public control{
private :
    serviceImp service;
public:
   void SearchProduct(int pecode,string name){
   service.Search(pecode,name);	
   }	
    void Add(Products product){
        service.add(product);
    }

    void Remove(int pcode){
        service.remove(pcode);
    }

    void Edit(Products product){
        service.edit(product);
    }

    void Show(int pecode){
        service.show(pecode);
    }

    void ShowAll(){
        service.showall();
    }
    void existing(int x){
    service.IsExisting(x);	
    }
};
class controllusers:public systemcheakImp{
private:
systemcheakImp systemcheakimp;
public:	
void SignUser(){
string username,password,phone; int age;	
cout<<"\t\t\t Enter your information \t\t\t \n\n";
cout<<"Username : ";cin>>username;
cout<<"password : "; cin>>password;
cout<<"phone    : ";cin>>phone;
cout<<"age      : "; cin>>age;
users user(username,password,phone,age);
systemcheakimp.sign_user(user);	
}

void LoginUser(){
string username,password;	
cout<<"\t\t\t Enter your information \t\t\t \n\n";
cout<<"Username : ";cin>>username;
cout<<"password : "; cin>>password;
systemcheakimp.login_user(username,password);	
}


void LoginAdmin(){
string username,password;	
cout<<"\t\t\t Enter your information \t\t\t \n\n";
cout<<"Username : ";cin>>username;
cout<<"password : "; cin>>password;
systemcheakimp.login_admin(username,password);	
}


void ForgetPasswordUser(){
string ph;
cout<<"Enter your Phone \n";
cin>>ph;
systemcheakimp.forgetpassword_user(ph);	
}


void ForgetPasswordAdmin(){
string ph;
cout<<"Enter your Pecode \n";
cin>>ph;
systemcheakimp.forgetpassword_admin(ph);	
}	
};

