#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <sstream>
#include <bits/stl_vector.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class User {
	public:
		User(string n, string uid, string pass, string pNu, string m, double b, string p){
			this->uname = n;
			this->uID = uid;
			this->password = pass;
			this->upNumber = pNu;
			this->membership = m;
			this->balance = b;
			this->purchase = p;
		}
		
		void setBalance(double a){ this->balance +=a; }
		void setPurchase(string pu){ this->purchase = this->purchase + ", " + pu; }
		
		string getUName(){ return this->uname; }
		string getUID(){return this->uID; }
		string getUPNumber(){return this->upNumber; }
		string getMembership(){return this->membership; }
		string getPassword(){return this->password; }
		double getBalance(){return this->balance;}
		string getPurchase(){return this->purchase;}
		
	private:
		string uname, uID, upNumber, membership, password, purchase;
		double balance;
			
};


class Division{
	public:
		Division(){
			this->name="";
			this->detail="";
		}
		
		Division(string n, string d, Division* pDiv = NULL){  
	        this->name = n;
	        this->detail = d;
	        this->parentDiv = pDiv;
	    }
		
		string getName(){ return this->name; }

		bool isUnique( vector<Division*> &Divisions, Division & newDiv){
			for (int i = 0; i < Divisions.size(); ++i) {
			    if (newDiv.name == Divisions[i]->name) {return false;}
			}
			return true;
		}
	
	private:
		string name, detail;
		Division* parentDiv;
};


class Vehicle { 
	public:
	    virtual void printIt() = 0;
		virtual string getName() = 0;
		virtual string getType() = 0;
	    virtual double getEffective() = 0;
	    virtual Division* getDivision() = 0;
};

class fourWheel : public Vehicle{
	public:
		fourWheel(){
			
			this->name="";
			this->detail="";
			this->div=new Division;
			this->type = "";
			this->year=0;
			this->price=0.0;
			this->speed = "";
			this->fuelType = "";
			this->seatNumber = 0;
			this->weight = 0.0;
			
		}
	
		fourWheel(string n, string det, Division* d, string t, int y, double pr, string s, string fT, int seatN, double w){
		 	
		 	this->name=n;
		 	this->detail=det;
		 	this->div=d;
		 	this->type=t;
		 	this->year=y;
		 	this->price=pr;
			this->speed = s;
			this->fuelType = fT;
			this->seatNumber = seatN;
			this->weight = w;
		 
		 }
		 
		 void printIt() {
			cout << "Detail: " << this->detail;
	        cout << "\nName: " << this->name;
	        cout << "\nType: " << this->type;
	        cout << "\nManufactured Year: " << this->year;
	        cout << "\nPrice per day: " << this->price;			
			cout << "\nSpeed Range: " << this->speed;
	        cout << "\nFuel Type: " << this->fuelType;
	        cout << "\nSeat Number: " << this->seatNumber;
	        cout << "\nWeight: " << this->weight;
	    }

		string getName(){ return this->name; }
		string getType(){ return this->type; }
		string getSpeed(){ return this->speed;	}
	    double getEffective(){ return 0; }	
	    Division* getDivision(){ return div; }
	
		
	protected:
	    string type, detail, name, speed, fuelType;
   		double weight, price;
   		int seatNumber, year;
		Division* div;
};

class Performance : public fourWheel{
	public:
		Performance(){
			this->discount = 0.0;
			this->pumpHorsePower="";
			this->soundEngine="";
		}

		Performance(string n, string det, Division* d, string t, int y, double pr, string s, string fT, int seatN, double w, double dis, string pHP, string sE) 
		: fourWheel(n, det, d, t, y, pr, s, fT, seatN, w){
			
			this->discount = dis;
			this->pumpHorsePower = pHP;
			this->soundEngine = sE;
			
		}
		
		double getEffective(){
			return ( (this->price*(1-this->discount)) >= 0) ? (this->price*(1-this->discount)) : 0.0;
		}
		
    	void printIt() {
			fourWheel::printIt();
			cout << "\nDiscount: " << this->discount;
			cout << "\nPump Horse Power: " << this->pumpHorsePower;
			cout << "\nSound Engine: " << this->soundEngine << endl;
    	}
    private:
    	string pumpHorsePower, soundEngine;
    	double discount;
};


class Luxury : public fourWheel{
	public:
		
		Luxury(){
			this->discount = 0.0;
			this->seatCoolers = "";
		}
		
		Luxury(string n, string det, Division* d, string t, int y, double pr, string s, string fT, int seatN, double w, double dis, string seatC)
		 : fourWheel(n, det, d, t, y, pr, s, fT, seatN, w){
		 
		 	this->discount = dis;
		 	this->seatCoolers = seatC;
		 
		 } 
		
		double getEffective(){
			return ( ((this->price*(1-this->discount)) - 10.0) >=0 ) ? ((this->price*(1-this->discount)) - 10.0) : 0.0;
		}

		void printIt() {
        	fourWheel::printIt();
        	cout << "\nDiscount: " << this->discount;
        	cout << "\nSeat Coolers: " << this->seatCoolers << endl;
        }
		
	private:
		string seatCoolers;
		double discount;
};

