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

int find_lib(int d)
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

    for(i=0;i<num_lib;i++)
    {
        s1 = 0;

        if(!lib[i])
        {
            if(d+lib_info[i][1]<num_days)
            {
                xd = d+lib_info[i][1];
                nb = 0;

                for(k=0;k<lib_info[i][0];k++)
                {
                    if(!finished_books[bookin_lib[i][k]])
                    {
                        nb++;
                        s1 += score_books[bookin_lib[i][k]];
                        if(nb==lib_info[i][2])
                        {
                            xd++;
                            nb = 0;
                            if(xd==num_days)
                            {
                                break;
                            }
                        }
                    }
                }

                sq = sqrt(lib_info[i][1]);
                r1 = (s1)/(sq);

                if(r1>max)
                {
                    max = r1;
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

    i = find_lib(d);

    while(d!=num_days)
    {
        if(i==-1)
        {
            break;
        }

        f = 1;
        
        count2 = 0;

        c1 = 0;

        for(j=0;j<lib_info[i][0];j++)
        {
            index = bookin_lib[i][j];
            if(!finished_books[index])
            {
                if(f)
                {
                    d = d + lib_info[i][1];
                    d1 = d;
                    if(d>=num_days)
                    {
                        break;
                    }
                    count1++;
                }
                f = 0;
                c1++;
                count2++;
                temp2.push_back(index);
                if(c1==lib_info[i][2])
                {
                    d1++;
                    if(d1==num_days)
                    {
                        break;
                    }
                    c1 = 0;
                }
                finished_books[index] = 1;
            }
        }

        if(count2)
        {
            temp1.push_back(lib_info[i][3]);
            lib[i] = 1;
            temp1.push_back(count2);

            ans_line1.push_back(temp1);

            ans_line2.push_back(temp2);

            temp1.clear();
            temp2.clear();
        }
        if(d>=num_days)
        {
            break;
        }
        
        i = find_lib(d);

    }

    cout<<count1<<endl;

    for(i=0;i<count1;i++)
    {
        cout<<ans_line1[i][0]<<" "<<ans_line1[i][1]<<endl;

        for(j=0;j<ans_line1[i][1];j++)
        {
            cout<<ans_line2[i][j]<<" ";
        }
        cout<<endl;
    }






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