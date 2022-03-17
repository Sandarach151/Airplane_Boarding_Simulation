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
        plane[i]->row = int(i/y)+1;
        plane[i]->col = i%y+1;
        plane[i]->bag = rand()%(maxBag+1);
    }
    unsigned seed = rand()%1000;
    shuffle(plane, plane+(x*y), default_random_engine(seed));
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
    for(int i=0; i<=max; i++){
        for(int i=0; i<x*y; i++){
            plane[i]->pos+=1;
        }
        moveselapsed++;
        int maxb = 0;
        int seatachieved = 0;
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
}*/
