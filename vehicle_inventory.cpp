#include "vehicle_inventory.hpp"
#include <map>

std::map<int, std::array<float,NUM_OF_MEASURE_TYPES>> vehicle_inventory;

std::array<float,NUM_OF_MEASURE_TYPES> telematics_to_inventory( int vehicle_id, measure type, float measured_val )
{
    std::array<float,NUM_OF_MEASURE_TYPES> vehicle_status;
    vehicle_status.fill(NAN);

    if(vehicle_inventory.find(vehicle_id) != vehicle_inventory.end())
    {
        vehicle_status =  vehicle_inventory[vehicle_id];
    }

    vehicle_status.at(type) = measured_val;
    vehicle_inventory[vehicle_id] = vehicle_status;

    return vehicle_inventory[vehicle_id];
}
