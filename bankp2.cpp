#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <random>
#include <ctime>

using namespace std;

class bankaccount
{
    static int counterforcvv2;
    static int counterforshaba;
    public:
    string accounttype;
    string cardnumber;
    string shabanumber;
    string accountnumber;
    string cvv2;
    long double balance;
    string expirationdate;
    string fourdigitpass;
    string secondstaticpass;
    string seconddynamicpass;
    void cvv2Maker()
    {   
        cvv2="100"+counterforcvv2;
        counterforcvv2++;
    }
    void shabaMaker()
    {
        shabanumber = "IR1000000000000000000000" + counterforshaba;
        counterforshaba++;
    }

};
int bankaccount::counterforcvv2=1;
int bankaccount::counterforshaba=1;
class user
{
    public:
    string firstname;
    string lastname;
    string idnumber;
    int age;
    string username;
    string password;
    bankaccount accounts[5];


};

set<int> generatedNumbers;

int generateUniqueRandomNumber() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(100000, 999999);
    int randomNumber;
    do 
    {
        randomNumber = dist(gen);
    } 
    while (generatedNumbers.find(randomNumber) != generatedNumbers.end());
    generatedNumbers.insert(randomNumber);
    return randomNumber;
}


void sign_up()
{
    
}


int main()
{
    cout<<"jsdus";
}