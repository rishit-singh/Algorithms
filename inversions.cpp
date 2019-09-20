#include <iostream>

using namespace std;

long long merge_inversions(long long int * list, int begin, int mid, int end)	{
	long long int * left = new long long int[mid - begin + 1];
	long long int * right = new long long int[end - mid];
	int i = 0, j = 0, k = begin;
	long long int inversions = 0;
	for (int x = 0; x < mid - begin + 1; x++)	{
		left[x] = list[x + begin];
		}
	for (int x = 0; x < end - mid; x++)	{
		right[x] = list[x + mid + 1];
		}
	while ((i < mid - begin + 1) && (j < end - mid))	{
		if (left[i] > right[j])	{
			list[k] = right[j];
			inversions += (mid - begin + 1) - i;
			j++;
			}
		else	{
			list[k] = left[i];
			i++;
			}
		k++;
		}
	while (i < (mid - begin + 1))	{
		list[k] = left[i];
		i++;
		k++;
		}
	while (j < (end - mid))	{
		list[k] = right[j];
		j++;
		k++;
		}
	return inversions;
	}

long long int merge_sort(long long int * list, int begin, int end)	{
	if (begin >= end)	{
		return 0;
		} 
	else	{
		long long int inversions = 0;
		inversions += merge_sort(list, begin, (end + begin) / 2);
		inversions += merge_sort(list, ((end + begin) / 2) + 1, end);
		inversions += merge_inversions(list, begin, (end + begin) / 2, end);
		return inversions;
		}
	}

int main()	{
	int t;
	cin >> t;
	while (t--)	{
		long long int n;
		cin >> n;
		long long int * list = new long long int[n];
		for (long long int i = 0; i < n; i++)	{
			cin >> list[i];
			}
		long long int inversions = merge_sort(list, 0, n - 1);
		cout << inversions << endl;
		}
	return 0;
	}
