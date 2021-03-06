/**********************************************************************************
*  MIT License                                                                    *
*                                                                                 *
*  Copyright (c) 2018 Vahan Aghajanyan <vahancho@gmail.com>                       *
*                                                                                 *
*  Permission is hereby granted, free of charge, to any person obtaining a copy   *
*  of this software and associated documentation files (the "Software"), to deal  *
*  in the Software without restriction, including without limitation the rights   *
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
*  copies of the Software, and to permit persons to whom the Software is          *
*  furnished to do so, subject to the following conditions:                       *
*                                                                                 *
*  The above copyright notice and this permission notice shall be included in all *
*  copies or substantial portions of the Software.                                *
*                                                                                 *
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
*  SOFTWARE.                                                                      *
***********************************************************************************/

#ifndef COORDINATE_H
#define COORDINATE_H

namespace erkir
{

//! Implements the geographical coordinate abstraction.
class Coordinate
{
public:
  //! Constructs a coordinate by the given decimal degrees.
  Coordinate(double degrees);

  //! Returns this coordinate's value in decimal degrees.
  double degrees() const;

  //! Returns this coordinate's value in radians.
  double radians() const;

  /// A helper function to convert radians to degrees.
  static double toDegrees(double radians);

  /// A helper function to convert degrees to radians.
  static double toRadians(double degrees);

  static double pi();

private:
  double m_degrees;
};

class Latitude : public Coordinate
{
public:
  Latitude(double degree);
};

class Longitude : public Coordinate
{
public:
  Longitude(double degree);
};

}

#endif // COORDINATE_H
