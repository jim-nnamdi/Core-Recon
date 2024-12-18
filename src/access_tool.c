#include "../includes/geometry.h"
#include "../includes/access_tool.h"

char _test_email[20] = "base@recon";
char _test_passw[20]= "base@@recon";

static void enable_user_permissions(GtkButton *button, gpointer user_data) {
    Enable_User_Access *enable_access = (Enable_User_Access *) user_data;
    GtkEntryBuffer *encrypted_email = gtk_entry_get_buffer(GTK_ENTRY(enable_access->encrypted_email));
    // perform some decryption at this point for the encrypted email to text
    const gchar *encrypted_email_raw = gtk_entry_buffer_get_text(encrypted_email) 
    ? gtk_entry_buffer_get_text(encrypted_email): _test_email;
    GtkEntryBuffer *encrypted_password = gtk_entry_get_buffer(GTK_ENTRY(enable_access->encrypted_passw)) 
    ? gtk_entry_get_buffer(GTK_ENTRY(enable_access->encrypted_passw)) : _test_passw;
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

    GtkWidget *core_password_label = gtk_label_new("password");
    GtkWidget *core_password_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(enable_access_frame), core_password_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(enable_access_frame), core_password_entry, 1, 1, 1, 1);

    GtkWidget *core_email_address_label = gtk_label_new("email");
    GtkWidget *core_email_address_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(enable_access_frame), core_email_address_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(enable_access_frame), core_email_address_entry, 1, 2, 1, 1);

    // splits the entry data into the enable_user_access data structure
    // this holds an encrypted version of the emails and the passwords 
    Enable_User_Access *enable_core_access = g_new(Enable_User_Access, 1);
    enable_core_access->encrypted_email = core_email_address_entry;
    enable_core_access->encrypted_passw = core_password_entry;

    GtkWidget *submit_button = gtk_button_new_with_label("Enable Access");
    gtk_grid_attach(GTK_GRID(enable_access_frame), submit_button, 2, 3, 2, 2);

    // when a signal is sent from the click action then trigger the enable callback on data
    g_signal_connect(submit_button, "clicked", G_CALLBACK(enable_user_permissions), enable_core_access);

    gtk_widget_set_margin_start(enable_access_frame, 50);
    gtk_widget_set_margin_top(enable_access_frame, 100);
    gtk_window_present(GTK_WINDOW(window));
}