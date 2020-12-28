#include "Einstein-Problem.h"

void execute() {
	backtracking(0, 0, 0, 0);
}

static int  cnt = 0;
void backtracking(const int row, const int col, const int pre_row, const int pre_col) {
	cnt++;
	/* termination condition */
	if (row == SIZE) {
		cout << "=============================FIND SOLUTION============================\n";
		for (int i = 0; i < SIZE; i++) 
			cout << setw(13) << "HOUSE " << i;
		cout << '\n';
		cout.setf(ios::right);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) 
				print(i, house[j].get(i));
			cout << '\n';
		}
		cout << "\n찾은 노드 수 : " << cnt << '\n';
		return;
	}
	/* check promising */
	if (promising(pre_row, pre_col)) {
		/* already initialized */
		if (house[col].get(row) != INT_MAX) {
			if (col + 1 == SIZE) backtracking(row + 1, 0, row, col);
			else backtracking(row, col + 1, row, col);
		}
		else {
			for (int idx = 0; idx < SIZE; idx++) {
				if (!used[row][idx]) {
					used[row][idx] = true;
					house[col].set(row, idx);
					if (col + 1 == SIZE) backtracking(row + 1, 0, row, col);
					else backtracking(row, col + 1, row, col);
					used[row][idx] = false;
					house[col].set(row, INT_MAX);
				}
			}
		}
	}
}

bool promising(const int row, const int col) {
	switch (row)
	{
	/* color check */
	case COLOR:
		/* 4. The green house is on the left of the white house (next to it) */
		if (house[col].get(COLOR) == GREEN) {
			if (col == SIZE - 1) return false;
			if (house[col + 1].get(COLOR) != INT_MAX && house[col + 1].get(COLOR) != WHITE) return false;
		}
		if (house[col].get(COLOR) == WHITE) {
			if (col == 0) return false;
			if (house[col - 1].get(COLOR) != INT_MAX && house[col - 1].get(COLOR) != GREEN) return false;
		}
		break;
	/* nation check */
	case NATION:
		/* 1. The Brit lives in a red house */
		if (house[col].get(NATION) == BRIT && house[col].get(COLOR) != RED) return false;
		if (house[col].get(COLOR) == RED  && house[col].get(NATION) != BRIT) return false;
		/* 9. The Norwegian lives in the first house */
		if (house[col].get(NATION) == NORWEGIAN && col != 0) return false;
		if (col == 0 && house[col].get(NATION) != NORWEGIAN) return false;
		/* 14. The Norwegian lives next to the blue house */
		if (house[col].get(NATION) == NORWEGIAN && col == 0 && house[col + 1].get(COLOR) != BLUE) return false;
		if (col == 1 && house[col].get(COLOR) == BLUE && house[col - 1].get(NATION) != NORWEGIAN) return false;
		break;
	/* beverage check */
	case BEVERAGE:
		/* 3. The Dane drinks tea */
		if (house[col].get(BEVERAGE) == TEA  && house[col].get(NATION) != DANE) return false;
		if (house[col].get(NATION) == DANE && house[col].get(BEVERAGE) != TEA) return false;
		/* 5. The green house owner drinks coffee */
		if (house[col].get(BEVERAGE) == COFFEE && house[col].get(COLOR) != GREEN) return false;
		if (house[col].get(COLOR) == GREEN  && house[col].get(BEVERAGE) != COFFEE) return false;
		/* 8. The man living in the house right in the center drinks milk */
		if (house[col].get(BEVERAGE) == MILK && col != 2) return false;
		if (col == 2 && house[col].get(BEVERAGE) != MILK) return false;
		break;
	/* cigar check */
	case CIGAR:
		/* 7. The owner of the yellow house smokes Dunhill */
		if (house[col].get(CIGAR) == DUNHILL && house[col].get(COLOR) != YELLOW) return false;
		if (house[col].get(COLOR) == YELLOW  && house[col].get(CIGAR) != DUNHILL) return false;
		/* 12. The owner who smokes Blue Master drinks beer */
		if (house[col].get(CIGAR) == BLUE_MASTER && house[col].get(BEVERAGE) != BEER) return false;
		if (house[col].get(BEVERAGE) == BEER && house[col].get(CIGAR) != BLUE_MASTER) return false;
		/* 13. The German smokes Prince */
		if (house[col].get(CIGAR) == PRINCE && house[col].get(NATION) != GERMAN) return false;
		if (house[col].get(NATION) == GERMAN && house[col].get(CIGAR) != PRINCE) return false;
		/* 15. The man who smokes Blend has a neighbor who drinks water */
		if (house[col].get(CIGAR) == BLEND) {
			if (col == 0 && house[col + 1].get(BEVERAGE) != WATER) return false;
			if (col > 0 && col < SIZE - 1) {
				if (house[col + 1].get(BEVERAGE) == WATER) break;
				else if (house[col - 1].get(BEVERAGE) == WATER) break;
				else return false;
			}
			if (col == SIZE - 1 && house[col - 1].get(BEVERAGE) != WATER) return false;
		}
		break;
	/* pet check */
	case PET:
		/* 2. The Swede keeps dogs as pets */
		if (house[col].get(PET) == DOG   && house[col].get(NATION) != SWEDE) return false;
		if (house[col].get(NATION) == SWEDE && house[col].get(PET) != DOG) return false;
		/* 6. The person who smokes Pall Mall rears birds */
		if (house[col].get(PET) == BIRD && house[col].get(CIGAR) != PALL_MALL) return false;
		if (house[col].get(CIGAR) == PALL_MALL && house[col].get(PET) != BIRD) return false;
		/* 10. The man who smokes Blend lives next to the one who keeps cats */
		if (house[col].get(PET) == CAT) {
			if (col == 0 && house[col + 1].get(CIGAR) != BLEND) return false;
			if (col > 0 && col < SIZE - 1) {
				if (house[col + 1].get(CIGAR) == BLEND) break;
				else if (house[col - 1].get(CIGAR) == BLEND) break;
				else return false;
			}
			if (col == SIZE - 1 && house[col - 1].get(CIGAR) != BLEND) return false;
		}
		/* 11. The man who keeps horses lives next to the man who smokes Dunhill */
		if (house[col].get(PET) == HORSE) {
			if (col == 0 && house[col + 1].get(CIGAR) != DUNHILL) return false;
			if (col > 0 && col < SIZE - 1) {
				if (house[col + 1].get(CIGAR) == DUNHILL) break;
				else if (house[col - 1].get(CIGAR) == DUNHILL) break;
				else return false;
			}
			if (col == SIZE - 1 && house[col - 1].get(CIGAR) != DUNHILL) return false;
		}
		break;
	}
	return true;
}