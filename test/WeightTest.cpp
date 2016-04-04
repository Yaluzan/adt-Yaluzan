#include "gtest/gtest.h"
#include "../source/include/Weight.hpp"
#include <iostream>

//constructors
TEST(Weight, DefaultConstructor){
	Weight w;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 0) << "Weight";
}

TEST(Weight, doubleConstructor){
	Weight w{5};
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 5) << "Weight";
}

//Operatoren:
TEST(Weight, AssignWeight){
	Weight w;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 0) << "Empty weight";
	w = 2 * Weight::KILOGRAM;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 2) << "Assigned";
}

TEST(Weight, AddWeight) { 						//operator+
	// leeg + leeg
	Weight a = 0 * Weight::KILOGRAM;
	Weight b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0.0) << "empty+empty";
	
	// leeg + vol
	Weight c = 2 * Weight::KILOGRAM;
	b = b + c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 2.0) << "empty+full";
	
	// vol + vol
	Weight d = 3 * Weight::KILOGRAM;
	d = d + c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 5.0) << "full+full";
}

TEST(Weight, SubstractWeight) { 				//operator-
	// leeg - leeg
	Weight a{};
	Weight b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0.0) << "empty-empty";
	
	// leeg - vol
	Weight c = 2 * Weight::KILOGRAM;
	b = b - c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c = c - a;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 2.0) << "full-empty";
	
	// vol - vol
	Weight d = 1 * Weight::KILOGRAM;
	d = d - c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , -1.0) << "full-full neg";
	Weight e= 3 * Weight::KILOGRAM;
	Weight f= 2 * Weight::KILOGRAM;
	e = e - f;
 	ASSERT_DOUBLE_EQ(e/Weight::KILOGRAM , 1.0) << "full-full";
}

TEST(Weight, MultiplyWeightDouble) { 						//operator* (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Weight a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty*0 Weight";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty Weight";
		
	// vol * 0
	Weight b =1 * Weight::KILOGRAM;
	b = b * 0;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 0) << "full*0 Weight";
		
	// vol * getal1
	Weight c =2 * Weight::KILOGRAM;
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 4) << "full*getal1 Weight";
	
	// vol * getal2
	Weight d =3  * Weight::KILOGRAM;
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 7.5) << "full * getal2 Weight";

}

TEST(Weight, MultiplyDoubleWeight) { 						//operator* (2)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Weight a;
	a = 0 * a;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty*0 Weight";
	
	// leeg * getal1
	a = getal1 * a;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty Weight";
		
	// vol * 0
	Weight b =1 * Weight::KILOGRAM;
	b = 0 * b;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 0) << "full*0 Weight";
		
	// vol * getal1
	Weight c =2 * Weight::KILOGRAM;
	c = getal1 * c;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 4) << "full*getal1 Weight";
	
	// vol * getal2
	Weight d =3  * Weight::KILOGRAM;
	d = getal2 * d;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 7.5) << "full * getal2 Weight";

}

TEST(Weight, DivideDouble) { 					//operator/ (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Weight a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty / 0 Weight";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty x";
	
	// vol / 0
	Weight b = 1 * Weight::KILOGRAM;
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 1) << "full / 0 Weight";
	
	// vol / getal1
	Weight c = 1 * Weight::KILOGRAM;
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 0.5) << "full / getal1 Weight";
	
	// vol / getal2
	Weight d =1 * Weight::KILOGRAM;
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 0.4) << "full / getal2 Weight ";
	
}

TEST(Weight, DivideWeight) { 					//operator/ (2)
    Weight a;
	Weight d;
	Weight b = 4 * Weight::KILOGRAM;
	Weight c = 2 * Weight::KILOGRAM;
	
	// leeg / leeg
	double z = a / d;		// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(z , 0) << "empty / empty";	
	
	// vol / leeg
	z = b / a;
	ASSERT_DOUBLE_EQ(z , 4) << "full / empty";
	
	// vol / vol
	z = b / c;
	ASSERT_DOUBLE_EQ(z , 2) << "full / full";	
}

TEST(Weight, AddAssignWeight) {					//operator+=
	// leeg + leeg
	Weight a;
	Weight b;
	a += b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty+empty";
	
	// leeg + vol
	Weight c = 2  * Weight::KILOGRAM;
	b += c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 2) << "empty+full";
	
	// vol + vol
	Weight d = 3 * Weight::KILOGRAM;
	d += c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 5) << "full+full"; 
}

TEST(Weight, SubtractAssignWeight) { 			//operator-=
	// leeg - leeg
	Weight a;
	Weight b;
	a -= b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty-empty";
	
	// leeg - vol
	Weight c = 2  * Weight::KILOGRAM;
	b -= c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c -= a;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 2) << "full-empty";
	
	// vol - vol
	Weight d = 1 * Weight::KILOGRAM;
	d -= c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , -1) << "full-full neg";
	Weight e = 5 * Weight::KILOGRAM;
	Weight f = 3 * Weight::KILOGRAM;
	e -= f;
	ASSERT_DOUBLE_EQ(e/Weight::KILOGRAM , 2) << "full-full";
}	

TEST(Weight, GreaterThan) { 				//operator>
	Weight a(2 * Weight::KILOGRAM);
	Weight b(1 * Weight::KILOGRAM);
	ASSERT_TRUE(a > b) << "greater than";
	ASSERT_FALSE(b > a) << "less than";
}

TEST(Weight, LessThan) { 					//operator>
	Weight a(1 * Weight::KILOGRAM);
	Weight b(2 * Weight::KILOGRAM);
	ASSERT_TRUE(a < b) << "greater than";
	ASSERT_FALSE(b < a) << "less than";
}