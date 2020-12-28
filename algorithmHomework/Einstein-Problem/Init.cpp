#include "Einstein-Problem.h"

void House::set(int row, int value) {
	switch (row)
	{
	case COLOR:    this->color    = value; break;
	case NATION:   this->nation   = value; break; 
	case BEVERAGE: this->beverage = value; break;
	case CIGAR:    this->cigar    = value; break;
	case PET:      this->pet      = value; break;
	}
}

int House::get(int row) {
	switch (row)
	{
	case COLOR:    return this->color;
	case NATION:   return this->nation;
	case BEVERAGE: return this->beverage;
	case CIGAR:    return this->cigar;
	case PET:      return this->pet;
	}
}

void print(const int row, const int col) {
	switch (row)
	{
	case 0:
		if      (col == 0) { cout << setw(14) << "파랑"; break; }
		else if (col == 1) { cout << setw(14) << "초록"; break; }
		else if (col == 2) { cout << setw(14) << "빨강"; break; }
		else if (col == 3) { cout << setw(14) << "하양"; break; }
		else if (col == 4) { cout << setw(14) << "노랑"; break; }
	case 1:
		if      (col == 0) { cout << setw(14) << "영국"; break; }
		else if (col == 1) { cout << setw(14) << "덴마크"; break; }
		else if (col == 2) { cout << setw(14) << "독일"; break; }
		else if (col == 3) { cout << setw(14) << "노르웨이"; break; }
		else if (col == 4) { cout << setw(14) << "스웨덴"; break; }
	case 2:
		if      (col == 0) { cout << setw(14) << "맥주"; break; }
		else if (col == 1) { cout << setw(14) << "커피"; break; }
		else if (col == 2) { cout << setw(14) << "우유"; break; }
		else if (col == 3) { cout << setw(14) << "차"; break; }
		else if (col == 4) { cout << setw(14) << "물"; break; }
	case 3:
		if      (col == 0) { cout << setw(14) << "블루마스터"; break; }
		else if (col == 1) { cout << setw(14) << "던힐"; break; }
		else if (col == 2) { cout << setw(14) << "팔말"; break; }
		else if (col == 3) { cout << setw(14) << "프린스"; break; }
		else if (col == 4) { cout << setw(14) << "블랜드"; break; }
	case 4:
		if      (col == 0) { cout << setw(14) << "고양이"; break; }
		else if (col == 1) { cout << setw(14) << "새"; break; }
		else if (col == 2) { cout << setw(14) << "강아지"; break; }
		else if (col == 3) { cout << setw(14) << "물고기"; break; }
		else if (col == 4) { cout << setw(14) << "말"; break; }
	}
}