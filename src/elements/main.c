#include "./widgets.c"

void init_widgets()
{
    // iniciando o builder
    // OBS: a pasta do .glade precisa ser informada, saindo da pasta build
    builder = gtk_builder_new_from_file("../src/ui/ui.glade");

    // linkando os widgets da tela
    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    btn1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn1"));
    lbl1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl1"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
}
