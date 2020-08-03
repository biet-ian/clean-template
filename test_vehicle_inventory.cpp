
#include <gtest/gtest.h>
#include "vehicle_inventory.hpp"

TEST(COLLECT, verify_storage_incoming_status_of_a_vehicle )
{
    auto inventory_entry = telematics_to_inventory( 33, measure::motor_temp, 95.0);
    ASSERT_NEAR (95.0, inventory_entry[measure::motor_temp], 0.01);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
