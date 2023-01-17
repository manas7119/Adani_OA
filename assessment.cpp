#include<bits/stdc++.h>
using namespace std;

int get_random_number(int min, int max)
{
	int random_variable = rand();
	return min + (random_variable % (max - min + 1));
}

vector<vector<int>> generate_2d_array(int numberOfRows, int numberOfColumns) {
  vector<vector<int>> arr(numberOfRows,vector<int>(numberOfColumns));
  
  srand(time(nullptr)); // use current time as seed for random generator to get true random values
  
  for(int i=0; i<numberOfRows; i++) {
    for(int j=0; j<numberOfColumns; j++) {
      int value = get_random_number(0,100);
      arr[i][j] = value;
    }
  }
  
  return arr;
}

void count_sort(vector<int> &arr, int min, int max)
{
    int n = arr.size();
    int output[n];
    int RANGE = max-min+1;
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));
    int i=0;
  
    for (i = 0; i < n; ++i)
        count[arr[i]]++;
 
   for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
 
    for (i = n-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
 
    for (i = 0; i<n; ++i)
        arr[i] = output[i];
}

vector<vector<int>> sort_2d_list(vector<vector<int>> &arr, int columnIndex) {
    vector<int> unsorted_column;
    for(int i=0; i<arr.size(); i++) {
      unsorted_column.push_back(arr[i][columnIndex]);
    }
  
    count_sort(unsorted_column, 0, 100);
  
    for(int i=0; i<arr.size(); i++) {
      arr[i][columnIndex] = unsorted_column[i];
    }
    
    return arr;
}

int main() {
    
    int numberOfRows, numberOfColumns;
    cout<<"Enter number of rows : ";
    cin>>numberOfRows;
    cout<<"Enter number of columns : ";
    cin>>numberOfColumns;  
    
    vector<vector<int>> arr = generate_2d_array(numberOfRows, numberOfColumns);
    cout<<"Initially created 2d array : \n";
    for(auto row:arr) {
      for(auto ele:row) cout<<ele<<" ";
      cout<<endl;
    }
    cout<<endl;
  
    int columnIndex;
    cout<<"Enter column Index to sort : ";
    cin>>columnIndex;
    
    sort_2d_list(arr,columnIndex);
    
    cout<<"2d array after sorting : \n";
    for(auto row:arr) {
      for(auto ele:row) cout<<ele<<" ";
      cout<<endl;
    }
    
    return 0;
}