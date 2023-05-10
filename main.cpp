#include <iostream>
#include<fstream>
#include <sstream>
#include<string.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*__________________ Functions are declared here_____________________*/

// Login Methods
void login();
void regi();
void forgot();

//Menu Methods
void login_menu();
void main_menu();
void patient_menu();
void staff_menu();
void donner_menu();
void inventory_menu();

//Patient Methods
void add_patient();
void show_patient();
void search_patient();
void update_patient();
void delete_patient();

//Staff Methods
void add_staff();
void show_staff();
void search_staff();
void update_staff();
void delete_staff();


//Blood Bank Methods
void add_donner();
void show_donner();
void search_donner();
void update_donner();
void delete_donner();


//Inventory Methods
void add_inventory();
void show_inventory();
void search_inventory();
void update_inventory();
void delete_inventory();


/*Struct*/
struct Patient{


string pId,pname,fname,mname,paddress,ph;


};

struct Staff{

string sId,sname,saddress,sph,spost,semail;

};

struct Donner{

string dId,dname,daddress,dph,demail,blood_group;

};

struct Invent{

string iId,iname;

};


/* Login Function created here with file system it will check if the inputed Login are valid

   or not. It will check from admin.txt file.

 */
void login(){

int cont;
string userId, password, id, pass;
cout<<"\t\t\tPlease Enter The Username and Password:"<<endl;
cout<<"\t\t\t USERNAME: ";
cin>>userId;
cout<<"\t\t\t PASSWORD: ";
cin>>password;
ifstream input("admin.txt");
while(input>>id>>pass)
{

    if(id==userId &&pass==password)
    {

        cont = 1;
        system("cls");
    }
}
 input.close();

 if(cont==1)
 {

     cout<<"ADMIN: "<<userId;
     main_menu();
 }

 else
 {

     cout<<"LOGIN ERROR";
     login_menu();
  }
}

/* Registration Function will add user name and password for login to admin system and save the file in
admin.txt
 */

void regi()
{

 string ruserId, rpassword,rid,rpass;
 system("cls");
 cout<<"\t\t\t Enter the username: ";
 cin>>ruserId;
 cout<<"\t\t\t Enter the password: ";
 cin>>rpassword;

 ofstream f1("admin.txt",ios::app);
 f1<<ruserId<<' '<<rpassword<<endl;
 system("cls");
 cout<<"\n\t\t\t Registration is SuccessFull! \n";
 login_menu();

}


void forgot()
{
  int option;
  system("cls");
  cout<<"\t\t\t Forgot Password ? \n";
  cout<<"Press 1 to search your id by username "<<endl;
  cout<<"Press 2 to back to main menu "<<endl;

  cout<<"\n\t\t\t Enter your choice: ";
  cin>>option;

   switch (option)
	{
		case 1:
		    {


			int cont=0;
			string suserId,sId,spass;
			cout<<"\n\t\t\t Enter The username which you rememeber: ";
            cin>>suserId;

            ifstream f2("admin.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    cont=1;

                }
            }

            f2.close();

            if(cont==1)
            {

                cout<<"\n\t\t\t Your account is found!";
                cout<<"\n\t\t\t Your password is : "<<spass;
                login_menu();
            }
            else
            {
                cout<<"\n\t\t\t Sorry !!! No account is found!";
                login_menu();
            }

			break;
	}

		case 2:
		    {
			login_menu();
		    }
	    default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			break;
          }
}


/* Menu Start from here

void login_menu()
void main_menu()
void patient_menu()
void staff_menu()
void bloodbank_menu()
void inventory_menu()


*/
void login_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  WELCOME TO LOGIN PAGE                   \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. LOGIN                            |"<<endl;
   cout<<"\t\t\t|                  2. REGISTER                         |"<<endl;
   cout<<"\t\t\t|                  3. FORGOT PASSWORD                  |"<<endl;
   cout<<"\t\t\t|                  4. EXIT                             |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			login();
			getch();
			break;
		case 2:
			system("cls");
			regi();
			getch();
			break;
		case 3:
			system("cls");
			forgot();
			getch();
			break;
		case 4:
			exit(1);
		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}


