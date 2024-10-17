/*
 * --------------------------------------------------------------
 * Trabalho 2 de Sistemas Operacionais - FIFO | OTM | LRU
 * Professor: Fernando Menezes Matos
 * Alunos: João Victor Freir e Matheus de Mendonça
 *
 * Compilação:
 * Win: g++ -o escalonador .\escalonador.cpp
 * Mac: g++ -std=c++11 escalonador.cpp -o escalonador
 * 
 * Execução:
 * Win: .\escalonador.exe 
 * Mac: ./escalonador
 * --------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;

void readInput(const string& filename, int& frames, vector<int>& pages) {
    ifstream infile(filename);
    
    if (!infile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    infile >> frames;  // Primeiro número é o número de quadros
    int temp;
    while (infile >> temp) {
        pages.push_back(temp);  // Lê as páginas subsequentes
    }
    
    infile.close();
}

// FIFO Algorithm
int FIFO(vector<int>& pages, int frames) {
    queue<int> memory;
    set<int> mem_set;
    int faults = 0;
    
    for (int page : pages) {

        if (mem_set.find(page) == mem_set.end()) {  
            if (memory.size() == frames) {
                int removed = memory.front();
                memory.pop();
                mem_set.erase(removed);
            }
            memory.push(page);
            mem_set.insert(page);
            faults++;
        }

    }
    
    return faults;
}

// Optimal Algorithm (OTM)
int OTM(vector<int>& pages, int frames) {
    vector<int> memory;
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        if (find(memory.begin(), memory.end(), page) == memory.end()) {
              
            if (memory.size() == frames) {
                // Acha a página para substituir
                int farthest = -1, replace_index = -1;
                for (int j = 0; j < memory.size(); j++) {

                    int next_use = 999;
                    for (int k = i + 1; k < pages.size(); k++) {
                        if (memory[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if (next_use > farthest) {
                        farthest = next_use;
                        replace_index = j;
                    }
                }
                memory[replace_index] = page;
            } else {
                memory.push_back(page);
            }

            faults++;
        }

    }
    
    return faults;
}

int LRU(vector<int>& pages, int frames) {
    vector<int> memory;
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        
        if (find(memory.begin(), memory.end(), page) == memory.end()) {

            if (memory.size() == frames) {
                int lru_page = -1, lru_index = i;  
                
                // Encontrar a página menos recentemente usada
                for (int mem_page : memory) {
                    
                    for (int j = i - 1; j >= 0; j--) {

                        if (pages[j] == mem_page) {
                            if (j < lru_index) {
                                lru_page = mem_page;
                                lru_index = j;
                            }
                            break;
                        }
                    }
                }

                replace(memory.begin(), memory.end(), lru_page, page);
            } else {
                memory.push_back(page);
            }

            faults++;
        }
    }

    return faults;
}

int main() {
    int frames;
    string filename = "test2.txt";
    vector<int> pages;

    readInput(filename, frames, pages);

    // Example input
    /*cin >> frames;
    while (cin >> temp) {
       // pages.push_back(temp);
    }*/
    
    cout << "FIFO " << FIFO(pages, frames) << endl;
    cout << "OTM " << OTM(pages, frames) << endl;
    cout << "LRU " << LRU(pages, frames) << endl;

    return 0;
}


