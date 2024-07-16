// The used-predefined libraries and classes
#include <iostream>
#include <string>
#include <windows.h>//for system fun for coloring the text and sleep fun 
#include <fstream>
#include <cstdlib>//for exist function
#include <map>

//fast input and output using #define statmenet
#define fastIO  ios_base::sync_with_stdio(false) , cin.tie(NULL),cout.tie(NULL);

//colors 
#define red    "\x1b[31m"
#define green  "\x1b[32m"
#define yellow  "\x1b[33m"
#define blue   "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan   "\x1b[36m"
#define bright "\x1b[1m"
#define reset   "\x1b[0m"//reset to the default colour - white -

using namespace std;

bool validusername(ifstream& login, string username) {
    login.open("login.txt");
    if (!login.is_open()) {
        cerr << red "SORRY ! THE CLIENTS FILE YOU ARE TRYING TO OPEN FOR SEARCHING IS NOT FOUND ";
        exit(1);//as return statment
    }
    string name;
    while (!login.eof()) {
        login >> name;
        if (name == username) {
            login.close();
            return true;//found
        }
    }
    login.close();  
    return false;//not found
}

bool validpassword(ifstream& pass, string username, string password) {

    pass.open("login.txt");
    if (!pass.is_open()) {
        cerr << red "SORRY ! THE CLIENTS FILE YOU ARE TRYING TO OPEN FOR SEARCHING IS NOT FOUND ";
        exit(1);
    }

    string name, passw;
    while (!pass.eof()) {
        pass >> name;
        if (name == username) {
            pass >> passw;
            if (passw == password) {
                pass.close();
                return true;
            }
        }
    }
    pass.close();
    return false;
}

void split(string x, map <int,string>& m) {
    string temp;
    int flag = 1;
    for (int c = 1; c < x.size(); c++) { //we start from c=1 because after reading the username
                            // the corser will move by ine bit ( one char ) so hw will be on the 
                            // '' char thats why we make it on the 1st char of password directly 
        if (x[c] != ' ') {  // but also we can start from c-0 because we have condition to check 
                             // if the current char is ' ' or not 
            temp += x[c];
        }
        else {
            cout << m[flag] << " : " << temp << endl;
            flag++;

            temp.clear();
        }
    }
    cout << m[flag] << " : " << temp << endl;
    //because the compiler when he reaches the end of string the following char will be 
    // not ' ' but he will end so null thats why we add it down 
    return;
}

void display(string username) {
    ifstream show("info.txt");
    if (!show.is_open()) {
        cerr << red "SORRY ! THE INFORMATION FILE YOU ARE TRYING TO OPEN IS NOT FOUND ";
        exit(1);
    }

    string header;
    std::getline(show, header); //just to make the start line of reading from the 2nd (directly to the names)
    map <int,string>m;
    m[0] = "USERNAME";
    m[1] = "PASSWORD";
    m[2] = "AGE";
    m[3] = "MOBILE NUMBER";

    m[4] = "CITY";
    m[5] = "SPECIALEST";
    m[6] = "SALARY";

    string x;
    while (!show.eof()) {
        show >> x;
        if (x == username) {
            cout << m[0] << " : " << x << endl;
            std::getline(show, x);
            split(x, m);
            return;
        }
       }
    //impossiple to reach this statement because infact the compiler reach this fun if the 
   //username and paaword are correct so the user certainly exist in the system !!
    
}

bool allowedpassword(string password) {
    if (password.size() >= 8) {
        int digit = 0, capital = 0, smal = 0, sympol = 0;
        for (int c = 0; c < password.size(); c++) {
            if ((password[c] >= '0') && (password[c] <= '9'))
                digit++;
            else if ((password[c] >= 'A') && (password[c] <= 'Z'))
                capital++;
            else if ((password[c] >= 'a') && (password[c] <= 'z'))
                smal++;
            else sympol++;
        }
        if (digit) {
            if (capital) {
                if (smal) {
                    if (sympol) {
                        return true;
                    }
                    else {
                        cerr << red"SORRY THE PASSWORD YOU HAVE ENTERED DOESN'T CONTAIN SYMPOLS LIKE @,$.... !!\n";
                        return false;
                    }
                }
                else {
                    cerr << red"SORRY THE PASSWORD YOU HAVE ENTERED DOESN'T CONTAIN SMALL LETTERS LIKE a,d..... !!\nINVALID EDIT !\n";
                    return false;
                }
            }
            else {
                cerr << red"SORRY THE PASSWORD YOU HAVE ENTERED DOESN'T CONTAIN CAPITAL LETTERS  LIKE A,B..... !!\nINVALID EDIT !\n";
                return false;
            }
        }
        else {
            cerr << red"SORRY THE PASSWORD YOU HAVE ENTERED DOESN'T CONTAIN DIGITS LIKE 1,2.... !!\nINVALID EDIT !\n";
            return false;
        }

    }
    else {
        cerr << red"SORRY THE PASSWORD YOU HAVE ENTERED IS TOO SHORT !!\nINVALID EDIT !\n";
        return false;
    }
}

string getpass(ifstream& login, string name) {
    login.open("login.txt");
    if (!login.is_open()) {
        cerr << red "SORRY THE FILE YOU ARE TRYING TO OPEN IS NOT FOUND ";
        exit(1);
    }
    string user, pass;
    while (!login.eof()) {
        login >> user;
        if (user == name) {
            login >> pass;
            return pass;
             }
    }

}