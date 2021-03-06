//
// Created by jojo on 03.03.20.
//
#include "../io/Reader.h"
#include "../io/Writer.h"
#include "../Point.h"
#include "../Graph.h"
#include "../Frontend.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char** argv)
{
    using namespace BAMapping;
    std::string dataset_path = argv[1];
    std::string ref_cam_path = dataset_path + "cameras_reference.txt";
    std::string cam_graph_file = dataset_path + "unoptimized.json";
    std::string cam_tum_file = dataset_path + "unoptimized_tum.txt";
    std::string ref_cam_tum_file = dataset_path + "groundtruth_tum.txt";
    std::string ref_graph_file = dataset_path + "ref_graph.json";
    std::string voc_path = dataset_path + "ORBvoc.txt";
    std::string voc_path_gz = dataset_path +"ORBvoc.yml.gz";
    std::string db_path = dataset_path + "ORBdb_small.yml.gz";
    std::string obs_path = dataset_path + "observations.txt";
    std::string point_path = dataset_path + "points.txt";
    std::string cam_file = dataset_path + "cameras.txt";
    std::string cam_out_file = dataset_path + "cameras_out.txt";
    std::string config_file = dataset_path + "ITE.yaml";
    auto frameVec = io::Reader::readITEFrames(cam_file.c_str(),
                                              (dataset_path + "observations.txt").c_str(),
                                              dataset_path.c_str(),1);
    auto ref_frameVec = io::Reader::readITEFrames(ref_cam_path.c_str(),
                                              (dataset_path + "observations.txt").c_str(),
                                              dataset_path.c_str(),1);
    auto ref_pointVec = io::Reader::readPoints((dataset_path + "points.txt").c_str());

    Graph graph;
    Graph ref_graph;
    ref_graph.setGraph(ref_frameVec,{});
    graph.setGraph(frameVec,ref_pointVec);
    Graph::WriteToFile(graph,cam_graph_file.c_str());
    Graph::WriteToFile(ref_graph,ref_graph_file.c_str());
    Writer::writeToFileTUMFormat(ref_graph,ref_cam_tum_file.c_str());
    Writer::writeToFileTUMFormat(graph,cam_tum_file.c_str());
//
//    Frontend frontend;
//    std::vector<std::vector<cv::Mat > > features;
//    int id = 0;
//    for(auto& frame : frameVec)
//    {
//        std::cout<<"extracting: "<<id<<std::endl;
//        cv::Ptr<cv::ORB> orb_detector = cv::ORB::create(500);
//        frontend.ExtractORB(frame,orb_detector);
//        features.push_back(frame.mKepoint_descriptors);
//        id++;
//    }
//    OrbVocabulary voc(9,3);
//    voc.create(features);
//    voc.save(voc_path_gz);
//    frontend.ExtractAndCreateDatabase(frameVec,voc_path);
//    frontend.LoadDataBase(db_path);
//    using namespace cv;
//    int query_id;
//    Ptr<ORB> orb_detector = ORB::create(500);

//    while(1)
//    {
//        std::cin>>query_id;
//        if(query_id<0)
//            break;
//        DBoW2::QueryResults ret;
//        auto frame_q = frameVec[query_id];
////        frontend.ExtractORB(frame_q,orb_detector);
//        frontend.query(frame_q,ret);
//        std::cout<<"quering id: "<<query_id<<std::endl;
//        std::cout<<ret<<std::endl;
//        cv::Mat query_img  = cv::imread(frameVec[query_id].getInfraRedImagePath());
//        for(auto r : ret)
//        {
//            auto frame_r = frameVec[r.Id];
////            frontend.ExtractORB(frame_r,orb_detector);
//            std::vector<cv::DMatch> matches;
//            frontend.matchORB(frame_q.mDescriptior,frame_r.mDescriptior,matches);
//            cv::Mat result_img  = cv::imread(frameVec[r.Id].getInfraRedImagePath());
//            cv::Mat img3;
//            cv::drawMatches(query_img,frame_q.mKeypoints,result_img,frame_r.mKeypoints,matches,img3);
//            imshow("matches",img3);
//            cv::waitKey(0);
//        }
//        cv::destroyWindow("matches");
//    }
}