void main_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGMENT SYSTEM               \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. PATIENT DETAILS                    |"<<endl;
   cout<<"\t\t\t|                  2. STAFF DETAILS                      |"<<endl;
   cout<<"\t\t\t|                  3. BLOOD BANK                         |"<<endl;
   cout<<"\t\t\t|                  4. INVENTORY DETAILS                  |"<<endl;
   cout<<"\t\t\t|                  5. EXIT                               |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			patient_menu();
			getch();
			break;
		case 2:
			system("cls");
			staff_menu();
			getch();
			break;
		case 3:
			system("cls");
			donner_menu();
			getch();
			break;
		case 4:
		    system("cls");
			inventory_menu();
			getch();
			break;
        case 5:
			exit(1);
		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}



void patient_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGMENT SYSTEM               \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. ADD PATIENT                        |"<<endl;
   cout<<"\t\t\t|                  2. SHOW PATIENT                       |"<<endl;
   cout<<"\t\t\t|                  3. SEARCH PATIENT                     |"<<endl;
   cout<<"\t\t\t|                  4. UPDATTE PATIENT                    |"<<endl;
   cout<<"\t\t\t|                  5. DELETE PATIENT                     |"<<endl;
   cout<<"\t\t\t|                  6. GO BACK                            |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			add_patient();
			getch();
			break;
		case 2:
			system("cls");
			show_patient();
			getch();
			break;
		case 3:
			system("cls");
             search_patient();
			getch();
			break;
		case 4:
           system("cls");
            update_patient();
			getch();
			break;

        case 5:
            system("cls");
             delete_patient();
			getch();
			break;
        case 6:
            system("cls");
			main_menu();

		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}

void staff_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGMENT SYSTEM               \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. ADD STAFF                          |"<<endl;
   cout<<"\t\t\t|                  2. SHOW STAFF                         |"<<endl;
   cout<<"\t\t\t|                  3. SEARCH STAFF                       |"<<endl;
   cout<<"\t\t\t|                  3. UPDATE STAFF                       |"<<endl;
   cout<<"\t\t\t|                  4. DELETE STAFF                       |"<<endl;
   cout<<"\t\t\t|                  5. GO BACK                            |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			add_staff();
			getch();
			break;
		case 2:
			system("cls");
			show_staff();
			getch();
			break;
		case 3:
			system("cls");
			search_staff();
			getch();
			break;
		case 4:
		    system("cls");
			update_staff();
			getch();
			break;

        case 5:
             system("cls");
			delete_staff();
			getch();
            break;
        case 6:
            system("cls");
			main_menu();
		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}


void donner_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGMENT SYSTEM               \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. ADD DONNER                         |"<<endl;
   cout<<"\t\t\t|                  2. SHOW DONNER                        |"<<endl;
   cout<<"\t\t\t|                  3. SEARCH DONNER                      |"<<endl;
   cout<<"\t\t\t|                  4. UPDATE DONNER                      |"<<endl;
   cout<<"\t\t\t|                  5. DELETE DONNER                      |"<<endl;
   cout<<"\t\t\t|                  6. GO BACK                            |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			add_donner();
			getch();
			break;
		case 2:
			system("cls");
			show_donner();
			getch();
			break;
		case 3:
			system("cls");
			search_donner();
			getch();
			break;
		case 4:
		    system("cls");
			update_donner();
			getch();
			break;
        case 5:
             system("cls");
			delete_donner();
			getch();
           break;

        case 6:
            system("cls");
			main_menu();
		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}

void inventory_menu()
{
   int c;

   cout<<"\n\n";


   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGMENT SYSTEM               \n\n\n";
   cout<<"\t\t\t_____________________  MENU ___________________________\n\n";
   cout<<"                                                                 \n\n";

   cout<<"\t\t\t|                  1. ADD INVENTORY                         |"<<endl;
   cout<<"\t\t\t|                  2. SHOW INEVNTORY                        |"<<endl;
   cout<<"\t\t\t|                  3. SEARCH INVENTORY                      |"<<endl;
   cout<<"\t\t\t|                  4. UPDATE INVENTORY                      |"<<endl;
   cout<<"\t\t\t|                  5. DELETE INVENTORY                      |"<<endl;
   cout<<"\t\t\t|                  6. GO BACK                               |"<<endl;

   cout<<"\n\t\t\t PLEASE ENTER YOUR CHOICE: ";

   cin>>c;
   cout<<endl;
   switch (c)
	{
		case 1:
			system("cls");
			add_inventory();
			getch();
			break;
		case 2:
			system("cls");
			show_inventory();
			getch();
			break;
		case 3:
			system("cls");
            search_inventory();
			getch();
			break;
		case 4:
          system("cls");
          update_inventory();
			getch();
			break;

        case 5:
            system("cls");
          delete_inventory();
			getch();
            break;
        case 6:
            system("cls");
			main_menu();
		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			getch();
			break;
	}
	return;
}
// Menu's Function end here





