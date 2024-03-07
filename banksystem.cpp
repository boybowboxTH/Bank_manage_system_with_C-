#include<iostream>
#include<vector>
using namespace std;

class bank_acc{
private:
    string name;
    int acc_num;
    double balance;
public:
    bank_acc(string n,int acc,double bal){
        name = n;
        acc_num = acc;
        balance = bal;
    }
    string getname(){
        return name;
    }
    int getacc_num(){
        return acc_num;
    }
    double getbalance(){
        return balance;
    }
    void deposit(double amount){
        balance = balance +amount;
    }
    void withdraw(double amount){
    if(balance >= amount){
        balance = balance - amount; // Corrected typo: 'blance' to 'balance'
        cout<<"\t\t\t Withdraw Successfully...."<<endl;
    } else {
        cout<<"\t\t\t Not enough Balance...."<<endl;
    }
}
};
class bankmanagement{
private:
    vector<bank_acc> accounts;
public:
    void Addacc(string name,int acc_num,double balance){
        accounts.push_back(bank_acc(name,acc_num,balance));
    }
    void showallacc(){
        cout<<"\t\t\t All Account"<<endl;
        cout<<"\t\t\t____________________________"<<endl;
        for(int i =0; i<accounts.size();i++){
            cout<<"\t\t\t Name :"<<accounts[i].getname()<<" Account Number :"<<accounts[i].getacc_num()<<" Balance :"<<accounts[i].getbalance()<<endl;
        }
    }
    void searchacc(int acc){
        cout<<"\t\t\t_______________________________"<<endl;
        cout<<"\t\t\t Account Holder"<<endl;
        for(int i =0; i<accounts.size();i++){
            if(accounts[i].getacc_num()==acc){
                cout<<"\t\t\t Name :"<<accounts[i].getname()<<" Account Number :"<<accounts[i].getacc_num()<<" Balance :"<<accounts[i].getbalance()<<endl;
            }
        }
    }
   bank_acc* findAccount(int accountnum){
    for(int i = 0; i<accounts.size();i++){
        if(accounts[i].getacc_num()==accountnum){
            return &accounts[i];
        }
    }
}
};

int main(){
    bankmanagement bank;
    int choice;
    char op;
    do{
    system("cls");
    cout<<"\t\t\t______________________________"<<endl;
    cout<<"\t\t\t::Bank Management System::"<<endl;
    cout<<"\t\t\t______________________________"<<endl;
    cout<<"\t\t\t\tMain Menu"<<endl;
    cout<<"\t\t\t______________________________"<<endl;
    cout<<"\t\t\t 1.Create New Account"<<endl;
    cout<<"\t\t\t 2.Show All Account"<<endl;
    cout<<"\t\t\t 3.Search Account"<<endl;
    cout<<"\t\t\t 4.Deposit Money"<<endl;
    cout<<"\t\t\t 5.Withdraw Money"<<endl;
    cout<<"\t\t\t 6.Exit"<<endl;
    cout<<"\t\t\t_______________________________"<<endl;
    cout<<"\t\t\t Enter Your Choice    :";
    cin>>choice;
    switch(choice){
        case 1:{
            string name;
            int acc_num;
            double balance;
            cout<<"\t\t\t Enter Name           :";
            cin>>name;
            cout<<"\t\t\t Enter Account Number :";
            cin>>acc_num;
            cout<<"\t\t\t Enter Balance        :";
            cin>>balance;
            bank.Addacc(name,acc_num,balance);
            cout<<"\t\t\t Create Account Successfuly..."<<endl;
            break;
        }
        case 2:{
            bank.showallacc();
            break;
        }
        case 3:{
            int accnum;
            cout<<"\t\t\t_______________________________"<<endl;
            cout<<"\t\t\t Enter Account Number :";
            cin>>accnum;
            bank.searchacc(accnum);
            break;
        }
        case 4:{
            int accountNum;
            double amount;
            cout<<"\t\t\t_______________________________"<<endl;
            cout<<"\t\t\t Enter Account Number to Deposit Money :";
            cin>>accountNum;
            bank_acc* account = bank.findAccount(accountNum);
            if(account !=NULL){
                cout<<"\t\t\t Enter Amount to Deposit :";
                cin>>amount;
                account->deposit(amount);
                cout<<"\t\t\t "<<amount<<" Deposit Successfully...."<<endl;
            }else{
                cout<<"\t\t\t Account Not Found...."<<endl;
            }
            break;
        }
        case 5:{
            int accountNum;
            double amount;
            cout<<"\t\t\t_______________________________"<<endl;
            cout<<"\t\t\t Enter Account Number to withdraw Money :";
            cin>>accountNum;
            bank_acc* account = bank.findAccount(accountNum);
            if(account !=NULL){
                cout<<"\t\t\t Enter Amount to withdraw :";
                cin>>amount;
                account->withdraw(amount);
            }else{
                cout<<"\t\t\t Account Not Found...."<<endl;
            }
            break;
        }
        case 6:{
            cout<<"\t\t\t_______________________________"<<endl;
            cout<<"\t\t\t Thank you for used this software!!"<<endl;
            exit(1);
            break;
        }
    }

    cout<<"\t\t\t Do you want to Countinue or Exit [Yes/No]?";
    cin>>op;
}while(op=='y' ||op=='Y');
}