class twoWheel : public Vehicle{
	public:
		twoWheel(){			
			
			this->name="";
			this->detail="";
			this->div=new Division;
			this->type="";
			this->year=0;
			this->price=0.0;
			this->wheelSize=0.0;
			this->cylinders=0;
			this->engine="";
			this->maxSpeed=0.0;

		}
		twoWheel(string n, string det, Division* d, string t, int y, double pr, double wSize, int cyl, string e, double maxS){
		
			this->name=n;
		 	this->detail=det;
		 	this->div=d;
		 	this->type = t;
		 	this->year=y;
		 	this->price=pr;
		 	this->wheelSize=wSize;
		 	this->cylinders=cyl;
		 	this->engine=e;
		 	this->maxSpeed=maxS;
		 	
		}
				
		string getName(){ return this->name; }
		string getType(){ return this->type; }
	    double getEffective(){ return 0; }	
	    Division* getDivision(){ return div; }		
				
		void printIt() {
	        cout << "Detail: " << this->detail;
	        cout << "\nName: " << this->name;
	        cout << "\nType: " << this->type;
	        cout << "\nManufactured Year: " << this->year;
	        cout << "\nPrice per day: " << this->price;	
	       	cout << "\nWheel Size: " << this->wheelSize;
	      	cout << "\nCylinders: " << this->cylinders;
	      	cout << "\nEngine: " << this->engine;
			cout << "\nMaxSpeed: " << this->maxSpeed;
	    }
	    
	protected:
		string engine, detail, name, type;
		double wheelSize, maxSpeed, price;
		int cylinders, year;
		Division* div;
};

class Sports : public twoWheel{
	
	public:
		Sports() {
			this->discount = 0.0;
			this->requiredLicence = "";
			this->modification="";
    	}
    	Sports(string n, string det, Division* d, string t, int y, double pr, double wSize, int cyl, string e, double maxS, double dis, string rL, string m)
		 : twoWheel(n, det, d, t, y, pr, wSize, cyl, e, maxS){
		 	
		 	this->discount = dis;
		 	this->requiredLicence = rL;
		 	this->modification = m;
		 
		 }
   		
   		double getEffective(){
			return ( (this->price*(1-this->discount)) >= 0) ? (this->price*(1-this->discount)) : 0.0;
		}
    	
		void printIt() {
			twoWheel::printIt();
			cout << "\nDiscount: " << this->discount;
			cout << "\nRequired Licence: " << this->requiredLicence;
			cout << "\nModification: " << this->modification << endl;;
		}
	
	private:
    	string requiredLicence, modification;
    	double discount;
    	
};


class Moped : public twoWheel{
	public:
		
		Moped(){
			this->discount = 0.0;
			this->windSheildSize = "";
		}
		
		Moped(string n, string det, Division* d, string t, int y, double pr, double wSize, int cyl, string e, double maxS, double dis, string wSS)
		 : twoWheel(n, det, d, t, y, pr, wSize, cyl, e, maxS){
		 	
		 	this->discount = dis;
		 	this->windSheildSize=wSS;
		 
		 }

	    double getEffective(){
			return ( ((this->price*(1-this->discount)) - 5.0) >=0 ) ? ((this->price*(1-this->discount)) - 5.0) : 0.0;
		}
	    
		void printIt() {
			twoWheel::printIt();
			cout << "\nDiscount: " << this->discount;
			cout << "\nWind Sheild Size: " << this->windSheildSize << endl;
	    }
	private:
	    string windSheildSize;	
	    double discount;

};



template <typename T> void split(const string& str, vector<T> &u, char delim = ';'){
    stringstream ss(str);
    string token;
    while (std::getline(ss, token, delim)) {
        u.push_back(token);
    }
}

template <typename T> void addUsers(vector<T> &Users, string n, string uid, string pass, string pNu, string m, double b, string p) {
	Users.push_back(new User(n, uid, pass, pNu, m, b, p));
}

template <typename T> void addPerformance(vector<T> &Vehicles, string name, string detail, Division* div, string type, int year, double price, string sspeed, string fuelType, int seatNumber, double weight, double dis, string pHP, string sE) {
	Vehicles.push_back(new Performance(name, detail, div, type, year, price, sspeed, fuelType, seatNumber, weight, dis, pHP, sE));
}

template <typename T> void addLuxury(vector<T> &Vehicles, string name, string detail, Division* div, string type, int year, double price, string sspeed, string fuelType, int seatNumber, double weight, double dis, string seatC) {
	Vehicles.push_back(new Luxury(name, detail, div, type, year, price, sspeed, fuelType, seatNumber, weight, dis, seatC));
}

template <typename T> void addSports(vector<T> &Vehicles, string name, string detail, Division* div, string type, int year, double price, double wheelSize, int cylinders, string engine, double maxSpeed, double dis, string rL, string m) {
	Vehicles.push_back(new Sports(name, detail, div, type, year, price, wheelSize, cylinders, engine, maxSpeed, dis, rL, m));
}

template <typename T> void addMoped(vector<T> &Vehicles, string name, string detail, Division* div, string type, int year, double price, double wheelSize, int cylinders, string engine, double maxSpeed, double dis, string wSS) {
	Vehicles.push_back(new Moped(name, detail, div, type, year, price, wheelSize, cylinders, engine, maxSpeed, dis, wSS));
}

template <typename T> bool authorizationUser(vector<T> &Users, string username, string password){
	
	int a=0;
	
	for(int i=0; i<Users.size(); i++){
		if( username.compare(Users[i]->getUID()) == 0 && password.compare(Users[i]->getPassword()) == 0){
			a++;
		}
	}
	
	return (a == 1) ? true : false;
	
}

string removeSpaces(string selection){ 
    selection.erase(remove(selection.begin(), selection.end(), ' '), selection.end()); 
    return selection; 
} 

