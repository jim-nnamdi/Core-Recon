#ifndef AUTH_HANDLER_H
#define AUTH_HANDLER_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    GtkWidget *username_entry;
    GtkWidget *password_entry;
    GtkWidget *email_address;
}register_data;

typedef register_data RegisterData;

static void on_submit(GtkButton* button, gpointer user_data);
static void register_frame(GtkApplication *app, gpointer user_data);

#endif