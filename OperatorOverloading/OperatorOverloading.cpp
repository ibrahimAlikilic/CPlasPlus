#include <iostream>
#include <string>
#include<list>
#include<math.h>

using namespace std;

void Operation();
int SelectOperatipn();
char Again();

int counter = 0;
bool chackSame;
float ReelCout[2];
float VisualCout[2];

class ComplexNumber {
private:
	float real;
	float visual;
public:
	ComplexNumber(float real, float visual) {
		this->real = real;
		this->visual = visual;
	}
	void print() {
		cout << real << " + " << visual << "i" << endl;
		//Down for Polar Form :
		//Length:
		float squareReal = pow(real, 2);
		float squarevisual = pow(visual, 2);
		float plus = squareReal + squarevisual;
		float squareroot = sqrt(plus);
		//Angle:
		const double PI = 3.14159265;
		float tanangle = (visual / real);
		float radyan = atan(tanangle);
		float angle = radyan * 180.0 / PI;
		cout << "Polar Form is :" << squareroot << " X cis" << angle << endl;
	}
	ComplexNumber operator+ (ComplexNumber comNum) {
		ComplexNumber complexNumbers3(0, 0);
		complexNumbers3.real = this->real + comNum.real;
		complexNumbers3.visual = this->visual + comNum.visual;
		return complexNumbers3;
	}
	ComplexNumber operator- (ComplexNumber comNum) {
		ComplexNumber complexNumbers3(0, 0);
		complexNumbers3.real = this->real - comNum.real;
		complexNumbers3.visual = this->visual - comNum.visual;
		return complexNumbers3;
	}
	ComplexNumber operator* (ComplexNumber comNum) {
		ComplexNumber complexNumbers3(0, 0);
		complexNumbers3.real = this->real * comNum.real;
		complexNumbers3.visual = this->visual * comNum.visual;
		return complexNumbers3;
	}
	ComplexNumber operator/ (ComplexNumber comNum) {
		ComplexNumber complexNumbers3(0, 0);
		complexNumbers3.real = this->real / comNum.real;
		complexNumbers3.visual = this->visual / comNum.visual;
		return complexNumbers3;
	}
	bool operator ==( ComplexNumber cumNum) {
		if (this->real == cumNum.real && this->visual == cumNum.visual) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const ComplexNumber& cumNum) const {
		return this->real == cumNum.real && this->visual == cumNum.visual;
	}
	list<ComplexNumber>complexNumberAdd;

	void operator+=(ComplexNumber& cumNum) {
		this->complexNumberAdd.push_back(cumNum);
	}
	void operator-=(ComplexNumber& cumNum) {
		this->complexNumberAdd.remove(cumNum);
	}
	void operator*=(ComplexNumber& cumNum) {
		this->complexNumberAdd.push_back(cumNum);
	}
	void operator/=(ComplexNumber& cumNum) {
		this->complexNumberAdd.push_back(cumNum);
	}
};
ostream& operator <<(ostream& COUT, ComplexNumber& cumNum) {
	COUT << ReelCout[counter] << " + (";
	COUT << VisualCout[counter] << "i) ";
	counter++;
	return COUT;
}
int main() {
	char GoOrBr;
	bool chack;
	bool TWChack=true;
	do
	{
		Operation();
		int want = SelectOperatipn();
		if (want == 1 || want == 2 || want == 3 || want == 4 || want == 5 || want == 6 || want == 7 || want == 8 || want == 9) {}//For chack want value
		else {
			while (TWChack)
			{
				system("cls");
				cout << "You get in rong value please enter value again" << endl;
				Operation();
				want = SelectOperatipn();
				if (want == 1 || want == 2 || want == 3 || want == 4 || want == 5 || want == 6 || want == 7 || want == 8 || want == 9)
					TWChack = false;
			}
		}
		ComplexNumber complexNumbers1(ReelCout[0], VisualCout[0]);
		ComplexNumber complexNumbers2(ReelCout[1], VisualCout[1]);
		if (want == 1) {
			ComplexNumber complexNumbers3 = complexNumbers1 + complexNumbers2;
			complexNumbers3.print();
		}
		else if (want == 2) {
			ComplexNumber complexNumbers3 = complexNumbers1 - complexNumbers2;
			complexNumbers3.print();
		}
		else if (want == 3) {
			ComplexNumber complexNumbers3 = complexNumbers1 * complexNumbers2;
			complexNumbers3.print();
		}
		else if (want == 4) {
			ComplexNumber complexNumbers3 = complexNumbers1 / complexNumbers2;
			complexNumbers3.print();
		}
		else if (want == 5) {
			ComplexNumber complexNumbers3 = complexNumbers1 + complexNumbers2;
			complexNumbers3 += complexNumbers3;
			complexNumbers3.print();
		}
		else if (want == 6) {
			ComplexNumber complexNumbers3 = complexNumbers1 - complexNumbers2;
			complexNumbers3 -= complexNumbers3;
			complexNumbers3.print();
		}
		else if (want == 7) {
			ComplexNumber complexNumbers3 = complexNumbers1 * complexNumbers2;
			complexNumbers3 *= complexNumbers3;
			complexNumbers3.print();
		}
		else if (want == 8) {
			ComplexNumber complexNumbers3 = complexNumbers1 / complexNumbers2;
			complexNumbers3 /= complexNumbers3;
			complexNumbers3.print();
		}
		else if (want == 9) {
			if (complexNumbers1 == complexNumbers2) {
				cout << " " << complexNumbers1 << " and " << complexNumbers2 << "are equal" << endl;
				counter = 0;
			}
			else {
				cout << " " << complexNumbers1 << " and " << complexNumbers2 << "are not equal" << endl;
				counter = 0;

			}
		}
			
		GoOrBr = Again();
		if (GoOrBr == 'G' || GoOrBr == 'g') {
			chack = true;
			system("cls");
		}
		else
			chack = false;
	} while (chack);
	return EXIT_SUCCESS;
}
void Operation() {
	cout << "Plese select the want mathematical operation ." << endl;
	cout << "1: + operation " << endl;
	cout << "2: - operation " << endl;
	cout << "3: X operation " << endl;
	cout << "4: / operation " << endl;
	cout << "5: += operation " << endl;
	cout << "6: -= operation " << endl;
	cout << "7: *= operation " << endl;
	cout << "8: /= operation " << endl;
	cout << "9: == operation " << endl;
}
int SelectOperatipn() {
	int want;
	cout << "Plese press the want mathematical operation number : "; cin >> want; cout << endl;
	system("cls");
	if (want == 1 || want == 2 || want == 3 || want == 4 || want == 5 || want == 6 || want == 7 || want == 8 || want == 9) {
		for (int i = 0; i < 2; i++) {
			cout << "Please enter the " << i + 1 << " values of the 1st class reel number : "; cin >> ReelCout[i]; cout << endl;
			cout << "Please enter the " << i + 1 << " values of the 1st class visual number : "; cin >> VisualCout[i]; cout << endl;
		}
	}
	return want;
}
char Again() {
	char GoBr;
	cout << "Will you go on ?" << endl << "If will you go on please key in G or g from keyboard" << endl << "If won't you go on please key in any button from keyboard ." << endl << "Key in :"; cin >> GoBr;
	return GoBr;
}