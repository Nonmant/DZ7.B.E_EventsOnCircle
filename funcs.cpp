//https://contest.yandex.ru/contest/29396/problems/

#include "funcs.h"
#include <bits/stdc++.h>

enum EventType : short int{
    LineStart = 0,
    LineEnd = 1
};

void parseInput(std::istream & input,
                std::vector<std::tuple<double,EventType,int>> & events,
                 int & N, std::pair<double, double> & r){
    input >> N;
    events.reserve(2*N);
    double r1,r2,fi1,fi2;
    for(int i = 0; i<N; ++i){
        input>>r1>>r2>>fi1>>fi2;

        if(i == 0){
            r.first = r1;
            r.second = r2;
        } else {
            if(r1>r.first)
                r.first = r1;
            if(r2<r.second)
                r.second = r2;
        }

        events.emplace_back(fi1,LineStart,i);
        events.emplace_back(fi2,LineEnd,i);
    }
}

void parseFile(std::istream & input, std::ostream & output){
    //! pos, type, sector id
    std::vector<std::tuple<double,EventType,int>> events;
    int N;
    std::pair<double,double> r;

    parseInput(input,events,N,r);

    std::sort(events.begin(),events.end());

    double allSectorsAngle = 0;
    std::unordered_set<int> currentSectorsIds;
    bool allLines = false;
    double allLinesStart = -1;
    //first circle
    for(auto & event : events){
        auto [pos, type, id] = event;
        if(type == LineStart){
            currentSectorsIds.insert(id);
        } else{
            currentSectorsIds.erase(id);
        }
    }

    if(currentSectorsIds.size() == N){
        allLines = true;
        allLinesStart = 0;
    }

    for(auto & event : events){
        auto [pos, type, id] = event;
        if(type == LineStart){
            currentSectorsIds.insert(id);

            if(currentSectorsIds.size() == N){
                allLines = true;
                allLinesStart = pos;
            }
        }else{
            currentSectorsIds.erase(id);
            if(allLines){//all lines end
                allLines = false;
                allSectorsAngle+=pos - allLinesStart;
            }
        }
    }

    if(allLines){
        allSectorsAngle += 2*M_PI-allLinesStart;
    }

    double S = (pow(r.second,2) - pow(r.first,2))*(allSectorsAngle/2);
    //output
    output << std::fixed << std::setprecision( 10 ) << S << std::endl;
}
