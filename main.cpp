#include <bits/stdc++.h>
#include "const.h"

using namespace std;

string s, ip, op, opt;

string fname = "high";

int avg(uint8_t a, uint8_t b, uint8_t c){
    return (a+b+c)/3;
}

int main(int argc, char* argv[]){

    if (argc > 1) {
        fname = argv[1];  
    } 

    ip = "./input/"+fname+".ppm";
    op = "./output/"+fname+".ppm";
    opt = "./output/"+fname+".txt";


    ifstream f(ip);
    ofstream of(op);
    ofstream oft(opt);
    

    if (!f.is_open()) {
        cout << "File can't be opened";
        return 1;
    }
    else cout<<"File opened successfully"<<endl;

    string s,h,w,wh,disc,flt;

    getline(f, s);
    getline(f,disc);
    getline(f, wh);
    istringstream(wh) >> w >> h;
    
    getline(f, disc);

    for (int i = 0; i < stoi(w)*stoi(h) ; i++)
    {   
        getline(f, s);
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
        a = stoi(s);

        getline(f, s);
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
        b = stoi(s);

        getline(f, s);
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
        c = stoi(s);

        img[i] = uint8_t(avg(a,b,c));
        len++;
    }
    cout<<int(img[0])<<endl;
    cout<<len<<endl;

    int dat[stoi(h)][stoi(w)];

    of<<"P3"<<endl;
    of<<w<<" "<<h<<endl;
    of<<"255"<<endl;
    
    int index = 0;
    for (int i = 0; i < stoi(h); i++)
    {
        for (int j = 0; j < stoi(w); j++)
        {
           dat[i][j] = img[index];
           index++;
        }
    }
    
    for (int i = 0; i < stoi(h); i++)
    {
        for (int j = 0; j < stoi(w); j++)
        {
            of<<dat[i][j]<<" ";
            of<<dat[i][j]<<" ";
            of<<dat[i][j]<<endl;

        }
    }

    for (int i = 0; i < stoi(h); i++)
    {
        for (int j = 0; j < stoi(w); j++)
        {

            id = num - ceil((dat[i][j] / 255.0) * (num - 1)) + 10;
            
            if(id<num/2) {
                id = id - 5;
                if(id<0)id=0;
            }
            else if(id>num/2) {
                id = id + 5;
                if(id>=num)id = num-1;
            }
            oft<<ascii_chars[id]<<ascii_chars[id];
        }
        oft<<endl;
    }

}