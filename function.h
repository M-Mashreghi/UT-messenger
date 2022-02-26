#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#include "../../struct.h"
using namespace std;

#define numbermax 12


#define zero 0
#define one 1
#define two 2
#define True 1
#define False 0
#define firstvalue 5

void adduserr(char* Username, char* Password, char* PhoneNum, user* contact);
int phonenumberchecker(char* phonenumber);
int passwordchecker(char* pass);
void passchange(user* neww);
void adduser(user* head, user* neww);
void showunreadmessage(user* neww, userMessage* messagehead);
void freerammessage(userMessage* messagehead);
void freeramuser(user* head);
void changeusername(user* head, user* neww);
void about(user* head);
void info(user* head);
int PhoneNumCheckforsignup(user* head, char* phone);
int usernameCheckforsignup(user* head, char* NewUser);
void loginmenu(user* head, user* neww, userMessage* messagehead);
void sendmessage(user* head, user* neww, userMessage* messagehead);
int checkreciverexists(user* head, char* reciver);
int findusernameforlogin1(char* Username, char* Password, user* head);
void addmessage(userMessage* messagehead, userMessage* message);
void showsentmssage(user* neww, userMessage* messagehead);
void showreceivedmessage(user* neww, userMessage* messagehead);
struct user* findusernameforlogin(char* Username, user* head);
void savemessage(userMessage* messagehead);
void addmssage(char* text, char* reciver, char* sender, userMessage* message);
void saveuser(user* head);







#endif // !FUNCTION_H