#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constant {
  static const float timeToNextFramePeng = 0.2;
  static const float backgroundSpeed [] = {0, 5, 50, 500};
  static const float qttBackgrounds = 4;
}

namespace direction {
  enum dir {
    up,
    down
  };

}

namespace obstacle {
  enum obsType {
    Boat,
    Iceberg,

    qtt
  };
}


#endif // CONSTANTS_HPP
