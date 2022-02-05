// Hashing->With the help of hasing we can insert,delete and search in constant time

//Hashing with unordered map
// 1.All the element are distinct
// 2.The order is not maintained

#include<unordered_set> 
#include<iostream>
using namespace std;


int main(){
    //Created a set
    unordered_set<int> s;

    //Inserting values in the set
    s.insert(5);
    s.insert(10);

    // //s.find() is used to check wether the element is pressent or not
    // if(s.find(50)==s.end()){
    //     cout<<"not founds";
    // }
    // else{
    //     cout<<"found";
    // }

    // //It is used to clear the complete set
    // s.clear(); 

    // / Used to iterate through the set
    // for(auto it =s.begin(); it !=s.end(); it++){
    //     cout<<*it<<" ";
    // }/
    
    // //used to find the size
    // cout<<s.size();

    // //Using the count to check wether a element is present or not
    // if(s.count(5)){
    //     cout<<"Present";
    // }
    // else{
    //     cout<<"Not present";
    // }

    //Used to remove a element from the set
    s.erase(5);

    //Used to remove element in a given range
    s.erase(s.begin(),s.end());
    

    return 0;
}