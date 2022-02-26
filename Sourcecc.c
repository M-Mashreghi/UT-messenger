#define _CRT_SECURE_NO_WARNINGS
#include"struct.h"
#include"function.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>

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
				char* Username = (char*)malloc(sizeof(char)); char* Password = (char*)malloc(sizeof(char)); char* PhoneNum = (char*)malloc(sizeof(char));
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
					free(Username); free(Password); free(PhoneNum);
				}
			}
			else if (strcmp(CMD, "login") == zero)
			{
				char* Username = (char*)malloc(sizeof(char)); char* Password = (char*)malloc(sizeof(char)); free(CMD);
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

				struct user* pass;
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
int phonenumberchecker(char* phonenumber) {
	if (phonenumber[zero] != '0')
	{
		printf("the number should start with zero\n");
		return zero;
	}
	int i = zero;
	while (phonenumber[i] != '\0') {
		if (phonenumber[i] < '0' || phonenumber[i] > '9') {
			printf("the numbers aren't clear\n");
			return zero;
		}
		i++;
	}
	if (i != 11) {
		printf("the number should be 11 char not more or less\n");
		return zero;
	}
	return one;
}
int passwordchecker(char* pass) {
	if (strlen(pass) < 6) {
		printf("ur password are less then 6 char\nu must enter more than 6 char\n");
		return zero;
	}
	return one;
}
void loginmenu(user* head, user* neww, userMessage* messagehead) {
	char c; int i, a, flag;
	while (one) {
		showunreadmessage(neww, messagehead);
		printf("login menu\n>>");
		i = zero; a = zero; flag = zero;
		char* loginCMD = (char*)malloc(sizeof(char));
		while ((c = getchar()) != '\t')
		{
			loginCMD[i] = c;
			if (c == '\n') {
				flag = one;
				break;
			}
			if (c == ' ') {
				flag = two;
				break;
			}
			i++;
			loginCMD = (char*)realloc(loginCMD, (i + one) * sizeof(char));
		}
		loginCMD[i] = '\0';

		if (flag == one) {
			if (strcmp(loginCMD, "logout") == zero) {
				printf("logout succusfull\n");
				break;
			}
			if (strcmp(loginCMD, "info") == zero) {
				info(head);
			}
			else if (strcmp(loginCMD, "close") == zero) {
				saveuser(head);
				savemessage(messagehead);
				freeramuser(head);
				freerammessage(messagehead);
			}
			else {
				printf("not recognize\npls try again\n");
			}
			free(loginCMD);
			continue;
		}
		else if (flag == two) {
			if (strcmp(loginCMD, "show_received") == zero) {
				showreceivedmessage(neww, messagehead);
			}
			else if (strcmp(loginCMD, "edit_username") == zero) {
				changeusername(head, neww);
			}
			else if (strcmp(loginCMD, "edit_pass") == zero) {
				passchange(neww);
			}
			else if (strcmp(loginCMD, "show_sent") == zero) {
				showsentmssage(neww, messagehead);
			}
			else if (strcmp(loginCMD, "sent") == zero) {
				sendmessage(head, neww, messagehead);
			}
			else if (strcmp(loginCMD, "about") == zero) {
				about(head);
			}
			else {
				printf("not recognize the order\npls try again\n>>");
			}
			free(loginCMD);
			continue;
		}
		else {
			printf("not recognize\npls try again\n>>");
			free(loginCMD);
			continue;
		}

	}
}
void adduser(user* head, user* neww)
{
	user* now = head->next;
	user* pre = head;
	int i = zero;
	while (now != NULL)
	{
		pre = now;
		now = now->next;
		i++;
	}
	pre->next = neww;
	neww->next = NULL;
	return;
}
void passchange(user* neww) {
	int a = zero, j = zero; char c;
	char* Password = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n')
	{
		if (c == ' ') {
			printf("t\terror....\n\t\tyou didn't type correct\n");
			a = one;
			break;
		}
		Password[j] = c;
		j++;
		Password = (char*)realloc(Password, (j + one) * sizeof(char));
	}
	Password[j] = '\0';
	if (a == zero && passwordchecker(Password)) {
		free(neww->pass);
		neww->pass = (char*)malloc((j + one) * sizeof(char));
		strcpy(neww->pass, Password);
		free(Password);
		printf("\t\tpassword have been changed succesfully\n");
	}
	else {
		printf("\t\tpassword couldn't change succesfully\n");
		free(Password);
	}
}
void changeusername(user* head, user* neww) {
	int a = zero, i = zero, j = zero, b = zero; char c; char* Username;
	Username = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			printf("t\terror....\n\t\tyou didn't type correct\n");
			a = one;
		}
		Username[i] = c;
		i++;
		Username = (char*)realloc(Username, (i + one) * sizeof(char));
	}
	Username[i] = '\0';
	struct user* current = head->next;
	while (current != NULL)
	{
		if (strcmp(current->username, Username) == zero) b++;
		current = current->next;
	}
	if (a == zero && b == zero) {
		free(neww->username);
		neww->username = (char*)malloc((j + one) * sizeof(char));
		strcpy(neww->username, Username);
		free(Username);
		printf("username changed succusfull\n");

	}
	else {
		free(Username);
		printf("the order was succesfully\n");
		if (b != zero)printf("username was repeated\n");
	}
}
void about(user* head) {
	int a = zero, i = zero, b = zero; char c;
	char* Username = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			printf("t\terror....\n\t\tyou didn't type correct\n");
			a = one;
		}
		Username[i] = c;
		i++;
		Username = (char*)realloc(Username, (i + one) * sizeof(char));
	}
	Username[i] = '\0';

	if (a == zero) {
		struct user* current = head->next;
		while (current != NULL)
		{
			if (strcmp(current->username, Username) == zero) {
				printf("\t\tits username = %s\n\t\tits phonenumber = %s\n\t\tthe time he signed up at %s", current->username, current->number, current->date);	free(Username); b = one;
				break;
			}
			current = current->next;
		}
	}
	else {
		printf("\t\terror\n\t\tu didnt type correctly\n");
		free(Username);

	}
	if (b == one) {
		printf("\tno one found with names u search\n");

	}
}
void info(user* head) {
	int i = one;
	struct user* current = head->next;
	while (current != NULL)
	{
		if (i == one)printf("\tthe users of messenger:\n");
		printf("\t\t%d.%s\n", i, current->username); i++;
		current = current->next;
	}
	printf("finished\n");
}
int checkreciverexists(user* head, char* reciver) {
	struct user* current = head->next;
	while (current != NULL)
	{
		if (strcmp(reciver, current->username) == zero)
			return zero;
		current = current->next;
	}
	system("cls");
	printf("the user doesn't exist");
	return one;
}
void addmessage(userMessage* messagehead, userMessage* message) {
	userMessage* now = messagehead->next;
	userMessage* pre = messagehead;
	while (now != NULL)
	{
		pre = now;
		now = now->next;
	}
	pre->next = message;
	message->next = NULL;
}
int findusernameforlogin1(char* Username, char* Password, user* head) {
	struct user* current = head->next;
	while (current != NULL)
	{

		if (strcmp(current->username, Username) == zero)
			if (strcmp(current->pass, Password) == zero)
				return one;
			else printf("\t\tpassword is incorrect\n");

		current = current->next;
	}
	printf("\t\tuser didn't find\n");
	return zero;
}
void sendmessage(user* head, user* neww, userMessage* messagehead) {
	char c; int a = zero, i = zero, z = zero, b = zero;
	char* reciver = (char*)malloc(sizeof(char));
	char* text = (char*)malloc(sizeof(char));
	while ((c = getchar()) != ' ')
	{
		reciver[i] = c;
		if (c == '\n') {
			system("cls");
			printf("t\terror....\n\t\tyou didn't type correct\n");
			a = one;
			break;
		}
		i++;
		reciver = (char*)realloc(reciver, (i + one) * sizeof(char));
	}
	reciver[i] = '\0';
	while ((c = getchar()) != '\n')
	{
		text[z] = c;
		z++;
		text = (char*)realloc(text, (z + one) * sizeof(char));
	}
	text[z] = '\0';
	b = checkreciverexists(head, reciver);
	printf("hi");
	if (a == zero && b == zero) {
		userMessage* message = (userMessage*)malloc(sizeof(userMessage));
		addmssage(text, reciver, neww->username, message);
		addmessage(messagehead, message);
		printf("\t\t message has been send successfull\n");
	}
	else {
		free(reciver); free(text);
		system("cls");
		printf("\t\terror... .\t\tNot recognize\n\n");
	}
}
void showsentmssage(user* neww, userMessage* messagehead) {
	char c;
	int z = zero, i = zero;
	char* reciv = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n')
	{
		reciv[z] = c;
		z++;
		reciv = (char*)realloc(reciv, (z + one) * sizeof(char));
	}
	reciv[z] = '\0';
	struct userMessage* current = messagehead->next;
	while (current != NULL)
	{
		if (strcmp(current->receiver, reciv) == zero && strcmp(neww->username, current->sender) == zero) {
			printf("a message have been send to %s and the text is( %s )\nand it send in %s", current->receiver, current->content, current->date);
			i++;
		}
		current = current->next;
	}
	free(reciv);
	if (i == zero) {
		printf("\tu didn't save any message\n");
	}



}
void showreceivedmessage(user* neww, userMessage* messagehead) {
	char c; int z = zero, i = zero; char* sender = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n')
	{
		sender[z] = c;
		z++;
		sender = (char*)realloc(sender, (z + one) * sizeof(char));
	}
	sender[z] = '\0';

	struct userMessage* current = messagehead->next;
	while (current != NULL)
	{
		if (strcmp(current->sender, sender) == zero && strcmp(neww->username, current->receiver) == zero) {
			i++;
			if (strcmp(current->status, "0") == zero) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("\t\ta message from %s to %s and the text is( %s )\n\t\tand it send in %s", current->sender, current->receiver, current->content, current->date);
				strcpy(current->status, "1");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("\t\ta message from %s to %s and the text is( %s )\n\t\tand it send in %s", current->sender, current->receiver, current->content, current->date);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}

		}
		current = current->next;
	}
	free(sender);
	if (i == zero) {
		printf("\tno message were found\n");
	}
}
struct user* findusernameforlogin(char* Username, user* head) {
	struct user* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(Username, cur->username) == zero)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
