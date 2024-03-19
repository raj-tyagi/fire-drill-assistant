#include <bits/stdc++.h>

#include<conio.h>

#define INFINITY 999

using namespace std;

int l=64;

class fire_escape

{

      private:

              int graph[30][30];

              int graph2[30][30];

              int predecessor[30];
              int dist[30];

              int predecessor2[30];
              int dist2[30];

              bool mark[30];

              int Floor;

              int source;
              int source2;

              int vertices;
              int vertices2;

      public:

              void input();

              void input2();

              void initialize();

              int search_min_node();

              int search_min_node2();

              void calculate_dist();

              void calculate_dist2();

              void output();

              void output2();

              void display_path(int);

              void display_path2(int);

};


void fire_escape :: input()

{

cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;

cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices;
cout<<endl;

while(Floor<=0)
{

while(vertices <= 0)

{

cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;

cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices;
cout<<endl;

}

}

cout<<"Enter the adjacency matrix for the Floor \t"<<"\n========================================\n";

cout<<"To enter the location of fire type: "<<INFINITY<<endl;

for(int i=1;i<=vertices;i++)
{

    cout<<"\n";

cout<<"Enter the distance from room\t"<<i<<":\t"<<endl;

for(int j=1;j<=vertices;j++)

{

cin>>graph[i][j];

while(graph[i][j]<0) {

 cout<<"Distance should be positive. Enter the distance again\n";

 cin>>graph[i][j];

     }

}

}

 cout<<"Enter your location(starting point):\t\n";
 cin>>source;

 while((source<0) && (source>vertices-1))

 {

 cout<<"Your location should be between 0 and"<<vertices-1<<endl;

 cout<<"Enter the location again\n";

 cin>>source;

     }

}

void fire_escape::input2()

{

cout<<"Enter the total number of Floors in the building:\t";

cin>>Floor;

cout<<endl;
cout<<"Enter the total number of rooms in the Floor:\t";

cin>>vertices2;

cout<<endl;

while(Floor<=0)

{

while(vertices2 <= 0)

{

cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;

cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices2;
cout<<endl;
}
}

cout<<"Enter the adjacency matrix for the Floor \t"<<"\n========================================\n";
cout<<"To enter the location of fire type: "<<INFINITY<<endl;
for(int i=1;i<=vertices2;i++)
{
    cout<<"\n";
cout<<"Enter the distance from room\t"<<i<<":\t"<<endl;
for(int j=1;j<=vertices2;j++)
{
cin>>graph2[i][j];
while(graph2[i][j]<0) {
 cout<<"Distance should be positive. Enter the distance again\n";
 cin>>graph2[i][j];
     }
}

}

 cout<<"Enter your location(starting point):\t\n";
 cin>>source2;
 while((source2<0) && (source2>vertices2-1))
 {
 cout<<"Your location should be between 0 and"<<vertices2-1<<endl;
 cout<<"Enter the location again\n";
 cin>>source2;
     }
}


void fire_escape::initialize()
{
 for(int k=1;k<=Floor;k++)
{
 for(int i=1;i<=vertices;i++)
 {
     mark[i] = false;
     dist[i] = INFINITY ;
     dist2[i] = INFINITY ;
     predecessor[i] = -1;
     predecessor2[i] = -1;
     }
}
     dist[source]= 0;
     dist2[source]= 0;
 }

int fire_escape::search_min_node()
{
     int min_dist = INFINITY;
     int closestUnmarkedNode;

     for(int k=1;k<=Floor;k++)
{
     for(int i=1;i<=vertices;i++)
     {
         if((!mark[i]) && ( min_dist >= dist[i]))
         {
  min_dist = dist[i];
  closestUnmarkedNode = i;
}
}
}
     return closestUnmarkedNode;
}
int fire_escape::search_min_node2()
{
     int min_dist = INFINITY;
     int closestUnmarkedNode;
     for(int k=1;k<=Floor;k++)
{
     for(int i=1;i<=vertices;i++)
     {
         if((!mark[i]) && ( min_dist >= dist2[i]))
         {
  min_dist = dist2[i];
  closestUnmarkedNode = i;
}
}
}
     return closestUnmarkedNode;
}

