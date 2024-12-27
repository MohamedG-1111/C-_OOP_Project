
#include "validation.cpp"
class service : public vaild{
public:
    virtual void add(Products product)=0;
    virtual void show(int pecode)=0;
    virtual void remove(int pecode)=0;
    virtual void edit(Products product)=0;
    virtual void showall()=0;
    virtual bool IsExisting(int pecode)=0;
    virtual void Search(int pecode=0 , string name="0");
};
class serviceImp : public service{
private:
    vaild va;
    repoimp repo;
public:
       void Search(int pecode=0 , string name="0"){
       if(repo.search(pecode,name) == 1){
       cout<<"Product is found \n";	
       }
       else{
    cout<<"Product is not found \n";
       }	
       }	
	
    bool IsExisting(int pecode){
    bool b=0;
    for(int i=0;i<product.size();i++){
    if(pecode == product[i].getID()){
    	b=1;
    	break;
    }	
    }	
    if(b) return 1;
    else
    return 0;
    }
   void add(Products product){
        int pecode=product.getID();
        if((va.vaildation(product) == 1 ) && (va.vaildShow(pecode)== 1)){
            repo.addproduct(product);
            cout<<"Added sucessfully \n";
        }
        else
        {
            cout<<"Not added \n";
        }
    }
    void remove(int pecode){
        if(va.vaildShow(pecode) == 1 ){
            repo.removeproduct(pecode);
            cout<<"removed sucessfully \n";
        }
        else
        {
            cout<<"Not removed \n";
        }
    }
  void show(int pecode){
        if(va.vaildShow(pecode) == 1){
            repo.show(pecode);
        }
        else{
            cout<<"Not found \n";
        }
    }

    void edit(Products product){
        int x=-1;
        x=product.getID();
        if (va.vaildShow(x) == 1){
            repo.editproduct(product);
        }
        else {
            cout<<"Not edit \n";
        }
    }

    void showall(){
        repo.showAll();
    }
};
