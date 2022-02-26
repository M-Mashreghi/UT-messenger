#define _CRT_SECURE_NO_WARNINGS
#include"struct.h"
#include"function.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#include "ConsoleApplication1/ConsoleApplication1/function.cpp"

using namespace std;

#define zero 0
#define one 1
#define two 2
#define True 1
#define False 0
#define firstvalue 5

int main()
{
	user* head = (struct user*)malloc(sizeof(user));
	head->next = NULL;
	userMessage* messagehead = (struct userMessage*)malloc(sizeof(userMessage));
	messagehead->next = NULL;

	while (true)
	{
		printf("Welcome to UT Messenger\nPls enter your command\n>>");
		int a = firstvalue, b = firstvalue, flag = firstvalue;
		char* CMD = (char*)malloc(sizeof(char));
		char c;
		int i = zero;
		while (true)
		{
			c = getchar();
			CMD[i] = c;
			if (c == '\n') {
				flag = two;
				break;
			}
			if (c == ' ') {
				flag = one;
				break;
			}
			i++;
			CMD = (char*)realloc(CMD, (i + one) * sizeof(char));
		}
		CMD[i] = '\0';
		if (flag == one) {
			if (strcmp(CMD, "signup") == zero)
			{
				char* Username = (char*)malloc(sizeof(char));char* Password = (char*)malloc(sizeof(char));char* PhoneNum = (char*)malloc(sizeof(char));
				free(CMD);
				i = zero;

				while ((c = getchar()) != ' ')
				{

					if (c == '\n') {
						system("cls");
						printf("t\terror....\n\t\tyou didn't type correct\n");
						a = one;
						break;
					}
					Username[i] = c;
					i++;
					Username = (char*)realloc(Username, (i + one) * sizeof(char));
				}
				Username[i] = '\0';
				if (a == one) {
					continue;
				}
				int j = zero;
				while ((c = getchar()) != ' ')
				{
					if (c == '\n') {
						system("cls");
						printf("\t\terror....\n\t\tyou didn't type correct\n");
						a = one;
						break;
					}
					Password[j] = c;
					j++;
					Password = (char*)realloc(Password, (j + one) * sizeof(char));
				}
				Password[j] = '\0';


				int z = zero;
				while ((c = getchar()) != '\n')
				{
					PhoneNum[z] = c;
					z++;
					PhoneNum = (char*)realloc(PhoneNum, (z + one) * sizeof(char));
				}
				PhoneNum[z] = '\0'; 
				if (phonenumberchecker(PhoneNum) && passwordchecker(Password) && usernameCheckforsignup(head, Username) && PhoneNumCheckforsignup(head, PhoneNum))
				{
					user* usersign = (user*)malloc(sizeof(user));
					adduserr(Username, Password, PhoneNum, usersign);
					adduser(head, usersign);
					loginmenu(head, usersign, messagehead);
				}
				else {
					free(Username);free(Password);free(PhoneNum);
				}
			}
			else if (strcmp(CMD, "login") == zero)
			{
				char* Username = (char*)malloc(sizeof(char));char* Password = (char*)malloc(sizeof(char));free(CMD);
				i = zero;
				while ((c = getchar()) != ' ')
				{

					if (c == '\n') {
						system("cls");
						printf("t\terror....\n\t\tyou didn't type correct\n");
						a = one;
						break;
					}
					Username[i] = c;
					i++;
					Username = (char*)realloc(Username, (i + one) * sizeof(char));
				}
				Username[i] = '\0';
				if (a == one) {
					continue;
				}
				int j = zero;
				while ((c = getchar()) != '\n')
				{
					Password[j] = c;
					j++;
					Password = (char*)realloc(Password, (j + one) * sizeof(char));
				}
				Password[j] = '\0';
				
				struct user *pass;
				pass = findusernameforlogin(Username, head);
				if (findusernameforlogin1(Username, Password, head)) {
					loginmenu(head, pass, messagehead);
				}
			}
			else {
				system("cls");
				printf("\t\tNot recognize\n");
			}
		}
		if (flag == two) {
			if (strcmp(CMD, "close") == zero) {
				saveuser(head);
				savemessage(messagehead);
				freeramuser(head);
				freerammessage(messagehead);
				return 1;
			}
			else {
				system("cls");
				printf("\t\tNot recognize\n");
			}
		}
	}
}









