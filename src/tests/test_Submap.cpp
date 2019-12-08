//
// Created by jojo on 07.12.19.
//
#include "../io/Reader.h"
#include "../Graph.h"
#include "../Viewer.h"
int main(int argc, char** argv)
{

    BAMapping::Graph graph;
    BAMapping::io::Reader::readITEData(&graph,"../dataset_local/ITE_dataset/cameras.txt",
                            "../dataset_local/ITE_dataset/observations.txt",
                            "../dataset_local/ITE_dataset/points.txt",
                            "../dataset_local/ITE_dataset/",
                            "../dataset_local/ITE_dataset/ITE.yaml");
    BAMapping::Graph::setAsRootGraph(&graph);
    BAMapping::Viewer viewer;
    graph.splitInto(5);
    auto submaps = graph.getSubmaps();

    viewer.setFrames(submaps[4]->getConstFrames());
    viewer.setPoints(submaps[4]->getConstPoints());
//    viewer.setFrames(graph.getConstGlobalFrames());
//    viewer.setPoints(graph.getConstGlobalPoints());
    viewer.visualize();
}