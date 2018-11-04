#include <iostream>
using namespace std;

void rotate4 ( int& a, int& b, int& c, int& d )
{
    int temp;
    temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}

void rotate_square ( int k, int **array, int n )  //k指的是第几层   这个是旋转正方形 n是小array的边长
{
    if(n+1-(2*k) > 0)
    {
        for ( int i = 0; i < n+1-(2*k); i++ )
       {
           rotate4(array[k-1+i][k-1], array[n-k][k-1+i], array[n-k-i][n-k], array[k-1][n-k-i]);
       }
    }
}

int circles( int n )   //求出需要多少个正方形，n/2向上取整
{
    if ( n%2 == 0 ) return n/2;
    else return (n+1)/2;
}

void rotate_matrix ( int **array, int n ) //转整个矩阵
{
    for ( int k = 1; k <= circles(n); k++ )
    {
        rotate_square(k, array, n);
    }
}

bool equal_matrix(int **array1, int **array2, int n)
{
    int d = 0;
    for ( int i = 0; i < n && d == 0; i++ )
    {
        for ( int j = 0; j < n && d == 0; j++ )
        {
            if ( array1[i][j] == array2[i][j] )
                continue;
            else d = d+1;
        }
    }
    if ( d == 0 ) return true;
    else return false;
    
}
int main()
{
    int n, N;
    cin >> n;
    int **small = new int* [n];
    for ( int i = 0; i < n; i++ )
    {
        small[i] = new int[n];
    }
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            cin >> small[i][j];
        }
    }
    cin >> N;
    int **big = new int* [N];
    for ( int i = 0; i < N; i++ )
    {
        big[i] = new int[N];
    }
    for ( int i = 0; i < N; i++ )
    {
        for ( int j = 0; j < N; j++ )
        {
            cin >> big[i][j];
        }
    }
    int d = 0;
    for ( int i = 0; i <= N-n && d == 0; i++ ) //从大矩阵里截取小矩阵 i j代表左上角的坐标
    {
        for ( int j = 0; j <= N-n && d == 0; j++ )
        {
            int **cut = new int* [n];
            for ( int m = 0; m < n; m++ )
            {
                cut[m] = new int[n];
            }
            for ( int s = 0; s < n; s++ )
            {
                for ( int p = 0; p < n; p++ )
                {
                    cut[s][p] = big[i+s][j+p];
                }
            }
            if ( equal_matrix(cut, small, n) == true )
            {
                cout << j << " " << i << endl;
                d = 1;
                delete[] cut;
            }
            else
            {
                rotate_matrix(small, n);
                if ( equal_matrix(cut, small, n) == true )
                {
                    cout << j << " " << i << endl;
                    d = 1;
                    delete[] cut;
                }
                else
                {
                    rotate_matrix(small, n);
                    if ( equal_matrix(cut, small, n) == true )
                    {
                        cout << j << " " << i << endl;
                        d = 1;
                        delete[] cut;
                    }
                    else
                    {
                        rotate_matrix(small, n);
                        if ( equal_matrix(cut, small, n) == true )
                        {
                            cout << j << " " << i << endl;
                            d = 1;
                            delete[] cut;
                        }
                        else continue;
                    }
                }
            }
        }
    }
    return 0;
}
