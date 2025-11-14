#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    
    vector<queue<int>>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int TN;
        cin >> TN;

        queue<int>q;
        for(int i=0; i<8; i++)
        {
            int input;
            cin >> input;
            q.push(input);
        }

        bool is_end = false;
        int cur;
        int digit = 1;

        while(true)
        {   
            cur = q.front(); q.pop();
            cur -= digit;
            if(cur <= 0)
            {
                cur = 0;
                q.push(cur);
                break;
            }

            q.push(cur);
            digit++;
            if(digit > 5) digit = 1;
        }


        answers.push_back(q);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
    {
        queue<int>q = answers[i];
        cout << "#" << i+1 << " ";
        for(int j=0; j<8; j++)
        {
            cout << q.front(); q.pop();

            if(j==7) cout << endl;
            else cout << " ";
        }
    }

	return 0;
}