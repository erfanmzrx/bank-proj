#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <random>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;


long long int RandomMaker( long long int min,long long int max) 
{
    long double Random = (rand() * 1.0) /RAND_MAX;
    Random = ((Random * (max - min)) + min) ;
    return (long long int)Random;
}

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
    void cdnumMaker()
    {
        long long tmp=RandomMaker(100000000000 , 999999999999);
        cardnumber = "6104" + to_string(tmp) ;
    }
    void accnumMaker()
    {
        accountnumber = to_string(RandomMaker(100000000 , 999999999));
    }
    void passMaker()
    {
        seconddynamicpass= RandomMaker(100000 , 999999);
    }
    static string generateExpiryDate() 
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int year = 1900 + ltm->tm_year + 3;
        int month = 1 + ltm->tm_mon;
        return to_string(month) + "/" + to_string(year);
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
    linklist<bankaccount> accounts;





};
user choosenUser;
bankaccount choosenBankacc;

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
void ctbankacc()
{
    if(choosenUser.accounts.size>=5)
    {
        cout << "you have 5 bank accounts. you cant create more!" << endl;
        return;
    }
    bankaccount newbankacc;
    cout << "Select your bank account type" << endl;
    cout << "1. Sepordeh" << endl;
    cout << "2. Jari" << endl;
    cout << "3. Gharzol hasaneh" << endl;
    int choice=0;
    while (choice<1 || choice>3)
    {
        cin >> choice;
    }    
    switch (choice)
    {
    case 1:
        newbankacc.accounttype="Sepordeh";
        break;
    case 2:
        newbankacc.accounttype="Jari";
        break;
    case 3:
        newbankacc.accounttype="Gharzol hasaneh";
        break;
    }
    newbankacc.balance=100000;
    cout << "Create 4 digit password" << endl;
    cin >> newbankacc.fourdigitpass;
    while (newbankacc.fourdigitpass.length()!=4)
    {
        cout << "Invalid password ! try again" << endl;
        cin >> newbankacc.fourdigitpass; 
    }    
    // newbankacc.cdnumMaker();
    newbankacc.accnumMaker();
    newbankacc.shabaMaker();
    newbankacc.cvv2Maker();
    newbankacc.expirationdate=newbankacc.generateExpiryDate();
    cout << "Would you like to set secondry static password ?" << endl << endl << "1. Yes" << endl << "2. no";
    int tmp=0;
    while (tmp<1 || tmp>2)
    {
        cin >> tmp;
    }
    if(tmp==1)
    {
        cout << "Enter a 6 digit password" << endl;
        cin >> newbankacc.secondstaticpass;
        while (newbankacc.secondstaticpass.length()!=6)
        {
            cout << "Invalid password ! try again" << endl;
            cin >> newbankacc.secondstaticpass; 
        }
        cout << "Password set successfully" << endl;
        
    }
    if (tmp==2)
    {
        newbankacc.secondstaticpass=="\0";
    }  
    cout << "here is your credit card information" << endl << endl;
    cout << "card number : " << newbankacc.cardnumber << endl ;
    cout << "account number : " << newbankacc.accountnumber <<endl;
    cout << "shaba number : " << newbankacc.shabanumber << endl;
    cout << "cvv2 : " << newbankacc.cvv2 << endl;
    cout << "expiration date : " << newbankacc.expirationdate << endl << endl;
    choosenUser.accounts.push_front(newbankacc);
    return;
}   
void changepass()
{

    cout << "which password would you like to change?" << endl;
    cout << "1. 4 digit password " << endl << "2. second static password " << endl;
    int choice=0;
    cin>> choice;
    while(choice < 1 || choice >2)
    {
        cin >> choice;
    }
    if(choice==1)
    {
        cout << "Enter a new 4 digit password" << endl;
        cin >> choosenBankacc.fourdigitpass;
        while (choosenBankacc.fourdigitpass.length()!=4)
        {
            cout << "Invalid password ! try again" << endl;
            cin >> choosenBankacc.fourdigitpass; 
        }
        cout << "4 digit password changed successfully" << endl;
        return ;           
    }
    if (choice == 2)
    {
        cout << "Enter a new second static password (must be 6 digits) : " << endl;
        cin >> choosenBankacc.secondstaticpass ;
        while (choosenBankacc.secondstaticpass.length()!=6)
        {
            cout << "Invalid password ! try again" << endl;
            cin >> choosenBankacc.secondstaticpass; 
        }
        cout << "second static password changed successfully" << endl;
        return;
    }
}
void viewbalance()
{
    cout << " Your account balance is : " << endl << choosenBankacc.balance << endl ;
    return;
}
void transfer()
{
    cout << "Enter your card number : " << endl;
    string choosencardnumber="\0";
    cin >> choosencardnumber;
    while (choosencardnumber!=choosenBankacc.cardnumber)
    {
        cout << "invalid card number! try again" << endl;
        cin >> choosencardnumber;
    }
    cout << "Enter reciver card number : " << endl ;
    string reccardnum="\0";
    cin >> reccardnum;
    node<user> * t = users.h ;
    bool x=false;
    bankaccount reciver;
    while(t!=nullptr)
    {
        node<bankaccount> *tmp=(*t).d.accounts.h;
        while(tmp!=nullptr)
        {
            if((*tmp).d.cardnumber == reccardnum )
            {
                cout << (*t).d.firstname << " " << (*t).d.lastname << endl;
                reciver=(*tmp).d;
                x=true;
                break;
            }
            tmp=tmp->n;
        }
        if(x==true)
        {
            break;
        }
        t=t->n;
    }
    if(x=false)
    {
        cout << "invalid card number for reciver !" << endl ;
        return;
    }
    cout << "how much do you want to send?" << endl;
    long double amount;
    cin >> amount;
    while (amount > choosenBankacc.balance || amount >3000000)
    {
        cout << "card balance is not enough or the amount is more than 3000000! try again." << endl;
        cin >> amount;
    }
    if(amount <=100000)
    {
        if(choosenBankacc.secondstaticpass.length()==6)
        {
            cout << "Enter your second static password" << endl;
            string pass;
            cin >> pass;
            if(pass!=choosenBankacc.secondstaticpass)
            {
                cout << "wrong password! returning back to panel" << endl;
                return;
            }
            choosenBankacc.balance-=amount;
            reciver.balance+=99.99 * amount;
            cout << "The transaction has been successfully completed." << endl;
            return;
        }
    }
    choosenBankacc.passMaker();
    cout << "Your second dynamic password is : " << choosenBankacc.seconddynamicpass << endl;
    cout << "Enter the password : " << endl;
    string pass;
    cin >> pass;
    while(pass != choosenBankacc.seconddynamicpass)
    {
        cout << "wrong password! try again." << endl;
        cin >> pass; 
    }
    choosenBankacc.balance-=amount;
    reciver.balance+=99.99 * amount;
    cout << "The transaction has been successfully completed." << endl;
    return;   
}
void menu()
{
    int choice=0;
    while(choice!=5)
    {
        choice=0;
        cout << "choose one of the options below :" << endl << endl;
        cout << "1. Create bank account" << endl;
        cout << "2. Change 4 digit password or second static password" << endl;
        cout << "3. Check your balance" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. log out" << endl;
        while (choice<1 || choice>5)
        {
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            ctbankacc();
            break;
        case 2:
            changepass();
            break;   
        case 3:
            viewbalance();
            break;
        case 4:
            transfer();
            break;                
        case 5:
            return;
        }
    }
}
void choosebankacc()
{
    cout << "Choose one of your bank accounts : " <<endl << endl;
    node<bankaccount> * tmp = choosenUser.accounts.h ;
    int i=1;
	while ( tmp != 0 ) 
    {
		cout << i << ". "<<(*tmp).d.accountnumber << endl ;
        i++;
		tmp = tmp -> n;
	}
    int choice=0;
    cin >> choice;
    while(choice <1 || choice > i)
    {
        cin >> choice;   
    }
    node<bankaccount> * temp = choosenUser.accounts.h;
    for( int j=0 ; j<choice ; j++)
    {
        if(j==choice-1)
        {
            choosenBankacc=(*temp).d;
            break;
        }
        temp = temp->n;
    }
    return;
}
int main()
{
    srand(getpid());
    int choose=0;
    while(choose!=3)
    {
        cout<<"Welcome!" << endl;
        cout << "Please login or sign up " << endl << "1. login" << endl << "2. sign up" << endl << "3. Exit" << endl ;
        choose=0;
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
                menu();
            }
        }
        if(choose == 2)
        {
            sign_up();
            menu();
        }
    }
}