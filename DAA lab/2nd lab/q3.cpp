#include <bits/stdc++.h>
#include <chrono>
#include <unistd.h>
#include <vector>
using namespace std;
using namespace std::chrono;
vector<int> arr;
int n = 0;
void ascending_insertionSort()
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void decending_insertionSort()
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void arrDisplay()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void generateRandomArray(int start, int end)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(start, end);
    extern int n;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(distr(gen));
    }
}
void generateRandomArray()
{
    int start, end;
    cout << "Enter the length:";
    cin >> n;
    cout << "Enter the start value:";
    cin >> start;
    cout << "Enter the end value:";
    cin >> end;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(start, end);

    if (start > end)
    {
        cout << "enter a vaild range" << endl;
        return;
    }
    else
    {
        extern int n;
        for (int i = 0; i < n; i++)
        {
            arr.push_back(distr(gen));
        }
    }
}

double timerasce()
{
    auto start = system_clock::now();
    sleep(1);
    ascending_insertionSort();
    auto end = system_clock::now();
    return duration_cast<nanoseconds>(end - start).count() / pow(10, 9);
}
double timerdesc()
{
    auto start = system_clock::now();
    sleep(1);
    decending_insertionSort();
    auto end = system_clock::now();
    return duration_cast<nanoseconds>(end - start).count() / pow(10, 9);
}
void _5thbit()
{
    cout << "\nTIME TAKEN :" << timerasce();
}

void compareSorting()
{
    cout << "Inputs\taverage\t\tbest case\t\tworst case\n";
    for (int i = 5000; i <= 50000; i += 5000)
    {
        n = i;
        generateRandomArray(-1000, 2000);
        double time_for_sorting = timerasce();
        cout << i << "\t";
        cout << time_for_sorting << "\t\t";
        time_for_sorting = timerasce() - 1;
        cout << time_for_sorting << "\t\t";
        time_for_sorting = timerdesc();
        cout << time_for_sorting << "\t\t";
        cout << endl;
    }
}
int menu()
{
    int choice;
    cout << "Enter a Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 0:
        cout << "Exiting...";
        sleep(2);
        system("cls");
        exit(0);
        break;
    case 1:
        generateRandomArray();
        cout << endl;
        break;
    case 2:
        if (n > 0)
            arrDisplay();
        else
            cout << "Array doesn't exist." << endl;
        cout << endl;
        break;

    case 3:
        ascending_insertionSort();
        cout << "Sorting done ascending..." << endl;
        cout << endl;
        break;
    case 4:
        decending_insertionSort();
        cout << "Sorting done decending..." << endl;
        cout << endl;
        break;
    case 5:
        cout << "Sorting in ascending..." << endl;
        _5thbit();
        cout << "Sorting done ascending..." << endl;
        cout << endl;
        break;
    case 6:
        cout << "Sorting in ascending..." << endl;
        ascending_insertionSort();
        cout << "Sorting done ascending..." << endl;
        _5thbit();
        cout << endl;
        break;
    case 7:
        cout << "Sorting in decending..." << endl;
        decending_insertionSort();
        cout << "Sorting done decending..." << endl;
        _5thbit();
        cout << endl;
        break;
    case 8:
        compareSorting();
        cout << endl;
        break;
    default:
        break;
    }
}
int main()
{
    cout << "\n\nrobin,20051828 \n\n";
    while (true)
    {
        menu();
    }
    return 0;
}