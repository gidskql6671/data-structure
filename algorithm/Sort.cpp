/* Sorting Algorithm�� ���� */

template <typename T>
bool defaultCompare(T a, T b);


template <typename T> 
void insertionSort(T arr[], int n, bool (*compare)(T, T) = defaultCompare);

template <typename T> 
void selectionSort(T arr[], int n, bool (*compare)(T, T) = defaultCompare);




// �⺻ �� �Լ�
template <typename T>
bool defaultCompare(T a, T b){
    return a <= b;
}

// Insertion Sort�� ����
// T arr[] : ������ 1���� �迭
// int n : �迭 �� ������ ����
// bool (*compare)(T, T) : ���Ҹ� �����ִ� �� �Լ� 
template <typename T> 
void insertionSort(T arr[], int n, bool (*compare)(T, T)){
    // arr[0] ~ arr[0] ������ ���Ұ� �Ѱ��̹Ƿ� �翬�� ���ĵ� ����. �� �ε��� 1���� ����
    for(int i = 1; i < n; i++){
        T key = arr[i];
        int j;
        
        // arr[0:i]�� ���ĵǾ��ִ� ������. �� i-1���� �������� �����ϸ�
        // key���� ���� ���� ������ ���� �ڿ� key���� �־� ��.
        for(j = i - 1; j >= 0 && compare(key, arr[j]); j--)
            arr[j+1] = arr[j];
        
        arr[j+1] = key; // key���� ���� ���� ������ ���� �ڿ� key�� �־���.
    }
}

// Selection Sort�� ����
// T arr[] : ������ 1���� �迭
// int n : �迭 �� ������ ����
// bool (*compare)(T, T) : ���Ҹ� �����ִ� �� �Լ� 
template <typename T> 
void selectionSort(T arr[], int n, bool (*compare)(T, T)){
    for(int i = 0; i < n; i++){
        int minIdx = i;
        
        for(int j = i + 1; j < n; j++)
            if (compare(arr[j], arr[minIdx]))
                minIdx = j;
        
        if (i != minIdx){
            T tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}