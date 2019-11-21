#include <k4a/k4a.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void create_xy_table(const k4a_calibration_t *calibration, k4a_image_t xy_table);

void generate_point_cloud(const k4a_image_t depth_image,
                                 const k4a_image_t xy_table,
                                 k4a_image_t point_cloud,
                                 int *point_count);

void write_point_cloud(const char *file_name, const k4a_image_t point_cloud, int point_count);
