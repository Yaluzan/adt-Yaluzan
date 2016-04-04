#include "../include/Force.hpp"

const Force Force::NEWTON(1);
Force::Force(double val):value{val}{
}

Force::Force():value{0}{}

Force & Force::operator= (const Force & rhs){
  value = rhs.value;
  return *this;
}

bool Force::operator< (const Force & rhs) const{
  return (value < rhs.value);
}

bool Force::operator> (const Force & rhs) const{
  return (value > rhs.value);
}

Force Force::operator+ ( const Force & rhs ) const{
  return Force{value + rhs.value};
}

Force & Force::operator+= ( const Force & rhs){
  value += rhs.value;
  return *this;
}

Force Force::operator- ( const Force & rhs ) const{
  return Force{value - rhs.value};
}

Force & Force::operator-= ( const Force & rhs ){
  value -= rhs.value;
  return *this;
}

Force Force::operator* ( const double & rhs ) const{
  return Force{value * rhs};
}

Force & Force::operator*= ( const double & rhs ){
  value *= rhs;
  return *this;
}

Force operator* ( double n, const Force & rhs ){
  return Force{rhs.value * n};
}

Force Force::operator/ ( const double & rhs ) const{
  return Force{value / rhs};
}


Force & Force::operator/= ( const double & rhs ){
  value /= rhs;
  return *this;
}

double Force::operator/ ( const Force & rhs){
  double temp = value;
  if(rhs.value != 0) {
    temp = temp / rhs.value;
  }
  return temp; 
}

std::ostream& operator<<(std::ostream & os, const Force &rhs){
  os <<  rhs.value << "N";
}

std::istream& operator>>(std::istream & is, Force & rhs){
  double value;
   std::string suffix;
   // Read the value, and remove any trailing whitespace.
   is >> value >> std::ws;
   if (!is) {
      throw std::runtime_error{"Force: Reached end of stream before fully reading a Force."};
   }
   // Construct the metric suffix.
   while(1) {
      char temp;
      // The end of the stream might coincidence with the end of the metric specifier.
      // As such do not throw an exception but test the current stream.
      if (is >> temp) {
         // A suffix for metric values only consist out of alphabetic characters;
         // anything else could indicate the end of this suffix, and should be put back.
         if (isalpha(temp)) {
            suffix += temp;
         } else {
            // That character is not supposed to be used by this stream;
            // put it back, as some other stream might rely on it.
            is.putback(temp);
            break;
         }
      } else {
         // No point in reading from an empty or corrupt stream.
         break;
      }
   }
   // Specifies all available suffixes, and which value corresponds to it.
   const struct {std::string suffix; const Force & factor;} possible_suffixes[] = {
         {"N", Force::NEWTON}
   };
   for (const auto & possibility : possible_suffixes) {
      if (suffix == possibility.suffix) {
         rhs = value * possibility.factor;
         return is;
      }
   }
   throw std::runtime_error{"Length: Either stream ended, or none of the known extensions match the specified one."};
}


Force operator* ( const Weight & lhs, const Acceleration & rhs){
  double w = lhs/Weight::KILOGRAM;
  Speed one = 1 * Length::METER/Duration::SECOND;
  Acceleration ac = one/Duration::SECOND;
  double a = rhs/ac;
  //std::cout << "created with force with double: " << w << " * " << a << ": " << w * a << std::endl;
  return Force{w * a};
}