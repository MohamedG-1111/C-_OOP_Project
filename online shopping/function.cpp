#include"controller .cpp"
void AddProduct() {
    controlIMP control;
    Products product;

    cout << "Enter information of product \n";
    cout << "Enter pcode   : ";
    int x;
    cin >> x;
    product.setID(x);

    cout << "Enter name     : ";
    string s;
    cin >> s;
    product.setName(s);

    cout << "Enter category : ";
    string g;
    cin >> g;
    product.setCategory(g);

    cout << "Enter price    : ";
    int c;
    cin >> c;
    product.setPrice(c);

    cout << "Enter quantity : ";
    int q;
    cin >> q;
    product.setQuantity(q);

    control.Add(product);
    cout<<"\n\n               ------------------------------                  \n\n";
}

void ShowProducts() {
    controlIMP control;
    cout << "Show all products \n ";
    control.ShowAll();
      cout<<"\n\n               ------------------------------                  \n\n";
}
void UserSearch(){
	    controlIMP control;
cout<<"To Enter pecode press 1 , To Enter name press 2 \n";
int n;
cin>>n;	
if(n == 1){
int pecode; 
cin>>pecode;
control.SearchProduct(pecode,"0");	
}
else if(n==2){
string name; cin>>name;
control.SearchProduct(0,name);		
}
else{
cout<<"Error \n";
}
	
}

void RemoveProduct() {
    controlIMP control;
    Products product;
    cout << "Enter pcode : ";
    int x;
    cin >> x;
    control.Remove(x);
      cout<<"\n\n               ------------------------------                  \n\n";
}

void EditProduct() {
    controlIMP control;
    Products product;
    cout << "Enter pcode : ";
    int x;
    cin >> x;
    if(control.IsExisting(x) == 1){
      cout << "Enter new information \n";
        product.setID(x);

        cout << "Enter name     : ";
        string s;
        cin >> s;
        product.setName(s);

        cout << "Enter category : ";
        string g;
        cin >> g;
        product.setCategory(g);

        cout << "Enter price    : ";
        int c;
        cin >> c;
        product.setPrice(c);

        cout << "Enter quantity : ";
        int q;
        cin >> q;
        product.setQuantity(q);

        control.Edit(product);	
    }
    else
    cout<<"Not found \n";
      cout<<"\n\n               ------------------------------                  \n\n";
      
    }


void ShowPecode() {
    cout << "Enter Pcode \n";
    int p;
    cin >> p;
    controlIMP control;
    control.Show(p);
      cout<<"\n\n               ------------------------------                  \n\n";
}

void menu() {
    cout<<"\n\n                   Menu                    \n";
    cout << "              Press 1 Add product            \n";
    cout << "              Press 2 Remove product         \n";
    cout << "              Press 3 Show all products      \n";
    cout << "              Press 4 Edit product           \n";
    cout << "              Press 5 Show product           \n";
    cout << "              Press 6 Exit                   \n";

    while(true) {
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                AddProduct();
                break;
            case 2:
                RemoveProduct();
                break;
            case 3:
                ShowProducts();
                break;
            case 4:
                EditProduct();
                break;
            case 5:
                ShowPecode();
                break;
            case 6:
              return;
            default:
                cout << "Choose the correct option\n";
                break;
        }
    }
}

void Checksystem() {
    int ua = 0;

    cout << "\t\t\t\t\t\t Online Shopping \t\t\t\t\t\t\t\t \n\n\n";
    cout << "\t\t User, press 1\t\t\t" << "\t Admin, press 2 \t\t"<<"\t  Exit ,press 3 \n\n";
    cin >> ua;

    if (ua == 1) {
        controllusers controluser;
        int check = 0;

        cout << "\t 1 - Sign in \n\n";
        cout << "\t 2 - Login   \n\n";
        cout << "\t 3 - Forget password \n\n";
        cin >> check;

        switch(check) {
            case 1:
                controluser.SignUser();
                break;
            case 2:
                controluser.LoginUser();
                break;
            case 3:
                controluser.ForgetPasswordUser();
                break;
        }
    }
    else if (ua == 2) {
        controllusers controluser;
        int check = 0;

        cout << "\t 1 - Login   \n\n";
        cout << "\t 2 - Forget password \n\n";
        cin >> check;

        switch(check) {
            case 1:
                controluser.LoginAdmin();
                break;
            case 2:
                controluser.ForgetPasswordAdmin();
                break;
        }
    }
}

int programAdmin() {
    Checksystem();
   if(access == 1) {
        menu();
    }
}
