#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constant {
    static const float qttBackgrounds = 4;
    static const float obstacleSpeed = 600;
    static const float timeToNextFramePeng = 0.2;
    static const float backgroundSpeed [] = {0, 5, 50, 500};
    static const float minTimeObstacles = 2;
    static const float maxTimeObstacles = minTimeObstacles+1;
    static const float penguinInitX = 100;

}

namespace direction {
  enum dir {
    up,
    down
  };

}

namespace obstacle {
  enum obsType {
    Iceberg,
    Buoy,

    qtt
  };
}


#endif // CONSTANTS_HPP
