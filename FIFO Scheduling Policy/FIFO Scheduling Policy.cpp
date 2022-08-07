// FIFO Scheduling Policy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task
{
    double r;
    double p;
    double e;
    double d;
    double s;
    int x;
    int y;
};

bool r_comp(task& a, task& b)
{
    return a.r < b.r;
}

int main()
{
    int n, j = 15; // j refers to number of jobs for all tasks
    cout << "Enter number of tasks: ";
    cin >> n;
    vector<task> tasks(n);
    cout << "Enter Tasks info as Release, Period, Execution and Deadline e.g: 0 6 2 6" << endl;
    cout << "                                                                 1 8 2 8" << endl;
    cout << "                                                                 ......." << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> tasks[i].r;
        cin >> tasks[i].p;
        cin >> tasks[i].e;
        cin >> tasks[i].d;
        tasks[i].x = i + 1;
        tasks[i].y = 1;
    }
    sort(tasks.begin(), tasks.end(), r_comp);
    tasks[0].s = tasks[0].r;
    while (j--)
    {
        cout << "from T" << tasks[0].s << " to T" << tasks[0].s + tasks[0].e << ": j" << tasks[0].x << tasks[0].y << endl;
        if (tasks[0].d * tasks[0].y <= tasks[0].s + tasks[0].e)
        {
            cout << "j" << tasks[0].x << tasks[0].y << " has Deadline Broken" << endl;
            break;
        }
        tasks[0].y++;
        tasks[0].r += tasks[0].p;
        int startNextJob = tasks[0].s + tasks[0].e;
        sort(tasks.begin(), tasks.end(), r_comp);
        if (tasks[0].r > startNextJob)
            tasks[0].s = tasks[0].r;
        else
            tasks[0].s = startNextJob;

    }
    return 0;
}
