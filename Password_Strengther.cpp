#include <iostream>
#include<string>
#include <regex>
using namespace std;
//initialising names and common passwords
string firstnames[] = { "James", "Kate", "John", "Emily", "Michael", "Olivia", "William", "Sophia", "Benjamin", "Charlotte", "Daniel", "Mia", "Alexander", "Ava", "Henry", "Harper", "Samuel", "Amelia", "Joseph", "Evelyn", "David", "Abigail", "Benjamin", "Sophia", "James", "Emma", "Noah", 
"Isabella", "Jacob", "Olivia", "William", "Ava", "Benjamin", "Mia", "Daniel", "Emily", "Michael", "Charlotte", "Samuel", "Amelia", "Christopher", "Harper", "Andrew", "Abigail", "Joseph", "Sofia", "Thomas", "Ella", "William", "Scarlett", "Samuel", "Lily", "Benjamin", "Grace", "Ethan", "Addison", "Jackson", "Natalie", "Aiden", "Sofia", "Daniel", "Victoria", "Alexander", "Avery", "Joseph", "Zoe", "Jack", "Grace", "Matthew", "Lily", "Gabriel", "Chloe", "Benjamin", "Elizabeth", "Oliver", "Scarlett", "Daniel", "Natalie", "Jackson", "Lucy", "Henry", "Sophie", "Owen", "Zoe", "Ethan", "Lily", "Sebastian", "Ella", "David", "Grace", "James", "Mia", "Christopher", "Harper", "Andrew", "Leah", "Benjamin", "Victoria", "Samuel", "Isabella", "Joseph", "Amelia", "William", "Abigail", "Daniel", "Sofia", "Noah", "Avery", "Emma", "Christopher", "Mia", "Alexander", "Harper", "Ava", "Benjamin", "Charlotte", "William", "Grace", "Daniel", "Lily", "Samuel", "Sophia", "Joseph", "Mia", "Oliver", "Evelyn", "Alexander", "Elizabeth", "William", "Chloe", "Daniel", "Avery" };
string lastnames[] = { "Smith", "Johnson", "Brown", "Davis", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez", "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter", "Mitchell", "Perez", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart", "Sanchez", "Morris", "Rogers", "Reed", "Cook", "Morgan", "Bell", "Murphy", "Bailey", "Rivera", "Cooper", "Richardson", "Cox", "Howard", "Ward", "Torres", "Peterson",
"Gray", "Ramirez", "James", "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", "Henderson", "Coleman", "Jenkins", "Perry", "Powell", "Long", "Patterson", "Hughes", "Flores", "Washington", "Butler", "Simmons", "Foster", "Gonzales", "Bryant", "Alexander", "Russell", "Griffin", "Diaz", "Hayes", "Myers" };
string commonpasswords[] = { "password", "123456", "123456789", "12345678", "12345", "1234567", "1234567890", "qwerty", "abc123", "password1", "admin", "letmein", "welcome", "monkey", "sunshine", "password123", "123123", "iloveyou", "football", "admin123", "letmein123", "1234", "iloveyou1", "123456a", "welcome1", "trustno1", "password!", "qwerty123", "admin1234", "123321", "shadow", "starwars", "1234abcd", "qwertyuiop", "password2", "123456789a", "princess", "football1", "baseball", "superman", "12345a", "michael", "dragon", "1qaz2wsx", "121212", "superman1", "password1234", "batman", "master", "123qwe", "123abc", "111111", 
"123456789abc", "summer", "solo", "chocolate", "password12", "justin", "letmein1", "123", "orange", "shadow1", "pokemon", "qwerty1234", "12345678910", "loveme", "password12345", "qazwsx", "mustang", "access", "killer", "welcome123", "trustno1!", "123654", "test", "abc1234", "charlie", "pokemon1", "qwert", "george", "1q2w3e4r", "superman123", "1234567a", "maggie", "merlin", "harley", "gandalf", "chicken", "password123!", "qwertyu", "letmein1234", "babygirl", "tigger", "password!123", "banana", "daniel", "1234abcd!" };
void checkpassword(string psswd)
{
	int counter = 0;
	//used to count how many characters in the password
	int charactercount = psswd.length();
	if (psswd.length() > 11)
		counter += 2;
	else if (psswd.length() > 7)
		counter++;
	//used for checking if there is an uppercase or lowercase letter 
	bool iscapital = false;
	bool issmall = false;
	for (char character : psswd)
	{
		if (isupper(character))
		{
			iscapital = true;
			counter++;
			break;
		}
	}
	for (char character : psswd)
		if (islower(character))
		{
			issmall = true;
			counter++;
			break;
		}
	
	//used to check if there is a digit included in the password
	bool hasnumber = false;
	for (char character : psswd)
	{
		if (isdigit(character))
		{
			hasnumber = true;
			counter++;
			break;
		}
	}
	//used for checking for special character
	bool hasspecial = false;
	for (char character : psswd)
	{
		if (!isalnum(character))
		{
			hasspecial = true;
			counter++;
			break;
		}
	}
	//used for checking identical characters
	bool identical = false;
	for (int i = 0; i < charactercount; i++)
		if (psswd[i] == psswd[i + 1] && psswd[i] == psswd[i + 2])
			identical = true;
	if (!identical)
		counter++;
	//used for checking if there is an email address entered
	bool hasemailaddress = false;
	regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}\b)");
	if (regex_search(psswd, emailPattern))
		hasemailaddress = true;
	if (!hasemailaddress)
		counter++;
	//used for checking if a first or last name being used
	bool firstname = false;
	bool lastname = false;
	for (int i = 0; i < 100; i++)
	{
		if (psswd == firstnames[i])
			firstname = true;
		if (psswd == lastnames[i])
			lastname = true;
	}
	if (!firstname)
		counter++;
	if (!lastname)
		counter++;
	//used to check if a common passwords is used 
	bool commonpass = false;
	for (int i = 0; i < 10; i++)
		if (psswd == commonpasswords[i])
			commonpass = true;
	if (!commonpass)
		counter++;
	//now the program will calculate the score of the password entered
	if (psswd.length() < 8)
		cout << "Very weak password , it is less than 8 characters\n";
	else if (counter <= 8 )
		cout << "Weak Passsword\n";
	else if (counter <= 10)
		cout << "Strong Password\n";
	else
		cout << "Very Strong password\n";
	if (psswd.length() > 7 && psswd.length() < 12)
		cout << "You should use a password with at least 12 characters\n";
	if (!iscapital)
		cout << "You should use a capital letter\n";
	if (!issmall)
		cout << "You should use a small letter\n";
	if (!hasnumber)
		cout << "You should use a number\n";
	if (!hasspecial)
		cout << "You should use a special character\n";
	if (identical)
		cout << "You should not write more than two identical letters in a row\n";
	if (hasemailaddress)
		cout << "You should not write an email address in the password\n";
	if (firstname || lastname)
		cout << "You should not write your first or last name\n";
	if (commonpass)
		cout << "You should not write a common password\n";
}
int main()
{
	cout << "Enter your passsword please\n";
	string password;
	cin >> password;
	checkpassword(password);
}
