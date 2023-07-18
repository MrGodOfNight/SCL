#include "randomizer.hpp"
#include "utilities.hpp"

namespace SCL
{
  int Randomizer::randomInt(int min, int max)
  {
    Utilities util;
    long long entropy = util.entropy;

    int answer = entropy % (entropy + 1) % max + min;
    if (answer > max) answer -= min;
    if (answer > max) answer += min;

    return answer;
  } // randomInt

  float Randomizer::randomFloat(float min, float max)
  {
    Utilities util;
    long long entropy = util.entropy;

    float answer = entropy % (entropy + 1) % (int)max / (max + 1) * (max - min) + min;
    if (answer < min) answer += max - min;

    return answer;
  } // randomFloat

  double Randomizer::randomDouble(double min, double max)
  {
    Utilities util;
    long long entropy = util.entropy;

    double answer = entropy % (entropy + 1) % (int)max / (max + 1) * (max - min) + min;
    if (answer < min) answer += max - min;

    return answer;
  } // randomDouble

  bool Randomizer::randomBool()
  {
    Randomizer rand;
    if(rand.randomInt(0, 10) >= 5) return true;
    else return false;
  } // randomBool
  
} // namespace SCL