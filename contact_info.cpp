/*
Joe Hollon
Costumer Data - Revised
Cis 1202 Chapter 11
June-15-18
*/
#include<iostream>
#include<string>
//want mess with the ones below
#include<stdio.h>
#include<cstring>


using namespace std;


//put structs here/////////////////////////////////////////////
struct address {
	//put street, city, state, zip
	char w_street[100];
	string w_city;
	string w_state;
	int w_zip;
	////home details/////////////
	char h_street[100];
	string h_city;
	string h_state;
	int h_zip;
};
struct costumer {
	//put last name, first name
	char first_name[50];
	char last_name[50];
};


//put prototypes here///////////////////////////////////////////better for functions if struct are before loads var in first
int view_menu(int user_choice);
int costumer_get(costumer name[], address area[], int data_counter);//only need deref in prototypes
void display_info(costumer name[] , address area[], int data_counter );
void search_name(costumer name[], address area[], int data_counter);

int data_counter = 0;//if declare the var here and get rid of const int size it becomes a dynamic array well kind of 
//i just set the array of structures to something really big so it will be awhile till it hits the end

int main() {
	int user_choice = 0;//menu item choice

	//const int size = 2;//i cant change this if i do 3 
	//int size = 1;//has to == to the amount of data taken in 

	costumer name[963];//goes to the costumer struct//set to big number, so user wont run into the end of the array for awhile 
	address area[963];//goes to address struct//i like numbers that can be divided by 3 :}

	user_choice = view_menu(user_choice);//set user choice to view menu result

	while (user_choice < 4) {//where user wants to go

		if (user_choice == 1) {//first choice
			//cout << "user input" << endl;
			data_counter = costumer_get(name, area, data_counter);
			//get_address(area);
			user_choice = view_menu(user_choice);
		}
		else if (user_choice == 2) {//second choice
			//cout << "display info" << endl;
			display_info(name, area, data_counter);
			user_choice = view_menu(user_choice);
		}
		else if (user_choice == 3) {//thrid choice
			//cout << "search database" << endl;
			search_name(name, area, data_counter);
			user_choice = view_menu(user_choice);
		}
		else {
			exit(0);
		}
	}
	

	system("pause");
	return 0;
}
int view_menu(int user_choice) {
	

		cout << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << "X Costumer Contacts menu X" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;
		printf("Select for the following Menu\n\n");
		printf("1: Enter new costumer\n");
		printf("2: Display all costumers\n");
		printf("3: search a patricular name\n");
		printf("4: Exit program\n");

		printf("Enter choice: ");
		cin >> user_choice;
		
		return user_choice;
}

int costumer_get(costumer name[], address area[], int data_counter){
	//cin.ignore();//put cin.ignore() before both string, edit... once before all...//dumb i spent to long to figure out 

	
	char data_entry = 'y';

	do {
		cout << endl;
		cout << "Custmer " << data_counter + 1 << endl;
		cin.ignore();//put cin.ignore() before both string, edit... once before all...//dumb i spent to long to figure out 
		cout << "Enter Customer First Name: ";
		cin.getline(name[data_counter].first_name, 50);////
										                   //costumer input
		cout << "Enter Customer Last name: ";             //
		cin.getline(name[data_counter].last_name, 50);//

		cout << endl;

		//work address///////////////////////////////
		cout << "Enter Work Street address: ";
		cin.getline(area[data_counter].w_street, 100);

		cout << "Enter Work City: ";
		getline(cin, area[data_counter].w_city);

		cout << "Enter Work State: ";              
		getline(cin, area[data_counter].w_state);

		cout << "Enter Work Zip-Code: ";
		cin >> area[data_counter].w_zip;
		///////////////////////////////////////////////

		cout << endl;

		//home address////////////////////////////////
		cin.ignore();
		cout << "Enter Home Street address: ";
		cin.getline(area[data_counter].h_street, 100);

		cout << "Enter Home City: ";
		getline(cin, area[data_counter].h_city);

		cout << "Enter Home State: ";
		getline(cin, area[data_counter].h_state);

		cout << "Enter Home Zip-Code: ";
		cin >> area[data_counter].h_zip;
		//////////////////////////////////////////////

		cout << endl;
		cout << "Would you like to add another entry? ";
		cin >> data_entry;
		cout << endl;

		data_counter++;

	} while (data_entry == 'y');
	
	return data_counter;//returns loop counter dosnt nessarly work the way i want 
}


void display_info(costumer name[], address area[], int data_counter){//out-put data 

	cout << endl;

	for (int i = 0; i < data_counter; i++) {//changed to data counter
		//displays first and last name////////////////////////////////
		cout << "Customer " << i + 1 << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << "first name: " << name[i].first_name << endl;
		cout << "Last name: " << name[i].last_name << endl;
		cout << endl;
		//display home details////////////////////////////////////////
		//cout << "Work address below " << endl;
		cout << "Work Street: " << area[i].w_street << endl;
		cout << "Work City: " << area[i].w_city << endl;
		cout << "Work State: " << area[i].w_state << endl;
		cout << "work Zip-Code: " << area[i].w_zip << endl;
		cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
		//display home details////////////////////////////////////////
		//cout << "Home address below: " << endl;
		cout << "Home Street: " << area[i].h_street << endl;
		cout << "Home City: " << area[i].h_city << endl;
		cout << "Home State: " << area[i].h_state << endl;
		cout << "Home Zip-Code: " << area[i].h_zip << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << endl;

		
		
	}
}
void search_name(costumer name[], address area[], int data_counter) {//searching for name and out-put data

	char search_first_name[50];//char needed for strcmp
	char search_last_name[50];//

	cin.ignore();

	cout << endl;

	cout << "The number of items in the database is " << data_counter;

	cout << endl;

	cout << "Enter targets first name: ";//input name that you are searching for 
	cin.getline(search_first_name, 50);//
	cout << "enter targets last name: ";//
	cin.getline(search_last_name, 50);//

	cout << endl;

	for (int i = 0; i < data_counter; i++) {//changed to data counter data_counter = 'const int size = 2'; 
		if (strcmp(name[i].first_name, search_first_name) == 0) {//comparing first name
			if (strcmp(name[i].last_name, search_last_name) == 0) {//comparing last name 

				//so when it finds the search name "i" becomes the the matching struct array output
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
				cout << "You found a match, here are the results" << endl << endl;
				cout << "client information for " << name[i].first_name << " " << name[i].last_name << endl;
				cout <<"Work Address: "<< area[i].w_street << endl;
				cout <<"Work City:"<< area[i].w_city << endl;
				cout <<"Work State: "<< area[i].w_state << endl;
				cout <<"Work Zip: "<< area[i].w_zip << endl;
				cout <<"Home Address: "<< area[i].h_street << endl;
				cout <<"Home City: "<< area[i].h_city << endl;
				cout <<"Home State: "<< area[i].h_state << endl;
				cout <<"Home Zip: "<< area[i].h_zip << endl;
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;
			}
			else {
				cout << "No match " << endl << endl;
			}
		}
	}
}