// Patient Functions Starts here

void add_patient()
{
     Patient patient;
     system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________ADD PATIENT___________________________\n\n";
   cout<<"                                                                   \n\n";
   cin.ignore();
 cout<<"\t\t\t Enter the pId: ";
 getline(cin,patient.pId);
 cout<<"\t\t\t Enter Patient Name: ";
 getline(cin,patient.pname);
 cout<<"\t\t\t Enter Patient's Father Name: ";
 getline(cin,patient.fname);
  cout<<"\t\t\t Enter Patient's Mother Name: ";
 getline(cin,patient.mname);
 cout<<"\t\t\t Enter Patient's Address: ";
 getline(cin,patient.paddress);
 cout<<"\t\t\t Enter Patient's Phone Number: ";
 getline(cin,patient.ph);


 ofstream write;
 write.open("patient.txt",ios::app| ios::ate);
 write<<patient.pId<<","<<patient.pname<<","<<patient.fname<<","<<patient.mname<<","<<patient.paddress<<","<<patient.ph<<endl;
 write.close();
 cout<<"\n\t\t\tInformation Added "<<endl;


 patient_menu();


}

void show_patient()
{

   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________SHOW PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";
   ifstream read;
   read.open("patient.txt");
    string line;

    while(getline(read,line))
   {
      stringstream ss(line);
        Patient patient;
   //read>>patient.pId;
   getline(ss,patient.pId,',');
   cout<<"Patient's ID: "<<patient.pId<<endl;
   //read>>patient.pname;
   getline(ss,patient.pname,',');
   cout<<"Patient's Name: "<<patient.pname<<endl;
    //read>>patient.fname;
   getline(ss,patient.fname,',');
    cout<<"Father's Name: "<<patient.fname<<endl;
    //read>>patient.mname;
   getline(ss,patient.mname,',');
    cout<<"Mother's Name: "<<patient.mname<<endl;
    //read>>patient.paddress;
   getline(ss,patient.paddress,',');
    cout<<"Patient's Address: "<<patient.paddress<<endl;
    //read>>patient.ph;
   getline(ss,patient.ph,',');
 cout<<"Phone Number: "<<patient.ph<<endl;
/*
   cout<<"Patient ID: "<<patient.pId<<endl;
   cout<<"Patient Name: "<<patient.pname<<endl;
   cout<<"Father's Name: "<< patient.fname<<endl;
   cout<<"Mother's Name: "<<patient.mname<<endl;
   cout<<"Patient Address: "<<patient.paddress<<endl;
   cout<<"Phone Number: "<<patient.ph<<endl; */
   cout<<"\n\n\n";
   cout<<"*****************************************"<<endl;

   }
 read.close();
   patient_menu();


}


void search_patient()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________SEARCH PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";

    vector<Patient> patients;

  ifstream inputFile("patient.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Patient patient;
    getline(ss, patient.pId, ',');
    getline(ss, patient.pname, ',');
    getline(ss, patient.fname, ',');
    getline(ss, patient.mname, ',');
    getline(ss, patient.paddress, ',');
    getline(ss, patient.ph);
    patients.push_back(patient);
  }

  inputFile.close();

  // Search for a patient by ID
  string searchId ;
  cout<<"Enter the patient id you want to search: ";
  cin>>searchId;
  for (const auto& patient : patients) {
    if (patient.pId == searchId) {
      cout << "Patient's ID: " << patient.pId << endl;
      cout << "Patient's Name: " << patient.pname << endl;
      cout << "Father's Name: " << patient.fname << endl;
      cout << "Mother's Name: " << patient.mname << endl;
      cout << "Patient's Address: " << patient.paddress << endl;
      cout << "Phone Number: " << patient.ph << endl;
      break;
    }
  }
    patient_menu();



}


void update_patient()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________Update PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";
 vector<Patient> patients;

ifstream inputFile("patient.txt");
if (!inputFile) {
  cerr << "Error opening file!" << endl;
}

