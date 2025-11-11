#include<iostream>
#include<algorithm>
#include<vector>
#define box_cnt 100

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

    vector<int>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int flatten_cnt;
        cin >> flatten_cnt;

        vector<int>boxes(box_cnt, 0);

        for(int i=0; i<box_cnt; i++)
        {
            cin >> boxes[i];
        }

        while(flatten_cnt > 0)
        {
            sort(boxes.begin(), boxes.end());
            boxes[0]++; boxes[box_cnt-1]--;
            flatten_cnt--;
        }

        sort(boxes.begin(), boxes.end());
        int answer = boxes[99] - boxes[0];


        answers.push_back(answer);
	}

    for(int i=0; i<T; i++) cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}