#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "auth_handler.h"

static void activate(GtkApplication *app, gpointer user_data) {
    register_frame(app, user_data);
}

#endif