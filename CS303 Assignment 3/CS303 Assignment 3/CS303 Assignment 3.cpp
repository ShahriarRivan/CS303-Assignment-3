
// Name:  Shahriar Rivan

#include <iostream>
#include<queue>
#include <string.h>
#include<string>
#include<map>
#include<iterator>

using namespace std;

void move_to_rear(queue<int> *q);    // Function template for Question 1 of the assignment "move_to_rear" using queue, push, pop, front

bool Palindrome(string word, int start, int end); // Function for Question 2 of the assignment which checks for palindrome

void print(map<string, string> printMap);

void findOnMap(map<string, string> map, string state);

int main()
{
	queue<int> Q;
	int QueueNum, QueueVal, palinSize;
	string option;
	bool error=true, exitProgram=false;
	string palin, find;
	
	
	cout << "Welcome to Assignment 3\nPlease enter the corresponding number of the Problem you wish to check:\n" << endl;
	cout << "1.\t Write a new queue function called move_to_rear that moves the element currently at the front \n\t of the queue to the rear of the queue.The element that was second in line will be the new front\n\t element.Do these using functions push, front, and pop." << endl;
	cout << "\n2.\t As discussed in Chapter 5, a palindrome is a word that reads the same left to right as right\n\t to left.Write a recursive function that determines whether its argument string is a palindrome." << endl;
	cout << "\n5.\t Declare the map container stateDataMap to store pairs of the form (stateName, capitalName),\n\t where stateNameand capitalName are variables of type string :\n\t -- Write C++ statements that\n\t    add the following pairs to stateDataMap : (Nebraska, Lincoln), (New York, Albany), (Ohio, Columbus),\n\t    (California, Sacramento), (Massachusetts, Boston), and (Texas, Austin).\n\t -- Write a C++ method\n\t    that outputs the data stored in stateDataMap.\n\t -- Write a C++ statement that changes the capital\n\t    of California to Los Angeles\n\t -- Write a C++ method that outputs the capitalName using the stateName\n\t    which will be entered by the user." << endl;
	while (exitProgram == false)
	{
		while (error == true)
		{
			cin >> option;
			if (option.length() > 1)
			{
				option[0] = '3';
			}
			if (option[0] == '1' || option[0] == '2' || option[0] == '5' || option[0]=='x' || option[0] == 'X')
			{
				error = false;
			}
			else
			{
				cout << "Invalid input\nTry again!" << endl;
			}
		}

		if (option[0] == '1')
		{
			cout << "Please enter the number of items you want in the queue: ";
			cin >> QueueNum;

			for (int i = 1; i <= QueueNum; i++)
			{
				cout << "Enter position " << i << endl;
				cin >> QueueVal;
				Q.push(QueueVal);
			}
			cout << "The numbers you entered are\nFront: " << Q.front() << "\nBack: " << Q.back() << endl;
			move_to_rear(&Q);
			cout << "\nAfter performing the 'move_to_rear' operation you have\nFront: " << Q.front() << "\nBack: " << Q.back() << endl;
		}
		else if (option[0] == '2')
		{
			cout << "Enter the word you want to check for Palindrome: ";
			cin >> palin;
			palinSize = palin.length();

			if (Palindrome(palin, 0, palinSize - 1) == true)
			{
				cout << palin << " is Palindrome" << endl;
			}
			else
			{
				cout << palin << " is not Palindrome" << endl;
			}
		}
		else if (option[0] == '5')
		{
			string stateName[] = { "Nebraska", "New York","Ohio", "California","Massachusetts", "Texas" };
			string capitalName[] = { "Lincoln","Albany", "Columbus","Sacramento", "Boston","Austin" };

			map<string, string> stateDataMap;
			for (int i = 0; i < 6; i++)
			{
				stateDataMap.insert(pair<string, string>(stateName[i], capitalName[i]));
			}

			cout << "\n\n\nData currently in the system:\n" << endl;
			print(stateDataMap);
			stateDataMap["California"] = "Los Angeles";
			cout << "\n\n\nAfter changing the capital of Californi to Los Angeles\n" << endl;
			print(stateDataMap);

			cout << "\n\nEnter the name of the state you wish to find: ";
			cin >> find;
			find[0] = toupper(find[0]);
			for (int i = 1; i < find.length(); i++)
			{
				find[i] = tolower(find[i]);
			}

			findOnMap(stateDataMap, find);



		}

		if (option[0] != 'X' || option[0] != 'x')
		{
			cout << "\n\n\n\n\nPress X to exit program.\nOR" << endl;
			cout << "If you wish to check another Problem please enter a number again which corresponds with the problem: ";
			cin >> option;
		}
		if (option[0] == 'X' || option[0] == 'x')
		{
			exitProgram = true;
		}
	}
	
	
}

void move_to_rear(queue<int>* q)
{
	int temp;
	temp = q->front();
	q->pop();
	q->push(temp);
}

bool Palindrome(string word, int start, int end)
{
	if (word.length() == 1)
	{
		return true;
	}
	else if (word[start] != word[end])
	{
		return false;
	}
	else if (start < end + 1)
	{
		return Palindrome(word, start + 1, end - 1);
	}
	return true;
}

void print(map<string, string> printMap)
{
	for (auto pair : printMap)
	{
		cout << "\nState   : " << pair.first << "\nCapital : " << pair.second << endl;
	}
}

void findOnMap(map<string, string> map, string state)
{
	if (map.find(state) != map.end())
	{
		cout << "The capital of " << state << " is " << map[state] << endl;
	}
	else
	{
		cout << "\n!***Information for " << state << " is not in our data***!" << endl;
	}
}