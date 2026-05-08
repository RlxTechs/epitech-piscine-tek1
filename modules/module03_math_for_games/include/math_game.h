#ifndef MATH_GAME_H_
#define MATH_GAME_H_

typedef struct vector2_s {
    double x;
    double y;
} vector2_t;

typedef struct rect_s {
    double x;
    double y;
    double width;
    double height;
} rect_t;

double clamp_double(double value, double min, double max);
double lerp(double start, double end, double t);
double deg_to_rad(double degrees);
double rad_to_deg(double radians);

vector2_t vector2_create(double x, double y);
vector2_t vector2_add(vector2_t a, vector2_t b);
vector2_t vector2_sub(vector2_t a, vector2_t b);
vector2_t vector2_scale(vector2_t v, double scale);
double vector2_dot(vector2_t a, vector2_t b);
double vector2_length(vector2_t v);
double vector2_distance(vector2_t a, vector2_t b);
vector2_t vector2_normalize(vector2_t v);

int point_in_rect(vector2_t point, rect_t rect);
int rects_collide(rect_t a, rect_t b);

void rng_seed(unsigned int seed);
int random_int(int min, int max);
double random_double(double min, double max);

#endif
