#include "./includes/geometry.h"
#include "./includes/access_tool.h"

static void enable_user_permissions(GtkButton *button, gpointer user_data) {
    Enable_User_Access *enable_access = (Enable_User_Access *) user_data;
    GtkEntryBuffer *encrypted_email = gtk_entry_get_buffer(GTK_ENTRY(enable_access->encrypted_email));
    // perform some decryption at this point for the encrypted email to text
    const gchar *encrypted_email_raw = gtk_entry_buffer_get_text(encrypted_email);
    GtkEntryBuffer *encrypted_password = gtk_entry_get_buffer(GTK_ENTRY(enable_access->encrypted_passw));
    // perform some decryption at this point for the encrypted password to raw
    const gchar *encrypted_password_raw = gtk_entry_buffer_get_text(encrypted_password);
    g_print("%s\n", encrypted_email_raw);
}

static void access_tool_encrypted_email(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Access recon tool");
    gtk_window_set_default_size(GTK_WINDOW(window), _window_width, _window_height);

    GtkWidget *enable_access_frame = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), enable_access_frame);

    GtkWidget *password_label = gtk_label_new("password");
    GtkWidget *password_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(enable_access_frame), password_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(enable_access_frame), password_entry, 1, 1, 1, 1);

    GtkWidget *email_address_label = gtk_label_new("email");
    GtkWidget *email_address_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(enable_access_frame), email_address_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(enable_access_frame), email_address_entry, 1, 2, 1, 1);
}