string line;
while (getline(inputFile, line)) {
  stringstream ss(line);
  Patient patient;
  getline(ss, patient.pId, ',');
  getline(ss, patient.pname, ',');
  getline(ss, patient.fname, ',');
  getline(ss, patient.mname, ',');
  getline(ss, patient.paddress, ',');
  getline(ss, patient.ph);
  patients.push_back(patient);
}

inputFile.close();

// Search for a patient by ID
string searchId ;
cout<<"Enter the patient id you want to search: ";
cin>>searchId;
for (auto& patient : patients) {
  if (patient.pId == searchId) {
    cout << "Patient's ID: " << patient.pId << endl;
    cout << "Patient's Name: " << patient.pname << endl;
    cout << "Father's Name: " << patient.fname << endl;
    cout << "Mother's Name: " << patient.mname << endl;
    cout << "Patient's Address: " << patient.paddress << endl;
    cout << "Phone Number: " << patient.ph << endl;

    cout<<"*******************************************************"<<endl;
    cout<<"------------------UPDATE INFORMATION---------------------------"<<endl;

    string name,faname,maname,add,p;
    cout << "Patient's Name: ";
    cin>>name;
    cout << "Father's Name: ";
    cin>>faname;
    cout << "Mother's Name: ";
    cin>>maname;
    cout << "Patient's Address: ";
    cin>>add;
    cout << "Phone Number: ";
    cin>>p;

    patient.pname = name;
    patient.fname = faname;
    patient.mname = maname;
    patient.paddress = add;
    patient.ph = p;

    break;
  }
}

// Write the updated information back to the file
ofstream outputFile("patient.txt"); // replace "filename.txt" with the actual name of your text file
if (!outputFile) {
  cerr << "Error opening file!" << endl;
}

for (const auto& patient : patients) {
  outputFile << patient.pId << "," << patient.pname << "," << patient.fname << "," << patient.mname << "," << patient.paddress << "," << patient.ph << endl;
}

outputFile.close();

patient_menu();

}

void delete_patient(){

system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________DELETE PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";


vector<Patient> patients;

// Load the patients from the file into the vector
ifstream inputFile("patient.txt");
if (!inputFile) {
  cerr << "Error opening file!" << endl;
}

string line;
while (getline(inputFile, line)) {
  stringstream ss(line);
  Patient patient;
  getline(ss, patient.pId, ',');
  getline(ss, patient.pname, ',');
  getline(ss, patient.fname, ',');
  getline(ss, patient.mname, ',');
  getline(ss, patient.paddress, ',');
  getline(ss, patient.ph);
  patients.push_back(patient);
}

inputFile.close();

// Prompt the user for the ID of the patient to delete
string deleteId;
cout << "Enter the patient id you want to delete: ";
cin >> deleteId;

// Search for the patient with the matching ID and erase them from the vector
auto iter = remove_if(patients.begin(), patients.end(), [&](const Patient& p) { return p.pId == deleteId; });
if (iter != patients.end()) {
  patients.erase(iter, patients.end());
  cout << "Patient with ID " << deleteId << " has been deleted." << endl;
} else {
  cout << "Patient with ID " << deleteId << " not found." << endl;
}

// Write the updated vector back to the file
ofstream outputFile("patient.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
}

for (const auto& patient : patients) {
  outputFile << patient.pId << "," << patient.pname << "," << patient.fname << "," << patient.mname << "," << patient.paddress << "," << patient.ph << endl;
}

outputFile.close();

patient_menu();


}

/* Code For staff starts here*/

void add_staff()
{
     Staff staff;
     system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________ADD STAFF_____________________________\n\n";
   cout<<"                                                                   \n\n";
   cin.ignore();
 cout<<"\t\t\t Enter the Staff ID: ";
 getline(cin,staff.sId);
 cout<<"\t\t\t Enter Staff Name: ";
 getline(cin,staff.sname);
 cout<<"\t\t\t Enter Staff's Address: ";
 getline(cin,staff.saddress);
 cout<<"\t\t\t Enter Staff's Phone Number: ";
 getline(cin,staff.sph);
 cout<<"\t\t\t Enter Staff's Post: ";
 getline(cin,staff.spost);
 cout<<"\t\t\t Enter Staff's Email: ";
 getline(cin,staff.semail);


 ofstream write;
 write.open("staff.txt",ios::app| ios::ate);
 write<<staff.sId<<","<<staff.sname<<","<<staff.saddress<<","<<staff.sph<<","<<staff.spost<<","<<staff.semail<<endl;
 write.close();
 cout<<"\n\t\t\tInformation Added "<<endl;


 staff_menu();


}

