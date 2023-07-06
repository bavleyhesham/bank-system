#include <iostream>
#include <string>
using namespace std;
void intro()
{
    cout << "              **Hallo to our Bank system***\n";
    cout << "  1.customers             2.our service                     3.exit\n";
    cout << "Enter your choice\n";
}
class customer
{
public:
    string custname;
    int custphone, id, mo;

    void addcust()
    {
        cout << "Enter your name sir\n";
        cin >> custname;
        cout << "Enter your value of your account\n";
        cin >> mo;
        cout << "Enter your id\n";
        cin >> id;
        cout << "Enter your phone number\n";
        cin >> custphone;
        cout << "ok, it done successful\n";
    }
    void displaycust()
    {
        cout << custname << '\n';
        cout << custname << " id : " << id << '\n';
        cout << custname << " phone number : " << custphone << '\n';
        cout << custname << " account value : " << mo << '\n';
    }
    void deposit()
    {
        int val;
        cout << "Enter value of money" << endl;
        cin >> val;
        mo += +val;
        cout << "New balance is " << mo << endl;
    }
    void withdraw()
    {
        int var;
        cout << "Enter value of money" << endl;
        cin >> var;

        if (mo - var < 0)
            cout << "sorry , you dont have enough money to withdraw from it\n";
        else
        {
            mo -= var;
            cout << "New balance is " << mo << endl;
        }
    }
    void display()
    {
        cout << "Balance is " << mo << endl;
    }
};

