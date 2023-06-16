#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

class Guesser
{
public:
    inline void guess(int &x, int &y, int &z)
    {
        do {
            x = rand() % 9 + 1;
            y = rand() % 9 + 1;
            z = rand() % 9 + 1;
        } while(x == y || y == z || x == z);
    }
};

template <typename TGuesser=Guesser>
class BaseBallGame
{
    typedef tuple<int, int, int> INPUT;
    typedef tuple<int, int> RESULT;
    vector<pair<INPUT, RESULT>> v;
    TGuesser guesser;

public:
    BaseBallGame() { srand((unsigned)time(0)); }
    
    void run()
    {
        while (1)
        {
            int x = 0, y = 0, z = 0;
            guesser.guess(x, y, z);

            cout << "당신이 생각한 숫자는 " << x
                << ", " << y << ", " << z << " 입니까?" << endl;
            int strike = 0, ball = 0;
            cout << "strike 갯수 : ";
            cin >> strike;
            if (strike == 3)
            {
                cout << "성공!" << endl;
                break;
            }
            cout << "ball 갯수 : ";
            cin >> ball;

            v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
            dump();
        }
    }
    void dump()
    {
        printf("-------------------------\n");
        printf("입력값   s b\n");
        for (auto& p : v)
        {
            printf(" %d %d %d : %d %d\n",
                get<0>(p.first), get<1>(p.first), get<2>(p.first),
                get<0>(p.second), get<1>(p.second));
        }
        printf("-------------------------\n");
    }
};

int main(void)
{
    BaseBallGame<Guesser> bbg;
    bbg.run();
}