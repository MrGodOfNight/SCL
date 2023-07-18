namespace SCL
{
  /**
   * randomizer class
  */
  class Randomizer
  {
    public:

      /**
       * method that produces a random integer value
       * @param min minimum value
       * @param max maximum value
       * @return int
      */
      int randomInt(int min, int max);

      /**
       * method that produces a random float value
       * @param min minimum value
       * @param max maximum value
       * @return float
      */
      float randomFloat(float min, float max);

      /**
       * method that produces a random double value
       * @param min minimum value
       * @param max maximum value
       * @return double
      */
      double randomDouble(double min, double max);

      /**
       * method that produces a random bool value
       * @return bool
      */
      bool randomBool();
  }; // class Randomizer
  
  
} // namespace SCL