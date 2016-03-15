//! @file coordinate.hpp
//! @author Matthijs Mud
//! @date March 15th, 2016
//! @version 1.0

#ifndef COORDINATE_HPP
#define COORDINATE_HPP
#include <iostream>

namespace r2d2 {
   namespace adt {
      // Forward declaration.
      class distance;
      class length; // TODO: Replace with an import, as it should become a component of this.
      
       //! @class coordinate
       //! @brief A location in space, specified as an offset to an arbitrary origin.
       //!
       //! The offset to the origin is given in meters.
      class coordinate {
         friend distance;
      private:
         double x;
         double y;
         double z;
      private:
         coordinate(double x, double y, double z);
      public:
         //! @brief Copies the fields from the right hand side into this,
         //! and returns a reference to this.
         //!
         //! @param rhs Object from which to copy the values.
         //! @return Reference to the left hand side of the operator.
         coordinate & operator =(const coordinate & rhs);
         
         //! @brief Adds the distance to this coordinate,
         //! and returns a reference to it.
         //!
         //! @param rhs Distance to add to this coordinate.
         //! @return Reference to this coordinate.
         coordinate & operator +=(const distance & rhs);
         
         //! @brief Substracts the given distance from this coordinate,
         //! and returns a reference to it.
         //!
         //! @param rhs Distance to subtract from this coordinate.
         //! @return Reference to this coordinate.
         coordinate & operator -=(const distance & rhs);
         
         //! @brief Gets the coordinate at the given distance from this coordinate.
         //! 
         //! @param rhs Distance to add to this coordinate.
         //! @return The coordinate at the given distance from this coordinate.
         coordinate operator +(const distance & rhs) const;
         
         //! @brief Gets the coordinate at the given distance from this coordinate.
         //! 
         //! @param rhs Distance to subtract from this coordinate.
         //! @return The coordinate at the given distance from this coordinate.
         coordinate operator -(const distance & rhs) const;
         
         //! @brief Gets the distance the other coordinate is away from this coordinate.
         //!
         //! @param rhs Other coordinate which is used to determine the distance.
         //! @return Distance from this coordinate to the other.
         distance operator -(const coordinate & rhs) const;
         
         //! @brief Writes the specified coordinate to the std::ostream, returning that stream.
         //!
         //! The output is given in the format "coordinate(xm, ym, zm)", 
         //! where the 'x', 'y' and 'z' are replaced by the offsets to the origin.
         //! @param lhs Stream to which to write the string representation of the coordinate.
         //! @param rhs Reference to the object to write to the outputstream.
         //! @return Reference to the stream passed in by lhs.
         //! @see operator>>(std::istream, const r2d2::adt::coordinate &)
         friend std::ostream & operator <<(std::ostream & lhs, const coordinate & rhs);
         
         //! @brief Reads a coordinate from the given input stream, returning said stream.
         //!
         //! The input should be given in the format "coordinate(z m, y m, z m)",
         //! ignoring the quotes. The values 'x', 'y' and 'z' should be replaced with floating point values.
         //! Any excess whitespace is ignored. As of now, only meter is supported; other metric prefixes fail.
         //! @param lhs Stream from which to read data
         //! @param rhs Reference to an uninitialized coordinate to overwrite.
         //! @return Reference to the stream passed in by lhs.
         //! @see operator<<(std::ostream &, r2d2::adt::coordinate &)
         friend std::istream & operator >>(std::istream & lhs, coordinate & rhs);
         
         //! @brief The arbitrary origin to be used.
         static const coordinate origin;
      };
   }
}

#endif // COORDINATE_HPP
