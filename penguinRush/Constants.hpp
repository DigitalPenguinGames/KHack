#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constant {
    static const float gravity = 98;
    static const float penguinSpeed = 100;
    static const float backgroundSpeed [] = {0, 5, 50, 500};
    static const float qttBackgrounds = 4;
}

namespace obstacle {
  enum obsType {
    Boat,
    Iceberg,

    qtt
  };
}


#endif // CONSTANTS_HPP