int usernameCheckforsignup(user* head, char* NewUser)
{
	user* curr = head->next;
	while (curr != NULL)
	{
		if (strcmp(NewUser, curr->username) == zero)
		{
			printf("Username has already exist . Try login or adifferent Username\n");
			return zero;
		}
		curr = curr->next;
	}
	return one;
}
int PhoneNumCheckforsignup(user* head, char* phone)
{
	user* curr = head->next;
	while (curr != NULL)
	{
		if (strcmp(phone, curr->number) == zero)
		{
			printf("Phone number has already exist . Try login or adifferent phone number\n");
			return zero;
		}
		curr = curr->next;
	}
	return one;
}
void savemessage(userMessage* messagehead) {
	FILE* message;
	message = fopen("messag.txt", "w+");
	struct userMessage* curr = messagehead->next;
	while (curr != NULL)
	{
		fprintf(message, "message from %s to %s and the text is  %s  and time= %s", curr->sender, curr->receiver, curr->content, curr->date);
		curr = curr->next;
	}
	fclose(message);
}
void freerammessage(userMessage* messagehead)
{
	struct userMessage* curr = messagehead->next;
	struct userMessage* pre = messagehead;
	while (curr != NULL)
	{
		free(curr->content);
		free(curr->sender);
		free(curr->status);
		free(curr->receiver);
		free(curr->date);
		free(curr);
		pre = curr;
		curr = curr->next;
	}
	free(messagehead->next);
}
void freeramuser(user* head) {
	struct user* curr = head->next;
	struct user* pre = head;
	while (curr != NULL)
	{
		free(curr->pass);
		free(curr->date);
		free(curr->number);
		free(curr->username);
		free(curr);
		pre = curr;
		curr = curr->next;
	}
	free(head);
}
void adduserr(char* Username, char* Password, char* PhoneNum, user* usersign) {
	usersign->username = (char*)malloc((strlen(Username) + one) * sizeof(char));
	usersign->pass = (char*)malloc((strlen(Password) + one) * sizeof(char));
	usersign->number = (char*)malloc((strlen(PhoneNum) + one) * sizeof(char));
	strcpy(usersign->username, Username);
	strcpy(usersign->pass, Password);
	strcpy(usersign->number, PhoneNum);
	free(Username);
	free(Password);
	free(PhoneNum);
	time_t now;
	time(&now);
	char* t = ctime(&now);
	usersign->date = (char*)malloc((strlen(t) + 1) * sizeof(char));
	strcpy(usersign->date, t);
	printf("it was succufull\n");
}
void showunreadmessage(user* neww, userMessage* messagehead) {
	struct userMessage* current = messagehead->next;
	while (current != NULL)
	{
		if (strcmp(current->status, "0") == zero && strcmp(neww->username, current->receiver) == zero) {
			printf("\t\tan unread message from %s\n\t\tand it send in %s", current->sender, current->date);
		}
		current = current->next;
	}
}
void addmssage(char* contect, char* reciver, char* sender, userMessage* message) {
	message->receiver = (char*)malloc((strlen(contect) + one) * sizeof(char));
	message->content = (char*)malloc((strlen(reciver) + one) * sizeof(char));
	message->sender = (char*)malloc((strlen(sender) + one) * sizeof(char));
	strcpy(message->receiver, reciver);
	strcpy(message->sender, sender);
	strcpy(message->content, contect);
	message->status = (char*)malloc(1 * sizeof(char));
	strcpy(message->status, "0");
	time_t nw;
	time(&nw);
	char* now = ctime(&nw);
	message->date = (char*)malloc((strlen(now) + 1) * sizeof(char));
	strcpy(message->date, now);
	free(reciver);
	free(contect);

}
void saveuser(user* head) {
	FILE* users;
	users = fopen("users.txt", "w+");
	struct user* current = head->next;
	while (current != NULL)
	{
		fprintf(users, "username = %s , phonenumber = %s ,password = %s , time of signup = %s ", current->username, current->number, current->pass, current->date);
		current = current->next;
	}
	fclose(users);

}
