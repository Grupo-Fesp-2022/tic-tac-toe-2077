#include "./widgets.c"

void init_widgets()
{
    // iniciando o builder
    builder = gtk_builder_new_from_file("../build/ui.glade");

    // linkando os widgets da tela
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
}