int main()
{
    customer cust[100];
    int cont = 0;
    while (true)
    {
        intro();
        int x, y = 0;
        cin >> x;
        if (x == 3)
        {
            cout << "                 happy to see you.                  " << endl;
            return 0;
        }
        else if (x == 1)
        {
            while (true)
            {
                cout << "                **customers service***\n";
                cout << "  1.add customer          2.display customer                     3.search customer\n";
                cout << "  4.update customer information                5.back\n";
                int ch1;
                cin >> ch1;
                if (ch1 == 1)
                {
                    char check1 = 'y';
                    while (check1 == 'y')
                    {
                        cust[cont].addcust();
                        cont++;
                        cout << "Do you want add another customer(y/n) \n";
                        cin >> check1;
                    }
                }
                else if (ch1 == 2)
                {
                    for (int i = 0; i < cont; i++)
                    {
                        cust[i].displaycust();
                        cout << "          /******************/" << '\n';
                    }
                }
                else if (ch1 == 3)
                {
                    char check2 = 'y';
                    while (check2 == 'y')
                    {
                        cout << "Enter customer name you want to search\n";
                        string se;
                        cin >> se;
                        int ch2 = 0;
                        for (int i = 0; i < cont; i++)
                        {
                            if (se == cust[i].custname)
                            {

                                cust[i].displaycust();
                                ch2 = 1;
                                cout << "          /******************/" << '\n';
                            }
                        }
                        if (ch2 == 0)
                        {
                            cout << "sorry,but customer not in our system,please go back and join him/her.\n";
                        }
                        cout << "Do you want search another customer(y/n) \n";
                        cin >> check2;
                    }
                }

                else if (ch1 == 4)
                {
                    char check3 = 'y';
                    while (check3 == 'y')
                    {

                        cout << "Enter the name of the customer you want to upadte his/her info\n";
                        string s;
                        cin >> s;
                        int h = 0;
                        int ch;
                        int bev = 0;
                        for (int i = 0; i < cont; i++)
                        {
                            if (s == cust[i].custname)
                            {
                                cout << "customer name : " << cust[i].custname << endl;
                                cout << "customer id : " << cust[i].id << endl;
                                cout << "customer phone number : " << cust[i].custphone << endl;
                                cout << "customer account value : " << cust[i].mo << endl;
                                cout << "          /******************/" << '\n';
                                h = 1;
                                bev = i;
                            }
                        }
                        if (h == 0)
                        {
                            cout << " Not found that customer\n";
                        }
                        else
                        {
                            char check4 = 'y';
                            while (check4 == 'y')
                            {
                                cout << "what the information about customer you want to update?\n";
                                cout << "1.name\n";
                                cout << "2.id\n";
                                cout << "3.phone number\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    string ne;
                                    cout << "Enter the new name of the customer\n";
                                    cin >> ne;
                                    cust[bev].custname = ne;
                                }
                                else if (ch == 2)
                                {
                                    int ni;
                                    cout << "Enter the new id of the customer\n";
                                    cin >> ni;
                                    cust[bev].id = ni;
                                }
                                else if (ch == 3)
                                {
                                    int pi;
                                    cout << "Enter the new phone number of the customer\n"
                                         << endl;
                                    cin >> pi;
                                    cust[bev].custphone = pi;
                                }
                                cout << "Do you want to upadte another information?  (y/n) " << endl;

                                cin >> check4;
                            }
                        }

                        cout << "Do you want update another customer info(y/n) \n";
                        cin >> check3;
                    }
                }

                else if (ch1 == 5)
                    break;
            }
        }
        else if (x != 1 && x != 2 && x != 3)
        {
            cout << "please enter a correct value\n";
        }
        else
        {
            while (true)
            {
                cout << "          ***customer services***          " << endl;
                cout << "1-deposit        2-withdraw        3-display balance        4-back " << endl;
                cout << "Enter your choice" << endl;
                int num;
                cin >> num;
                if (num == 4)
                {
                    break;
                }
                if (num == 1)
                {
                    char ch1 = 'y';
                    while (ch1 == 'y')
                    {
                        int check7 = 0;
                        int id1;
                        string name1;
                        cout << "Enter your name " << endl;
                        cin >> name1;
                        cout << "Enter your id " << endl;
                        cin >> id1;
                        for (int i = 0; i < cont; i++)
                        {
                            if (cust[i].custname == name1 && cust[i].id == id1)
                            {
                                cust[i].deposit();
                                check7 = 1;
                            }
                        }
                        if (check7 == 0)
                            cout << "sorry ,you may input awrong value ,please check the name and id you input or if you are not in our system please join us\n";
                        cout << "Do you want to make deposit operation again  (y/n) " << endl;
                        cin >> ch1;
                        if (ch1 == 'n')
                        {
                            break;
                        }
                    }
                }
                if (num == 2)
                {
                    char ch2 = 'y';
                    while (ch2 == 'y')
                    {
                        int check8 = 0;
                        int id2;
                        string name2;
                        cout << "Enter your name " << endl;
                        cin >> name2;
                        cout << "Enter your id " << endl;
                        cin >> id2;
                        for (int i = 0; i < cont; i++)
                        {
                            if (cust[i].custname == name2 && cust[i].id == id2)
                            {
                                cust[i].withdraw();
                                check8 = 1;
                            }
                        }
                        if (check8 == 0)
                            cout << "sorry ,you may input awrong value ,please check the name and id you input or if you are not in our system please join us\n";
                        cout << "Do you want to make withdraw operation again (y/n) " << endl;
                        cin >> ch2;
                        if (ch2 == 'n')
                        {
                            break;
                        }
                    }
                }
                if (num == 3)
                {
                    char ch3 = 'y';
                    while (ch3 == 'y')
                    {
                        int id3;
                        string name3;
                        cout << "Enter your name " << endl;
                        cin >> name3;
                        cout << "Enter your id " << endl;
                        cin >> id3;
                        for (int i = 0; i < cont; i++)
                        {
                            if (cust[i].custname == name3 && cust[i].id == id3)
                            {
                                cust[i].display();
                            }
                        }
                        cout << "Do you want to desplay balance of another customer (y/n) " << endl;
                        cin >> ch3;
                        if (ch3 == 'n')
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