void fire_escape::calculate_dist()
{
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
 int count = 0;
 while(count<vertices)
   {
 	closestUnmarkedNode = search_min_node();
 	mark[closestUnmarkedNode] = true;
 for(int k=1;k<=Floor;k++)
{
 for(int i=1;i<=vertices;i++)
 {
    if((!mark[i]) && (graph[closestUnmarkedNode][i]>0) )
    {
     if(dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i]<dist[i] )
     {
dist[i] = dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i];
predecessor[i] = closestUnmarkedNode;
    }
}
    }
}
count++;
}

}

void fire_escape::calculate_dist2()
{
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
 int count = 0;
 while(count<vertices2)
   {
 	closestUnmarkedNode = search_min_node2();
 	mark[closestUnmarkedNode] = true;

 for(int k=1;k<=Floor;k++)
{
 for(int i=1;i<=vertices2;i++)
 {
    if((!mark[i]) && (graph2[closestUnmarkedNode][i]>0) )
    {
     if(dist2[closestUnmarkedNode]+graph2[closestUnmarkedNode][i]<dist2[i] )
     {
dist2[i] = dist2[closestUnmarkedNode]+graph2[closestUnmarkedNode][i];
predecessor2[i] = closestUnmarkedNode;
    }
}
    }
}
count++;
}
}

void fire_escape::display_path(int node)
{

if(node == source)
{
//CONVERT TYPE CASTING FOR INT TO CHAR

cout<<(char)(node + l)<<"..";
}

else if(predecessor[node] == -1)

cout<<"No path from “source” to "<<(char)(node + 96)<<endl;

else
{
display_path(predecessor[node]);
cout<<(char) (node + l)<<"..";

  }

getch();

}
void fire_escape::display_path2(int node)
{

if(node == source2)
{

cout<<(char)(node + l)<<"..";
}

else if(predecessor2[node] == -1)
cout<<"No path from “source”to "<<(char)(node + 96)<<endl;

{
display_path2(predecessor2[node]);
cout<<(char) (node + l)<<"..";

  }
getch();

}

void fire_escape::output()
{

    cout<<endl;
cout<<"Shortest distance for Floor\t"<<1<<":\t"<<endl;
for(int i=1;i<=vertices;i++)
{

if(i == source)
{
cout<<(char)(source+l)<<".."<<source;

}

else
display_path(i);
cout<<"--->"<<"\tShortest Distance:\t"<<dist[i]<<endl;
}


getch();
}
void fire_escape::output2()
{

    cout<<endl;
cout<<"Shortest distance for Floor\t"<<2<<":\t"<<endl;
for(int i=1;i<=vertices2;i++)
{

if(i == source2)
{
cout<<(char)(source2+l)<<".."<<source;

}

else
display_path2(i);
cout<<"--->"<<"\tShortest Distance:\t"<<dist2[i]<<endl;
}


getch();
}
void drill()
{
   cout << "\n\t\t\t SITUATION\n ";
    cout<< "=====================================================";
    cout << "\n\t\tPress 1 if it is  "
         << "an Emergency\n";
    cout << "\t\tPress 2 if it is "
         << " a drill\n";
    cout << "\t\tPress 3 to exit";
}

void menu()
{
    cout << "\n\t\t Fire Escape System \n ";
    cout<< "=====================================================";
    cout << "\n\t\tPress 1 to enter the "
         << "Path constraints for floor 1\n";
    cout << "\n\t\tPress 2 to enter the "
         << "Path constraints for floor 2\n";
    cout << "\n\t\tPress 3 to get the"
         << " shortest path for floor 1\n";
     cout << "\n\t\tPress 4 to get the"
         << " shortest path for floor 2\n";
    cout << "\n\t\tPress  5 to exit";


}

