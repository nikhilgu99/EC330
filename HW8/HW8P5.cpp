/*
* NAME: Nikhil Gupta	BUID: U86132587 
* COLLABORATOR: Sharith Godamanna
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <limits.h>
#include <utility>

using namespace std;

class Graph
{
    public:
        vector<vector<int>> costMatrix; 
        vector<string> startCities;

        int V = 0;

        Graph(const char* filename)
        {
            ifstream file(filename);

            string start = "";
            string end = "";
            string arrow = "";

            int cost = 0;
            int index = 0;

            bool inCities = false;
            bool firstRun = true;
            bool foundStart = false;
            bool foundEnd = false;
            int startIndex = -1;
            int endIndex = -1;

            if(file.is_open())
            {
                while(!file.eof())
                {
                    file >> start;
                    file >> arrow;
                    file >> end;
                    file >> cost;

                    if(firstRun){
                        startCities.push_back(start);
                        firstRun = false;
                    }else{
                        for(int i = 0; i < startCities.size(); i++){
                            if(startCities[i] == start){
                                inCities = true;
                                break;
                            }
                        }
                        if(!inCities){
                            startCities.push_back(start);
                        }
                        inCities = false;
                    }
                }

                file.clear();
                file.seekg(0, file.beg);
                costMatrix.resize(startCities.size(), vector<int>(startCities.size(), INT_MAX));

                while(!file.eof()){
                    file >> start;
                    file >> arrow;
                    file >> end;
                    file >> cost;

                    end = end.substr(0, 4);

                    for(int i = 0; i < startCities.size(); i++){
                        if(!foundStart){
                            if(startCities[i] == start){
                                foundStart = true;
                                startIndex = i;
                            }
                        }
                        if(!foundEnd){
                            if(startCities[i] == end){
                                foundEnd = true;
                                endIndex = i;
                            }
                        }
                        if(foundEnd && foundStart)
                        {
                            break;
                        }
                    }

                    if(costMatrix[startIndex][endIndex] > cost){
                        costMatrix[startIndex][endIndex] = cost;
                    }
                    if(costMatrix[endIndex][startIndex] > cost){
                        costMatrix[endIndex][startIndex] = cost;
                    }

                    foundEnd = false;
                    foundStart = false;
                }
            }

            V = startCities.size();
        }
        void doPrims() //Used Prim's algorithm
        {
            int keys[V];
            int predecessors[V];
            bool visited[V];

            for(int i = 0; i < V; i++){
                keys[i] = INT_MAX;
                visited[i] = false;
            }

            keys[0] = 0;
            
            int minKey = 0;
            int minIndex = 0;

            for(int i = 0; i < V - 1; i++) {

                minKey = INT_MAX;

                for(int j = 0; j < V; j++){
                    if(!visited[j] && keys[j] < minKey){
                        minKey = keys[j];
                        minIndex = j;
                    }
                }

                visited[minIndex] = true;

                for(int j = 0; j < V; j++){
                    if(!visited[j] && costMatrix[minIndex][j] < keys[j]){
                        keys[j] = costMatrix[minIndex][j];
                        predecessors[j] = minIndex;
                    }
                }
            }

            vector<int> noChildren;
            bool noChildrenBool;

            for(int i = 0; i < V; i++){

                noChildrenBool = true;

                for(int j = 0; j < V; j++){
                    if(i == predecessors[j]){
                        noChildrenBool = false;
                        break;
                    }
                }

                if(noChildrenBool){
                    noChildren.push_back(i);
                }
            }

            list<int> tempPath;
            list<int> totalPath;

            int totalCost = 0;
            int cost = 0;
            int last = 0;
            int current = 0;

            for(int i = 0; i < noChildren.size(); i++){
                tempPath.push_back(noChildren[i]);
                last = noChildren[i];
                cost = 0;

                while(true){
                    current = predecessors[last];
                    cost += costMatrix[last][current];
                    tempPath.push_back(current);
                    if(current == 0){
                        break;
                    }else{
                        last = current;
                    }
                }

                totalCost += (2 * cost);

                tempPath.reverse();
                totalPath.insert(totalPath.end(), tempPath.begin(), tempPath.end());
                tempPath.reverse();
                totalPath.insert(totalPath.end(), tempPath.begin(), tempPath.end());
                tempPath.clear();
            }

            int prev = 0;

            for(list<int>::iterator iter = totalPath.begin(); iter != totalPath.end(); iter++){
                if(iter != totalPath.begin()){
                    if(*iter == prev){
                        *iter = -1;
                    }
                }
                prev = *iter;
            }
            totalPath.remove(-1);

            // Output path to path.txt
            ofstream file("path.txt");
            file << "COST: $" << totalCost << "\n" <<endl;
            for(list<int>::iterator iter = totalPath.begin(); iter!= totalPath.end(); iter++)
            {
                file << startCities[*iter] << endl;
            }
        }
};

int main()
{
    Graph graph("map.txt");
    graph.doPrims();

    return 0;
}
