#ifndef PHYSICS_H_
#define PHYSICS_H_

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

typedef struct circle_s {
    vector2_t center;
    double radius;
} circle_t;

typedef struct body_s {
    vector2_t position;
    vector2_t velocity;
    vector2_t acceleration;
    double width;
    double height;
    double bounce;
} body_t;

typedef struct world_s {
    double width;
    double height;
    double gravity;
} world_t;

vector2_t vec2(double x, double y);
vector2_t vec2_add(vector2_t a, vector2_t b);
vector2_t vec2_sub(vector2_t a, vector2_t b);
vector2_t vec2_scale(vector2_t v, double scale);
double vec2_length_squared(vector2_t v);
double clamp_double(double value, double min, double max);

rect_t body_get_rect(body_t body);
void body_apply_gravity(body_t *body, world_t world);
void body_update(body_t *body, double delta_time);
void body_resolve_world_bounds(body_t *body, world_t world);

int point_in_rect(vector2_t point, rect_t rect);
int rects_overlap(rect_t a, rect_t b);
int circles_overlap(circle_t a, circle_t b);
int body_collides(body_t a, body_t b);

int physics_run_demo(void);

#endif