class objectives
{
public:

// Function for Knapsack algorithm
//Knapsack Algorithm:
//Idea: Use the knapsack algorithm to optimize the selection of items (e.g., equipment or resources)
//to carry during an emergency evacuation, considering their weights and values.

/*
int knapsack( vector<int>& weights, vector<int>& values) {


    cout<<"Enter Capacity "<<endl;
    int capacity; cin>>capacity;
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}
*/
int knapsack(int capacity, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}


// Function for Job Scheduling algorithm
// Job Scheduling function
//Idea: Use a greedy job scheduling algorithm to prioritize the order
//in which tasks or jobs are assigned to available resources or personnel during an emergency evacuation.

int jobScheduling(vector<int>& start_times, vector<int>& end_times, vector<int>& profits)
{
    int n = start_times.size();

    vector<vector<int>> jobs(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        jobs[i][0] = start_times[i];
        jobs[i][1] = end_times[i];
        jobs[i][2] = profits[i];
    }

    // Sort jobs based on their end times in ascending order

    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    });

    vector<int> dp(n, 0);
    dp[0] = jobs[0][2];

    for (int i = 1; i < n; i++)
    {
        int prevJob = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (jobs[j][1] <= jobs[i][0])
            {
                prevJob = j;
                break;
            }
        }

        dp[i] = max(jobs[i][2] + (prevJob != -1 ? dp[prevJob] : 0), dp[i - 1]);
    }

    return dp[n - 1];
}

//Function for Huffman Encoding algorithm
//Idea: Use Huffman encoding to compress data (e.g., messages, instructions, or information)
//related to the fire escape system, so that it can be transmitted or stored more efficiently.

unordered_map<char, string> huffman_encoding(string input)
{


    unordered_map<char, int> frequency;

    for (char c : input)
    {
        frequency[c]++;
    }

    auto compare = [](const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second > b.second;
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);
    for (auto& pair : frequency)
    {
        pq.push(pair);
    }

    unordered_map<char, string> huffman_codes;
    while (pq.size() > 1)
    {
        auto a = pq.top();
        pq.pop();

        auto b = pq.top();
        pq.pop();

        huffman_codes[a.first] = "0" + huffman_codes[a.first];

        huffman_codes[b.first] = "1" + huffman_codes[b.first];
        pq.push({0, a.second + b.second});
    }

    return huffman_codes;
}

//Function for Optimal Merge algorithm
//Idea: Use the optimal merge algorithm to merge sorted data (e.g., lists, arrays, or queues) related
//to the fire escape system, in order to optimize the time and resources required for data processing.

vector<int> optimal_merge(vector<vector<int>>& sorted_lists)
{
    int n = sorted_lists.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> indices(n, 0);
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
// Function for Optimal Merge algorithm (continued)
        if (!sorted_lists[i].empty())
        {
            pq.push({sorted_lists[i][0], i});
        }
    }

    while (!pq.empty())
    {
        int val = pq.top().first;
        int list_idx = pq.top().second;
        pq.pop();
        result.push_back(val);

        if (indices[list_idx] < sorted_lists[list_idx].size() - 1)
        {
            pq.push({sorted_lists[list_idx][indices[list_idx] + 1], list_idx});
            indices[list_idx]++;
        }
    }

    return result;
}

};

