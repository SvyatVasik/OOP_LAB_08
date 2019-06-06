
//3 лабораторна(Singleton)
/*#include<iostream>
#include<string.h>
using namespace std;
#define Q 100
class BigInt
{

private:
	static BigInt *singleObject;
	static int count;
	int chyslo[Q];
	int quantity;
	BigInt(char *sr) {
		int j, i = 0;
		quantity = strlen(sr);
		for (j = 0; j < quantity; j++, i++)
			chyslo[j] = sr[i] - '0';
		for (; j < Q; j++) chyslo[j] = 0;
		count++;
	}
public:
	static BigInt& getInstance(char* n)
	{
		if (count == 0)
		{
			singleObject = new BigInt(n);
		}
		return *singleObject;
	};
	~BigInt() {}
	int* GetChyslo() { return chyslo; };

	int GetQuanity() { return quantity; };
	void SetQuantity(int a) { quantity = a; };
	void Print() {
		int i = quantity;
		cout <<"\n"<<"Довге ціле число: ";
		while (i > 0) {
			cout<<chyslo[i - 1];
			i--;
		}
		cout<<"\n";
	}
	void Suma(BigInt& ch2, BigInt& ch3) {
		int ch2quantity = ch2.GetQuanity(),ch3quantity = ch3.GetQuanity();
		int *ch2chyslo = ch2.GetChyslo(), *ch3chyslo = ch3.GetChyslo();
		int i, length = ch2quantity + 1;
		if (quantity > ch2quantity)
			length = quantity + 1;
		for (i = length-1; i >= 0; i--)
		{
			*(ch3chyslo + i) += chyslo[i] + *(ch2chyslo + i); //
			*(ch3chyslo + i + 1) += (*(ch3chyslo + i) / 10); //
			*(ch3chyslo + i) %= 10; //
		}
		if (*(ch3chyslo + length - 1) == 0)
			length--;
		ch3.SetQuantity(length);
	}
	int WhichBigger(BigInt& ch2) {
		int ch2quantity = ch2.GetQuanity(), *ch2chyslo = ch2.GetChyslo();
		int k = 3; // 3 - коли однакові числа
		int length = quantity;
		if (quantity > ch2quantity)
		{
			length = quantity;
			k = 1; // 1 число більше
		}
		else
			if (ch2quantity > quantity)
			{
				length = ch2quantity;
				k = 2; // 2 число більше
			}
			else // додаткова перевірка
				for (int i = 0; i < length;)

				{
					if (chyslo[i] > *(ch2chyslo + i))
					{
						k = 1; // 1 число більше
						break; // вихід з фор
					}
					if (*(ch2chyslo + i) > chyslo[i])
					{
						k = 2; // 2 число більше
						break; // вихід з фор
					}
				}
		return k;
	}
	void Difference(BigInt& ch2, BigInt& ch4) { //ch2 - обов'язково менше з чисел
		int *ch2chyslo = ch2.GetChyslo(), *ch4chyslo = ch4.GetChyslo();
		for (int i = 0; i < quantity; i++) // прохід по числах
		{
			if (i < (quantity - 1)) // якщо не перша цифра
			{
				chyslo[i + 1]--; // позичаєм 1
				*(ch4chyslo + i) += 10 + chyslo[i]; // збільшуєм на 10
			}
			else
				*(ch4chyslo + i) += chyslo[i];
			*(ch4chyslo + i) -= *(ch2chyslo + i);
			if (*(ch4chyslo + i) / 10 > 0)
			{
				*(ch4chyslo + i + 1) += 1;
				*(ch4chyslo + i) %= 10;
			}
		}
		ch4.SetQuantity(quantity);
	}
	bool operator >(BigInt& obj);
	BigInt operator +(BigInt& obj);
	friend istream& operator >>(istream& input, BigInt& obj);
	friend ostream& operator <<(ostream& output, BigInt& obj);

};

int BigInt::count = 0;
BigInt* BigInt::singleObject = 0;

ostream& operator <<(ostream& output, BigInt& obj)
{
	int i = 0;
	output <<"\n"<<"Довге ціле число: ";
	while (i < obj.GetQuanity()) {
		output<<obj.chyslo[i];
		i++;
	}
	output<<"\n";
	return output;
}
istream& operator >>(istream& input, BigInt& obj)
{
	printf("\n Введіть довге ціле число: \n");
	char sr[Q];
	input >> sr;
	int j, i = 0;
	obj.quantity = strlen(sr) ;
	for (j = 0; j < obj.quantity; j++,

i++)
		obj.chyslo[j] = sr[i] - '0';
	return input;
}

int main()
{
	system("chcp 1251");
	cout<<"Enter the long number:"<<endl;
	char* numb=new char[Q];
	cin>>numb;
	BigInt& bigInt=BigInt::getInstance(numb);
	cout<<"Enter the long number:"<<endl;
	cin>>numb;
	bigInt=BigInt::getInstance(numb);
	cout<<bigInt;
}*/

