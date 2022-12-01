#include<bits/stdc++.h>
using namespace std;

struct Eater{ int id; };
struct FoodItem{ int id; };


class Restaurant{
    
private:
    map<int, vector<int>> log;
    map<int,int> foodItemFreq;
public: 

    void order(int eid, int fid){
        log[eid].push_back(fid);
        foodItemFreq[fid]++;
    }

    void display(){
        for(auto p : log){
            cout<<"Eater ID: "<<p.first<<endl;
            cout<<"Food Items ID: ";
            for(auto x : p.second){
                cout<<x<<", ";
            }
            cout<<endl;
        }
    }

    void top3Items(){
        
        int i1, a;
        int i2, b;
        int i3, c;
        a=b=c=INT_MIN;

        for(auto p : foodItemFreq){
            if(p.second > a){
                c=b;
                i3=i2;
                b=a;
                i2=i1;
                i1=p.first;
                a=p.second;
            }
            else if(p.second > b){
                c=b;
                i3=i2;
                i2=p.first;
                b=p.second;
            }
            else if(p.second > c){
                i3=p.first;
                c=p.second;
            }
        }
        cout<<"1st: "<<i1<<":"<<a<<endl;
        cout<<"2nd: "<<i2<<":"<<b<<endl;
        cout<<"3rd: "<<i3<<":"<<c<<endl;
    }
};

int main(){

    int n;
    cin>>n;
    int eid, fid;
    Restaurant R;
    for(int i=0;i<n;i++){
        cin>>eid>>fid;
        R.order(eid, fid);
    }
    R.top3Items();

}