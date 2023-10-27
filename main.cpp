#include <iostream>
#include <vector>
#include <cstdlib>
 #include <ctime>
using namespace std;

vector<int> generarNumerosAleatorios(int tam) {
    std::vector<int> numerosAleatorios;
    for (int i = 0; i < tam; i++) {
        numerosAleatorios.push_back(rand()%1000);
    }
    return numerosAleatorios;
}
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    int aux;
    for (int i=0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
}
void insertionSort(vector<int>&arr) {
    int n=arr.size();
    for (int i = 1; i < n; i++) {
        int aux = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = aux;
    }
}

void selectionSort(vector<int>&arr) {
    int n=arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//

void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortHelper(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void mergeSort(vector<int> &arr) {
    int n = arr.size();
    mergeSortHelper(arr, 0, n - 1);
}
void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int left = low + 1;
        int right = high;

        while (true) {
            while (left <= right && arr[left] <= pivot) {
                left++;
            }
            while (arr[right] >= pivot && right >= left) {
                right--;
            }
            if (right < left) {
                break;
            } else {
                swap(arr[left], arr[right]);
            }
        }

        swap(arr[low], arr[right]);
        quicksort(arr, low, right - 1);
        quicksort(arr, right + 1, high);
    }
}
void mostrar(vector<int>arr){
    int n=arr.size();
    for(int i;i<n;i++){
        cout<<i<<" "<<arr[i]<<endl;
    }
    arr.clear();
}
int main()
{
  int tam;
    cout<<"Ingrese el tamaño del vector: "<<endl;
    cin>>tam;
    srand(time(0));
    vector<int> arr = generarNumerosAleatorios(tam);
    bubbleSort(arr);
    mostrar(arr);
    //insertionSort(arr);
    //mostrar(arr);
    //selectionSort(arr);
    //mostrar(arr);
    //mergeSort(arr);
    //mostrar(arr);
    //int n=arr.size();
    //quicksort(arr, 0, n - 1);
    //mostrar(arr);

}


