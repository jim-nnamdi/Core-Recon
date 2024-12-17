#include "../includes/geometry.h"
#include "../includes/auth_handler.h"

static void on_submit(GtkButton* button, gpointer user_data){
    RegisterData *register_logic_sent = (RegisterData *) user_data;
    GtkEntryBuffer *username_buffer = gtk_entry_get_buffer(GTK_ENTRY(register_logic_sent->username_entry));
    const gchar* raw_username_data = gtk_entry_buffer_get_text(username_buffer);

    GtkEntryBuffer *password_buffer = gtk_entry_get_buffer(GTK_ENTRY(register_logic_sent->password_entry));
    const gchar* raw_password_data = gtk_entry_buffer_get_text(password_buffer);

    GtkEntryBuffer *email_address_buffer = gtk_entry_get_buffer(GTK_ENTRY(register_logic_sent->password_entry));
    const gchar* raw_email_address = gtk_entry_buffer_get_text(email_address_buffer);

    g_print("username : '%s'\n", raw_username_data);
    g_print("email address: '%s'\n", raw_email_address);
}

static void register_frame(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Register on core-recon");
    gtk_window_set_default_size(GTK_WINDOW(window), _window_width, _window_height);

    GtkWidget *register_frame_grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), register_frame_grid);

    GtkWidget *username_label = gtk_label_new("username");
    GtkWidget *username_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(register_frame),username_label, 0, 0 , 1, 1);
    gtk_grid_attach(GTK_GRID(register_frame),username_entry, 1, 0, 1, 1);

    GtkWidget *password_label = gtk_label_new("password");
    GtkWidget *password_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(register_frame), password_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(register_frame), password_entry, 1, 1, 1, 1);

    GtkWidget *email_address_label = gtk_label_new("email");
    GtkWidget *email_address_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(register_frame), email_address_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(register_frame), email_address_entry, 1, 2, 1, 1);

    RegisterData *register_logic = g_new(RegisterData,1);
    register_logic->username_entry = username_entry;
    register_logic->password_entry = password_entry;
    register_logic->email_address = email_address_entry;

    GtkWidget *submit_button = gtk_button_new_with_label("Register Account");
    gtk_grid_attach(GTK_GRID(register_frame), submit_button, 2, 3, 2, 2);
    g_signal_connect(submit_button, "clicked", G_CALLBACK(on_submit), register_logic);

    gtk_widget_set_margin_start(register_frame, 50);
    gtk_widget_set_margin_top(register_frame, 100);
    gtk_window_present(GTK_WINDOW(window));
}