/*
 * student.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Administrator
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//type definition
struct SData{
	unsigned int ID;
	char Name[40];
	float height;
};

//Linked_list Node
struct Sstudent{
	struct SData Student;
	struct Sstudent* PNext_Student;
};

//APIs
void AddStudent();

int Delete_Student();

void View_Student();

void DeleteALL();

void Get_Number_Node();

#endif /* STUDENT_H_ */
