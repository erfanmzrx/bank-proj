#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <random>
#include <ctime>
#include <string>


using namespace std;

template <typename T>
class node {
public :
	T d ;
	node * n ;
};

template <typename T>
class linklist
{
    public:
	node<T> * h ;
	int size ;
    public:
    linklist()
    {
        h=nullptr;
        size=0;
    }
    ~linklist()
    {
        node<T> * tmp = this->h ;

        while ( tmp != 0 )
        {
            node<T>* tmp2 = tmp->n ;
            delete tmp ;
            tmp = tmp2;
        }
        this->h = nullptr ;
        this->size = 0 ;
    }
    void push_front(T num)
    {
        node<T> * tmp = new node<T> ;
	    tmp -> d = num ;
	    tmp -> n = this->h ;
	    this->h = tmp ;
	    this->size ++ ;
    }
    void print ()
    {
        cout << "printing linklist of size " << size << endl ;
	    node<T> * tmp = this->h ;
	    while ( tmp != 0 )
        {
		    cout << (*tmp).d << endl ;
		    tmp = tmp -> n;
	    }
    }
};

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
user choosenUser;

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

linklist<user> users;


void sign_up()
{
    user newuser;
    cout << "Enter your name:" << endl;
    cin >> newuser.firstname;
    cout << "Enter your last name:" << endl;
    cin >> newuser.lastname;
    cout << "Enter your id number:" << endl;
    cin >> newuser.idnumber;
    cout << "Enter your age:" << endl;
    cin >> newuser.age;
    cout << "Enter your username:" << endl;
    cin >> newuser.username;
    cout << "Enter your password:" << endl;
    cin >> newuser.password;
    users.push_front(newuser);
    cout << "signed up successfully" << endl;
    choosenUser=newuser;
}
bool log_in ()
{
    string tmpusername , tmppassword;
    cout << "Enter your username :" << endl;
    cin >> tmpusername;
    cout << "Enter your password :" << endl;
    cin >> tmppassword;
    node<user> * t = users.h ;
    while(t!=nullptr)
    {
        if(t->d.username==tmpusername)
        {
            if(t->d.password==tmppassword)
            {
                choosenUser=t->d;
                cout << "logged in successfully ";
                return true ;
            }
        }
        t=t->n;
    }
    cout << "Username or password is wrong" <<endl;
    cout << "Returning to menu" << endl ;
    return false ; 
}

void menu()
{

}


int main()
{

    for(;;)
    {
        cout<<"Welcome!" << endl;
        cout << "Please login or sign up " << endl << "1. login" << endl << "2. sign up" << endl << "3. Exit" << endl ;
        int choose=0;
        while(choose!=1 && choose!=2 && choose!=3)
        {
            cin >> choose;
        }
        if(choose==3)
        {
            return 0;
        }
        if(choose == 1)
        {
            bool tmp=log_in();
            if(tmp==false)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(choose == 2)
        {
            sign_up();
            break;
        }
    }



}