void show_staff()
{

   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________SHOW STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";
   ifstream read;
   read.open("staff.txt");
    string line;

    while(getline(read,line))
   {
      stringstream ss(line);
        Staff staff;
   getline(ss,staff.sId,',');
   cout<<"Staff's ID: "<<staff.sId<<endl;

   getline(ss,staff.sname,',');
   cout<<"Staff's Name: "<<staff.sname<<endl;

   getline(ss,staff.saddress,',');
    cout<<"Staff's Address: "<<staff.saddress<<endl;

   getline(ss,staff.sph,',');
 cout<<" Staff's Phone Number: "<<staff.sph<<endl;

   getline(ss,staff.spost,',');
    cout<<"Staff's Post: "<<staff.spost<<endl;

   getline(ss,staff.semail,',');
    cout<<"Staff's Email: "<<staff.semail<<endl;

   cout<<"\n\n\n";
   cout<<"*****************************************"<<endl;

   }
 read.close();
   staff_menu();


}


void search_staff()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________SEARCH STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";

  vector<Staff> staffs;

  ifstream inputFile("staff.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Staff staff;
    getline(ss, staff.sId, ',');
    getline(ss, staff.sname, ',');
    getline(ss, staff.saddress, ',');
    getline(ss, staff.sph);
    getline(ss, staff.spost, ',');
    getline(ss, staff.semail, ',');

    staffs.push_back(staff);
  }

  inputFile.close();

  // Search for a patient by ID
  string searchId ;
  cout<<"Enter the Staff id you want to search: ";
  cin>>searchId;
  for (const auto& staff : staffs) {
    if (staff.sId == searchId) {
      cout << "Staff's ID: " << staff.sId << endl;
      cout << "Staff's Name: " << staff.sname << endl;
      cout << "Staff's Address: " << staff.saddress << endl;
      cout << "Staff's Phone Number: " << staff.sph << endl;
      cout << "Staff's Post: " << staff.spost << endl;
      cout << "Staff's Email: " << staff.semail << endl;
      break;
    }
  }
    staff_menu();



}


void update_staff()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________UPDATE STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";
  vector<Staff> staffs;

  ifstream inputFile("staff.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Staff staff;
    getline(ss, staff.sId, ',');
    getline(ss, staff.sname, ',');
    getline(ss, staff.saddress, ',');
    getline(ss, staff.sph, ',');
    getline(ss, staff.spost, ',');
    getline(ss, staff.semail);

    staffs.push_back(staff);
  }

  inputFile.close();

  // Search for a staff by ID
  string searchId;
  cout << "Enter the Staff ID you want to search: ";
  cin >> searchId;

  for (auto& staff : staffs) {
    if (staff.sId == searchId) {
      cout << "Staff's ID: " << staff.sId << endl;
      cout << "Staff's Name: " << staff.sname << endl;
      cout << "Staff's Address: " << staff.saddress << endl;
      cout << "Staff's Phone Number: " << staff.sph << endl;
      cout << "Staff's Post: " << staff.spost << endl;
      cout << "Staff's Email: " << staff.semail << endl;

      cout << "*******************************************************" << endl;
      cout << "------------------UPDATE INFORMATION---------------------------" << endl;

      string na, add, p, po, em;
      cout << "Staff's Name: ";
      cin >> na;
      cout << "Staff's Address: ";
      cin >> add;
      cout << "Staff's Phone Number: ";
      cin >> p;
      cout << "Staff's Post: ";
      cin >> po;
      cout << "Staff's Email: ";
      cin >> em;

      staff.sname = na;
      staff.saddress = add;
      staff.sph = p;
      staff.spost = po;
      staff.semail = em;
    }
  }

  // Write the updated information back to the file
  ofstream outputFile("staff.txt");
  if (!outputFile) {
    cerr << "Error opening file!" << endl;

  }

  for (const auto& staff : staffs) {
    outputFile << staff.sId << "," << staff.sname << "," << staff.saddress << "," << staff.sph << "," << staff.spost << "," << staff.semail << endl;
  }

  outputFile.close();

staff_menu();

}

