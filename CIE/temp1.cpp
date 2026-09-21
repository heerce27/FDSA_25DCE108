#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int key, int &comparisons)
{
    comparisons = 0;
    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (a[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key, int &comparisons)
{
    comparisons = 0;
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        comparisons++;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
        {
            comparisons++;
            low = mid + 1;
        }
        else
        {
            comparisons++;
            high = mid-1;
        }
    }
    return -1;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j<n-i-1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int countFrequency(int a[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            count++;
    }
    return count;
}

bool alreadyReported(int reported[], int count, int key)
{
    for (int i = 0; i < count; i++)
    {
        if (reported[i] == key)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter number of badge IDs: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "No badge records available." << endl;
        return 0;
    }
    int *a = new int[n];
    int *sorted = new int[n];
    int *reported = new int[n];
    cout << "Enter badge IDs:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sorted[i] = a[i];
    }
    
    int reportedCount = 0;
    cout << "\nRepeated Badge IDs:" << endl;
    bool foundRepeated = false;
    for (int i = 0; i < n; i++)
    {
        // If already reported, skip it
        if (alreadyReported(reported, reportedCount, a[i]))
            continue;

        int frequency = countFrequency(a, n, a[i]);

        if (frequency > 1)
        {
            cout << "Badge ID: " << a[i]
                 << " | Occurrences: " << frequency << endl;

            reported[reportedCount] = a[i];
            reportedCount++;

            foundRepeated = true;
        }
    }

    if (!foundRepeated)
    {
        cout << "No repeated badge IDs." << endl;
    }

    // ------------------------------------------------
    // PART 2: Sort Copy
    // ------------------------------------------------

    bubbleSort(sorted, n);

    cout << "\nSorted Badge IDs:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << sorted[i] << " ";
    }

    cout << endl;

    // ------------------------------------------------
    // PART 3: Queries
    // ------------------------------------------------

    int q;

    cout << "\nEnter number of verification requests: ";
    cin >> q;

    if (q <= 0)
    {
        cout << "No verification requests." << endl;

        delete[] a;
        delete[] sorted;
        delete[] reported;

        return 0;
    }

    int totalLinearComparisons = 0;
    int totalBinaryComparisons = 0;

    for (int i = 0; i < q; i++)
    {
        int key;

        cout << "\nEnter badge ID to verify: ";
        cin >> key;

        int linearComparisons;
        int binaryComparisons;

        // Method 1: Linear Search on original array
        int originalPosition =
            linearSearch(a, n, key, linearComparisons);

        // Method 2: Binary Search on sorted array
        int sortedPosition =
            binarySearch(sorted, n, key, binaryComparisons);

        totalLinearComparisons += linearComparisons;
        totalBinaryComparisons += binaryComparisons;

        cout << "\nBadge ID: " << key << endl;

        if (originalPosition != -1)
        {
            cout << "Found" << endl;

            // Position is 1-based
            cout << "First position in original record: "
                 << originalPosition + 1 << endl;
        }
        else
        {
            cout << "Not Found" << endl;
            cout << "First position in original record: -1" << endl;
        }

        cout << "Number of comparisons - Method 1 (Linear Search): "
             << linearComparisons << endl;

        cout << "Number of comparisons - Method 2 (Binary Search): "
             << binaryComparisons << endl;
    }

    // ------------------------------------------------
    // PART 4: Final Comparison
    // ------------------------------------------------

    cout << "\n====================================" << endl;
    cout << "TOTAL COMPARISONS" << endl;
    cout << "====================================" << endl;

    cout << "Method 1 - Linear Search: "
         << totalLinearComparisons << endl;

    cout << "Method 2 - Binary Search: "
         << totalBinaryComparisons << endl;

    if (totalLinearComparisons < totalBinaryComparisons)
    {
        cout << "Better Method: Linear Search" << endl;
    }
    else if (totalBinaryComparisons < totalLinearComparisons)
    {
        cout << "Better Method: Binary Search" << endl;
    }
    else
    {
        cout << "Both methods performed equally." << endl;
    }

    delete[] a;
    delete[] sorted;
    delete[] reported;

    return 0;
}