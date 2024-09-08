/*
 * student.c
 *
 *  Created on: Aug 8, 2024
 *      Author: Administrator
 */

#include "student.h"

struct Sstudent *gpFirstStudent = NULL;

void AddStudent()
{
	struct Sstudent *PNewStudent;
	struct Sstudent *PLastStudent;
	char temp_text[40];
	//check the list is empty ==Yes
	if(gpFirstStudent == NULL)
	{
		//create new record
		PNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
		//assign the gpFirstStudent to NewStudent
		gpFirstStudent = PNewStudent;
	}
	else //the list contains record
	{
		//Navigate until reach to the last record
		PLastStudent = gpFirstStudent;
		while(PLastStudent->PNext_Student){
			PLastStudent = PLastStudent->PNext_Student;
		}
			//create new record
			PNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
			//assign the PLastStudent to NewStudent
			PLastStudent->PNext_Student = PNewStudent;
	}

	//fill the record data
	printf("\nEnter the ID: ");
	gets(temp_text);
	PNewStudent->Student.ID = atoi(temp_text);

	printf("\nEnter Student Full Name: ");
	gets(PNewStudent->Student.Name);

	printf("\nEnter the Height: ");
	gets(temp_text);
	PNewStudent->Student.height = atof(temp_text);

	//set the NewStudent record to NULL
	PNewStudent->PNext_Student = NULL;
}

int Delete_Student()
{
	//Get selected ID from user
	char temp_text[30];
	unsigned int selected_ID;
	printf("Enter the selected student ID to be deleted: ");
	gets(temp_text);
	selected_ID = atoi(temp_text);

	if(gpFirstStudent){

		struct Sstudent *selectedStudent = gpFirstStudent;
		struct Sstudent *previousStudent = NULL;
		//loop on all records starting of gpFirstStudent
		while(selectedStudent){
			//compare the record ID with selected ID
			if(selectedStudent->Student.ID == selected_ID)
			{
				if(previousStudent)
				{
					previousStudent->PNext_Student = selectedStudent->PNext_Student;
				}else
				{
					gpFirstStudent = selectedStudent->PNext_Student;
				}
				free(selectedStudent);
				return 1;
			}
			previousStudent = selectedStudent;
			selectedStudent=selectedStudent->PNext_Student;

		}
	}
	printf("\ncannot find student ID");
	return 0;

}

void View_Student()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	unsigned int count = 0;
	if(gpFirstStudent == NULL)
		{printf("\nEmpty list");}

		while(currentStudent){
			printf("\nRecord number: %d", count+1);
			printf("\n \tstudent ID: %d", currentStudent->Student.ID);
			printf("\n \tstudent Name: %s", currentStudent->Student.Name);
			printf("\n \tstudent Height: %f", currentStudent->Student.height);
			currentStudent = currentStudent->PNext_Student;
			count++;
		}

}

void DeleteALL()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		printf("Empty list");
	}else
	{
		while(currentStudent){
			struct Sstudent *tempStudent = currentStudent;
			currentStudent = currentStudent->PNext_Student;
			free(tempStudent);
		}
		gpFirstStudent = NULL;
	}

}

void Get_Number_Node()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	unsigned int count = 0, index;
	printf("Enter the index position\n");
	scanf("%d", &index);

	if(gpFirstStudent == NULL)
		{
			printf("Empty list");
		}else
		{
			while(currentStudent){
				if(count == index)
					printf("%d", currentStudent->Student.ID);
			}
			count++;
			currentStudent = currentStudent->PNext_Student;
		}

}