bool authorization(string username, string password){
	
	string line;
	ifstream inFile ("admin.txt");    
	
	int a = 0;
	     
	if (inFile.is_open()){
	    while ( getline (inFile, line) ){
	    	stringstream ss(line);
	    	string user, pass;
	    	
	    	ss >> user >> pass;
	    	
	    	if( username.compare(user) == 0 && password.compare(pass) == 0){
	    		a = 1;
			}
	    }
	    inFile.close();
	}
	else{cout << "Unable to open file"; } 
	
	return (a == 1) ? true : false;
	
}

template <typename T> bool reg(vector<T> &Users){
	
	string fName, pNumb, password, uname, firstName, lName;
	double bal = 0.0;
	
	cout << "	_________________________________________________________________  " << endl << endl;
	cout << "	              Welcome to our registration system  " << endl;
	cout << "	_________________________________________________________________  " << endl << endl;
	
	cout << "		Please enter your First name: ";
	cin >> firstName;
	
	cout << "		Please enter your Last name: ";
	cin >> lName;
	
	fName = firstName + " " + lName;
	
	cout << "		Please Enter your phone number: ";
	cin >> pNumb;
	cout << "                Choose your User name:  " ;
	
	bool va = false;
	
	while(!va){		//ask user to enter an input until its valid
		
		string username;
		int matches = 0;
		
		cin >> username;
		
		for(int i=0; i<Users.size(); i++){
			if(username==Users[i]->getUID()){
				matches++;
			}
		}
		
		if(matches != 0){
			cout << endl <<  "                Username already in use!!! Please choose another username" << endl;
			cout << "                Choose your User name:  " ;
			
		}
		else{
			uname = username;
			va = true;
		}
	}
	
	cout << "                Please Enter your password:  " ;
	cin >> password;
	
	system("CLS");
	
	ifstream inFile ("member.txt");         
	string line, selec;
	
	if (inFile.is_open()){
	    while ( getline (inFile, line) ){
	      cout << line << '\n';
	    }
	    inFile.close();
	}
	else{cout << "Unable to open file"; } 
	
	cout << "             Would you like to be our VIP member?" << endl;
	cout << "             		Y. Agree" << endl;
	cout << "                   N. No, thank you" << endl << endl;
	cout << "             Enter your selection: ";
	
	cin >> selec;
	string mem;
	string pur;
	
	if(selec[0] == 'y' || selec[0] == 'Y'){
		mem = "VIP";
		bal=10.0;
		pur= "VIPmembership";
	}else{
		mem = "NONE";
		bal=0.0;
		pur= " ";
	}
	
	system("CLS");
	cout << "Account Successfully Created!!!" << endl;
	cout << "Taking you to the main menu...." << endl;
	
	addUsers(Users, fName, uname, password, pNumb, mem, bal, pur);
	
	std::ofstream out;
	out.open("users.txt", std::ofstream::out | std::ofstream::app);
	std::ostringstream os;
	os << std::setprecision(2);
	os << bal;
	std::string ba = os.str();
	out << fName+";"+uname+";"+password+";"+pNumb+";"+mem+";"+ba+";"+pur<< endl;
	out.close();
	
	sleep(2);
	return 1;
	
}

template <typename T> void updateUser(vector<T> &u, string username, double bala, string prod){
	
	string fName, pNumb, password, memb, purch;
	double balan = 0.0;
	string path = "users.txt";
	const char * p = path.c_str();
	
	string line[256];
	vector<string> temp;
	std::ofstream temporary;
	temporary.open("temp.txt", std::ofstream::out);
	std::ostringstream os;
	ifstream file;
	file.open("users.txt");
	string str;
	int i= 0;
	while (getline(file, str)) {
		line[i]=str;
		i++;
	}
	for(int f=0; f<i; f++){
		split(line[f], temp);
		if(temp[1].compare(username)==0){
			fName = temp[0];
			password = temp[2];
			pNumb = temp[3];
			memb = temp[4];
			balan = atof(temp[5].c_str()) + bala;
			purch = temp[6] + ", " + prod;
			os << balan;
			std::string ba = os.str();
			temporary << fName+";"+username+";"+password+";"+pNumb+";"+memb+";"+ba+";"+purch <<endl;
		}
		else{
			temporary << line[f] << endl;
		}		
		temp.clear();
	}
	file.close();
	temporary.close();
	
	
	remove(p);
	rename("temp.txt", p);
	
}


