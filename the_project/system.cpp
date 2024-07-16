

//USER-DEFINED HEADER FILE 
#include "functions.h"


int main()
{

    fastIO;
    system("color 6");
  
    cout << "\n\t\t\t\t*******************************************************\n\n\n";
    cout << "\t\t\t\t\tWELLCOME TO LOGIN & REGISTERATION SYSTEM\n\n";
    cout << cyan"\t\t\t\t\t\t\t LOGIN\n\n";
    cout << "\t\t\t\t\t\t   SIGN UP (REGISTER)\n\n";
    cout << "\t\t\t\t\t\t    FORGET PASSWORD ?\n\n";
    cout << "\t\t\t\t\t\t\t EXIST\n\n\n";
    cout << yellow"\t\t\t\t*******************************************************\n\n\n";

    cout << reset "CHOOSE YOUR OPTION , PLEASE : ";
    string option;
    getline(cin, option);
  
     
    if (option == "login") { 
        
        cout << "*******************************************************\n\n";
        cout << "USERNAME : ";
        int trials = 0;
        string username;      
        ifstream login;
        do {
            
            cin >> username;
            cout << magenta "LOADING ......\n";
            Sleep(4000);//waiting fun take 1 parameter in milsec.  
           
        
            if (validusername(login, username)) {
                cout <<  reset "VALID USERNAME!\n\n";
               break;
                     
            } 

            if(trials==0)
              cerr << red "THE ENTERED USERNAME NOT CORRECT ,YOU HAVE OTHER CHANCE ! PLEASE ENTER YOUR VALID USERNAME ! : ";
            
            trials++;
         
            } 
          while (trials != 2);


        if (trials == 2)
        {
            cerr << red "SORRY YOUR ENTERED USERNAME NOT FOUND & YOU HAVE EXCEEDED THE ALLOWED TRIALS ,THANK YOU FOR USING OUR SYSTEM !";
            exit(1);
            
        }

        //for sure the compiler when reaches this line that
        // means the username found so now we will check his password

        string password;
        cout << "PASSWORD : ";
        trials = 0;
        ifstream pass;
        do {

            cin >> password;
            cout << magenta "LOADING ......\n";
            Sleep(4000);


            if (validpassword(pass, username,password)) {
                cout << reset "VALID PASSWORD!\n\n";
                 break;
            }

            if (trials == 0)
                cerr << red "THE ENTERED PASSWORD NOT CORRECT ,YOU HAVE OTHER CHANCE ! PLEASE ENTER YOUR VALID PASSWORD ! : ";

            trials++;
            
        } 
        while (trials != 2);

        if (trials == 2)
        {
            cerr << red "SORRY YOUR ENTERED PASSWORD NOT FOUND & YOU HAVE EXCEEDED THE ALLOWED TRIALS ,THANK YOU FOR USING OUR SYSTEM !";
             exit(1);
        }

        //for sure the compiler when reaches this line that
     // means the password found so now we will offer him 2 options
        cout << "*******************************************************\n\n";
        cout << "WELLCOME "<< username << " ENJOY OUR SRVICES !\n\n";
        cout << "1-DIPLAY MY PERSONAL INFORMATION\n2-EXIST MY PAGE\n\n";
        cout << "CHOOSE YOUR OPTION :";
        int service;
        cin >> service;

        if (service == 1) {
            display(username);
            exit(1);
        }
       
        cout << "THANK YOU , GOOD BYE "<<username << " !";
        exit(1);

    }


    if (option == "forget password") {
        ifstream login;
        string username;
        cout << "PLEASE WRITE YOUR USERNAME : ";

        cin >> username;
        if (validusername(login, username)) {
            login.close();
            cout << "THIS IS YOUR PASSWORD : " << getpass(login, username);
            exit(1);

        }
        //invalid name 
        cerr << red"SORRY THE REQUESTED NAME IS NOT FOUND IN OUR SYSTEM " << username << " !";

        exit(1);
    }

    if (option == "sign up") {
        fstream print("login.txt", ios::app);
        fstream info("info.txt", ios::app);

        print << endl;
        info << endl;
        cout << "*******************************************************\n\n";
     
        map <int,string>m;
        m[0] = "USERNAME";
        m[1] = "PASSWORD";
        m[2] = "AGE";
        m[3] = "MOBILE NUMBER";
    
        m[4] = "CITY";
        m[5] = "SPECIALEST";
        m[6] = "SALARY";
        string temp;
        for (int c = 0; c < 7; c++)
        {

            if (c == 1) {
                cout << "CHOOSE VALID " << m[c] << " : ";//password 

                cin >> temp;
                int num = 1;
                while (num != 3) {
                    if (allowedpassword(temp)) {
                        print << temp << " ";
                        info << temp << " ";
                        break;
                    }
                    else  cout <<red  "SORRY , THE PASSWORD IS WRONG , PLEASE TRY AGAIN ! \n";
                    
                    num++;
                    cout << reset "PLEASE ENTER VALID PASSWORD :";
                    cin >> temp;
                }
                if (num == 3) {
                    cerr << red "SORRY THE PASSWORD IS NOT CORRECT AND YOU HAVE EXCEEDED THE ALLOWED TRIALS \n";
                    exit(1);
                }
                continue;//to avoid print the pass, again on the login file
            } 
          
            cout << "CHOOSE VALID " << m[c] << " : ";
            cin >> temp;
            if (c == 0)
            print << temp << " ";
            info << temp << " ";

        }
        
        cout << "THANK YOU , YOUR RECORD RECENTLY HAS BEEN ADDED TO OUR SYSTEM , ENJOY OUR OFFERED SERVIVES !!\n" ;
        return 0;
    }

};