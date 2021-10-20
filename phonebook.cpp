#include <iostream>
#include <cstring>
using namespace std;

class directorynode
{
public:
    char number[50]; //Defining an array for Phone Number
    char email[40];  //Defining an array for Email Account
    char name[30];   //Defining an array for Name
    directorynode *prev, *next;

    directorynode(char n[], char r[], char g[])
    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(email, g);
        next = NULL;
        prev = NULL;
    }

    friend class directorylist;
};

class directorylist
{
    directorynode *head, *temp, *ptr;
    directorynode *ptr1, *ptr2, *dup;

public:
    directorynode *prevn;
    void insert();                    //Defining Insert Function
    void sort();                      //Defining Sort Function
    void deletecontact(char n[20]);   //Defining Delete Contact Function
    void deletesamenumber();          //Defining Delete Same Number Function
    void deletesamename();            //Defining Same Name Function
    void deletesameemail();           //Defining Same Email Function
    void searchbyname(char p[20]);    //Defining Search by Name Function
    void searchbynumber(char no[30]); //Defining Search by Number Function
    void searchbyemail(char g[20]);   //Defining Search by Email Function
    void accept();                    //Defining Accept Function
    void display();                   //Defining Display Function
    void update(char ch[10]);         //Defining Update Function

    directorylist()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
    }
};

void directorylist::accept() //Implementing the Accept Function
{
    char number[50];
    char email[40];
    char name[30];
    char ans;
    do
    {
        cout << "ENTER FIRST NAME: ";
        cin >> name;
        cout << "ENTER NUMBER: ";
        cin >> number;

        while (strlen(number) != 10)
        {
            cout << "ENTER VALID NUMBER: ";
            cin >> number;
        }

        cout << "ENTER EMAIL: ";
        cin >> email;
        temp = new directorynode(name, number, email);

        if (head == NULL)
        {
            head = temp;
        }

        else
        {
            ptr = head;
            while (ptr->next != NULL)

            {
                ptr = ptr->next;
            }

            ptr->next = temp;
            temp->prev = ptr;
        }

        cout << "\nDO YOU WANT TO CONTINUE? ";
        cin >> ans;
    }

    while (ans == 'y');
}

void directorylist::display() //Implementing the Display Function
{
    ptr = head;         //start the node
    while (ptr != NULL) //traverse till last
    {
        cout << "\n\nNAME::\t" << ptr->name;
        cout << "\nNUMBER::\t+91-" << ptr->number;
        cout << "\nEMAIL::\t" << ptr->email;
        ptr = ptr->next;
    }
}

void directorylist::insert() //Implementing the Insert Function
{
    accept();
}

void directorylist::sort() //Implementing the Sort Function
{
    directorynode *i, *j;
    int temp;
    char n[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
            if (temp > 0)
            {
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
            }
        }
    }
}

void directorylist::deletecontact(char s[20]) //Implementing the Delete Contact Function
{
    int c = 0;
    ptr = head;

    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)
        {
            c = 1;
            break;
        }

        else
        {
            c = 2;
        }

        ptr = ptr->next;
    }

    if (c == 1 && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }

    if (ptr == head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }

    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }

    if (c == 2)
    {
        cout << "YOUR ENTERED NAME IS NOT IN THE LIST...\n\n";
    }
}

void directorylist::deletesamename() //Implementing the Delete Same Name Function
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->name, ptr2->next->name) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }

            else
            {
                ptr2 = ptr2->next;
            }
        }

        ptr1 = ptr1->next;
    }
}

void directorylist::deletesameemail() //Implementing the Delete Same Email Function
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->email, ptr2->next->email) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }

            else
            {
                ptr2 = ptr2->next;
            }
        }

        ptr1 = ptr1->next;
    }
}

void directorylist::deletesamenumber() //Implementing the Delete Same Number Function
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->number, ptr2->number) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }

            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void directorylist::searchbyname(char na[10]) //Implementing the Search by Name Function
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "\n\nNAME FOUND" << endl;
            cout << "\nCONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nEMAIL::\t" << ptr->email;
        }

        ptr = ptr->next;
    }
}

void directorylist::searchbynumber(char num[20]) //Implementing the Search by Number Function
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "\n\nNUMBER FOUND\n"
                 << endl;
            cout << "\nCONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nEMAIL::\t" << ptr->email;
        }

        ptr = ptr->next;
    }
}

void directorylist::searchbyemail(char gm[20]) //Implementing the Search by Email Function
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(gm, ptr->email) == 0)
        {
            cout << "\n\nEMAIL FOUND\n"
                 << endl;
            cout << "\nCONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nEMAIL::\t" << ptr->email;
        }

        ptr = ptr->next;
    }
}

void directorylist::update(char n[20]) //Implementing the Update Function
{
    char ans;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {
            do
            {
                cout << "\nWHAT DO YOU WANT TO UPDATE?\n1. NAME\n2. PHONE NUMBER\n3. EMAIL\n";
                cin >> c;

                switch (c)
                {
                case 1:
                    cout << "ENTER NEW NAME: ";
                    cin >> ptr->name;
                    break;

                case 2:
                    cout << "ENTER NEW PHONE-NUMBER: ";
                    cin >> ptr->number;
                    while (strlen(ptr->number) != 10)
                    {
                        cout << "ENTER VALID NUMBER: ";
                        cin >> ptr->number;
                    }

                    break;

                case 3:
                    cout << "ENTER NEW EMAIL: ";
                    cin >> ptr->email;
                    break;
                }

                cout << "\nDO YOU WANT TO CONTINUE UPDATING?\n";
                cin >> ans;

            }

            while (ans == 'y');
        }

        ptr = ptr->next;
    }
}

int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char email[20];
    directorylist d1;

    char ans;
    int ch, a;
    cout << "\n\nWELCOME TO THE PHONEBOOK APPLICATION";
    cout << "\n\nWHAT IS YOUR NAME?\n";
    cin >> name;
    cout << "\n\nWELCOME " << name << ", ENTER THE DETAILS";
    cout << "\n\n\nLET'S CREATE YOUR PHONEBOOK\n\n";
    d1.accept();
    d1.sort();
    bool quit = false;

    while (!quit)
    {
        cout << "\n\n\nOPERATIONS\n";
        cout << "\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBER IN PHONEBOOK\n7) DELETE SAME EMAIL IN PHONEBOOK\n8) SEARCH\n9) EXIT\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            d1.display();
            break;

        case 2:
            d1.insert();
            d1.sort();
            break;

        case 3:
            cout << "\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;

        case 4:
            cout << "\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK \n";
            cin >> name;
            d1.deletecontact(name);
            break;

        case 5:
            d1.deletesamename();
            d1.display();
            break;

        case 6:
            d1.deletesamenumber();
            d1.display();
            break;

        case 7:
            d1.deletesameemail();
            d1.display();
            break;

        case 8:
            do
            {
                cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY EMAIL\n";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;

                case 2:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> number;
                    d1.searchbynumber(number);
                    break;

                case 3:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> email;
                    d1.searchbyemail(email);
                    break;
                default:
                    cout << "\nNO PROPER INPUT GIVEN.....\n";
                }
                cout << "\nDO YOU WANT TO CONTINUE SEARCHING?\n";
                cin >> ans;

            } while (ans == 'y');
            break;

        case 9:
            quit = true;
            break;
        default:
            cout << "\nNO PROPER INPUT GIVEN..\n";
        }
    }
}
