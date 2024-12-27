#include<fstream>
#include"Modules.cpp"
#include<vector>
#include<iostream>
using namespace std;
int access =0 ;
class repo{
protected:
    static vector<Products>product;
public:
    virtual void addproduct(Products Product)=0;
    virtual void removeproduct(int pecode)=0;
    virtual void editproduct(Products productt)=0;
    virtual void show(int pecode)=0;
    virtual void showAll()=0;
    virtual int search(int pecode=0,string name="0");
   
};
vector<Products>repo::product;
class repoimp:public repo{
public:
   int search(int pecode=0,string name="0"){
   	bool b=0;
     for(int i=0;i<product.size();i++){
      if(pecode == product[i].getID() || name == product[i]. getName())
      b=1;	
     }
     if(b) return 1;
     else
     return -1;	
   }
    void addproduct(Products Product){
        product.push_back(Product);
    }

    void removeproduct(int pecode){
        int x=-1;
        for(int i=0;i<product.size();i++){
            if(pecode == product[i].getID()){
                x=i;
                break;
            }
        }
        if(x!=-1){
            product.erase(product.begin()+x);
            x=-1;
        }
        else
            cout<<"Not found \n";
    }

    void editproduct(Products productt) {
        int b = -1;
        for (int i = 0; i < product.size(); i++) {
            if (productt.getID() == product[i].getID()) {
                b = i;
                break;
            }
        }
        if (b == -1) {
        cout<<"Not found \n";
        return;	
        }
        else{
            product[b] =  productt;
        }
            
    }
    void show(int pecode){
    	int c=-1;
    for(int i = 0; i < repoimp::product.size(); i++){
    if(pecode == product[i].getID()){
    c=i;
    break;	
    }	
    }
    cout<<"pecode : "<<product[c].getID()<<" "<<"Name  : "<<product[c]. getName()<<" ";
    cout<<"Category : "<<product[c].getCategory()<<" "<<"price  : "<<product[c].getPrice();
    cout<<" "<<"Quantity : "<<product[c].getQuantity()<<"\n";
    } 
    void showAll(){
    	cout<<"    All products \n";
    for(int i = 0; i < repoimp::product.size(); i++){
      cout<<"pecode : "<<product[i].getID()<<" "<<"Name  : "<<product[i]. getName()<<" ";
            cout<<"Category : "<<product[i].getCategory()<<" "<<"price  : "<<product[i].getPrice();
            cout<<" "<<"Quantity : "<<product[i].getQuantity()<<"\n";	
    }	
    }
    
    };
   class systemcheak{
public:	

virtual void sign_user(users user)=0;
virtual void login_user(string username,string password)=0;
virtual void login_admin(string username,string password)=0;
virtual void forgetpassword_user(string phone)=0;
virtual void forgetpassword_admin(string phone)=0;	
};
class systemcheakImp:public systemcheak{
protected :
ifstream read;
ofstream write;	
public: 
void  sign_user(users user){
write.open("users.txt" ,ios::app);
write<<user.getusername()<<" "<<user.getpassword()<<" "<<user.getphone()<<" "<<user.age()<<"\n";
write.close();
}
void login_user(string username,string password){
read.open("users.txt");	
string use,pass;
bool b=0;
while(read>>use>>pass){
if(use == username && pass == password ) {
cout<<"Login successsful \n\n";
	b=1;	
break;	
}	
}
if(b==0)
cout<<"forget usename or password \n";	
read.close();	
}

void login_admin(string username,string password){	
if(username == "mog111@gmail.com" && password=="mohamedwwe"){
cout<<"Login is successfull \n";
access=1;	
}	
else{
cout<<"login is not suceessful \n";	
}		
}

void forgetpassword_user(string phone){
read.open("users.txt");	
string use,pass,ph;
bool b=0;
while(read>>use>>pass>>ph){
if(ph == phone){
	b=1;
cout<<"Your account is found \n";
cout<<"Username : "<<use<<" \npasssword : "<<pass<<" \nphone : "<<ph<<"\n";
break;	
}	
}
if(b==0)
cout<<"Your account is not found \n";	
}

void forgetpassword_admin(string ID){
read.open("admin.txt");	
string use,pass,ph;
bool b=0;
while(read>>use>>pass>>ph){
if(ID == ph){
	b=1;
	access=1;
cout<<"Your account is found \n";
cout<<"Username : "<<use<<" \npasssword : "<<pass<<" \nphone : "<<ph<<"\n";
break;	
}	
}
if(b==0)
cout<<"Your account is not found \n";	
}	
};