void delete_staff(){

system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________DELETE PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";
 system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________UPDATE STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";
  vector<Staff> staffs;

  ifstream inputFile("staff.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Staff staff;
    getline(ss, staff.sId, ',');
    getline(ss, staff.sname, ',');
    getline(ss, staff.saddress, ',');
    getline(ss, staff.sph, ',');
    getline(ss, staff.spost, ',');
    getline(ss, staff.semail);

    staffs.push_back(staff);
  }

  inputFile.close();
string deleteId;
cout << "Enter the Staff ID you want to delete: ";
cin >> deleteId;

for (auto it = staffs.begin(); it != staffs.end(); ++it) {
  if (it->sId == deleteId) {
    staffs.erase(it); // remove the staff member from the vector
    break;
  }
}

// Write the updated information back to the file
ofstream outputFile("staff.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
}

for (const auto& staff : staffs) {
  outputFile << staff.sId << "," << staff.sname << "," << staff.saddress << "," << staff.sph << "," << staff.spost << "," << staff.semail << "," << endl;
}

outputFile.close();



staff_menu();
}

/* Staff section codes ends here*/





/*-------------------------------------------------------------DONNER*/








/*Donner sections starts here*/


void add_donner()
{
     Donner donner;
     system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________ADD Donner_____________________________\n\n";
   cout<<"                                                                   \n\n";
   cin.ignore();
 cout<<"\t\t\t Enter the Donner ID: ";
 getline(cin,donner.dId);
 cout<<"\t\t\t Enter Donner Name: ";
 getline(cin,donner.dname);
 cout<<"\t\t\t Enter Donner's Address: ";
 getline(cin,donner.daddress);
 cout<<"\t\t\t Enter Donner's Phone Number: ";
 getline(cin,donner.dph);
 cout<<"\t\t\t Enter Donner's Email: ";
 getline(cin,donner.demail);
 cout<<"\t\t\t Enter Donner's Blood Group: ";
 getline(cin,donner.blood_group);


 ofstream write;
 write.open("donner.txt",ios::app| ios::ate);
 write<<donner.dId<<","<<donner.dname<<","<<donner.daddress<<","<<donner.dph<<","<<donner.demail<<donner.blood_group<<","<<endl;
 write.close();
 cout<<"\n\t\t\tInformation Added "<<endl;


 donner_menu();


}

void show_donner()
{

   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________SHOW STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";
   ifstream read;
   read.open("donner.txt");
    string line;

    while(getline(read,line))
   {
      stringstream ss(line);
        Donner donner;
   getline(ss,donner.dId,',');
   cout<<"Donner's ID: "<<donner.dId<<endl;

   getline(ss,donner.dname,',');
   cout<<"Donner's Name: "<<donner.dname<<endl;

   getline(ss,donner.daddress,',');
    cout<<"Donner's Address: "<<donner.daddress<<endl;

   getline(ss,donner.dph,',');
 cout<<" Donner's Phone Number: "<<donner.dph<<endl;

   getline(ss,donner.demail,',');
    cout<<"Donner's Email: "<<donner.demail<<endl;

    getline(ss,donner.blood_group,',');
    cout<<"Donner's Blood Group: "<<donner.blood_group<<endl;

   cout<<"\n\n\n";
   cout<<"*****************************************"<<endl;

   }
 read.close();
   donner_menu();


}


void search_donner()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________SEARCH DONNER___________________________\n\n";
   cout<<"                                                                 \n\n";

  vector<Donner> donners;

  ifstream inputFile("donner.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Donner donner;
    getline(ss, donner.dId, ',');
    getline(ss, donner.dname, ',');
    getline(ss, donner.daddress, ',');
    getline(ss, donner.dph);
    getline(ss, donner.demail, ',');
    getline(ss, donner.blood_group, ',');

    donners.push_back(donner);
  }

  inputFile.close();

  // Search for a patient by ID
  string searchId ;
  cout<<"Enter the Staff id you want to search: ";
  cin>>searchId;
  for (const auto& donner : donners) {
    if (donner.dId == searchId) {
      cout << "Donner's ID: " << donner.dId << endl;
      cout << "Donner's Name: " << donner.dname << endl;
      cout << "Donner's Address: " << donner.daddress << endl;
      cout << "Donner's Phone Number: " << donner.dph << endl;
      cout << "Donner's Email: " << donner.demail << endl;
      cout << "Donner's Blood Group: " << donner.blood_group << endl;
      break;
    }
  }
    donner_menu();

}


