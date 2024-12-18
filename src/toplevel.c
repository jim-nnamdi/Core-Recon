#include "../includes/toplevel.h"
#include "../includes/geometry.h"

void top_level_handler(GtkApplication* app, gpointer user_data){
    TopLevel_Pages *top_level_page = (TopLevel_Pages *)user_data;
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "toplevel");
    gtk_window_set_default_size(GTK_WINDOW(window), _window_width, _window_height);

    GtkWidget* stack_grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), stack_grid);

    GtkWidget* stack_page = gtk_stack_new();
    gtk_grid_attach(GTK_GRID(stack_grid), stack_page, 0, 1, 1, 1);

    GtkWidget* stack_switcher = gtk_stack_switcher_new();
    gtk_grid_attach(GTK_GRID(stack_grid), stack_switcher, 0, 0, 1, 1);

    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stack_switcher),GTK_STACK(stack_page));

    GtkWidget* button_one = gtk_button_new_from_icon_name("phone");
    GtkWidget* button_two = gtk_button_new_from_icon_name("camera");

    gtk_stack_add_titled(GTK_STACK(stack_page),button_one, "phone", "Phone");
    gtk_stack_add_titled(GTK_STACK(stack_page), button_two, "camera", "Camera");

    gtk_stack_set_transition_type(GTK_STACK(stack_page),GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN);
    gtk_stack_set_transition_duration(GTK_STACK(stack_page), 1000);
    
    gtk_window_present(GTK_WINDOW(window));
}