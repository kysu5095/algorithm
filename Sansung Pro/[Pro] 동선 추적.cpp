#include <vector>
#include <math.h>
#include <string.h>
#define MAX_PID  50001
#define MAX_UID  1001
#define MAX_SIZE 10000

using namespace std;

struct NODE {
    int r, c;
    bool visit;
    bool remove;
}node[MAX_PID];

vector<int> visited[MAX_UID];
vector<int> coordinate[4][MAX_SIZE * 2];

void init()
{
    memset(node, 0, sizeof(NODE) * MAX_PID);
    for (int i = 0; i < MAX_UID; i++) visited[i].clear();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < (MAX_SIZE) * 2; j++)
            coordinate[i][j].clear();
}

void addPlace(int pID, int r, int c)
{
    node[pID] = { r, c, false, false };

    coordinate[0][r].push_back(pID);
    coordinate[1][c].push_back(pID);
    coordinate[2][r + c].push_back(pID);
    coordinate[3][r - c + MAX_SIZE].push_back(pID);
}

void removePlace(int pID)
{
    node[pID].remove = true;
}

void contactTracing(int uID, int visitNum, int moveInfo[], int visitList[])
{
    int pid = moveInfo[0];
    int r = node[pid].r;
    int c = node[pid].c;

    visited[uID].push_back(pid);

    for (int i = 1; i < visitNum; i++) {
        int direction = moveInfo[i];
        int distance = MAX_PID;
        int num;

        switch (direction)
        {
        case 0:
            for (auto& it : coordinate[1][c]) {
                if (node[it].r >= r || node[it].visit || node[it].remove) continue;
                if (r - node[it].r < distance) {
                    distance = r - node[it].r;
                    num = it;
                }
            }
            break;

        case 1:
            for (auto& it : coordinate[2][r + c]) {
                if (node[it].c <= c || node[it].visit || node[it].remove) continue;
                if (node[it].c - c < distance) {
                    distance = node[it].c - c;
                    num = it;
                }
            }
            break;

        case 2:
            for (auto& it : coordinate[0][r]) {
                if (node[it].c <= c || node[it].visit || node[it].remove) continue;
                if (node[it].c - c < distance) {
                    distance = node[it].c - c;
                    num = it;
                }
            }
            break;

        case 3:
            for (auto& it : coordinate[3][r - c + MAX_SIZE]) {
                if (node[it].c <= c || node[it].visit || node[it].remove) continue;
                if (node[it].c - c < distance) {
                    distance = node[it].c - c;
                    num = it;
                }
            }
            break;

        case 4:
            for (auto& it : coordinate[1][c]) {
                if (node[it].r <= r || node[it].visit || node[it].remove) continue;
                if (node[it].r - r < distance) {
                    distance = node[it].r - r;
                    num = it;
                }
            }
            break;

        case 5:
            for (auto& it : coordinate[2][r + c]) {
                if (node[it].c >= c || node[it].visit || node[it].remove) continue;
                if (c - node[it].c < distance) {
                    distance = c - node[it].c;
                    num = it;
                }
            }
            break;
        case 6:
            for (auto& it : coordinate[0][r]) {
                if (node[it].c >= c || node[it].visit || node[it].remove) continue;
                if (c - node[it].c < distance) {
                    distance = c - node[it].c;
                    num = it;
                }
            }
            break;

        case 7:
            for (auto& it : coordinate[3][r - c + MAX_SIZE]) {
                if (node[it].c >= c || node[it].visit || node[it].remove) continue;
                if (c - node[it].c < distance) {
                    distance = c - node[it].c;
                    num = it;
                }
            }
            break;
        }

        visited[uID].push_back(num);
        pid = num;
        r = node[pid].r;
        c = node[pid].c;
    }

    int len = visited[uID].size();
    for (int i = 0; i < len; i++) {
        pid = visited[uID][i];

        node[pid].visit = true;
        visitList[i] = pid;
    }
}

void disinfectPlaces(int uID)
{
    int len = visited[uID].size();
    for (int i = 0; i < len; i++) {
        int pid = visited[uID][i];
        node[pid].visit = false;
    }
}