#ifndef TOPLEVEL_H
#define TOPLEVEL_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const gchar* toplevel_page_name;
} toplevel_pages;

typedef toplevel_pages TopLevel_Pages;
void top_level_handler(GtkApplication* app, gpointer user_data);

#endif