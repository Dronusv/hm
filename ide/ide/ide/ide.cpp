
#include<fstream>
#include <iostream>

int main()
{
    std::ifstream in("in.txt");
    int N;
    in >> N;
    int* massN = new int[N];
    for (int i = 0; i < N; ++i) {
        in >> massN[i];
    }
    int M;
    in >> M;
    int* massM = new int[M];
    for (int i = 0; i < M; ++i) {
        in >> massM[i];
    }
    std::ofstream out("out.txt");
    out << M << std::endl;
    out << massM[M - 1]<<" ";
    for (int i = 0; i < M - 1; ++i) {
        out << massM[i]<<" ";
    }
    out<<std::endl;
    out << N << std::endl;
    for (int i = 1; i < N; ++i) {
        out << massN[i] << " ";
    }
    out << massN[0];
    out.close();
    in.close();
    delete[]massN;
    delete[]massM;
}

