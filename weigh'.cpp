#include <iostream>
#include <algorithm>
using namespace std;
struct job
{
int start, finish, profit;
// Constructor
job(const int &s = 0, const int &f = 0, const int &p = 0)
{
start = s;
finish = f;
profit = p;
}
};
bool cmp(const job &a, const job &b)
{
return a.finish < b.finish;
}
int check_Overloop(const job *j, const int &n)
{
for (int i = n - 2; i > -1; i--)
if (j[n - 1].start >= j[i].finish)
return i;
return -1;
}
int wi_sch(const job *j, const int &n)
{
if (n == 0)
return j[0].profit;
else
{
int i = check_Overloop(j, n);
int incl = j[n - 1].profit;
if (i != -1)
incl += wi_sch(j, i + 1);
int excl = wi_sch(j, n - 1);
return (incl > excl ? incl : excl);
}
}
int max_profit(job *j, const int &n)
{
sort(j, j + n, cmp);
cout << "\n\nSorted jobs according to respective finish time are :\n\n"
<< "S.N.\t Start-time\t Finish-time\t\tProfit\n";
for (int i = 0; i < n; i++)
cout << "\n " << i + 1 << "\t\t" << j[i].start << "\t\t"
<< j[i].finish << "\t\t" << j[i].profit;
return wi_sch(j, n);
}
int main()
{
job j[] = {{42, 57, 95}, {120, 54, 87}, {82, 16, 110}, {10, 48, 11}};
int n = sizeof(j) / sizeof(j[0]);
cout << "\n\t Weighted Interval Scheduling \n";
cout << "\nGiven jobs are :\n\nS.N.\t Start-time\tFinish-time\t\tProfit\n";
for (int i = 0; i < n; i++)
cout << "\n " << i + 1 << "\t\t" << j[i].start << "\t\t"
<< j[i].finish << "\t\t" << j[i].profit;
int mx = max_profit(j, n);
cout << "\n\nThe Maximum Optimal Profit is : " << mx << endl;
}

