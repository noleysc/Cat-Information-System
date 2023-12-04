#include <bits//stdc++.h>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//important functions/declarations for GUI, storing information, and logic
bool isValidString(string s){
    auto isletter=[](char ch){return isalpha(static_cast<unsigned char>(ch));};
    return all_of(s.begin(), s.end(), isletter);
}
bool isValid(string s){
    auto isvalid=[](char i){return isprint(static_cast<unsigned char>(i));};
    return all_of(s.begin(), s.end(), isvalid);
}
bool isValidNum(string s){
    auto isvalid=[](char i){return isdigit(static_cast<unsigned char>(i));};
    return all_of(s.begin(), s.end(), isvalid);
}
bool isValidMail(string s){
    auto isvalid=[](char i){return isgraph(static_cast<unsigned char>(i));};
    return all_of(s.begin(), s.end(), isvalid);
}
void printline(){
    string line;
    line = "-   -  -  - - - - - - - - - - - - - - - - - - - - - - - -  -  -   -";
    cout<<"\n"<<"\t"<<line<<"\t"<<"\n";
}
void clearComplaints(){
    ofstream comp;
    comp.open("custcomments.txt", ios::out | ios::trunc);
    comp<<"";
    comp.close();
}
void getComplaints(){
ifstream comp;
comp.open("custcomments.txt",ios_base::app);
if (comp.is_open()){
    cout<<"\n"<<comp.rdbuf();
    comp.close();
    return;
}
else{
    cout<<"There are no comments right now.\n";
    comp.close();
    return;
}
}
void getRecords(){
    ifstream recs;
    recs.open("thecatsmeowrecords.txt", ios_base::app);
    printline();
    if(recs.is_open()){
        cout<<recs.rdbuf();
    }
    printline();
}
    void printgui() {
        ifstream gui("menu.txt");
        printline();
        if (gui.is_open()) {
            cout << gui.rdbuf();
        }
        printline();
    }
    //class to organize the cats' information
    class cat {
    public:
        cat(const string& name, const string & age, const string& cl, const string& cc, const string& breed, const string& perst, const string& sex, const string& email)
            {
            ofstream records;
            records.open("thecatsmeowrecords.txt", ios_base::app);
                records<<name<<"\t|";
                records<<age<<",  ";
                records<<cl<<",  ";
                records<<cc<<",  ";
                records<<breed<<",  ";
                records<<perst<<",  ";
                records<<sex<<",  ";
                records<<email<<"\n";
                records.close();
                fstream pubrecords;
                pubrecords.open("thecatsmeowpubrecords.txt", ios_base::app);
                pubrecords<<"\n"<<name<<"\t|";
                pubrecords<<age<<",  ";
                pubrecords<<cl<<",  ";
                pubrecords<<cc<<",  ";
                pubrecords<<breed<<",  ";
                pubrecords<<perst<<",  ";
                pubrecords<<sex;
                pubrecords.close();
                fstream input;
                input.open(name, ios_base::app);
                input<<name<<"\n\n";
                input<<age<<"\n";
                input<<cl<<"\n";
                input<<cc<<"\n";
                input<<breed<<"\n";
                input<<perst<<"\n";
                input<<sex<<"\n";
                cout<<"Would you like to add any notes to "<<name<<"'s profile?\n";
                string inp;
                getline(cin >> ws, inp);
                input<<"NOTES:\n";
                input<<"\n"<<inp;
            };
};
//function to add a message to
void leaveMessage(){
    fstream message;
    message.open("custcomments.txt", ios_base::app);
    string ccom;
    string *cc;
    cc=&ccom;
    getline(cin >> ws, *cc);
    message<<ccom<<"\n";
    message.close();
}
//function to initialize staff function switch/case loop with correct password
void getPass(){
    int choice;
    int lo;
    lo=1;
    string pass;
    pass="staffpasswordexample";
    string upass;
    cout<<"Please enter the staff password.\n";
    cin>>upass;
    if(upass==pass){
        do{
            printline();
            cout<<"1. View Complaints...\n2. View Records...\n3. Clear Complaints...\n4. Exit...";
            printline();
            cin>>choice;
            switch(choice) {
                default:
                    cout<<"Please re-enter an input provided.\n";
                    printline();
                    break;
                    case 1:
                    printline();
                    getComplaints();
                    printline();
                    break;
                    case 2:
                    getRecords();
                    break;
                    case 3:
                        clearComplaints();
                        break;
                        case 4:
                            lo=2;
                            break;
            }
    }while(lo==1);
    if(lo==2){
        return;
    }}
}
//function to get the description of a cat for storage and display purposes
void getCat() {
    int qc;
    qc = -2;
    int ccl1, ccc1, sex, agec;
    string user, cname, ccl, ccc, breed, perst, pers, cs, email, cage;
    cout << "These initial questions are to build the cat a profile in our database.\n";
    printline();
    do {
        cout << "What is the email of the previous owner?\nThis is for the cat's future owner and us to collect some information if necessary.\n";
        cin >> email;
        if (isValidMail(email)) {
            qc = -1;
        }
    } while (qc == -2);
    do{
        cout<<"Is it more appropriate to supply the cat's age in weeks or years?\n1.Weeks\n2.Years\n";
        cin>>agec;
        switch(agec){
            default:
                cout<<"Please enter a valid integer.\n";
                break;
            case 1:{
                cout<<"What is the cat's age?";
                getline(cin >> ws, cage);
                if(isValidNum(cage)){
                    string w;
                    w=" week(s)";
                    cage=cage+w;
                    qc=-0;
                break;}
                else{
                    cout<<"Please enter a valid integer.\n";
                    break;
                }
            }
            case 2:{
                cout<<"What is the cat's age?";
                getline(cin>>ws,cage);
                if(isValidNum(cage)){
                    string y;
                    y=" year(s)";
                    cage=cage+y;
                    qc=0;
                break;
                }
                else{
                    cout<<"Please enter a valid integer.\n";
                }
            }
        }}while(qc==-1);
    do {
        cout << "What is the cat's name?\n";
        cin >> cname;
        if (isValidString(cname)) {
            qc = 1;
        } else {
            cout << "Please re-enter your input with only alphabetical characters.\n";
        }
    } while (qc == 0);
    do {
        cout << "What is the cat's coat length?\n1.Long\n2.Short\n3.N/A\n";
        cin >> ccl;
        if (isValidNum(ccl)&&((stoi(ccl)<=3&&stoi(ccl)>=1))) {
            if (stoi(ccl) == 1) {
                ccl = "Long";
                qc = 2;
            } else {
                if (stoi(ccl) == 2) {
                    ccl = "Short";
                    qc = 2;
                } else {
                    if (stoi(ccl) == 3) {
                        ccl = "N/A";
                        ccc = "N/A";
                        qc = 3;
                    } else {
                        cout << "Please re-enter your input with only numerical characters.\n";
                    }
                }
            }
        }
    } while (qc == 1);
    if(qc!=3){
        string *coa;
        coa = &ccc;
        do {
            cout<< "What is the cat's coat color?\n1.Black\n2.White\n3.Cream\n4.Orange\n5.Blue-Gray\n6.Gray\n7.Brown\n8.Other\n";
            cin >> ccc1;
            switch (ccc1) {
                default:
                    cout<<"Please enter an integer option given.";
                    break;
                case 1: {
                    *coa = "Black";
                    qc = 3;
                    break;
                }
                case 2: {
                    *coa = "White";
                    qc = 3;
                    break;
                }
                case 3: {
                    *coa = "Cream";
                    qc = 3;
                    break;
                }
                case 4: {
                    *coa = "Orange";
                    qc = 3;
                    break;
                }
                case 5: {
                    *coa = "Blue-Gray";
                    qc = 3;
                    break;
                }
                case 6: {
                    *coa = "Gray";
                    qc = 3;
                    break;
                }
                case 7: {
                    *coa = "Brown";
                    qc = 3;
                    break;
                }
                case 8: {
                    cout << "What is the cat's coat color?\nIf multicolored insert colors with dashes in-between.\n";
                    getline(cin >> ws, *coa);
                    if (isValid(*coa)) {
                        qc = 3;
                        break;
                    } else {
                        cout << "Please re-enter your input as displayed.\n";
                    }
                }
            }
        } while (qc == 2);}
    do {
        cout << "What is the cat's breed?\n";
        getline(cin >> ws, breed);
        if (isValid(breed)) {
            qc = 4;
        }
    } while (qc == 3);
    do {
        cout << "What is the cat's sex?\n1.M\n2.F\n";
        cin >> sex;
        if (sex == 1) {
            cs = "Male";
            qc = 5;
        } else {
            if (sex == 2) {
                cs = "Female";
                qc = 5;
            } else {
                cout << "Please re-enter your input with only options displayed.\n";
            }
        }
    } while (qc == 4);
    do {
        cout << "What is the cat's personality type?\n1.Shy\n2.Timid\n3.Active\n4.Dominant\n";
        cin >> pers;
        string *pt;
        pt = &pers;
        if (isValidNum(*pt)) {
            if (stoi(*pt) == 1) {
                *pt = "Shy";
                qc = 6;
            } else {
                if (stoi(pers) == 2) {
                    *pt = "Timid";
                    qc = 6;
                } else {
                    if (stoi(pers) == 3) {
                        *pt = "Active";
                        qc = 6;
                    } else {
                        if (stoi(pers) == 4) {
                            *pt = "Dominant";
                            qc = 6;
                        } else {
                            cout << "Please re-enter your input with only numerical characters.\n";
                        }
                    }
                }
            }
        }
    } while (qc == 5);
    cat cat(cname, cage, ccl, ccc, breed, pers, cs, email);
    printline();
}
//function to see a cat's information in a kinder format (with registration notes!)
void inspectCat(const string &name){
    ifstream cat;
    cat.open(name, ios_base::app);
    if(cat.is_open()){
        printline();
        cout<<"\n"<<cat.rdbuf();
        printline();
        return;
}
    else{
        cout<<"There is no cat with the name you provided.";
}}
//function to verify the user knows the password to input the cats
void getPassCat(){
    string pass;
    pass="1012310132welovecats";
    string upass;
    cout<<"Please enter the staff password.\n";
    printline();
    cin>>upass;
    if(upass==pass){
        printline();
        getCat();
    }
}
//function to display all cats stored
void showCats(){
    ifstream pubrecords;
    int cou=1;
    pubrecords.open("thecatsmeowpubrecords.txt");
        string line;
        int dwl;
        dwl=1;
        vector<string> base;
        base={"Name", "Age", "Coat Length", "Coat Color", "Breed", "Personality", "Sex"};
        vector<string> cats;
        while(getline(pubrecords, line))
        {
            cats.push_back(line);
        }
        pubrecords.close();
        do{
        cout<<"Total cats:"<<cats.size()<<"\n";
        for(size_t i{ }; i<base.size(); i++){
            cout<<"\t";
            cout<<" "<<base[i];
        }
        printline();
        int w;
        w=1;
        while(w==1) {
            int *pt;
            pt=&cou;
                for (size_t i{}; i < cats.size(); i++) {
                    cout << i + 1 << "\t" << cats[i];
                    printline();
                }
            cout << "Would you like to view any of their pages?\n1.Yes\n2.No\n";
                cin>>(w);
                w=w+2;
        }
        while(w==3){
            string name;
            cout << "What is the cat's name?\n";
            cin >> name;
            inspectCat(name);
            cout<<"Would you like to view another cat?\n1.Yes\n2.No\n";
            cin>>(w);
            if(w==2){
                return;
            }
        }
        if(w==4){
            return;
        }
        }while(dwl==1);
        }
//main
    int main() {
        fstream records;
        records.open("thecatsmeowrecords.txt");
        fstream gui;
        ofstream line;
        line.open("line.txt");
        gui.open("menu.txt");
        fstream ornament;
        ornament.open("line.txt");
        int loo;
        int lo=1;
        do{
            cout << "\t\t\t\t The Cat's Meow\n\t    the compatibility app to find your cat the purrfect friend.";
            printgui();
            cin>>loo;
            switch(loo){
                default:
                    cout<<"Please re-enter your input with only options displayed.\n";
                    break;
                    case 1:
                        printline();
                        getPassCat();
                        break;
                    case 2:
                        showCats();
                        break;
                        case 3:
                            cout<<"\nPlease leave your message:\n";
                            printline();
                            leaveMessage();
                            printline();
                            break;
                            case 4:
                                getPass();
                                break;
                                case 5:
                                    lo=2;
        }}while(lo==1);
return 0;}