/*
//Strategy
#include <iostream>
#include <sstream>
#include <map>

#define COUNT 5

using namespace std;

class Competition;


class InfoStrategy {
public:
	virtual ~InfoStrategy() {}

	virtual void getInfo(Competition obj);
};

class Competition {
private:
	InfoStrategy *infoStrategy;
protected:
	string nameOfCompetition;
	string date;
public:
	const string &getNameOfCompetition() const {
		return nameOfCompetition;
	}

	const string &getDate() const {
		return date;
	}

	Competition() {}

	Competition(string nameOfCompetition, string date) {
		this->nameOfCompetition = nameOfCompetition;
		this->date = date;
	}

	void setInfoStrategy(InfoStrategy *strategy) {
		infoStrategy = strategy;
	}

	virtual string whoWin() {
		return "not example of match class!";
	}

	void getInfo() {
		infoStrategy->getInfo(*this);
	}
};

class Match : public Competition {
public:
	string nameOfFirst;
	int scoreOfFirst;
	string nameOfSecond;
	int scoreOfSecond;
public:
	Match(const string &nameOfCompetition, const string &date, const string &nameOfFirst, int scoreOfFirst,
		  const string &nameOfSecond, int scoreOfSecond);

	string whoWin();
};

class Run : public Competition {
public:
	string loser;
	int scoreOfLoser;
	string winner;
	int scoreOfWinner;

	Run(const string &nameOfCompetition, const string &date, const string &loser, int scoreOfLoser,
		const string &winner, int scoreOfWinner);

	string whoWin();
};

class InfoMatch : public InfoStrategy {
public:
	void getInfo(Match obj) {
		cout << obj.getNameOfCompetition() << " " << obj.getDate() << " " << "MATCH " << obj.nameOfFirst << " "
			 << obj.scoreOfFirst << " " << obj.scoreOfSecond << " " << obj.nameOfSecond << endl;
	}

};

class InfoRun : public InfoStrategy {
public:
	InfoRun() {}

	void getInfo(Run obj) {
		cout << obj.getNameOfCompetition() << " " << obj.getDate() << " " << "RUN " << obj.winner << " "
			 << obj.scoreOfWinner << " " << obj.scoreOfLoser << " " << obj.loser << endl;

	}
};


Match::Match(const string &nameOfCompetition, const string &date, const string &nameOfFirst, int scoreOfFirst,
			 const string &nameOfSecond, int scoreOfSecond) : Competition(nameOfCompetition, date),
															  nameOfFirst(nameOfFirst), scoreOfFirst(scoreOfFirst),
															  nameOfSecond(nameOfSecond), scoreOfSecond(scoreOfSecond) {
	setInfoStrategy(new InfoMatch());
}

string Match::whoWin() {
	if (scoreOfFirst > scoreOfSecond) {
		return nameOfFirst;
	} else if (scoreOfFirst < scoreOfSecond) {
		return nameOfSecond;
	}
	return "noone";
}


Run::Run(const string &nameOfCompetition, const string &date, const string &loser, int scoreOfLoser,
		 const string &winner, int scoreOfWinner) : Competition(nameOfCompetition, date), loser(loser),
													scoreOfLoser(scoreOfLoser), winner(winner),
													scoreOfWinner(scoreOfWinner) {
	setInfoStrategy(new InfoRun());
}

string Run::whoWin() {
	return winner;
}

void countWins(Competition *arrayOfMembers[COUNT], int arrayOfWins[3][3]) {
	for (int i = 0; i < COUNT; i++) {
		string result = arrayOfMembers[i]->whoWin();
		if (result == "TeamLol") {
			arrayOfWins[0][0]++;
		} else if (result == "Oreol") {
			arrayOfWins[1][0]++;
		} else if (result == "Soma") {
			arrayOfWins[2][0]++;
		}
	}
}

void sortSum(int arrayOfWins[3], string arrayOfTeams[3]) {int temp;
	string nameTemp;
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (arrayOfWins[j] > arrayOfWins[j + 1]) {
				temp = arrayOfWins[j];
				arrayOfWins[j] = arrayOfWins[j + 1];
				arrayOfWins[j + 1] = temp;
				nameTemp = arrayOfTeams[j];
				arrayOfTeams[j] = arrayOfTeams[j + 1];
				arrayOfTeams[j + 1] = nameTemp;
			}
		}
	}
}

void printTeams(int arrayOfWins[3], string arrayOfTeams[3]) {
	for (int i = 0; i < 3; i++) {
		cout << arrayOfTeams[i] << " wins -> " << arrayOfWins[i] << endl;
	}
	cout << endl;
}

void printInfo(Competition *arrayOfMembers[COUNT]) {
	cout << "Info about members of competition" << endl;
	for (int i = 0; i < COUNT; i++) {
		arrayOfMembers[i]->getInfo();
	}
	cout << endl;
}

int main() {
	Competition *arrayOfMembers[COUNT];
	arrayOfMembers[0] = new Run("LP 2019", "01.04.2019", "TeamLol", 10, "Oreol", 9);
	arrayOfMembers[1] = new Match("LP 2019", "01.04.2019", "Soma", 10, "Oreol", 4);
	arrayOfMembers[2] = new Run("LP 2019", "01.04.2019", "Soma", 6, "TeamLol", 5);
	arrayOfMembers[3] = new Match("LP 2019", "01.04.2019", "Oreol", 5, "TeamLol", 9);
	arrayOfMembers[4] = new Run("LP 2019", "01.04.2019", "TeamLol", 5, "Oreol", 4);
	printInfo(arrayOfMembers);
	string arrayOfTeams[] = {"TeamLol", "Soma", "Oreol"};
	int arrayOfWins[3] = {0, 0, 0};
	for (int i = 0; i < COUNT; i++) {
		string result = arrayOfMembers[i]->whoWin();
		if (result == arrayOfTeams[0]) { arrayOfWins[0]++; }
		else if (result == arrayOfTeams[1]) { arrayOfWins[1]++; }
		else if (result == arrayOfTeams[2]) { arrayOfWins[2]++; }
	}
	cout << "Before sort" << endl;
	printTeams(arrayOfWins, arrayOfTeams);
	sortSum(arrayOfWins, arrayOfTeams);
	cout << "After sort" << endl;
	printTeams(arrayOfWins, arrayOfTeams);
	system("pause");
	return 0;
}

*/

