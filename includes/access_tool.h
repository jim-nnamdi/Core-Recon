#ifndef ACCESS_TOOL_H
#define ACCESS_TOOL_H

#include <gtk/gtk.h>

typedef struct {
    GtkWidget *encrypted_email;
    GtkWidget *encrypted_passw;
} enable_user_access;

typedef enable_user_access Enable_User_Access;
static void enable_user_permissions(GtkButton *button, gpointer user_data);
static void access_tool_encrypted_email(GtkApplication *app, gpointer user_data);

#endif