
#include <iostream>
using namespace std;

float p[] = {60,100,120 };
float w[] = {10,20,30 };
int n=3;
float W = 50.0;

float maxprofit = 0.0;
bool bestset[] = {false, false, false, false, false };
bool includes[] = {false, false, false, false, false };
bool promising(int i, float weight, float profit)
{
    float totweight, boundOnProfit;
    int k;
    if (weight > W)
        return false;
    totweight = weight;
    boundOnProfit = profit;
    for (int j=i+1; j<=n; j++)
    {
        if (totweight + w[j] <= W)
        {
            totweight += w[j];
            boundOnProfit += p[j];
        }
        else
        {
            k = j;
            boundOnProfit += p[k] * (W - totweight) / w[k];
            break;
        } // end if
    } // end for
    return boundOnProfit > maxprofit;
} // end promising
void knapsack(int i, float weight, float profit)
{
    if (weight <= W && profit > maxprofit)
    {
        maxprofit = profit;
        for (int index=1; index <= n; index++)
        {
            bestset[index] = includes[index];
        } // end for
    } // end if
    if (promising(i, weight, profit))
    {
        includes[i+1] = true;
        knapsack(i+1, weight + w[i+1], profit + p[i+1]);
        includes[i+1] = false;
        knapsack(i+1, weight, profit);
    } // end if
} // end knapsack
int main()
{

    knapsack(0, 0.0, 0.0); // inital call to kick off the backtracking
// print results
    cout << "Best profit: " << maxprofit << endl;
    cout << "Items stolen should be:" << endl;
    for (int index = 1; index <= n; index++)
    {
        if (bestset[index])
        {
            cout << "item " << index << endl;
        } // end if
    } // end for
} // end main
