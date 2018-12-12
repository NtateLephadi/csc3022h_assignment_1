/* A database header file that stores student information
 * database.h
 *  	
 *  Created on: 02 Mar 2018
 *      Author: Tumelo
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <vector>
#include <cstdlib>

/*
* A student record structure that stores student information
*/
struct student_record{
	std::string name;
	std::string surname;
	std::string student_number;
	std::string class_record; 
};

extern std::vector<student_record> students;

/*
* A namespace that contains the declaration of all the database functions
*/
namespace lphtum003{

	void add_student(std::string name, std::string surname, std::string student_number, std::string class_record);
	void read_database(std::string filename);
	void save_database(std::string filename);
	void display_student(std::string student_number);
	void grade_student(std::string student_number);
}

#endif /* DATABASE_H_ */
