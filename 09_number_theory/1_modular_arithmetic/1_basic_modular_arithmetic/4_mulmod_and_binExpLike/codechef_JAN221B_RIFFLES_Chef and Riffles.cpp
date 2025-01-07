#include <iostream>
#include <vector>
using namespace std;

// solution 1 -> got TLE

// Function to perform one riffle shuffle
vector<int> riffleShuffle(const vector<int>& perm) {
  int N = perm.size();
  vector<int> shuffled(N);
  for (int i = 0; i < N / 2; ++i) {
    shuffled[i] = perm[2 * i];              // Odd indices
    shuffled[N / 2 + i] = perm[2 * i + 1];  // Even indices
  }
  return shuffled;
}

// Function to find the period of riffle shuffles
int findPeriod(int N) {
  vector<int> perm(N);
  for (int i = 0; i < N; ++i) perm[i] = i + 1;

  vector<int> original = perm;
  int period = 0;

  do {
    perm = riffleShuffle(perm);
    ++period;
  } while (perm != original);

  return period;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, K;
    cin >> N >> K;

    // Find the period of the shuffle
    int period = findPeriod(N);

    // Reduce K using the period
    K %= period;

    // Generate the identity permutation
    vector<int> perm(N);
    for (int i = 0; i < N; ++i) perm[i] = i + 1;

    // Apply K shuffles
    for (int i = 0; i < K; ++i) {
      perm = riffleShuffle(perm);
    }

    // Print the result
    for (int i = 0; i < N; ++i) {
      cout << perm[i] << " ";
    }
    cout << endl;
  }

  return 0;
}

// solution2 -> Accepted
vector<int> apply(vector<int> seq, vector<int> arr) {
  int n = arr.size();
  vector<int> temp(n);
  for (int i = 0; i < n; i++) {
    temp[i] = seq[arr[i]];
  }
  return temp;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n / 2; i++) {
      arr[i] = i * 2;
      arr[i + n / 2] = i * 2 + 1;
    }
    vector<int> seq(n);
    for (int i = 0; i < n; i++) seq[i] = i;
    while (k > 0) {
      if (k & 1) {
        seq = apply(seq, arr);
      }
      arr = apply(arr, arr);
      k >>= 1;
    }
    for (int i = 0; i < n; i++) cout << seq[i] + 1 << " ";
    cout << "\n";
  }

  return 0;
}
