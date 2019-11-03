#ifndef POINT_H
#define POINT_H
#include <Eigen/Eigen>

class Point
{
public:
    typedef Eigen::Vector3f Pose;
    typedef Eigen::Vector3i Color;

    Point();
    ~Point();
    inline double* getMutable() { return m_p; }

    //for viewer
    float pointSize; //in meter
    Pose pose;
    Color color;
private:
    double *m_p;

};

typedef std::vector<Point> PointVector;
typedef std::map<unsigned int,Point*> PointPtrMap;

#endif // POINT_H
