#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int num_book,num_lib,num_days;
vector<int> score_books(100100);
vector<vector<int>> lib_info(100100);
vector<vector<int>> bookin_lib(100100);

int lib[100100] = {0};

int finished_books[100100] = {0};

int find_lib()
{
    int i,j,k,s1;

    int ans;

    s1 = 0;

    int nb;

    int xd;
    double max = -100000;

    double r1;
    double sq = 1;

    ans = -1;

    int cb = 0;

    for(i=0;i<num_lib;i++)
    {
        s1 = 0;

        if(!lib[i])
        {
                cb = 0;
                for(k=0;k<lib_info[i][0];k++)
                {
                    if(!finished_books[bookin_lib[i][k]])
                    {
                        cb++;
                    }
                }

                if(cb!=14)
                {
                    if(cb>max)
                    {
                        max = cb;
                        ans = i;
                    }

                }
        }
    }

    return ans;
}

int main()
{
    int i,j;
    

    cin>>num_book>>num_lib>>num_days;

    

    for(i=0;i<num_book;i++)
    {
        cin>>score_books[i];
    }

   

    for(i=0;i<num_lib;i++)
    {
        lib_info[i] = vector<int>(4);
        cin>>lib_info[i][0]>>lib_info[i][1]>>lib_info[i][2];

        lib_info[i][3] = i;

        bookin_lib[i] = vector<int>(lib_info[i][0]);
        for(j=0;j<lib_info[i][0];j++)
        {
            cin>>bookin_lib[i][j];
        }
    }

    int s1,s2;

    int k;
    int y;

    double r1,r2;


    for(i=0;i<num_lib;i++)
    {
        for(j=0;j<lib_info[i][0];j++)
        {
            for(k=j+1;k<lib_info[i][0];k++)
            {
                if(score_books[bookin_lib[i][j]] < score_books[bookin_lib[i][k]])
                {
                    y = bookin_lib[i][j];
                    bookin_lib[i][j] = bookin_lib[i][k];
                    bookin_lib[i][k] = y;
                }
            }
        }
    }

    int d = 0;


    for(i=0;i<num_book;i++)
    {
        finished_books[i] = 0;
    }

    vector<vector<int>> ans_line1;
    vector<vector<int>> ans_line2;

    vector<int> temp1;
    vector<int> temp2;

    int count1 = 0;
    int count2 = 0;
    int c1 = 0;

    int index = 0;
    int f = 0;
    int d1;

    i = find_lib();

    int score = 0;

    cout<<num_lib<<endl;

    int count = 0;

    d = 0;
    int td;

    while(count!=num_lib)
    {
        
        count++;

        d += 2;

        td = d;

        c1 = 0;

        cout<<i<<" "<<lib_info[i][0]<<endl;

        for(j=0;j<lib_info[i][0];j++)
        {
            cout<<bookin_lib[i][j]<<" ";
            td++;
            if(td<=num_days)
            {
                finished_books[bookin_lib[i][j]] = 1;
            }
            

        }

        lib[i] = 1;

        cout<<endl;

        
        i = find_lib();

    }

    // cout<<count1<<endl;

    // for(i=0;i<count1;i++)
    // {
    //     cout<<ans_line1[i][0]<<" "<<ans_line1[i][1]<<endl;

    //     for(j=0;j<ans_line1[i][1];j++)
    //     {
    //         cout<<ans_line2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }






    // cout<<num_lib<<endl;

    // for(i=0;i<num_lib;i++)
    // {
    //     cout<<i<<" "<<lib_info[i][0]<<endl;
    //     for(j=0;j<lib_info[i][0];j++)
    //     {
    //         cout<<bookin_lib[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
}