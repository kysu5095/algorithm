#include <string>
#include <string.h>
#include <unordered_map>
#define MAX_ITEM  30001
#define MAX_PRICE 300000000

using namespace std;

int idx, tag_idx;
int product[MAX_ITEM][2];
unordered_map<string, int>  ttoh;

void init(int N)
{
	idx = 0;
	tag_idx = 0;
	memset(product, 0, sizeof(product));
	ttoh.clear();
}

void addProduct(int mPrice, int tagNum, char tagName[][10])
{
	product[idx][0] = mPrice;
	for (int i = 0; i < tagNum; i++) {
		if (ttoh.count(string(tagName[i])) == 0) 
			ttoh[string(tagName[i])] = tag_idx++;

		product[idx][1] += (1 << ttoh[string(tagName[i])]);
	}
	idx++;
}

int buyProduct(char tag1[], char tag2[], char tag3[])
{
	if (ttoh.count(string(tag1)) == 0) return -1;
	if (ttoh.count(string(tag2)) == 0) return -1;
	if (ttoh.count(string(tag3)) == 0) return -1;
	int t1 = ttoh[string(tag1)];
	int t2 = ttoh[string(tag2)];
	int t3 = ttoh[string(tag3)];

	int p_idx = 0;
	int p_price = MAX_PRICE;
	for (register int i = 0; i < idx; i++) {
		if ((product[i][1] & (1 << t1)) == 0) continue;
		if ((product[i][1] & (1 << t2)) == 0) continue;
		if ((product[i][1] & (1 << t3)) == 0) continue;
		if (product[i][0] < p_price) {
			p_idx = i;
			p_price = product[i][0];
		}
	}
	if (p_price == MAX_PRICE) return -1;
	product[p_idx][1] = 0;
	return p_price;
}

void adjustPrice(char tag1[], int changePrice)
{
	int t1 = ttoh[string(tag1)];
	for (register int i = 0; i < idx; i++) {
		if ((product[i][1] & (1 << t1)) == 0) continue;
		product[i][0] += changePrice;
	}
}