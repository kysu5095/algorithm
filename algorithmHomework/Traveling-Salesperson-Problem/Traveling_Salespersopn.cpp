#include "Traveling_Salesperson.h"

vector<int> optTour;

/* create different graphs using user input */
void createRandomMap() {
	/* prepare random */
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 100);
	bool alreadCreate[101] = { false, };
	/* create graph and fill random cost */
	map = new int*[graphSize];
	for (int i = 0; i < graphSize; i++) {
		map[i] = new int[graphSize];
		for (int j = 0; j < graphSize; j++) {
			if (i == j) map[i][j] = 0;
			else {
				while (true) {
					map[i][j] = dis(gen);
					if (!alreadCreate[map[i][j]]) {
						alreadCreate[map[i][j]] = true;
						break;
					}
				}
			}
		}
	}
	/* create dynamic programing table and fill table */
	dp = new int*[graphSize];
	for (int i = 0; i < graphSize; i++) {
		dp[i] = new int[(1 << graphSize) + 1];
		for (int j = 0; j < (1 << graphSize) + 1; j++)
			dp[i][j] = INT_MAX;
	}
}

/* execute best search first version */
void bestFirstSearch(int num) {
	priority_queue<Node> pq;
	vector<int> path;
	path.push_back(0);
	int bound = 0;
	/* textbook version initailize */
	if (num == 1) 
		bound = getLowerBound_textbookVersion(path, 0);
	/* my own version initailize */
	else 
		dp[0][1] = 0;
	pq.push({ 0, bound, 1, path });
	salesPerson(pq, INT_MAX, num);
}

/* start best first search */
void salesPerson(priority_queue<Node>& pq, int minLength, int flag) {
	clock_t start, end;
	generatedNode = 0;
	boundTime = 0;
	boundCnt = 0;
	while (!pq.empty()) {
		/* pop highest priority bound */
		Node node = pq.top();
		int level = node.level;
		int bound = node.bound;
		int visited = node.visited;
		vector<int> path = node.path;
		pq.pop();
		/* check promising */
		if (flag == 1 && bound > minLength) continue;
		if (flag == 0 && bound > dp[path[path.size() - 1]][visited]) continue;

		/* find next city */
		for (int i = 1; i < graphSize; i++) {
			bool find = true;
			for (int j = 1; j < (int)path.size(); j++) 
				if (path[j] == i) {
					find = false;
					break;
				}
			/* when 'i' is not visited */
			if (find) {
				path.push_back(i);
				visited |= (1 << i);
				if (level == graphSize - 2) {
					/* insert last index */
					path.push_back(0);
					if (getLength(path) < minLength) {
						/* update minLength and optTour */
						minLength = getLength(path);
						optTour.clear();
						optTour.resize(path.size());
						copy(path.begin(), path.end(), optTour.begin());
						minDistance = minLength;
					}
				}
				else {
					boundCnt++;
					start = clock();
					if (flag == 1) bound = getLowerBound_textbookVersion(path, level + 1);
					else bound = getLowerBound_myOwnVersion(path, i, visited);
					end = clock();
					boundTime = (double)(end - start);
					if (bound < minLength) {
						pq.push({ level + 1, bound, visited, path });
						generatedNode++;
					}
				}
				/* make previous state */
				path.pop_back();
				visited &= (~(1 << i));
			}
		}
	}
}

/* get lower bound - text book version- */
int getLowerBound_textbookVersion(vector<int>& path, int level) {
	int bound = 0;
	bool* visited = new bool[graphSize];
	memset(visited, false, graphSize);
	/* check visited path */
	for (int i = 0; i < (int)path.size(); i++) visited[path[i]] = true;
	/* the bound recently obtained */
	for (int i = 0; i < level; i++) bound += map[path[i]][path[i + 1]];

	int last_index = path[(int)path.size() - 1];
	for (int row = 0; row < graphSize; row++) {
		if (row != last_index && visited[row]) continue;
		int next = INT_MAX;
		for (int col = 0; col < graphSize; col++) {
			if (row == col) continue;
			/* last index can't go first area */
			if (row == last_index && visited[col]) continue;
			/* already visit area */
			if (col && visited[col]) continue;
			next = min(next, map[row][col]);
		}
		/* get lowest value in row */
		bound += next;
	}
	return bound;
}

/* get lower bound - my own version - */
int getLowerBound_myOwnVersion(vector<int>& path, int index, int visited) {
	int bound = 0;
	int sz = (int)path.size();
	for (int i = 0; i < sz - 1; i++)
		bound += map[path[i]][path[i + 1]];
	/* update bound and path */
	if (bound < dp[index][visited]) 
		dp[index][visited] = bound;
	else bound = INT_MAX;
	return bound;
}

/* get path getLength */
int getLength(vector<int>& path) {
	int len = 0;
	for (int i = 0; i < (int)path.size() - 1; i++)
		len += map[path[i]][path[i + 1]];
	return len;
}

int main() {
	cout << "input graph size(5 to 10) : ";
	cin >> graphSize;
	createRandomMap();
	cout << "======== RANDOM MAP ========\n";
	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}


	clock_t start, end;
	double result;

	cout << "\n======= Textbool Version =======\n";
	start = clock();
	bestFirstSearch(1);
	end = clock();
	result = (double)(end - start);
	cout << "최단 루트 : ";
	for (int i = 0; i < (int)optTour.size(); i++)
		cout << optTour[i] + 1 << " ";
	cout << '\n';
	cout << "최단 거리 : " << minDistance << '\n';
	cout << "생성된 노드 수 : " << generatedNode << '\n';
	cout << "Bound 실행 횟수 : " << boundCnt << '\n';
	cout << "Bound 실행 시간 : " << boundTime << '\n';
	cout << "프로그램 실행시간 : " << result << "ms\n";
	cout << "\n======= My Own Version =======\n";
	start = clock();
	 bestFirstSearch(0);
	end = clock();
	result = (double)(end - start);
	cout << "최단 루트 : ";
	for (int i = 0; i < (int)optTour.size(); i++)
		cout << optTour[i] + 1 << " ";
	cout << '\n';
	cout << "최단 거리 : " << minDistance << '\n';
	cout << "생성된 노드 수 : " << generatedNode << '\n';
	cout << "Bound 실행 횟수 : " << boundCnt << '\n';
	cout << "Bound 실행 시간 : " << boundTime << '\n';
	cout << "프로그램 실행시간 : " << result << "ms\n";
	system("pause");
	return 0;
}