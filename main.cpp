#include <iostream>
using namespace std;

///###############################################################################
///                                 Introduction                                 #
///###############################################################################
//--------------------------------------------------------------------------------
//Copyright: Gabriel Pacheco 2021

//Task 4: Demonstrate technique selection and implementation skills 2

//Project: This project demonstrates the development of a templated function
//         and an specialized templated function. The templated function will
//         receive arrays of different types (int, float, double) as an argument
//         to see if a 3D point is on the right or left side of a plane formed
//         by another three 3D points. The specialized templated function
//         serves the same purpose but in this case the 3D points will be
//         stored in structs.

//Structs developed:
    struct point; //Struct that holds the x,y,z coordinates for a 3D point

//Functions developed: (member functions defined inside struct/class)
    //This function returns "1" or "0" depending on which side of the plane point D is at
    template <typename T> bool orient3d(const T* const pa, const T* const pb, const T* const pc, const T* const pd);

    //This function returns "1" or "0" depending on which side of the plane point D is at.
    //Specialized to receive structs as argument.
    bool orient3d (const point &pa, const point &pb, const point &pc, const point &pd);

//Warnings:
//(1) Please be aware that struct is not templated as this was not
//    requested by the client. Therefore please be aware that all
//    instances of the object "point" will be constructed with doubles.

//--------------------------------------------------------------------------------
//Testing: When the 3D points are inputted into the functions as arguments, the
//         same will return either a "0" or a "1" which will indicate to which side
//         of the plane formed by A,B,C point D is located. If initialized with the
//         same values for x,y,z for both the array and the struct the answer will
//         be the same, testing data can be seen down below. If the program is run,
//         the numeric array will lead to the first result of "0" and the struct
//         will lead to the second result of "1", if  both had the same data they
//         would lead to the same result.

//         Data Points:                     Result:

//         point A = (3,19,22)                 0
//         point B = (4,56,12)
//         point C = (4,-5,2)
//         point D = (-23,44,1)

//         point A = (3,19,22)                 1
//         point B = (4,56,12)
//         point C = (4,-5,2)
//         point D = (12,-32,17)

//--------------------------------------------------------------------------------
///###############################################################################
///                                    Code                                      #
///###############################################################################

struct point
{
    public:
        ///--Default Constructor
        point() : x(0),y(0),z(0){}

        ///--Obvious Constructor
        point(const double _x, const double _y, const double _z) :  x(_x), y(_y), z(_z){}

        ///--Get functions
        double getX() const { return x; }
        double getY() const { return y; }
        double getZ() const { return z; }

    private:
        double x,y,z;
};

//--------------------------------------------------------------------------------
//Template for all numeric data types
template <typename T> bool orient3d(const T* const pa, const T* const pb, const T* const pc, const T* const pd)
{
    cout<<"Template for numeric data types"<<endl;

    const T adx(pa[0]-pd[0]);
    const T bdx(pb[0]-pd[0]);
    const T cdx(pc[0]-pd[0]);
    const T ady(pa[1]-pd[1]);
    const T bdy(pb[1]-pd[1]);
    const T cdy(pc[1]-pd[1]);
    const T adz(pa[2]-pd[2]);
    const T bdz(pb[2]-pd[2]);
    const T cdz(pc[2]-pd[2]);

    return (adx*(bdy*cdz-bdz*cdy)+bdx*(cdy*adz-cdz*ady)+cdx*(ady*bdz-adz*bdy)>0);
}

//--------------------------------------------------------------------------------
//Template for structures. The maths realized in this function are the same ones
//to the ones that were done in the previous function, yet in this function the
//data in order to do the calculations must be obtained through member functions
//which belong to the point structure.
bool orient3d (const point &pa, const point &pb, const point &pc, const point &pd)
{
    cout<<"\nSpecialized template for structures"<<endl;
    const double adx(pa.getX()-pd.getX());
    const double bdx(pb.getX()-pd.getX());
    const double cdx(pc.getX()-pd.getX());
    const double ady(pa.getY()-pd.getY());
    const double bdy(pb.getY()-pd.getY());
    const double cdy(pc.getY()-pd.getY());
    const double adz(pa.getZ()-pd.getZ());
    const double bdz(pb.getZ()-pd.getZ());
    const double cdz(pc.getZ()-pd.getZ());

    return (adx*(bdy*cdz-bdz*cdy)+bdx*(cdy*adz-cdz*ady)+cdx*(ady*bdz-adz*bdy)>0);
}

//--------------------------------------------------------------------------------

int main()
{
//In this main the initialization of the 3D points will be seen with the data being
//held in numeric arrays and in structures. The result stored in "answerOne" is the
//result from the function utilized for numeric data types, while the result stored
//in "answerTwo" is the result from the specialized templated function.

    //Data points defined by numeric type data arrays
    const int dataA [] = {3,19,22};
    const int dataB [] = {4,56,12};
    const int dataC [] = {4,-5,2};
    const int dataD [] = {-23,44,1};

    //Data points held in a structure
    const point A(3,19,22);
    const point B(4,56,12);
    const point C(4,-5,2);
    const point D(12,-32,17);

    //Testing answers
    bool answerOne = orient3d <int> (dataA, dataB, dataC, dataD);
    cout<<"Answer: "<<answerOne<<endl;
    bool answerTwo = orient3d (A,B,C,D);
    cout<<"Answer: "<<answerTwo<<endl;
}
