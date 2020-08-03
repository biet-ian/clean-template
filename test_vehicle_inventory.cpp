
#include <gtest/gtest.h>
#include "vehicle_inventory.hpp"

TEST(COLLECT, verify_storage_incoming_status_of_a_vehicle )
{
    auto inventory_entry = telematics_to_inventory( 33, measure::motor_temp, 95.0);
    ASSERT_NEAR (95.0, inventory_entry[measure::motor_temp], 0.01);
    ASSERT_TRUE( std::isnan(inventory_entry[measure::battery_temp]) );
    ASSERT_TRUE( std::isnan(inventory_entry[measure::battery_pc]) );

    inventory_entry = telematics_to_inventory( 33, measure::battery_pc, 99.99);
    ASSERT_NEAR (95.0, inventory_entry[measure::motor_temp], 0.01);
    ASSERT_NEAR (99.99, inventory_entry[measure::battery_pc], 0.001);    
    ASSERT_TRUE( std::isnan(inventory_entry[measure::battery_pc]) );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
