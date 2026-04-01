#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string getpassword(int length){
    string password ="";
    string characters="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charsize = characters.size();
    srand(time(0));
    int randomindex;
    for(int i=0;i<length;i++){
        randomindex=rand()%charsize;
        password+=characters[randomindex];
    }

    return password; 
}

int main(){
int length;
cout<<"Enter the length of the password: ";
cin>>length;
string password;
cout<<"Generated password :"<<password;
} 

 