template <typename T, typename Y> bool rentBike(vector<T> &u, vector<Y> &v, string username){

	bool success = false;
	
	do{		//ask user to enter an input until its valid
		
		system("CLS");
		
		cout << "      _____________________________________________" << endl << endl;
		cout << "           What kind of motorcycle do you want? " << endl;
		cout << "      _____________________________________________" << endl << endl;
		cout << "            A. Sport motorcycle" << endl;
		cout << "            B. Moped" << endl << endl;
		cout << "            C. Go back" << endl << endl;
		cout << "      ______________________________________________" << endl << endl;
		cout << "           Enter your selection: ";
		
		string choice, prod;
		int a, b, day, amount;
		double bala;
		
		getline(cin, choice);
		choice = removeSpaces(choice);
		
		if(choice[0] == 'a'){
			int count =0;
			system("CLS");
			cout << "________________________________________________________________" << endl << endl << endl;
			cout << "    Here is the list of all sports bike we have: " << endl << endl;    
			cout << "________________________________________________________________" << endl << endl << endl;
			for(int i=0; i<v.size(); i++){
				if( (v[i]->getType()).compare("Sports bike") == 0 ){
					count++;
					cout << " *** Option " << count << " ***";
					cout << endl;
					v[i]->printIt();
					cout << endl << endl;
				}
					
			}
			cout << "________________________________________________________________" << endl << endl << endl;
					
			bool ok = false;
			int p=0;
			do{
				cout << "Enter your option number: ";
				cin >> a;
				if(a > 0 && a <= count){
					system("CLS");
					for(int i=0; i<v.size(); i++){
						if( (v[i]->getType()).compare("Sports bike") == 0){
							p++;
							if( p == a ){
								cout << "_________________________________________________" << endl;
								cout << endl;
								cout << "           You selected: " << endl;
								amount = v[i]->getEffective();
								prod = v[i]->getName();
								v[i]->printIt();
								cout << "_________________________________________________" << endl;
							}
						}
					}
					cout << "How many days would you like to rent? ";
					cin >> day;
					bala = day*amount;
					cout << "Total rental amount: $" << bala << " before membership discount. "<< endl;
						
					for(int i=0; i<u.size(); i++){
						if( (u[i]->getUID()).compare(username) == 0){
							u[i]->setPurchase(prod);
							if((u[i]->getMembership()).compare("VIP") == 0){
								bala -= 5.0;
							}
							u[i]->setBalance(bala);
							updateUser(u, username, bala, prod);
						}
					}
					
					system("CLS");
					cout << "_____________________________________________" << endl << endl;
					cout << "     Updating your account balance......" << endl;
					cout << "_____________________________________________" << endl;
					sleep(2);

					ok = true;
					
				}else{ cout << "Please choose from the options above: ";	}
					
			}while(!ok);
			
			if(ok){
				success = true;
			}
			
		}
		
		else if(choice[0] == 'b'){
			int countL =0;
			system("CLS");
			cout << "________________________________________________________________" << endl << endl << endl;
			cout << "    Here is the list of all Moped bike we have: " << endl << endl;    
			cout << "________________________________________________________________" << endl << endl << endl;
			for(int i=0; i<=v.size(); i++){
				if( (v[i]->getType()).compare("Moped bike") == 0 ){
					countL++;
					cout << " *** Option " << countL << " ***";
					cout << endl;
					v[i]->printIt();
					cout << endl << endl;
				}
					
			}
			cout << "________________________________________________________________" << endl << endl << endl;
					
			bool ok = false;
			int p1=0;
			do{
				cout << "Enter your option number: ";
				cin >> a;
				if(a > 0 && a <= countL){
					system("CLS");
					for(int i=0; i<v.size(); i++){
						if( (v[i]->getType()).compare("Moped bike") == 0){
							p1++;
							if( p1 == a ){
								cout << "_________________________________________________" << endl;
								cout << endl;
								cout << "             You selected: " << endl;
								amount = v[i]->getEffective();
								prod = v[i]->getName();
								v[i]->printIt();
								cout << "_________________________________________________" << endl;
							}
						}
					}
					cout << "How many days would you like to rent? ";
					cin >> day;
					bala = day*amount;
					cout << "Total rental amount: $" << bala << " before membership discount."<< endl;
					sleep(2);
						
					for(int i=0; i<u.size(); i++){
						if( (u[i]->getUID()).compare(username) == 0){
							u[i]->setPurchase(prod);
							if((u[i]->getMembership()).compare("VIP") == 0){
								bala -= 5.0;
							}
							u[i]->setBalance(bala);
							updateUser(u, username, bala, prod);
						}
					}
					
					system("CLS");
					cout << "_____________________________________________" << endl << endl;
					cout << "     Updating your account balance......" << endl;
					cout << "_____________________________________________" << endl;
					

					ok = true;
					
				}else{ cout << "Please choose from the options above: ";	}
				
			}while(!ok);
			
			if(ok){
				success = true;
			}
		}
		
		else if(choice[0] == 'c'){
			success = true;
			system("CLS");
			cout << "         Loading user menu....." << endl;
			sleep(2);
			break;
		}
		else {
			cout << "         Please ENTER one of the options above." << endl;
			sleep(2);
			continue;
		}
		
		
		
		break;
	}while(!success);
	
	return 1;
}


