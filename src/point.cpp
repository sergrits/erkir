#include <cmath>
#include "point.h"

namespace geodesy
{

Point::Point(const Latitude &latitude, const Longitude &longitude)
  :
    m_latitude(latitude),
    m_longitude(longitude)
{
}

const Latitude &Point::latitude() const
{
  return m_latitude;
}

const Longitude &Point::longitude() const
{
  return m_longitude;
}

double Point::sphericalDistanceTo(const Point &point, double radius) const
{
  // see mathforum.org/library/drmath/view/51879.html for derivation

  auto phi1 = m_latitude.radians();
  auto lambda1 = m_longitude.radians();
  auto phi2 = point.latitude().radians();
  auto lambda2 = point.longitude().radians();
  auto deltaPhi = phi2 - phi1;
  auto deltaLambda = lambda2 - lambda1;

  auto a = std::sin(deltaPhi / 2.0) * std::sin(deltaPhi / 2.0) +
           std::cos(phi1) * std::cos(phi2) *
           std::sin(deltaLambda / 2.0) * std::sin(deltaLambda / 2.0);
  auto c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

  return radius * c;
}

double Point::sphericalBearingTo(const Point &point) const
{
  // see mathforum.org/library/drmath/view/55417.html for derivation

  auto phi1 = m_latitude.radians();
  auto phi2 = point.latitude().radians();
  auto deltaLambda = point.longitude().radians() - longitude().radians();
  auto y = std::sin(deltaLambda) * std::cos(phi2);
  auto x = std::cos(phi1) * std::sin(phi2) -
           std::sin(phi1) * std::cos(phi2) * std::cos(deltaLambda);
  auto theta = std::atan2(y, x);

  return fmod(Coordinate::toDegrees(theta) + 360.0, 360.0);
}

double Point::sphericalFinalBearingTo(const Point &point) const
{
  // get initial bearing from destination point to this point & reverse it by adding 180�
  return fmod(point.sphericalBearingTo(*this) + 180.0, 360.0);
};

}
