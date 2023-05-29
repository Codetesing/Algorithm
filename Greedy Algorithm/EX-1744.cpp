#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visitd[10001] = { false };

int Solution(vector<int>& number)
{
    int answer = 0;

    sort(number.begin(), number.end());

    for (int i = number.size() - 1; i > 0; i--)
    {
        if ((!visitd[i] && !visitd[i - 1]) && (number[i] > 1 && number[i - 1] > 1))
        {
            visitd[i] = visitd[i - 1] = true;
            answer += number[i] * number[i - 1];
        }
    }
    for (int i = 0; i < number.size() - 1; i++)
    {
        if ((!visitd[i] && !visitd[i + 1]) && (number[i] <= 0 && number[i + 1] <= 0))
        {
            visitd[i] = visitd[i + 1] = true;
            answer += number[i] * number[i + 1];
        }
    }
    for (int i = 0; i < number.size(); i++)
        if (!visitd[i])
            answer += number[i];

    return answer;
}

void Insert(vector<int>& number, int N)
{
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        number.push_back(num);
    }
}

int main()
{
    int N; cin >> N;
    vector<int> number;
    Insert(number, N);
    cout << Solution(number);

    return 0;
}