template <typename T, typename Y> bool rentCar(vector<T> &u, vector<Y> &v, string username){
	bool success = false;
	
	do{		//ask user to enter an input until its valid
		
		system("CLS");
		
		cout << "      _____________________________________________" << endl << endl;
		cout << "           What kind of car do you want? " << endl;
		cout << "      _____________________________________________" << endl << endl;
		cout << "            A. Performance car" << endl;
		cout << "            B. Luxury car" << endl << endl;
		cout << "            C. Go back" << endl << endl;
		cout << "      ______________________________________________" << endl << endl;
		cout << "           Enter your selection: ";
		
		string choice, prod;
		int a, b, day, amount;
		double bala;
		
		getline(cin, choice);
		choice = removeSpaces(choice);
		
		if(choice[0] == 'a'){
			int count =0;
			system("CLS");
			
			cout << "________________________________________________________________" << endl << endl << endl;
			cout << "    Here is the list of all performance cars we have: " << endl << endl;    
			cout << "________________________________________________________________" << endl << endl << endl;
			for(int i=0; i<v.size(); i++){
				if( (v[i]->getType()).compare("Performance car") == 0 ){
					count++;
					cout << " *** Option " << count << " ***";
					cout << endl;
					v[i]->printIt();
					cout << endl << endl;
				}
					
			}
			cout << "________________________________________________________________" << endl << endl << endl;
					
			bool ok = false;
			int l =0;
			do{
				cout << "Enter your option number: ";
				cin >> a;
				if(a > 0 && a <= count){
					system("CLS");
					for(int i=0; i<v.size(); i++){
						if( (v[i]->getType()).compare("Performance car") == 0){
							l++;
							if( l == a ){
								cout << "_________________________________________________" << endl;
								cout << endl;
								cout << "                  You selected: " << endl;
								amount = v[i]->getEffective();
								prod = v[i]->getName();
								v[i]->printIt();
								cout << "_________________________________________________" << endl;
							}
						}
					}
					cout << "How many days would you like to rent? ";
					cin >> day;
					bala = day*amount;
					cout << "Total rental amount: $" << bala << " before membership discount;" << endl;
					sleep(2);
						
					for(int i=0; i<u.size(); i++){
						if( (u[i]->getUID()).compare(username) == 0){
							u[i]->setPurchase(prod);
							if((u[i]->getMembership()).compare("VIP") == 0){
								bala -= 5.0;
							}
							u[i]->setBalance(bala);
							updateUser(u, username, bala, prod);
						}
					}
					
					system("CLS");
					cout << "_____________________________________________" << endl << endl;
					cout << "     Updating your account balance......" << endl;
					cout << "_____________________________________________" << endl;
					sleep(2);

					ok = true;
					
				}else{ cout << "Please choose from the options above: ";	}
					
			}while(!ok);
			
			if(ok){
				success = true;
			}
			
		}
		
		else if(choice[0] == 'b'){
			int countL =0;
			system("CLS");
			cout << "________________________________________________________________" << endl << endl << endl;
			cout << "    Here is the list of all luxury cars we have: " << endl << endl;    
			cout << "________________________________________________________________" << endl << endl << endl;
			for(int i=0; i<v.size(); i++){
				if( (v[i]->getType()).compare("Luxury car") == 0 ){
					countL++;
					cout << " *** Option " << countL << " ***";
					cout << endl;
					v[i]->printIt();
					cout << endl << endl;
				}
					
			}
			cout << "________________________________________________________________" << endl << endl << endl;
					
			bool ok = false;
			int m = 0;
			do{
				cout << "Enter your option number: ";
				cin >> a;
				if(a > 0 && a <= countL){
					system("CLS");
					for(int i=0; i<v.size(); i++){
						if( (v[i]->getType()).compare("Luxury car") == 0){
							m++;
							if( m == a ){
								cout << "_________________________________________________" << endl;
								cout << endl;
								cout << "                You selected: " << endl;
								amount = v[i]->getEffective();
								prod = v[i]->getName();
								v[i]->printIt();
								cout << "_________________________________________________" << endl;
							}
						}
					}
					cout << "How many days would you like to rent? ";
					cin >> day;
					bala = day*amount;
					cout << "Total rental amount: $" << bala << " before membership discount."<< endl;
					sleep(2);
						
					for(int i=0; i<u.size(); i++){
						if( (u[i]->getUID()).compare(username) == 0){
							u[i]->setPurchase(prod);
							if((u[i]->getMembership()).compare("VIP") == 0){
								bala -= 5.0;
							}
							u[i]->setBalance(bala);
							updateUser(u, username, bala, prod);
						}
					}
					
					system("CLS");
					cout << "_____________________________________________" << endl << endl;
					cout << "     Updating your account balance......" << endl;
					cout << "_____________________________________________" << endl;
					sleep(2);

					ok = true;
					
				}else{ cout << "Please choose from the options above: ";	}
				
			}while(!ok);
			
			if(ok){
				success = true;
			}
		}
		
		else if(choice[0] == 'c'){
			success = true;
			system("CLS");
			cout << "         Loading user menu....." << endl;
			sleep(2);
			break;
		}
		else {
			cout << "         Please ENTER one of the options above." << endl;
			sleep(2);
			continue;
		}
		
		
		
		break;
	}while(!success);
	
	return 1;
}

void welcome(){
	
	ifstream inFile ("welcome.txt");         
	string line;
	
	
	if (inFile.is_open()){
	    while ( getline (inFile, line) ){
	      cout << line << '\n';
	    }
	    inFile.close();
	}
	else{cout << "Unable to open file"; } 
	
}

