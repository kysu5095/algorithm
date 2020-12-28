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
		if      (col == 0) { cout << setw(14) << "�Ķ�"; break; }
		else if (col == 1) { cout << setw(14) << "�ʷ�"; break; }
		else if (col == 2) { cout << setw(14) << "����"; break; }
		else if (col == 3) { cout << setw(14) << "�Ͼ�"; break; }
		else if (col == 4) { cout << setw(14) << "���"; break; }
	case 1:
		if      (col == 0) { cout << setw(14) << "����"; break; }
		else if (col == 1) { cout << setw(14) << "����ũ"; break; }
		else if (col == 2) { cout << setw(14) << "����"; break; }
		else if (col == 3) { cout << setw(14) << "�븣����"; break; }
		else if (col == 4) { cout << setw(14) << "������"; break; }
	case 2:
		if      (col == 0) { cout << setw(14) << "����"; break; }
		else if (col == 1) { cout << setw(14) << "Ŀ��"; break; }
		else if (col == 2) { cout << setw(14) << "����"; break; }
		else if (col == 3) { cout << setw(14) << "��"; break; }
		else if (col == 4) { cout << setw(14) << "��"; break; }
	case 3:
		if      (col == 0) { cout << setw(14) << "��縶����"; break; }
		else if (col == 1) { cout << setw(14) << "����"; break; }
		else if (col == 2) { cout << setw(14) << "�ȸ�"; break; }
		else if (col == 3) { cout << setw(14) << "������"; break; }
		else if (col == 4) { cout << setw(14) << "����"; break; }
	case 4:
		if      (col == 0) { cout << setw(14) << "�����"; break; }
		else if (col == 1) { cout << setw(14) << "��"; break; }
		else if (col == 2) { cout << setw(14) << "������"; break; }
		else if (col == 3) { cout << setw(14) << "�����"; break; }
		else if (col == 4) { cout << setw(14) << "��"; break; }
	}
}