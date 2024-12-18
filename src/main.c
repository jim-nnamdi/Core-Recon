#include <gtk/gtk.h>
#include "../includes/auth_handler.h"

void activate(GtkApplication *app, gpointer user_data) {
    register_frame(app, user_data);
}

int main(int argc, char** argv){
    GtkApplication* app;
    app = gtk_application_new("org.grof.africa", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app),argc, argv);
    g_object_unref(app);
    return status;
}