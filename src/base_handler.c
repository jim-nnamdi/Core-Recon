
#include "./includes/auth_handler.h"
#include "./includes/base_handler.h"

static void activate(GtkApplication *app, gpointer user_data) {
    register_frame(app, user_data);
}