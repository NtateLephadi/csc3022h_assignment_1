/* A scource file that 
 * driver.cpp
 *
 *  Created on: 03 Mar 2018
 *      Author: Tumelo
 */

#include "database.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

	char input;

	std::vector<student_record> students;
	std::string name, surname, student_number, class_record, filename, temp;

	do{
		cout << "0: \t Add student" << endl;
		cout << "1: \t Read database" << endl;
		cout << "2: \t Save database" << endl;
		cout << "3: \t Display given student data" << endl;
		cout << "4: \t Grade Student" << endl;
		cout << "q: \t Quit" << endl;
		cout << "Enter a number (or q to quit) and press return..." << endl;
		cin >> input;

		switch(input){
			case '0':
				cout << "Enter name:" << endl;
				cin >> name;
				cout << "Enter surname:" << endl;
				cin >> surname;
				cout << "Enter student number:" << endl;
				cin >> student_number;
				cout << "Enter class record:" << endl;
				cin >> temp;
				std::getline(cin, class_record);
				class_record = temp + class_record;
				lphtum003::add_student(name, surname, student_number, class_record);
				break;
			case '1':
				lphtum003::read_database(filename);
				break;
			case '2':
				lphtum003::save_database(filename);
				break;
			case '3':
				lphtum003::display_student(student_number);
				break;
			case '4':
				lphtum003::grade_student(student_number);
				break;
			case 'q':
				break;
			default:
				cout << "Invalid entry." << endl;
		}
	}while(input != 'q');

	return 0;
}
