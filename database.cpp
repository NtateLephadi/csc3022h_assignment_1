/* A database source file that is able to read or write student's information in a text file
 * database.cpp
 *
 *  Created on: 02 Mar 2018
 *      Author: Tumelo
 */

#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

std::vector<student_record> students;

/*
* add_student() is a void method which adds students to the databse
*/
void lphtum003::add_student(std::string name, std::string surname, std::string student_number, std::string class_record){

	bool existing_student = false;
	
	for(unsigned int i = 0; i < students.size(); i++){
		if (students[i].student_number.compare(student_number) == 0){
			existing_student = true;
			students[i].name = name;
			students[i].surname = surname;
			students[i].student_number = student_number;
			students[i].class_record = class_record;
			break;
		}
	}

	if(!existing_student){
		student_record new_student;

		new_student.name = name;
		new_student.surname = surname;
		new_student.student_number  = student_number;
		new_student.class_record = class_record;
		
		students.push_back(new_student);
	}
}

/*
* read_database() is a void method that is able to read student information from a text file and save it into the database
*/
void lphtum003::read_database(std::string filename){
	cout << "Enter filename:" << endl;
	cin >> filename;

	// Open file with a file stream. ifstream constructor
	// wants a C char * string, so call c_str() method.
	ifstream in(filename.c_str());
	
	if(!in){ 
		cout << "Couldn't open " << filename << endl; 
		in.close();
	}

	else{
		while(!in.eof()){

			string sentence, data_entry;
			std::vector<string> lines;
			student_record new_student;
			
			getline(in, sentence);
			std::istringstream iss(sentence);
			while(std::getline(iss, data_entry, ' ')){
				lines.push_back(data_entry);
	    	}

			for(unsigned int i = 0; i < 3; i++){
				new_student.name = lines[0];
				new_student.surname = lines[1];
				new_student.student_number = lines[2];
			}

			for (unsigned int j = 3; j < lines.size(); j++)
			{
				new_student.class_record = new_student.class_record + lines[j] + " ";
			}

			lphtum003::add_student(new_student.name, new_student.surname, new_student.student_number, new_student.class_record);
		}
	}
}
/*
* save_database is a void method that writes all the information from the database into a textfile
*/
void lphtum003::save_database(std::string filename){
	cout << "Enter filename:" << endl;
	cin >> filename;
	
	ofstream ofs(filename.c_str());

	for (unsigned int i = 0; i < students.size(); i++)
	{
		ofs << students[i].name << " " << students[i].surname << " " << students[i].student_number << " " << students[i].class_record;
		ofs << endl;
	}
}

/*
* display_student is a void method that writes the information of a student with the given student number onto the console
*/
void lphtum003::display_student(std::string student_number){
	cout << "Enter student number:" << endl;
	cin >> student_number;

	bool existing_student = false;

	for(unsigned int i = 0; i < students.size(); i++){
		if(students[i].student_number.compare(student_number) == 0){
			
			existing_student = true;

			cout << students[i].name << " ";
			cout << students[i].surname << " ";
			cout << students[i].student_number << " ";
			cout << students[i].class_record << endl;
		}
	}

	if(!existing_student){
		cout << "Student not found." << endl;
	}
}

/*
* grade_student() is a void method that writes the grade average of a student with the given student number onto the console
*/
void lphtum003::grade_student(std::string student_number){
	cout << "Enter student number:" << endl;
	cin >> student_number;

	bool existing_student = false;

	std::vector<string> grades;
	std::string grade;
	unsigned int sum = 0;
	float average = 0.0; 

	for(unsigned int i = 0; i < students.size(); i++){
		if (students[i].student_number.compare(student_number) == 0){

			existing_student = true;
			
			std::stringstream ss(students[i].class_record);
			while(std::getline(ss, grade, ' ')){
				grades.push_back(grade);
	    	}			
		}
	}

	if(existing_student){
		for(unsigned int i = 0; i < grades.size(); i++){
			sum = stoi(grades[i]) + sum;
		}

		average = sum / static_cast<double>(grades.size());

		printf("The average is: %3.2f \n", average);
	}
	else{
			cout << "Student not found." << endl;	
	}
}
