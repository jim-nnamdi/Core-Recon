#include "../includes/base_handler.h"

void activate(GtkApplication *app, gpointer user_data) {
    register_frame(app, user_data);
}