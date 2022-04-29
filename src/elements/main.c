#include "./vars.c"
#include "./widgets.c"

void init_widgets()
{
    // iniciando o builder
    builder = gtk_builder_new_from_file("../build/ui.glade");

    // linkando os widgets da tela
    credits_page = GTK_WIDGET(gtk_builder_get_object(builder, "credits_page"));
    game_single_page = GTK_WIDGET(gtk_builder_get_object(builder, "game_single_page"));
    lbl_single = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_single"));
    menu_page = GTK_WIDGET(gtk_builder_get_object(builder, "menu_page"));
    new_game_page = GTK_WIDGET(gtk_builder_get_object(builder, "new_game_page"));
    stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
}