/*
//6 лабораторна(Iterator)
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class Queue {
private:
	T *queuePointer;
	int size;
	int currentSize;
public:
	friend class QueueIterator;
	Queue(int newsize);
	~Queue();
	int add(T newElement);
	T pop();
	void sum();
	void printQueue();
};

template <class T>
Queue<T>::Queue(int newsize) {
	currentSize = 0;
	queuePointer = new T[size = newsize];
}

template <class T>
Queue<T>::~Queue() {
	delete[] queuePointer;
}

template <class T>
int Queue<T>::add(T newElement) {
	if (currentSize > size - 1) {
		cout << "Queue is full" << endl;
		return 0;
	}
	else {
		for (int i = currentSize; i > 0; i--) {
			queuePointer[i] = queuePointer[i - 1];
		}
		queuePointer[0] = newElement;
		currentSize++;
		return 1;
	}
}

template <class T>
T Queue<T>::pop() {
	T save;
	save = queuePointer[currentSize - 1];
	queuePointer[currentSize - 1] = NULL;
	currentSize--;
	return save;
}

template <>
void Queue<int>::sum() {
	int sum = 0;
	for (int i = 0; i < currentSize; i++) {
		sum += queuePointer[i];
	}
	cout << sum << endl;
}

template <>
void Queue<string>::sum() {
	string sum;
	for (int i = 0; i < currentSize; i++) {
		sum+=queuePointer[i];
	}
	cout << sum << endl;
}

template <class T>
void Queue<T>::printQueue() {
	if (currentSize == 0) {
		cout << "Queue is empty";
	}
	else {
		for (int i = 0; i < currentSize; i++) {
			cout << queuePointer[i] << " ";
		}
	}
	cout << endl;
	return;
}

template <class T>
void fillQueue(Queue<T> *queue) {
	int i;
	cout << "You want add one element to queue(1 - yes)?" << endl;
	cin >> i;
	while (i == 1) {
		cout << "Enter element" << endl;
		T save;
		cin >> save;
		if (queue->add(save) == 0) {
			return;
		}
		cout << "You want add one element to queue(1 - yes)?" << endl; cin >> i;
	}
}

class QueueIterator{
private:
	Queue<int>* q;
	int index = 0;

public:
	QueueIterator(){
		q=NULL;
		index=0;
	}
	QueueIterator(Queue<int>* prg)
	{
		q=prg;
		index = 0;
	}
	void operator++(int)
	{
		index++;
	}
	bool operator()()
	{
		return index != q->size;
	}
	int operator *()
	{
		return q->queuePointer[index];
	}

};

int main() {
	int size;
	cout << "Enter size of int queue" << endl;
	cin >> size;
	Queue<int> *intQueue = new Queue<int>(size);
	fillQueue(intQueue);
	cout << "Int queue:"<<endl;
	QueueIterator iter(intQueue);
	while (iter()) {
		cout<<*iter<<endl;
		iter++;
	}
	system("pause");
	return 0;} */
