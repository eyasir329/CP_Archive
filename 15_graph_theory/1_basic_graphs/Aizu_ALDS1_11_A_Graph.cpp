#include <bits/stdc++.h>
using namespace std;

void sol1() {  // accepted
  string line;
  vector<string> lines;

  // Read input from stdin
  while (getline(cin, line)) {
    lines.push_back(line);
  }

  // First line gives the number of nodes
  int N = stoi(lines[0]);

  // Initialize adjacency matrix with 0s
  vector<vector<int>> m(N, vector<int>(N, 0));

  // Process the input
  for (size_t i = 1; i < lines.size(); i++) {
    stringstream ss(lines[i]);
    int u, k;
    ss >> u >> k;
    vector<int> v;

    // Read the rest of the line into the vector v
    int vertex;
    while (ss >> vertex) {
      v.push_back(vertex);
    }

    // Populate adjacency matrix
    for (int neighbor : v) {
      m[u - 1][neighbor - 1] = 1;  // Convert to 0-based index
    }
  }
  // Print the adjacency matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << m[i][j];
      if (j < N - 1) cout << " ";  // Space between elements
    }
    cout << "\n";  // Newline at the end of each row
  }
}

void sol2() {  // accepted
  int n;
  cin >> n;  // n<=100
  // convert to adjacency matrix
  int A[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = 0;  // initialize by default
    }
  }
  for (int i = 0; i < n; i++) {
    int k, d;
    cin >> k >> d;
    k--;
    for (int j = 0; j < d; j++) {
      int x;
      cin >> x;
      x--;
      A[k][x] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j];
      if (j != n - 1) cout << ' ';
    }
    cout << endl;
  }
}