template <typename T, typename Y> bool userMenu(vector<T> &u, vector<Y> &v, string username){
	
	bool logout = false;
	
	do{		//ask user to enter an input until its valid
	
		system("CLS");
		string name, pList;
		double balance;
		
		for(int i=0; i<u.size(); i++){
			if( username.compare(u[i]->getUID()) == 0){
				name = u[i]->getUName();
				balance = u[i]->getBalance();
				pList = u[i]->getPurchase();
			}
		}
		
		cout << "      _____________________________________________" << endl << endl;
		cout << "           Welcome " << name << " !!!" << endl;
		cout << "      _____________________________________________" << endl << endl;
		cout << "            A. Check account balance" << endl;
		cout << "            B. Rent a car" << endl;
		cout << "            C. Rent a motorcycle" << endl << endl;
		cout << "            D. Log out " << endl << endl;
		cout << "      ______________________________________________" << endl << endl;
		cout << "           Enter your selection: ";
		
		string choice, back;
		bool flagBack = false;
		bool flagCar = false;
		bool flagBike = false;
		
		getline(cin, choice);
		choice = removeSpaces(choice);
		
		switch(choice[0]){
			case 'a':
			case 'A':
				system ("CLS");
				cout << "      _____________________________________________" << endl << endl;
				cout << "                      Account information" << endl;
				cout << "      _____________________________________________" << endl << endl;
				cout << "            Full Name: " << name << endl;
				cout << setprecision(2) << fixed << "            Account balance: $" << balance << endl;
				cout << "            Your puchased items: " << pList << endl << endl << endl;
				cout << "         Please empty your account balance by end of every month!!!" << endl;
				cout << "      ______________________________________________" << endl << endl;
				cout << "           Enter \"q\" to go back: "; 
				
				do{
					getline(cin, back);
					if(back.compare("q") == 0 || back.compare("Q") == 0){
						system("CLS");
						flagBack = true;
					}
					else{ 
						cout << " Please Enter \"q or Q\" to go back to your menu: ";
					}
				}while(!flagBack);
				continue;
			case 'b':
			case 'B':
				do{
					system ("CLS");
					if(rentCar(u,v,username)){
						system("CLS");
						flagCar=true;
					}
				}while(!flagCar);		
				continue;
			case 'c':
			case 'C':
				do{
					system ("CLS");
					if(rentBike(u,v,username)){
						system("CLS");
						flagBike=true;
					}
				}while(!flagBike);		
				continue;
			case 'd':
			case 'D':
				logout = true;
				system ("CLS");
				cout << endl << endl << "       Logging out.... ";
				sleep(2);
				break;
			default:
				cout << "           Please ENTER one of the options above." << endl;
				sleep(2);
				continue;
		}
		break;
	}while(!logout);
	
	return 1;
	
}

void findPrefix(string word, int patLength, int prefArray[]) {
   int length = 0;		
   prefArray[0] = 0;     //first place is always 0 as no prefix

   for(int j = 1; j<patLength; j++) {		//j = subtext's last char position(index)     
	    if(word[length] == word[j]) {			//if the chars are same implement both indexes and add length of the Longest proper prefix with is also a suffix
	        length++;
	        prefArray[j] = length;    
	    }
		else{						//if chars are diff, then check the value of variable 'length'. If it is '0' then set LPS[length] = 0 and increment 'j' value by one, if it is not '0' then set length = LPS[length-1].
	        if(length != 0) {
	        length = prefArray[length - 1];
	        j--;     //decrease i to avoid effect of increasing after iteration
	        }
			else{
				prefArray[j] = 0;
			}
	            
	    }
   }
}

int kmpPattSearch(string name, string pattern) {
   int n, m, i = 0, j = 0;
   n = name.size();
   m = pattern.size();
   int prefixArray[m];    //prefix array as same size of searching pattern
   findPrefix(pattern, m, prefixArray);
   int occur = 0;
	
   while(i < n) {
      	if(name[i] == pattern[j]) {
        	i++; j++;
      	}

	    if(j == m) {
	        j = prefixArray[j-1];    //get the prefix length from array
	        occur++;
	    }
		else if(i < n && pattern[j] != name[i]) {	//If mismatch occurred, consider "LPS[j-1]". If its not 0, meaning there are same prefix and it will match for sure; start comparing from the char after the prefix in the pattern with the char mismatched char in the text.
	        if(j != 0)
	        	j = prefixArray[j-1];
	        else
	            i++;
	    }
	}
	return occur;
}

string lowercase(string temp){					//make the text into lowercase
    string toReturn ="";
    for(int i=0; i<temp.size(); i++)
    {
        toReturn += tolower(temp[i]);

    }
    return toReturn;
}

template <typename T> void doIt(vector<T> &u, string patt){
	
	vector<pair<int,User*> > allItems;
	
	string pattern = lowercase(patt);
					
	for (int i = 0; i<u.size(); i++) {
	    string text = u[i]->getPurchase();
	    int occur = 0;
	    text=lowercase(text);
	    occur = kmpPattSearch(text,pattern);
				
		if(occur>0){
			allItems.push_back(make_pair(occur,u[i]));
		}
    }
				    
    sort(allItems.begin(),allItems.end());
	reverse(allItems.begin(),allItems.end());
				    
	if(allItems.size()==0){
		cout<<"---------->No record found!!!"<<endl;
	}
    else{
    	cout<<allItems.size()<< "---------->records found...\n";
	} 
    for(int i=0; i<allItems.size(); i++){
      cout<< i+1 << "). User Full name: " << allItems[i].second->getUName() << "   Purchased product: "<< allItems[i].second->getPurchase() <<" (Number of occurence:  "<< allItems[i].first << ")\n";
    }
}


