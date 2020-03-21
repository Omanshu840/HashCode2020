#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,j;
    int num_book,num_lib,num_days;

    cin>>num_book>>num_lib>>num_days;

    vector<int> score_books(num_book);

    for(i=0;i<num_book;i++)
    {
        cin>>score_books[i];
    }

    vector<vector<int>> lib_info(num_lib);

    vector<vector<int>> bookin_lib(num_lib);

    for(i=0;i<2;i++)
    {
        lib_info[i] = vector<int>(3);
        cin>>lib_info[i][0]>>lib_info[i][1]>>lib_info[i][2];

        bookin_lib[i] = vector<int>(lib_info[i][0]);
        for(j=0;j<lib_info[i][0];j++)
        {
            cin>>bookin_lib[i][j];
        }
    }


    int d = 0;

    int finished_books[num_book];

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

    i = 0;
    int index = 0;
    int f = 0;
    int d1;

    while(d!=num_days)
    {
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
            temp1.push_back(i);
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

        if(i==num_lib-1)
        {
            break;
        }
        i++;

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

    
}