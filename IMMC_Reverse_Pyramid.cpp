#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class Passenger{
    public:
        int row; //1 - 23
        int col; // 1 - 6
        int pos;
        int bag;
};

int main(){
    srand(time(0));
    int x = 23;
    int y = 6; //fixed
    int maxBag = 2;
    int up1 = 0; //fixed
    int up2 = 0; //fixed
    int bagTime = 0;
    Passenger* plane[x*y];
    bool arr[x][y];
    for(int i = 0; i<x; i++){
        for(int j=0; j<y; j++){
            arr[i][j] = false;
        }
    }
    for(int i=0; i<x*y; i++){
        plane[i] = new Passenger;
        plane[i]->col = int(i/x)+1;
        plane[i]->row = i%x+1;
        plane[i]->bag = rand()%(maxBag+1);
    }
    unsigned seed1 = rand()%1000;
    unsigned seed2 = rand()%1000;
    unsigned seed3 = rand()%1000;
    unsigned seed4 = rand()%1000;
    unsigned seed5 = rand()%1000;
    int settemp1 = int((x+1)/2);
    int settemp3 = int(x/4);
    int settemp2 = x - settemp1 - settemp3;
    int settemp4 = int(x/3);
    int settemp5 = x - 2*settemp4;
    int settemp6 = x - settemp5;
    Passenger* sr1[2*(settemp1)];
    Passenger* sr2[2*(settemp2 + settemp5)];
    Passenger* sr3[2*(settemp4 + settemp3)];
    Passenger* sr4[2*(settemp5 + settemp4)];
    Passenger* sr5[2*(settemp6)];
    for(int i=0; i<settemp1; i++){
        sr1[i] = plane[x - settemp1 + i];
    }
    for(int i=0; i<settemp1; i++){
        sr1[settemp1 + i] = plane[6*x - settemp1 + i];
    }
    for(int i=0; i<settemp5; i++){
        sr2[i] = plane[2*x - settemp5 + i];
    }
    for(int i=0; i<settemp5; i++){
        sr2[settemp5 + i] = plane[5*x - settemp5 + i];
    }
    for(int i=0; i<settemp2; i++){
        sr2[2*settemp5 + i] = plane[settemp3 + i];
    }
    for(int i=0; i<settemp2; i++){
        sr2[settemp2 + 2*settemp5 + i] = plane[5*x + settemp3 + i];
    }
    for(int i=0; i<settemp3; i++){
        sr3[i] = plane[i];
    }
    for(int i=0; i<settemp3; i++){
        sr3[settemp3 + i] = plane[5*x + i];
    }
    for(int i=0; i<settemp4; i++){
        sr3[2*settemp3 + i] = plane[x + settemp4 + i];
    }
    for(int i=0; i<settemp4; i++){
        sr3[settemp4 + 2*settemp3 + i] = plane[4*x + settemp4 + i];
    }
    for(int i=0; i<settemp5; i++){
        sr4[i] = plane[3*x - settemp5 + i];
    }
    for(int i=0; i<settemp5; i++){
        sr4[settemp5 + i] = plane[4*x - settemp5 + i];
    }
    for(int i=0; i<settemp4; i++){
        sr4[2*settemp5 + i] = plane[x + i];
    }
    for(int i=0; i<settemp4; i++){
        sr4[settemp4 + 2*settemp5 + i] = plane[4*x + i];
    }
    for(int i=0; i<settemp6; i++){
        sr5[i] = plane[2*x + i];
    }
    for(int i=0; i<settemp6; i++){
        sr5[settemp6 + i] = plane[3*x + i];
    }
    shuffle(sr1, sr1+(2*(settemp1)), default_random_engine(seed1));
    shuffle(sr2, sr2+(2*(settemp2 + settemp5)), default_random_engine(seed2));
    shuffle(sr3, sr3+(2*(settemp4 + settemp3)), default_random_engine(seed3));
    shuffle(sr4, sr4+(2*(settemp5 + settemp4)), default_random_engine(seed4));
    shuffle(sr5, sr5+(2*(settemp6)), default_random_engine(seed5));
    for(int i=0; i<2*(settemp1); i++){
        plane[i] = sr1[i];
    }
    for(int i=0; i<2*(settemp2 + settemp5); i++){
        plane[i + 2*settemp1] = sr2[i];
    }
    for(int i=0; i<2*(settemp4 + settemp3); i++){
        plane[i + 2*(settemp1 + settemp2 + settemp5)] = sr3[i];
    }
    for(int i=0; i<2*(settemp5 + settemp4); i++){
        plane[i + 2*(settemp1 + settemp2 + settemp3 + settemp4 + settemp5)] = sr4[i];
    }
    for(int i=0; i<2*(settemp6); i++){
        plane[i + 2*(settemp1 + settemp2 + settemp3 + 2*settemp4 + 2*settemp5)] = sr5[i];
    }
    for(int i=0; i<x*y; i++){
        plane[i]->pos = -1*i;
    }
    int max = plane[0]->row - plane[0]->pos;
    for(int i=1; i<x*y; i++){
        int j = plane[i]->row - plane[i]->pos;
        if(j > max){
            max = j;
        }
    }
    int moveselapsed = 0;
    int seatachieved = 0;
    for(int i=0; i<=max; i++){
        for(int i=0; i<x*y; i++){
            plane[i]->pos+=1;
        }
        moveselapsed++;
        int maxb = 0;
        for(int i=0; i<x*y; i++){
            if(plane[i]->pos == plane[i]->row){
                arr[plane[i]->row][plane[i]->col] = true;
                seatachieved++;
                if((plane[i]->col == 1 && arr[plane[i]->row][2] == true && arr[plane[i]->row][3] == true) || (plane[i]->col == 6 && arr[plane[i]->row][5] == true && arr[plane[i]->row][4] == true)){
                    up2++;
                    cout << "##";
                }
                else if((plane[i]->col == 2 && arr[plane[i]->row][3] == true) || (plane[i]->col == 5 && arr[plane[i]->row][4] == true)){
                    up1++;
                    cout << "#";
                }
                else if((plane[i]->col == 1 && arr[plane[i]->row][3] == true) || (plane[i]->col == 6 && arr[plane[i]->row][4] == true)){
                    up1++;
                    cout << "#";
                }
                else if((plane[i]->col == 1 && arr[plane[i]->row][2] == true) || (plane[i]->col == 6 && arr[plane[i]->row][5] == true)){
                    up1++;
                    cout << "#";
                }
                cout << plane[i]->row << "  " << plane[i]->col << "  " << plane[i]->bag << endl;
                if(plane[i]->bag>maxb){
					maxb = plane[i]->bag;
				}
				plane[i]->bag = 0;
            }
        }
        bagTime += maxb;
        cout << "Bags, Seats, Moves: " << maxb << "  " << seatachieved << "  " << moveselapsed << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "1 person gets up: " << up1 << endl;
    cout << "2 persons get up: " << up2 << endl;
    cout << "Obstructions caused by stowing bags: " << bagTime << endl;
    cout << "Max distance a person has to walk (in rows): " << max << endl;
    return 0;
}

/*for(int i=0; i<x*y; i++){
        cout << plane[i]->row << "  " << plane[i]->col << "  " << plane[i]->pos << endl;
}

for(int i=0; i<settemp1; i++){
        cout << bsr[i]->row << "  " << bsr[i]->col << endl;
}*/
