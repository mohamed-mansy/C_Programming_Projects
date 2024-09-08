/*
 * main.c
 *
 *  Created on: Aug 9, 2024
 *      Author: Administrator
 */

#include "student.h"

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char temp_text[40];

	while(1){
		printf("\n===========================\n");
		printf("\nchoose on of the following options \n");
		printf("\n1: AddStudent ");
		printf("\n2: Delete_Student ");
		printf("\n3: View_Students ");
		printf("\n4: Get_Nth_node ");
		printf("\n5: DeleteALL ");

		printf("\nEnter option number: ");
		gets(temp_text);
		printf("\n===========================\n");

		switch(atoi(temp_text)){
		case 1:
			AddStudent();
			break;

		case 2:
			Delete_Student();
			break;

		case 3:
			View_Student();
			break;

		case 4:
			Get_Number_Node();
			break;

		case 5:
			DeleteALL();
			break;

		default:
			printf("\nwrong option");
			break;

		}

	}


	return 0;
}