template <typename T> bool adminMenu(vector<T> &u, string admin){
	
	system("CLS");
	string line, a, b;
	ifstream inFile ("admin.txt");    
		     
	if (inFile.is_open()){
	    while ( getline (inFile, line) ){
	    	stringstream ss(line);
	    	string user, pass, fName, lName;
		    	
	    	ss >> user >> pass >> fName >> lName;
		    	
	    	if( admin.compare(user) == 0){
	    		a = fName;
	    		b = lName;
			}
	    }
	    inFile.close();
	}
	else{cout << "Unable to open file"; } 
	
	bool logout = false;
	
		
	do{		//ask user to enter an input until its valid
		
		system("CLS");
		
		cout << "      __________________________________________________________" << endl << endl;
		cout << "           Welcome " << a << " " << b << " !!!" << endl;
		cout << "      __________________________________________________________" << endl << endl;
		cout << "            A. Print total revenue(Sum of all users balance)" << endl;
		cout << "            B. Search users by their rented car name.(sorted by )" << endl;
		cout << "            C. Check all users' balance" << endl << endl;
		cout << "            D. Log out " << endl << endl;
		cout << "      ___________________________________________________________" << endl << endl;
		cout << "           Enter your selection: ";
		
		string choice, back, backB;
		string pattern, patt;
		string baa;
		int cou = 0;
		bool flagR = false;
		bool flagB = false;
		bool flagBa = false;
		int n = sizeof(u) / sizeof(u[0]);
		
		getline(cin, choice);
		choice = removeSpaces(choice);
		
		cout << endl;
		int tot = 0;
		int num = 0;
		
		switch(choice[0]){
			case 'a':
			case 'A':
				system("CLS");
				for(int i=0; i<u.size(); i++){
					tot += u[i]->getBalance();
					num++;
				}
				cout << "________________________________________________________________________________________" << endl << endl;
				cout << "   There are " << num-1 << " users making totals of $" << tot << " revenue." << endl;
				cout << "________________________________________________________________________________________" << endl << endl;
				cout << " Enter \"b\" to go back: ";
				
				do{
					getline(cin, back);
					if(back.compare("b") == 0 || back.compare("B") == 0){
						system("CLS");
						flagR = true;
					}
					else{ 
						cout << "Please Enter \"b or B\" to go back to your menu: ";
					}
					continue;
				}while(!flagR);
				continue;
			case 'b':
			case 'B':
				system("CLS");
				cout << "______________________________________________________________________________________________" << endl << endl;
				cout << "                              Please enter the search pattern below. " << endl << endl;
				cout << "                      Users\' Rented car names containing your given pattern " <<endl;
				cout << "                     will be printed along with their number of occurence." << endl;
				cout << "                              Following list will be sorted(ascending)  " <<endl;
				cout << "                                    by number of occurences.     " << endl;
				cout << "                      Admin can see what products are most likely to be rented " << endl;
				cout << "______________________________________________________________________________________________" << endl << endl;
				cout << " Enter your search pattern: ";
				do{
					getline(cin, patt);
					doIt(u, patt);
					cout << "Enter any letter to go back: ";
					getline(cin, baa);
					if(baa.compare("^") != 0){
						flagBa = true;
					}
				}while(!flagBa);
				continue;
			case 'c':
			case 'C':
				system("CLS");
				quicksort(u, 0, n - 1); 
				cout << "________________________________________________________________________________________" << endl << endl;
				for(int i=0; i<u.size(); i++){
					cout << "User full name: " << u[i]->getUName() << "    User's account balance: $" << u[i]->getBalance() << endl;
				}
				cout << "________________________________________________________________________________________" << endl << endl;
				cout << " Enter \"b\" to go back: ";
				do{
					getline(cin, backB);
					if(backB.compare("b") == 0 || backB.compare("B") == 0){
						system("CLS");
						flagB = true;
					}
					else{ 
						cout << "Please Enter \"b or B\" to go back to your menu: ";
					}
					continue;
				}while(!flagB);
				continue;
			case 'd':
			case 'D':
				logout = true;
				system ("CLS");
				cout << "       Logging out.... ";
				sleep(2);
				break;
			default:
				cout << "Please ENTER one of the options above." << endl;
				sleep(2);
				continue;
		}
		break;
	}while(!logout);
	
	return 1;
	
}






template <typename T> int partition(vector<T> &Users, int left, int right){	//takes median number as a pivot and find its correct place, then places smaller elements on the left and larger on the right of the pivot
	int pivotIndex = left + (right - left) / 2;		// pivot will be the median  
	double pivotValue = (Users[pivotIndex]->getBalance());		//value of the pivot
	int i = left, j = right;
  	
  	while(i <= j) {						//examine the elements untill the upper and lower bounds crosses
        while((Users[i]->getBalance()) < pivotValue) {		//increase our lower bounds for as long as the value at that index is less than the value of the pivot
            i++;
        }
        while((Users[j]->getBalance()) > pivotValue) {     //decrease the upper bounds index for as long as the value is greater than the pivot value.
            j--;
        }
        if(i <= j) {		//when 2 while loops are done, we will get values to be swapped 
        	T tmp = Users[i];
			Users[i] = Users[j];
			Users[j] = tmp;
            i++;				//check next elements
            j--;
        }
    }
    return i;
}

template <typename T> void quicksort(vector<T> &Users, int left, int right) {
    if(left < right) {				
        int pivotIndex = partition(Users, left, right);	//find new pivotIndex
        quicksort(Users, left, pivotIndex - 1);			//recursively break down the array into smaller parts and swap elements until sorted
        quicksort(Users, pivotIndex, right);
	}
}

