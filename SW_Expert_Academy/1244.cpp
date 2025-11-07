#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int answer;
int swap_cnt;
bool is_end_dfs;

int arr2int(vector<int>arr) // arr -> int 로 변환
{
    int end_idx = arr.size()-1;
    int value = arr[end_idx--];
    int digit = 1;
    while(end_idx >= 0)
    {
        digit *= 10;
        value += arr[end_idx--] * digit;
    } 

    return value;
}

void comb_func(int n, int r, int start, int depth, vector<int> comb, vector<vector<int>>&combs)
{
    if(depth == r)
    {
        combs.push_back(comb);
    }
    
    else
    {
        for(int i=start+1; i<=n; i++)
        {
            comb.push_back(i-1);
            comb_func(n,r,i,depth+1,comb, combs);
            comb.pop_back();
        }
    }
}

bool is_low_func(vector<int>arr) //내림차순인지 검사하는 함수
{
    bool is_low = true;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size(); j++)
            if(arr[i] < arr[j]) is_low = false;
    }

    return is_low;
}

void dfs(int depth, vector<int> arr, vector<vector<int>>combs)
{
    if(is_end_dfs) return;

    vector<int> cp_arr = arr;

    int value = arr2int(cp_arr);

    bool is_low = is_low_func(cp_arr); //내림차순인지 검사

    if(is_low)
    {
        int overlap_idx_1, overlap_idx_2;
        bool is_overlap = false;
        //중복되는 수 검사
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                if(cp_arr[i] == cp_arr[j])
                {
                    is_overlap = true;
                    overlap_idx_1 = i;
                    overlap_idx_2 = j;
                }
            }
        }
        
        if(!is_overlap) //중복되는 수가 없으면
        {
            int end_idx = cp_arr.size()-1;
            while(depth < swap_cnt)
            {
                swap(cp_arr[end_idx], cp_arr[end_idx-1]);
                depth++;
            }        
        }

        value = arr2int(cp_arr);
        answer = max(answer, value);

        is_end_dfs = true;
        return;
    }

    if(swap_cnt == depth)
    {
        answer = max(answer, value);
        return;
    } //기저조건

    for(vector<int> vec : combs)
    {
        swap(cp_arr[vec[0]], cp_arr[vec[1]]);
        int swap_value = arr2int(cp_arr);

        dfs(depth+1, cp_arr, combs);
        cp_arr = arr;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<int> answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = -1;

        string number;

        cin >> number >> swap_cnt;

        vector<int>arr;
        for(int i=0; i<number.size(); i++)
        {
            arr.push_back(number[i] - '0');
        }

        //조합 경우의 수 구하기
        int n = number.size();
        vector<vector<int>> combs;
        vector<int>comb;
        comb_func(n,2,0,0,comb,combs);

        is_end_dfs = false;
        dfs(0, arr, combs);

        answers.push_back(answer);
    }

    for(int i=0; i<answers.size(); i++)
    {
        cout << "#" << i+1 << " " << answers[i] << endl;
    }

	return 0;
}