void update_donner()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________UPDATE DONNER___________________________\n\n";
   cout<<"                                                                 \n\n";
   vector<Donner> donners;
  ifstream inputFile("donner.txt");
   if (!inputFile) {
  cerr << "Error opening file!" << endl;
  return;
}

string line;
while (getline(inputFile, line)) {
  stringstream ss(line);
  Donner donner;
  getline(ss, donner.dId, ',');
  getline(ss, donner.dname, ',');
  getline(ss, donner.daddress, ',');
  getline(ss, donner.dph, ',');
  getline(ss, donner.demail, ',');
  getline(ss, donner.blood_group);

  donners.push_back(donner);
}

inputFile.close();

// Search for a donner by ID
string searchId;
cout << "Enter the Donner ID you want to update: ";
cin >> searchId;
bool found = false;

for (auto& donner : donners) {
  if (donner.dId == searchId) {
    found = true;
    cout << "Donner's ID: " << donner.dId << endl;
    cout << "Donner's Name: " << donner.dname << endl;
    cout << "Donner's Address: " << donner.daddress << endl;
    cout << "Donner's Phone Number: " << donner.dph << endl;
    cout << "Donner's Email: " << donner.demail << endl;
    cout << "Donner's Blood Group: " << donner.blood_group << endl;

    cout << "*******************************************************" << endl;
    cout << "------------------UPDATE INFORMATION-------------------" << endl;

    string name, address, phone, email, blood_group;
    cout << "Donner's Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Donner's Address: ";
    getline(cin, address);
    cout << "Donner's Phone Number: ";
    getline(cin, phone);
    cout << "Donner's Email: ";
    getline(cin, email);
    cout << "Donner's Blood Group: ";
    getline(cin, blood_group);

    donner.dname = name;
    donner.daddress = address;
    donner.dph = phone;
    donner.demail = email;
    donner.blood_group = blood_group;

    cout << "Donner's information updated successfully!" << endl;
  }
}

if (!found) {
  cout << "Donner with ID " << searchId << " not found!" << endl;
}

// Write the updated information back to the file
ofstream outputFile("donner.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
  return;
}

for (const auto& donner : donners) {
  outputFile << donner.dId << "," << donner.dname << "," << donner.daddress << ","
             << donner.dph << "," << donner.demail << "," << donner.blood_group << endl;
}

outputFile.close();

donner_menu();

}

void delete_donner(){

system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________DELETE PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";
  vector<Donner> donners;

  ifstream inputFile("donner.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    Donner donner;
    getline(ss, donner.dId, ',');
    getline(ss, donner.dname, ',');
    getline(ss, donner.daddress, ',');
    getline(ss, donner.dph);
    getline(ss, donner.demail, ',');
    getline(ss, donner.blood_group, ',');

    donners.push_back(donner);
  }

  inputFile.close();
string deleteId;
cout << "Enter the Staff ID you want to delete: ";
cin >> deleteId;

for (auto it = donners.begin(); it != donners.end(); ++it) {
  if (it->dId == deleteId) {
    donners.erase(it); // remove the staff member from the vector
    break;
  }
}

// Write the updated information back to the file
ofstream outputFile("donner.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
}

for (const auto& donner : donners) {
  outputFile << donner.dId << "," <<  donner.dname << "," <<  donner.daddress << "," <<  donner.dph <<"," << donner.demail << "," << donner.blood_group << endl;
}

outputFile.close();



donner_menu();
}

/* Donner Section Ends here */



/*-----------------------------------------------------------------INVENTORY---------------------------------------------------*/



/* Inventory Sections Starts Here*/


void add_inventory()
{
    Invent invent;
     system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________ADD Inventory_____________________________\n\n";
   cout<<"                                                                   \n\n";
   cin.ignore();
 cout<<"\t\t\t Enter the Inventory ID: ";
 getline(cin,invent.iId);
 cout<<"\t\t\t Enter Inventory Name: ";
 getline(cin,invent.iname);



 ofstream write;
 write.open("inventory.txt",ios::app| ios::ate);
 write<<invent.iId<<","<<invent.iname<<","<<endl;
 write.close();
 cout<<"\n\t\t\tInformation Added "<<endl;


 inventory_menu();


}

