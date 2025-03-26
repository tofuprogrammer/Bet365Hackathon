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
    cout << "Read " << productsVector.size() << " numbers\n\n";
    /*
    copy (productsVector.begin(),
          productsVector.end(),
          ostream_iterator<int>(cout, "\n"));
    cout << "-----\n";
     */

    int boxSizes[4] = {5, 16, 42, 59};
    int numberOfBoxes[4] = {0, 0, 0, 0};
    int boxesRemainder = 0;
    int largestBoxesRemainder = 0;
    int largeBoxesRemainder = 0;
    int smallBoxesRemainder = 0;
    int smallestBoxesRemainder = 0;
    int smallestRemainder;
    int boxesUsed = 0;
    int boxID = 0;
    int totalBoxes = 0;
    for (int iterator = 0; iterator < 100; iterator++)
    {
        cout << "For " << productsVector[iterator] << " products\n";
        /*
        numberOfBoxes[3] = productsVector[iterator] / boxSizes[3];
        cout << numberOfBoxes[3] << " of the largest boxes (59)\n";
        boxesRemainder = productsVector[iterator] % boxSizes[3];
        numberOfBoxes[2] = boxesRemainder / boxSizes[2];
        cout << numberOfBoxes[2] << " of the large boxes (42)\n";
        boxesRemainder %= boxSizes[2];
        numberOfBoxes[1] = boxesRemainder / boxSizes[1];
        cout << numberOfBoxes[1] << " of the small boxes (16)\n";
        boxesRemainder %= boxSizes[1];
        numberOfBoxes[0] = boxesRemainder / boxSizes[0];
        boxesRemainder %= boxSizes[0];
        if (boxesRemainder != 0)
        {
        numberOfBoxes[0] += 1;
        }
        cout << numberOfBoxes[0] << " of the smallest boxes (5)\n";
        boxesUsed = numberOfBoxes[3] + numberOfBoxes[2] + numberOfBoxes[1] + numberOfBoxes[0];
        */
        largestBoxesRemainder = productsVector[iterator] % boxSizes[3];
        largeBoxesRemainder = productsVector[iterator] % boxSizes[2];
        smallBoxesRemainder = productsVector[iterator] % boxSizes[1];
        smallestBoxesRemainder = productsVector[iterator] % boxSizes[0];
        if (largestBoxesRemainder >= 5 || largeBoxesRemainder == 0)
        {
            smallestRemainder = largestBoxesRemainder;
            boxID = 3;
        }
        else
        {
            smallestRemainder = 999999999;
        }
        if (largeBoxesRemainder < smallestRemainder && (largeBoxesRemainder >= 5 || largeBoxesRemainder == 0))
        {
            smallestRemainder = largeBoxesRemainder;
            boxID = 2;
        }
        if (smallBoxesRemainder < smallestRemainder && (smallBoxesRemainder >= 5 || smallBoxesRemainder == 0))
        {
            smallestRemainder = smallBoxesRemainder;
            boxID = 1;
        }
        if (smallestBoxesRemainder < smallestRemainder && (smallestBoxesRemainder >= 5 || smallestBoxesRemainder == 0))
        {
            smallestRemainder = smallestBoxesRemainder;
            boxID = 0;
        }
        numberOfBoxes[boxID] += 1;
        cout << "Smallest remainder = " << smallestRemainder << '\n';
        cout << "Box ID = " << boxID << '\n';
        cout << "Used " << boxesUsed << " boxes for this delivery\n";
        totalBoxes += boxesUsed;
        cout << '\n';
    }
    cout << "Used " << totalBoxes << " boxes\n";
}