int main()
{
   string s1("Jaypee2023");
   string s2;
   int choice,ch,c;

fire_escape a;

cout<<"\tEnter the password to access the project:\t"<<endl;
cout<<"Pass :"<<endl;

cin>>s2;

if(s1==s2)

{


cout<<"\tWe are here to help\t"<<endl;
cout<<endl;

cout<<"\tChoose 1 for REACHING FIRE ESCAPE SYSYTEM (GETTING SHORTEST PATH)"<<endl;
cout<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<endl;
cout<<"\tChoose 2 for Getting ADDITIONAL FEATURES in case of emergency"<<endl;
cout<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<endl;

int abc;
cin>>abc;


if(abc==1)
{
    do {
        cout << "\n";
        drill();
        cout<<"\n------------------------------------------------------";
        cout << "\n\n\t\tEnter your "
             << "Choice:\t ";
        cin >> ch;
        cout<<"\n------------------------------------------------------";
        cout<<endl;

        switch (ch) {
        case 1:
            cout<<"Enter Device  Password:\t";
            cin>>s2;
     if((s2.compare(s1)) == 0)
    {
    cout<<"\n\t\tEmergency services have been contacted"<<endl;

    cout <<"\n\t\tWelcome to Fire Escape System\t"<<endl;
    }
    else if((s2.compare(s1))!= 0)

    {
       cout <<"\n\tpassword didn't match , Please Enter again\n ";
       break;
       drill();

    }

            do
        {
         menu();
         cout<<"\n------------------------------------------------------";
        cout << "\n\n\t\tEnter your "<< "choice:\t ";
        cin >> choice;
        cout<<"\n------------------------------------------------------";
        cout<<endl;

        switch (choice)
        {
        case 1:

        {

            a.input();
            a.calculate_dist();
            break;
        }

        case 2:
        {
         a.input2();
            a.calculate_dist2();
            break;
        }

        case 3:
            {

           a.output();
            break;
            }

        case 4:
        {
            a.output2();
            break;
        }
        case 5:
        {
        exit(0);
        break;
        }

        default:
        {
        cout<<"Invalid Choice Please try again\n";
        }

        }
 }
 while(choice!=5);
 break;

        case 2:
           cout<<"\n\t\tProceed to the drill"<<endl;

        do
    {
         menu();

         cout<<"\n------------------------------------------------------";

         cout << "\n\n\t\tEnter your "
             << "choice:\t ";

         cin >> choice;

         cout<<"\n------------------------------------------------------";

         cout<<endl;


         switch (choice) {

        case 1:

        {

            a.input();
            a.calculate_dist();
            break;

        }

        case 2:

        {

         a.input2();
         a.calculate_dist2();
         break;

        }

        case 3:
           {
               a.output();
               break;
            }
        case 4:
            {
           a.output2();
           break;
            }
        case 5:
            {
        exit(0);
        break;
        }

        default:
        {
        cout<<"Invalid Choice Please try again\n";
        }
        }
    }
 while(choice!=5);
 break;
        case 3:
        exit(0);
        break;

        default:
        cout<<"Invalid Choice Please try again\n";
        }
 }
 while(choice!=3);

}



else if(abc==2)
    {
        cout<<"Choose how many times you want to use the features"<<endl;
int f;
cin>>f;
for(int i=0;i<f;i++)
{

 cout<<"Choose 1 for KNAPSACK \nChoose 2 for JOB SCHEDULING\nChoose 3 for HUFFMAN ENCODING\nChoose 4 for OPTIMAL SEARCH"<<endl;
 cout<<"Enter your choice "<<endl;
 int n;
 cin>>n;

 objectives obj;

//switch case 2
 switch(n)
 {
     case 1:
         {
//KNAPSACK PROBLEM
 cout<<endl;
    cout<<endl;

    cout<<"Function for Knapsack algorithm"<<endl;
cout<<"Knapsack Algorithm:"<<endl;

cout<<"Idea: Use the knapsack algorithm to optimize the selection of items (e.g., equipment or resources)"<<endl;
cout<<"to carry during an emergency evacuation, considering their weights and values."<<endl;

cout<<endl;
cout<<endl;
/*cout << "Function for Knapsack algorithm" << endl;
    cout << "Knapsack Algorithm:" << endl;
    cout << "Idea: Use the knapsack algorithm to optimize the selection of items (e.g., equipment or resources)" << endl;
    cout << "to carry during an emergency evacuation, considering their weights and values." << endl;
    cout << endl;
*/
    int num_weights;
    cout << "How many weights do you want to enter?" << endl;
    cin >> num_weights;
    vector<int> weights;
    cout << "Enter values for weights:" << endl;
    for (int i = 0; i < num_weights; i++) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    int num_values;
    cout << "How many values do you want to enter?" << endl;
    cin >> num_values;
    vector<int> values;
    cout << "Enter values for values:" << endl;
    for (int i = 0; i < num_values; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }

    cout << "Enter capacity:" << endl;
    int capacity;
    cin >> capacity;

    int knapsack_result = obj.knapsack(capacity, weights, values);
    cout<<endl;
    cout << "Knapsack result: " << knapsack_result << endl;

break;
 }


case 2:
{

    //JOB SCHEDULING PROBLEM
    // Sample input for Job Scheduling

  //  vector<int> start_times = {1, 2, 3, 4, 6};

  cout<<endl;
cout<<endl;
    cout<<"Function for Job Scheduling algorithm"<<endl;
cout<<" Job Scheduling function"<<endl;
cout<<"Idea: Use a greedy job scheduling algorithm to prioritize the order"<<endl;
cout<<"in which tasks or jobs are assigned to available resources or personnel during an emergency evacuation."<<endl;

cout<<endl;
cout<<endl;

    int num_values;
    cout << "How many start_times do you want to enter?" << endl;
    cin >> num_values;
    vector<int> start_times;
    cout << "Enter start_times for values:" << endl;
    for (int i = 0; i < num_values; i++) {
        int value;
        cin >> value;
       start_times.push_back(value);
    }



    //vector<int> end_times = {3, 5, 10, 6, 9};

     int num_values1;
    cout << "How many end_times do you want to enter?" << endl;
    cin >> num_values1;
    vector<int> end_times;
    cout << "Enter end_times for values:" << endl;
    for (int i = 0; i < num_values1; i++) {
        int value1;
        cin >> value1;
       end_times.push_back(value1);
    }

    //vector<int> profits = {20, 20, 100, 70, 60};

    int num_values2;
    cout << "How many profits do you want to enter?" << endl;
    cin >> num_values2;
    vector<int> profits;
    cout << "Enter profits for values:" << endl;
    for (int i = 0; i < num_values2; i++) {
        int value2;
        cin >> value2;
       profits.push_back(value2);
    }
    // Call the Job Scheduling function
    int result = obj.jobScheduling(start_times, end_times, profits);
    // Display the result
    cout << "Job Scheduling result: " << result << endl;
break;
}


case 3:
{

    // Huffman Encoding

    //string input = "abracadabra";

    cout<<endl;
    cout<<endl;
cout<<"Function for Huffman Encoding algorithm"<<endl;
cout<<"Idea: Use Huffman encoding to compress data (e.g., messages, instructions, or information)"<<endl;
cout<<"related to the fire escape system, so that it can be transmitted or stored more efficiently."<<endl;
cout<<endl;
cout<<endl;

cout<<"Please enter the string : ";
     string input;  cin>>input;
    unordered_map<char, string> huffman_codes = obj.huffman_encoding(input);
    cout << "Huffman Encoding result: " << endl;
    for (auto& pair : huffman_codes)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

break;
}
case 4:
    // OPTIMAL MERGE
 {
   // vector<vector<int>> sorted_lists = {{2, 6, 9}, {1, 4, 8}, {3, 5, 7}};

    // Initialize an empty vector of vectors

cout<<endl;
cout<<endl;
    cout<<"Function for Optimal Merge algorithm"<<endl;
cout<<"Idea: Use the optimal merge algorithm to merge sorted data (e.g., lists, arrays, or queues) related"<<endl;
cout<<"to the fire escape system, in order to optimize the time and resources required for data processing."<<endl;
cout<<endl;
cout<<endl;

    vector<vector<int>> sorted_lists;

    // Get the number of rows from the user
    int num_rows;
    cout << "Enter the number of rows: ";
    cin >> num_rows;

    // Get the elements for each row from the user
    for (int i = 0; i < num_rows; i++) {
        vector<int> row;
        int num_cols;
        cout << "Enter the number of elements in row " << i << ": ";
        cin >> num_cols;

        // Get the elements for the current row
        for (int j = 0; j < num_cols; j++) {
            int elem;
            cout << "Enter element " << j << " for row " << i << ": ";
            cin >> elem;
            row.push_back(elem);
        }


        // Add the current row to the 2D vector
        sorted_lists.push_back(row);
    }

    vector<int> optimal_merge_result = obj.optimal_merge(sorted_lists);
    cout << "Optimal Merge result: ";
    for (int num : optimal_merge_result)
    {
        cout << num << " ";
    }
    cout << endl;




break;}


 case 5:
      {
        exit(0);
        break;

        default:
        cout<<"Invalid Choice Please try again\n";
        }
        }

}
}
}

else //PASSWORD IF-ELSE
{
cout<<"WRONG PASSWORD"<<endl;
exit(0);
}
return 0;
}