int main(){
	
	vector <Division*> Divisions;
	vector <Vehicle*> Vehicles;
	vector <User*> Users;

//Load User datas	
	string line[1024];
	vector<string> temp;
	ifstream file;
	file.open("users.txt");
	string str;
	int i= 0;
	while (getline(file, str)) {
		line[i]=str;
		i++;
	}
	for(int f=0; f<i; f++){
		split(line[f], temp);
		double bala = atof(temp[5].c_str());
		addUsers(Users, temp[0], temp[1], temp[2], temp[3], temp[4], bala, temp[6]);
		temp.clear();
	}
	file.close();
	

//Load Divisions	
	string line1[256];
	vector<string> temp1;
	ifstream file1;
	
	file1.open("divisions.txt");
	string str1;
	int i1= 0;
	while (getline(file1, str1)) {
		line1[i1]=str1;
		i1++;
	}
	for(int f=0; f<i1; f++){
		split(line1[f], temp1);
		if(temp1[0].compare("car") == 0){
			Division* car = new Division(temp1[0], temp1[1]);
			if (car->isUnique(Divisions, *car)) {
		        Divisions.push_back(car);
		    }
		    else {
		        cout << "GUID is not unique for this product: " << car->getName() << endl;
		    }
		}
		if(temp1[0].compare("bike") == 0){
			Division * bike = new Division(temp1[0], temp1[1]);
			if (bike->isUnique(Divisions, *bike)) {
		        Divisions.push_back(bike);
		    }
		    else {
		        cout << "GUID is not unique for this product: " << bike->getName() << endl;
		    }
		}
		temp1.clear();
	}
	file1.close();
	
	Division* car = new Division();
	Division* bike = new Division();
	
//Load vehicles
	string line2[256];
	vector<string> temp2;
	ifstream file2("vehicles.txt");
	
	string str2;
	int i2= 0;
	
	while (getline(file2, str2)) {
		line2[i2]=str2;
		i2++;
	}
	
	
	for(int f=0; f<6; f++){
		split(line2[f], temp2);
		if(temp2[0].compare("luxury") == 0){
			int y = atoi(temp2[5].c_str());
			double pr = atof(temp2[6].c_str());
			int seatN = atoi(temp2[9].c_str());
			double w = atof(temp2[10].c_str());
			double d = atof(temp2[11].c_str());
			addLuxury(Vehicles, temp2[1], temp2[2], car, temp2[4], y, pr, temp2[7], temp2[8], seatN, w, d, temp2[12]);
		}
		else if(temp2[0].compare("performance") == 0){
			int y = atoi(temp2[5].c_str());
			double pr = atof(temp2[6].c_str());
			int seatN = atoi(temp2[9].c_str());
			double w = atof(temp2[10].c_str());
			double d = atof(temp2[11].c_str());
			addPerformance(Vehicles, temp2[1], temp2[2], car, temp2[4], y, pr, temp2[7], temp2[8], seatN, w, d, temp2[12], temp2[13]);
		}
		else if(temp2[0].compare("sports") ==0){
			int y = atoi(temp2[5].c_str());
			double pr = atof(temp2[6].c_str());
			double wSize = atof(temp2[7].c_str());
			int cyl = atoi(temp2[8].c_str());
			double maxS = atof(temp2[10].c_str());
			double d = atof(temp2[11].c_str());
			addSports(Vehicles, temp2[1], temp2[2], bike, temp2[4], y, pr, wSize, cyl, temp2[9], maxS, d, temp2[12], temp2[13]);
		}
		else if(temp2[0].compare("moped") ==0){
			int y = atoi(temp2[5].c_str());
			double pr = atof(temp2[6].c_str());
			double wSize = atof(temp2[7].c_str());
			int cyl = atoi(temp2[8].c_str());
			double maxS = atof(temp2[10].c_str());
			double d = atof(temp2[11].c_str());
			addMoped(Vehicles, temp2[1], temp2[2], bike, temp2[4], y, pr, wSize, cyl, temp2[9], maxS, d, temp2[12]);
		}
		else{
			cout << "Cannot initialize!!!" << endl;
		}
		
	temp2.clear();
	}
	file2.close();
	
	
//Printing Main screen
	
	bool done = false;
//Functioning of the main screen
	do{		//ask user to enter an input until its valid
		
		system("CLS");
		welcome();
		cout << "             Enter your selection: " ;
		
		string user, pass, selection;
		bool flagUser = false;
		bool flagAdmin = false;
		bool regDone = false;
		
		getline(cin, selection);
		selection = removeSpaces(selection);
		
		cout << endl;
		
		switch(selection[0]){
			case 'a':
			case 'A':
				system ("CLS");
				do{
					
					cout << "Enter your username: ";
					cin >> user;
						
					cout << "Enter your password: ";
					cin >> pass;
					
					if(authorizationUser(Users, user, pass)){
						system ("CLS");
						cout << "Successful. Redirecting to User Menu....";
						sleep(2);
						system("CLS");
						if(userMenu(Users, Vehicles, user)){
							system("CLS");
							flagUser = true;
						}
					}else{
						system("CLS");
						cout << "Wrong username/password!!!" << endl;
					}
					
				}while(!flagUser);
				continue;
			case 'b':
			case 'B':
				system ("CLS");
				
				do{
					
					cout << "Enter your username: ";
					cin >> user;
						
					cout << "Enter your password: ";
					cin >> pass;
					
					if(authorization(user, pass)){
						system ("CLS");
						cout << "Successful. Redirecting to Admin Menu....";
						sleep(2);
						system("CLS");
						if(adminMenu(Users, user)){
							system("CLS");
							flagAdmin = true;
						}
					}else{
						system("CLS");
						cout << "Wrong username/password!!!" << endl;
					}
					
				}while(!flagAdmin);
				continue;
			case 'c':
			case 'C':
				do{
					system("CLS");
					if(reg(Users)){
						regDone = true;
					}
				}while(!regDone);
				continue;
			case 'q':
			case 'Q':
				done = true;
				break;
			default:
				cout << "             Please ENTER one of the options above." << endl;
				sleep(2);
				continue;
		}
		break;
	}while(!done);

}
