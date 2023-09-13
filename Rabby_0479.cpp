#include <bits/stdc++.h>
using namespace std;
class Vehicle {
  private:
    vector<string> vehicle_name[100];
    vector<pair<int,string>> vehicle_detail[100];//abstraction
  public:
    virtual void setVehicle(string s,int n){//override
        vehicle_name[n].push_back(s);
    }
    virtual void setVehicle(int  num,string st,int n){
        vehicle_detail[n].push_back({num,st});
    }
    virtual void getlist(int n){
        for(int i=0;i<vehicle_detail[n].size();i++){
            cout<<vehicle_name[n][i]<<" "<<vehicle_detail[n][i].first<<" "<<vehicle_detail[n][i].second<<endl;
        }
    }
};
Vehicle obj;
class Company: public Vehicle{//company class has inherited vehicle class
  private:
    string s;
  public:
    Company(string s){
        cout<<"Welcome to "<<s<<" group of industries"<<endl;
    }
    void setter(string s){//encapsulation
       this->s=s;
    }
    string getter(){//encapsulation
        return s;
    }
    void setVehicle(string s,int n){//polymorphysm
        obj.setVehicle(s,n);
    }
    void setVehicle(int num,string st,int n){
        obj.setVehicle(num,st,n);
    }
    void view(){
        cout<<s<<endl;
    }
    void getlist(int n){
        obj.getlist(n);
    }
};
vector<Company> company_list;
void add_company(){
    cout<<"Enter the name of your company"<<endl;
    string s,st;
    cin>>s;
    Company var(s);
    var.setter(s);
    var.getter();
    cout<<"Do you want to add vehicle to your company?\n"<<endl;
    cout<<"press y for Yes and n for No"<<endl;
    char c;
    cin>>c;
    if (c=='y'){
        int n,num;
        cout<<"Enter number of vehicle ";
        cin>>n;
        while(n--){
            cout<<"Enter the name of vehicle :"<<endl;
            cin>>s;
            var.setVehicle(s,company_list.size());
            cout<<"Enter the registration number of vehicle :"<<endl;
            cin>>num;
            cout<<"Enter the name of the driver:"<<endl;
            cin>>s;
            var.setVehicle(num,s,company_list.size());
            cout<<"Vehicle added successfully"<<endl;
        }
    }
    company_list.push_back(var);

}
void view(bool f){
    for(auto i:company_list){
        cout<<"1.";
        i.view();
        cout<<endl;
    }
    if (f)return ;
    int n;
    cout<<"enter then number of the company to view vehicles available in that company\n";
    cout<<"enter 0 to quit\n";
    cin>>n;
    if(n){
        company_list[n-1].getlist(company_list.size());
    }
}
void delete_company(){
    view(1);
    cout<<"enter then number of the company to delete that company\n";
    int n;
    cin>>n;
    n--;
    company_list.erase(company_list.begin()+n);
    cout<<"Company deleted successfully press q to go back"<<endl;
    getchar();
}
int main()
{
    while(1){
        cout<<"press 1 to add new company"<<endl;
        cout<<"press 2 to view all available company"<<endl;
        cout<<"press 3 to delete a company"<<endl;
        cout<<"press 4 to exit"<<endl;
        int n;
        cin>>n;
        if (n==1)add_company();
        else if (n==2)view(0);
        else if (n==3)delete_company();
        else break;
    }
    return 0;
}
