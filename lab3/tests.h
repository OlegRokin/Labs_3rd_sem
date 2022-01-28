#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "graph.cpp"
#include "extra.h"
#include <fstream>
#include <string>
#include <chrono>

void WriteIntoFile(string file_name) {
    ofstream file;
    file.open(file_name);

    file << "Directed Graph - Find the shotest way; Elements; Time (ms)" << endl;
    for (int i = 0; i < 20; ++i) {
        auto time_total = 0;
        int iterations = 2;
        for (int j = 0; j < iterations; ++j) {
            //Graph<int> graph = GenerateGraphRand(1000 + 1000 * i, 1);
            Graph<int> graph(GenerateGraphRand(1000 + 1000 * i, true));
            cout << "DEBUG0 - " << i << endl;
            auto t_1 = std::chrono::high_resolution_clock::now();
            graph.FindShortest(0);
            auto t_2 = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
            time_total += time;
            cout << "DEBUG1 - " << i << endl;
        }

        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
    }
    file << endl;

//    file << "Directed Graph - Find the shotest way; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            //Graph<int> graph = GenerateGraphDef(1000 + 1000 * i, 1, 1);
//            Graph<int> graph(GenerateGraphDef(1000 + 1000 * i, true, 1));
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindShortest(0);
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Directed Graph - Find the shotest way; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            //Graph<int> graph = GenerateGraphDef(1000 + 1000 * i, 1, 0);
//            Graph<int> graph(GenerateGraphDef(1000 + 1000 * i, true, 0));
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindShortest(0);
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find the shotest way; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            //Graph<int> graph = GenerateGraphRand(1000 + 1000 * i, 0);
//            Graph<int> graph(GenerateGraphRand(1000 + 1000 * i, false));
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindShortest(0);
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find the shotest way; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            Graph<int> graph = GenerateGraphDef(1000 + 1000 * i, false, 1);
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindShortest(0);
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find the shotest way; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            Graph<int> graph = GenerateGraphDef(1000 + 1000 * i, false, 0);
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindShortest(0);
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file <<";" << 1000 + 1000 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find a skeleton; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            Graph<int> graph = GenerateGraphRand(100 + 100 * i, false);

//            //bool connected = false;
////            Graph<int> graph(100 + 100 * i, 0);
////            do {
////                graph = GenerateGraphRand(100 + 100 * i, 0);
////                //connected = graph.IsConnected();
////            } while(!graph.IsConnected());
//            //while(!graph.IsConnected()) {
//                graph = GenerateGraphRand(100 + 100 * i, 0);
//            //}

//            auto t_1 = std::chrono::high_resolution_clock::now();
//            graph.FindSkeleton();
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file << ";" << 100 + 100 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find a skeleton; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            Graph<int> graph = GenerateGraphDef(100 + 100 * i, false, 1);
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            /*Graph<int> skeleton = */graph.FindSkeleton();
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file << ";" << 100 + 100 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

//    file << "Undirected Graph - Find a skeleton; Elements; Time (ms)" << endl;
//    for (int i = 0; i < 20; ++i) {
//        auto time_total = 0;
//        int iterations = 2;
//        for (int j = 0; j < iterations; ++j) {
//            Graph<int> graph = GenerateGraphDef(100 + 100 * i, false, 0);
//            auto t_1 = std::chrono::high_resolution_clock::now();
//            /*Graph<int> skeleton = */graph.FindSkeleton();
//            auto t_2 = std::chrono::high_resolution_clock::now();
//            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t_2 - t_1).count();
//            time_total += time;
//        }

//        file << ";" << 100 + 100 * i << ";" << time_total / iterations << endl;
//    }
//    file << endl;

}

#endif // TESTS_H
