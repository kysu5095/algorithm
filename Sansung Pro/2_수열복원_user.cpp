///===== user.cpp =====

extern int orderCheck(int left, int right);

const int LM = (int)1e5 + 5;
int index[LM], trr[LM];

void mergeSort(int* arr, int s, int e) {
    if (s >= e) return;

    int m = (s + e) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);

    int i = s, j = m + 1, k = s;
    while (i <= m && j <= e) {
        if (orderCheck(arr[i], arr[j])) trr[k++] = arr[i++];
        else trr[k++] = arr[j++];
    }

    while (i <= m) trr[k++] = arr[i++];
    while (j <= e) trr[k++] = arr[j++];

    for (int i = s; i <= e; i++)
        arr[i] = trr[i];
}

void array_restore(int arrCount, int dat[]) {
    // implement here
    for (int i = 0; i < arrCount; i++) index[i] = i;
    mergeSort(index, 0, arrCount - 1);
    for (int i = 0; i < arrCount; i++) dat[index[i]] = i + 1;
}