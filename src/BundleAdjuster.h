//
// Created by jojo on 22.01.20.
//

#ifndef BAMAPPING_BUNDLEADJUSTER_H
#define BAMAPPING_BUNDLEADJUSTER_H

#include "Graph.h"
#include "Error.h"

#include "util/Parser.h"

#include "ceres/ceres.h"
#include <vector>
namespace BAMapping
{
    class BundleAdjuster
    {
    public:
        static void optimizePose(Mat4& Tcw, const Vec4& intrinsics, const std::vector<Vec3>& obs_vec, const std::vector<Vec3>& ref_points);
        static void optimizePose(Mat4& Twc, const Mat4& Twc_ref,const Vec4& intrinsics, const std::vector<Vec3>& obs_vec, const std::vector<Vec3>& ref_obs_vec);

        static void optimize(Graph& graph, const char* config_file,const bool fix_seperators);
        static void optimizeGlobal(Graph& graph, const char* config_file,
                const std::vector<std::string>& plyNames = std::vector<std::string>());
        static std::vector<Vec6> packCameraParam(const Graph& graph);
        static std::vector<Vec3> packPointParam(const Graph& graph);
        static std::vector<Vec4> getIntrinsics(Parser config, size_t n);

        static void unpackCameraParam(Graph& graph, const std::vector<Vec6>& extrinsics);
        static void unpackPointParam(Graph& graph, const std::vector<Vec3>& points);
    };
}



#endif //BAMAPPING_BUNDLEADJUSTER_H
