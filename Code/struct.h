#pragma once




struct userMessage
{
	char* content;
	char* sender;
	char* receiver;
	char* date; 
	char* status; 
	userMessage* next;
};

struct user
{
	char* username;
	char* pass;
	char* number;
	char* date;
	user* next;
};

