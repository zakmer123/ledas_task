#define _USE_MATH_DEFINES

#include "Vector3D.h"
#include "Segment3D.h"

int main(){
    //примеры
    
    //Segment3D s1(Vector3D(0, 0, 0), Vector3D(0, 0, 0));
    //Segment3D s2(Vector3D(0, 0, 0), Vector3D(2, 2, 2));
    ////Intersection is: (0,0,0)
    // 
    //Segment3D s1(Vector3D(2, 2, 2), Vector3D(2, 2, 2));
    //Segment3D s2(Vector3D(0, 0, 0), Vector3D(2, 2, 2));
    ////Intersection is: (2,2,2)
    // 
    //Segment3D s1(Vector3D(3, 3, 3), Vector3D(3, 3, 3));
    //Segment3D s2(Vector3D(0, 0, 0), Vector3D(2, 2, 2));
    ////No intersection
    // 
    //Segment3D s1(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    //Segment3D s2(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    ////Intersection is: (1,1,1)
    // 
    //Segment3D s1(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    //Segment3D s2(Vector3D(2, 2, 2), Vector3D(2, 2, 2));
    ////No intersection
    //
    //Segment3D s1(Vector3D(1, 2, 3), Vector3D(4, 2, 3)); 
    //Segment3D s2(Vector3D(2, 1, 5), Vector3D(2, 4, 5));
    ////No intersection
    //
    //Segment3D s1(Vector3D(1, 1, 1), Vector3D(3, 3, 1)); 
    //Segment3D s2(Vector3D(1, 3, 3), Vector3D(3, 1, 2));
    ////No intersection
    //
    //Segment3D s1(Vector3D(std::sqrt(2), std::sqrt(3), 1),
    //    Vector3D(2 * std::sqrt(2), 2 * std::sqrt(3), 1)); 
    //Segment3D s2(Vector3D(std::sqrt(2), std::sqrt(3), 3),
    //    Vector3D(2 * std::sqrt(2), 2 * std::sqrt(3), 5));
    ////No intersection
    //
    //Segment3D s1(Vector3D(1, 2, 3), Vector3D(4, 5, 6));
    //Segment3D s2(Vector3D(2, 3, 4), Vector3D(3, 4, 5));
    ////Intersection is: (2,3,4)
    //
    //Segment3D s1(Vector3D(1, 2, 3), Vector3D(2, 3, 4));
    //Segment3D s2(Vector3D(3, 4, 5), Vector3D(4, 5, 6));
    ////No intersection
    
    //Segment3D s1(Vector3D(std::sqrt(2), 2, 3), Vector3D(3 * std::sqrt(2), 4, 3));
    //Segment3D s2(Vector3D(std::sqrt(2), 4, 3), Vector3D(3 * std::sqrt(2), 2, 3));
    ////Intersection is: (2.82843,3,3)
    
    //Segment3D s1(Vector3D(1, 2, std::sqrt(5)), Vector3D(3, 4, std::sqrt(5)));
    //Segment3D s2(Vector3D(4, 3, std::sqrt(5)), Vector3D(6, 5, std::sqrt(5)));
    ////No intersection
    //

    Segment3D s1(Vector3D(1, 2, std::sqrt(5)), Vector3D(3, 4, std::sqrt(5)));
    Segment3D s2(Vector3D(3, 4, std::sqrt(5)), Vector3D(5, 6, std::sqrt(5)));
    //Intersection is: (3,4,2.23607)

    std::optional<Vector3D> intersec = s1.intersect(s2);

    if (intersec) {
        std::cout << "Intersection is: ";
        intersec.value().print();
    }
    else {
        std::cout << "No intersection" << std::endl;
    }

    return 0;
}