void show_inventory()
{

   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t______________________SHOW STAFF___________________________\n\n";
   cout<<"                                                                 \n\n";
   ifstream read;
   read.open("inventory.txt");
    string line;

    while(getline(read,line))
   {
      stringstream ss(line);
        Invent invent;
   getline(ss,invent.iId,',');
   cout<<"Inventory's ID: "<<invent.iId<<endl;

   getline(ss,invent.iname,',');
   cout<<"Inventory's Name: "<<invent.iname<<endl;


   cout<<"\n\n\n";
   cout<<"*****************************************"<<endl;

   }
 read.close();
   inventory_menu();


}


void search_inventory()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________SEARCH DONNER___________________________\n\n";
   cout<<"                                                                 \n\n";

  vector<Invent> invents;

  ifstream inputFile("inventory.txt");
  if (!inputFile) {
    cerr << "Error opening file!" << endl;

  }

  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
  Invent invent;
    getline(ss, invent.iId, ',');
    getline(ss, invent.iname, ',');


    invents.push_back(invent);
  }

  inputFile.close();

  // Search for a patient by ID
  string searchId ;
  cout<<"Enter the Staff id you want to search: ";
  cin>>searchId;
  for (const auto& invent : invents) {
    if (invent.iId == searchId) {
      cout << "Inventory's ID: " << invent.iId << endl;
      cout << "Inventory's Name: " << invent.iname << endl;
      break;
    }
  }
    inventory_menu();

}


void update_inventory()
{
   system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________UPDATE INVENTORY___________________________\n\n";
   cout<<"                                                                 \n\n";
   vector<Invent> invents;
  ifstream inputFile("inventory.txt");
   if (!inputFile) {
  cerr << "Error opening file!" << endl;
  return;
}

string line;
while (getline(inputFile, line)) {
  stringstream ss(line);
  Invent invent;
    getline(ss, invent.iId, ',');
    getline(ss, invent.iname, ',');


    invents.push_back(invent);
}

inputFile.close();

// Search for a donner by ID
string searchId;
cout << "Enter the Donner ID you want to update: ";
cin >> searchId;
bool found = false;

for (auto& invent : invents) {
  if (invent.iId == searchId) {
    found = true;
    cout << "Inventory's ID: " << invent.iId << endl;
    cout << "Inventory's Name: " << invent.iname << endl;

    cout << "*******************************************************" << endl;
    cout << "------------------UPDATE INFORMATION-------------------" << endl;

    string name;
    cout << "Donner's Name: ";
    cin.ignore();
    getline(cin, name);


    invent.iname = name;


    cout << "Information updated successfully!" << endl;
  }
}

if (!found) {
  cout << "Inventory with ID " << searchId << " not found!" << endl;
}

// Write the updated information back to the file
ofstream outputFile("inventory.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
  return;
}

for (const auto& invent : invents) {
  outputFile << invent.iId << "," << invent.iname << "," << endl;
}

outputFile.close();

inventory_menu();

}

void delete_inventory(){

system("cls");
   cout<<"\t\t\t_________________________________________________________\n\n\n";
   cout<<"\t\t\t                  HOSPITAL MANAGEMENT SYSTEM              \n\n\n";
   cout<<"\t\t\t____________________DELETE PATIENT___________________________\n\n";
   cout<<"                                                                 \n\n";
  vector<Invent> invents;
  ifstream inputFile("inventory.txt");
   if (!inputFile) {
  cerr << "Error opening file!" << endl;
  return;
}

string line;
while (getline(inputFile, line)) {
  stringstream ss(line);
  Invent invent;
    getline(ss, invent.iId, ',');
    getline(ss, invent.iname, ',');


    invents.push_back(invent);
}

inputFile.close();
string deleteId;
cout << "Enter the Staff ID you want to delete: ";
cin >> deleteId;

for (auto it = invents.begin(); it != invents.end(); ++it) {
  if (it->iId == deleteId) {
    invents.erase(it); // remove the staff member from the vector
    break;
  }
}

// Write the updated information back to the file
ofstream outputFile("inventory.txt");
if (!outputFile) {
  cerr << "Error opening file!" << endl;
}

for (const auto& invent : invents) {
  outputFile << invent.iId << "," <<  invent.iname << ","<< endl;
}

outputFile.close();



inventory_menu();
}

/*Inventory Sections Ends Here*/










  int main()
  {

  login_menu();


      return 0;
}
