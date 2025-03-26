#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    ifstream products ("/Users/sam/XcodeProjects/Bet365Hackathon/Bet365Hackathon/input1.txt");
    istream_iterator<int> start (products), end;
    vector<int> productsVector (start, end);
    cout << "Read " << productsVector.size() << " numbers\n";
    copy (productsVector.begin(),
          productsVector.end(),
          ostream_iterator<int>(cout, "\n"));

    int boxSizes[4] = {5, 16, 42, 59};
}
