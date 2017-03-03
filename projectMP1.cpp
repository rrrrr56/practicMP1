#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;
int i;
class BOOK {
protected:
	char name1[300]; char name2[300]; char name3[300]; char nomer[300]; char s1[106];
public:
	virtual void operation(char x) = 0;
};
class CHOOSE {
public:
	char number;
	void chnumber() {
		char oper[300];
		 bool q; do {
		cout << "Ââåäèòå íîìåð îïåðàöèè: ";
		cin.getline(oper, 300);
		if (((int)oper[0] < 49) || ((int)oper[0] > 51) || ((int)oper[1] != '\0'))
		{ cout << "Îøèáêà: íåâåðíàÿ îïåðàöèÿ.\n"; q = false; }
		else q = true;
		} while (q == false);
		number = oper[0];
	}
};
class WRITE : public BOOK {
private:
	bool checkname(const char(&buf1)[300]) {
		int n; bool er1 = true;
		n = strlen(buf1);
		if ((n > 30) || (n == 0)) { cout << "Îøèáêà: íàðóøåíèå äîïóñòèìîé äëèíû ñòðîêè.\n"; return false; }
		if ((((int)buf1[0] < -64) || ((int)buf1[0] > -33)) && ((int)buf1[0] != -88)) { cout << "Îøèáêà: íåïðàâèëüíûé 1-ûé ñèìâîë.\n"; return false; }
		for (i = 1; i <= (n - 1); i++) {
			if ((((int)buf1[i] < -32) || ((int)buf1[i] > -1)) && (buf1[i] != '-') && ((int)buf1[i] != -72))
			{
				er1 = false; break;
			}
		}
		if (er1 == false) { cout << "Îøèáêà: ââîä íåäîïóñòèìûõ ñèìâîëîâ.\n"; return false; }
		return true;
	}
	bool checknomer(const char(&buf2)[300]) {
		int n1; n1 = strlen(buf2); bool er2 = true;
		if (buf2[0] != '8')
		{
			if ((buf2[0] != '+') || (buf2[1] != '7')) { cout << "Îøèáêà: íåïðàâèëüíîå íà÷àëî íîìåðà.\n"; return false; }
		}
		if (((buf2[0] == '8') && (n1 != 11)) || ((buf2[0] == '+') && (buf2[1] == '7') && (n1 != 12)))
		{ cout << "Îøèáêà: íåäîïóñòèìàÿ äëèíà íîìåðà.\n"; return false; }
		for (i = 1; i <= (n1 - 1); i++) {
			if (((int)buf2[i] < 48) || ((int)buf2[i] > 57)) {
				er2 = false; break;
			}
		}
		if (er2 == false) { cout << "Îøèáêà: ââîä íåäîïóñòèìûõ ñèìâîëîâ.\n"; return false; }
		return true;
	}
public:
	void operation(char x) {
		if (x == '1') {
			ofstream fout; fout.open("C:\\spravka.txt", ios::app);
			bool N; 
			do { cout << "Ââåäèòå ôàìèëèþ: ";
				cin.getline(name1, 300);
				OemToAnsi(name1, name1); N = checkname(name1);
			} while (N == false);			
			do { cout << "Ââåäèòå èìÿ: ";
				cin.getline(name2, 300);
				OemToAnsi(name2, name2); N = checkname(name2);
			} while (N == false);			
			do { cout << "Ââåäèòå îò÷åñòâî: ";
				cin.getline(name3, 300);
				OemToAnsi(name3, name3); N = checkname(name3);
			} while (N == false); 
			do { cout << "Ââåäèòå íîìåð òåëåôîíà: "; cin.getline(nomer, 300); N = checknomer(nomer); } while (N == false);
			fout << name1 << ' ' << name2 << ' ' << name3 << ' ' << nomer << "\n";
			fout.close();
		}
	}
};
class READ : public BOOK {
private:
	char s[300];
	bool cheksearch(const char(&buf3)[300]) {
		int n2 = strlen(buf3); bool er3 = true;
		if (n2 > 92) { cout << "Îøèáêà: çàäàí ñëèøêîì äëèííûé çàïðîñ.\n"; return false; }
		if (n2 == 0) { cout << "Îøèáêà: çàäàí ïóñòîé çàïðîñ.\n"; return false; }
		int j = 0; for (i = 0; i <= (n2 - 1); i++) {
			if (buf3[i] == ' ') j += 1;
			if ((((int)buf3[i] < -64) || ((int)buf3[i] > -1)) && ((int)buf3[i] != -88) && ((int)buf3[i] != -72) && ((int)buf3[i] != 32)) {
				er3 = false; break;
			}
		}
		if (er3 == false) { cout << "Îøèáêà: ââîä íåäîïóñòèìûõ ñèìâîëîâ.\n"; return false; }
		if (j == n2) { cout << "Îøèáêà: çàäàí ïóñòîé çàïðîñ.\n"; return false; }
		return true;
		 }
public:
	void operation(char x) {
		if (x == '2') {
			ifstream fin; fin.open("C:\\spravka.txt");
			bool search; 
			do { cout << "Ââåäèòå ïîèñêîâûé çàïðîñ: ";
				cin.getline(s, 300); OemToAnsi(s, s); search = cheksearch(s);
			} while (search == false);
			bool foun = false; while (!fin.eof())
			{
				fin.getline(s1, 106);
				if (strstr(s1, s)) {
					cout << s1 << "\n"; foun = true;
				}
			}
			fin.close();
			if (foun == false) cout << "Ïî Âàøåìó çàïðîñó íå íàø¸ëñÿ íè îäèí êîíòàêò.\n";
		}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Äëÿ çàïèñè íîâîãî êîíòàêòà â ñïðàâî÷íèê ââåäèòå 1.\nÄëÿ íàõîæäåíèÿ êîíòàêòà â ñïðàâî÷íèêå ââåäèòå 2.\nÄëÿ îêîí÷àíèÿ ðàáîòû ñî ñïðàâî÷íèêîì ââåäèòå 3.\n";
	ofstream fout; fout.open("C:\\spravka.txt", ios::app); fout.close();
	CHOOSE z; WRITE x; READ y;
	do {
		z.chnumber();
		x.operation(z.number);
		y.operation(z.number);
	} while (z.number != '3');
	return (0);
}
