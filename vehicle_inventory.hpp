
#include <array>
enum measure{
    motor_temp,
    battery_pc,
    battery_temp,
    NUM_OF_MEASURE_TYPES,
};

struct telematics{
    int vehicle_id;
    measure type;
    float measurement;
};

struct inventory
{
    /* data */
    int vehicle_id;
    float motor_temp;
    float battery_pc;
    float battery_temp;
};

std::array<float,NUM_OF_MEASURE_TYPES> telematics_to_inventory( int vehicle_id, measure type, float measured_val );