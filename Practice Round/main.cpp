#include<iostream>

using namespace std;

int main()
{
    int max_slices, pizza_types;
    cin>>max_slices>>pizza_types;

    int num_slices[pizza_types];
    int i,j;

    for(i=0;i<pizza_types;i++)
    {
        cin>>num_slices[i];
    }

    int sum = 0;
    int tmpArray[pizza_types];
    int ta = -1;
    int ans[pizza_types];
    int an = -1;
    int max = 0;
    int f = 0;

    for(i=pizza_types-1;i>=0;i--)
    {
        sum = 0;
        ta = -1;
        for(j=i;j>=0;j--)
        {
            if(sum+num_slices[j]<max_slices)
            {
                sum = sum + num_slices[j];
                ta++;
                tmpArray[ta] = j;
            }
            else if(sum+num_slices[j]==max_slices)
            {
                sum = sum + num_slices[j];
                ta++;
                tmpArray[ta] = j;
                f = 1;
                break;
            }
        }

        if(f)
        {
            break;
        }

        if(sum>max)
        {
            max = sum;
            an = ta;
            for(i=0;i<=ta;i++)
            {
                ans[i] = tmpArray[i];
            }
        }
    }

    if(f)
    {
        cout<<ta+1<<endl;
        for(i=ta;i>=0;i--)
        {
            cout<<tmpArray[i]<<" ";
        }
    }
    else
    {
        cout<<an+1<<endl;
        for(i=an;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
    }
}